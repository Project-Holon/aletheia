# A negated if-condition on a loop-invariant flag is materialised and hoisted, so the complement flag is not in the source

summary: for `if (flag) A else B` inside a loop, 1.1p1 computes `!flag` as a 0/1 value (`mov rX, #1 / cmp rF, #0 / movne rX, #0`), hoists it to the preheader and branches `bne B` with A as the fall-through. A register holding `!flag` before a loop is that hoisted test, not a second variable; writing the complement out (`is_high = !is_low; if (!is_high)`) gives the same loop body but moves the loop's other invariants.

Found in: src/matched/func_0209739C.c (0x0209739C, MSL __dec2num)

The image computes r7 = !is_low before the refinement loop and tests
`cmp r7, #0 / bne dec` at the loop head, increment arm first. The source is
`if (is_low) { ++*ll; if (isinf(guess)) goto done; } else --*ll;` with no
is_high at all. `is_high = !is_low` with `if (!is_high) {inc} else dec` emits
identical loop instructions, but 1.1p1 then places the loop's invariants
(&x64, &dec, the zero high word of a `& 1` mask) at the top of the region after
the preceding loop and merges them with earlier copies, instead of at the
loop preheader: 721 bytes out and 4 bytes short, which held this function from
wave 9 to wave 17. `if (is_high) dec else inc` materialises `!!is_low`
(`moveq`) and lays the decrement out first.
