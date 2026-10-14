/*
 * function: GSYNC_STATE_StateSaveFinishMessage
 * address: 0x021D72D8
 * packet: pkt_ov123_021D72D8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_MESSAGE_SetMonName 0x021D57D0 thumb ov123
 *   GSYNC_MESSAGE_PrintInWindow 0x021D5960 thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_DISP_SetSlotAnimCommand 0x021D62D0 thumb ov123
 *   GSYNC_DISP_SetFadeDirection 0x021D6650 thumb ov123
 *   GSYNC_DISP_CreateMonIconActor 0x021D6458 thumb ov123
 *   GSYNC_DISP_RestartActorAnim 0x021D652C thumb ov123
 *   GSYNC_STATE_ResetSlotActors 0x021D7204 thumb ov123
 *   GSYNC_STATE_StateShowResultMessage 0x021D7180 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GAME_DATA_SaveMain  0x02012DD0  thumb  arm9
 *   POKE_TOOL_Dummy  0x020185F0  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01254.h"
typedef unsigned short u16;
typedef struct { u16 f0; char *f4; void (*f8)(char *); } Callback;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int GAME_DATA_SaveMain(u8 *p);
extern void GSYNC_MESSAGE_ClearStream(char *);
extern void GSYNC_MESSAGE_SetMonName(void *p, int msg, int n, void *mon);
extern void GSYNC_MESSAGE_PrintInWindow(char *,int,int);
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
extern void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v);
extern void GSYNC_DISP_SetSlotAnimCommand(u8 *p, int i, int v);
extern void GSYNC_DISP_SetFadeDirection(u8 *p, int flag);
extern int POKE_TOOL_Dummy(void *);
struct Obj02181;
extern void GSYNC_DISP_CreateMonIconActor(struct Obj02181 *p, void *n, int i);
extern void GSYNC_DISP_RestartActorAnim(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GSYNC_STATE_ResetSlotActors(u8 *p);
extern void GSYNC_STATE_StateShowResultMessage(int a);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateSaveFinishMessage(char *p)
{
    Callback cb;
    func_02009448(((struct Obj01254 *)p)->f28);
    if (GAME_DATA_SaveMain(((struct Obj01254 *)p)->f2C)==2) {
        ((struct Obj01254 *)p)->fAD=0;
        ((struct Obj01254 *)p)->fAB=0;
        ((struct Obj01254 *)p)->fAE=0;
        GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj01254 *)p)->f18);
        GSYNC_MESSAGE_SetMonName(*(char * *)&((struct Obj01254 *)p)->f18,45,0,(void *)(*(int *)&((struct Obj01254 *)p)->fC));
        GSYNC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj01254 *)p)->f18,1,4);
        GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        GSYNC_DISP_SetSlotAnimSeq((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),6,7);
        GSYNC_DISP_SetSlotAnimSeq((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,1);
        cb.f0=0; cb.f4=p; cb.f8=(void (*)(char *))GSYNC_STATE_ResetSlotActors;
        GSYNC_DISP_SetSlotAnimCommand((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,(int)&cb);
        GSYNC_DISP_SetFadeDirection((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        GSYNC_DISP_CreateMonIconActor((struct Obj02181 *)(*(char * *)&((struct Obj01254 *)p)->f14),(void *)POKE_TOOL_Dummy(((struct Obj01254 *)p)->fC),0);
        GSYNC_DISP_RestartActorAnim(*(char * *)&((struct Obj01254 *)p)->f14);
        GFL_USE_PlaySeDefaultVolume(0x658);
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateShowResultMessage,0x295);
    }
}
