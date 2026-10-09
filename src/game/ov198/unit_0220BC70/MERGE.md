# unit_0220BC70 merge status (ol052)

10 parts left (was 9 parts + 11 folder members). Greedy merged 9 boundaries.
Remaining boundaries and blockers:
- p01|p02, p02|p03, p03|p04: func_0201C724 has two incompatible prototypes (p01 u32,u32,s16,s16,void*,u32,u32; p02 void*,u32,u32,u32,u32,u32,u16). p03 is a parked DIFF draft (22 bytes, see its header); the s16 versus u32 argument shape changes code.
- p04|p05: local function put() declared with two different parameter lists (struct *,int x5 versus u8 *,void *,void *,short,u32,void *,u16); needs per-part rename.
- p05|p06, p06|p07, p07|p08: anonymous local structs viewed through different field names (first/second/third/item/fifth) over globals d_02211D34 and d_02211D68; needs one canonical struct per global (lane 042 method), plus func_0220E9A0 prototype disagreement.
- p08|p09, p09|p10: DIFF after merge (func_0220ED54 and func_0220EECC); d_02211D34 declared two ways.
