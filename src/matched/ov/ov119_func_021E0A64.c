/*
 * function: POKETRADE_SAVE_StepCheckEvolution
 * address: 0x021E0A64
 * packet: pkt_ov119_021E0A64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_SAVE_PopBgm 0x021DFD64 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_SAVE_StepBeginSyncRange24 0x021E0BA4 thumb ov119
 *   POKETRADE_SAVE_StepBeginWipeOut 0x021E0C78 thumb ov119
 *   POKETRADE_SAVE_PopBgmFadeIn60 0x021DFD3C thumb ov119
 */
#include "../include/Obj00906.h"
#include "../include/Obj22766.h"
#include "../include/Obj22767.h"
#include "../include/Obj22768.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
struct MsgBank;
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBeginWipeOut(void *);
extern void POKETRADE_SAVE_PopBgm(void *);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_SAVE_StepBeginSyncRange24(void *);
extern void POKETRADE_SAVE_StepBeginWipeOut(char *p);
extern void POKETRADE_SAVE_PopBgmFadeIn60(void *);
void POKETRADE_SAVE_StepCheckEvolution(char *p)
{
    void *a,*b;
    u32 out,result;
    if(*(int *)&((struct Obj00906 *)p)->f82C==0) {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginWipeOut);
        goto exit;
    }
    else {
    if(*(int *)&((struct Obj00906 *)p)->f8!=0) {
        if(POKETRADE_PROC_IsHostSide(p)) {a=POKETRADE_PROC_GetSideMon(p,0);b=POKETRADE_PROC_GetSideMon(p,1);}
        else {a=POKETRADE_PROC_GetSideMon(p,1);b=POKETRADE_PROC_GetSideMon(p,0);}
        result=SHINKA_CHECK_CheckEvolution(0,a,1,(u32)b,GAME_DATA_GetSeason(((struct Obj00906 *)p)->f82C),&out,((struct Obj00906 *)p)->f5F4);
        if(result) {
            ((struct Obj22766 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f8=1;
            ((struct Obj22767 *)(*(char * *)&((struct Obj00906 *)p)->f8))->fC=result;
            ((struct Obj22768 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f10=out;
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);
            POKETRADE_SAVE_PopBgm(p);
            return;
        }
    }
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00906 *)p)->f720),50,(void *)(((struct Obj00906 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginSyncRange24);
    }
exit:
    POKETRADE_SAVE_PopBgmFadeIn60(p);
}
