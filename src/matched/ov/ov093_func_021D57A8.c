/*
 * function: func_021D57A8
 * address:  0x021D57A8
 * packet:   pkt_ov093_021D57A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D62C4(void *p, int i);

void func_021D57A8(u8 *p, u8 *a, u8 *b)
{
    int r = func_021D62C4(p, 0x18);
    u8 v;
    v = p[0xF8];
    if (v == 2 && r) *a = 0x11;
    else *a = v;
    v = p[0xF9];
    if (v == 2 && r) *b = 0x11;
    else *b = v;
    if (*a == 0x11) {
        if (*b == 0x11) *b = 0;
        *a = *b;
    } else if (*b == 0x11) {
        *b = *a;
    }
}
