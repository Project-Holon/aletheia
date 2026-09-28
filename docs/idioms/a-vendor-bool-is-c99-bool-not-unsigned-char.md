# A DWARF `bool` in a libdwcutil object is C99 `_Bool`, not an `unsigned char` typedef

summary: libdwcutil's DWARF types flags and parameters as one-byte `bool`; declared as
`unsigned char`, a converted argument such as `pushIpAuto(x != 0)` gains an `and r0, r0,
#0xff` the original lacks, while `typedef _Bool bool;` under `-lang c99` gives the bare
`movne r0, #1 / moveq r0, #0` and changes nothing in functions that only store or test.

Found in: src/matched/ov016_func_021C8A6C.c (0x021C8A6C, pushWinButton)

The original passes a comparison straight to a `bool` parameter:

```
sub  r0, r4, #2
teq  r0, #1
movne r0, #1
moveq r0, #0
bl   pushIpAuto
```

With `typedef unsigned char bool;` the same C (`pushIpAuto(((focus - 2) ^ 1) != 0)`) adds
`and r0, r0, #0xff` before the call, because the caller narrows to the parameter type.
`_Bool` is already 0 or 1, so the narrowing disappears. All 27 scenesetlist.o functions were
re-verified EXACT after switching the shared prelude, so the choice only shows where a value
is converted.
