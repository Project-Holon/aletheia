# unit_0208B7BC (arm9)

Translation unit 0208B7BC..0208C960, 44 functions, confidence proven (tools/tuboundary.py).

Two parts are left, `unit_0208B7BC_p01.c` (0208B7BC..0208B8B0) and
`unit_0208B7BC_p02.c` (0208B950..0208C960). Merging them into one
`unit_0208B7BC.c` is blocked by:

- c99=DIFF: appending `func_0208B950` (the PXI callback with two switches that lower
  to jump tables, 0x0208B950) to the first part changes the bytes of the merged file.
  Every other boundary merged.

What was unified to get from 25 files to 2: one `PmBss` / `PMiWork` / `PMGenCallbackInfo`
set of types (struct `PMiWork` offsets 0x08/0x3c, `g_02153000[6]` and the callback list
fields now use named fields), `OS_GetVBlankCount` defined once, enum parameter types
replaced by `int` to match the other members' prototypes.
`g_02153020` (the DMA count array) stays a separate global: viewing it as
`g_02153000.preDmaCnt` changes the bytes.

- `func_0208B8B0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
