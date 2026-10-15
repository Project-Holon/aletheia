/*
 * function: GTSNEGO_MSG_CreateDraw
 * address: 0x021D8430
 * packet: pkt_ov120_021D8430
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   GTSNEGO_DISP_GetUnit 0x021D60FC thumb ov120
 *   PMS_DRAW_Create 0x0202DB0C thumb
 */
#include "../include/Obj06444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PmsDraw;
extern u32 GTSNEGO_DISP_GetUnit(u8 *p);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
void GTSNEGO_MSG_CreateDraw(u8 *p,void *q)
{
    if(!((struct Obj06444 *)p)->fCC)
        ((struct Obj06444 *)p)->fCC=PMS_DRAW_Create(GTSNEGO_DISP_GetUnit(q),0,(u32)(((struct Obj06444 *)p)->fA4),(u32)(((struct Obj06444 *)p)->f14),8,4,((struct Obj06444 *)p)->fC8);
}
