/*
 * function: func_021E6480
 * address:  0x021E6480
 * packet:   pkt_ov093_021E6480
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C8288(void *p);
extern void func_021D7704(int a, int b);

void func_021E6480(int a, void *b, int c)
{
    if (c == func_021D775C(3) && (u8)(func_021C8288(b) + 254) <= 2)
        func_021D7704(0x31, 2 << 10);
}
