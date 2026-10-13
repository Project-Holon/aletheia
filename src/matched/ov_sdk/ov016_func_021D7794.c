/*
 * function: DWCi_TSKlOperate
 * address:  0x021D7794
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   DWCi_TSKlOperate 0x021D7794 arm
 *   gMemTask    0x021DE6E4 data
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *gMemTask;

void DWCi_TSKlOperate(u32 index, u8 val)
{
    u8 *ptr = (u8 *)gMemTask;
    ptr += index << 6;
    ptr[0x38] = val;
}
