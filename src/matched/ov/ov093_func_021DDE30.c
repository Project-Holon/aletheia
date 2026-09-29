/*
 * function: func_021DDE30
 * address:  0x021DDE30
 * packet:   pkt_ov093_021DDE30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DDE74  0x021DDE74  thumb  ov093
 *   func_021DDEA4  0x021DDEA4  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021DDE74(int a, int b, int c, int d);
extern int func_021DDEA4(int b, int c, int d);
extern void func_021DD044(int a, int b, int c);

void func_021DDE30(int a, int b, int c, int d, int e)
{
    int r;

    if (c == func_021D775C(2)) {
        if (e != 0)
            r = func_021DDE74(a, b, c, d);
        else
            r = func_021DDEA4(b, c, d);
        if (r != 0)
            func_021DD044(a, b, c);
    }
}
