/*
 * function: func_021ED094
 * address:  0x021ED094
 * packet:   pkt_ov170_021ED094
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020F08 0x02020F08 thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_02049E34 0x02049E34 arm
 *   func_0204B7F0 0x0204B7F0 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049F34 0x02049F34 arm
 *   func_0204B7F8 0x0204B7F8 arm
 *   func_0204ADEC 0x0204ADEC arm
 */


extern unsigned func_02020F08(void);
extern unsigned func_02020E60(unsigned item, unsigned which);
extern void *func_02049E34(unsigned a0, unsigned a1, unsigned a2, void **a3, unsigned short a4);
extern void *func_0204B7F0(void *p);
extern void func_0204A9D0(void *a, void *b);
extern void func_020307B0(void *p);
extern void *func_02049F34(unsigned a0, unsigned a1, void **a2, unsigned a3);
extern void *func_0204B7F8(void *p);
extern void func_0204ADEC(void *dst, void *src, unsigned flag);

void func_021ED094(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = func_02049E34(func_02020F08(), func_02020E60(item, 1), 0, &a, 0x4C);
    func_0204A9D0(func_0204B7F0(*(void **)(w + 0x9E9C)), a);
    func_020307B0(q);
    q = func_02049F34(func_02020F08(), func_02020E60(item, 2), &b, 0x4C);
    func_0204ADEC(func_0204B7F8(*(void **)(w + 0x9E9C)), b, 1);
    func_020307B0(q);
}
