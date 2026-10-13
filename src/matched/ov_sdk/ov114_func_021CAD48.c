/*
 * function: CRYPTOi__BN_CTX_init
 * address:  0x021CAD48
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Clears a 0x110-byte record and both of its end markers.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, int);

void CRYPTOi__BN_CTX_init(u8 *p)
{
    MI_CpuFill8(p, 0, 0x110);
    *(u32 *)p = 0;
    *(u32 *)(p + 0x108) = 0;
}
