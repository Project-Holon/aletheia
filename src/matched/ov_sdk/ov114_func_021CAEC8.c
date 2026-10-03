/*
 * function: func_021CAEC8
 * address:  0x021CAEC8
 * packet:   pkt_ov114_021CAEC8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_set_word (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021CADAC(u8 *a, int n);

int func_021CAEC8(u8 *a, unsigned long w)
{
    u8 *A;
    A = (*(int *)(a + 8) < 1) ? func_021CADAC(a, 2) : a;
    if (A == 0)
        return 0;
    *(u32 *)(a + 0xc) = 0;
    *(u32 *)(a + 4) = 0;
    *(u32 *)*(u32 **)a = w;
    if (*(u32 *)*(u32 **)a != 0)
        *(u32 *)(a + 4) = 1;
    return 1;
}
