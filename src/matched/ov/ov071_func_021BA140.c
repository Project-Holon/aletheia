/*
 * function: func_021BA140
 * address:  0x021BA140
 * packet:   pkt_ov071_021BA140
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202590C  0x0202590C  thumb
 *   func_02043814  0x02043814  arm
 */

typedef unsigned char u8;

extern void func_0202590C(void *o, short x, short y);
extern void func_02043814(void *a, void *b);

void func_021BA140(u8 *p)
{
    int x = *(int *)(p + 0x2d8) >> 8;
    int b = 8 - x % 32;
    u8 *q = p + (x / 32) * 4;
    int i;

    for (i = 0; i < 7; i++) {
        func_0202590C(*(void **)(p + i * 4 + 0x2a0), 0x20, b + i * 32);
        if (*(void **)(q + i * 4 + 0x24) != 0) {
            func_02043814(*(void **)(q + i * 4 + 0x24), *(void **)(p + i * 4 + 0x2bc));
        }
    }
}
