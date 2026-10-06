# palanm (arm9)

Parts palanm_p01..p03 plus member func_02021444.c (second by address).

Blocked by: func_02021444 uses a struct the other members declare differently (not a struct/union errors in the merge); merging p02 with its neighbour changes the code (c99=DIFF, nolang=DIFF); struct PalAnmSlot has two layouts (PalAnmSlot_1 vs PalAnmSlot_020215BC) between p03 and the next part. Needs a struct pass on PalAnmSlot.
