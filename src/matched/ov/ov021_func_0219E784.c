/*
 * function: FLDMMDL_RAIL_GetDrawOffsetByDir
 * address:  0x0219E784
 * packet:   pkt_ov021_0219E784
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_GetStepVector  0x021B8050  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineKey  0x021B80D8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_0207B51C  0x0207B51C  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   d_021D84D4     0x021D84D4  data  ov021  a1
 *   d_021D841C     0x021D841C  data  ov021  a2
 *   FX_SinCosTable_     0x020A1B38  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef signed long long s64;
typedef struct { s32 x, y, z; } V;

static inline void setv(V *p, s32 x, s32 y, s32 z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}

static inline void setw(s16 *p, s32 x, s32 y, s32 z)
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
}

extern u8  d_021D84D4[][4];
extern u16 d_021D841C[];
extern s16 FX_SinCosTable_[];

struct Sub;
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FIELD_RAIL_WORK_GetStepVector(struct Sub *o, s16 *out);
extern u32 FIELD_RAIL_WORK_GetLineKey(u8 *p);
extern void func_0207AF1C();
extern void func_0207B51C();
extern void VEC_Normalize();

void FLDMMDL_RAIL_GetDrawOffsetByDir(u32 o, u32 idx, s16 *v)
{
    u32 t;
    u32 n;
    s32 k;
    s32 c;
    s32 m[9];
    V vec;

    t = (u32)FLDMMDL_RAIL_GetRailWork((void *)o);
    FIELD_RAIL_WORK_GetStepVector((struct Sub *)t, v);
    n = FIELD_RAIL_WORK_GetLineKey((u8 *)t);
    k = (d_021D841C[d_021D84D4[n][idx]] >> 4) * 2;
    c = FX_SinCosTable_[k + 1];
    v[1] = (s16)(((s64)c * v[1] + 0x800) >> 12);
    setv(&vec, v[0], v[1], v[2]);
    func_0207AF1C(m, FX_SinCosTable_[k], c);
    func_0207B51C(&vec, m, &vec);
    VEC_Normalize(&vec, &vec);
    setw(v, vec.x, vec.y, vec.z);
}
