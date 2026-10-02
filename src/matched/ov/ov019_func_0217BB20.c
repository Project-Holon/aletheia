/*
 * function: func_0217BB20
 * address: 0x0217BB20
 * packet: pkt_ov019_0217BB20
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217BB04 0x0217BB04 thumb ov019
 *   func_0217B8E4 0x0217B8E4 thumb ov019
 */
extern int func_0217BB04(char *);
extern int func_0217B8E4(char *, char);
int func_0217BB20(char *p)
{
    if (func_0217BB04(p) == 1) {
        func_0217B8E4(p, 50);
        return 1;
    }
    return 0;
}
