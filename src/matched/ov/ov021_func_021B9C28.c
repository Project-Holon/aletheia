/*
 * function: FIELD_RAIL_LINEPOS_ArcFlat
 * address:  0x021B9C28
 * packet:   pkt_ov021_021B9C28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of FIELD_RAIL_LINEPOS_Straight: height interpolated between the two +0x30 vectors
 * of the FIELD_RAIL_WORK_GetStartPoint/FIELD_RAIL_WORK_GetEndPoint objects, then FIELD_RAIL_SlerpVec on the
 * flattened offsets and a sideways push along the normalised result.
 *
 * t1/t2 stay raw in [sp]/[sp,#4] and are shifted `<< 12` at every use
 * because the first call spells the shift over `(u32)` and the second over
 * the plain int: the two shifts are different expressions, so 1.1p1 does not
 * CSE them into a saved fx value (which cost a fourth stack slot).
 *
 * symbols:
 *   FIELD_RAIL_WORK_GetSpot  0x021B82F4  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetWidthOffsetRaw  0x021B8300  thumb  ov021
 *   FIELD_RAIL_WORK_GetUnitScale  0x021B8308  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetEndPoint  0x021B834C  thumb  ov021
 *   FIELD_RAIL_WORK_GetLinePos  0x021B835C  thumb  ov021
 *   FIELD_RAIL_SlerpVec  0x021B9B24  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12865.h"

typedef unsigned char  u8;
typedef long long      s64;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_WORK_GetSpot(u8 *p);
u32 FIELD_RAIL_WORK_GetLineOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetWidthOffsetRaw(u8 *p);
int FIELD_RAIL_WORK_GetUnitScale(void *p);
u8 *FIELD_RAIL_WORK_GetStartPoint(u8 *p);
u8 *FIELD_RAIL_WORK_GetEndPoint(u8 *p);
u8 *FIELD_RAIL_WORK_GetLinePos(void *p);
void FIELD_RAIL_SlerpVec(V *a, V *b, V *c, int k);
u32 func_0207C768(u32 a, u32 b);
void func_0207C9D0(V *a, V *b, V *c);
void func_0207CA00(V *a, V *b, V *c);
void func_0207CAE8(V *a, V *b, V *c);
void VEC_Normalize(V *a, V *b);
void func_0207CEE4(int s, V *a, V *b, V *c);

static inline int FX_Mul(int a, int b)
{
    return (int)(((s64)a * b + 0x800) >> 12);
}

void FIELD_RAIL_LINEPOS_ArcFlat(void *p, V *out)
{
    V c;
    V d;
    V e;
    V g;
    V f;
    V h;
    V i;
    int s;
    int t2;
    int t1;
    V *a;
    V *b;
    u8 *q;
    int r;

    FIELD_RAIL_WORK_GetSpot(p);
    a = (V *)FIELD_RAIL_WORK_GetStartPoint(p);
    b = (V *)FIELD_RAIL_WORK_GetEndPoint(p);
    a = (V *)((u8 *)a + 0x30);
    b = (V *)((u8 *)b + 0x30);
    t1 = FIELD_RAIL_WORK_GetLineOffset(p);
    t2 = FIELD_RAIL_WORK_GetLineEndOffset(p);
    s = func_0207C768((u32)t1 << 12, (u32)t2 << 12);
    out->y = b->y - a->y;
    out->y = func_0207C768(FX_Mul(out->y, t1 << 12), t2 << 12);
    out->y += a->y;
    q = FIELD_RAIL_WORK_GetLinePos(p);
    c.x = ((struct Obj12865 *)q)->f4;
    c.y = out->y;
    c.z = ((struct Obj12865 *)q)->fC;
    func_0207CA00(a, &c, &d);
    func_0207CA00(b, &c, &e);
    d.y = 0;
    e.y = 0;
    func_0207CA00(&e, &d, &f);
    f.y = 0;
    VEC_Normalize(&f, &f);
    FIELD_RAIL_SlerpVec(&g, &d, &e, s);
    func_0207C9D0(&c, &g, out);
    r = (int)(((s64)((int)FIELD_RAIL_WORK_GetWidthOffsetRaw(p) << 12) * FIELD_RAIL_WORK_GetUnitScale(p) + 0x800) >> 12);
    VEC_Normalize(&g, &h);
    func_0207CAE8(&h, &f, &i);
    if (i.y < 0) {
        func_0207CEE4(-r, &h, out, out);
    } else {
        func_0207CEE4(r, &h, out, out);
    }
}
