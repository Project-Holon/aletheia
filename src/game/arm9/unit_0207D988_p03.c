/*
 * file:     unit_0207D988_p03.c
 * unit:     yes
 * function: func_0207DE30, func_0207DE5C
 * address:  0x0207DE30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

int func_0207DE30(s32 *level);
int func_0207DE5C(s32 *level);


#define reg_G3X_GXFIFO          (*(vu32 *)0x04000400)

#define reg_G3X_GXSTAT          (*(vu32 *)0x04000600)

#define reg_G3X_CLEAR_COLOR     (*(vu32 *)0x04000350)

#define reg_G3X_CLEAR_DEPTH     (*(vu16 *)0x04000354)

#define reg_G3X_DISP_1DOT_DEPTH (*(vu16 *)0x04000610)

#define REG_CLIPMTX_RESULT_0_ADDR 0x04000640

#define REG_VECMTX_RESULT_0_ADDR  0x04000680


/*
 * sdk:      G3X_GetMtxStackLevelPV (libgx.TWL.HYB.a g3x.o)
 */
int func_0207DE30(s32 *level)
{
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    } else {
        *level = (s32)((reg_G3X_GXSTAT & 0x1f00) >> 8);
        return 0;
    }
}


#define reg_G3X_GXFIFO          (*(vu32 *)0x04000400)

#define reg_G3X_GXSTAT          (*(vu32 *)0x04000600)

#define reg_G3X_CLEAR_COLOR     (*(vu32 *)0x04000350)

#define reg_G3X_CLEAR_DEPTH     (*(vu16 *)0x04000354)

#define reg_G3X_DISP_1DOT_DEPTH (*(vu16 *)0x04000610)

#define REG_CLIPMTX_RESULT_0_ADDR 0x04000640

#define REG_VECMTX_RESULT_0_ADDR  0x04000680


/*
 * sdk:      G3X_GetMtxStackLevelPJ (libgx.TWL.HYB.a g3x.o)
 */
int func_0207DE5C(s32 *level)
{
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    } else {
        *level = (s32)((reg_G3X_GXSTAT & 0x2000) >> 13);
        return 0;
    }
}
