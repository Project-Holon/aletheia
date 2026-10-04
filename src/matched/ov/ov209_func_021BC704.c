/*
 * function: func_021BC704
 * address: 0x021BC704
 * packet: pkt_ov209_021BC704
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 */
#include "../include/Obj00088.h"
struct PalAnmSlot;extern void func_020215A0(struct PalAnmSlot *,unsigned);extern void func_02021540(struct PalAnmSlot *);
void func_021BC704(char *p){func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,0);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,1);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,2);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,3);func_02021540(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC);}
