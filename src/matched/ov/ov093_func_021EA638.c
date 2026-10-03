/*
 * function: func_021EA638
 * address:  0x021EA638
 * packet:   pkt_ov093_021EA638
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021EA730(char *p, u32 a, u16 b, u32 c);

void func_021EA638(char *p, struct H *h, int c)
{
    func_021EA55C(h, *(int *)(p + 0xac));
    func_021EA730(p, *(int *)(p + 0xac), h->b2, c);
}
