# Lane U26: ov016 SDK slice (14 rows) — one method finding, no EXACT

Slice `scratch/a2/slices/u26.txt`. Two rows (0x021BC63C, 0x021D5A58) were already
modified in the tree by another lane and were skipped untouched.

## Method finding: a switch "dispatch order" wall is fixed by permuting the CLUSTER, not case 0

`021C687C` (`input`, scenesetedit32.o) was parked as a pure dispatch-order wall after
"case order (0 last)" came back flat. The chain mwcc emits walks the *cluster members* in
the order they appear in the source, and that order changes the object size:

| source case order (default last) | size | concrete bytes |
|---|---|---|
| 0, 0x80, 0x82, 0x83 (parked) | 404 (extent 400) | 318 |
| 0x83, 0x80, 0x82, 0 (applied) | **400 (size-exact)** | **209** |

All 120 orderings of the five blocks (4 cases + default) were compiled; 0x83,0x80,0x82 is
optimal, 0x80,0x82,0x83 / 0x82,0x80,0x83 / 0x80,0x83,0x82 are 301-319, and the position of
`case 0` is irrelevant (its block is the no-op `break`). So: on a parked switch-dispatch
row, permute the dense cluster's members before declaring the wall — and do not conclude
"flat" from moving the singleton case alone.

What the remaining 209 bytes are, and why it is a wall: the image runs the range test
first (`cmp r4,#0x83 / bgt default; cmp r4,#0x80 / blt zero-test`) and the `cmp r4,#0`
singleton last; 1.1p1 emits the singleton first and the cluster second for every one of
the 120 orderings. Same layout, two groups swapped.

## The one EXACT cell in this slice is out of scope, and its object proves it

`021D0DE0` (`cbWm`, usbap.o) is byte-EXACT at `-O1,p`: 148/148, 0 diffs, with 1.1p1 and
with 1.1 / 1.2 / ../2.0/base (wall clock 1 s to re-measure). `-O4,p` gives 144 B / 87. It
is not fileable: the object's own mates say usbap.o is a `-O4,p` object — func_021D0CEC is
220 B / 2 diffs at `-O4,p` against 228 B / 147 at `-O1`, and func_021D0E74 is 332 / 286
against 368 / 272. A single object was built with one configuration, so the `-O1` cell is
a coincidence of this body, which is what T6 recorded from the other side.

## Pin re-check (no change)

Every ARM row in the slice is optimal at `dsi/1.1p1`: the `../2.0/sp1p2` and `../2.0/base`
cells are worse on all of them (e.g. 021D06A4 148/92 against 144/12, 021CFCC8 360/265
against 336/9, 021D3638 17 diffs against 5). The two thumb rows are on `../2.0/sp1p2`
(atermset.o, stamp 3.0.0.126) and 160/117 and 186/176 are their best cells.

Per-row residues are in each parked source header, not here.
