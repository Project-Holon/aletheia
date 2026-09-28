# ov_sdk parked-pending graduation pass, 2026-09-28

Worked the 31 files in `src/pending/ov_sdk/`. None were byte-correct: using the
correct command (with `--lang c99`, see the tooling note below) all verified
DIFF, so none could graduate by an evidence class alone. Eight were made EXACT
by fixing the C; one was a stale duplicate of an already-matched file and was
removed; 22 remain, each with a named mechanism.

## Tooling note

`tools/session/promote_fast.py` (and hence `pending_pct.py`) does not pass
`--lang`, so a pending file that declares `typedef _Bool bool;` reports a
spurious `CCERR` (`undefined identifier '_Bool'`). The real verdict appears as
soon as `--lang c99` is passed. Twelve ov016 files were affected; all turned out
to be DIFF. Consider having `verify()` in promote_fast.py read the header's
`lang:` field.

## Graduated (8)

| file | addr | what closed it |
|---|---|---|
| `ov014_func_021784F0.c` | 0x021784F0 | `DWCi_MOV_WH_StateInEndParent`: inverted guard (`if (x != 2) { f(); return 0; } return 1;`) reproduces the original `beq` to the tail arm (fall-through polarity). |
| `ov009_func_02164490.c` | 0x02164490 | `get48bits_2`: no C spelling of the 64-bit return builds the 16-byte shape (every OR/union/struct form leaves an `orr ...,#0` or a general shift); hand-written `asm void` body, same as the sibling `get48bits_3` at 0x021644A0. |
| `ov016_func_021CDF98.c` | 0x021CDF98 | `endScene2`: `DWCi_GXlInvisible(1,1)` belongs *inside* the `Choose == 0` arm, not after it. |
| `ov016_func_021CE2F4.c` | 0x021CE2F4 | `endScene1`: the second `DWCi_EFFlFade(3,0,0x15,8)` is *outside* the `Choose == 2 \|\| 3` guard; only the first fade is guarded. |
| `ov016_func_021CE364.c` | 0x021CE364 | `endScene2`: same family, `DWCi_GXlInvisible(1,1)` inside the `Choose == 2 \|\| 3` arm. |
| `ov107_func_021F4538.c` | 0x021F4538 | `MBi_CheckMBParent`: two guards sharing explicit `goto ret0/ret1` labels instead of an if/else-if chain (forces the two branch-to-exit blocks the image has). |
| `ov114_func_021BA690.c` | 0x021BA690 | permuter: split-assign `p = hay; p = p + i;`, inline the bound `(len1-len2)+1`, keep the dead `n=` store that reserves r8. |
| `ov114_func_021CA06C.c` | 0x021CA06C | `DWCi_EncSetError`: `CTRDGi_IsTaskAvailable` is ambiguous in `symbols_sdk.json` (11 rows); pinning `0x02059F38 arm` fixed `blx` -> `bl`. |

Each is `status: EXACT` in `src/matched/ov_sdk/`, with its shard written and
`manifest --check` clean (7554 shards, no duplicates, no unread json).

Removed as stale: `ov107_func_021F3CB8.c` (`MBi_calc_cksum`) was already matched
at `src/matched/ov_sdk/ov107_func_021F3CB8.c` (shard `pkt_ov107_021F3CB8`,
EXACT).

## Remaining 22: why each cannot graduate

Every one is a codegen near-miss (no source-only evidence can help), except the
two called out as additionally witness-starved.

Register allocation / naming:

- `func_021D1F6C` — one-colour rotation (image `g` in r1, `*g` in r3; compile
  picks r0/r2). 4000 AST compiles flat.
- `func_021D5BC0` — swapped callee-saved pair (image r5/r6, compile r6/r5).
  4000 AST compiles flat.
- `ov016_func_021C84BC` `initGraphics` — 2-register tie in the last six halfword
  writes (image keeps G2S in r1, derives G2 with `sub r2,r1,#0x1000`); permuter
  flat at 38 bytes out.
