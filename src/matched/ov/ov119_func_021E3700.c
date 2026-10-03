/*
 * function: func_021E3700
 * address:  0x021E3700
 * packet:   pkt_ov119_021E3700
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The vertex table is a non-const file static: as an extern (or a const
 * static) the allocator keeps n*3 in r1; as a writable file static it keeps
 * n*3 in r4 and the base in r3 like the original.
 *
 * symbols:
 *   d_021E8190 0x021E8190 data a2
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef s16 fx16;
typedef volatile u32 vu32;

#define REG_VTX_16 (*(vu32 *)0x0400048C)

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

static fx16 d_021E8190[24];

void func_021E3700(int n)
{
    G3_Vtx(d_021E8190[n * 3], d_021E8190[n * 3 + 1], d_021E8190[n * 3 + 2]);
}
