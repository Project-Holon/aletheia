/*
 * function: IRCBATTLEMENU_Main
 * address:  0x02197AAC
 * packet:   pkt_ov021_02197AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   IRC_BATTLE_ENTRY_GetGameSys  0x02155A90  thumb  ov010
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01495.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Tcbl;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 WIH_DWC_PollStatus(void *key);
extern void APP_TASKMENU_UpdateMenu(u32);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void func_02040618(u32, u32, u32);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);
extern u32 IRC_BATTLE_ENTRY_GetGameSys(u8 *p);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void WIPE_SetBrightnessFadeOut(u32, u32);

u32 IRCBATTLEMENU_Main(u32 r0, u32 r1, u32 r2, u8 *a)
{
    u32 ret;
    void (*cb)(u8 *);

    cb = *(void (**)(u8 *))a;
    ret = 1;
    WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList((const struct BigObj *)(((struct Obj01495 *)a)->f30)));
    if (cb != 0) {
        cb(a);
        ret = 0;
    }
    if (((struct Obj01495 *)a)->f2C0 != 0) {
        APP_TASKMENU_UpdateMenu(((struct Obj01495 *)a)->f2C0);
    }
    if (((struct Obj01495 *)a)->f2E0 != 0) {
        APP_TASKMENU_WIN_Update((u8 *)(((struct Obj01495 *)a)->f2E0));
    }
    func_02040618(4, 3, ((struct Obj01495 *)a)->f2AC);
    ((struct Obj01495 *)a)->f2AC = ((struct Obj01495 *)a)->f2AC - 1;
    TCBL_Main((struct Tcbl *)(((struct Obj01495 *)a)->f2B8));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj01495 *)a)->f2BC));
    CLACT_DrawSystem();
    if (((struct Obj01495 *)a)->f306 == 0) {
        GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)IRC_BATTLE_ENTRY_GetGameSys((u8 *)(((struct Obj01495 *)a)->f2E4)));
    }
    if (WIPE_SYS_EndCheck() != 0) {
        if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)IRC_BATTLE_ENTRY_GetGameSys((u8 *)(((struct Obj01495 *)a)->f2E4))) != 0) {
            ((struct Obj01495 *)a)->f8 = 12;
            ret = 1;
            WIPE_SetBrightnessFadeOut(0, 0);
            WIPE_SetBrightnessFadeOut(1, 0);
        }
    }
    return ret;
}
