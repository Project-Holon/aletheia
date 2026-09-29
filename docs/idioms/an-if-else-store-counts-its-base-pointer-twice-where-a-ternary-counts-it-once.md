# An if/else pair of field stores counts the base pointer twice where the same store as a ternary counts it once, and that can decide which local keeps a callee-saved register

summary: when several locals that are live from entry compete for the last
callee-saved register, a store written as `t->f = c ? A : B;` counts `t` once
and `if (c) t->f = A; else t->f = B;` counts it twice. That one extra use can
move `t` into `r7` and push a different local onto the stack. The emitted code
for the store is the same either way (two pool loads, one `strh`), so the diff
shows up as a whole-function register swap, not at the store.

Found in: `docs/notes/pkt_ov012_02174744.c.txt` (0x02174744, parked 5 bytes out)

`func_02174744` is an 18-state machine. Four locals are live from entry: `req`,
`ctx`, `state` and one of `p`, `n`, `t`. The original gives `r7` to
`t = ctx->fC0` and spills `p` and `n`:

```
ldr r7, [r0]           /* t = ctx->fC0 */
...
str r1, [r7]           /* case 12: t->f0 = ... */
strh r0, [r7, #0x10]   /* t->f10 = 0x48b / 0x48c */
```

Written as a ternary, the case 12 store let `n` (and in an earlier variant,
`p`) take `r7`, leaving about 200 differing lines:

```c
t->f10 = (n == 0 || (p->f15C[0] & 2) == (p->f15C[n] & 2)) ? 0x48b : 0x48c;
```

Written as two arms, `t` wins `r7`, and what is left is 38 bytes of
spill-slot offsets:

```c
if (n == 0 || (p->f15C[0] & 2) == (p->f15C[n] & 2))
    t->f10 = 0x48b;
else
    t->f10 = 0x48c;
```

These did not move `t`: `register`, reordering the declarations, reusing `t`
as the case 8 temporary (four more uses), and giving `n` an unsigned type. The
use count that matters is the one the front end sees for each statement, not
the count in the emitted code.

With the register settled, the spill slots follow declaration order
(`function-scope-versus-block-scope-decides-spill-slot-order.md`,
`local-declaration-order-is-stack-order.md`). Here that meant declaring
`Slot *slots;` first and `q` before `cnt`/`mine`, which brought the function
to 5 bytes.
