/*
 * function: GSYNC_STATE_ProcMain
 * address: 0x021D9158
 * packet: pkt_ov123_021D9158
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200F7C0 0x0200F7C0 thumb
 *   GSYNC_DOWNLOAD_CleanupOnce 0x021D5D58 thumb ov123
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   GSYNC_STATE_CommitReceivedMon 0x021D8F58 thumb ov123
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GSYNC_DOWNLOAD_Process 0x021D5D7C thumb ov123
 *   GSYNC_DISP_Draw 0x021D5E60 thumb ov123
 *   GSYNC_MESSAGE_UpdateSystem 0x021D562C thumb ov123
 *   func_0200FB24 0x0200FB24 thumb
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 */
#include "../include/Obj01406.h"
#include "../include/Obj22983.h"
typedef unsigned char u8;
extern unsigned int WIPE_SYS_EndCheck(void);
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern int GSYNC_DOWNLOAD_CleanupOnce(char *p);
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void GAME_DATA_SaveCancel(char *p);
extern void GSYNC_STATE_CommitReceivedMon(char *);
extern void func_0200F7C0(u32 value);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void GSYNC_DOWNLOAD_Process(char *p);
extern void GSYNC_DISP_Draw(u8 *p);
extern void GSYNC_MESSAGE_UpdateSystem(char *p);
int GSYNC_STATE_ProcMain(void *a, int b, int c, char *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))(p+0x50);
    result=1;
    if (WIPE_SYS_EndCheck() && !((struct Obj01406 *)p)->fAE && func_0200FB24()) {
        if (((struct Obj01406 *)p)->f8) GSYNC_DOWNLOAD_CleanupOnce(((struct Obj01406 *)p)->f8);
        NHTTP_RAP_DeleteConnection(((struct Obj01406 *)p)->f10);
        if (((struct Obj01406 *)p)->fAD) {
            GAME_DATA_SaveCancel(((struct Obj01406 *)p)->f2C);
            ((struct Obj01406 *)p)->fAD=0;
        }
        GSYNC_STATE_CommitReceivedMon(p);
        if (((struct Obj01406 *)p)->fAB) func_0200F7C0(41);
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
        DWC_RAPCOMMON_HandleNetError(1,0);
        ((struct Obj22983 *)(*(char * *)&((struct Obj01406 *)p)->f20))->f1C8=7;
        return 1;
    }
    if (callback) { callback(p); result=0; }
    if (((struct Obj01406 *)p)->f1C) APP_TASKMENU_UpdateMenu(((struct Obj01406 *)p)->f1C);
    if (((struct Obj01406 *)p)->f8) GSYNC_DOWNLOAD_Process(((struct Obj01406 *)p)->f8);
    GSYNC_DISP_Draw(((struct Obj01406 *)p)->f14);
    GSYNC_MESSAGE_UpdateSystem(((struct Obj01406 *)p)->f18);
    return result;
}
