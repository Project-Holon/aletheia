/*
 * function: func_021C76A4
 * address:  0x021C76A4
 * packet:   pkt_ov111_021C76A4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   G3D_LIGHT_CreateSlots  0x02048BC4  arm
 *   G3D_LIGHT_ApplySlots  0x02048C58  arm
 *   G3D_SYSTEM_SetProjection  0x02046858  arm
 *   func_02040588  0x02040588  arm
 *   d_021C8810  0x021C8810  data
 *   d_021C896C  0x021C896C  data
 *   FX_SinCosTable_  0x020A1B38  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef short s16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
} Camera;

struct LightSlot;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
struct LightSet;
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void func_02040588(unsigned char which, unsigned char enable);
extern const void *const d_021C8810;
extern const Camera d_021C896C;
extern const s16 FX_SinCosTable_[];

void func_021C76A4(Work *p)
{
    Camera cam;
    void *light;

    G3D_SYSTEM_Init(0, 1, 0, 1, 0x1000, 0x27, 0);
    light = G3D_LIGHT_CreateSlots((const struct LightSet *)(&d_021C8810), 0x27);
    p->f100 = light;
    G3D_LIGHT_ApplySlots(light);
    cam = d_021C896C;
    cam.f4 = FX_SinCosTable_[0x16C];
    cam.f8 = FX_SinCosTable_[0x16D];
    G3D_SYSTEM_SetProjection((const u32 *)(&cam));
    func_02040588(0, 1);
    *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~(0x2000 | 0x1000)) | 0x8);
}
