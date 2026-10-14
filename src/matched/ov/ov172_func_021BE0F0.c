/*
 * function: COMM_TVT_SYS_ClearHostBusy
 * address:  0x021BE0F0
 * packet:   pkt_ov172_021BE0F0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void COMM_TVT_SYS_ClearHostBusy(u8 *c)
{
    *(u32 *)(c + 0x30) = 0;
}
