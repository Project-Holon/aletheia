/*
 * function: func_0216E47C
 * address:  0x0216E47C
 * packet:   pkt_ov010_0216E47C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *
 * Save-table init callback: fills the 0x168-byte block with 0xFF bytes
 * (tail call to MIi_CpuClear32 through the pool word at 0x0216E48C).
 * Pointer word 0x0216E47D at arm9 0x0209DC94.
 */

typedef unsigned int u32;

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);

void func_0216E47C(void *block)
{
    MIi_CpuClear32(0xFFFFFFFF, block, 0x168);
}
