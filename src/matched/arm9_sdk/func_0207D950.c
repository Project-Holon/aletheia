/*
 * function: func_0207D950
 * address:  0x0207D950
 * packet:   pkt_0207D950
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3_MultTransMtx33 (libgx.TWL.HYB.a g3imm.o)
 *
 * symbols:
 *   MI_Copy36B   0x02082B60  arm
 */

typedef long fx32;
typedef unsigned long u32;
typedef int BOOL;
typedef volatile u32 vu32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

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
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)
#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)
#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)

extern void MI_Copy36B(const void *pSrc, void *pDest);

void func_0207D950(const MtxFx33 *mtx, const VecFx32 *trans)
{
    reg_G3X_GXFIFO = 0x19;
    MI_Copy36B(mtx, (void *)&reg_G3X_GXFIFO);
    reg_G3X_GXFIFO = (u32)trans->x;
    reg_G3X_GXFIFO = (u32)trans->y;
    reg_G3X_GXFIFO = (u32)trans->z;
}
