/*
 * function: FIELD_RAIL_CAMERA_BlendEyeTarget
 * address:  0x021BA550
 * packet:   pkt_ov021_021BA550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetEndPoint  0x021B834C  thumb  ov021
 *   FIELD_RAIL_WORK_GetPointCamera  0x021B836C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
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
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
u8 *FIELD_RAIL_WORK_GetStartPoint(u8 *p);
u8 *FIELD_RAIL_WORK_GetEndPoint(u8 *p);
int *FIELD_RAIL_WORK_GetPointCamera(u32 q, u32 k);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
void FIELD_CAMERA_StopTargetTrace(u8 *p);
u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
u32 FIELD_RAIL_WORK_GetLineOffset(u8 *p);
void FIELD_CAMERA_SetEyeRaw(u32 o, V *v);
void FIELD_CAMERA_SetTarget(u32 o, V *v);
u32 func_0207C768(u32 a, u32 b);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void FIELD_RAIL_CAMERA_BlendEyeTarget(u32 p)
{
    V m;
    V n;
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int d;
    int t;

    q = FIELD_RAIL_GetFocusWork((u8 *)p);
    h = FIELD_RAIL_GetFieldCamera((u8 *)p);
    a = (u32)FIELD_RAIL_WORK_GetStartPoint((u8 *)q);
    b = (u32)FIELD_RAIL_WORK_GetEndPoint((u8 *)q);
    k0 = FIELD_RAIL_WORK_GetPointCamera(q, a);
    k1 = FIELD_RAIL_WORK_GetPointCamera(q, b);
    FIELD_CAMERA_EnterMode((u8 *)h, 2);
    FIELD_CAMERA_StopTargetTrace((u8 *)FIELD_RAIL_GetFieldCamera((u8 *)p));
    d = FIELD_RAIL_WORK_GetLineEndOffset((u8 *)q);
    t = FIELD_RAIL_WORK_GetLineOffset((u8 *)q);
    m.x = func_0207C768(FX_MUL(k1[1] - k0[1], t << 12), d << 12);
    m.y = func_0207C768(FX_MUL(k1[2] - k0[2], t << 12), d << 12);
    m.z = func_0207C768(FX_MUL(k1[3] - k0[3], t << 12), d << 12);
    n.x = func_0207C768(FX_MUL(k1[4] - k0[4], t << 12), d << 12);
    n.y = func_0207C768(FX_MUL(k1[5] - k0[5], t << 12), d << 12);
    n.z = func_0207C768(FX_MUL(k1[6] - k0[6], t << 12), d << 12);
    m.x += k0[1];
    m.y += k0[2];
    m.z += k0[3];
    n.x += k0[4];
    n.y += k0[5];
    n.z += k0[6];
    FIELD_CAMERA_SetEyeRaw(h, &m);
    FIELD_CAMERA_SetTarget(h, &n);
}
