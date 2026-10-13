/*
 * function: EVENT_APPEAR_CreateSpinZoomAlt
 * address:  0x021BF5E8
 * packet:   pkt_ov021_021BF5E8
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
 *   EVENT_APPEAR_RunSpinZoomAlt  0x021BF8EC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 pad[21]; u32 f5C; u32 f60; u32 f64; } X;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int EVENT_APPEAR_RunSpinZoomAlt(void *task, int *state, void **q);
u32 EVENT_APPEAR_CreateSpinZoomAlt(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    u32 h = (u32)func_020122C0((void *)b, (void *)a, EVENT_APPEAR_RunSpinZoomAlt, 0x68);
    X *x = func_020124E8((struct Obj *)h);
    x->f4 = c;
    x->f0 = b;
    x->f5C = d;
    x->f60 = e;
    x->f64 = f;
    return h;
}
