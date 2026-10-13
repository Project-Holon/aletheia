/*
 * function: CRYPTOi__BN_RECP_CTX_init
 * address:  0x021CCA5C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CRYPTOi__BN_init  0x021CACD0  arm  ov114
 *
 *
 * Releases both halves of the pair at p and p+0x14, then clears two words.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void CRYPTOi__BN_init(int a);

void CRYPTOi__BN_RECP_CTX_init(u8 *p)
{
    CRYPTOi__BN_init((int)p);
    CRYPTOi__BN_init((int)(p + 0x14));
    *(u32 *)(p + 0x28) = 0;
    *(u32 *)(p + 0x30) = 0;
}
