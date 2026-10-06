# unit_020911D4.c (arm9)

Translation unit 020911D4..0209D850, 162 functions, confidence weak (tools/tuboundary.py).

This range mixes compilers (dsi/1.1p1 and dsi/1.2), ISAs (thumb stubs and ARM code)
and hand-written runtime routines, so it cannot be one file. The parts
`unit_020911D4_p01..p11.c` are the merged same-setting runs, in address order.
Left as separate files in this folder:

- func_020911D4.c (arm), func_020911D8.c (thumb): a different ISA from their neighbours.
- p01..p03 (thumb stubs): merging them with func_020911D8.c changes the padding bytes
  between the asm stubs (10 bytes differ), so they stay apart. The unprototyped extern
  needed for the asm stubs was tried and is not the blocker.
- p04 and p05: merging p04+p05 with p06 (func_02091D38) changes the register allocation
  of func_02091D38 (539 bytes differ); the cause was not found in the time available.
- func_020921F4 is in p05 but cannot join func_020922B0 (p06): c99=DIFF.
- func_02099224.c (1.1p1) sits between compiler 1.2 members (unit_020979BC part p07 and
  func_0209953C.c, 1.2); func_0209953C.c is 1.2 and cannot join its 1.1p1 neighbours.
- compares.c, converters.c, dadd_dsub.c, fgeq.c, ll_divmod.c: manifest kind `runtime`
  (compared at their layout/runtime_arm9.txt rows), so they cannot be merged with
  other code.
- func_0209D820.c: merging with the previous part gives c99=DIFF.
- p09 and p10 (0209B2E8, 0209C054): the runtime members between them block a merge;
  p10 + p11 gives c99=DIFF.
