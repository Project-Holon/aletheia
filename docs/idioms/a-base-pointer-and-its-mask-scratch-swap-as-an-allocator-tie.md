# A base pointer and the mask scratch of a read-modify-write can swap as an allocator tie

summary: when a short block computes `base = obj + off`, loads a halfword through
it, masks that load with a constant for a compare, and ORs the constant back for
the store, the register holding the base and the register holding the mask
result are two scratch colours the allocator is free to swap.  Every general
source lever leaves the byte count identical; the tie recolours only the load
sequence and is not movable from C.

Found in: `src/pending/ov_sdk/ov009_func_021679C0.c` (0x021679C0, ov009,
`WcmWmcbReset`, libwcm.TWL.HYB.a(wmif.o), 756 B, 19 B out)

The image's read-modify-write is

```
add r0, r4, #0x1300   ; base -> r0
ldrh r2, [r0, #0x10]  ; v    -> r2
and r3, r2, #0x24     ; temp -> r3
cmp r3, #0x24
beq fail
orr r2, r2, #0x24     ; OR reuses v's r2 (in-place)
strh r2, [r0, #0x10]
```

and 1.1p1 emits the same five instructions with the base and the mask scratch
swapped: `base -> r3`, `temp -> r0`, and the OR result takes the freed mask
register rather than v's r2 (`orr r0, r2, #0x24; strh r0, [r3, #0x10]`).  The
base is live across the whole block and the mask result dies at the `cmp`, so
the allocator is free to colour the pair either way; nothing crosses a call or
a join.

The levers measured, all byte-identical at 19 B out:

* named `v` local vs. inline `p[8]` in both the test and the store;
* `v |= 0x24; p[8] = v;` vs. `p[8] = v | 0x24;` vs. `p[8] = p[8] | 0x24;` vs.
  `p[8] |= 0x24` (the last strictly worse, 22 B, from a different lowering);
* reading/writing the halfword through a struct member (`wcmw->field22EA`) vs.
  raw pointer arithmetic for the *preceding* status field - inert, so the tie
  is local to this block, not the earlier base;
* `v` declared `unsigned short` vs. `unsigned int` - inert;
* `p` declared `unsigned short *p;` assigned after the guard vs. initialised at
  declaration (worse, the initialiser sinks and reorders the guard, 33 B);
* declaration order of `p`/`v` both ways, and the no-code self-assignment
  `v = v;` - inert.

A second, separate scheduler tie sits one arm later at +0184: the shared
`case 3/default` wmResult arm emits `ldr r3,[pc]; mov r2,r5; add r1,r0,#0x1000`
where the image has `ldr r3,[pc]` before `add r1`.  Reordering the switch arms
to make that arm the fall-through changes the block predecessor set and is
strictly worse (27 B), so the arm order is already the image's; the swap is a
branch-target-vs-fall-through scheduling artifact.

Rule: a same-size residue confined to one load/mask/OR sequence, where no
declaration order, statement order, named temporary, member spelling or width
moves it, is this allocator tie.  Record it and move on; both registers are
scratch and neither crosses a boundary.
