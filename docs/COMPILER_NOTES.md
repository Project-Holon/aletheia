# Compiler notes

Facts about the matching compilers (mwcc, CodeWarrior, MSL) that keep being
rediscovered during cleanup and integration. Each one explains a trap that has
cost a lane time more than once. Record a new fact here when a lane meets it.

## 1. Struct-member offsets at or above 0x530 change the load

mwcc 1.1p1 emits a literal-pool load for a struct-member offset at or above
0x530. An `Obj`-view member at the same offset used `movs` plus `lsls` instead.
The offset, the type and the expression can be identical; a different struct
still produces different bytes. In ov197 this moved 8 functions. It is the
mechanism behind the recurring "literal-pool placement" trap: converting a
leading view can move CodeWarrior's literal pool and DIFF a whole file.

## 2. The original pointer-chasing reload structure is load-bearing

A hand-written function that replaced the original's repeated pointer chasing
with one cached base compiled smaller than the original. In ov225 a
`func_021BB854` that used `data->heap` directly compiled to 424 bytes against
the original 448; keeping every `q->f4->...` reload made it EXACT. Do not
"clean up" a reload chain the original performs unless the bytes still match.

## 3. `match.py one` needs the ORIGINAL address

`match.py one` takes the ORIGINAL image address, from
`layout/matched/<region>/pkt_<region>_<addr>.json`. The address in a `match.py
tu` listing is the COMPILED layout, and it shifts after any struct size change,
so it is the wrong address for `match.py one`. This bit OC-ov198 and confirmed
an earlier finding.
