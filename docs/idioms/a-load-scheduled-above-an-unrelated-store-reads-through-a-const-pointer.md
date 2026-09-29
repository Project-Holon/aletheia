# A load the original schedules above an unrelated store is read through a const pointer

summary: when the only residue is one load that the original issues before a
store (to the outgoing-argument area, a global, or a struct copy's
destination) and ours issues after it, declare the pointer the load reads
through `const`; mwcc then treats the load as unable to alias the store and
the scheduler hoists it, with no other change to the function.

Found in: `src/matched/ov/ov021_func_021934F8.c` (0x021934F8),
`src/matched/ov/ov021_func_02193498.c` (0x02193498),
`src/matched/ov/ov021_func_0218DC84.c` (0x0218DC84),
`src/matched/ov/ov021_func_0218DDB4.c` (0x0218DDB4)

All four had sat as parked DIFF notes, each with a list of statement orders,
temporaries and local types that did not move the load.

The three shapes, original on the left:

```
ldr  r2, [r6, #8]      ; src[2]              ldr  r0, [sp, #0x128]
ldr  r0, [sp, #0x128]  ; stack arg e         str  r7, [sp]
str  r7, [sp]          ; outgoing arg 5      str  r0, [sp, #4]
str  r0, [sp, #4]      ; outgoing arg 6      ldr  r2, [r6, #8]
```

```
ldr  r3, =d_021DD9E0                          ldr  r5, [r0]        ; q[0]
ldr  r5, [r0]          ; q[0]                 ldr  r3, =d_021DD9E0
strh r4, [r3, #2]      ; global = a           strh r4, [r3, #2]
```
(with `d[1] = a; x = q[0];` in that order; a plain `int *q` keeps the
load below the `strh`, and hoisting `x = q[0]` above the store overshoots
the pool load)

```
strh r2, [r1, r0]      ; struct copy, 1st    strh r2, [r1, r0]
ldr  r0, [sp, #0x18]                         ldr  r0, [sp, #0x18]
ldr  r1, [r6, #0x70]   ; p->o, call arg      strh r0, [r5, #2]
strh r0, [r5, #2]      ; struct copy, 2nd    ...third strh...
                                             ldr  r1, [r6, #0x70]
```

The fixes are `const int *src`, `const int *q` and `const char *p` in the
signature. None of these functions writes through the pointer.

Related, narrower findings:
`const-pointer-lets-a-field-load-survive-a-store.md` (a reload disappears),
`const-hoists-the-loop-test-load-above-the-body-stores.md` (a loop bound),
`a-const-source-pointer-pulls-field-loads-up-next-to-the-call-result.md`.
Try `const` before any statement reordering whenever a load and a store trade
places.
