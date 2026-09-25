/*
 * function: func_021C4424
 * address:  0x021C4424
 * packet:   pkt_021C4424
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4440  0x021C4440  thumb
 *   func_021C4464  0x021C4464  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C4440(char *, int);
extern void func_021C4464(char *, int);

void func_021C4424(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x10) == 0)
        func_021C4440(p, i);
    else
        func_021C4464(p, i);
}
