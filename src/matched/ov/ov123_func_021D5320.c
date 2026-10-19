/*
 * function: GSYNC_MENU_ProcMain
 * address: 0x021D5320
 * packet: pkt_ov123_021D5320
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   TCBL_Main 0x020310C4 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WIH_DWC_PollStatus  0x0201058C  thumb  arm9
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 */
#include "../include/Obj01733.h"
extern void APP_TASKMENU_UpdateMenu(void *);
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Tcbl;
extern u32 WIH_DWC_PollStatus(void *key);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void CLACT_DrawSystem(void);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);
int GSYNC_MENU_ProcMain(int a,int b,int c,char *p)
{
    int result=1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result=0;
    }
    if (((struct Obj01733 *)p)->f238) APP_TASKMENU_UpdateMenu(((struct Obj01733 *)p)->f238);
    if (GFL_NET_GetRunState()) {
        ((struct Obj01733 *)p)->f27C=((struct Obj01733 *)p)->f278;
        ((struct Obj01733 *)p)->f278=WIH_DWC_PollStatus(0);
    }
    TCBL_Main(((struct Obj01733 *)p)->f230);
    PRINTSYS_QUE_Main(((struct Obj01733 *)p)->f234);
    BG_SYS_ChangeScrollImmediate(4,3,((struct Obj01733 *)p)->f268);
    --((struct Obj01733 *)p)->f268;
    CLACT_DrawSystem();
    if (!((struct Obj01733 *)p)->f28C) GAMESYSTEM_TryStartAutoComm(((struct Obj01733 *)p)->f264);
    if (WIPE_SYS_EndCheck() && GAMESYSTEM_IsNetOffBySleep(((struct Obj01733 *)p)->f264)) {
        ((struct Obj01733 *)p)->f8=0;
        result=1;
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
    }
    return result;
}
