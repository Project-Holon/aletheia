# Distinct goto labels parked at the function tail keep lone per-arm epilogue pops from tail-merging

summary: when a switch arm whose body is only `return;` must reproduce a fresh
`pop` written into the arm (or its jump-table slot), two things are needed: the
return must have its own *distinct* target, and that target must sit after the
whole switch, not beside it. A plain shared `return;`, or `goto` labels placed
next to their switches, makes mwccarm tail-merge the lone `pop` into a
neighbouring `...; bl; pop` and emit `b <shared pop>` instead.

Found in: `src/pending/ov_sdk/ov009_func_021674BC.c` (0x021674BC,
`WcmWmcbConnect`, libwcm.TWL.HYB.a(wmif.o)), measured 2026-10-01 in wave 8.

The image has three empty returns each with its own
`pop {r4, r5, r6, pc}`: the `case 6:` slot of the state switch, the `default`
slot of the nested phase switch, and its `case 11:` slot. Written as plain
`return;` the front end merges the lone `pop`s into the tails of nearby
`...; bl WcmWmReset; pop` blocks and puts `b <shared pop>` in the three slots
(12 concrete bytes out). This is the reverse of
[a shared exit block is written out in each arm](a-shared-exit-block-is-written-out-in-each-arm.md):
there the image cross-jumped and the source repeated the statements; here the
image did NOT cross-jump, which is the
[two failure returns need two labels](two-failure-returns-need-two-labels-or-the-compiler-merges-them.md)
case, one label per arm.

The placement is the new part. Giving each arm its own `goto Rk;` with the
three labels written as the last statements of the function (after the outer
switch) closes the three slots exactly; mwccarm then emits the lone `pop`
inline in each arm/table slot. Moving the same labels back next to their
switches (inside the enclosing case) re-arms the merge and the three slots go
straight back to `b <shared pop>` — the labels' *position in the source* decides
whether the merge pass fires, not just their count. The function lost 4 of the
12 residue bytes as a side effect of the changed CFG (a pool-load scheduling
tie in an unrelated arm moved), which is the tell that the merge pass really did
stop.
