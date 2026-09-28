/*
 * function: func_0207DD24
 * address:  0x0207DD24
 * packet:   pkt_0207DD24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3X_SetClearColor (libgx.TWL.HYB.a g3x.o)
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

void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, BOOL fog)
{
    u32 val = (u32)(rgb | (alpha << 16) | (polygonID << 24));

    if (fog) {
        val |= 0x8000;
    }
    reg_G3X_CLEAR_COLOR = val;
    reg_G3X_CLEAR_DEPTH = (u16)depth;
}
