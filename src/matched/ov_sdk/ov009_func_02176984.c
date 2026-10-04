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

typedef unsigned int   u32;
extern int func_021684CC(char *key, char *value, char *string, char separator);
extern u32 sub_02095EAC(u32 a0, u32 *a1, u32 mode);

unsigned char func_02176984(char *a0)
{
    char buf[4] = {0};
    unsigned char r = 0;

    if (func_021684CC((char *)0x021A208Cu, buf, a0 + 8, 0x2F) > 0)
        r = (unsigned char)sub_02095EAC((u32)buf, 0, 10);
    return r;
}
