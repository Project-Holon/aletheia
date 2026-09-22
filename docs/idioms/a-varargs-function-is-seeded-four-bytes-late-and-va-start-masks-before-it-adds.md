# A varargs function is seeded four bytes late, and its `va_start` masks before it adds

summary: a variadic function opens with TWO pushes, and `disasm.py` labels the
second one, so the worklist seeds the function four bytes into its own body;
subtract four and look the address up in `layout/symbols_sdk.txt`. The three
instructions after that second push are the SDK's `va_start`, and they are
`add` / `bic` / `add` -- mask to a word boundary FIRST, step one word SECOND.
Any other order, and any spelling built on `sizeof(last)`, is byte-wrong.

Found in: `src/matched/func_0208CF34.c` (0x0208CF34 `OS_SPrintf`),
`src/matched/func_0208D7E0.c` (0x0208D7E0 `STD_TSPrintf`),
`src/matched/func_0208D80C.c` (0x0208D80C `OS_SNPrintf`)

## The mis-seeded label

`docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md` records
that taking the address of a register parameter reserves a four-word home area.
Every variadic function does exactly that, to the last named parameter, so it
always opens:

```
0208D7E0  0f 00 2d e9  push {r0, r1, r2, r3}     <- the home area
0208D7E4  08 40 2d e9  push {r3, lr}             <- the ordinary frame
```

`disasm.py` only auto-labels a prologue that saves `lr` (`docs/AGENT-BRIEF.md`
S7), and the first push does not. So it labels 0x0208D7E4 and the worklist
carries a "function" that starts one instruction inside the real one. The tell
in `match.py show --addr` is unmistakable once you know it: the seeded address
opens with `push {r3, lr}`, and the word *before* it is `0f 00 2d e9`.

In wave 7 this accounted for three of the ten open entries of `pkt_02087AE4`,
and all three went EXACT on the first compile once written at the true entry.
One of them already had a `src/pending/` file whose status had been corrected
from EXACT to DIFF, 9 bytes out -- that file's C was *right*; it was being
compared against the wrong four bytes.

Do not treat such an entry as a new function to name. These are TwlSDK library
members: `layout/symbols_sdk.txt` has the real name at the real address, and
using it also buys the relocation its witness through `layout/symbols_sdk.json`.

## The `va_start` spelling

The body's first three instructions are the macro, and they pin its order:

```
0208D7E8  add r1, sp, #0xc      ; &fmt, in the home area
0208D7EC  bic r1, r1, #3        ; round DOWN to a word boundary
0208D7F0  add r3, r1, #4        ; then step one word past it
```

So the macro is

```c
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
```

mask first, add second. Two near misses, both measured at 0x0208D7E0:

| spelling | result |
| --- | --- |
| `(char *)&(l) + sizeof(l))` | no `bic` at all; 4 bytes short, 19 out |
| `((unsigned)((char *)&(l) + sizeof(l)) & ~3u) + 4` | emits `add` before `bic`; 48 bytes, 35 out |
| `(((unsigned)&(l) & ~3u) + 4)` | **EXACT** |

The middle one is the trap: it looks like the same arithmetic and is 8 bytes
long in the same three-instruction shape, but the compiler emits the operations
in source order and the `add`/`bic` swap shifts every following instruction.

## The worker's bound is a signed int

`STD_TSPrintf` is the unbounded form and reaches its bounded worker as
`STD_TVSNPrintf(dst, INT_MAX, fmt, vlist)`. The image materialises the bound as
`mvn r1, #0x80000000`, i.e. 0x7FFFFFFF and not 0xFFFFFFFF, which is the only
evidence that the worker's second parameter is `int` rather than `size_t`.
Writing `(unsigned)-1` there is a different instruction and a different byte.
