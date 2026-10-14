/*
 * function: CircleGraph_UpdateState
 * address: 0x021C15B8
 * packet: pkt_ov217_021C15B8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CircleGraph_UpdateHidden 0x021C1610 thumb ov217
 *   CircleGraph_UpdateDrawSlow 0x021C1628 thumb ov217
 *   CircleGraph_UpdateDrawFast 0x021C1638 thumb ov217
 *   CircleGraph_UpdateErase 0x021C1648 thumb ov217
 *   CircleGraph_UpdateShown 0x021C1658 thumb ov217
 *   CircleGraph_UpdateDrawMedium 0x021C1670 thumb ov217
 *   CircleGraph_AdvanceFrame 0x021C1680 thumb ov217
 *   CircleGraph_TickHold 0x021C16C4 thumb ov217
 */
#include "../include/Obj04640.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 w0,w4,type,wc,counter; } Rec;
extern void CircleGraph_UpdateHidden(u32);
extern void CircleGraph_UpdateDrawSlow(u8 *);
extern void CircleGraph_UpdateDrawFast(u8 *);
extern void CircleGraph_UpdateErase(u8 *);
extern void CircleGraph_UpdateShown(u32);
extern void CircleGraph_UpdateDrawMedium(u8 *);
extern void CircleGraph_AdvanceFrame(Rec *);
extern void CircleGraph_TickHold(void *);
void CircleGraph_UpdateState(u8 *p)
{
    if (((struct Obj04640 *)p)->f14==0) {
        switch (((struct Obj04640 *)p)->f8) {
        case 0: CircleGraph_UpdateHidden((u32)p); break;
        case 1: CircleGraph_UpdateDrawSlow(p); break;
        case 2: CircleGraph_UpdateDrawFast(p); break;
        case 3: CircleGraph_UpdateErase(p); break;
        case 4: CircleGraph_UpdateShown((u32)p); break;
        case 5: CircleGraph_UpdateDrawMedium(p); break;
        }
    }
    CircleGraph_AdvanceFrame((Rec *)p);
    CircleGraph_TickHold(p);
}
