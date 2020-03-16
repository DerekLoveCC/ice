//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// <auto-generated>
//
// Generated from file `PluginFacade.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef ICEGRID_API_EXPORTS
#   define ICEGRID_API_EXPORTS
#endif
#include <IceGrid/PluginFacade.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <Ice/LocalException.h>
#include <Ice/SlicedData.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

}

IceGrid::ReplicaGroupFilter::~ReplicaGroupFilter()
{
}

IceGrid::TypeFilter::~TypeFilter()
{
}

IceGrid::RegistryPluginFacade::~RegistryPluginFacade()
{
}

#else // C++98 mapping

namespace
{

}

IceGrid::ReplicaGroupFilter::~ReplicaGroupFilter()
{
}

/// \cond INTERNAL
ICEGRID_API ::Ice::LocalObject* IceGrid::upCast(ReplicaGroupFilter* p) { return p; }
/// \endcond

IceGrid::TypeFilter::~TypeFilter()
{
}

/// \cond INTERNAL
ICEGRID_API ::Ice::LocalObject* IceGrid::upCast(TypeFilter* p) { return p; }
/// \endcond

IceGrid::RegistryPluginFacade::~RegistryPluginFacade()
{
}

/// \cond INTERNAL
ICEGRID_API ::Ice::LocalObject* IceGrid::upCast(RegistryPluginFacade* p) { return p; }
/// \endcond

namespace Ice
{
}

#endif