/*
 * function: GSYNC_STATE_StateShowProgressMessage
 * address: 0x021D8154
 * packet: pkt_ov123_021D8154
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 *   GSYNC_MESSAGE_RestartTimeIcon 0x021D5A7C thumb ov123
 *   GSYNC_DISP_DeleteSlotActor 0x021D62E0 thumb ov123
 *   GSYNC_DISP_StartPaletteWave 0x021D65F4 thumb ov123
 *   GSYNC_DISP_SetFadeDirection 0x021D6650 thumb ov123
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageThenSend 0x021D8130 thumb ov123
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj03795.h"
typedef unsigned char u8;
extern void GSYNC_MESSAGE_PrintStreamId(char *, int);
extern void GSYNC_MESSAGE_RestartTimeIcon(char *);
extern void GSYNC_DISP_DeleteSlotActor(u8 *, int);
extern void GSYNC_DISP_StartPaletteWave(u8 *p);
extern void GSYNC_DISP_SetFadeDirection(u8 *p, int flag);
extern void GSYNC_DISP_SetSlotAnimSeq(u8 *, int, unsigned int);
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageThenSend(char *p);
void GSYNC_STATE_StateShowProgressMessage(char *p)
{
    GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj03795 *)p)->f18, 11);
    GSYNC_MESSAGE_RestartTimeIcon(*(char * *)&((struct Obj03795 *)p)->f18);
    GSYNC_DISP_DeleteSlotActor(*(u8 * *)&((struct Obj03795 *)p)->f14, 8);
    GSYNC_DISP_StartPaletteWave((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14));
    GSYNC_DISP_SetFadeDirection((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 1);
    GSYNC_DISP_SetSlotAnimSeq(*(u8 * *)&((struct Obj03795 *)p)->f14, 6, 5);
    GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 0);
    GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 12);
    GFL_USE_PlaySeDefaultVolume(0x657);
    GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitMessageThenSend, 0x5c3);
}
