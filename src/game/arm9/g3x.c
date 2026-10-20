/*
 * file:     g3x.c
 * unit:     yes
 * function: G3X_Init, G3X_Reset, G3X_ClearFifo, G3X_InitMtxStack, G3X_ResetMtxStack, G3X_SetFog, G3X_GetClipMtx, G3X_GetVectorMtx, G3X_SetEdgeColorTable, G3X_SetFogTable, G3X_SetClearColor, G3X_InitTable, G3X_GetMtxStackLevelPV, G3X_GetMtxStackLevelPJ, G3X_SetDisp1DotDepth, G3X_GetBoxTestResult, GXi_NopClearFifo128_
 * address:  0x0207D988
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
 *   G3X_ClearFifo      0x0207DAF8  arm
 *   G3X_InitMtxStack   0x0207DB1C  arm
 *   G3X_InitTable      0x0207DD4C  arm
 *   G3X_ResetMtxStack   0x0207DBB4  arm
 *   GXi_NopClearFifo128_   0x0207DECC  arm
 *   G3X_GetMtxStackLevelPV   0x0207DE30  arm
 *   G3X_GetMtxStackLevelPJ   0x0207DE5C  arm
 *   MI_Copy64B   0x02082BA0  arm
 *   MI_Copy36B   0x02082B60  arm
 *   MIi_CpuCopy16   0x02082A60  arm
 *   MI_Copy32B   0x02082B44  arm
 *   MI_NDmaFillAsync     0x0272FBD0  arm
 *   MI_NDmaFill          0x0272FB28  arm
 *   MIi_DmaFill32Async   0x02082390  arm
 *   MIi_DmaFill32        0x020821C0  arm
 *   MIi_CpuClear32       0x02082A7C  arm
 *   GXi_DmaId            0x020A84C0  data
 */
#define reg_G3X_GXFIFO          (*(vu32 *)REG_GXFIFO_ADDR)
#define reg_G3X_GXSTAT          (*(vu32 *)REG_GXSTAT_ADDR)
#define reg_G3X_CLEAR_COLOR     (*(vu32 *)REG_CLEAR_COLOR_ADDR)
#define reg_G3X_CLEAR_DEPTH     (*(vu16 *)REG_CLEAR_DEPTH_ADDR)
#define reg_G3X_DISP_1DOT_DEPTH (*(vu16 *)REG_DISP_1DOT_DEPTH_ADDR)
#define REG_CLIPMTX_RESULT_0_ADDR REG_CLIPMTX_RESULT_ADDR
#define REG_VECMTX_RESULT_0_ADDR  REG_VECMTX_RESULT_ADDR
#define reg_G3X_DISP3DCNT       (*(vu16 *)REG_DISP3DCNT_ADDR)
#define reg_G3X_FOG_OFFSET      (*(vu16 *)REG_FOG_OFFSET_ADDR)
#define reg_G3_POLYGON_ATTR     (*(vu32 *)REG_POLYGON_ATTR_ADDR)
#define reg_G3_TEXIMAGE_PARAM   (*(vu32 *)REG_TEXIMAGE_PARAM_ADDR)
#define reg_G3_TEXPLTT_BASE     (*(vu32 *)REG_TEXPLTT_BASE_ADDR)
#define reg_G3_MTX_MODE         (*(vu32 *)REG_MTX_MODE_ADDR)
#define reg_G3_MTX_POP          (*(vu32 *)REG_MTX_POP_ADDR)
#define reg_G3_MTX_IDENTITY     (*(vu32 *)REG_MTX_IDENTITY_ADDR)
#define reg_G3_END_VTXS         (*(vu32 *)REG_END_VTXS_ADDR)
#define reg_G2_BG0OFS           (*(vu32 *)REG_BG0OFS_ADDR)
#define reg_G2_BG0CNT           (*(vu16 *)REG_BG0CNT_ADDR)
#define reg_G3X_CLRIMAGE_OFFSET (*(vu16 *)REG_CLRIMAGE_OFFSET_ADDR)
#define reg_G3X_FOG_COLOR       (*(vu32 *)REG_FOG_COLOR_ADDR)
#define reg_G3_SHININESS (*(vu32 *)REG_SHININESS_ADDR)
#include "../types.h"
#include "../sdk_ioreg_reg.h"
#include "../sdk_ioreg.h"

