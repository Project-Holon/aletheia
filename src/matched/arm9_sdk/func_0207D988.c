/*
 * function: func_0207D988
 * address:  0x0207D988
 * packet:   pkt_0207D988
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3X_Init (libgx.TWL.HYB.a g3x.o)
 *
 * symbols:
 *   G3X_ClearFifo      0x0207DAF8  arm
 *   G3X_InitMtxStack   0x0207DB1C  arm
 *   G3X_InitTable      0x0207DD4C  arm
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

#define reg_G3_MTX_MODE         (*(vu32 *)0x04000440)
#define reg_G3_MTX_POP          (*(vu32 *)0x04000448)
#define reg_G3_MTX_IDENTITY     (*(vu32 *)0x04000454)

#define reg_G3_END_VTXS         (*(vu32 *)0x04000504)
#define reg_G2_BG0OFS           (*(vu32 *)0x04000010)
#define reg_G2_BG0CNT           (*(vu16 *)0x04000008)
#define reg_G3X_CLRIMAGE_OFFSET (*(vu16 *)0x04000356)
#define reg_G3X_FOG_COLOR       (*(vu32 *)0x04000358)

extern void G3X_ClearFifo(void);
extern void G3X_InitMtxStack(void);
extern void G3X_InitTable(void);

static inline void G3X_SetShading(int shading)
{
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(0x3000 | 0x0002)) | (shading << 1));
}

static inline void G2_SetBG0Priority(int priority)
{
    reg_G2_BG0CNT = (u16)((reg_G2_BG0CNT & ~0x3) | (priority << 0));
}

void func_0207D988(void)
{
    G3X_ClearFifo();
    reg_G3_END_VTXS = 0;
    while (reg_G3X_GXSTAT & 0x08000000) {
    }
    reg_G3X_DISP3DCNT = 0;
    reg_G3X_GXSTAT = 0;
    reg_G2_BG0OFS = 0;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    G3X_SetShading(0);
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~0x3000) | 0x0010);
    reg_G3X_DISP3DCNT &= 0xcffb;
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
    G3X_InitMtxStack();
    reg_G3X_CLEAR_COLOR = 0;
    reg_G3X_CLEAR_DEPTH = 0x7fff;
    reg_G3X_CLRIMAGE_OFFSET = 0;
    reg_G3X_FOG_COLOR = 0;
    reg_G3X_FOG_OFFSET = 0;
    G2_SetBG0Priority(0);
    G3X_InitTable();
    reg_G3_POLYGON_ATTR = 0x001f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_TEXPLTT_BASE = 0;
}
