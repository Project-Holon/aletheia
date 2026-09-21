# Per-file compiler pins: the policy and the evidence

The project pins `dsi/1.1p1` with `-O4,p -proc arm946e` as the default for every file, and the pinned
front end is what produced the overwhelming majority of this image. It did not produce all of it. Where the
bytes themselves prove a different front end built a function, that function may carry a per-file pin, and
the evidence is recorded here at the time the pin is taken.

Rule, adopted 2026-09-19 by the owner:

1. A pin names a front end the tooling already has: `compiler: ../1.2/sp2` or `compiler: ../2.0/sp2` in the
   file's house header. `match.py` resolves it verbatim under its dsi directory, `manifest --verify` records
   it as `dsi/../1.2/sp2` in the shard, and `tools/csrc.py` peels only the `dsi/` prefix so the chain builds
   the file with the same compiler the shard claims.
2. A pin requires byte evidence, not a hunch: an instruction or an instruction pair the pinned front end
   cannot emit, quoted from the image, plus the probe that shows the alternative front end emitting it.
3. The evidence goes in this file, one entry per function, with the addresses of the differing bytes.
4. Sweeping compiler versions over a whole file or a whole range is still forbidden. A pin is one decision
   per function, confirmed by compile.

## The front-end tells, measured

| tell | what it looks like | what it proves |
|---|---|---|
| interworking conflict | a register `blx rN` in the same function as an ARMv4T-style return `pop {..., lr}` then `bx lr` | mwccarm 1.2. Under `-proc arm946e` every dsi build emits `pop {..., pc}` instead, so no dsi front end can produce the pair |
| constant materialisation | the image has `mov rD, #2048` then `adds rD, rS, rD`; dsi/1.1p1 folds the same source to `adds rD, rS, #2048` | mwccarm 1.2 for that function. Probe re-run on 2026-09-19: `dsi/1.1p1 -O4,p -proc arm946e` gives `e2920b02 adds r0, r2, #2048`, `../1.2/sp2 -O4,p -proc arm946e` gives `e3a00b02 mov r0, #2048` + `e0920000 adds r0, r2, r0` |
| frame padding | the image uses `sub sp, sp, #4` where a dsi build pads a five-register frame with a dead `push {r3}` | 1.2 for that function |
| kept constants | the image rematerialises a constant from the pool where the build keeps it live in a callee-saved register | 2.0 |

## Pins in force

