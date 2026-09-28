/*
 * function: func_021CAE20
 * address:  0x021CAE20
 * packet:   pkt_ov114_021CAE20
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_copy (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021CADAC(u8 *, int);
extern void func_02082D44(void *, void *, unsigned long);

u8 *func_021CAE20(u8 *a, u8 *b)
{
    u8 *A;
    if (a == b)
        return a;
    A = (*(int *)(b + 4) <= *(int *)(a + 8)) ? a : func_021CADAC(a, *(int *)(b + 4));
    if (A == 0)
        return 0;
    func_02082D44(*(void **)b, *(void **)a, *(int *)(b + 4) * 4);
    {
        int t = *(int *)(b + 4);
        *(int *)(a + 4) = t;
        if (t == 0) {
            if (*(void **)a != 0)
                *(u32 *)*(void **)a = 0;
        }
    }
    *(int *)(a + 0xc) = *(int *)(b + 0xc);
    return a;
}
