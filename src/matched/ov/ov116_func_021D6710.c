/*
 * function: WIFI_BSUBWAY_Step
 * address: 0x021D6710
 * packet: pkt_ov116_021D6710
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_BSUBWAY_IsTransferReady 0x021D696C thumb ov116
 *   WIFI_BSUBWAY_AsyncHasError 0x021D7158 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_StartSaveProc 0x021D737C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_GetSaveState 0x021D73D4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateWindow 0x021D7B70 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_InitBt 0x021D7A3C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PrintMessage 0x021D8010 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon 0x021D8190 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PollBt 0x021D7A94 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream 0x021D80CC thumb ov116
 *   WIFI_BSUBWAY_StatusSetMessage 0x021D6B88 thumb ov116
 *   WIFI_BSUBWAY_StatusCheckMessage 0x021D6C50 thumb ov116
 *   WIFI_BSUBWAY_StartProfileUpload 0x021D6CBC thumb ov116
 *   WIFI_BSUBWAY_FinishProfileUpload 0x021D6D18 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DispatchTable 0x021D7424 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CancelBt 0x021D7AA8 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_EndBt 0x021D7AC8 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteWindow 0x021D7C58 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_StartRetryProc 0x021D73E0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CheckNetError 0x021D7B00 thumb ov116
 *   WIFI_BSUBWAY_AbortHttpRequest 0x021D7038 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_IsPrintDone 0x021D7B64 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdateText 0x021D7CF4 thumb ov116
 *   DPW_BT_Main 0x021C8FA8 arm ov114
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb  arm9
 */
#include "../include/Obj00671.h"
#include "../include/Obj22612.h"
#include "../include/Obj22613.h"
#include "../include/Obj22614.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern int WIFI_BSUBWAY_IsTransferReady(u8 *,int);
extern int WIFI_BSUBWAY_AsyncHasError(u8 *p);
extern u32 func_0200FB24(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_FadeInBgmFull(unsigned);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(u8 *);
extern void WIFI_BSUBWAY_GRAPHIC_CreateWindow(u8 *,u32);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void WIFI_BSUBWAY_GRAPHIC_InitBt(u8 *);
extern int WIFI_BSUBWAY_GRAPHIC_GetSaveState(u8 *),FADE_IsActive(void),WIFI_BSUBWAY_GRAPHIC_PollBt(u8 *),WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *);
extern void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *,u32);
extern void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(u8 *p);
extern void WIFI_BSUBWAY_StatusSetMessage(u8 *,void *,int);
extern int WIFI_BSUBWAY_StatusCheckMessage(u8 *,unsigned),WIFI_BSUBWAY_FinishProfileUpload(u8 *,u8 *),WIFI_BSUBWAY_GRAPHIC_DispatchTable(u8 *,int),WIFI_BSUBWAY_GRAPHIC_EndBt(u8 *);
extern void WIFI_BSUBWAY_StartProfileUpload(u8 *,void *,u8 *),WIFI_BSUBWAY_GRAPHIC_CancelBt(u8 *),WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *),WIFI_BSUBWAY_GRAPHIC_StartRetryProc(u8 *);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern int WIFI_BSUBWAY_GRAPHIC_CheckNetError(u8 *);
extern int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(u8 *);
extern void WIFI_BSUBWAY_AbortHttpRequest(u8 *),DPW_BT_Main(void),WIFI_BSUBWAY_GRAPHIC_UpdateText(u8 *);
int WIFI_BSUBWAY_Step(void *a,int *state,int b,u8 *p)
{
    int v;
    if(WIFI_BSUBWAY_IsTransferReady(p,*state)!=0) {
        if(WIFI_BSUBWAY_AsyncHasError(p+0x182c)!=0 || func_0200FB24()!=0) *state=20;
    }
    switch(*state) {
    case 0: GFL_USE_FadeOutBgm(6); ++*state; break;
    case 1: if(GFL_USE_IsBgmFading()==0) { GFL_USE_SetBgmPaused((void *)1); GFL_USE_PushBgm(); GFL_USE_CancelChangeAndPlayBgm(1153,65535); GFL_USE_FadeInBgmFull(6); ++*state; } break;
    case 2: WIFI_BSUBWAY_GRAPHIC_StartSaveProc(p); ++*state; break;
    case 3: if(WIFI_BSUBWAY_GRAPHIC_GetSaveState(p)==0) ++*state; else { ((struct Obj22612 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=2; *state=17; } break;
    case 4: WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,125); FADE_Start(3,16,0,1); ++*state; break;
    case 5: if(FADE_IsActive()==0) ++*state; break;
    case 6: WIFI_BSUBWAY_GRAPHIC_InitBt(p); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,26); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++*state; break;
    case 7: if(WIFI_BSUBWAY_GRAPHIC_PollBt(p)!=0) ++*state; break;
    case 8: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++*state; break;
    case 9: WIFI_BSUBWAY_StatusSetMessage(p+0x1610,((struct Obj00671 *)p)->f1844,125); ++*state; break;
    case 10: if(WIFI_BSUBWAY_StatusCheckMessage(p+0x1610,125)!=0) ++*state; break;
    case 11: WIFI_BSUBWAY_StartProfileUpload(p+0x1610,((struct Obj00671 *)p)->f1844,p+0x182c); ++*state; break;
    case 12: if(WIFI_BSUBWAY_FinishProfileUpload(p+0x1610,p+0x182c)!=0) ++*state; break;
    case 13: v=WIFI_BSUBWAY_GRAPHIC_DispatchTable(p,125); if(v==1) { ((struct Obj22613 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=0; ++*state; } else if(v==2) { ((struct Obj22614 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=2; ++*state; } break;
    case 14: WIFI_BSUBWAY_GRAPHIC_CancelBt(p); FADE_Start(3,0,16,1); ++*state; break;
    case 15: if(WIFI_BSUBWAY_GRAPHIC_EndBt(p)!=0 && FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++*state; } break;
    case 16: if(GFL_NET_ERR_ShowScreen(0)==0) WIFI_BSUBWAY_GRAPHIC_StartRetryProc(p); ++*state; break;
    case 17: GFL_USE_FadeOutBgm(6); ++*state; break;
    case 18: if(GFL_USE_IsBgmFading()==0) ++*state; break;
    case 19: return 1;
    case 20: if(WIFI_BSUBWAY_GRAPHIC_CheckNetError(p)!=0) *state=21; else *state=14; WIFI_BSUBWAY_AbortHttpRequest(p+0x1610); break;
    case 21: if(WIFI_BSUBWAY_GRAPHIC_IsPrintDone(p)!=0) *state=14; break;
    }
    if(((struct Obj00671 *)p)->fB68!=0) DPW_BT_Main();
    WIFI_BSUBWAY_GRAPHIC_UpdateText(p+4);
    return 0;
}
