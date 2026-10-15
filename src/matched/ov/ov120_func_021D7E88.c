/*
 * function: GTSNEGO_MSG_RedrawRowA
 * address: 0x021D7E88
 * packet: pkt_ov120_021D7E88
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: separately filed 021D7E9C.
 * symbols:
 *   GTSNEGO_MSG_RedrawRow 0x021D7CE8 thumb ov120
 *   gGtsnegoRowLabelA 0x021D8BD8 data a2
 */
#include "../include/Obj22845.h"
typedef unsigned short u16;
extern const u16 gGtsnegoRowLabelA[];
extern void GTSNEGO_MSG_RedrawRow(char *p, u16 n, int i);
void GTSNEGO_MSG_RedrawRowA(char *p,int i) {GTSNEGO_MSG_RedrawRow(p,gGtsnegoRowLabelA[i],((struct Obj22845 *)p)->f24);}
