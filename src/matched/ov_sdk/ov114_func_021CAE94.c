/*
 * function: CRYPTOi__BN_clear
 * address:  0x021CAE94
 * packet:   pkt_ov114_021CAE94
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_clear (crypto_bobj1.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, unsigned long);

void CRYPTOi__BN_clear(u8 *p)
{
    if (*(void **)p != 0)
        MI_CpuFill8(*(void **)p, 0, *(u32 *)(p + 8) * 4);
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0xc) = 0;
}
