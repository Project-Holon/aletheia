# Compiler notes

Facts about the matching compilers (mwcc, CodeWarrior, MSL) that keep being
rediscovered during cleanup and integration. Each one explains a trap that has
cost a lane time more than once. Record a new fact here when a lane meets it.

## 1. Any introduced struct can change the codegen, not just one at 0x530

mwcc 1.1p1 emits a literal-pool load for a struct-member offset at or above
0x530. An `Obj`-view member at the same offset used `movs` plus `lsls` instead.
The offset, the type and the expression can be identical; a different struct
still produces different bytes. In ov197 this moved 8 functions. It is the
mechanism behind the recurring "literal-pool placement" trap: converting a
leading view can move CodeWarrior's literal pool and DIFF a whole file.

The 0x530 threshold is one common trigger, not the whole rule. OC10-ov175
measured every net-context view individually against an otherwise EXACT base and
found views failing at LOW offsets too: `Obj00840` grew `GdbGetMyRecords` by 4
bytes, and `Obj01170`, `Obj01171`, `Obj02513`, `Obj10690` and `Obj24326` also
DIFFed, while every view at 0x530 or above failed as above. Introducing a struct
changes how mwcc allocates and reloads across the whole function, so any view can
fail regardless of its own offset. Test each view against an EXACT base instead
of trusting the threshold.

## 2. Missing explicit padding is a trap of its own

A struct reconstructed from observed offsets and natural alignment can still be
the wrong size. OC10-ov128 found that four-byte members in `...ItemScreen`
(0x0F4, 0x0FC, 0x10C, 0x114) and `...ListScreen` (0x010) needed explicit pads
because natural alignment does not fill those gaps. Without them a later field
landed at 0x598 instead of 0x5A8. The error shows up as a LATER field being
misplaced, not at the gap itself, so check every field offset after a fold, not
just the one that changed.

## 3. The original pointer-chasing reload structure is load-bearing

A hand-written function that replaced the original's repeated pointer chasing
with one cached base compiled smaller than the original. In ov225 a
`func_021BB854` that used `data->heap` directly compiled to 424 bytes against
the original 448; keeping every `q->f4->...` reload made it EXACT. Do not
"clean up" a reload chain the original performs unless the bytes still match.

## 4. `match.py one` needs the ORIGINAL address

`match.py one` takes the ORIGINAL image address, from
`layout/matched/<region>/pkt_<region>_<addr>.json`. The address in a `match.py
tu` listing is the COMPILED layout, and it shifts after any struct size change,
so it is the wrong address for `match.py one`. This bit OC-ov198 and confirmed
an earlier finding.

## 5. A volatile reload can be load-bearing

OC10-ov121a kept the `Obj_021DAEF0` view because its 0xACC field is `volatile
int` and the reload is required for the bytes. A typed struct field that drops
the volatile changes the load schedule and DIFFs the function. Keep the
`volatile` qualifier (and the reload) when the original view had one.

## 6. Signedness can change control flow, not just instructions

A signedness change is not only an `ldrb`/`ldrsb` difference. OC10-ov128's
`Wf2dmapTouchTileRecord.x`/`.y` had to be `short`: the unsigned form dropped a
negative branch and shrank a function by 4 bytes. Compare the branch structure,
not just the load widths, when choosing a field type.

## 7. One wrong field width can propagate across many functions

OC10-ov204 found `PselWork.animReverse` (0x48) is stored 32-bit; the wave 9
`u16` form grew `PSEL_SetAnimTarget` by 4 bytes and shifted 45 functions. A
single wrong width moves every function that reads the field, so fix the width
at its definition and re-verify the whole region, not just the function you were
looking at.

## 8. A non-contiguous split is possible

A file whose functions sit in two or more non-adjacent ranges, with another
original between them, cannot be compared as one contiguous blob, but it can
still be verified function by function. `tools/gameverify.py` already has a
per-function path (`runtime_kind`, `runtime_verify`) for the arm9 runtime
entries, and the engine underneath (`match.run_one`) works for C, not only asm.
A merged piece opts in with the header marker `contiguous: no` and lists each of
its own functions with its real address in the `symbols:` block; the same block
`tools/gamelink.py` already reads to cut the file into runs. `gameverify.py
--file` and `match.py manifest --verify` then compare each function at its own
address (`match.piece_entry_status`), and the manifest entry keeps kind
`game_unit` with a `pieces: true` flag and an `addresses` list parallel to
`functions`. The marker is absent from every existing file, so the path is
dormant until a file is merged as a piece; the 39 runtime rows are untouched.

## 9. A partial conversion is not a valid test of a typed form

The original source used the typed form throughout, so its instruction
schedule corresponds to converting every site of that object at once.
Converting only some sites yields a hybrid with a different register
schedule and a false DIFF. Convert every site in the function before
concluding that the typed form DIFFs, and treat a "kept because the typed
form DIFFs" note as a claim to re-test, not as settled.