#include "../sdk_fx.h"

#include "../sdk_gx.h"

typedef void (*MIDmaCallback)(void *);

extern void G3X_ClearFifo(void);
extern void G3X_InitMtxStack(void);
extern void G3X_InitTable(void);
extern void G3X_ResetMtxStack(void);
extern void GXi_NopClearFifo128_(void *pDest);
extern int G3X_GetMtxStackLevelPV(s32 *level);
extern int G3X_GetMtxStackLevelPJ(s32 *level);
#include "mi_memory.h"
#include "../twl/mi_ndma.h"
extern void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
#include "mi_dma.h"
void G3X_Init(void);
void G3X_Reset(void);
void G3X_SetFog(BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset);
int G3X_GetClipMtx(MtxFx44 *m);
int G3X_GetVectorMtx(MtxFx33 *m);
void G3X_SetEdgeColorTable(const void *src);
void G3X_SetFogTable(const void *src);
void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);
void G3X_SetDisp1DotDepth(fx32 w);
int G3X_GetBoxTestResult(s32 *in);
extern u32 GXi_DmaId;

static inline void G3X_SetShading(int shading)
{
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(0x3000 | 0x0002)) | (shading << 1));
}

static inline void G2_SetBG0Priority(int priority)
{
    reg_G2_BG0CNT = (u16)((reg_G2_BG0CNT & ~0x3) | (priority << 0));
}

/*
 * sdk:      G3X_Init (libgx.TWL.HYB.a g3x.o)
 */
void G3X_Init(void)
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

/*
 * sdk:      G3X_Reset (libgx.TWL.HYB.a g3x.o)
 */
void G3X_Reset(void)
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

/*
 * sdk:      G3X_ClearFifo (libgx.TWL.HYB.a g3x.o)
 */
void G3X_ClearFifo(void)
{
    GXi_NopClearFifo128_((void *)&reg_G3X_GXFIFO);
    while (reg_G3X_GXSTAT & 0x08000000) {
    }
}

/*
 * sdk:      G3X_InitMtxStack (libgx.TWL.HYB.a g3x.o)
 */
void G3X_InitMtxStack(void)
{
    s32 levelPV, levelPJ;

    reg_G3X_GXSTAT |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&levelPV)) {
    }
    while (G3X_GetMtxStackLevelPJ(&levelPJ)) {
    }
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 0;
    if (levelPJ) {
        reg_G3_MTX_POP = (u32)levelPJ;
    }
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_POP = (u32)levelPV;
    reg_G3_MTX_IDENTITY = 0;
}

/*
 * sdk:      G3X_ResetMtxStack (libgx.TWL.HYB.a g3x.o)
 */
void G3X_ResetMtxStack(void)
{
    s32 levelPV, levelPJ;

    reg_G3X_GXSTAT |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&levelPV)) {
    }
    while (G3X_GetMtxStackLevelPJ(&levelPJ)) {
    }
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 0;
    if (levelPJ) {
        reg_G3_MTX_POP = (u32)levelPJ;
    }
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_POP = (u32)levelPV;
    reg_G3_MTX_IDENTITY = 0;
}

/*
 * sdk:      G3X_SetFog (libgx.TWL.HYB.a g3x.o)
 */
void G3X_SetFog(BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset)
{
    if (enable) {
        reg_G3X_FOG_OFFSET = (u16)fogOffset;
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~0x3f40) | ((fogSlope << 8) | (fogMode << 6) | 0x80));
    } else {
        reg_G3X_DISP3DCNT &= 0xcf7f;
    }
}

/*
 * sdk:      G3X_GetClipMtx (libgx.TWL.HYB.a g3x.o)
 */
int G3X_GetClipMtx(MtxFx44 *m)
{
    if (reg_G3X_GXSTAT & 0x08000000) {
        return -1;
    } else {
        MI_Copy64B((void *)(const void *)REG_CLIPMTX_RESULT_0_ADDR, m);
        return 0;
    }
}

