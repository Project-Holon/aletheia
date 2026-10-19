/*
 * function: MET_TRAINERS_Init
 * address:  0x0200ED3C
 * packet:   pkt_0200ED3C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Save-table init callback: clears the 0xFC-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200ED44).  Pointer word
 * 0x0200ED3D at 0x0209DD60.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void MET_TRAINERS_Init(void *block)
{
    MI_CpuFill8(block, 0, 0xFC);
}
