/*
 * function: func_021B709C
 * address:  0x021B709C
 * packet:   pkt_ov021_021B709C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F184  0x0201F184  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
typedef signed int     s32;
struct Big;
struct WordSet;
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);

int func_021B709C(void *a, u32 *b, void *c)
{
    void *t;
    void *r;
    u32 x;

    t = func_0215A5E4(c);
    func_0200BE48(func_02012EBC(t));
    r = func_02012944(t);
    x = *b;
    func_0201F02C(a, 0, r);
    func_0201F184(a, 1, x);
    return 9;
}
