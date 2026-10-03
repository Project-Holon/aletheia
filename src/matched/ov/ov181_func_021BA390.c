/*
 * function: func_021BA390
 * address: 0x021BA390
 * packet: pkt_ov181_021BA390
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021BA4AA, then labelled 021BA4AC.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_020437D4 0x020437D4 arm
 *   func_021BA354 0x021BA354 thumb ov181
 *   func_021B9DCC 0x021B9DCC thumb ov181
 */
typedef unsigned short u16;
extern void *func_02045770(void *);
struct Bmp { void *pixels; u16 width, height, depth, kind; };
extern void *func_020437D4(const struct Bmp *);
extern void func_021BA354(void *, void *, unsigned);
extern void func_021B9DCC(char *, unsigned);
void func_021BA390(char *p)
{
    char *a, *b;
    unsigned n;
    u16 i, j, k, l, m, o;
    unsigned x, y;
    if (*(int *)(p + 0x2e0) == 0) return;
    *(int *)(p + 0x2dc) += 0x1000;
    if (*(int *)(p + 0x2dc) < 0x1000) return;
    *(int *)(p + 0x2dc) -= 0x1000;
    n = 1;
    if (*(unsigned char *)(p + 0x2d2)) n = 4;
    a = func_020437D4(func_02045770(*(void **)(p + 0x2bc)));
    b = func_020437D4(func_02045770(*(void **)(p + 0x2c4)));
    x = 0;
    for (i = 0; i < 32; i++, x += 32) func_021BA354(a + x, 0, n);
    for (j = 1; j < 25; j++) {
        x = j * 1024;
        y = (j - 1) * 1024;
        for (k = 0; k < 32; k++, x += 32, y += 32) func_021BA354(a + x, a + y, n);
    }
    x = 0;
    y = 0x6000;
    for (l = 0; l < 32; l++, x += 32, y += 32) func_021BA354(b + x, a + y, n);
    for (m = 1; m < 28; m++) {
        x = m * 1024;
        y = (m - 1) * 1024;
        for (o = 0; o < 32; o++, x += 32, y += 32) func_021BA354(b + x, b + y, n);
    }
    func_021B9DCC(p, 3);
}
