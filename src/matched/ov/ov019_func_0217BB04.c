/*
 * function: func_0217BB04
 * address: 0x0217BB04
 * packet: pkt_ov019_0217BB04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0217B8E4 0x0217B8E4 thumb ov019
 */
extern unsigned int func_0200FB24(void);
extern int func_0217B8E4(char *, char);
int func_0217BB04(char *p)
{
    if (func_0200FB24() != 0) {
        func_0217B8E4(p, 1);
        return 1;
    }
    return 0;
}
