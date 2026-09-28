/*
 * function: func_021D9404
 * address:  0x021D9404
 * packet:   pkt_021D9404
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_020310C4(void *);
extern void func_0201C4E4(void *);

void func_021D9404(char *p)
{
    func_020310C4(*(void **)(p + 0x88));
    func_0201C4E4(*(void **)(p + 0x8c));
}
