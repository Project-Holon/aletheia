/*
 * function: FIELD_RAIL_CAMERA_BlendOrbit
 * address:  0x021BA6E8
 * packet:   pkt_ov021_021BA6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_WORK_GetMode  0x021B82F0  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetEndPoint  0x021B834C  thumb  ov021
 *   FIELD_RAIL_WORK_GetPointCamera  0x021B836C  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_CAMERA_SetOrbit  0x021BA7E0  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
u16 FIELD_RAIL_WORK_GetMode(u8 *p);
u8 *FIELD_RAIL_WORK_GetStartPoint(u8 *p);
u8 *FIELD_RAIL_WORK_GetEndPoint(u8 *p);
int *FIELD_RAIL_WORK_GetPointCamera(u32 q, u32 k);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetLineOffset(u8 *p);
int *FIELD_RAIL_WORK_GetCamera(u32 q);
u32 func_0207C768(u32 a, u32 b);
void FIELD_RAIL_CAMERA_SetOrbit(u32 p, u16 ang, int r, V *pos);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void FIELD_RAIL_CAMERA_BlendOrbit(u32 p)
{
    V v;
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    int d;
    int t;
    u16 x;
    int x0;
    int y;

    q = FIELD_RAIL_GetFocusWork((u8 *)p);
    FIELD_RAIL_GetFieldCamera((u8 *)p);
    if (FIELD_RAIL_WORK_GetMode((u8 *)q) == 1) {
        a = (u32)FIELD_RAIL_WORK_GetStartPoint((u8 *)q);
        b = (u32)FIELD_RAIL_WORK_GetEndPoint((u8 *)q);
        k0 = FIELD_RAIL_WORK_GetPointCamera(q, a);
        k1 = FIELD_RAIL_WORK_GetPointCamera(q, b);
        d = FIELD_RAIL_WORK_GetLineEndOffset((u8 *)q);
        t = FIELD_RAIL_WORK_GetLineOffset((u8 *)q);
    } else {
        k0 = FIELD_RAIL_WORK_GetCamera(q);
        k1 = FIELD_RAIL_WORK_GetCamera(q);
        d = 1;
        t = 0;
    }
    x0 = k0[1];
    x = x0 + (k1[1] - x0) * t / d;
    y = k0[2] + func_0207C768(FX_MUL(k1[2] - k0[2], t << 12), d << 12);
    v.x = k0[3];
    v.y = k0[4];
    v.z = k0[5];
    FIELD_RAIL_CAMERA_SetOrbit(p, x, y, &v);
}
