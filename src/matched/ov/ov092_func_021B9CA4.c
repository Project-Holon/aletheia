/*
 * function: func_021B9CA4
 * address:  0x021B9CA4
 * packet:   pkt_ov092_021B9CA4
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
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
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
extern u32 func_02017E1C(void *mon, u32 id, u32 buf);
extern void *func_0200CA1C(u32 a);
extern void func_0200CFA0(void *a, void *mon);

void func_021B9CA4(struct S *s, void *party)
{
    int i;
    void *mon;
    u32 t;

    t = *(u32 *)s->f04;
    switch (t) {
    case 0:
    case 1:
        for (i = 0; i < func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                mon = func_0201AB28(party, i);
                if (func_02017E1C(mon, 5, 0) == 0x1ec) {
                    func_0200CFA0(func_0200CA1C(s->f00), mon);
                }
            }
        }
        break;
    }
}
