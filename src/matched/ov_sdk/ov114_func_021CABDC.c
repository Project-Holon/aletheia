/*
 * function: CRYPTOi__BN_free
 * address:  0x021CABDC
 * packet:   pkt_ov114_021CABDC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_free (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_MONT_CTX_free / CRYPTOi__BN_RECP_CTX_free
 *
 * symbols:
 *   CRYPTOi_MyFree  0x021CAAE8  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void CRYPTOi_MyFree(void *);

void CRYPTOi__BN_free(u8 *p)
{
    if (p == 0)
        return;
    if (*(u32 *)p != 0 && !(*(u32 *)(p + 0x10) & 2))
        CRYPTOi_MyFree(*(void **)p);
    *(u32 *)(p + 0x10) |= 0x8000;
    if (*(u32 *)(p + 0x10) & 1)
        CRYPTOi_MyFree(p);
}
