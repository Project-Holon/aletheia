/*
 * function: STARTMENU_Demo3dInit
 * address:  0x021B9C2C
 * packet:   pkt_ov088_021B9C2C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: the four ortho bounds bound to locals before the G3D_CAMERA_Create
 * call (inline in the argument list they evaluate in another order); the
 * sin/cos pair read as FX_SinCosTable_[0x2AA]/[0x2AB] (pool word base +
 * 0x540); d_021BD3DC without its ov088 token (contested hint).
 * volatile: 0x04000060 (DISP3DCNT) read-modify-written by the G3X_AntiAlias,
 *           G3X_AlphaTest and G3X_AlphaBlend inlines at 0x021B9D80-0x021B9D9C
 *
 * symbols:
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_UTIL_AddUnit  0x02047E88  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   ICA_ANIME_CreateStream  0x02011510  thumb
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048C58  0x02048C58  arm
 *   BG_SYS_SetLowBit  0x0204044C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_021BD410     0x021BD410  data  ov088  a4
 *   d_021BD3EC     0x021BD3EC  data  ov088  a4
 *   d_021BD3F8     0x021BD3F8  data  ov088  a4
 *   d_021BD404     0x021BD404  data  ov088  a4
 *   d_021BD3DC     0x021BD3DC  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef long long      s64;
typedef int            fx32;
typedef int            BOOL;

#define reg_G3X_DISP3DCNT (*(volatile u16 *)0x04000060)
#define REG_G3X_DISP3DCNT_GO_MASK  0x00002000
#define REG_G3X_DISP3DCNT_RO_MASK  0x00001000
#define REG_G3X_DISP3DCNT_AAE_MASK 0x00000010
#define REG_G3X_DISP3DCNT_ABE_MASK 0x00000008
#define REG_G3X_DISP3DCNT_ATE_MASK 0x00000004

static inline void G3X_AntiAlias(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_AAE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_AAE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline void G3X_AlphaTest(BOOL enable, int ref)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ATE_MASK);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ATE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline void G3X_AlphaBlend(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ABE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ABE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    u32 f0;
    u16 f4;
    u16 pad6;
    u32 f8;
    u32 fC;
    void *f10;
} Work;

extern const s16 FX_SinCosTable_[];
extern const u32 d_021BD410[];
extern VecFx32 d_021BD3EC;
extern VecFx32 d_021BD3F8;
extern VecFx32 d_021BD404;
extern const u32 d_021BD3DC[];

extern u32   G3D_UTIL_Create(u32 a, u32 b, u32 heap);
extern u16   G3D_UTIL_AddUnit(u32 a, const void *b);
struct G3dSys;
struct LightSet;
struct LightSlot;
extern u32 func_020489F4(u8 *a0, int i);
extern u32   func_02048A18(u32 a, u16 b);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern fx32  FX_Div(fx32 numer, fx32 denom);
extern void *G3D_CAMERA_Create(int a, int s, int c, int d, int e, int f, int g, int h,
                           VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void BG_SYS_SetLowBit(u32 mode);

void STARTMENU_Demo3dInit(Work *p, u32 heap)
{
    int base;
    fx32 s;
    fx32 c;
    fx32 t;
    fx32 top;
    fx32 bottom;
    fx32 left;
    fx32 right;

    p->f0 = G3D_UTIL_Create(7, 3, heap);
    p->f4 = G3D_UTIL_AddUnit(p->f0, d_021BD410);
    base = func_020489F4((u8 *)p->f0, p->f4);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->f0, base), 0);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->f0, base), 1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->f0, base + 1), 0);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->f0, base + 2), 0);

    c = FX_SinCosTable_[0x2AB];
    s = FX_SinCosTable_[0x2AA];
    t = FX_Mul(s, 0x19A);
    top = FX_Div(t, c);
    bottom = -FX_Div(t, c);
    right = FX_Div(FX_Mul(FX_Div(0x223, 0x1000), s), c);
    left = -FX_Div(FX_Mul(FX_Div(0x223, 0x1000), s), c);
    p->f10 = G3D_CAMERA_Create(1, top, bottom, left, right,
                           0x19A, 0x800000, 0x19A,
                           &d_021BD3EC, &d_021BD3F8, &d_021BD404, heap);
    p->fC = (u32)ICA_ANIME_CreateStream(heap, 0xA0, 0xE9, 0xA);
    p->f8 = (u32)func_02048BC4((const struct LightSet *)d_021BD3DC, heap);
    func_02048C58((struct LightSlot *)p->f8);
    BG_SYS_SetLowBit(1);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
}
