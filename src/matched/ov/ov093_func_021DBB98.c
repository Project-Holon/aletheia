/*
 * function: func_021DBB98
 * address:  0x021DBB98
 * packet:   pkt_ov093_021DBB98
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
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 func_021D5B40(struct QI *p);
extern void func_021D7704(int a, int b);

void func_021DBB98(int u, int a, int b, int *c)
{
    if (b == func_021D775C(2) && *c == 1) {
        if (func_021D5B40(func_021C7CF4((int *)a, b)) == 0) {
            func_021D7704(0x35, 2 << 12);
        }
    }
}
