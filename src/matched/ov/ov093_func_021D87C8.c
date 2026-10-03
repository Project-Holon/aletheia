/*
 * function: func_021D87C8
 * address:  0x021D87C8
 * packet:   pkt_ov093_021D87C8
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
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int a, int b);
int func_021D62A8(void *m);
void func_021D7704(int a, int b);
void func_021D76BC(int a, int b);

void func_021D87C8(void *a, int b, int c)
{
    void *r;
    if (c == func_021D775C(2)) {
        r = func_021C7CF4(b, c);
        if (func_021D62A8(r) != 0) {
            func_021D7704(0x35, 6 << 10);
            func_021D76BC(0x51, 0);
        }
    }
}
