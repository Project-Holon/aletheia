/*
 * function: func_021DC218
 * address:  0x021DC218
 * packet:   pkt_ov093_021DC218
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
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021D7704(int a, int b);

void func_021DC218(int u, int a, int b)
{
    if (b == func_021D775C(3) && func_021D62C4(func_021C7CF4((int *)a, b), 5) != 0
        && func_021D775C(0x1a) == 1) {
        func_021D7704(0x31, 3 << 11);
    }
}
