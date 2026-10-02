/*
 * function: func_021E704C
 * address:  0x021E704C
 * packet:   pkt_ov093_021E704C
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
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5B40(void *p);
extern void func_021E8860(int n);

void func_021E704C(int a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_021D5B40(func_021C7CF4(b, c)) == 0)
            func_021E8860(2);
    }
}
