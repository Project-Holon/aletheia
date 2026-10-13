/*
 * function: EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect
 * address:  0x021BEAFC
 * packet:   pkt_ov021_021BEAFC
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
 *   EVENT_FIELDMAP_CONTROL_RunFadeOut  0x021BEE74  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetFadeKind  0x021BEA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Work;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int EVENT_FIELDMAP_CONTROL_RunFadeOut(u32 p0, int *st, u8 *q);
extern int EVENT_FIELDMAP_CONTROL_GetFadeKind(int a);

void *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect(int a, int b, int c, int d)
{
    void *t = func_020122C0((void *)a, 0, EVENT_FIELDMAP_CONTROL_RunFadeOut, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = c;
    w->f14 = d;
    w->fC = EVENT_FIELDMAP_CONTROL_GetFadeKind(c);
    return t;
}
