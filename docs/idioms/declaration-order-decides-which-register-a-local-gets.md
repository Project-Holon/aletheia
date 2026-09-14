# Two locals live across the same loop take registers in declaration order, and the order they are initialised in is not it

summary: when two locals are live across one loop, the one declared first gets
the lower callee-saved register, and swapping the two declarations swaps every
occurrence of both registers; the order the zeroes are stored in the compiled
code is the *reverse* of the declaration order as often as not, so reading the
initialisation order back as the source order is what costs the time.

Found in: `src/matched/unit_0200BBC8.c` (0x0200BCB8),
`src/matched/unit_0200C7C0.c` (0x0200C7C0),
`src/matched/unit_0200DF10.c` (0x0200DF94)

`docs/idioms/local-declaration-order-is-stack-order.md` records the same cause
for locals that reach the stack: the later declaration sits at the lower
address. This is the register half of it, and it is harder to spot, because the
diff is a run of register numbers rather than a run of offsets.

`func_0200BCB8` counts the used slots of a two-slot record:

```
0200BCB8  push {r3, r4}
0200BCBA  movs r4, #0          /* the counter */
0200BCBC  movs r3, #0          /* the index   */
0200BCBE  movs r1, #0xe4
0200BCC0  adds r2, r3, #0
...
0200BCCA  adds r4, r4, #1
0200BCCC  adds r3, r3, #1
```

The counter is zeroed first and lives in `r4`; the index is zeroed second and
lives in `r3`. The obvious reading of that is "the counter was declared first",
and it is wrong:

```c
u32 n = 0;                 /* n -> r3, i -> r4:  7 bytes differ */
s32 i;

s32 i;                     /* i -> r3, n -> r4:  EXACT          */
u32 n = 0;
```

Both spellings emit the two `movs` in the same order and with the same
immediates; only which register each one targets changes, and with it every
later use of both. Nothing else in the function moves, which is what makes it
read like a scheduling problem rather than like a declaration.

`func_0200C7C0` is the same finding with the roles the other way round, so the
rule is not "the counter goes high". There the running sum is in `r2` and the
index in `r3`, and the source that reproduces it is `u32 base = 0, i = 0;`,
with the sum declared first. `func_0200DF94` is a third instance and agrees.

The rule to apply: when a function is byte for byte right except that two
registers are consistently interchanged, do not look at which value is
initialised first. Count the registers: the local in the lower one was declared
first, and the source order follows from that alone.
