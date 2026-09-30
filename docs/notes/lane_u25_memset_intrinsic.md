# lane U25: memset DOES inline when declared through a string.h-named header

Method finding, applies beyond ov009. Contradicts (or at least narrows)
`docs/idioms/builtin-clear-inlines-where-memset-calls.md`, which states that
"every dsi 1.1p1 build turns the named `memset` into a `bl` to 0x020923B0".
That is only true when `memset` is declared in the `.c` file itself.

Closed ov009 0x0217E078 `gsLargeIntPowerMod` (1164 bytes, EXACT,
`pkt_ov009_0217E078`) on exactly this. Its object zeroes five 0x104-byte local
structs with the rolled `stm r5!, {r0,r1,r2,r3}` x2 / `subs` / `bne` loop (the
same shape the idiom above shows). Two spellings reproduce it and one does not:

| spelling                                    | result                       |
|---------------------------------------------|------------------------------|
| `extern void *memset(void*, int, unsigned long);` in the .c | `bl memset`, 1020 B |
| `#include ".../src/matched/arm9_sdk/libc/string.h"` then `memset(&x, 0, sizeof x)` | **inlined stm loop**, 1164 B |
| `__builtin__clear(&x, sizeof x)`            | inlines (idiom above)        |

So the choice is not "`__builtin__clear` vs a real memset"; a `memset` declared
through a header literally named `string.h` is an intrinsic to mwccarm and
inlines. `src/matched/arm9_sdk/libc/string.h` is the header that does it,
including for `memcpy` value-numbering.

Second finding from the same row: when a division must come out unsigned in the
image, the operand needs an explicit unsigned cast, not just an unsigned
result type. `gsLargeIntPowerMod`'s exponent-bit test is the vendor's

```c
digitNum = (gsi_u32)i / 32;
digitBit = (gsi_u32)i % 32;
```

Declaring `digitNum`/`digitBit` as `unsigned int` while writing `i / 32` still
emits the signed sequence (`asr r0,sb,#4; add r0,sb,r0,lsr #27; ...`) and the
function stays 16 bytes long; the `(gsi_u32)i` cast gives the image's
`lsr r0, sb, #5` / `and r1, sb, #0x1f` and makes the row EXACT. The loop
induction variable `i` itself must stay `int` (the image tests it with `bpl`).

Upstream source for gsLargeInt is `scratch/U2/gs/src/GameSpy/common/gsLargeInt.c`;
the non-`NEWEXP` `gsLargeIntPowerMod` (line ~1279) is the one in the image. The
`NEWEXP` arm (line ~939) is a different function.
