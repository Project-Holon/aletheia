/*
 * function: EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault
 * address:  0x021BEB78
 * packet:   pkt_ov021_021BEB78
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
 *   EVENT_FIELDMAP_CONTROL_GetFadeKind  0x021BEA6C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut  0x021BEF08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; } X;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
typedef unsigned char  u8;
extern int EVENT_FIELDMAP_CONTROL_GetFadeKind(int x);
extern int EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut(u32 p0, int *st, u8 *q);
u32 EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault(u32 a, u32 b)
{
    u32 h = (u32)func_020122C0((void *)a, 0, EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut, 0x2c);
    X *x = func_020124E8((struct Obj *)h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 2;
    x->fC = EVENT_FIELDMAP_CONTROL_GetFadeKind(2);
    return h;
}
