/*
 * function: func_02176984
 * address:  0x02176984
 * packet:   pkt_02176984
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_021684CC  0x021684CC  arm
 *   sub_02095EAC   0x02095EAC  arm
 */

extern int func_021684CC(unsigned a, char *buf, char *src, int delim);
extern int sub_02095EAC(const char *s, char **end, int base);

unsigned char func_02176984(char *a0)
{
    char buf[4] = {0};
    unsigned char r = 0;

    if (func_021684CC(0x021A208Cu, buf, a0 + 8, 0x2F) > 0)
        r = (unsigned char)sub_02095EAC(buf, 0, 10);
    return r;
}
