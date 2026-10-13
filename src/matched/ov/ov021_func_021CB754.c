/*
 * function: func_021CB754
 * address:  0x021CB754
 * packet:   pkt_ov021_021CB754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D884  0x0200D884  thumb
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb  ov021
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb  ov021
 */
#include "../include/Obj05095.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *a);
struct Big;
struct BigObj;
struct Blk3C;
struct Ctx;
struct Sub020071CCCtrl;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAME_DATA_GetCurrentEvent(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern u32 COMM_ENTRY_MENU_Main(u8 *p);
extern u32 COMM_ENTRY_MENU_Delete(u32 *p);

int func_021CB754(u32 unused, u32 a)
{
    void *s, *h;
    void *t;
    u8 *p;
    int r;
    u32 z;

    t = SCRCMD_WORK_GetScriptWork((void *)a);
    SCRIPT_WORK_ResetFieldParam((int)t);
    s = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(t));
    h = GAME_DATA_GetSaveControl(s);
    GAME_DATA_GetEventWork(s);
    p = GAME_DATA_GetCurrentEvent(s);
    z = 0;
    func_0200D884(func_020071CC(h, 0x39), 0, 0);
    func_020071CC(h, 0x3A);
    r = COMM_ENTRY_MENU_Main((u8 *)(((struct Obj05095 *)p)->f71C));
    if (r != 0) {
        COMM_ENTRY_MENU_Delete((u32 *)(((struct Obj05095 *)p)->f71C));
        ((struct Obj05095 *)p)->f71C = z;
        switch (r) {
        case 1:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = z;
            return 1;
        case 2:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = 1;
            return 1;
        case 4:
        default:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = 2;
            return 1;
        }
    }
    return z;
}
