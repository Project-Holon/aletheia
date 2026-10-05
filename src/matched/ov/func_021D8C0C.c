/*
 * function: func_021D8C0C
 * address:  0x021D8C0C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D8C0C   0x021D8C0C  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *
 * Shape F1 (o28), gated twice: func_021D775C(2) must match c and
 * func_021D775C(0x44) must be non-zero, then func_021D76BC(0x35, 2 << 12).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_021D76BC(int key, u32 val);

void func_021D8C0C(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021D775C(0x44) != 0)
            func_021D76BC(0x35, 2 << 12);
    }
}
