/*
 * function: func_021D8E1C
 * address:  0x021D8E1C
 * packet:   pkt_ov093_021D8E1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021D8E00  0x021D8E00  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D8E7C  0x021D8E7C  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D8E00(void *a, int b);
extern int func_021C8288(void *p);
extern void func_021D8E7C(int u, void *a, u32 b, u32 c, u8 d);

void func_021D8E1C(int a, void *b, int c, int *d)
{
    if (func_021D8E00(b, c)) {
        func_021D8E7C(a, b, c, (u8)(func_021C8288(b) == 1), 1);
        *d = 1;
    }
}
