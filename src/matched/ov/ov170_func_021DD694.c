/*
 * function: func_021DD694
 * address:  0x021DD694
 * packet:   pkt_ov170_021DD694
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 */

extern unsigned func_0201AA18(void *party);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);

int func_021DD694(void ***p, unsigned skip)
{
    unsigned i;
    for (i = 0; i < func_0201AA18((*p)[2]); i++) {
        if (i != skip) {
            void *m = func_0201AB28((*p)[2], i);
            if (func_02017E1C(m, 0x4C, 0) == 0 && func_02017E1C(m, 0xA0, 0) != 0)
                return 1;
        }
    }
    return 0;
}
