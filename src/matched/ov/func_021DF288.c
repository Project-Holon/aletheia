/*
 * function: func_021DF288
 * address:  0x021DF288
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DF288   0x021DF288  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021D7704   0x021D7704  thumb ov093
 *
 * Shape F1 (o28) with a two-argument tail: gate on func_021D775C(2), then
 * func_021D7704(0x35, 2 << 10).  First parameter is not read.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void func_021D7704(int a, int b);

void func_021DF288(void *a, void *b, int c)
{
    if (c == func_021D775C(2))
        func_021D7704(0x35, 2 << 10);
}
