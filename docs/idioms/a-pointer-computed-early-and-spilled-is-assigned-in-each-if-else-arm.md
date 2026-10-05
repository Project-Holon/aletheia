# A pointer computed early and spilled is assigned in each if/else arm

summary: When the image computes a pointer right after an if/else join, spills it, and
uses it once much later (after several calls), but the draft computes it at the use, the
source assigned the pointer in BOTH arms of the if/else. Two definitions stop the
compiler from forwarding the single-use local to its use. The identical arm tails then
merge, so the image shows one copy of the computation after the join.

Found in: src/matched/ov/ov171_func_021DE388.c (0x021DE388)

The image, after an if/else that sets `v` to `i + 6` or `i`:

```
lsls r0, r4, #0x10      ; else arm, the if arm branches here after its own lsls
lsrs r0, r0, #0x10      ; v
str  r0, [sp, #0x18]    ; v spilled
lsls r1, r0, #2
ldr  r0, [sp, #0x28]    ; p + 0xB74, hoisted
adds r0, r0, r1
str  r0, [sp, #0x1c]    ; slot spilled, used after four calls
```

The draft `slot = (u32 *)(p + 0xB74 + v * 4);` after the if/else is forwarded to
`*slot = f(...)` at the end of the loop body. Then the five loop-invariant offsets
hoist in a different order, `v` and `x` swap registers, and 245 listing lines differ.

This gives EXACT (with `slot` declared before `v` for the 0x1c/0x18 slots):

```c
if (*(u8 *)(p + 0xC60) == 1) {
    ...
    v = (u16)(i + 6);
    slot = (u32 *)(p + 0xB74 + v * 4);
} else {
    v = (u16)i;
    slot = (u32 *)(p + 0xB74 + v * 4);
}
```
