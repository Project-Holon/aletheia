/*
 * function: func_021CADAC
 * address:  0x021CADAC
 * packet:   pkt_ov114_021CADAC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__bn_expand2 (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_copy / CRYPTOi__BN_set_word
 *
 * symbols:
 *   func_021CAAB4  0x021CAAB4  arm  ov114
 *   func_02082D44  0x02082D44  arm
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021CAAB4(unsigned long);
extern void func_02082D44(void *, void *, unsigned long);
extern void func_021CAAE8(void *);

u8 *func_021CADAC(u8 *a, int n)
{
    if (n > *(int *)(a + 8)) {
        u8 *newd;
        if (*(u32 *)(a + 0x10) & 2)
            return 0;
        newd = func_021CAAB4((n + 1) * 4);
        if (newd == 0)
            return 0;
        if (*(void **)a != 0) {
            func_02082D44(*(void **)a, newd, *(int *)(a + 4) * 4);
            func_021CAAE8(*(void **)a);
        }
        *(void **)a = newd;
        *(int *)(a + 8) = n;
    }
    return a;
}
