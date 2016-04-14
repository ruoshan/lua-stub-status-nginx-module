Name
====

ngx_lua_stub_status - Nginx C module to expose Lua API to ngx_lua for Nginx stub_status

Table of Contents
=================

* [Name](#name)
* [Status](#status)
* [Synopsis](#synopsis)
* [Functions](#functions)
    * [stub_status](#stub_status)
* [Compatibility](#compatibility)
* [Installation](#installation)
* [Author](#author)
* [Copyright and License](#copyright-and-license)

Status
======

This module is under development.

Synopsis
========

```nginx
http {
    server {
        listen 8080;

        location = /stub {
            content_by_lua '
                local stub_status = require "ngx.stub_status"
                for k, v in pairs(stub_status()) do
                    ngx.say(k, ": ", v)
                end
            ';
        }
    }
}
```

Functions
=========

stub_status
-------------
`syntax: value = stub_status()`

Return a table of the connection info similar to [http://nginx.org/en/docs/http/ngx_http_stub_status_module.html stub_status]

The keys of this table are:
* active: The current number of active client connections including `waiting` connections.
* accepted: The total number of accepted client connections.
* handled: The total number of handled connections. Generally, the parameter value is the same as `accepted` unless some resource limits have been reached.
* requests: The total number of client requests.
* reading: The current number of connections where nginx is reading the request header.
* writing: The current number of connections where nginx is writing the response back to the client.
* waiting: The current number of idle client connections waiting for a request.

NOTE: all the metrics mentioned above do NOT take ngx.socket.\* into account.

[Back to TOC](#table-of-contents)

Installation
============
configure your openresty:

```bash
./configure --with-http_stub_status_module --add-module=/path/to/lua-stub-status-nginx-module
make -j2
make install
```

:warning: `--with-http_stub_status_module` option is required

[Back to TOC](#table-of-contents)

Author
======

Ruoshan Huang

[Back to TOC](#table-of-contents)

Copyright and License
=====================

This module is licensed under the BSD license.

Copyright (C) 2016, by Ruoshan Huang

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

[Back to TOC](#table-of-contents)
