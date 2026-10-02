/*
 * function: func_021E3F08
 * address:  0x021E3F08
 * packet:   pkt_ov093_021E3F08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *p);

void func_021E3F08(void *a, int b, int *p)
{
    u8 *s;

    if (p[6] != 0) {
        s = func_021C88A4(a, 0xb, b);
        *(int *)(s + 4) = 0x19;
        s[0x14] = 1;
        s[8] = b;
        s[0x15] = 1;
        func_021C88C8(a, s);
        p[6] = 0;
    }
}
