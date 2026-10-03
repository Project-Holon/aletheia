/*
 * function: func_021DDF98
 * address:  0x021DDF98
 * packet:   pkt_ov093_021DDF98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021DDE74  0x021DDE74  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021DCFF8(int a, int b);
extern int func_021DDE74(int a, int b, int c, int d);
extern void func_021DD044(int a, int b, int c);

void func_021DDF98(int a, void *b, int c)
{
    u8 j;

    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        j = func_021DCFF8(a, 2);
        if (func_021DDE74(a, (int)b, c, j) != 0)
            func_021DD044(a, (int)b, c);
    }
}
