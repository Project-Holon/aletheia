/*
 * function: func_021EB874
 * address:  0x021EB874
 * packet:   pkt_ov170_021EB874
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_020078C4 0x020078C4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_020257D0 0x020257D0 thumb
 */

extern void *func_02045EC0(void *bank, unsigned index);
extern unsigned func_020078C4(unsigned a, unsigned b);
extern void func_0201EFA4(void *obj, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void func_02043B5C(void *buf, unsigned char value);
extern void func_0201C7D0(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void func_02045808(void *vec);
extern void func_020257D0(void *o);

void func_021EB874(char **p, unsigned a, int i)
{
    void *s = func_02045EC0(*(void **)(p[11] + 0x80), 0x1E);
    unsigned n = func_020078C4(((unsigned *)p[0])[1], a);
    func_0201EFA4(*(void **)(p[11] + 0x84), 0, n, 2, 0, 1);
    func_0201F250(*(void **)(p[11] + 0x84), *(void **)(p[11] + 0x88), s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, *(void **)(p[11] + 0x88), *(void **)(p[11] + 0x7C), 0x1480);
    else
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, *(void **)(p[11] + 0x88), *(void **)(p[11] + 0x7C), 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}
