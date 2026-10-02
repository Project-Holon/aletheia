# An unused frame word under a hoisted sign word is a hoisted long long copy

summary: when a loop's fx32 multiplies read a spilled `s >> 31` sign word from
a slot whose lower neighbour is never touched (one extra frame word, no `r3`
pad push), the source keeps a `long long` copy of the scale assigned inside the
loop body; LICM hoists it as a 64-bit temporary, reserving an 8-byte slot whose
low word is copy-propagated away.

Found in: src/matched/ov/ov021_func_0218D444.c (0x0218D444)

With `FX_Mul(x, s)` inline helpers the build was 37 bytes out: `push {r3-r7,lr};
sub sp,#0x38` against `push {r4-r7,lr}; sub sp,#0x3c`, the sign word one slot
low. `long long ls; ... ls = s;` at the top of the outer loop body, with both
multiplies written `((long long)(x << 12) * ls + 0x800LL) >> 12`, gives the
frame and the slot. Assigning `ls` before the loop computes the sign word too
early; assigning it in the inner loop collapses it back to a 4-byte temporary.

Two companions in the same function: a plain `for` duplicated the guard around
the hoisted block, an explicit `if` guard plus `do { } while` did not; and
passing `*(int *)(p + 4)` to the first call (instead of the local `s` loaded
from it) swapped `s` below the hoisted `m * w` temporary as in the image.
