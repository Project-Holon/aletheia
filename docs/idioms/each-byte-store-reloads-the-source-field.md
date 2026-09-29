# Every byte written through a pointer re-reads the source field

summary: When a struct field is serialised one byte at a time into a buffer
reached through a global pointer, the compiler must reload that field once per
byte; the original C has no local copy, and adding one collapses N loads into
one and loses bytes. Pair it with the mask living *before* the shift, or the
`& 0xff` folds into the `strb` and each byte costs one instruction too few.

Found in: src/matched/ov_sdk/ov172_func_021C2E1C.c (0x021C2E1C)

The object writes a 32-bit EXIF tag value big-endian through a global context:

```
ldr r2, [r6, #4]          ; ctx->pos
add r0, r2, #1
str r0, [r6, #4]          ; ctx->pos++
ldr r1, [r5, #0xc]        ; entry->val_c        <-- reloaded per byte
ldr r0, [r6, #0x14]       ; ctx->buf
and r1, r1, #0xff000000
lsr r1, r1, #0x18
strb r1, [r0, r2]
```

The C that reproduces it reads the field straight out of the parameter for
every byte, with no local:

```c
ctx->buf[ctx->pos++] = (entry->val_c & 0xff000000) >> 24;
ctx->buf[ctx->pos++] = (entry->val_c & 0xff0000) >> 16;
ctx->buf[ctx->pos++] = (entry->val_c & 0xff00) >> 8;
ctx->buf[ctx->pos++] = entry->val_c;
```

Two traps:

* Binding `long v = entry->val_c;` first gives one load and four reuses; the
  object has four loads, because the `strb` through `ctx->buf` may alias
  `*entry` and the value is re-read each time. Keep the parameter direct.
* Writing `(v >> 24) & 0xff` (mask after the shift) lets 1.1p1 fold the mask
  into the `strb` and drop the `and`, one instruction short per byte. Spelled
  as `(v & 0xff000000) >> 24` the mask sits before the shift and survives.
  The top byte then disassembles `and`+`lsr`, the lower ones `and`+`asr`.

Both changes together took this function from 760 bytes (76 short, 497 concrete
mismatches) to the exact 836.
