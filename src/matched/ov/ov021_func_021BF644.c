/*
 * function: EVENT_APPEAR_CreateDescendingSpin
 * address:  0x021BF644
 * packet:   pkt_ov021_021BF644
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_APPEAR_RunDescendingSpin  0x021BFB90  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
} Ent;

typedef unsigned int   u32;
struct Desc;
int EVENT_APPEAR_RunDescendingSpin(int task, int *state, int *q);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);

int EVENT_APPEAR_CreateDescendingSpin(int a, int b, int c)
{
    int h = (int)func_020122C0((void *)b, (void *)a, EVENT_APPEAR_RunDescendingSpin, 0x68);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f4 = c;
    e->f0 = b;
    return h;
}
