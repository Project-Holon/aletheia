/*
 * function: WIH_SetError
 * address: 0x0217814C
 * packet: pkt_ov014_0217814C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *gWihWork;
void WIH_SetError(int error)
{
    if ((unsigned)(*(int *)(gWihWork + 0x1e70) - 9) > 1)
        *(int *)(gWihWork + 0x1e98) = error;
}
