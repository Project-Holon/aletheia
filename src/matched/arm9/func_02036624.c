/*
 * function: func_02036624
 * address:  0x02036624
 * packet:   pkt_02036624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

int func_02036624(void *p, int v)
{
    return v % *(int *)((char *)p + 4);
}
