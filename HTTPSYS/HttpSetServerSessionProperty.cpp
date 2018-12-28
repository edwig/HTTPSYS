//////////////////////////////////////////////////////////////////////////
//
// USER-SPACE IMPLEMENTTION OF HTTP.SYS
//
// 2018 (c) ir. W.E. Huisman
// License: MIT
//
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "http_private.h"
#include "RequestQueue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Not implemented yet

HTTPAPI_LINKAGE
ULONG WINAPI
HttpSetServerSessionProperty(IN HTTP_SERVER_SESSION_ID  ServerSessionId
                            ,IN HTTP_SERVER_PROPERTY    Property
                            ,_In_reads_bytes_(PropertyInformationLength) PVOID PropertyInformation
                            ,IN ULONG                   PropertyInformationLength)
{
  // See if we have minimal parameters
  if(ServerSessionId == NULL || PropertyInformation == nullptr)
  {
    return ERROR_INVALID_PARAMETER;
  }

  // Grab our session
  ServerSession* session = reinterpret_cast<ServerSession*>(ServerSessionId);

  switch(Property)
  {
    case HttpServerStateProperty:
    case HttpServerTimeoutsProperty:
    case HttpServerQosProperty:
    case HttpServerLoggingProperty:
    case HttpServerAuthenticationProperty:
    case HttpServerExtendedAuthenticationProperty:
    case HttpServerChannelBindProperty:             // Fall through
    default:                                        return ERROR_INVALID_PARAMETER;
  }

  return NO_ERROR;
}
