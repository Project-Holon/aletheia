/*
 * function: func_021DDA28
 * address:  0x021DDA28
 * packet:   pkt_ov093_021DDA28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern u8 *func_021C7CF4(void *a, int b);
extern int func_021D62C4(u8 *p, int i);
extern void func_021DD044(u8 *a, u8 *b, int c);

void func_021DDA28(u8 *a, u8 *b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D775C(0x38) > 3
        && func_021D62C4(func_021C7CF4(b, c), 0xf) == 0)
        func_021DD044(a, b, c);
}
