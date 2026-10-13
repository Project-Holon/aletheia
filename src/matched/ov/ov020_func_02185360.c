/*
 * function: EVENT_MAPCHANGE_CreateExitWarpEvent
 * address:  0x02185360
 * packet:   pkt_ov020_02185360
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
 *   GAME_DATA_GetSpecialLocation  0x02012894  thumb
 *   GAME_DATA_GetEntranceLocation  0x02012870  thumb
 *   func_02013E7C  0x02013E7C  thumb
 *   GAME_DATA_SetEscapeLocation  0x020128C0  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly  0x02162694  thumb  ov010
 *   EVENTDATA_SYSTEM_IsSpecialExitConnect  0x021625E8  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENT_MAPCHANGE_EntranceEvent  0x02184388  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 *   EVENT_MAPCHANGE_UpdateEscapeLocation  0x02185EB0  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02014444Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
S7 *GAME_DATA_GetSpecialLocation(void *p);
struct Rec1C;
struct Rec1C *GAME_DATA_GetEntranceLocation(const struct BigObj *p);
u32 func_02013E7C(u32 id);
void GAME_DATA_SetEscapeLocation(struct BigObj *p, const struct Rec1C *src);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
int EVENTDATA_SYSTEM_IsSpecialExitConnect(int a0);
int EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(int a0, int a1, int a2);
u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
int EVENT_MAPCHANGE_EntranceEvent(int a, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);
void EVENT_MAPCHANGE_UpdateEscapeLocation(int a, u16 *p);

void *EVENT_MAPCHANGE_CreateExitWarpEvent(void *p, int u, int a, int b)
{
    char *r4;
    void *r5 = GAMESYSTEM_GetGameData(p);
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_EntranceEvent, 0x9c);
    u16 *r6;

    r4 = func_020124E8(r0v);
    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    if (EVENTDATA_SYSTEM_IsSpecialExitConnect(a) != 0) {
        *(S7 *)(r4 + 0x10) = *GAME_DATA_GetSpecialLocation(r5);
    } else {
        EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(a, (int)(r4 + 0x10), b);
    }
    ((struct Obj00248 *)r4)->f2C = EVENTDATA_SYSTEM_GetConnectExitType((u8 *)a);
    r6 = (u16 *)GAME_DATA_GetEntranceLocation(r5);
    if (func_02013E7C(r6[2]) == 1 && func_02013E7C(((struct Obj00248 *)r4)->f14) == 0) {
        GAME_DATA_SetEscapeLocation(r5, (const struct Rec1C *)r6);
    }
    EVENT_MAPCHANGE_UpdateEscapeLocation((int)r5, (u16 *)(r4 + 0x10));
    func_0201447C(GAME_DATA_GetMoveModelSys(r5), 2);
    return r0v;
}