| file | pin | evidence |
|---|---|---|
| `src/matched/func_020525A0.c` | `../1.2/sp2` | 1.1p1 emits a five-register frame with a dead `push {r3}` where the original uses `sub sp, sp, #4` |
| `src/matched/func_02052634.c` | `../1.2/sp2` | same tell as above, same family |
| `src/matched/func_020624C8.c` | `../2.0/sp2` | 1.1p1 keeps two heap addresses live where the original rematerialises them from the pool |
| `src/pending/func_0206B6A4.c` | `../2.0/sp2` | same tell as above, same family |
| `src/matched/func_02074A6C.c` | `../2.0/sp2` | 44-byte accessor: the image is `push {r3, lr}` / `mov r3, #1` / `mov ip, #0; str ip, [sp]` with the boolean rebuilt from immediates, the "kept constants" tell above, measured on a third family; 1.1p1 also schedules the pair differently |
| `src/matched/func_02074A98.c` | `../2.0/sp2` | same shape, same packet, same measurement (44 bytes) |
| `src/pending/func_0206AD64.c` | `../2.0/sp2` | 88 bytes with 0 concrete mismatches under the pin against 96 under 1.1p1; same tell, measured by wave r6's small-3 lane. Parked, not filed |
| `src/pending/func_0206AE2C.c` | `../2.0/sp2` | 104 bytes, same measurement and lane |
| `src/matched/func_02072D20.c` | `../2.0/sp2` | 120-byte ARM body: 1.1p1 emits the same 120 instructions in the same order and is 4 bytes out on one decision, sharing the literal `1` into callee-saved `mov r5,#1` + `mov r0,r5` where the image (and 2.0) emits `mov r2,#1` + `mov r0,#1`. 19 1.1p1 spellings measured, all share the constant |
| `src/pending/func_02072E7C.c`, `src/pending/func_02072E8C.c`, `src/pending/func_0209128C.c` | `../2.0/sp2` | byte-correct under the pin where 1.1p1 is a pool-load-order DIFF (E7C, E8C) or a one-byte predication DIFF (128C); parked with one own-pool wildcard each |
| `src/matched/func_020528A8.c`, `src/matched/func_020528BC.c`, `src/matched/func_02052F58.c`, `src/matched/func_02052F90.c`, `src/pending/func_02052FC8.c` | `../1.2/sp2` | `pkt_020526A8` is a 1.2 unit on two tells at once: `blx r3` beside `ldm sp!, {lr}; bx lr` at 0x02052F6C/0x02052F80, and `sub sp, sp, #4` where 1.1p1 pads with a dead `push {r3}` (the same tell as `func_020525A0.c`). Under the pin the same one-line C is byte-exact where 1.1p1 is 27 bytes out and folds the 16-bit mask into a shift pair |
| `src/matched/func_02072A88.c` | `../1.2/sp2` | the tail-call tell again: `a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write` is not unspellable, it is 1.2 |
| `src/matched/func_02072BDC.c` | `../2.0/sp2` | the "kept constants" tell: 23 bytes out under 1.1p1, 39 under 1.2, byte-exact under the pin |
| `src/matched/func_02069E20.c` | `../2.0/sp2` | the "kept branches" tell, the counterpart of "kept constants": the image keeps `tst r2, #0x100` at 0x02069E4C and `beq 0x02069E68` at 0x02069E50 over a five-instruction guard body at 0x02069E54..0x02069E64. 1.1p1 -O4,p always predicates a guard block of five instructions or fewer (`asrne/ldrne/andne/orrne/strne`), giving 100 bytes against the original's 104; under the pin the same C is 104 bytes, 0 mismatches |
| `src/matched/func_02069AC4.c` | `../2.0/sp2` | the "kept branches" tell again, one packet over (`pkt_020694D8`, 2026-09-21). The image keeps the DEAD compare `cmp r5, lr` at 0x02069B00 (`0e 00 55 e1`), the left leaf of a four-way FourCC search tree, immediately before the unconditional `b 0x02069B74` at 0x02069B04 (`1a 00 00 ea`) to the default exit; the 'CGLP' arm is empty and shares that exit. 1.1p1 -O4,p folds the compare out and lands at 216 bytes against the original's 220, every other byte identical and shifted by exactly four. Empty-arm, `case`+`default:` fallthrough, `continue` and `goto` spellings all fold the same way. Under the pin the same C is 220 bytes, 0 mismatches |
| `src/matched/func_0206EBB8.c` | `../2.0/sp2` | the "kept branches" tell again, packet `pkt_0206EB00` (2026-09-21). The image keeps `tst r1, #1` at 0x0206EC18 (`01 00 11 e3`) and `beq 0x0206EC30` at 0x0206EC1C (`03 00 00 0a`) over the FOUR-instruction guard body at 0x0206EC20..0x0206EC2C (`00 10 90 e5` `ldr r1,[r0]` / `04 10 81 e3` `orr r1,r1,#4` / `00 10 80 e5` `str r1,[r0]` / `1e ff 2f e1` `bx lr`); 1.1p1 -O4,p predicates it to `ldrne/orrne/strne/bxne` for 148 bytes against the original's 152, every other byte identical. Under the pin the same C is 152 bytes, 0 mismatches |
| `src/matched/func_0206EB00.c` | `../2.0/sp2` | same packet and pass, the "kept constants" side of the same family. The image rematerialises the clear call's zero argument (`00 00 a0 e3` `mov r0, #0` at 0x0206EB24) while the loop counter gets its own `mov r2, #0` at 0x0206EB3C; 1.1p1 -O4,p CSEs the two into one `mov r4, #0` hoisted to 0x0206EB18, which then needs a fourth callee-saved register and gives `push {r4, r5, r6, lr}` (`70 40 2d e9`) against the original's `push {r3, r4, r5, lr}` (`38 40 2d e9`), 22 concrete bytes out at the same 124. Under the pin the same C is 124 bytes, 0 mismatches |
| `src/matched/func_02070BD8.c` | `../2.0/sp2` | packet `pkt_0207010C` (2026-09-21), a new tell in the same family: the image RE-READS the count field it has just stored, `ldrb r1, [r0, #0x19]` / `cmp r1, #0` / `bxls lr` at 0x02070BF4..0x02070BFC, while 1.1p1 -O4,p forwards the value still live in r2 from the `strb r2, [r0, #0x19]` two instructions earlier and emits `tst r2, #0xff` / `bxeq lr`, one instruction shorter: 72 bytes against the original's 76, 43 concrete bytes out and the whole loop shifted by four. The loop's own bound re-read at 0x02070C0C is identical under both, so this is the guard's entry test alone. Under the pin the same C is 76 bytes, 0 mismatches, sole ABS32 site resolving `data_table x8` |
| `src/matched/func_0206A17C.c` | `../2.0/sp2` | packet `pkt_0206A12C` (2026-09-21), the "kept constants" tell on a 32-byte leaf. The image materialises the detach store's zero EARLY, `mov r1, #0` at 0x0206A180 (`00 10 a0 e3`), between the `ldrh r2, [r0, #0x32]` and the `bic r2, r2, #1`, and loads the buffer pointer only at 0x0206A18C (`2c 20 90 e5`) once the flags read-modify-write has retired. 1.1p1 -O4,p hoists that buffer load and sinks the constant, giving `ldrh r3 / ldr r2,[r0,#0x2c] / mov r1,#0 / bic r3,r3,#1 / strh r3`: the same 32 bytes with the first five instructions permuted, 16 concrete bytes out. Three further source orderings all schedule identically under 1.1p1. Under the pin the same C is 32 bytes, 0 mismatches |
| `src/matched/func_0206A5B4.c` | `../2.0/sp2` | the "kept branches" tell, same packet and pass. The image writes the context lookup's zero result out TWICE, once per arm: `mov r3, #0` at 0x0206A614 (`00 30 a0 e3`) reached by the inner bounds failure and a second `mov r3, #0` at 0x0206A61C (`00 30 a0 e3`) reached by the outer null/offset guard, each with its own branch to 0x0206A620 (`02 00 00 ea` at 0x0206A610, `00 00 00 ea` at 0x0206A618). 1.1p1 -O4,p cross-jumps the two arms into a single `mov r3, #0` and emits the two branches back to back, giving 196 bytes against the original's 200, every following instruction identical and shifted by exactly four. Four spellings of the split (goto to a shared label, chained else-if, hoisted `r3 = 0` initialiser, duplicated-else) all fold the same way. Under the pin the same C is 200 bytes, 0 mismatches; EXACT* only because 0x0206A67C has no label |
| `src/matched/func_02068EA0.c` | `../2.0/sp2` | packet `pkt_02068808` (2026-09-21), the re-read/forward tell of the row above, measured on a glyph-draw dispatcher. The image RE-READS the font's header chain a second time before the switch dispatch, `ldr r1, [r7]` at 0x02068F00 (`00 10 97 e5`) then `ldr r3, [r1, #8]` at 0x02068F04 (`08 30 91 e5`), although the identical chain was loaded at 0x02068EE8/0x02068EEC (`00 10 97 e5` / `08 20 91 e5`) for the stride `mla` two instructions earlier; 1.1p1 -O4,p forwards the register it still holds live and collapses the pair into one `ldr r3, [r3, #8]`, giving 284 bytes against the original's 292 with the `addls pc, pc, r1, lsl #2` dispatch and its whole eight-entry branch table shifted by four. A `volatile` outer load, struct-typed field chains, binding the header to a local before or after the out[1] computation, and a fresh `(*font)->hdr` chain in every switch arm all CSE identically at 284. Under the pin the same C is 292 bytes, 0 mismatches, both PC24 sites resolving `label` |
| `src/matched/func_020713A4.c` | `../2.0/sp2` | packet `pkt_02071104` (2026-09-21), the "kept constants" tell on a 36-byte unlabelled leaf of the 0x02071104 matrix family. The image materialises the unit scale FIRST, `mov r2, #0x1000` (`01 2a a0 e3`) at 0x020713A4 then `str r2, [r0]` (`00 20 80 e5`) at 0x020713A8, and only then `mov r1, #0` (`00 10 a0 e3`) at 0x020713AC; 1.1p1 -O4,p schedules the zero first (`mov r1,#0` / `mov r2,#0x1000` / `str r2,[r0]`) for the same 36 bytes, 9 concrete bytes out across the first three words. Binding both constants to locals (either declaration order) and writing f14 immediately after f00 all keep the zero-first schedule. Under the pin the same C is 36 bytes, 0 mismatches |
| `src/matched/func_02071EFC.c` | `../2.0/sp2` | packet `pkt_02071DD4` (2026-09-21), the "kept constants" tell on the 36-byte identity leaf of the 0x02071CDC constructor family, the same measurement as the row above on a different family. The image materialises the unit scale FIRST, `mov r2, #0x1000` (`01 2a a0 e3`) at 0x02071EFC then `str r2, [r0]` at 0x02071F00, and only then `mov r1, #0` (`00 10 a0 e3`) at 0x02071F04; 1.1p1 -O4,p schedules the zero first for the same 36 bytes, 9 concrete bytes out under all ten spellings measured in `docs/notes/func_02071EFC.c.txt` (every store order, both constants bound to locals, the zero derived from the live 0x1000 as `one - one`, and a re-read of the just-stored field). Under the pin the same C is 36 bytes, 0 mismatches, no relocations |
| `src/matched/func_02072524.c` | `../2.0/sp2` | the SECOND, byte-identical copy of the row above: the same 36-byte identity leaf is emitted twice in this file, and the same `mov r2, #0x1000` (`01 2a a0 e3`) at 0x02072524 / `mov r1, #0` (`00 10 a0 e3`) at 0x0207252C ordering, 9 bytes out under 1.1p1, 0 mismatches under the pin. Filed from the same C with only the name and address changed |
| `src/matched/func_02072320.c` | `../2.0/sp2` | same packet and pass, the "kept constants" tell on the 84-byte identity-scale member. The image writes `str r2, [r0]` / `str r2, [r0, #0x14]` at 0x02072328/0x0207232C and materialises the zero LATE, `mov lr, #0` (`00 e0 a0 e3`) at 0x02072330, before `str lr, [r0, #4]`; 1.1p1 -O4,p sinks the zero above the pair and merges the f00/f04 stores into one `stm r0, {r2, lr}`, giving 80 bytes against the original's 84. All six store permutations, a `z` local, `d->f14 = d->f00` and hoisting all three constants keep the merge. The image's `push {r3, lr}` / `pop {r3, pc}` with NO call in the body confirms lr is spent as a scratch, which the merge denies. Under the pin the same C is 84 bytes, 0 mismatches |
| `src/pending/func_0207312C.c` | `../2.0/sp2` | packet `pkt_0207312C` (2026-09-21), the "kept constants" tell on the 180-byte sound-channel table init. The image materialises the allocator's element size TWICE, `mov r1, #0x14` (`14 10 a0 e3`) at 0x02073134 and again at 0x02073140; 1.1p1 -O4,p CSEs the pair into one hoisted `mov r4, #0x14` plus two `mov r1, r4`, which costs a further callee-saved register and turns the original's eight-register `push {r4, r5, r6, r7, r8, sb, sl, lr}` (`f0 47 2d e9`) into a ten-register `push {r3, r4, ..., fp, lr}`, 180 bytes with 128 concrete bytes out. Under the pin the same C is 180 bytes, 0 mismatches: BYTE-CORRECT. Parked, not filed: the ABS32 site at +0xAC needs 0x0214E024, whose ONLY pool word image-wide is this function's own pool_020731D8 at 0x020731D8, so `literal` has no outside witness |
| `src/pending/func_02073344.c` | `../2.0/sp2` | same packet and pass, the "kept constants" tell on the 152-byte voice allocator. The image materialises each zero fresh -- `mov r1, #0` (`00 10 a0 e3`) at 0x02073380 for the list-head argument, then `moveq r0, #0` (`00 00 a0 03`) at 0x0207338C, 0x0207339C and 0x020733B4 for the three `return 0` exits; 1.1p1 -O4,p CSEs all four into a single hoisted `mov r7, #0`, giving 156 bytes against the original's 152 and permuting the whole callee-saved allocation (obj r4->r6, slot r6->r4, pri r7->r5), 99 concrete bytes out. Four 1.1p1 spellings measured (separate node local, declaration reorder, early read of o->f0, explicit `(void *)0` cast) all hoist the zero. Under the pin the same C is 152 bytes, 0 mismatches: BYTE-CORRECT. Parked, not filed: the PC24 site at +0x68 needs func_02073624, which has exactly one branch anywhere in the image, the `bl` at 0x020733AC inside this very function, so `label` refuses it |
| `src/pending/func_02072758.c` | `../2.0/sp2` | same packet and pass, the "kept constants" tell on the 48-byte boot sequence. The image rematerialises the last call's zero argument, `mov r0, #0` (`00 00 a0 e3`) at 0x0207277C, although the spin loop still holds a zero live in the callee-saved r4 set at 0x0207275C; 1.1p1 -O4,p reuses it as `mov r0, r4` (`04 00 a0 e1`), the same 48 bytes with exactly those 2 bytes out under all five spellings in `docs/notes/pkt_02071DD4.c.txt`. Under the pin the same C is 48 bytes, 0 mismatches: BYTE-CORRECT. Parked, not filed, and not for codegen: three of its five PC24 sites (0x020731E0, 0x02073D7C, 0x02075858) have no branch outside its own 48 bytes and no `matched` entry, so it caps at MATCH* until one of the three is filed |

