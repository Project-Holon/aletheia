/*
 * function: func_021CA42C
 * address:  0x021CA42C
 * packet:   pkt_021CA42C
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_02045374(void *);
extern unsigned char func_02045730(void *);
extern void func_02041B6C(unsigned);

void func_021CA42C(char *p)
{
    func_02045374(*(void **)(p + 0xc));
    func_02041B6C(func_02045730(*(void **)(p + 0xc)));
}
