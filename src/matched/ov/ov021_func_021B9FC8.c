/*
 * function: FIELD_RAIL_LINEFUNC_Arc
 * address:  0x021B9FC8
 * packet:   pkt_ov021_021B9FC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks the segments of the path object FIELD_RAIL_GetProbeWork returns (slot i in
 * the record's +6 field, points from FIELD_RAIL_WORK_GetPos) looking for the one pos
 * projects onto; when the horizontal distance to the projection is within
 * FIELD_RAIL_WORK_GetWidthLimit's range + 0x10, fills the record's +4 field from it and
 * returns 1 when the record round-trips through FIELD_RAIL_ClampLocation and
 * FIELD_RAIL_GetLocationPos. Sibling of FIELD_RAIL_LINEFUNC_Straight.
 * pos->x and pos->z read into x/z locals before the R stores: written
 * straight into R, pos keeps a callee-saved register, obj is spilled
 * instead, and 187 bytes move.
 *
 * symbols:
 *   FIELD_RAIL_GetPoint  0x021B8224  thumb  ov021
 *   FIELD_RAIL_GetLine  0x021B8230  thumb  ov021
 *   FIELD_RAIL_GetUnitScaleRaw  0x021B8248  thumb  ov021
 *   FIELD_RAIL_GetProbeWork  0x021B824C  thumb  ov021
 *   FIELD_RAIL_ClampLocation  0x021B8250  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetWidthLimit  0x021B8304  thumb  ov021
 *   FIELD_RAIL_RoundToGrid  0x021B8378  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FIELD_RAIL_ProjectOnSegment  0x021BAE7C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   VEC_Add  0x0207C9D0  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Mag  0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;
typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    s16 f4;
    s16 f6;
} Rec;

int *FIELD_RAIL_GetPoint(void *p, int k);
int *FIELD_RAIL_GetLine(void *p, int a);
u32 FIELD_RAIL_GetUnitScaleRaw(u8 *p);
u32 FIELD_RAIL_GetProbeWork(u8 *p);
void FIELD_RAIL_ClampLocation(void *p, Rec *r, Rec *o);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetWidthLimit(u8 *p);
int FIELD_RAIL_RoundToGrid(int x);
int FIELD_RAIL_GetLocationPos(void *p, Rec *r, int c);
void FIELD_RAIL_WORK_SetLocation(void *o, Rec *r);
void FIELD_RAIL_WORK_GetPos(void *o, V *v);
int FIELD_RAIL_ProjectOnSegment(int *e0, int *e1, const V *pos, V *a, int *b, V *c);
int func_0207C768(int a, int b);
void VEC_Add(V *a, V *b, V *c);
void VEC_Subtract(const V *a, V *b, V *c);
int VEC_DotProduct(V *a, V *b);
void VEC_CrossProduct(V *a, V *b, V *c);
int VEC_Mag(V *a);
void VEC_Normalize(V *a, V *b);
int VEC_Distance(const V *a, const V *b);
typedef signed int     s32;
s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

static inline int FX_Mul(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

int FIELD_RAIL_LINEFUNC_Arc(int a, void *p, const V *pos, Rec *out, int arg)
{
    V P;
    V Q;
    V D;
    V E;
    V F;
    V A;
    V C;
    V R;
    V S;
    V G;
    V H;
    int B;
    Rec buf;
    int len;
    u32 lim;
    u32 n;
    int k;
    u32 i;
    int *info;
    int *e0;
    int *e1;
    void *obj;
    int m;
    int t;
    int d;
    int u;
    u32 dist;
    int x;
    int z;

    info = FIELD_RAIL_GetLine(p, a);
    e0 = FIELD_RAIL_GetPoint(p, info[0]);
    e1 = FIELD_RAIL_GetPoint(p, info[1]);
    if (FIELD_RAIL_ProjectOnSegment(e0, e1, pos, &A, &B, &C) == 0) {
        return 0;
    }
    out->id = a;
    out->f2 = 1;
    out->f3 = 3;
    out->f4 = 0;
    out->f6 = 0;
    obj = (void *)FIELD_RAIL_GetProbeWork(p);
    FIELD_RAIL_WORK_SetLocation(obj, out);
    n = FIELD_RAIL_WORK_GetLineEndOffset(obj) >> 4;
    FIELD_RAIL_WORK_GetPos(obj, &P);
    Q.x = P.x;
    Q.y = P.y;
    Q.z = P.z;
    k = FIELD_RAIL_GetUnitScaleRaw(p);
    for (i = 1; i < n; i++) {
        out->f6 = i;
        FIELD_RAIL_WORK_SetLocation(obj, out);
        FIELD_RAIL_WORK_GetPos(obj, &P);
        lim = FIELD_RAIL_WORK_GetWidthLimit(obj);
        VEC_Subtract(&Q, &P, &D);
        VEC_Subtract(pos, &P, &E);
        VEC_Normalize(&D, &F);
        len = VEC_Mag(&D);
        VEC_Normalize(&D, &G);
        VEC_Normalize(&E, &H);
        VEC_CrossProduct(&G, &H, &C);
        D = F;
        m = VEC_Mag(&E);
        VEC_Normalize(&E, &E);
        t = func_0207C768(m, len);
        E.x = FX_Mul(E.x, t);
        E.y = FX_Mul(E.y, t);
        E.z = FX_Mul(E.z, t);
        d = VEC_DotProduct(&D, &E);
        if (d <= 0x1000 && d >= 0) {
            u = FX_Mul(d, len);
            A.x = FX_Mul(F.x, u);
            A.y = FX_Mul(F.y, u);
            A.z = FX_Mul(F.z, u);
            VEC_Add(&P, &A, &A);
            x = pos->x;
            z = pos->z;
            R.x = x;
            R.z = z;
            R.y = 0;
            S.x = A.x;
            S.y = 0;
            S.z = A.z;
            dist = func_0207C768(VEC_Distance(&R, &S), k) >> 12;
            lim += 0x10;
            if (lim >= dist) {
                if (C.y >= 0) {
                    out->f4 = FIELD_RAIL_RoundToGrid(dist);
                } else {
                    out->f4 = -FIELD_RAIL_RoundToGrid(dist);
                }
                FIELD_RAIL_ClampLocation(p, out, &buf);
                FIELD_RAIL_GetLocationPos(p, out, arg);
                if (GF_STANDARD_CompareBytes((const u8 *)out, (const u8 *)(&buf), 8) == 0) {
                    return 1;
                }
                return 0;
            }
        }
        Q.x = P.x;
        Q.y = P.y;
        Q.z = P.z;
    }
    return 0;
}
