/*
 * function: func_0219CEAC
 * address:  0x0219CEAC
 * packet:   pkt_ov021_0219CEAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219CB24  0x0219CB24  thumb  ov021
 */

extern void func_0219CB24(int *, int, unsigned int, unsigned int, unsigned int, int);

void func_0219CEAC(int *obj)
{
    unsigned int i;
    int *p;
    int *t;

    t = (int *)obj[7];
    if (t != 0 && t[0] == 1) {
        i = 0;
        p = (int *)t[4];
        if (!(i < *(unsigned short *)((char *)t + 6))) {
            return;
        }
        for (; i < *(unsigned short *)((char *)t + 6); i++, p += 5) {
            if (p[4] != 0 && *(unsigned char *)p == 1) {
                *(unsigned char *)p = 0;
                func_0219CB24(obj, p[4], *(unsigned short *)(p + 2), *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), p[1]);
                p[4] = 0;
            }
        }
    }
}
