/*
 * function: FIELD_RAIL_LINEFUNC_Straight
 * address:  0x021B9E84
 * packet:   pkt_ov021_021B9E84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds the 8-byte record for id `a` at pos between the two entries of
 * FIELD_RAIL_GetLine's link: horizontal distance and height offset scaled by
 * FIELD_RAIL_GetUnitScaleRaw and rounded by FIELD_RAIL_RoundToGrid; returns 0 when out of range,
 * else 1 when the record round-trips unchanged through FIELD_RAIL_ClampLocation and
 * FIELD_RAIL_GetLocationPos.
 * pos->x and pos->z go through locals: stored straight into m, the y = 0
 * stores interleave with them and the loads split; the out-of-range
 * `return 0` is the fall-out of an if around the rest (it sits after the
 * final epilogue). The spill slots follow h0, h1, L, dist, diff declared
 * in that order.
 *
 * symbols:
 *   FIELD_RAIL_GetPoint  0x021B8224  thumb  ov021
 *   FIELD_RAIL_GetLine  0x021B8230  thumb  ov021
 *   FIELD_RAIL_GetLinePos  0x021B823C  thumb  ov021
 *   FIELD_RAIL_GetUnitScaleRaw  0x021B8248  thumb  ov021
 *   FIELD_RAIL_ClampLocation  0x021B8250  thumb  ov021
 *   FIELD_RAIL_RoundToGrid  0x021B8378  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FIELD_RAIL_ProjectOnSegment  0x021BAE7C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   _u32_div_f     0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

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
void FIELD_RAIL_GetLinePos(u8 *p, int k);
u32 FIELD_RAIL_GetUnitScaleRaw(u8 *p);
void FIELD_RAIL_ClampLocation(void *p, Rec *r, Rec *o);
int FIELD_RAIL_RoundToGrid(int x);
int FIELD_RAIL_GetLocationPos(void *p, Rec *r, int c);
int FIELD_RAIL_ProjectOnSegment(int *e0, int *e1, const V *pos, V *a, int *b, V *c);
typedef signed int     s32;
u32 func_0207C768(u32 a, u32 b);
int VEC_Distance(const V *a, const V *b);
s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

int FIELD_RAIL_LINEFUNC_Straight(int a, void *p, const V *pos, Rec *out, int arg)
{
    V A;
    V C;
    V m;
    V n;
    int B;
    Rec buf;
    int *info;
    int k;
    int *e0;
    int *e1;
    int h0;
    int h1;
    u32 L;
    u32 dist;
    int diff;
    int i;
    int x;
    int z;

    info = FIELD_RAIL_GetLine(p, a);
    e0 = FIELD_RAIL_GetPoint(p, info[0]);
    e1 = FIELD_RAIL_GetPoint(p, info[1]);
    k = FIELD_RAIL_GetUnitScaleRaw(p);
    if (FIELD_RAIL_ProjectOnSegment(e0, e1, pos, &A, &B, &C) == 0) {
        return 0;
    }
    x = pos->x;
    z = pos->z;
    m.x = x;
    n.x = A.x;
    m.z = z;
    n.z = A.z;
    m.y = 0;
    n.y = 0;
    dist = (int)func_0207C768((int)VEC_Distance(&m, &n), (int)k) >> 12;
    FIELD_RAIL_GetLinePos(p, info[3]);
    L = info[5] << 4;
    diff = L - ((int)func_0207C768((int)B, (int)k) >> 12);
    for (i = 0; i < 4; i++) {
        if (a == e0[i]) {
            h0 = e0[i + 8];
        }
        if (a == e1[i]) {
            h1 = e1[i + 8];
        }
    }
    if (dist <= h0 + (h1 - h0) * diff / L + 0x10) {
        out->id = a;
        out->f2 = 1;
        out->f3 = 3;
        if (C.y >= 0) {
            out->f4 = FIELD_RAIL_RoundToGrid(dist);
        } else {
            out->f4 = -FIELD_RAIL_RoundToGrid(dist);
        }
        out->f6 = FIELD_RAIL_RoundToGrid(diff);
        FIELD_RAIL_ClampLocation(p, out, &buf);
        FIELD_RAIL_GetLocationPos(p, &buf, arg);
        if (GF_STANDARD_CompareBytes((const u8 *)out, (const u8 *)(&buf), 8) == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}
