/*
 * function: CONFIG_Copy
 * address:  0x02008314
 * packet:   pkt_020082EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */

extern void MI_CpuCopy8(void *dst, void *src, int n);
void CONFIG_Copy(void *a0, void *a1)
{
    MI_CpuCopy8(a0, a1, 4);
}
