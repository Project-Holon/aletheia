/*
 * function: FIELD_RAIL_CAMERA_BlendAnglesShift
 * address:  0x021BACA8
 * packet:   pkt_ov021_021BACA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Keyframe lerp between two FIELD_RAIL_WORK_GetPointCamera records: two wrapped 16-bit
 * angles (+4, +8), a scalar (+0xC) and a vector (+0x10..+0x18).  The
 * angle and scalar locals are int with explicit (u16) casts: as u16
 * locals the x0 load sinks below the k1 loads and every spill slot moves.
 * k1 is declared before k0 to put k0 in r5.
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetEndPoint  0x021B834C  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_RAIL_WORK_GetPointCamera  0x021B836C  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
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
u8 *FIELD_RAIL_WORK_GetStartPoint(u8 *p);
u8 *FIELD_RAIL_WORK_GetEndPoint(u8 *p);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
int FIELD_CAMERA_ResumeTargetTrace(u32 a);
int *FIELD_RAIL_WORK_GetPointCamera(u32 q, u32 k);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetLineOffset(u8 *p);
void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
u32 func_0207C768(u32 a, u32 b);
void FIELD_CAMERA_SetTargetShift(u32 o, V *v);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void FIELD_RAIL_CAMERA_BlendAnglesShift(u32 p)
{
    V v;
    int *k1;
    int *k0;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int s;
    int d;
    int t;
    int x0;
    int y0;
    int z0;
    int y1;
    int z1;
    int dx;
    int dy;
    u16 x;
    u16 y;

    q = FIELD_RAIL_GetFocusWork((u8 *)p);
    a = (u32)FIELD_RAIL_WORK_GetStartPoint((u8 *)q);
    b = (u32)FIELD_RAIL_WORK_GetEndPoint((u8 *)q);
    h = FIELD_RAIL_GetFieldCamera((u8 *)p);
    FIELD_CAMERA_EnterMode((u8 *)h, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera((u8 *)p));
    k0 = FIELD_RAIL_WORK_GetPointCamera(q, a);
    k1 = FIELD_RAIL_WORK_GetPointCamera(q, b);
    d = FIELD_RAIL_WORK_GetLineEndOffset((u8 *)q);
    t = FIELD_RAIL_WORK_GetLineOffset((u8 *)q);
    s = func_0207C768(t << 12, d << 12);
    x0 = (u16)k0[1];
    y0 = (u16)k0[2];
    z0 = k0[3];
    y1 = (u16)k1[2];
    z1 = k1[3];
    dx = (u16)k1[1] - x0;
    if (dx >= 0x8000)
        dx -= 0x10000;
    else if (dx <= -0x8000)
        dx += 0x10000;
    x = x0 + (FX_MUL(dx << 12, s) >> 12);
    dy = y1 - y0;
    if (dy >= 0x8000)
        dy -= 0x10000;
    else if (dy <= -0x8000)
        dy += 0x10000;
    y = y0 + (FX_MUL(dy << 12, s) >> 12);
    FIELD_CAMERA_SetYaw((u8 *)h, y);
    FIELD_CAMERA_SetPitch((u8 *)h, x);
    FIELD_CAMERA_SetDistance((u8 *)h, z0 + FX_MUL(z1 - z0, s));
    v.x = k0[4] + FX_MUL(k1[4] - k0[4], s);
    v.y = k0[5] + FX_MUL(k1[5] - k0[5], s);
    v.z = k0[6] + FX_MUL(k1[6] - k0[6], s);
    FIELD_CAMERA_SetTargetShift(h, &v);
}
