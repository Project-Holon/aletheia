/*
 * function: func_021CABDC
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
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021CAAE8(void *);

void func_021CABDC(u8 *p)
{
    if (p == 0)
        return;
    if (*(u32 *)p != 0 && !(*(u32 *)(p + 0x10) & 2))
        func_021CAAE8(*(void **)p);
    *(u32 *)(p + 0x10) |= 0x8000;
    if (*(u32 *)(p + 0x10) & 1)
        func_021CAAE8(p);
}
