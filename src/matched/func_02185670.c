/*
 * function: func_02185670
 * address:  0x02185670
 * packet:   pkt_02185670
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185354  0x02185354  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_021852F4  0x021852F4  thumb  ov023
 */

extern void func_02185354(char *p);
extern void func_02186444(char *p, int v);
extern void func_021852F4(void *p, int v);

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

int func_02185670(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    *(unsigned short *)(p + 0x9288) = 0;
    func_02186444((char *)p, 4);
    func_021852F4(*(void **)(p + 0x100), 0);
    func_02185354((char *)p);
    return a1;
}
