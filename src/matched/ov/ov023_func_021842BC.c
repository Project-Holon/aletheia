/*
 * function: func_021842BC
 * address:  0x021842BC
 * packet:   pkt_ov023_021842BC
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char u8;

void func_021842BC(int a0, int a1, const u8 *src, char *p)
{
    int i;
    u8 *d;
    const u8 *s;

    if (p != 0 && a0 == 0) {
        for (i = 0; i < 5; i++) {
            d = (u8 *)p + i * 6;
            s = src + i * 6;
            d[0x4212] = s[0];
            d[0x4213] = s[1];
            d[0x4214] = s[2];
            d[0x4215] = s[3];
            d[0x4216] = s[4];
            d[0x4217] = s[5];
        }
    }
}
