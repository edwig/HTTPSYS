HTTP.SYS
========

This library is a user-space implementation of the MS-Windows HTTP.SYS kernel driver.
It implements the "HTTP Server API" 2.0 as defined by Microsoft and documented here:
https://docs.microsoft.com/en-us/windows/desktop/http/http-server-api-version-2-0-reference

It was created for various reasons:
- Educational purposes
- Non-disclosed functions (the websockets implementation)
- Because it can be done :-)

A number of functions of HTTP.SYS where not (yet) implemented, including
- HTTP 2.0 Server push
- Logging following the log rules
- Version 1.0 of the "HTTP Server API"
- Various registry settings of the driver (See document: planning.md)

These functionalities are left for a later date and version.

This piece of software is also included (and tested!) in the Marlin project.
You can find the Marlin project under: https://github.com/Edwig/Marlin


License: MIT