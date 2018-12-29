//////////////////////////////////////////////////////////////////////////
//
// USER-SPACE IMPLEMENTTION OF HTTP.SYS
//
// 2018 (c) ir. W.E. Huisman
// License: MIT
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include <vector>
#include <string>

class UrlGroup;
class Logfile;

using UrlGroups = std::vector<UrlGroup*>;
using std::wstring;

class ServerSession
{
public:
  ServerSession();
 ~ServerSession();

 // FUNCTIONS
 ULONG    AddUrlGroup   (UrlGroup* p_group);
 bool     RemoveUrlGroup(UrlGroup* p_group);
 // SETTERS
 void     SetSocketLogging(int p_logging);
 void     SetEnabledState(HTTP_ENABLED_STATE p_state);
 void     SetTimeoutEntityBody    (USHORT p_timeout);
 void     SetTimeoutDrainBody     (USHORT p_timeout);
 void     SetTimeoutRequestQueue  (USHORT p_timeout);
 void     SetTimeoutIdleConnection(USHORT p_timeout);
 void     SetTimeoutHeaderWait    (USHORT p_timeout);
 void     SetTimeoutMinSendRate   (ULONG  p_rate);
 void     SetAuthentication(ULONG p_scheme,CString p_domain,CString p_realm,wstring p_domainW,wstring p_realmW,bool p_caching);

 // GETTERS
 int      GetSocketLogging()          { return m_socketLogging;           };
 Logfile* GetLogfile()                { return m_logfile;                 };
 HTTP_ENABLED_STATE GetEnabledState() { return m_state;                   };
 USHORT   GetTimeoutEntityBody()      { return m_timeoutEntityBody;       };
 USHORT   GetTimeoutDrainEntityBody() { return m_timeoutDrainEntityBody;  };
 USHORT   GetTimeoutRequestQueue()    { return m_timeoutRequestQueue;     };
 USHORT   GetTimeoutIdleConnection()  { return m_timeoutIdleConnection;   };
 USHORT   GetTimeoutHeaderWait()      { return m_timeoutHeaderWait;       };
 ULONG    GetTimeoutMinSendRate()     { return m_timeoutMinSendRate;      };

private:
  // Create and start our logfile
  void    CreateLogfile();

  UrlGroups           m_groups;
  Logfile*            m_logfile       { nullptr };
  int                 m_socketLogging { SOCK_LOGGING_OFF };
  HTTP_ENABLED_STATE  m_state         { HttpEnabledStateActive };
  // Timeouts
  USHORT              m_timeoutEntityBody        { URL_TIMEOUT_ENTITY_BODY     };
  USHORT              m_timeoutDrainEntityBody   { URL_TIMEOUT_DRAIN_BODY      };
  USHORT              m_timeoutRequestQueue      { URL_TIMEOUT_REQUEST_QUEUE   };
  USHORT              m_timeoutIdleConnection    { URL_TIMEOUT_IDLE_CONNECTION };
  USHORT              m_timeoutHeaderWait        { URL_TIMEOUT_HEADER_WAIT     };
  ULONG               m_timeoutMinSendRate       { URL_DEFAULT_MIN_SEND_RATE   };
  // Locking for update
  CRITICAL_SECTION    m_lock;
};
