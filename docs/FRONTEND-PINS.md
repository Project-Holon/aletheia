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

Reverting any of these reverts its callees and promotions with it: the pin has decided whether bytes count
three separate times.

## The 3D rig unit: pinned as a family, 2026-09-19

Range `0x0205429C..0x020584E0`. The frontier probe of 2026-09-19 measured it directly:

* 30 rows, 14,728 code bytes (3.68 points), every one of them still open.
* Six of its rows (`0x0205429C`, `0x02054718`, `0x02054A68`, `0x02055498`, `0x02055B80`, `0x02055FD4`)
  carry register `blx rN` beside a `pop {..., lr}` return, so no dsi build can reach them at all.
* The remaining rows fail the constant-materialisation tell above: the image materialises
  `mov rD, #2048` / `mov rD, #4096` and adds, where 1.1p1 folds the immediate.
* `docs/notes/pkt_02053218.c.txt` records the same conflict measured across all 32 `-proc` values and all
  nine dsi builds, so the class is not a guess.

Owner's decision: allow the pin for this family, with the evidence recorded per file as the rule above
requires. When a lane is assigned a row in this range, its brief states the pin, and the file's header
carries `compiler: ../1.2/sp2`.

## What a pin does NOT change

`README.md`'s coverage figure, the denominator, and the honesty gate. A pinned file is a manifest entry like
any other, and the chain verifies it with the compiler its shard names. If a pinned file ever fails to
build in the chain, the pin resolution in `tools/csrc.py` is the first thing to check.
