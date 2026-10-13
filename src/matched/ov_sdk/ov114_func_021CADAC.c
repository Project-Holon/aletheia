/*
 * function: CRYPTOi__bn_expand2
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
 *   CRYPTOi_MyAlloc  0x021CAAB4  arm  ov114
 *   MI_CpuCopy8  0x02082D44  arm
 *   CRYPTOi_MyFree  0x021CAAE8  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *CRYPTOi_MyAlloc(unsigned long);
extern void MI_CpuCopy8(void *, void *, unsigned long);
extern void CRYPTOi_MyFree(void *);

u8 *CRYPTOi__bn_expand2(u8 *a, int n)
{
    if (n > *(int *)(a + 8)) {
        u8 *newd;
        if (*(u32 *)(a + 0x10) & 2)
            return 0;
        newd = CRYPTOi_MyAlloc((n + 1) * 4);
        if (newd == 0)
            return 0;
        if (*(void **)a != 0) {
            MI_CpuCopy8(*(void **)a, newd, *(int *)(a + 4) * 4);
            CRYPTOi_MyFree(*(void **)a);
        }
        *(void **)a = newd;
        *(int *)(a + 8) = n;
    }
    return a;
}
