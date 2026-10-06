# unit_0207FD34 (arm9)

Translation unit 0207FD34..02080C84, 46 functions. Parts p01..p04 (EXACT) plus members GX_SetBankForOBJ.c (0x0207FFD0) and GX_SetBankForTex.c (0x02080294).

Blocked by gGXState seen through several local structs (members with vramCnt, obj, tex, lcdc, objExtPltt fields), and by macro VRAMCNT defined twice. Unify gGXState into one struct with every field (check offsets), define VRAMCNT once, then merge in address order.
