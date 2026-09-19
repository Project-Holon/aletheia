# Whether short guard arms are predicated is the front end, not the shape

summary: four independent `if (p) *p = ...` arms of four instructions each are
if-converted into `ldrne`/`andne`/`strne` chains by `dsi/1.1p1` (100 bytes) and
kept as `cmp`/`beq` arms by `dsi/../2.0/sp2` (116 bytes), so an image full of
guard branches is evidence for the 2.0 front end and not for an unreachable C
spelling.

Found in: `src/matched/func_0206AE94.c` (0x0206AE94)

The image spreads the four bytes of one word into four optional word-sized
out-parameters, and each arm is a branch, with only the last one predicated as
an early return:

```
0206AE94  00 00 50 e3  cmp r0, #0
0206AE98  03 00 00 0a  beq 0x0206AEAC
0206AE9C  60 c0 9f e5  ldr ip, [pc, #0x60]
0206AEA0  a0 c0 9c e5  ldr ip, [ip, #0xa0]
0206AEA4  ff c0 0c e2  and ip, ip, #0xff
0206AEA8  00 c0 80 e5  str ip, [r0]
...                                    cmp r1 / beq / body, cmp r2 / beq / body
0206AEE8  1e ff 2f 01  bxeq lr        <- the last arm only
```

`dsi/1.1p1` if-converts all four arms (the arms fall inside the
predication budget of
`an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md`), which
drops the branch words and leaves 100 bytes against the original's 116 with 81
differing bytes:

```
0206AE94  00 00 50 e3  cmp r0, #0
0206AE98  00 c0 9f e5  ...  ldrne ip, [pc, #0x54]     /* 1.1p1 */
0206AE9C  ...              ldrne ip, [ip, #0xa0]
0206AEA0  ...              andne ip, ip, #0xff
0206AEA4  ...              strne ip, [r0]
```

`--cc ../2.0/sp2` with the same C reproduces the 116 bytes with zero concrete
differences, and is the filed pin for this row (the packet is pinned as a family
in `docs/FRONTEND-PINS.md`).

Ruled out on the way, all of which still if-convert under 1.1p1: `volatile` on
the destination pointers, `volatile` on the global, `if (p)` versus
`if (p != 0)`, the word bound to one named local, and `-proc arm7tdmi`. So the
"the branches are unreachable from plain C" record left by an earlier lane for
this address was a front-end choice, not a spelling wall: when the guard arms
are branches and the packet already carries 2.0 evidence, reach for the pin
before writing the row off.
