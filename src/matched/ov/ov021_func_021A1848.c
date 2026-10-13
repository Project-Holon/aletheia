/*
 * function: FIELD_3DBG_DrawQuad
 * address:  0x021A1848
 * packet:   pkt_ov021_021A1848
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws one textured quad through the geometry engine registers
 * (MTX_MODE 0x04000440 .. END_VTXS 0x04000504); func_0207D934 is the
 * 3x3 matrix multiply (command 0x1A). The parameter must be const: without
 * it every a[] load is repeated after each volatile register store (340 B).
 *
 * symbols:
 *   func_0207D934  0x0207D934  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef s16 fx16;
typedef s32 fx32;

#define REG_MTX_MODE     (*(volatile u32 *)0x04000440)
#define REG_MTX_IDENTITY (*(volatile u32 *)0x04000454)
#define REG_MTX_SCALE    (*(volatile u32 *)0x0400046C)
#define REG_TEXCOORD     (*(volatile u32 *)0x04000488)
#define REG_VTX_16       (*(volatile u32 *)0x0400048C)
#define REG_BEGIN_VTXS   (*(volatile u32 *)0x04000500)
#define REG_END_VTXS     (*(volatile u32 *)0x04000504)

extern void func_0207D934(const void *m);

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

void FIELD_3DBG_DrawQuad(const fx32 *a)
{
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    func_0207D934(a + 8);
    REG_MTX_MODE = 2;
    REG_MTX_SCALE = a[3];
    REG_MTX_SCALE = a[3];
    REG_MTX_SCALE = a[3];
    REG_BEGIN_VTXS = 1;
    G3_TexCoord(a[4], a[6]);
    G3_Vtx(-a[0], a[1], -a[2]);
    G3_TexCoord(a[4], a[7]);
    G3_Vtx(-a[0], -a[1], -a[2]);
    G3_TexCoord(a[5], a[7]);
    G3_Vtx(a[0], -a[1], -a[2]);
    G3_TexCoord(a[5], a[6]);
    G3_Vtx(a[0], a[1], -a[2]);
    REG_END_VTXS = 0;
}
