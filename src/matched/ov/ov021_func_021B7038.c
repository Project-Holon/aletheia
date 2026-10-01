/*
 * function: func_021B7038
 * address:  0x021B7038
 * packet:   pkt_ov021_021B7038
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb ov010
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *);
extern void *func_02012944(void *);
extern void func_0201F02C(void *, int, void *);
extern void func_0201EF40(void *, int, u16);

int func_021B7038(void *a, u32 *b, void *c)
{
    void *t;
    u16 x;

    t = func_02012944(func_0215A5E4(c));
    x = *b;
    func_0201F02C(a, 0, t);
    func_0201EF40(a, 1, x);
    return 7;
}
