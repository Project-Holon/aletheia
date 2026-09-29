/*
 * function: func_021B9C34
 * address:  0x021B9C34
 * packet:   pkt_ov092_021B9C34
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0216E62C  0x0216E62C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u8 *f04;
};

extern int func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern void func_0216E62C(u32 a, void *mon, int c);

void func_021B9C34(struct S *s, void *party, int c)
{
    int i;

    if (*(u32 *)s->f04 - 2 > 1) {
        for (i = 0; i < func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                func_0216E62C(s->f00, func_0201AB28(party, i), c);
            }
        }
    }
}
