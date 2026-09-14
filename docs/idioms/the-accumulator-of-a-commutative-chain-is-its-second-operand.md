# In a chain of commutative operators the result register is the second operand's, and the first is folded into it

summary: `e1 ^ e2 ^ e3 ^ e4` evaluates every operand into its own register but
accumulates into the one holding `e2`, so the operand the original folds in
first is the source's *first*, not the one whose value the accumulator starts
with; swapping just the leading pair costs a fifth register and a `push`.

Found in: `src/matched/unit_02017E64.c` (0x02017ED8)

`func_02017ED8` folds two words down to sixteen bits and tests the result.
The original is twenty bytes of straight-line arithmetic with no spill:

```
02017ED8  ldr  r3, [pc, #0x20]   /* 0xFFFF0000 */
02017EDA  lsls r2, r1, #0x10
02017EDC  ands r1, r3            /* b & M   */
02017EDE  ands r3, r0            /* a & M, and the mask dies here */
02017EE0  lsls r0, r0, #0x10
02017EE2  lsrs r3, r3, #0x10     /* e1 */
02017EE4  lsrs r0, r0, #0x10     /* e2 */
02017EE6  lsrs r1, r1, #0x10     /* e3 */
02017EE8  eors r0, r3            /* acc = e2 ^ e1 */
02017EEA  lsrs r2, r2, #0x10     /* e4 */
02017EEC  eors r0, r1
02017EEE  eors r0, r2
```

The accumulator is `r0`, which holds `(u16)a`, and `(a & 0xFFFF0000) >> 16` is
`eors`ed into it. The obvious reading of that is "the source wrote `(u16)a`
first"; it is the wrong way round. The only spelling that reproduces the
twenty bytes is

```c
u32 x = ((a & 0xFFFF0000) >> 16) ^ (u16)a
      ^ ((b & 0xFFFF0000) >> 16) ^ (u16)b;
```

Reading the `eors` order back as the source order gives

```c
u32 x = (u16)a ^ ((a & 0xFFFF0000) >> 16)
      ^ ((b & 0xFFFF0000) >> 16) ^ (u16)b;     /* 48 bytes, 39 wrong */
```

which is eight bytes longer and opens `push {r3, r4}`: with the masking
expression second, the mask constant has to stay live across both `ands` and
the function runs out of scratch registers. Every other permutation of the
four operands was tried and each is wrong in its own way (7, 32 and 39
concrete bytes), so the order is fully determined and there is exactly one
source spelling.

The rule to apply when a commutative chain is one register out: the operand
whose value the accumulator *starts* with is the source's **second** operand,
and the first `eors` / `adds` / `orrs` names the source's **first**. This is
the positional half of
`docs/idioms/commutative-operand-order-names-the-temporary.md`, which covers
the same operator from the other side: there the question is whether a call
result sits left or right of a binary operator, here it is which of four
equal-cost subexpressions the compiler chose to accumulate into.

The masks themselves are also not free to respell. `(a & 0xFFFF0000) >> 16`
is an `ands` with a pool word and a `lsrs`, while `a >> 16` is a bare `lsrs`
and `(u16)(a >> 16)` folds back to the same bare `lsrs`; the mask-then-shift
form is what puts the pool word there, and it is that pool word dying into
`r3` that the register allocation above depends on.
