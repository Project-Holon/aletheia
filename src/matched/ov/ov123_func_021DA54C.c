/*
 * function: PDWACC_STATE_ProcMain
 * address: 0x021DA54C
 * packet: pkt_ov123_021DA54C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_DISP_Draw 0x021D9A14 thumb ov123
 *   PDWACC_MESSAGE_UpdateSystem 0x021D9404 thumb ov123
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 */
#include "../include/Obj03276.h"
#include "../include/Obj22990.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0200FB24(void);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void PDWACC_DISP_Draw(int);
extern void PDWACC_MESSAGE_UpdateSystem(char *p);
extern u32 WIPE_SYS_EndCheck(void);
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void GAME_DATA_SaveCancel(char *p);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
int PDWACC_STATE_ProcMain(int a,int b,char *c,char *p)
{
    void (*f)(char *);
    int r;
    f = *(void (**)(char *))(p + 0x30);
    r = 1;
    if (f) {
        if (!func_0200FB24()) f(p);
        r = 0;
    }
    if (((struct Obj03276 *)p)->f14) APP_TASKMENU_UpdateMenu(((struct Obj03276 *)p)->f14);
    PDWACC_DISP_Draw(((struct Obj03276 *)p)->fC);
    PDWACC_MESSAGE_UpdateSystem(((struct Obj03276 *)p)->f10);
    if (WIPE_SYS_EndCheck()) {
        if (func_0200FB24()) {
            NHTTP_RAP_DeleteConnection(((struct Obj03276 *)p)->f8);
            if (((struct Obj03276 *)p)->f6C) {
                GAME_DATA_SaveCancel(((struct Obj03276 *)p)->f20);
                ((struct Obj03276 *)p)->f6C = 0;
            }
            WIPE_SetBrightnessFadeOut(0,0);
            WIPE_SetBrightnessFadeOut(1,0);
            r = 1;
            DWC_RAPCOMMON_HandleNetError(1,0);
            ((struct Obj22990 *)c)->f10 = 1;
        }
    } else if (func_0200FB24()) r = 1;
    return r;
}
