/*
 * function: func_02082E74
 * address:  0x02082E74
 * packet:   pkt_02082E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      MI_CpuComp8 (libmi.TWL.HYB.a mi_memory.o)
 */

typedef unsigned long u32;
typedef unsigned char u8;

int func_02082E74(const void *mem1, const void *mem2, u32 size)
{
    const u8 *p1 = (const u8 *)mem1;
    const u8 *p2 = (const u8 *)mem2;
    const u8 *p1end = p1 + size;

    while (p1 < p1end) {
        int d = (int)*p1++ - (int)*p2++;
        if (d != 0) {
            return d;
        }
    }
    return 0;
}
