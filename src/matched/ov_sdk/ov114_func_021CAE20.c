/*
 * function: CRYPTOi__BN_copy
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
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *CRYPTOi__bn_expand2(u8 *a, int n);
extern void MI_CpuCopy8(void *, void *, unsigned long);

u8 *CRYPTOi__BN_copy(u8 *a, u8 *b)
{
    u8 *A;
    if (a == b)
        return a;
    A = (*(int *)(b + 4) <= *(int *)(a + 8)) ? a : CRYPTOi__bn_expand2(a, *(int *)(b + 4));
    if (A == 0)
        return 0;
    MI_CpuCopy8(*(void **)b, *(void **)a, *(int *)(b + 4) * 4);
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
