/*
 * function: EVENT_BATTLE_REC_SAVE_CreateEvent
 * address:  0x021550B0
 * packet:   pkt_02154CA0
 * region:   ov008
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_BATTLE_REC_SAVE_EventMain  0x021550DC  thumb  ov008
 */

typedef unsigned int u32;

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int EVENT_BATTLE_REC_SAVE_EventMain(int u, int *st, int *o);

void *EVENT_BATTLE_REC_SAVE_CreateEvent(void *a0, int a1, int a2, int a3)
{
    void *r = func_020122C0(a0, 0, (void *)((int)EVENT_BATTLE_REC_SAVE_EventMain), 0x40);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    return r;
}
