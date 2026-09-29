# An enum-typed offset local keeps a far field offset in a callee-saved register and derives the next offset from it

summary: when the image does `movs r4,#0x9d; lsls r4,r4,#2` before a call, keeps r4 across it and later reaches a second field as `subs r4,#0xa8; str rX,[r5,r4]` (the second offset is the first minus a delta), the source holds the first offset in an enum-typed local (`typedef enum { K274 = 0x274 } Off; Off o = K274;`) and writes `p + o` and `p + (o - 0xa8)`; an `int` local folds to two independent constants, `p + 0x274` / `p + 0x1CC` never share the register.

Found in: src/matched/ov/ov099_func_021BC468.c (0x021BC468), src/matched/ov/ov099_func_021BC4D4.c (0x021BC4D4), src/matched/ov/ov099_func_021BC544.c (0x021BC544, offset 0x242 / 0x1CC), src/matched/ov/ov099_func_021BC6F4.c (0x021BC6F4, word index 0x73 as the enum local, `a[k] = 0x49`, `movs r6,#0x73` kept across the call)

The same enum lever as `an-enum-type-keeps-values-out-of-constant-folding.md`, applied to a
pointer offset instead of a loop counter. What the other spellings gave for 021BC468:
raw `p + 0x274` / `p + 0x1CC` (34 bytes out, `movs r0,#0x73; lsls` rematerialised);
`u32 *` word indexes (same); `char *q = p + 0x274; ... *(q - 0xa8)` (right frame, but
q rebuilt with `adds r0,r5,r7; subs r0,#0xa8` and the registers rotated); `int o` (folds).
Only `Off o; o = K274;` gives r4 = 0x274 live, `subs r4,#0xa8`, `str r0,[r5,r4]`.

Companion lever in the same functions: the two stores that follow the branch are written out
in each arm (`if (r == 0) { strb 0x4c; str 0x8a } else { strb 0x9b; str 0x8a }`); a
`s = cond ? 0x4c : 0x9b` single store, or an if/else assigning `s`, becomes a conditional
`movs` and loses the original's `b` over the second constant.
