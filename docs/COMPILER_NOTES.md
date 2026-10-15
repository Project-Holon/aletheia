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

