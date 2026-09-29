# A switch value loaded into r1 but dispatched in r0 is read again as a call argument in an arm

summary: when a state machine loads `*state` into r1 (`ldr r1, [r5]; cmp r1, #4`) yet computes the jump-table index in r0 (`adds r0, r1, r1`), and the arms that call through a function table avoid r1 for the pointer (`ldr r2, [r0, r2]; blx r2`), the switch value is still live in r1 as the callee's second argument: `*state = tbl[i].fn(p, *state)`. A one-argument callback puts the whole dispatch in r0; a hidden-argument `bl` (the other r1 idiom) puts the index computation in r1 as well.

Found in: src/matched/ov/ov023_func_02184674.c (0x02184674)

The image:

```
02184698  ldr  r0, [r5]
0218469C  str  r0, [r4, r6]       ; p->f194 = *state
021846A2  bl   func_0218644C      ; (p, *state), void
021846A6  ldr  r1, [r5]           ; switch value in r1 ...
021846A8  cmp  r1, #4
021846AC  adds r0, r1, r1         ; ... index computed in r0
...
021846F2  lsls r2, r0, #3         ; case 1: r2/r3 for the table, never r1
021846F6  ldr  r2, [r0, r2]
021846FE  blx  r2                 ; r1 = *state still, from the dispatch
02184700  str  r0, [r5]
```

Spellings and what they gave:

- `int (*fn)(char *p)` and `*state = fn(p);`: the switch value dies at the
  dispatch, so `ldr r0, [r5]; cmp r0, #4; adds r0, r0, r0` and the case arms
  pick r1 for the function pointer (12 concrete bytes over 15 instructions).
- The hidden-argument reading
  (`a-switch-index-in-r1-with-an-argless-bl-in-an-arm-names-a-hidden-argument.md`,
  since two arms open with an argument-less `bl func_020221A4`): the value
  moves to r1 but so does the whole five-instruction index computation. That
  idiom's shape is r1 throughout; this one is load in r1, index in r0.
- `int (*fn)(char *p, int state)` with `*state = fn(p, *state);` in both table
  arms: EXACT. The compiler CSEs `*state` with the switch operand, so r1 is
  live into the arms and the index is computed in the free r0.

The discriminator is which register the `adds rX, r1, r1` writes: r1 means
something keeps r0 live across the dispatch; r0 means the switch value itself
stays live into an arm, usually as an argument.
