/*
 * function: func_021EA614
 * address:  0x021EA614
 * packet:   pkt_ov093_021EA614
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EA55C  0x021EA55C  thumb  ov093
 *   func_021EA730  0x021EA730  thumb  ov093
 */
typedef unsigned char u8;

struct H {
    u8 b0[2];
    u8 b2;
};

extern void func_021EA55C(struct H *p, int a);
extern void func_021EA730(char *p, int a, int b, int c);

void func_021EA614(char *p, struct H *h)
{
    func_021EA55C(h, *(int *)(p + 0xac));
    func_021EA730(p, *(int *)(p + 0xac), h->b2, 0);
}
