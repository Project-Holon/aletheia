# unit_02195E80.c (ov009)

Translation unit 02195E80..02196C28, 24 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02195E80.c` is blocked by:

- ov009_func_02195E80.c..ov009_func_02196B48.c: prototype of func_02195340 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype of func_021950B4 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype 
- ov009_func_02195E80.c..ov009_func_02196348.c: prototype of func_02195340 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype of func_021950B4 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype 
- ov009_func_02195F9C.c..ov009_func_02196348.c: prototype of func_02195340 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype of func_021950B4 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype 
- ov009_func_02195F9C.c..ov009_func_02196118.c: prototype of func_02195340 differs between members (src/matched/ov_sdk/ov009_func_02196118.c); prototype of func_021950B4 differs between members (src/matched/ov_sdk/ov009_func_02196118.c)
- ov009_func_021961C8.c..ov009_func_02196348.c: prototype of func_02195F5C differs between members (src/matched/ov_sdk/ov009_func_02196268.c)
- ov009_func_02196458.c..ov009_func_02196B48.c: prototype of gti2ConnectionCommunicationError differs between members (src/matched/ov_sdk/ov009_func_021964A8.c); prototype of gti2ConnectedCallback differs between members (src/matched/ov_sdk/ov009_f
- ov009_func_02196458.c..ov009_func_0219666C.c: prototype of gti2ConnectionCommunicationError differs between members (src/matched/ov_sdk/ov009_func_021964A8.c); prototype of gti2ConnectedCallback differs between members (src/matched/ov_sdk/ov009_f
- ov009_func_02196558.c..ov009_func_0219666C.c: c99=CCERR: line 58: struct/union/enum/class tag 'GTI2Connection' redefined | line 178: 'incomingBufferMessages' is not a member of class 'struct GTI2Connection' | line 180: 'incomingBufferMessages' is
- ov009_func_0219681C.c..ov009_func_02196B48.c: prototype of func_02196558 differs between members (src/matched/ov_sdk/ov009_func_02196948.c); prototype of func_02195F5C differs between members (src/matched/ov_sdk/ov009_func_02196B48.c)
- ov009_func_0219681C.c..ov009_func_02196920.c: c99=CCERR: line 106: illegal implicit conversion from 'struct Conn_021968A0 *' to | line 106: 'struct Conn_0219681C *' nolang=CCERR: line 106: illegal implicit conversion from 'struct Conn_021968A0 *'
- ov009_func_02196948.c..ov009_func_02196B48.c: prototype of func_02195F5C differs between members (src/matched/ov_sdk/ov009_func_02196B48.c)

Members, in address order:

- `ov009_func_02195F9C.c`
- `ov009_func_021961C8.c`
- `ov009_func_02196558.c`
- `ov009_func_0219681C.c`
- `ov009_func_02196948.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02195E80.c` again.
