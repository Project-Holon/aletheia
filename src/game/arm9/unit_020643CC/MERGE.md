# unit_020643CC (arm9)

Round 4 state: 3 files remain, all byte-exact (tools/match.py).

- `unit_020643CC_p01.c`: func_020643CC (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_020643CC_p02.c`: func_02064648, func_0206469C, func_02064754 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_020643CC_p03.c`: func_020648B4, func_020648E0, func_02064934, func_020649D4, func_02064AB4, func_02064B68 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)

Boundaries between adjacent files:
- `unit_020643CC_p01.c` | `unit_020643CC_p02.c`: same compiler (2.0), blocked by struct views of the multi-cell types: p01 has the library typedef set (MultiCellData with pHierDataArray, MCInstance, HierData), p02 and p03 define struct MultiCellData and MultiCellBank with partial fields, struct MCD, Root, Obj and use the generic ../../matched/include/ObjNNNN.h views. One canonical MultiCellData/MultiCellBank/MCInstance by offset is needed.
- `unit_020643CC_p02.c` | `unit_020643CC_p03.c`: same compiler (2.0), blocked by struct views of the multi-cell types: p01 has the library typedef set (MultiCellData with pHierDataArray, MCInstance, HierData), p02 and p03 define struct MultiCellData and MultiCellBank with partial fields, struct MCD, Root, Obj and use the generic ../../matched/include/ObjNNNN.h views. One canonical MultiCellData/MultiCellBank/MCInstance by offset is needed.

