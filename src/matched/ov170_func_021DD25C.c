/*
 * function: func_021DD25C
 * address:  0x021DD25C
 * packet:   pkt_ov170_021DD25C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02007A18 0x02007A18 thumb
 */

extern int func_0201AA18(void *party);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern unsigned func_02017E88(void *p, unsigned id, unsigned v);
extern void *func_02007A18(void *save, int box, unsigned slot);

unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v)
{
    if (a >= 0x1E) {
        if (a >= 0x1E)
            a -= 0x1E;
        if (func_0201AA18((*p)[2]) > a)
            return func_02017E1C(func_0201AB28((*p)[2], a), id, v);
    } else if (a != 0xFF) {
        void *m = func_02007A18((*p)[1], box, a);
        if (m != 0)
            return func_02017E88(m, id, v);
    }
    return 0;
}
