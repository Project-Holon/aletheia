# script_work.c

Round 5 (r5 s07): 5 parts -> 4. p01 and p02 merged and EXACT. func_021588B0 is now typed
`int f(struct Obj00105 *obj, int arg)` (callback invoker), func_021588DC is typed C,
func_02158824 lost its three unused parameters (body is `func_020307B0(a0)`).

Left:
- p01|p02 (new numbering): func_02158F94 is defined with 3 parameters (the third is used when q != 0)
  but func_02158920 calls it with 2, so r2 is a stale register at the call. Passing an extra argument adds
  an instruction. Only a K&R definition could reproduce it. The old p03 stand-ins also pass int where
  callees take pointers (func_020307B0, func_02045808) and call func_0203CDBC(a0) with an
  argument although it takes none: these machine-style stand-ins must be rewritten as typed C.
- Global d_0217289C is declared two ways (p03|p04); func_02158FD0 has two prototypes (p04|p05).
- 0x021588CE..0x021588D0, 0x02158A8E..0x02158A90, 0x02158FDE..0x02158FE0 are 2-byte alignment pads, not code.
