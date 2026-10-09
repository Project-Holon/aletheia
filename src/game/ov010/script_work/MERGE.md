# script_work.c

Round 3 (r3_ov04): 6 parts -> 5. The uncovered block 0x02157968..0x021579AC is now five hidden functions at the start of p01 (func_02157968, 0215796C, 02157980, 02157998, 021579A4).

Left:
- p01|p02: func_021588B0 is defined with 3 parameters in p01 and called with 2 in p02. A K&R definition fixes that, but then func_02158824 (void with 4 parameters in p01) is called as int f(a0) in p02 stand-in code. The p02 stand-ins (a0, a1 style) must be rewritten as typed C first.
- p02|p03: func_02158F94 has 2 and 3 argument forms (same stand-in problem).
- 0x021588CE..0x021588D0, 0x02158A8E..0x02158A90, 0x02158FDE..0x02158FE0 are 2-byte alignment pads, not code.
- p03|p04, p04|p05, p05|p06: c99=DIFF or prototype conflicts as listed earlier (func_02158FE0 void * vs int).
