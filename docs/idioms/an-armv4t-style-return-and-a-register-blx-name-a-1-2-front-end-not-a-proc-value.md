# An ARMv4T-style return beside a register blx names a 1.2 front end, not a -proc value

summary: mwccarm 1.2 under `-proc arm946e` emits register `blx rN` and the ARMv4T-style return
`pop {..., lr}; bx lr` in the same function, and it materialises 64-bit constants in registers where
every dsi build folds them into an immediate. Those two signatures identify functions built with the
older toolchain, which the project's pinned `dsi/1.1p1` can never reproduce. The fix is a per-file
compiler pin in the house header, not a `-proc` and not a spelling change.

Found in: the 3D rig library at `0x0205429C..0x020584E0`, which is where this was measured, and 68 open
ARM functions across the image carry the epilogue signature, 37752 bytes, 9.42 coverage points; 14 of
them, 9572 bytes, 2.39 points, also contain register `blx` and are therefore strictly 1.2-built

Two probes, compiled with the same flags (`-O4,p -proc arm946e -enum int -Cpp_exceptions off
-interworking -char signed -msgstyle gcc`), differing only in the compiler binary:

| | dsi/1.1p1, 2.0/sp2 | 1.2/base, 1.2/sp2 |
| --- | --- | --- |
| return of a non-leaf function | `pop {r4, r5, r6, pc}` | `pop {r4, r5, r6, lr}` then `bx lr` |
| indirect call through a pointer | `blx rN` | `blx rN` |
| 64-bit constant 2048 | `adds r0, r2, #2048` | `mov r0, #2048` then `adds r0, r2, r0` |
| small frame | `push {r3, lr}` / `pop {r3, pc}` | `stmfd sp!, {lr}` / `sub sp, sp, #4` / `add sp, sp, #4` / `ldmfd sp!, {lr}` / `bx lr` |

So a function holding register `blx` together with the ARMv4T-style return cannot be built by 1.1p1 at
any `-proc` value, and can be built by 1.2 at `-proc arm946e`. This dissolves what
`a-register-blx-with-a-pop-lr-return-is-a-toolchain-conflict-no-proc-value-emits-both.md` called an
unmatchable toolchain conflict, and it partly supersedes
`an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md`: that epilogue names an ARMv4T-style
*front end*, which is `-proc arm7tdmi` on dsi or plain `-proc arm946e` on 1.2. Distinguishing them is
cheap: a function with the epilogue and no register `blx` may be either (try `-proc arm7tdmi` first, it
needs no version change), while one with the epilogue *and* a register `blx` is 1.2-built.

What the repo does not see: `compiler_path()` joins the version under `.../mwccarm/mwccarm/dsi/`, so the
project's version sweep only ever enumerated the dsi builds and never crossed 1.2 or 2.0. A version
argument of `../1.2/sp2` resolves today, because the join lands on `.../mwccarm/mwccarm/1.2/sp2/
mwccarm.exe` and the only check is that the path exists.

How to file one, which the tooling already honours end to end:

```c
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
```

`match.py one --cc ../1.2/sp2`, `manifest --verify --shard` and `csrc.py` all read the header field back,
so an entry filed this way re-verifies and rebuilds with the compiler that produced its bytes. Measured
on the rig unit's own parked C, recompiled unchanged: `0x02057B10` goes from 56 differing bytes under
1.1p1 to EXACT (76 B); `0x02057EF8` from 111 to EXACT (148 B); `0x020583CC` from 47 to EXACT (80 B);
`0x02056460` from 118 to 10 of 172. Under the pinned config the best verdict for any of them is DIFF,
which is why none was filed.

Caveat before switching a whole region: three of that unit's four existing EXACT entries are reproduced
by both configurations, and `unit_0205841C` (196 B) is a genuine `-proc arm7tdmi` match on 1.1p1 whose C
was hand-tuned to it, so per-function pins must be chosen per function, by compile, not per region.
