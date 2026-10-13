/*
 * function: DWCi_HEAPlAllocEx
 * address:  0x021D6414
 * packet:   pkt_ov016_021D6414
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HEAPlAllocEx (libdwcutil.TWL.HYB.a heap.o)
 *
 * symbols:
 *   DWCi_HEAPlAlloc  0x021D63C8  arm  ov016
 *   MI_CpuFill8    0x02082BCC  arm
 */

extern void *DWCi_HEAPlAlloc(unsigned long size, int alignment);
extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);

void *DWCi_HEAPlAllocEx(unsigned long size, int alignment)
{
    void *mem = DWCi_HEAPlAlloc(size, alignment);
    MI_CpuFill8(mem, 0, size);
    return mem;
}
