/*
 * function: EVENT_POKE_STATUS_CreateMoveSelectEvent
 * address:  0x0215A2E4
 * packet:   pkt_ov010_0215A2E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_POKE_STATUS_MoveSelectEvent  0x0215A370  thumb  ov010
 *   d_021728CC     0x021728CC  data  ov010  a4
 */
#include "../include/Obj03073.h"

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void EVENT_POKE_STATUS_MoveSelectEvent(void);
extern int d_021728CC;

int EVENT_POKE_STATUS_CreateMoveSelectEvent(int a, int b, int c, int d, int e, int f, unsigned short g)
{
    int t8 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    void *t12 = GAME_DATA_GetMyParty((void *)t8);
    char *p = (char *)func_02030734(4, 0x98, 1, (const char *)&d_021728CC, 0x11d);
    int r;
    int *q;

    ((struct Obj03073 *)p)->f0 = (int)t12;
    p[0xc] = 1;
    p[0xe] = POKEPARTY_GetCount(t12);
    p[0xf] = c;
    p[0x10] = 1;
    ((struct Obj03073 *)p)->f14 = g;
    p[0xd] = (f == 1) ? 3 : 2;
    ((struct Obj03073 *)p)->f20 = 0;
    ((struct Obj03073 *)p)->f8 = t8;
    r = (int)func_020122C0((void *)a, 0, EVENT_POKE_STATUS_MoveSelectEvent, 0x14);
    q = func_020124E8((struct Obj *)r);
    q[0] = a;
    q[1] = b;
    q[2] = (int)p;
    q[3] = d;
    q[4] = e;
    return r;
}
