/*
 * function: func_021BC9CC
 * address:  0x021BC9CC
 * packet:   pkt_ov021_021BC9CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD1DC  0x021BD1DC  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021BD1FC  0x021BD1FC  thumb  ov021
 *   func_021BD204  0x021BD204  thumb  ov021
 *   func_021BD1EC  0x021BD1EC  thumb  ov021
 *   func_021BD1F4  0x021BD1F4  thumb  ov021
 *   func_020439A0  0x020439A0  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021BD1DC(int a);
extern int func_02045770(int a);
extern int func_021BD1FC(int a);
extern int func_021BD204(int a);
extern int func_021BD1EC(int a);
extern int func_021BD1F4(int a);
extern void func_020439A0(int a, int b, int c, int d, u16 e, u16 f, u16 g, u16 h, int i);

void func_021BC9CC(char *p)
{
    int r4;
    int a, b;
    u16 c, d, e, f;

    r4 = *(int *)(p + 0xc8 + 4 * *(u8 *)(p + 0x14a));
    if (r4 != 0) {
        a = func_021BD1DC(r4);
        b = func_02045770(*(int *)(p + 0x24));
        c = func_021BD1FC(r4);
        d = func_021BD204(r4) - 8;
        e = func_021BD1EC(r4);
        f = func_021BD1F4(r4);
        func_020439A0(a, b, 0, 0, c, d, e, f, 0);
    }
    (*(u8 *)(p + 0x14a))++;
}