FLAGS ARE PART OF THE ENTRY, not just the compiler: a source whose header carries `flags: -O4,p -proc
arm7tdmi` (the arm-epilogue class, `layout/proc_hints.txt`, `tools/procscan.py`) must be VERIFIED with that
value. `src/matched/unit_0205841C.c` lays out 196 bytes under `arm7tdmi` and 188 under the default `arm946e`,
so a verifier passing default flags reports DIFF on a file the chain builds byte-identically.
`scripts/verify_shards.py` now reads both the `compiler:` and the `flags:` line from the header and passes
each through unchanged.

The last two were filed by a wave-r7 lane with the pin recorded in `docs/notes/pkt_02074A6C.c.txt`. 0x02074AC4
(36 bytes, same shape) is in another packet and was not measured under the pin, so it stays unpinned until
someone does.

Two traps in the verifier, both paid for again here. A verifier that hardcodes `--cc 1.1p1` reports a
correctly pinned file as **DIFF**, which reads exactly like a broken source: `scripts/verify_shards.py` did
that to the two rows above, and its fix is to read the source's own `compiler:` line and pass the value
through UNCHANGED. And a pinned file's shard records the pin as `dsi/../2.0/sp2`; that string is correct and
must not be normalised.

Reverting any of these reverts its callees and promotions with it: the pin has decided whether bytes count
three separate times.

