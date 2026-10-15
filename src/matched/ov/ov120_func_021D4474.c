/*
 * function: GTSNEGO_DISP_MoveCursorVertical
 * address: 0x021D4474
 * packet: pkt_ov120_021D4474
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_MoveRowCursor 0x021D43BC thumb ov120
 */
#include "../include/Obj00495.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GTSNEGO_DISP_MoveRowCursor(int,char *);
void GTSNEGO_DISP_MoveCursorVertical(int n,char *p) { int v; v=((struct Obj00495 *)p)->f160-2; if(((struct Obj00495 *)p)->f160>=2 || ((struct Obj00495 *)p)->f160<=4) GTSNEGO_DISP_MoveRowCursor(n+v*2,p); }
