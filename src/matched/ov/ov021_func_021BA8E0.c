/*
 * function: FIELD_RAIL_CAMERA_OrbitMovingPoint
 * address:  0x021BA8E0
 * packet:   pkt_ov021_021BA8E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetMode  0x021B82F0  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_CAMERA_SetOrbit  0x021BA7E0  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u16 FIELD_RAIL_WORK_GetMode(u8 *p);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetLineOffset(u8 *p);
int *FIELD_RAIL_WORK_GetCamera(u32 q);
u32 func_0207C768(u32 a, u32 b);
void FIELD_RAIL_CAMERA_SetOrbit(u32 p, u16 ang, int r, V *pos);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void FIELD_RAIL_CAMERA_OrbitMovingPoint(u32 p)
{
    V v;
    int *k;
    u32 q;
    int d;
    int t;
    u16 x;
    int y;

    q = FIELD_RAIL_GetFocusWork((u8 *)p);
    FIELD_RAIL_WORK_GetMode((u8 *)q);
    d = FIELD_RAIL_WORK_GetLineEndOffset((u8 *)q);
    t = FIELD_RAIL_WORK_GetLineOffset((u8 *)q);
    k = FIELD_RAIL_WORK_GetCamera(q);
    x = k[1];
    y = k[2];
    v.x = k[3] + func_0207C768(FX_MUL(k[6] - k[3], t << 12), d << 12);
    v.y = k[4] + func_0207C768(FX_MUL(k[7] - k[4], t << 12), d << 12);
    v.z = k[5] + func_0207C768(FX_MUL(k[8] - k[5], t << 12), d << 12);
    FIELD_RAIL_CAMERA_SetOrbit(p, x, y, &v);
}