INV-A re-tested records that a lane had closed this way; three of eight
were false. In `ov219/beacon_detail.c`, all six raw casts in
`func_0218532C` and `func_02185B74` convert to typed record fields and both
functions stay EXACT (288 and 272 bytes) once every site is converted; the
lane had measured a partial conversion. In `ov218/un_select.c`,
`UN_SELECT_CreateFrameList` typed `itemText[i]` is EXACT at 224 bytes, not
the 232 bytes a partial conversion measured.

The related reusable result is the base-first indexed form: when a direct
struct-indexed array access DIFFs, `((void**)&field[0])[i]` (or
`((T**)&field[0])[i]`) can be byte-exact. Two independent re-tests confirm
it, so try the base-first form before recording that a typed array access
has no alternative.

## 10. The arm9 coverage-accounting gap was an inventory bug, not missed code

DISC-1 closed the 1994-byte disagreement between `coveragemap.py` (arm9 matched
434030) and `ovstats.py` (436024). The bytes were two long-branch labels inside
the single matched function `MCSS_Draw` (`0x02014D2C..0x020155A0`), not function
starts. `tools/worklist.py` counted a listing label strictly inside a matched
unit's compiled bytes as an open function; it now credits it to its parent
(`interior` argument, `matched_interior`). `tools/fnaddr.py` records the laid-out
`.text` size under the reserved key `__size__` (`unit_size()`), and
`tools/coveragemap.py` now cross-checks its arm9 tiles against
`ovstats.arm9_summary()` and exits on any disagreement. After the fix arm9 reads
100.00 percent (436024 of 436032) and the map, ovstats and linkstats agree.

## 11. Three "missing" byte runs were missing manifest entries, not missing code

TAILSTUB-1 found that the arm9 8-byte run at `0x02072788` and the overlay 8-byte
runs `ov125 0x021D85DC` and `ov175 0x021DD560` are mwcc far tail calls
(`ldr ip,[pc]; bx ip` followed by a pool word). They are genuine code, but the
reason they read as gaps in one tool was that three of the shard/manifest entries
were absent, not that the code was unmatched. When a small run looks unmatched,
check the manifest entry before writing code.


## 12. A conversion helper name missing from `symbols:` can pass per file and break the link

When C code does a conversion or a divide, mwcc emits a call to a runtime helper
under its own name. The name depends on the operand types, not on what the
original code called:

| C operation | name mwcc emits | address |
| --- | --- | --- |
| `(double)` of an `int` | `_dflt` | 0x0209B750 |
| `(double)` of a `u32` | `_dfltu` | 0x0209B790 |
| `(s32)` of a `double` | `_dfix` | 0x0209C508 |
| `(u64)` of a `double` | `_ll_ufrom_d` | 0x0209C554 |
| `(float)` of an `int`, float `+`, `-`, `(int)` of a float | `_fflt`, `_fadd`, `_fsub`, `_ffix` | 0x0209BDBC, 0x0209C95C, 0x0209CB8C, 0x0209C494 |
| `u32 / u32`, `int / int` | `_u32_div_f`, `_s32_div_f` | 0x0209C2B0, 0x0209C0A4 |

If the name is not in the file's `symbols:` block, the per-file check takes its
address from the call in the image, so `gameverify.py` reports EXACT even when the
name is wrong for that address. `gamelink.py` then binds the name once for the
whole region (the first file wins), and every other file that calls the same name
goes to that address. In HELPER (wave 19), `mcss.c` wrote
`(double)(sizeS + 2)` with `sizeS` a `u32`: mwcc emitted `_dfltu`, the image calls
`_dflt`, and the two `_dfltu` calls in `msl_ansi_fp.c` landed 0x40 bytes off in
the ARM9 link. The fix was the field's real type (`GXTexSizeS`, an int enum).

Rules: put the emitted name in `symbols:` (check with `match.py one`: every
relocation must say "resolved"). If the name and the image address disagree, the
operand type in the C is wrong; do not change the address.

Both sides are now checked (wave 19):

- `tools/gameverify.py` reports a file whose relocation names no address anywhere
  (no `symbols:` row, no `func_`/`d_` name, not in `layout/symbols_sdk.json` or the
  matched manifest) as `MATCH (unattested: NAME: no symbols row)`, not EXACT. The
  check is `match.unattested_names`, applied in `restructure.verify`.
- `tools/gamelink.py` (and so `tools/onelink.py`), after the first link pass, reads
  every file's own call or pool word for each undefined name from the original code
  and fails with the names and files when two files disagree on the address.
- Two files had the wrong helper name for the image: `pokemontrade_3d.c` divided
  `long long` where the original divides unsigned (`_ll_udiv`), and
  `comm_btl_demo_main.c` took `u32 % 180` where the original takes a signed value
  (`_s32_div_f`). The operand type was fixed, not the address.
