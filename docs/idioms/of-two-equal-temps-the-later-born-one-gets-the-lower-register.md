# Of two equal temps, the later-born one gets the lower register

summary: mwcc's colouring pushes virtual registers onto the simplify stack in ascending birth
order and pops them in reverse, giving each the lowest free register. So when two values have
the same cost and interfere, the one created later in the IR gets the lower register. A swap of
two such values means the original created them in the other order.

Found in: src/pending/ov/ov114_func_021C8BC4.c (lane G1R7, read from mwcc's Coloring.c in the
inspiredrobot/mwcc repository).

How to use it:
- Find which value the original puts in the lower register: that value was born later.
- Look for a human source form that creates that value later in the IR without moving its load
  or use: a later declaration point, a later first assignment, splitting an expression so the
  other value is computed first, a temp introduced by a library call or struct copy.
- Loads fused into post-increment addressing fix the birth order to the load order, so a swap
  inside such a loop usually needs a different loop form, not a different declaration order.

Related: two-long-lived-values-in-each-others-registers.md, declaration-order-picks-the-register-
initialisation-order-picks-the-load.md.
