# A register-carried index in an unrolled walk is the spelled-out form, not a loop

summary: when a short fixed-count walk is fully unrolled but each element is
loaded through `movs rN,#i; ldrsb rM,[r0,rN]` instead of `ldrsb rM,[r0,#i]`,
the source spelled the arms out with a variable index re-assigned before each
arm; the same work written as a `for` loop stays rolled, and literal indices
use immediate offsets.

Found in: `src/matched/func_021D53DC.c` (0x021D53DC, ov093, Thumb)

`func_021D53DC` clamps the first seven signed bytes of `p` to a floor of 6 and
returns whether anything changed. The traced extent is the full 100 bytes
(0x021D53DC..0x021D5440). It is unrolled, but every load carries its index in a
register:

```
021D53DC  movs r1, #0          /* i = 0, also the changed flag */
021D53DE  ldrsb r2, [r0, r1]
021D53E0  cmp r2, #6
021D53E2  bge  #0x21d53ea
021D53E4  movs r1, #6
021D53E6  strb r1, [r0]        /* store offset is immediate */
...
021D53EA  movs r2, #1          /* i = 1, fresh register keeps r1 as the flag */
021D53EC  ldrsb r3, [r0, r2]
...
```

Three source shapes were measured against the same 100-byte extent:

```c
/* rolled: 32 bytes, the loop is not unrolled at all */
int changed = 0; int i;
for (i = 0; i < 7; i++) if (p[i] < 6) { p[i] = 6; changed = 1; }

/* immediate-offset unroll: right count of arms, wrong addressing */
if (p[0] < 6) { p[0] = 6; changed = 1; } ... if (p[6] < 6) { ... }

/* EXACT: arms spelled out, one variable index re-assigned before each */
int changed = 0; int i = 0;
if (p[i] < 6) { p[i] = 6; changed = 1; }
i = 1;
if (p[i] < 6) { p[i] = 6; changed = 1; }
...
i = 6;
if (p[i] < 6) { p[i] = 6; changed = 1; }
return changed;
```

The distinguishing tell is that the load's index is a register (`[r0, r1]`,
`[r0, r2]`) while the store's offset is immediate (`[r0, #1]`). A literal index
folds the load to an immediate offset too, and a `for` loop of the same body is
left rolled. The register form is what the optimizer emits for a variable index
that is still live across each arm, which is why the flag arithmetic reuses it
(`adds r1, r2, #0` at the one arm where the flag is set from the index).
