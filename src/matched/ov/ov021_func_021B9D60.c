/*
 * function: FIELD_RAIL_LINEPOS_Arc
 * address:  0x021B9D60
 * packet:   pkt_ov021_021B9D60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of FIELD_RAIL_LINEPOS_Straight and FIELD_RAIL_LINEPOS_ArcFlat: position from the +0x30 vectors
 * of the FIELD_RAIL_WORK_GetStartPoint/FIELD_RAIL_WORK_GetEndPoint objects through FIELD_RAIL_SlerpVec, then a
 * sideways push along the normalised direction (the segment's cross with
 * d_021D9A60 when the direction has a zero x or z).
 * Both call results go to u8 * locals and the two +0x30 pointers are
 * formed from them after the second call: `(V *)(call + 0x30)` hoists a's
 * add above the second call, and reassigning a/b in place swaps p and b
 * between r4 and r5. d_021D9A60 carries no ov021 token (sole-ref/data
 * resolves it; with the token it has no outside witness).
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
 *   d_021D9A60     0x021D9A60  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09633.h"

typedef unsigned char  u8;
typedef long long      s64;

typedef struct { int x, y, z; } V;

typedef unsigned int   u32;
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
extern V d_021D9A60;

void FIELD_RAIL_LINEPOS_Arc(void *p, V *out)
{
    V c;
    V d;
    V e;
    V g;
    V f;
    V h;
    V i;
    V w;
    int s;
    V *a;
    V *b;
    u8 *q;
    u8 *ta;
    u8 *tb;
    int r;

    FIELD_RAIL_WORK_GetSpot(p);
    ta = FIELD_RAIL_WORK_GetStartPoint(p);
    tb = FIELD_RAIL_WORK_GetEndPoint(p);
    a = (V *)(ta + 0x30);
    b = (V *)(tb + 0x30);
    s = func_0207C768(FIELD_RAIL_WORK_GetLineOffset(p) << 12, FIELD_RAIL_WORK_GetLineEndOffset(p) << 12);
    q = FIELD_RAIL_WORK_GetLinePos(p);
    c.x = ((struct Obj09633 *)q)->f4;
    c.y = ((struct Obj09633 *)q)->f8;
    c.z = ((struct Obj09633 *)q)->fC;
    func_0207CA00(a, &c, &d);
    func_0207CA00(b, &c, &e);
    func_0207CA00(&e, &d, &f);
    VEC_Normalize(&f, &f);
    FIELD_RAIL_SlerpVec(&g, &d, &e, s);
    func_0207C9D0(&c, &g, out);
    r = (int)(((s64)((int)FIELD_RAIL_WORK_GetWidthOffsetRaw(p) << 12) * FIELD_RAIL_WORK_GetUnitScale(p) + 0x800) >> 12);
    if (g.x != 0 && g.z != 0) {
        g.y = 0;
    } else {
        w = d_021D9A60;
        func_0207CA00(b, a, &g);
        func_0207CAE8(&g, &w, &g);
    }
    VEC_Normalize(&g, &h);
    func_0207CAE8(&h, &f, &i);
    if (i.y < 0) {
        func_0207CEE4(-r, &h, out, out);
    } else {
        func_0207CEE4(r, &h, out, out);
    }
}
