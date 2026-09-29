# A two-halfword struct result stored raw and copied at +4 is one initialised local

summary: `bl f; add rN,sp,#0; strh r0,[rN]; lsrs r0,r0,#16; strh r0,[rN,#2]` followed by a second halfword pair copied to `[rN,#4]`/`[rN,#6]` is `Pos b = f(...);` (f returns `struct {short x, y;}` in r0). Writing `Pos a = f(); Pos b = a;` adds a third copy and a bigger frame.

Found in: src/matched/ov/ov099_func_021B9800.c, ov099_func_021B984C.c, ov099_func_021B989C.c, ov099_func_021B9968.c, ov099_func_021B9BC4.c, ov099_func_021B9FDC.c

The raw result slot is the compiler's return temporary and the local `b` is the
second pair; the `x / 16` on a `short` field shows as `asrs #3; lsrs #28; adds;
lsls #12; lsrs #16` when passed to a `u16` parameter. A by-value `Pos`
argument is `ldrh/strh` into `sub r2, sp, #4` then `ldr r1, [r2]`. When the
callee also returns a struct (func_021C4A54 in ov099_func_021B9BC4) the second
temporary sits at `[sp]`, the local at `[sp+8]`.
