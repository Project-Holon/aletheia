/*
 * function: func_021EA6F4
 * address:  0x021EA6F4
 * packet:   pkt_ov093_021EA6F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF5E8  0x021EF5E8  thumb  ov093
 *   func_021EA730  0x021EA730  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021EF5E8(int a, u8 b, u16 c);
extern void func_021EA730(char *p, int a, int b, int c);

void func_021EA6F4(void *p, u8 b, u16 c)
{
    func_021EF5E8(*(int *)((char *)p + 0xac), b, c);
    func_021EA730(p, *(int *)((char *)p + 0xac), 0x50, 0);
}
