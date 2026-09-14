# A call used directly as another call's argument is scheduled per site, so five identical statements do not all come out the same

summary: `g(f(p), x, k)` lets the compiler choose whether to evaluate `f(p)`
before or after `x`, and it makes that choice independently at every site, so
one source shape can be byte for byte right at three call sites and three
instructions wrong at the next two; binding the inner result to a local,
`t = f(p); g(t, x, k);`, pins the order everywhere and is the only spelling
that reproduces a run of identical statements identically.

Found in: `src/matched/sub_02018A7C.c` (0x02018BC0, 0x02018BFC, 0x02018C38,
0x02018C74, 0x02018CB0)

`func_02018A7C` computes five stats with five textually identical statements.
Each one evaluates an arithmetic expression into a local, fetches the record's
nature, and hands both to the scaling function:

```
02018C74  adds r5, r0, #5       /* the stat, folded into the divide's result */
02018C76  adds r0, r4, #0
02018C78  bl   func_02018598    /* the nature, fetched second */
02018C7C  lsls r1, r5, #0x10
02018C7E  lsrs r1, r1, #0x10
02018C80  movs r2, #3
02018C82  bl   func_02019B04
```

Written with the inner call inline,

```c
stat = (base[4] * 2 + iv4 + ev4 / 4) * level / 100 + 5;
func_02017E40(p, 0xA5, func_02019B04(func_02018598(p), (u16)stat, 3));
```

the first three of the five come out exactly as above and the last two do not.
There the compiler hoists the `bl func_02018598` in front of the arithmetic and
parks its result in `r5`:

```
adds r0, r4, #0
bl   func_02018598
adds r5, r0, #0       /* the nature now occupies the register ... */
...
blx  _s32_div_f
adds r1, r0, #0       /* ... so the +5 cannot fold into the divide's result */
adds r1, r1, #5
lsls r1, r1, #0x10
adds r0, r5, #0
lsrs r1, r1, #0x10
```

Three extra instructions at each of the two sites, twelve bytes, and 203
concrete bytes wrong once everything after them has shifted. Binding the result
first,

```c
stat = (base[4] * 2 + iv4 + ev4 / 4) * level / 100 + 5;
nature = func_02018598(p);
func_02017E40(p, 0xA5, func_02019B04(nature, (u16)stat, 3));
```

gives the original at all five sites and the whole 660-byte function is EXACT.

Two things make this worth a file.

**The failure is not uniform, and that is what misleads.** A source shape that
is wrong is normally wrong everywhere, so three identical statements matching
and the next two not reads as a register-pressure problem that starts partway
down the function, and the search goes looking for what changed at the fourth
stat. Nothing changed at the fourth stat. C leaves the evaluation order of a
call's arguments unspecified, mwccarm decides it per site out of whatever its
scheduler has in hand, and a local is the only thing in the source that
constrains it.

**It also decides the callee-saved registers.** With the call inline, the level
lands in `r7` and the current HP in `r6`; with `nature` bound they are the
original's `r6` and `r7`, with no other change to the source. Nothing about
those two register numbers points back at an argument five hundred bytes
earlier, which is the other half of the cost.

The reverse reading is the useful one: **a call result that reaches the outer
call in the argument register it returned in, with the other arguments already
set up, was written inline; one that is computed first and then moved out of
the way was written into a local.** The related tells for the same distinction
elsewhere in an expression are
`docs/idioms/cmp-operand-order-names-the-temporary.md` and
`docs/idioms/commutative-operand-order-names-the-temporary.md`; this is the
argument-position case, and unlike those two it is worth twelve bytes rather
than one.
