/*
 * function: GSYNC_STATE_StateShowCompletionMessage
 * address: 0x021D8A9C
 * packet: pkt_ov123_021D8A9C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GSYNC_MESSAGE_SetMonName 0x021D57D0 thumb ov123
 *   GSYNC_MESSAGE_PrintStream 0x021D56FC thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_DISP_SetFadeDirection 0x021D6650 thumb ov123
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageThenNext 0x021D8A7C thumb ov123
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj02183.h"
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_DISP_UpdateProgressPosition(u8 *p, int n);
extern void GSYNC_MESSAGE_SetMonName(void *p, int msg, int n, void *mon);
extern void GSYNC_MESSAGE_PrintStream(char *p, int mode);
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
extern void GSYNC_DISP_SetFadeDirection(u8 *p, int flag);
extern void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageThenNext(char *p);
void GSYNC_STATE_StateShowCompletionMessage(char *p)
{
    if (((struct Obj02183 *)p)->f44) {
        func_020307B0(((struct Obj02183 *)p)->f44);
        ((struct Obj02183 *)p)->f44=0;
    }
    ((struct Obj02183 *)p)->f70=100;
    GSYNC_DISP_UpdateProgressPosition(((struct Obj02183 *)p)->f14,100);
    GSYNC_MESSAGE_SetMonName(((struct Obj02183 *)p)->f18,14,0,(void *)(((struct Obj02183 *)p)->fC));
    GSYNC_MESSAGE_PrintStream(((struct Obj02183 *)p)->f18,0);
    GSYNC_DISP_CreateSlotActor(((struct Obj02183 *)p)->f14,8);
    GSYNC_DISP_SetFadeDirection(((struct Obj02183 *)p)->f14,0);
    GSYNC_DISP_CreateSlotActor(((struct Obj02183 *)p)->f14,0);
    GSYNC_DISP_SetSlotAnimSeq(((struct Obj02183 *)p)->f14,4,6);
    GFL_USE_PlaySeDefaultVolume(0x658);
    GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageThenNext,0x8bd);
}
