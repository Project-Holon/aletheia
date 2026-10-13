/*
 * function: FIELD_PLAYER_GRID_CheckMapConnectAhead
 * address:  0x021A5810
 * packet:   pkt_ov021_021A5810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   EVENTDATA_SYSTEM_SearchConnectIdByGridPos  0x02162564  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectExitDir  0x021626B8  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
struct Q;
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(char *p, struct Q *q);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern int EVENTDATA_SYSTEM_IsConnectExitDir(char *a0, int a1);

int FIELD_PLAYER_GRID_CheckMapConnectAhead(u8 *p, int dir)
{
    u8 *a;
    int h;
    int i;
    Vec3 pos;

    a = FIELD_PLAYER_CORE_GetMmdl(*(u8 * *)&((struct Obj00262 *)p)->fC);
    h = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(*(u8 * *)&((struct Obj00262 *)p)->f10)));
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&pos);
    FLDMMDL_MOVE_AddDirVector(dir, (int *)(&pos), 0x10000);
    i = EVENTDATA_SYSTEM_SearchConnectIdByGridPos((char *)h, (struct Q *)(&pos));
    if (i == 0xffff) {
        return 0;
    }
    if (EVENTDATA_SYSTEM_IsConnectExitDir(EVENTDATA_SYSTEM_GetConnectData((char *)h, (u16)i), dir)) {
        return 1;
    }
    return 0;
}
