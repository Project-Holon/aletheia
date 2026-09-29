/*
 * function: func_02193260
 * address:  0x02193260
 * packet:   pkt_ov021_02193260
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char u8;

extern int func_020362DC(void);

int func_02193260(u8 *p, u8 q)
{
    int r = func_020362DC();
    int lim;

    if (q == 0) {
        lim = 8;
    } else {
        lim = 0x32;
    }
    if (p[0] != 0) {
        p[1] = p[1] + 1;
        if (p[1] >= lim) {
            p[1] = 0;
            return 1;
        }
        return 0;
    }
    if ((r & 3) != 0) {
        return 1;
    }
    return 0;
}
