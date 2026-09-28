/*
 * function: ov208_func_021C23BC
 * address:  0x021C23BC
 * packet:   pkt_ov208_021C23BC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern s16 FX_SinCosTable_[];

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

void ov208_func_021C23BC(u8 *p)
{
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, W(0x1d8), 16 - W(0x1d8));
    if (H(0x1dc) + 0x400u >= 0x10000)
        H(0x1dc) = H(0x1dc) - 0xfc00;
    else
        H(0x1dc) += 0x400;
    W(0x1d8) = ((s16)((FX_SinCosTable_[(H(0x1dc) >> 4) * 2 + 1] + 0x1000) / 2) * 14 >> 12) + 1;
}
