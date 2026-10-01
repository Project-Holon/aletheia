# A constant-pool address takes `ip` only when the low scratch registers are already reserved

summary: a fixed-address constant loaded for an aggregate byte-copy lands in
`ip` when `r0`/`r1`/`r2` are already committed to other live values of the same
statement block, and in `r0` when they are not.  When the diff is a cyclic
rotation of three roles across `{r0, r1, r2, ip}` (base, scaled length, small
constant, copy temps) the residue is the front end's preference order, not a
source shape: naming the small constant, making the source `const volatile`, a
named scaled-length local, and declaration reorders all leave the rotation
intact.

Found in: src/pending/ov_sdk/ov009_func_021700C8.c (0x021700C8, ov009, 20 B).

`DWCi_EncodeBinaryMsgCommand` fills a binary-message header.  After the
`MIi_CpuCopy32` call the image has:

```
021700F8  ldr ip, [pc, #0x64]   ; base = &d_021A2188
021700FC  lsl r0, r6, #2        ; len * 4
02170100  ldrb r3, [ip]         ; copy temps r2/r3
...
0217012C  str r1, [r5, #4]      ; r1 = 0x5a
02170134  strb r0, [r5, #9]     ; size = len * 4
```

dsi/1.1p1 instead commits `r0` to the base and rotates every role one slot:
`{base r0, len*4 r1, 0x5a r2, copy temp ip, copy temp r3}`.  The instruction
stream is identical; only the register nibbles differ, exactly 20 concrete
bytes.

`ip` is only chosen for the pool base because the image's front end had already
reserved `r0` (scaled length) and `r1` (`0x5a`) in the same block; the
scheduling of the two `r0`/`r1` definitions is not observable in the source
order.  Forcing `r0` to be live at the base load cannot be reached from C here,
because the scaled length is recomputed after the call and dies at the byte
store, and keeping it live across the call would push the frame.

Measured and rejected: a `n = len * 4;` local before the copy, `len *= 4` /
`len <<= 2`, a u8-cast length store, a block-scope `unsigned long version =
0x5a;`, `const volatile` on the source extern, `4 * len` / `len << 2`
spellings, pointer and memberwise id copies, `__builtin_memcpy`, a copy loop,
and six header-store orders.  Every spelling reproduces the cyclic rotation.

When the residue is this rotation, name it as an allocator tie in the blocker
and stop; the attempt budget belongs on other lanes.
