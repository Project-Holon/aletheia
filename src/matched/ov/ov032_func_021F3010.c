/*
 * function: func_021F3010
 * address:  0x021F3010
 * packet:   pkt_ov032_021F3010
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */

extern void *func_020450F0(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void *func_02045770(void);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void *func_02045730(void *);
extern void func_020409B4(void *);

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    unsigned char fc;
} T;

void func_021F3010(T *p, unsigned a, unsigned b, unsigned c, unsigned char d, unsigned char e, unsigned char f)
{
    void *w;
    p->f0 = func_020450F0((void *)a, c, d, e, f, b, 1);
    p->f4 = func_02045770();
    w = p->f0;
    p->fc = 0;
    p->f8 = w;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));
}
