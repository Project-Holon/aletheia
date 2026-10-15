/*
 * function: FIELD_COMM_ACTOR_SubscreenChangeMain
 * address:  0x021945E0
 * packet:   pkt_ov021_021945E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_DATA_SetFrameRate  0x020129D0  thumb
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */
#include "../include/Obj02693.h"

typedef unsigned int u32;
typedef unsigned char u8;

struct Obj;
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern u32 GAMESYSTEM_GetGameData(void);
extern void FLDMMDL_SysPauseMove(void *a);
struct BigObj;
extern void GAME_DATA_SetFrameRate(struct BigObj *p, u8 v);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);
extern void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v);
extern u32 *FLDMMDL_SysResumeMove(void *c);

int FIELD_COMM_ACTOR_SubscreenChangeMain(void *a, int b, u8 *c)
{
    void *r6;
    u32 r4;

    switch (c[0x10]) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(((struct Obj02693 *)c)->f8)) == 1) {
            r6 = FIELDMAP_GetMmdlSys(((struct Obj02693 *)c)->f8);
            GAME_EVENT_GetGameSystem(a);
            r4 = GAMESYSTEM_GetGameData();
            FLDMMDL_SysPauseMove(r6);
            GAME_DATA_SetFrameRate((struct BigObj *)r4, 1);
            FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(((struct Obj02693 *)c)->f8), ((struct Obj02693 *)c)->fC);
            c[0x10]++;
        }
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(((struct Obj02693 *)c)->f8)) == 1) {
            GAME_EVENT_GetGameSystem(a);
            GAME_DATA_SetSubscreenType((struct BigObj *)GAMESYSTEM_GetGameData(), ((struct Obj02693 *)c)->fC & 0xff);
            c[0x10]++;
        }
        break;
    case 2:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(((struct Obj02693 *)c)->f8));
        return 1;
    }
    return 0;
}
