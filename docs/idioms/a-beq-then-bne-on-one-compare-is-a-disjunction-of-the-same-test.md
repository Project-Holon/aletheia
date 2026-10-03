# A beq then bne on one compare is a disjunction of the same test

summary: `cmp r0, #1; beq T; bne F; T: movs r0, #1` (two branches on one set of flags,
the first jumping over the second) is `if (r == 1 || r == 1) return 1;`: one branch per
operand of `||`. The original likely compared against two constants with the same value.

Found in: src/matched/ov/ov093_func_021E86C8.c (0x021E86C8, ov093, Thumb)

The image tests `func_021C8168(a) == 0`, then `func_021B8DDC(b)`:

```
cmp r0, #1
beq ret1
bne ret0
ret1: movs r0, #1
```

Plain `if (... == 1)`, `&&` chains, ternaries, switch with `case 1`, `x == 1 || x != 1 && 0`
and nested retests give one `bne` (30-34 bytes). Two equal operands of one `||` give both
branches with the right targets:

```c
r = func_021B8DDC(b);
if (r == 1 || r == 1)
    return 1;
```

A `goto one` / `goto zero` pair (`if (r == 1) goto one; if (r != 1) goto zero; one:`) also
matches. Related: a-dead-repeated-branch-is-a-nested-retest.md.
