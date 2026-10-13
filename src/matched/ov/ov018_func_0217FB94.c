/*
 * function: EVENT_COMM_COMMON_TalkStartEventMain
 * address:  0x0217FB94
 * packet:   pkt_ov018_0217FB94
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   EVENT_COMM_COMMON_CreateTalkEvent  0x0217FC08  thumb  ov018
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 fC;
} Req;

struct Evt;
struct Obj;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void *FIELDMAP_GetMmdlSys(unsigned char *p);
void FLDMMDL_SysPauseMove(void *x);
typedef unsigned int   u32;
u32 *FLDMMDL_SysResumeMove(void *c);
void *EVENT_COMM_COMMON_CreateTalkEvent(int a, int b, u8 *c, int d, int e, u16 f);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_COMM_COMMON_TalkStartEventMain(int a, int *state, Req *req)
{
    int s;
    u8 *w;

    s = (int)GAME_EVENT_GetGameSystem((struct Obj *)a);
    w = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)s));
    switch (*state) {
    case 0:
        if (w == 0) {
            return 1;
        }
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((u8 *)req->f0));
        GAME_EVENT_CallEvent((struct Evt *)a, EVENT_COMM_COMMON_CreateTalkEvent(s, req->f0, w, req->f4, req->f8, req->fC));
        (*state)++;
        break;
    case 1:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((u8 *)req->f0));
        return 1;
    }
    return 0;
}
