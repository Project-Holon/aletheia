/*
 * function: func_02175B4C
 * address:  0x02175B4C
 * packet:   pkt_ov011_02175B4C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02175B14  0x02175B14  thumb  ov011
 */

typedef unsigned char u8;

typedef struct Fl {
    u8 lo : 2;
    u8 x  : 1;
    u8 y  : 1;
    u8 hi : 4;
} Fl;

extern int func_02175B14(void *b);

void func_02175B4C(u8 *a, u8 *b)
{
    if (func_02175B14(b) == 1) {
        ((Fl *)(b + 0x1a5))->x = 1;
        ((Fl *)(b + 0x1a5))->y = 0;
        a[0x8a] |= 0x20;
        a[0x900] = 1;
    }
}
