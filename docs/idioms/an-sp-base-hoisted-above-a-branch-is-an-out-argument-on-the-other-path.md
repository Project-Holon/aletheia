# An sp-relative base hoisted above a branch is an out-argument on the other path

summary: when `add rN, sp, #k` sits between a compare and its branch and one
arm uses it as the base for struct-field loads, look for a callee in the other
arm that takes a pointer to a local at sp+k. The address is computed in both
successors (field base on one side, `&local` argument on the other), so mwcc
CSEs it and hoists it into the compare block. A draft that leaves the slot at
sp+k as padding (or calls the callee without the out pointer) keeps the
`add` below the branch and never reaches the image.

Found in: src/matched/ov/ov021_func_02189BD0.c (0x02189BD0, ov021).

Image:

```
cmp  r2, #0xff
add  r1, sp, #0x28      ; base for in.f0 (fallthrough) and &id (target)
beq  target
ldrh r1, [r1, #0x14]    ; in.f0
...
target:
adds r0, r4, #0
add  r6, sp, #0x28
bl   func_021CD440      ; func_021CD440(pos, &id): r1 is still sp+0x28
```

Fix: declare the out local (`u16 id;`, last declared so it takes the lowest
slot) and pass it: `if (func_021CD440(pos, &id) == 1)`. Check matched callee
sources for the real prototype before treating a spare stack slot as padding.
