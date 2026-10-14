/*
 * function: GSYNC_STATE_StateTransferAnimationOpen
 * address: 0x021D8E28
 * packet: pkt_ov123_021D8E28
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateTransferAnimationStep 0x021D8DFC thumb ov123
 */
#include "../include/Obj06469.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v);
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateTransferAnimationStep(char *p);
void GSYNC_STATE_StateTransferAnimationOpen(char *p)
{
    if (--((struct Obj06469 *)p)->f60 == 0) {
        GSYNC_DISP_SetSlotAnimSeq(((struct Obj06469 *)p)->f14, 0, 1);
        GSYNC_DISP_CreateSlotActor(((struct Obj06469 *)p)->f14, 2);
        GSYNC_DISP_CreateSlotActor(((struct Obj06469 *)p)->f14, 3);
        ((struct Obj06469 *)p)->f60 = 15;
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateTransferAnimationStep, 0x9cf);
    }
}
