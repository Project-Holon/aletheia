# A `(short)` cast makes a masked big-endian byte shift unwidened

summary: `(short)(x & 0xff00) >> 8` emits `and #0xff00; lsl #16; asr #24`,
while `(x & 0xff00) >> 8` or `(signed char)(x >> 8)` collapse to a single
`lsr`/`asr #8`; declare the cast after the mask to reproduce the original.

Found in: src/matched/ov_sdk/ov172_func_021C3A28.c (0x021C3A28)

`(x & 0xff00) >> 8` on an `unsigned long` compiles to `and` + `lsr #8` (two
instructions).  Writing the same byte extraction as

```c
(short)(x & 0xff00) >> 8
```

— the cast is to a 16-bit signed type *after* the mask, before the shift —
makes mwcc emit the unwidened three-instruction sequence

```
and rD, rS, #0xff00
lsl rD, rD, #0x10
asr rD, rD, #0x18
```

The `lsl #16; asr #24` pair sign-extends the byte in bits 8..15; the mask is
kept because the value is materialised as a signed 16-bit quantity before the
16-bit shift.  A plain `(signed char)(x >> 8)`, a bare `(x >> 8)`, or an
assignment that only feeds a `strb` all optimise the extension away (one `lsr`
or `asr #8`).  Declaring the source field signed does *not* reproduce it
either; only the cast placement does.

With `(jexif->app1_length & 0xff00) >> 8` the function came out four bytes
short (the high-byte store collapsed to one `lsr`); with the `(short)` cast it
reached `EXACT`.  The matched sibling `jpeg_encode_ifd` (0x021C3620) does
*not* use this form — its own byte writes are `and` + `lsr`/`asr` — so the
cast is local to the encode-exif path.

A quick probe harness (one small function per spelling compiled with
`tools/mwccarm/mwccarm/dsi/1.1p1/mwccarm.exe`, disassembled with capstone)
found the mapping:
`(short)(ux & 0xff00) >> 8` → `and;lsl;asr`;
`(short)ux >> 8` → `lsl;asr`;
`(short)(ux >> 8)` → `lsr`.
