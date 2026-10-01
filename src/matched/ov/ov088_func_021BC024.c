/*
 * function: func_021BC024
 * address:  0x021BC024
 * packet:   pkt_ov088_021BC024
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_0201FDA0  0x0201FDA0  thumb
 */

typedef struct Ov088Win {
    unsigned char f00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
} Ov088Win;

extern void *func_0201FDA0(Ov088Win *win, int base, int pal, int pos, int heap);

void func_021BC024(char *p)
{
    Ov088Win win;

    win.f00 = 0;
    win.f01 = 0x18;
    win.f02 = 0xD;
    win.f03 = 0xF;
    win.f04 = 0;
    *(void **)(p + 0x7c) = func_0201FDA0(&win, 1, 0xE, 0, 0xB);
}
