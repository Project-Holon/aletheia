/*
 * function: func_021EB7E8
 * address:  0x021EB7E8
 * packet:   pkt_ov170_021EB7E8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_020257D0 0x020257D0 thumb
 */

extern void *func_020457B0(unsigned capacity, unsigned heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern void func_02043B5C(void *buf, unsigned char value);
extern unsigned func_0201D304(void *s, unsigned a, unsigned b);
extern void func_0201C7D0(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void func_02045808(void *vec);
extern void func_020257D0(void *o);

void func_021EB7E8(char **p, unsigned box, int i)
{
    void *s = func_020457B0(0x14, 0x804C);
    unsigned n;
    func_0200785C(((void **)p[0])[1], box, s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    n = func_0201D304(s, *(unsigned *)(p[11] + 0x78), 0);
    n = (0x60 - n) / 2;
    func_0201C7D0(*(void **)(p[11] + i * 8 + 8), n, 0, s, *(void **)(p[11] + 0x78), 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}
