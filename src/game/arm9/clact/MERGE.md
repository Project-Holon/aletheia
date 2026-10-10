# clact (arm9)

Round 12 (lane w12d): 11 parts -> 6. Old p06 to p11 (0204D048 .. end of clact.c) are now
`clact_p06.c`; every part is byte-exact (dsi/1.1p1).

What closed them:
- gUnk_020A1394 is one dispatch table whose rows take different argument lists. It is
  declared once as an unprototyped table, `extern void *(*const gUnk_020A1394[][3])();`
  (the six per-part function-pointer types are gone).
- One `struct Obj { u32 kind; u8 pad_04[8]; u8 unk_0c; }` replaces Obj_0204D3C4, Obj_0204D410,
  Obj0204D478, Obj0204D4B4 and the opaque Obj of old p08; one `struct Rec` (+0x10 field).

Boundaries left, by part start:
- p01 (0204A48C) | p02 (0204BE38): Pool_0204A48C against Pool_0204BE38, and g_02146A74 and
  s_clact_c declared two ways. One canonical Mgr/Pool by offset is needed.
- p02 | p03 (0204C83C): Mgr_0204BE38 lacks the field unk_0e0 that p03's view has (same
  object, g_02146A74).
- p03 | p04 (0204CBB0): Obj_0204C83C against Obj_0204CEB4 (same object, local views).
- p04 | p05 (0204CF74): Obj_0204CFDC against Obj_0204CED8.
- p05 | p06 (0204D048): Sub_0204CF74 (opaque), Sub_0204D048 ({u32 kind}), and three
  clones of the request struct (Req_0204CFDC, Req_0204D048, Req_0204D134).
- `textprint.c` was split out in round 6 (see layout/file_anchors.txt).
