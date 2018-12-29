Planning for HTTP.SYS
=====================

The following MAIN functionality **might** be implemented (or not)

- HTTPServer-API version 1.0 (as a backwards compatibility)
- HTTP/2.0 Server push
- Asynchroneous I/O

The following **sub** functions will be implemented in coming versions of this project:

- Logging (Done by HttpSendHttpResponse and HttpSendResponseEntityBody)

Registry setting and checks under "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\HTTP\Parameters". 
Existing checks are:

- AllowRestrictedChars (0 or 1).
  If nonzero, Http.sys accepts hex-escaped chars in request URLs that decode to U+0000 – U+001F and U+007F – U+009F ranges.
- EnableAggressiveMemoryUsage (0 or 1).
- EnableNonUTF8 (1 or 0). 
  If zero, Http.sys accepts only UTF-8-encoded URLs. If nonzero, Http.sys also accepts ANSI- or DBCS-encoded URLs in requests.
- FavorUTF8 (1 or 0)
  If nonzero, Http.sys always tries to decode a URL as UTF-8 first; if that conversion fails and EnableNonUTF8 is nonzero, 
  Http.sys then tries to decode it as ANSI or DBCS. If zero (and EnableNonUTF8 is nonzero), Http.sys tries to decode it as ANSI or DBCS; 
  if that is not successful, it tries a UTF-8 conversion.  
- MaxBytesPerSend 65536 (1 to 0xFFFF)
- MaxConnections 1024 (1024 - 2031616)
  Overrides the MaxConnections calculation in the driver. This is primarily a function of memory.
- MaxEndpoints (0)  (0 - 1024)
  Number of current endpoint objects that are permitted. 
  The default value of zero implies that the maximum is computed from available memory.
- MaxFieldLength (16384)
  Sets an upper limit for each header. See MaxRequestBytes. 
  This limit translates to approximately 32k characters for a URL.  
- MaxRequestBytes (16384) 256 - 16777216 (16MB) bytes
  Determines the upper limit for the total size of the Request line and the headers. 
  Its default setting is 16KB. 
  If this value is lower than MaxFieldLength, the MaxFieldLength value is adjusted.
- PercentUAllowed (1 or 0)
  If nonzero, Http.sys accepts the %uNNNN notation in request URLs.
- UrlSegmentMaxCount (255) (0 - 16383)
  Maximum number of URL path segments. If zero, the count bounded by the maximum value of a ULONG.
- UriEnableCache (1 or 0)
  If nonzero, the Http.sys response and fragment cache is enabled.
- UriMaxUriBytes (262144 ) 4096(4k) – 16777216(16MB) bytes  
  Any response that is greater than this value is not cached in the kernel response cache.
- UriScavengerPeriod (120 seconds)  10 - 0xFFFFFFFF seconds
  Determines the frequency of the cache scavenger. Any response or fragment that has not been accessed in the number 
  of seconds equal to UriScavengerPeriod is flushed.
- UrlSegmentMaxLength (260) 0 - 32,766 chars
  Maximum number of characters in a URL path segment (the area between the slashes in the URL). 
  If zero, it is the length that is bounded by the maximum value of a ULONG.

  