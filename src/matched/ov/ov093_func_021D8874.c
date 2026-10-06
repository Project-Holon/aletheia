/*
 * function: func_021D8874
 * address:  0x021D8874
 * packet:   pkt_ov093_021D8874
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_0201C1E8(int a);
u32 func_021D7B10(u32 a, u32 b);
int func_021D76BC(int key, u32 val);

void func_021D8874(void *a, int b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_0201C1E8((u16)func_021D775C(0x12)) == 1) {
            func_021D76BC(0x33, func_021D7B10(func_021D775C(0x33), 3 << 11));
        }
    }
}
