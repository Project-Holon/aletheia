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
  `tools/procscan.py`) is the authority. Measured: `pkt_02055498`'s three big rows need `-proc arm7tdmi`
  (at `arm946e` the 1.2 front end gives `0x02055B80` a nine-register push and a 0x3c frame; at `arm7tdmi`
  the prologue matches instruction for instruction, and `0x02055498`'s 0x88 frame matches only there),
  while the six small rows of `pkt_02057830` filed by lane rig-c reproduce byte-exactly at
  **`../1.2/sp2 -proc arm946e`**, and the per-row notes that blamed `arm7tdmi` for those six were wrong
  about the front end, not about the scheduler. So quote the proc per row, never for the family.
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
