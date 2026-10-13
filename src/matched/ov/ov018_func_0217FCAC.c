/*
 * function: EVENT_COMM_COMMON_TalkedStartEventMain
 * address:  0x0217FCAC
 * packet:   pkt_ov018_0217FCAC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb ov010
 *   COMM_PLAYER_CheckActive  0x02167A54  thumb ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb ov010
 *   EVENT_COMM_COMMON_CreateTalkedEvent  0x0217FD34  thumb ov018
 */
#include "../include/Obj04178.h"

typedef unsigned short u16;
struct Ctx;

typedef unsigned char  u8;
struct Evt;
struct Obj;
void *func_020124E4(struct Obj *p);
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int COMM_PLAYER_CheckActive(int *p, int i);
void *FIELDMAP_GetMmdlSys(unsigned char *p);
void FLDMMDL_SysPauseMove(void *x);
typedef unsigned int   u32;
u32 *FLDMMDL_SysResumeMove(void *c);
void *EVENT_COMM_COMMON_CreateTalkedEvent(int a, int b, u8 *c, int d, int e, u16 f);

int EVENT_COMM_COMMON_TalkedStartEventMain(int x, int *st, int *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    int *m;

    m = (int *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)v));
    switch (*st) {
    case 0:
        if (m == 0) {
            return 1;
        }
        if (COMM_PLAYER_CheckActive((int *)m[2], obj[2]) == 0) {
            return 1;
        }
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((unsigned char *)obj[0]));
        GAME_EVENT_CallEvent((struct Evt *)x, EVENT_COMM_COMMON_CreateTalkedEvent(v, obj[0], (u8 *)m, obj[1], obj[2], ((struct Obj04178 *)obj)->fC));
        *st = *st + 1;
        break;
    case 1:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((unsigned char *)obj[0]));
        return 1;
    }
    return 0;
}
