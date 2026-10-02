# A constant kept in a callee-saved register and shifted in a merged tail is a statement repeated in each arm

summary: when a large Thumb constant such as 0x2000 is built as `lsls rX, rK, #12` from a
small value (`movs rK, #2`) held in a callee-saved register for the whole function, and the
last use sits in a tail shared by both arms of an if, the source writes that statement in
each arm. The compiler tail-merges the arms after it has pooled the small half of the
constant, so the 2 stays live across every call.

Found in: src/matched/ov/ov021_func_021AC760.c (0x021AC760, ov021, Thumb)

The original opens with `movs r1, #2` (a call argument) and `movs r6, #2`, then later
builds `0x2000` twice as `lsls rN, r6, #12`: once as a call argument before an if, once
for `v.z -= 0x2000` after the arms join. Holding the 2 costs a callee-saved register, so
another parameter is spilled (`str r2, [sp, #8]`) and `r3` joins the push.

Writing `v.z -= 0x2000;` once after the if folds the constant and rematerialises it at
each use: 123 bytes differ. Every attempt to make the 2 a "real" variable stayed flat
or got worse: int, u8/u16/s16/u32, const and enum locals, `static const`, a one-element
array, an inline helper parameter, a loop-defined local, a zero-valued-local add, and
reassignments. (An enum local does stay real, but the compiler then CSEs `k << 12` into
one register, which the original does not.)

Writing the statement in both arms is exact, with the literal and with no local at all:

```c
if (func_0216D55C(b, 0x2000) != 0) {
    v.y += 7 * 0x1000;
    v.z -= 0x2000;
} else {
    func_02163E58(b, &v, &tmp);
    v.y = tmp + 9 * 0x1000;
    v.z -= 0x2000;
}
```

The tell: the shared tail already holds other merged material (here `movs r0, #7` /
`movs r0, #9` jumping to one `lsls r0, r0, #12; adds`), and the unexplained register
constant is used only there and at sites before the branch. Before hunting for a source
variable, try repeating the tail statement in each arm.
