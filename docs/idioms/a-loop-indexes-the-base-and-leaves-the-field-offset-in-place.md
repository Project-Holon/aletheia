# In a loop, an indexed field access indexes the base and keeps the field offset out of the pointer

summary: `p->slots[i]` in a loop compiles as `base + i * stride` and then a
fixed field offset, so folding the offset into the pointer in the C text
(`*(T *)(p + off + i * stride)`) moves that add onto the loop-invariant base and
loses the shape.

Found in: `src/matched/ov216_func_021BC6B4.c` (0x021BC6B4),
`src/matched/ov215_func_021F5E68.c` (0x021F5E68),
`src/matched/ov204_func_021BF00C.c` (0x021BF00C)

A loop over a fixed-offset array member of a big struct emits the base plus the
scaled index first, and leaves the member offset as a separate constant:

```
    movs r4, #0
    ...
    lsls r0, r4, #3              ; i * 8
    adds r5, r6, r0              ; p + i * 8
    ldr  r0, [r5, #0x38]         ; member at +0x38
```

The natural-looking C that folds the member offset into the pointer instead
lifts `+0x38` onto the loop-invariant base, and the whole loop body shifts:

```c
/* wrong shape: the +0x38 is hoisted before the index */
for (i = 0; i < 6; i++)
    f(*(void **)(p + 0x38 + i * 4), 0);

/* right shape: model the member, the compiler orders index then offset */
struct S { char pad[0x38]; void *slots[6]; };
for (i = 0; i < 6; i++)
    f(p->slots[i], 0);
```

The same applies when the member offset is past the `ldr` immediate reach: a
struct member forces the offset to be materialised once per iteration (a
register or a pool word) while the index stays on the base, which is what the
original does. When the indexed access is *not* in a loop and the address is
reused, the compiler may legitimately hoist `base + off` instead; there the
flat `*(T *)(p + off + i * stride)` form is the right one, so read the loop
before choosing.
