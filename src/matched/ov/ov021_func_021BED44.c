/*
 * function: EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7
 * address:  0x021BED44
 * packet:   pkt_ov021_021BED44
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
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect7  0x021BF430  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetFadeKind  0x021BEA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work;

typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int EVENT_FIELDMAP_CONTROL_RunWipeInEffect7(int a, int *s, int *q);
extern int EVENT_FIELDMAP_CONTROL_GetFadeKind(int a);

void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect7, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 7;
    w->fC = EVENT_FIELDMAP_CONTROL_GetFadeKind(7);
    return t;
}
