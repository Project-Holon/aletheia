/*
 * function: EVENT_POKE_STATUS_CreatePokeSelectEvent
 * address:  0x0215A07C
 * packet:   pkt_ov010_0215A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_02030734  0x02030734  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_POKE_STATUS_PokeSelectEvent  0x0215A214  thumb  ov010
 *   d_021728CC  0x021728CC  data
 */
#include "../include/Obj07281.h"

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    void *f0;
    void *f4;
    u32 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Task;

struct BigObj;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void EVENT_POKE_STATUS_PokeSelectEvent(void);
extern const char d_021728CC[];

void *EVENT_POKE_STATUS_CreatePokeSelectEvent(int a, u16 *b, u16 *c)
{
    void *h = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((void *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x40);
    void *r;
    Task *q;
    ((struct Obj07281 *)p)->f0 = h;
    p[0x34 / 4] = 3;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    r = func_020122C0((void *)a, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    q = func_020124E8(r);
    q->f0 = (void *)a;
    q->f4 = GAMESYSTEM_GetFieldMap((void *)a);
    q->f8 = p;
    q->fC = 0;
    q->f10 = b;
    q->f14 = c;
    return r;
}
