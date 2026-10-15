/*
 * function: FIELD_RAIL_LINEPOS_Straight
 * address:  0x021B9B7C
 * packet:   pkt_ov021_021B9B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The +0x30 vector of the FIELD_RAIL_WORK_GetStartPoint object replaces the object pointer
 * in place (`adds r4,#0x30` after the FIELD_RAIL_WORK_GetEndPoint call).  That needs the
 * second call's result bound to a local and the `a += 0x30` as its own
 * statement after it: inline in the argument list the add is hoisted ahead
 * of the call, and without reassigning `a` the compiler keeps both a and
 * a + 0x30 and swaps the s/a registers.
 *
 * symbols:
 *   FIELD_RAIL_WORK_GetSpot  0x021B82F4  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetWidthOffsetRaw  0x021B8300  thumb  ov021
 *   FIELD_RAIL_WORK_GetUnitScale  0x021B8308  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetEndPoint  0x021B834C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_MultAdd  0x0207CEE4  arm
 *   _ll_mul        0x0209C054  arm
 *   d_021D9A54     0x021D9A54  data  ov021  a4
 */

typedef unsigned char  u8;
typedef long long      s64;

typedef struct { int x, y, z; } V;

typedef unsigned int   u32;
u32 FIELD_RAIL_WORK_GetSpot(u8 *p);
u32 FIELD_RAIL_WORK_GetLineOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetWidthOffsetRaw(u8 *p);
u32 FIELD_RAIL_WORK_GetUnitScale(u8 *p);
u8 *FIELD_RAIL_WORK_GetStartPoint(u8 *p);
u8 *FIELD_RAIL_WORK_GetEndPoint(u8 *p);
u32 func_0207C768(u32 a, u32 b);
void VEC_Subtract(V *a, V *b, V *c);
void VEC_CrossProduct(V *a, V *b, V *c);
void VEC_Normalize(V *a, V *b);
void VEC_MultAdd(int s, V *a, V *b, V *c);
extern V d_021D9A54;

void FIELD_RAIL_LINEPOS_Straight(void *p, V *out)
{
    V t;
    V w;
    V u;
    int s;
    V *a;
    u8 *b;
    int m;
    int k;

    FIELD_RAIL_WORK_GetSpot(p);
    s = func_0207C768(FIELD_RAIL_WORK_GetLineOffset(p) << 12, FIELD_RAIL_WORK_GetLineEndOffset(p) << 12);
    a = (V *)FIELD_RAIL_WORK_GetStartPoint(p);
    b = FIELD_RAIL_WORK_GetEndPoint(p);
    a = (V *)((u8 *)a + 0x30);
    VEC_Subtract((V *)(b + 0x30), a, &t);
    VEC_MultAdd(s, &t, a, out);
    w = d_021D9A54;
    m = FIELD_RAIL_WORK_GetWidthOffsetRaw(p);
    k = FIELD_RAIL_WORK_GetUnitScale(p);
    VEC_CrossProduct(&t, &w, &u);
    VEC_Normalize(&u, &u);
    VEC_MultAdd((int)(((s64)(m << 12) * k + 0x800) >> 12), &u, out, out);
}
