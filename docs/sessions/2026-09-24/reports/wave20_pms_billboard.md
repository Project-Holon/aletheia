# Wave 20, lane pms_billboard (20E)

Seeds used: 4301 (0x0202E1F0), 4302 (0x0204EEC8).

| address | before -> after | verdict | what moved it |
|---|---|---|---|
| 0x0202E1F0 | 2 -> 2 | DIFF | nothing. Every spelling of the copy (struct pointer type, register, casts, `+ 0`, block scope) is propagated to `add r0, sp, #0x38`; second uses of the copy make every use a constant (312 to 371 out). Passing `ws` directly with no copy is also 2, so the lever is the missing use of w at the g call, not the copy. Permuter 800: flat |
| 0x0204EEC8 | 20 -> 14 | DIFF | st removed as a named local, `fmt & 7` written at both uses (permuter, seed 4302, minimised by hand). The st half of the prologue rotation closes. 720-order store sweep on the new source (relocations penalised): floor 14 at the current order |

0x0204EEC8 residue: a three-register rotation on the sb side (image sb ip, sb + 3 lr, 1 r5; compile lr, r5, ip), 5 of 5 relocations. Inert on it: u16 idx/b/fmt, table loads into locals in first-write order, a 120-compile declaration-order sweep with u32 and unsigned long idx, a `one` local, sb inlined, u32/unsigned long sb.

0x0202E1F0 residue: the compile colours o r6 / w r7 (as the image) only when w has no use at the func_02024368 call; the image does use r7 there.

Files written:
- docs/notes/pkt_0202E1F0.c.txt: wave-20 section, every measurement, best source unchanged (2).
- docs/notes/pkt_0204EEC8.c.txt: wave-20 section, every measurement, new best source (14) with the symbols block.
- this report.

Shards verified: none (nothing EXACT). Nothing filed in src/. No idiom file (nothing closed).

Seeds: none noticed.

Integrator: stage the two notes and this report. No figures change. Tool observation (no tools/ edit made): `permuter.py --out X` without a .c extension writes a file that `match.py one` measures as 3 of 5 relocations; the same bytes copied to X.c give 5 of 5. The symbols block seems to be read only from .c paths.
