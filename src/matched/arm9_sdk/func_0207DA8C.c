/*
 * function: func_0207DA8C
 * address:  0x0207DA8C
 * packet:   pkt_0207DA8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3X_Reset (libgx.TWL.HYB.a g3x.o)
 *
 * symbols:
 *   G3X_ResetMtxStack   0x0207DBB4  arm
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

extern void G3X_ResetMtxStack(void);

void func_0207DA8C(void)
{
    while (reg_G3X_GXSTAT & 0x08000000) {
    }
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    G3X_ResetMtxStack();
    reg_G3_POLYGON_ATTR = 0x001f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_TEXPLTT_BASE = 0;
}
