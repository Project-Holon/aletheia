/*
 * file:     g3imm.c
 * unit:     yes
 * function: G3_LoadMtx44, G3_LoadMtx43, G3_MultMtx44, G3_MultMtx43, G3_MultMtx33, G3_MultTransMtx33
 * address:  0x0207D8C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GX_SendFifo64B   0x02080CA8  arm
 *   GX_SendFifo48B   0x02080C84  arm
 *   MI_Copy36B   0x02082B60  arm
 *   MI_Copy36B   0x02082B60  arm
 */
#include "../types.h"

#include "../sdk_fx.h"

extern void GX_SendFifo64B(const void *src);
extern void GX_SendFifo48B(const void *src);
extern void MI_Copy36B(const void *pSrc, void *pDest);
void G3_LoadMtx44(const void *m);
void G3_LoadMtx43(const void *m);
void G3_MultMtx44(const void *m);
void G3_MultMtx43(const void *m);
void G3_MultMtx33(const void *m);
void G3_MultTransMtx33(const MtxFx33 *mtx, const VecFx32 *trans);

void G3_LoadMtx44(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x16;
    GX_SendFifo64B(m);
}

void G3_LoadMtx43(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x17;
    GX_SendFifo48B(m);
}

void G3_MultMtx44(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x18;
    GX_SendFifo64B(m);
}

void G3_MultMtx43(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x19;
    GX_SendFifo48B(m);
}

void G3_MultMtx33(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x1a;
    MI_Copy36B(m, (void *)0x04000400);
}

#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)

/*
 * sdk:      G3_MultTransMtx33 (libgx.TWL.HYB.a g3imm.o)
 */
void G3_MultTransMtx33(const MtxFx33 *mtx, const VecFx32 *trans)
{
    reg_G3X_GXFIFO = 0x19;
    MI_Copy36B(mtx, (void *)&reg_G3X_GXFIFO);
    reg_G3X_GXFIFO = (u32)trans->x;
    reg_G3X_GXFIFO = (u32)trans->y;
    reg_G3X_GXFIFO = (u32)trans->z;
}
