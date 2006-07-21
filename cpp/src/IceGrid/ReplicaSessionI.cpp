// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#include <Ice/Ice.h>

#include <IceGrid/ReplicaSessionI.h>
#include <IceGrid/Database.h>

using namespace std;
using namespace IceGrid;

ReplicaSessionI::ReplicaSessionI(const DatabasePtr& database, 
				 const string& name, 
				 const InternalRegistryPrx& proxy,
				 const ReplicaInfo& info) :
    _database(database),
    _traceLevels(database->getTraceLevels()),
    _name(name),
    _proxy(InternalRegistryPrx::uncheckedCast(proxy->ice_timeout(_database->getSessionTimeout() * 1000))),
    _info(info),
    _timestamp(IceUtil::Time::now()),
    _destroy(false)
{
    __setNoDelete(true);
    try
    {
	_database->addReplica(name, this);
    }
    catch(...)
    {
	__setNoDelete(false);
	throw;
    }
    __setNoDelete(false);
}

void
ReplicaSessionI::keepAlive(const Ice::Current& current)
{
    Lock sync(*this);
    if(_destroy)
    {
	throw Ice::ObjectNotExistException(__FILE__, __LINE__);
    }

    _timestamp = IceUtil::Time::now();

    if(_traceLevels->replica > 2)
    {
	Ice::Trace out(_traceLevels->logger, _traceLevels->replicaCat);
	out << "replica `" << _name << "' keep alive ";
    }
}

int
ReplicaSessionI::getTimeout(const Ice::Current& current) const
{
    return _database->getSessionTimeout();
}

void
ReplicaSessionI::destroy(const Ice::Current& current)
{
    Lock sync(*this);
    if(_destroy)
    {
	throw Ice::ObjectNotExistException(__FILE__, __LINE__);
    }

    _destroy = true;

    _database->removeReplica(_name);

    if(current.adapter)
    {
	try
	{
	    current.adapter->remove(current.id);
	}

	catch(const Ice::ObjectAdapterDeactivatedException&)
	{
	}
    }
}

IceUtil::Time
ReplicaSessionI::timestamp() const
{
    Lock sync(*this);
    if(_destroy)
    {
	throw Ice::ObjectNotExistException(__FILE__, __LINE__);
    }
    return _timestamp;
}
