/*
 * function: func_021855C8
 * address:  0x021855C8
 * packet:   pkt_021855C8
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185354  0x02185354  thumb  ov023
 */

extern void func_02185354(char *p);

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

int func_021855C8(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    *(unsigned short *)(p + 0x9286) = 0;
    func_02185354((char *)p);
    return a1;
}
