/*
 * function: func_021E3E64
 * address:  0x021E3E64
 * packet:   pkt_ov093_021E3E64
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E3F08  0x021E3F08  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void func_021E3F08(void *a, int c, int *w);

void func_021E3E64(int u, void *a, int b, int *p)
{
    if (b == func_021D775C(2))
        func_021E3F08(a, b, p);
}
