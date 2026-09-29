/*
 * function: func_021BB13C
 * address:  0x021BB13C
 * packet:   pkt_ov021_021BB13C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_021BB13C(char *a, char *b)
{
    int r = -1;
    if (*(unsigned char *)(b + 2) == 1) {
        unsigned idx = *(unsigned short *)b;
        if (*(unsigned *)(a + 8) > idx) {
            unsigned short *e = (*(unsigned short ***)(a + 0xc))[idx];
            unsigned w = e[0];
            int x = *(short *)(b + 4) + (w >> 1);
            int y = *(unsigned short *)(b + 6);
            if ((int)w > x && e[1] > y && x >= 0 && y >= 0)
                r = *(int *)((char *)e + (x + w * y) * 4 + 4);
        }
    }
    return r;
}
