/*
 * function: G3X_InitTable
 * address:  0x0207DD4C
 * packet:   pkt_0207DD4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3X_InitTable (libgx.TWL.HYB.a g3x.o)
 *
 * symbols:
 *   MI_NDmaFillAsync     0x0272FBD0  arm
 *   MI_NDmaFill          0x0272FB28  arm
 *   MIi_DmaFill32Async   0x02082390  arm
 *   MIi_DmaFill32        0x020821C0  arm
 *   MIi_CpuClear32       0x02082A7C  arm
 *   GXi_DmaId            0x020A84C0  data
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

typedef void (*MIDmaCallback)(void *);

extern u32 GXi_DmaId;
extern void MI_NDmaFillAsync(u32 ndmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg);
extern void MI_NDmaFill(u32 ndmaNo, void *dest, u32 data, u32 size);
extern void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
extern void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);

#define reg_G3_SHININESS (*(vu32 *)0x040004D0)

void G3X_InitTable(void)
{
    int i;

    if (GXi_DmaId != (u32)-1) {
        if (GXi_DmaId > 3) {
            MI_NDmaFillAsync(GXi_DmaId - 4, (void *)0x04000330, 0, 16, 0, 0);
            MI_NDmaFill(GXi_DmaId - 4, (void *)0x04000360, 0, 96);
        } else {
            MIi_DmaFill32Async(GXi_DmaId, (void *)0x04000330, 0, 16, 0, 0, 1);
            MIi_DmaFill32(GXi_DmaId, (void *)0x04000360, 0, 96, 1);
        }
    } else {
        MIi_CpuClear32(0, (void *)0x04000330, 16);
        MIi_CpuClear32(0, (void *)0x04000360, 96);
    }
    for (i = 0; i < 32; i++) {
        reg_G3_SHININESS = 0;
    }
}
