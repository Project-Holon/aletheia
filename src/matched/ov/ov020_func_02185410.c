/*
 * function: EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate
 * address:  0x02185410
 * packet:   pkt_ov020_02185410
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly  0x02162694  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENT_MAPCHANGE_EntranceCommEvent  0x02184410  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
int EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(int a0, int a1, int a2);
u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
int EVENT_MAPCHANGE_EntranceCommEvent(int a, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);

void *EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(void *p, int u, int a, int b)
{
    void *r0v;
    char *r4;

    GAMESYSTEM_GetGameData(p);
    r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_EntranceCommEvent, 0x9c);
    r4 = func_020124E8(r0v);
    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(a, (int)(r4 + 0x10), b);
    ((struct Obj00248 *)r4)->f2C = EVENTDATA_SYSTEM_GetConnectExitType((u8 *)a);
    return r0v;
}
