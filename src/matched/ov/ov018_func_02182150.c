/*
 * function: EVENT_COMM_COMMON_OfferEventMain
 * address:  0x02182150
 * packet:   pkt_ov018_02182150
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   EVENT_COMM_COMMON_CreateOfferAnswerEvent  0x021821B0  thumb  ov018
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;
struct Evt;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void FLDMMDL_SysPauseMove(void *);
extern void *EVENT_COMM_COMMON_CreateOfferAnswerEvent(void *, int);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELDMAP_IsReady(void *a);
extern u32 *FLDMMDL_SysResumeMove(void *c);

int EVENT_COMM_COMMON_OfferEventMain(void *a, int *state, int c)
{
    void *h;
    u8 *r;

    h = func_020124E4(a);
    r = GAMESYSTEM_GetFieldMap(h);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove((void *)FIELDMAP_GetMmdlSys(r));
        GAME_EVENT_CallEvent(a, EVENT_COMM_COMMON_CreateOfferAnswerEvent(h, c));
        (*state)++;
        break;
    case 1:
        if (r != 0 && FIELDMAP_IsReady(r) == 1) {
            FLDMMDL_SysResumeMove((void *)FIELDMAP_GetMmdlSys(r));
            return 1;
        }
        break;
    }
    return 0;
}
