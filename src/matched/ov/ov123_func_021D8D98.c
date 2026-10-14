/*
 * function: GSYNC_STATE_StateStartTransferAnimation
 * address: 0x021D8D98
 * packet: pkt_ov123_021D8D98
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_StartPaletteWave 0x021D65F4 thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 *   GSYNC_MESSAGE_RestartTimeIcon 0x021D5A7C thumb ov123
 *   GSYNC_DISP_SetFadeDirection 0x021D6650 thumb ov123
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSendRecordRequest 0x021D8D08 thumb ov123
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj03798.h"
extern void GSYNC_DISP_StartPaletteWave(unsigned char *p);
extern void GSYNC_MESSAGE_PrintStreamId(char *,int);
extern void GSYNC_MESSAGE_RestartTimeIcon(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_DISP_SetFadeDirection(u8 *p, int flag);
extern void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v);
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSendRecordRequest(char *p);
void GSYNC_STATE_StateStartTransferAnimation(char *p)
{
    if (--((struct Obj03798 *)p)->f60==0) {
        GSYNC_DISP_StartPaletteWave((unsigned char *)(*(char * *)&((struct Obj03798 *)p)->f14));
        GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj03798 *)p)->f18,8);
        GSYNC_MESSAGE_RestartTimeIcon(*(char * *)&((struct Obj03798 *)p)->f18);
        GSYNC_DISP_SetFadeDirection(((struct Obj03798 *)p)->f14,1);
        GSYNC_DISP_SetSlotAnimSeq(((struct Obj03798 *)p)->f14,4,5);
        GSYNC_DISP_SetSlotAnimSeq(((struct Obj03798 *)p)->f14,0,0);
        GSYNC_DISP_CreateSlotActor(((struct Obj03798 *)p)->f14,12);
        GFL_USE_PlaySeDefaultVolume(0x657);
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendRecordRequest,0x9a8);
    }
}
