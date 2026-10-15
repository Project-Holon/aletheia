/*
 * function: VIEWER_ACTOR_CreateModel
 * address:  0x021C7744
 * packet:   pkt_ov111_021C7744
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_UTIL_AddUnit  0x02047E88  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   d_021C8834  0x021C8834  data
 *   d_021C8950  0x021C8950  data
 *   d_021C8938  0x021C8938  data
 *   d_021C8944  0x021C8944  data
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
    u8 pad120[0x13C - 0x120];
    int f13C;
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
typedef int fx32;
typedef struct { fx32 x, y, z; } VecFx32;

extern void *G3D_UTIL_Create(int a, int b, int heap);
extern u16 G3D_UTIL_AddUnit(void *p, const void *q);
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void *G3D_CAMERA_Create(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern const unsigned char d_021C8834[];
extern const VecFx32 d_021C8950;
extern const VecFx32 d_021C8938;
extern const VecFx32 d_021C8944;
extern const s16 FX_SinCosTable_[];

void VIEWER_ACTOR_CreateModel(Work *p)
{
    void *mdl;
    int i;
    int n;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    p->fF8 = G3D_UTIL_Create(10, 10, 0x27);
    p->fFC = G3D_UTIL_AddUnit(p->fF8, d_021C8834);
    mdl = (void *)func_02048A18(p->fF8, p->fFC);
    n = G3D_SYSTEM_GetObjectAnimeCount(mdl);
    for (i = 0; i < n; i++) {
        G3D_SYSTEM_EnableObjectAnime(mdl, (u16)i);
    }
    a = d_021C8950;
    b = d_021C8938;
    c = d_021C8944;
    p->f104 = G3D_CAMERA_Create(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &a, &c, &b, 0x27);
}
