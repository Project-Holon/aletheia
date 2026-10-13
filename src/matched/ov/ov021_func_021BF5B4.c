/*
 * function: EVENT_APPEAR_CreateSpinZoom
 * address:  0x021BF5B4
 * packet:   pkt_ov021_021BF5B4
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
 *   EVENT_APPEAR_RunSpinZoom  0x021BF76C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    unsigned char pad8[0x54];
    int f5C;
    int f60;
    int f64;
} Work;

typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int EVENT_APPEAR_RunSpinZoom(void *task, int *state, void **q);


void *EVENT_APPEAR_CreateSpinZoom(int a, int b, int c, int d, int e, int f)
{
    void *t = func_020122C0((void *)b, (void *)a, EVENT_APPEAR_RunSpinZoom, 0x68);
    Work *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    w->f5C = d;
    w->f60 = e;
    w->f64 = f;
    return t;
}
