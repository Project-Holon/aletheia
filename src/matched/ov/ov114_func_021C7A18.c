/*
 * function: DWCi_Ndi_strlen
 * address:  0x021C7A18
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 *
 * symbols:
 *   strlen  0x0209477C  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int strlen(const u8 *s);

u32 DWCi_Ndi_strlen(const u8 *a0)
{
    return strlen(a0);
}
