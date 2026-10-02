/*
 * function: func_0200EA2C
 * address:  0x0200EA2C
 * packet:   pkt_0200EA2C
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
 * Save-table init callback: clears the 0x16C-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200EA38).  Pointer word
 * 0x0200EA2D at 0x0209DD48.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void func_0200EA2C(void *block)
{
    MI_CpuFill8(block, 0, 0x16C);
}
