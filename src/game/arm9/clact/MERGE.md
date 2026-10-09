# clact (arm9)

11 parts (clact_p01..p11) left (round 6: old p11|p12 merged after nine hidden accessors at 0x0204D564..0x0204D75C were written between them; the old p12|p13 boundary is now p11|p12). Boundaries, by part start:

- p02 (0204BE38) to p03 (0204C83C): struct Sys / struct Mgr are two views of one object, and an unsigned short operand differs. Unify by offset.
- p03 to p04 (0204CBB0): struct Obj_0204C83C vs Obj_0204CEB4 (same object, different local views).
- p04 to p05 (0204CF74): Obj_0204CFDC vs Obj_0204CED8.
- p05 to p06 (0204D048): Req vs Req_0204CFDC (const struct pointer).
- p06 to p07 (0204D104), p07 to p08 (0204D134), p08 to p09 (0204D3C4): gUnk_020A1394 is declared as three different function-pointer table types (Sub *, Dispatchable *, Obj0204D324 *). Needs one canonical dispatch type.
- p09 to p10 (0204D410): Obj_0204D3C4 vs Obj_0204D410. p10 to p11 (0204D478): Obj vs Obj0204D478.
- Round 6 (lane sa9): func_0204E130 and the old p12 (0204E180..) were moved out into the new TU `textprint.c`: layout/file_anchors.txt gives their __FILE__ string as textprint.c, while the clact functions up to func_0204E01C use clact.c. clact is now 11 parts; g_02146A78 is typed in textprint.c only.
