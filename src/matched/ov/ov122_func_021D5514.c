/*
 * function: func_021D5514
 * address: 0x021D5514
 * packet: pkt_ov122_021D5514
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment at 021D55FA, then next labelled function.
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   func_021D5110 0x021D5110 thumb ov122
 *   func_021D5310 0x021D5310 thumb ov122
 *   CLACT_DrawSystem 0x0204A600 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIH_DWC_PollStatus 0x0201058C thumb
 *   func_021D533C 0x021D533C thumb ov122
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02040618 0x02040618 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 */
#include "../include/Obj00208.h"
typedef unsigned int u32;
extern void APP_TASKMENU_UpdateMenu(void *);
extern void func_021D5110(char *);
extern void func_021D5310(unsigned char *p);
extern void CLACT_DrawSystem(void);
extern int GFL_NET_GetRunState(void);
struct BigObj;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Tcbl;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 WIH_DWC_PollStatus(void *);
typedef unsigned char  u8;
extern u32 func_021D533C(u8 *p);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_02040618(u32, u32, u32);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
int func_021D5514(void *a, void *b, void *c, char *p)
{
    int result = 1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result = 0;
    }
    if (((struct Obj00208 *)p)->f324) APP_TASKMENU_UpdateMenu(((struct Obj00208 *)p)->f324);
    if (((struct Obj00208 *)p)->f8 != 1) func_021D5110(p);
    func_021D5310((unsigned char *)p);
    CLACT_DrawSystem();
    if (GFL_NET_GetRunState()) {
        ((struct Obj00208 *)p)->f368 = ((struct Obj00208 *)p)->f364;
        ((struct Obj00208 *)p)->f364 = WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(((struct Obj00208 *)p)->f350));
        ((struct Obj00208 *)p)->f370 = ((struct Obj00208 *)p)->f36C;
        ((struct Obj00208 *)p)->f36C = func_021D533C((u8 *)p);
    }
    TCBL_Main(((struct Obj00208 *)p)->f31C);
    PRINTSYS_QUE_Main(((struct Obj00208 *)p)->f320);
    func_02040618(4, 3, ((struct Obj00208 *)p)->f358);
    ((struct Obj00208 *)p)->f358 = ((struct Obj00208 *)p)->f358 - 1;
    if (WIPE_SYS_EndCheck() && ((struct Obj00208 *)p)->f38C == 0) GAMESYSTEM_TryStartAutoComm(((struct Obj00208 *)p)->f354);
    if (WIPE_SYS_EndCheck() && GAMESYSTEM_IsNetOffBySleep(((struct Obj00208 *)p)->f354)) {
        ((struct Obj00208 *)p)->f8 = 2;
        result = 1;
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
    }
    return result;
}
