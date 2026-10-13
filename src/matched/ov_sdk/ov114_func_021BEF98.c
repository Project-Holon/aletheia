/*
 * function: NHTTPi_InitMutexInfo
 * address:  0x021BEF98
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Clears the word at +0x18.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void NHTTPi_InitMutexInfo(u8 *p)
{
    *(u32 *)(p + 0x18) = 0;
}