- `ov114_func_021BA590` — image materialises each `c>='A'`/`c<='Z'` as a 0/1
  boolean; 1.1p1 if-converts to range checks; `&` spellings over-allocate
  (r9/sl/fp). Permuter best 144 B with 100 B still out.
- `ov172_func_021C1F04` — recompile spills `w` (extra `str`/`ldr`); size 328 vs
  332. 6000 AST compiles, best size right but 151 bytes out.

Scheduler / ordering residues:

- `ov016_func_021CFCC8` `write` — `str r2,[sp]` (work=alloc()) placed after the
  `MemSet` load; image places it before. 3000 AST compiles flat.
- `ov016_func_021D04BC` `taskBegin4` — `str r2,[sp]` (`x=176`) ordered after the
  `MemStep` hoist; image loads MemStep first. 1200 AST flat.
- `ov016_func_021D06A4` `taskEnd0` — same as taskBegin4 with `x=152`.
- `ov009_func_021894D8` — varargs counter-increment scheduled after the format
  pointer; image increments first (idiom file exists). Permuter 300 flat.
- `ov009_func_021700C8` — cyclic register rotation in the inlined 5-byte copy;
  20 bytes. Permuter 200 flat.
- `ov016_func_021C9A94` `isPush` — each AREA copy scheduled load-pair/store in
  the image, all-load in the compile; permuter flat.

CSE / coalescing:

- `ov009_func_0216C8DC` — 1.1p1 CSEs the constant `0` into r4, pushing params to
  r8/r7/r6; image rematerialises. Permuter anneal best 128 of 134 bytes out.
- `ov016_func_021BD8D8` `DWCi_KBlInit` — whole-function reshuffle rooted in the
  button-loop's zero-argument coalescing (size 876 vs 844). Permuter flat.
- `ov016_func_021BE844` `disp` — prologue scheduling of the three 5-byte `KB_N5`
  copies vs `ix = line*12`; image 0x18 frame, compile 0x1c, then the whole
  allocation ripples. Permuter flat at 464 out.
- `ov016_func_021C00A8` `disp` — same disp residue (457 out), *and* capped by
  `keyboard10_str_20862/20864/20866` having no witness outside the range.
- `ov016_func_021C687C` `input` — switch dispatch order: image tests the
  0x80..0x83 cluster first, `0` last; 1.1p1 makes the 0-test the root. Case
  reordering and an explicit empty `case 0x81` were flat.
- `ov114_func_021CAAB4` `CRYPTOi_MyAlloc` — image has an extra redundant
  `mov r2, r0` before the indirect call; ~40 source shapes and flag/proc sweeps
  never emit it. Vendor object is stamped 4.0.0.1024 (same as the pin).
- `ov114_func_021CAAE8` `CRYPTOi_MyFree` — same redundant-copy quirk.

Additionally witness-starved (cannot be EXACT regardless of codegen):

- `ov009_func_02189780` — the counter-scheduling quirk plus `g_021A4568` /
  `g_021A458C` have no witness outside the range.
- `ov172_func_021C3DF4` — whole-function allocation scramble *and* 16 of 31
  relocations unresolved (the 12 `g_021Cxxxx` data targets have no outside
  witness, `write_exif_ifd_tables` has no address).

Not attempted to completion:

- `ov009_func_0219091C` — one ~9440-byte ARM routine (`gpiProcessSearch`); a
  full port, not a residue hunt.
- `ov114_func_021BA988` — the header C is semantically wrong (image passes the
  EF50 result to `9C1C`; the function is `void` with no `return 0`). Correcting
  it reaches 140/140 with only 2 concrete bytes left (a load lands r0/r1 where
  the image has r2, whose r1 is a phantom live value with no instruction
  trace). Left pristine; this one is worth a focused follow-up.