/*
 * sdk:      G3X_GetVectorMtx (libgx.TWL.HYB.a g3x.o)
 */
int G3X_GetVectorMtx(MtxFx33 *m)
{
    if (reg_G3X_GXSTAT & 0x08000000) {
        return -1;
    } else {
        MI_Copy36B((const void *)REG_VECMTX_RESULT_0_ADDR, m);
        return 0;
    }
}

void G3X_SetEdgeColorTable(const void *src)
{
    MIi_CpuCopy16(src, (void *)REG_EDGE_COLOR_ADDR, 0x10);
}

void G3X_SetFogTable(const void *src)
{
    MI_Copy32B(src, (void *)REG_FOG_TABLE_ADDR);
}

/*
 * sdk:      G3X_SetClearColor (libgx.TWL.HYB.a g3x.o)
 */
void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog)
{
    u32 val = (u32)(rgb | (alpha << 16) | (polygonID << 24));

    if (fog) {
        val |= 0x8000;
    }
    reg_G3X_CLEAR_COLOR = val;
    reg_G3X_CLEAR_DEPTH = (u16)depth;
}

/*
 * sdk:      G3X_InitTable (libgx.TWL.HYB.a g3x.o)
 */
void G3X_InitTable(void)
{
    int i;

    if (GXi_DmaId != (u32)-1) {
        if (GXi_DmaId > 3) {
            MI_NDmaFillAsync(GXi_DmaId - 4, (unsigned int)REG_EDGE_COLOR_ADDR, 0, 16, 0, 0);
            MI_NDmaFill((s32)(GXi_DmaId - 4), (s32)REG_FOG_TABLE_ADDR, 0, 96);
        } else {
            MIi_DmaFill32Async(GXi_DmaId, (void *)REG_EDGE_COLOR_ADDR, 0, 16, 0, 0, 1);
            MIi_DmaFill32(GXi_DmaId, (void *)REG_FOG_TABLE_ADDR, 0, 96, 1);
        }
    } else {
        MIi_CpuClear32(0, (void *)REG_EDGE_COLOR_ADDR, 16);
        MIi_CpuClear32(0, (void *)REG_FOG_TABLE_ADDR, 96);
    }
    for (i = 0; i < 32; i++) {
        reg_G3_SHININESS = 0;
    }
}

/*
 * sdk:      G3X_GetMtxStackLevelPV (libgx.TWL.HYB.a g3x.o)
 */
int G3X_GetMtxStackLevelPV(s32 *level)
{
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    } else {
        *level = (s32)((reg_G3X_GXSTAT & 0x1f00) >> 8);
        return 0;
    }
}

/*
 * sdk:      G3X_GetMtxStackLevelPJ (libgx.TWL.HYB.a g3x.o)
 */
int G3X_GetMtxStackLevelPJ(s32 *level)
{
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    } else {
        *level = (s32)((reg_G3X_GXSTAT & 0x2000) >> 13);
        return 0;
    }
}

/*
 * sdk:      G3X_SetDisp1DotDepth (libgx.TWL.HYB.a g3x.o)
 */
void G3X_SetDisp1DotDepth(fx32 w)
{
    reg_G3X_DISP_1DOT_DEPTH = (u16)((w >> 9) & 0x7fff);
}

/*
 * sdk:      G3X_GetBoxTestResult (libgx.TWL.HYB.a g3x.o)
 */
int G3X_GetBoxTestResult(s32 *in)
{
    if (reg_G3X_GXSTAT & 1) {
        return -1;
    } else {
        *in = (s32)(reg_G3X_GXSTAT & 2);
        return 0;
    }
}

/*
 * sdk:      GXi_NopClearFifo128_ (libgx.TWL.HYB.a g3x.o)
 * asm:      fixed-register stm block into the geometry FIFO (stmia r0, {r1, r2, r3, r12} x32); no C spelling.
 * hand-written in the original: unrolled stm FIFO writes, one SDK line-table row per instruction
 */
asm void GXi_NopClearFifo128_(void *pDest)
{
    mov r1, #0
    mov r2, #0
    mov r3, #0
    mov r12, #0
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    bx lr
}
