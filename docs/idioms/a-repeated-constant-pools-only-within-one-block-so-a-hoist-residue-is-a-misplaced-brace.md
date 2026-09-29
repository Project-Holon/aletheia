# A repeated constant pools only when its uses are in one block, so a hoist-shaped residue is a misplaced brace first

summary: when a function is one instruction longer than the image because a
small literal got hoisted into a callee-saved register, check whether the
literal's uses sit in the same basic block before blaming the front end. mwccarm
pools a repeated constant only when the uses are in one block; move one use into
a different block and the hoist disappears without touching the literal at all.
A partial hoist -- some repeated constants pooled, some not -- is almost always a
statement in the wrong place, not a compiler-version difference.

Found in: src/matched/ov_sdk/ov016_func_021CAA9C.c (0x021CAA9C)

`endScene2` calls `DWCi_GXlInvisible(1, 1)`, `DWCi_GXlInvisible(0, 0x15)` and
`DWCi_SetParam_(0, 0)` / `DWCi_SetParam_(2, 1)`. Written with the first
`GXlInvisible` outside its guard, that is three uses of `1` in one straight-line
region and three of `0`, and 1.1p1 hoists both:

```
021CAFFC  mov r5, #1          <- the spurious hoist
021CAB00  mov r0, r5
021CAB04  mov r1, r5
...
021CAB08  mov r4, #0
```

204 bytes in the image, 208 compiled, and the only real difference is
`mov r5, #1` plus the wider `push {r3, r4, r5, lr}`. Read as a front-end
difference it is very convincing: the image pools `0` but not `1`, dsi/1.1p1
pools both, and the 2.0/* tree pools neither, so the object (stamped
4.0.0.1025, between the installed 1.1p1 = build 1024 and 1.2 = build 1026)
appears to want a compiler that is not on this machine.

The image's `bne` says otherwise. It targets `0x021CAB08`, which is *past* the
first `GXlInvisible`, so the call is inside the guard and its use of `1` is in a
block of its own:

```c
if (Choose == 0) {
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);      /* inside: the bne skips it too */
}
DWCi_GXlInvisible(0, 0x15);
```

That one re-indentation is EXACT, 204 bytes, no cast and no prototype change.

The diagnostic, stated generally: the pooler works per block, so a constant that
*looks* repeated in the disassembly may not be repeated in the flow graph. Before
sweeping compiler pins, read the branch target of the guard that sits between
the uses. Measured flat while chasing the wrong answer: 19 compiler pins, and 23
spellings (argument casts, enum and `static const` locals, `u8`/`u16`/`s8`/
`bool`/`void*` parameter types, and the 0 bound to a local in the
copy-the-first-zero shape of
`a-second-zero-must-be-spelled-as-a-copy-of-the-first.md`). Not one moved the
hoist, because none of them moved the statement.

The cheapest tool is a matched sibling: the static copy of `endScene2` at
0x021CB5D8 in the same vendor object was EXACT already, and its block structure
showed the answer immediately. See `docs/notes/pkt_ov016_021CAA9C.c.txt` for the
full measurement log, including the wrong turn.
