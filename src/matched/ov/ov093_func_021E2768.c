/*
 * function: func_021E2768
 * address:  0x021E2768
 * packet:   pkt_ov093_021E2768
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
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);

void func_021E2768(int u, int a, int b, int *p)
{
    int n;

    if (b == func_021D775C(3)) {
        n = *p + 1;
        *p = n;
        func_021D76BC(0x30, n * 10);
    }
}
