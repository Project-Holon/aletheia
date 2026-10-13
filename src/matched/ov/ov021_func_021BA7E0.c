/*
 * function: FIELD_RAIL_CAMERA_SetOrbit
 * address:  0x021BA7E0
 * packet:   pkt_ov021_021BA7E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   d_020A1B38     0x020A1B38  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef long long      s64;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
void FIELD_CAMERA_StopTargetTrace(u8 *p);
void FIELD_RAIL_GetFocusPos(void **o, void *out);
void func_0207CA00(const V *a, const V *b, V *c);
void VEC_Normalize(const V *a, V *b);
void FIELD_CAMERA_SetTarget(u32 a, V *v);
void FIELD_CAMERA_SetEyeRaw(u32 a, V *v);
extern s16 d_020A1B38[];

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void FIELD_RAIL_CAMERA_SetOrbit(u32 p, u16 ang, int r, V *pos)
{
    V d;
    V c;
    V n;
    V out;
    u32 h;
    int save;
    int i;
    int cr;

    h = FIELD_RAIL_GetFieldCamera((u8 *)p);
    FIELD_CAMERA_EnterMode((u8 *)h, 2);
    FIELD_CAMERA_StopTargetTrace((u8 *)h);
    c = *pos;
    save = c.y;
    c.y = 0;
    FIELD_RAIL_GetFocusPos((void **)p, &d);
    d.y = 0;
    func_0207CA00(&d, &c, &d);
    VEC_Normalize(&d, &n);
    i = (ang >> 4) * 2;
    out.y = FX_MUL(d_020A1B38[i], r);
    cr = FX_MUL(d_020A1B38[i + 1], r);
    out.x = FX_MUL(n.x, cr);
    out.z = FX_MUL(n.z, cr);
    out.x += c.x;
    out.y += save;
    out.z += c.z;
    FIELD_CAMERA_SetTarget(h, pos);
    FIELD_CAMERA_SetEyeRaw(h, &out);
}
