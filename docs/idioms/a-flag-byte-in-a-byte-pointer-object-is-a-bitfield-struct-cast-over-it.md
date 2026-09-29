# A flag byte read as bit tests and set with bics/orrs is a bitfield struct cast over the byte pointer

summary: When an object is addressed as a raw byte pointer and one byte of it is tested with `lsls #n; lsrs #0x1f` and set with `bics r,#1; orrs`, declare `typedef struct { u8 pad[OFF]; u8 a:1; u8 b:1; ... } B;` and write `((B *)p)->a = 1;` / `((B *)p)->b != 0`; the other fields stay raw offsets, and bit 0 is the first (least significant) field.

Found in: `src/matched/ov/ov093_func_021B835C.c`, `src/matched/ov/ov093_func_021B8434.c`, `src/matched/ov/ov093_func_021B84D8.c`, `src/matched/ov/ov093_func_021B919C.c` (all ov093, flag byte at object offset 0x473)

The original shape (0x021B8434):

```
ldrb r0, [r5, r4]      ; r4 = 0x473 from the pool
lsls r1, r0, #0x1f
lsrs r1, r1, #0x1f     ; bit 0
...
ldrb r1, [r5, r4]
movs r0, #1
bics r1, r0
movs r0, #1
orrs r0, r1
strb r0, [r5, r4]      ; bit0 = 1
```

and bit 1 is `lsls #0x1e; lsrs #0x1f`, bit 3 `lsls #0x1c`, bit 6 `lsls #0x19`,
with `movs r0,#8; orrs` setting bit 3. Masks and shifts on `p[0x473]` do not
give the `bics`/`orrs` pair; a one-bit bitfield assignment does. Fields fill
from bit 0 upward on this compiler.