## The 3D rig unit: pinned as a family, 2026-09-19

Range `0x0205429C..0x020584E0`. The frontier probe of 2026-09-19 measured it directly, and wave r6's three
lanes ran it and CORRECTED two of the claims below. What the family really looks like, per row:

* 30 rows, 14,728 code bytes (3.68 points).
* **Only some rows carry the `blx rN` tell.** Verified by raw word scan and by compile: `0x0205429C`,
  `0x02054718`, `0x02054A68` carry register `blx r3`/`r4` beside an ARMv4T `pop {..., lr}; bx lr` return.
  `0x02054DB8` carries four ARMv4T returns and NO register `blx`. The three big rows of `pkt_02055498`
  (`0x02055498`, `0x02055B80`, `0x02055FD4`) carry **zero** `blx` — 12+5+5 `bl` and no `blx` in 3,920 code
  bytes. Those rows are pinnable on the constant-materialisation tell instead
  (`mov rN,#0x800` feeding `adds rD,rS,rN` at `0x0205551C/20`, `0x02055C04/08`, `0x02056068/70`, where
  1.1p1 folds to `adds rD,rS,#2048` and pairs it with `pop {r3, pc}`).
* **THE `-proc` IS PART OF THE PIN AND IT IS PER ROW.** `layout/proc_hints.txt` (generated by
  `tools/procscan.py`) is a census, NOT an oracle, and two of its bands are now falsified per row: for
  `pkt_02056460` and for the `pkt_02057830`/`pkt_02057B5C`/`pkt_02057F8C` rows, wave r8 measured
  `-proc arm946e` correct (on `0x02057B5C` the same source is 41 bytes out at `arm7tdmi` against 28 at
  `arm946e`; on `0x02056460`, `arm7tdmi` gives a five-register frame and 31 mismatches against 8), while
  `0x02055B80` genuinely needs `arm7tdmi` (its prologue is the only thing carrying the hint) and
  `0x02054DB8` needs it too. So quote the proc per row, measured, and where the census and the compile
  disagree, the compile wins and the census row should be corrected.
