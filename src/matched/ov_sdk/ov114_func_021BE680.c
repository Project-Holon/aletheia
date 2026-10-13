/*
 * function: NHTTP_CleanupAsync
 * address:  0x021BE680
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_CleanupAsync  0x021BA988  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *
 *
 * Tears the module down, forwarding `a` as the teardown callback.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void NHTTPi_CleanupAsync(u8 *, int);

void NHTTP_CleanupAsync(int a)
{
    NHTTPi_CleanupAsync(NHTTPi_GetSystemInfoP(), a);
}
