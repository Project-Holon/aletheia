/*
 * function: DWCi_Ndi_strncmp
 * address:  0x021C7A24
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
 *   strncmp  0x020949F4  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void strncmp(void);

void DWCi_Ndi_strncmp(void)
{
    strncmp();
}
