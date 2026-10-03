/*
 * function: func_021E700C
 * address:  0x021E700C
 * packet:   pkt_ov093_021E700C
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
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
struct Unk021D62A8;
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_021E8860(int a);

void func_021E700C(int x, int a, int c)
{
    if (c == func_021D775C(3)) {
        if (func_021D62A8(func_021C7CF4(a, (u8)func_021D775C(4))) != 0) {
            func_021E8860(2);
        }
    }
}
