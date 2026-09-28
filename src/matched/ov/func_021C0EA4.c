/*
 * function: func_021C0EA4
 * address:  0x021C0EA4
 * packet:   pkt_021C0EA4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Addresses are Black-image addresses.
 */

extern int _s32_div_f(int, int);

void func_021C0EA4(char *p, int v)
{
    *(int *)(*(int *)p + *(int *)(p + 0xc) * 4) = v;
    *(int *)(p + 0xc) = (*(int *)(p + 0xc) + 1) % *(int *)(p + 4);
}
