/*
 * function: FIELD_SAVEANIME_CreateWindow
 * address:  0x021D1264
 * packet:   pkt_ov021_021D1264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   d_021DB984     0x021DB984  data  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FIELD_SAVEANIME_DrawFrame  0x021D1430  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01509.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct CharBuf;
struct Light;
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_CAMERA_GetUp(u32 l, V *out);
extern void G3D_CAMERA_GetEye(u32 l, V *out);
extern void func_0207CA00(const V *a, const V *b, V *c);
extern void VEC_Normalize(const V *a, V *b);
extern void func_0207CAE8(const V *a, const V *b, V *c);
extern const V d_021DB984;
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void func_0206DF3C(V *a, int *x, int *y);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void FIELD_SAVEANIME_DrawFrame(u8 *p, u32 n);

void FIELD_SAVEANIME_CreateWindow(u8 *p)
{
    V pos;
    V d;
    V f;
    V s;
    V u;
    V at;
    V eye;
    int x;
    int y;
    void *o;
    u32 cam;

    o = FIELDMAP_GetFieldPlayer(((struct Obj01509 *)p)->f0);
    cam = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera((void *)(*(u32 *)&((struct Obj01509 *)p)->f0)));
    G3D_CAMERA_Reset((struct Light *)cam);
    G3D_CAMERA_GetUp(cam, &eye);
    G3D_CAMERA_GetEye(cam, &at);
    func_0207CA00(&eye, &at, &d);
    f = d;
    f.y = 0;
    VEC_Normalize(&f, &f);
    func_0207CAE8(&f, &d_021DB984, &s);
    func_0207CAE8(&d, &s, &u);
    VEC_Normalize(&u, &u);
    FIELD_PLAYER_GetPos(o, (struct VecFx32 *)&pos);
    pos.x += (int)(((long long)u.x * -0x1C000 + 0x800) >> 12);
    pos.y += (int)(((long long)u.y * -0x1C000 + 0x800) >> 12);
    pos.z += (int)(((long long)u.z * -0x1C000 + 0x800) >> 12);
    func_0206DF3C(&pos, &x, &y);
    x -= 0x10;
    y -= 0x18;
    ((struct Obj01509 *)p)->f8 = x % 8;
    ((struct Obj01509 *)p)->fA = y % 8;
    x /= 8;
    y /= 8;
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x > 0x1F) {
        x = 0x1F;
    }
    if (y > 0x18) {
        y = 0x18;
    }
    ((struct Obj01509 *)p)->f4 = BMP_WIN_Create(3, (u8)x, (u8)y, 5, (u32)5, (u32)9, (u32)1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01509 *)p)->f4)), 0);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01509 *)p)->f4);
    FIELD_SAVEANIME_DrawFrame(p, 0);
}
