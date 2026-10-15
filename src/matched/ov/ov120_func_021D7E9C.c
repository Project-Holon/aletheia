/*
 * function: GTSNEGO_MSG_RedrawRowB
 * address: 0x021D7E9C
 * packet: pkt_ov120_021D7E9C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: separately filed 021D7EB0.
 * symbols:
 *   GTSNEGO_MSG_RedrawRow 0x021D7CE8 thumb ov120
 *   gGtsnegoRowLabelB 0x021D8BE0 data a2
 */
#include "../include/Obj22846.h"
typedef unsigned short u16;
extern const u16 gGtsnegoRowLabelB[];
extern void GTSNEGO_MSG_RedrawRow(char *p, u16 n, int i);
void GTSNEGO_MSG_RedrawRowB(char *p,int i) {GTSNEGO_MSG_RedrawRow(p,gGtsnegoRowLabelB[i],((struct Obj22846 *)p)->f28);}
