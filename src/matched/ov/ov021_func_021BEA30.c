/*
 * function: EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent
 * address:  0x021BEA30
 * packet:   pkt_ov021_021BEA30
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
} Ent;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
int EVENT_FIELDMAP_CONTROL_RunFadeOut(u32 p0, int *st, u8 *q);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);
int EVENT_FIELDMAP_CONTROL_GetFadeKind(int a);

u32 EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(u32 a, u32 b, u32 c, u32 d)
{
    int h = (int)func_020122C0((void *)a, 0, EVENT_FIELDMAP_CONTROL_RunFadeOut, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = c;
    e->f14 = d;
    e->fC = EVENT_FIELDMAP_CONTROL_GetFadeKind(c);
    return h;
}
