/*
 * function: func_021F3058
 * address:  0x021F3058
 * packet:   pkt_ov032_021F3058
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F3010 0x021F3010 thumb ov032
 */

extern void func_021F3010(void *, unsigned, unsigned, unsigned, unsigned char, unsigned char, unsigned char);

void func_021F3058(char *p)
{
    func_021F3010(p + 0x17C, 6, 1, 2, 0x16, 0x1C, 6);
    func_021F3010(p + 0x190, 4, 0xD, 1, 0x15, 0xF, 3);
    func_021F3010(p + 0x1A4, 7, 4, 0, 0x13, 6, 2);
}
