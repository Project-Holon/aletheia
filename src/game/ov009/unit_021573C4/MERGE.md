# unit_021573C4 (ov009): 2 parts left (was 34), both EXACT

Parts p02..p08 of the earlier numbering are now one part (p02). The only boundary left is p01|p02,
a .bss layout problem:
1. p02's send_ping (func_02158524) needs a FUNCTION-LOCAL `static u16 pingseq`; a file-level
   static changes the scheduling of that function.
2. mwcc registers a function-local static when the function is compiled, so pingseq lands after the
   file-level u32 statics that p01 defines before it.
3. Every p01 u32 static then lands 4 bytes low (24 bytes differ). Standalone, p01 keeps pingseq at file level.
4. Statics are laid out in registration order with alignment, not by size.
5. p01 also defines the globals CPSMyMac and CPSDnsIp; p02 holds both inside `cps` (CPSMyMac in the
   pad at +0x58, CPSDnsIp as cps.dns at +0x60) and only declares `extern CPSDnsIp`. Merge: one definition.
6. p01 and p02 each define the dead file statics ip_conflict, wfailed, eport, mymss, ipid, pingseq,
   CPSDhcpMode (u8/u16/u32 spelling); keep one set, in the order p02 has.
7. Next step: put pingseq's definition inside func_02158524 in the merged file and drop p01's file-level copy.
8. Check the 24-byte shift by moving p01's u32 statics behind that definition.
9. CPSFragTable now lives in cps_types.h (fields count/from/end/time/data/buf).
10. Tools: scratchpad r18/L06b (pair.py, mi.sh, fixsw.py).
