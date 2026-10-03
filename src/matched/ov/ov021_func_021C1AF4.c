/*
 * function: func_021C1AF4
 * address:  0x021C1AF4
 * packet:   pkt_ov021_021C1AF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     stack slots (high to low) pos1, tgt1, pos2, tgt2, up2, up1. The caller's block
 *           locals take the top slots in textual order; each up vector is an inline helper's
 *           local, and the first call reaching the helper one inline level deeper (through
 *           mk_persp) is what puts up1 below up2. Both calls through mk directly: up1/up2
 *           swapped (2 bytes out). The zero targets need a brace initialiser in a declaration.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02048A24  0x02048A24  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 *   d_021DA6E8     0x021DA6E8  data  a4
 *   d_021DA6D0     0x021DA6D0  data  a4
 *   d_021DA6F4     0x021DA6F4  data  a4
 *   d_021DA6DC     0x021DA6DC  data  a4
 *   d_020A1EB8     0x020A1EB8  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef int fx32;
typedef struct { fx32 x, y, z; } VecFx32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02047CFC(int a, int b, int heap);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u8 d_021DE3D8;
extern const VecFx32 d_021DA6E8;
extern const VecFx32 d_021DA6D0;
extern const VecFx32 d_021DA6F4;
extern const VecFx32 d_021DA6DC;
extern const s16 d_020A1EB8[];

static inline void *mk(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *tgt, int heap)
{
    VecFx32 up = *upsrc;
    return func_02048A24(a, s, c, d, e, f, g, h, pos, &up, tgt, heap);
}

static inline void *mk_persp(VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *tgt, int heap)
{
    return mk(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, pos, upsrc, tgt, heap);
}

u32 *func_021C1AF4(u32 a, u32 b)
{
    u32 *r;

    r = func_02030734(a, 0x138, 1, (const char *)&d_021DE3D8, 0x158);
    r[5] = (u32)func_02047CFC(8, 2, a);
    *(u16 *)((u8 *)r + 0x10) = a;
    r[0] = b;
    r[6] = -1;
    {
        VecFx32 p1 = d_021DA6E8;
        VecFx32 t1 = {0, 0, 0};
        r[1] = (u32)mk_persp(&p1, &d_021DA6D0, &t1, a);
    }
    {
        VecFx32 p2 = d_021DA6F4;
        VecFx32 t2 = {0, 0, 0};
        r[2] = (u32)mk(2, 0x30000, -0x30000, -0x40000, 0x40000, 0x1000, 0x400000, 0, &p2, &d_021DA6DC, &t2, a);
    }
    r[3] = 0;
    return r;
}
