/*
 * function: EVENT_RECOVERY_CreateBallsEvent
 * address:  0x021C0820
 * packet:   pkt_ov021_021C0820
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x38-byte task (callback EVENT_RECOVERY_RunBalls) and initialises it.
 *
 * symbols:
 *   EVENT_RECOVERY_InitBalls  0x021C0904  thumb  ov021
 *   EVENT_RECOVERY_RunBalls  0x021C0844  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);
int EVENT_RECOVERY_RunBalls(u32 a, int *st, u8 *p);
void EVENT_RECOVERY_InitBalls(u8 *p, u32 a, u32 n);

void *EVENT_RECOVERY_CreateBallsEvent(void *p, int a1, u32 n)
{
    void *t = func_020122C0(p, (void *)a1, EVENT_RECOVERY_RunBalls, 0x38);
    u8 *w = func_020124E8(t);

    EVENT_RECOVERY_InitBalls(w, (u32)p, n);
    return t;
}
