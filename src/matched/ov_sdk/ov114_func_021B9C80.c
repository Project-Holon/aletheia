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
 *
 *
 * Overlay init hook: open then size the 0x021CF964 work block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02088168(u32 *buffer);
extern void func_02162248(void *, int);
extern u8 gNHTTPSslSeed[];

void NHTTPi_SetSSLseed(void)
{
    func_02088168((u32 *)gNHTTPSslSeed);
    func_02162248(gNHTTPSslSeed, 0x20);
}