* Wave r8's harvest from this family under the pin: `0x0205429C` (1148 B), `0x02054718` (848 B),
  `0x02054A68` (848 B), `0x020576D0` (352 B), `0x02057B5C` (100 B), `0x02057F8C` (284 B),
  `0x020580A8` (216 B), 3796 bytes in one wave. The fix that moved the three big rows was four source
  shapes rather than one register swap; they are written out in `docs/notes/pkt_0205429C.c.txt` and are
  the first four things to try on `func_02053E1C` (`pkt_02053218`, same shape, still open).
* Six rows are now EXACT under the pin (`0x02057AB8`, `0x02057B10`, `0x02057E68`, `0x02057EF8`, `0x02058180`,
  `0x02058204`, all `../1.2/sp2`, 768 bytes) plus `0x020583CC` (80 bytes, `../1.2/sp2`, lane rig-b), so the
  decision's first harvest is 848 bytes and the rest of the range is unchanged work.
* `docs/notes/pkt_02053218.c.txt` records the same conflict measured across all 32 `-proc` values and all
  nine dsi builds, so the class is not a guess.

Owner's decision: allow the pin for this family, with the evidence recorded per file as the rule above
requires. When a lane is assigned a row in this range, its brief states the pin, and the file's header
carries `compiler: ../1.2/sp2`.

## What a pin does NOT change

`README.md`'s coverage figure, the denominator, and the honesty gate. A pinned file is a manifest entry like
any other, and the chain verifies it with the compiler its shard names. If a pinned file ever fails to
build in the chain, the pin resolution in `tools/csrc.py` is the first thing to check.
