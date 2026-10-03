/*
 * function: func_021E354C
 * address:  0x021E354C
 * packet:   pkt_ov093_021E354C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8804  0x021E8804  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void func_021E8804(int a, void *b, int c, int d);

void func_021E354C(int u, void *a, int b, int c)
{
    if (b == func_021D775C(2)) {
        if (func_021D76BC(0x51, 1) != 0)
            func_021E8804(u, a, b, c);
    }
}
