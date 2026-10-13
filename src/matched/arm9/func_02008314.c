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
 */

extern void func_02082D44(void *dst, void *src, int n);
void CONFIG_Copy(void *a0, void *a1)
{
    func_02082D44(a0, a1, 4);
}
