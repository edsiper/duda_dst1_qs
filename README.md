# Duda DST-1 example

when launching the service try to access the URLs:

```bash
$ curl -i "http://127.0.0.1:2001/hello/?A=2&B=xyz"
HTTP/1.1 200 OK
Server: Monkey/1.4.0
Date: Tue, 14 Jun 2016 01:41:19 GMT
Content-Length: 49

Query String count=2
Value of A=2
Value of B=xyz
```

```bash
$ curl -i http://127.0.0.1:2001/hello/test
HTTP/1.1 200 OK
Server: Monkey/1.4.0
Date: Tue, 14 Jun 2016 01:41:51 GMT
Content-Length: 15

This is a test
```
