/*
 * function: EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain
 * address:  0x02181140
 * packet:   pkt_ov018_02181140
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb ov018
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb ov018
 *   d_0218389A     0x0218389A  data ov018 a2
 */
#include "../include/Obj05940.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 d_0218389A[];

typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Obj;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *x);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
u8 *GAME_DATA_GetMyStatus(void *p);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v);
void EVENT_COMM_COMMON_PrintMsg(u8 *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(u8 *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitCommonWork(void *m, u8 *obj);

int EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain(int x, int *st, u8 *obj)
{
    int v = (int)GAME_EVENT_GetGameSystem((struct Obj *)x);
    void *m;

    m = (void *)INTRUDE_COMM_GetWorkIfRunning((int)GAMESYSTEM_GetGameComm((const struct Ctx *)v));
    switch (*st) {
    case 0:
        WORDSET_SetSlotMyStatus((struct WordSet *)(((struct Obj05940 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        WORDSET_SetSlotMyStatus((struct WordSet *)(((struct Obj05940 *)obj)->f10), 1, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData((const struct Ctx *)v)));
        WORDSET_SetSlotFromMsgA0((struct WordSet *)(((struct Obj05940 *)obj)->f10), 2, ((struct Obj05940 *)obj)->f58);
        EVENT_COMM_COMMON_PrintMsg(obj + 0x10, d_0218389A[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(obj + 0x10) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *st = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(m, obj);
        return 1;
    }
    return 0;
}
