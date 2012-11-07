#ifndef APPLINKRPC_SYSTEMCONTEXTMARSHALLER_INCLUDE
#define APPLINKRPC_SYSTEMCONTEXTMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "PerfectHashTable.h"

#include "../include/JSONHandler/ALRPCObjects/SystemContext.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Wed Nov  7 13:10:41 2012
  source stamp	Thu Oct 25 06:49:27 2012
  author	robok0der
*/

namespace AppLinkRPC
{

//! marshalling class for SystemContext

  class SystemContextMarshaller
  {
  public:
  
    static std::string toName(const SystemContext& e) 	{ return getName(e.mInternal) ?: ""; }
  
    static bool fromName(SystemContext& e,const std::string& s)
    { 
      return (e.mInternal=getIndex(s.c_str()))!=SystemContext::INVALID_ENUM;
    }
  
    static bool checkIntegrity(SystemContext& e)		{ return e.mInternal!=SystemContext::INVALID_ENUM; } 
    static bool checkIntegrityConst(const SystemContext& e)	{ return e.mInternal!=SystemContext::INVALID_ENUM; } 
  
    static bool fromString(const std::string& s,SystemContext& e);
    static const std::string toString(const SystemContext& e);
  
    static bool fromJSON(const Json::Value& s,SystemContext& e);
    static Json::Value toJSON(const SystemContext& e);
  
    static const char* getName(SystemContext::SystemContextInternal e)
    {
       return (e>=0 && e<3) ? mHashTable[e].name : NULL;
    }
  
    static const SystemContext::SystemContextInternal getIndex(const char* s);
  
    static const PerfectHashTable mHashTable[3];
  };
  
}

#endif
