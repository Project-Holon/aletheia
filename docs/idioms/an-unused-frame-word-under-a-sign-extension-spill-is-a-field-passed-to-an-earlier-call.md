# An unused frame word under a sign-extension spill is a field passed to an earlier call

Shape: a Thumb function with an `FX_Mul`-style inline (`(long long)a * b`) in a
loop. The compiler hoists `b >> 31` (the high word of the sign-extended
multiplier) into a stack slot. In the image there is one frame word just
below that high-word slot that nothing reads or writes (frame one word larger,
`push {r3, ...}` for alignment); your build packs the slots with no gap, so
every slot above it is off by 4.

Cause: the multiplier local `s = p->f4` is also the argument of an earlier
call (`base = FX_Div(s, 0x2000)`). Passing the local makes the 64-bit
sign-extension pair coalesce its low word with `s`'s own slot. Passing the
field expression instead (`FX_Div(p->f4, 0x2000)`, still CSE'd into the same
single load) keeps the pair separate: its low word gets its own (dead) slot.

Fix: spell the earlier call's argument as the field read, keep the local for
the loop.

Seen in: ov021 func_0218D1D0 (wave A2).
