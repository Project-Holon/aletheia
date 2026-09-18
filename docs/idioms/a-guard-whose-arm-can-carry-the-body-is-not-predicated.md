# A guard whose arm can carry the whole body is not predicated

summary: `docs/idioms/an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md`
says a five-instruction-or-shorter guard body is always predicated and a short
`bx<cond> lr` in the original is unreachable; that is true of the *arm as
written*, but not of the function, because moving the body into the arm pushes
it past the threshold and restores the original's real branch at no cost.

Found in: `src/matched/func_02062D08.c` (0x02062D08)

The original branches over its guard and puts the `return 0` block after the
body:

```
ldr   r3, [r0, #0x1c]
ldrh  r2, [r3]
cmp   r1, r2
bhs   L_ret0
... five more instructions of body ...
mov   r0, #1
bx    lr
L_ret0:
mov   r0, #0
bx    lr
```

The guard spelling produces 52 bytes against the original's 56, because the
arm `{ return 0; }` is one instruction and gets folded into predicates
(`movhi r0, #0` / `pophi {r3, pc}`), which is the documented behaviour:

```c
if (i >= count) { return 0; }
...body...
return 1;
```

The positive spelling produces the original exactly:

```c
if (i < count) {
    ...body...
    return 1;
}
return 0;
```

Here the arm is the body -- nine instructions, well past five -- so the
predication threshold is never met.

Rule: before recording a short-guard function as a measured near miss, check
whether the guard has a mirror-image spelling whose arm carries the body. It
works whenever the guarded body (not the `return`) is long enough on its own.
It does not help the three setters in
`docs/notes/g2d_srt_setters.c.txt`, whose guard arms are a single store each
and have no body to move.
