/*
 * function: G3X_SetFog
 * address:  0x0207DC44
 * packet:   pkt_0207DC44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3X_SetFog (libgx.TWL.HYB.a g3x.o)
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef short fx16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;
typedef long s32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef union {
    struct {
        fx32 _00, _01, _02, _03;
        fx32 _10, _11, _12, _13;
        fx32 _20, _21, _22, _23;
        fx32 _30, _31, _32, _33;
    };
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

#define reg_G3X_GXFIFO          (*(vu32 *)0x04000400)
#define reg_G3X_GXSTAT          (*(vu32 *)0x04000600)
#define reg_G3X_CLEAR_COLOR     (*(vu32 *)0x04000350)
#define reg_G3X_CLEAR_DEPTH     (*(vu16 *)0x04000354)
#define reg_G3X_DISP_1DOT_DEPTH (*(vu16 *)0x04000610)
#define REG_CLIPMTX_RESULT_0_ADDR 0x04000640
#define REG_VECMTX_RESULT_0_ADDR  0x04000680

#define reg_G3X_DISP3DCNT       (*(vu16 *)0x04000060)
#define reg_G3X_FOG_OFFSET      (*(vu16 *)0x0400035C)
#define reg_G3_POLYGON_ATTR     (*(vu32 *)0x040004A4)
#define reg_G3_TEXIMAGE_PARAM   (*(vu32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE     (*(vu32 *)0x040004AC)

typedef enum { GX_FOGBLEND_COLOR_ALPHA = 0 } GXFogBlend;
typedef enum { GX_FOGSLOPE_0x0400 = 0 } GXFogSlope;

void G3X_SetFog(BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset)
{
    if (enable) {
        reg_G3X_FOG_OFFSET = (u16)fogOffset;
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~0x3f40) | ((fogSlope << 8) | (fogMode << 6) | 0x80));
    } else {
        reg_G3X_DISP3DCNT &= 0xcf7f;
    }
}
