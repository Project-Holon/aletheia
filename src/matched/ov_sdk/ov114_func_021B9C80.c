/*
 * function: NHTTPi_SetSSLseed
 * address:  0x021B9C80
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNHTTPSslSeed  0x021CF964  data
 *   OS_GetLowEntropyData  0x02088168  arm  arm9
 *   CPS_SslAddRandomSeed  0x02162248  arm  ov009
 *
 *
 * Overlay init hook: open then size the 0x021CF964 work block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void OS_GetLowEntropyData(u32 *buffer);
extern void CPS_SslAddRandomSeed(void *, int);
extern u8 gNHTTPSslSeed[];

void NHTTPi_SetSSLseed(void)
{
    OS_GetLowEntropyData((u32 *)gNHTTPSslSeed);
    CPS_SslAddRandomSeed(gNHTTPSslSeed, 0x20);
}
