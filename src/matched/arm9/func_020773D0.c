/*
 * function: CARDi_GetRomCacheBuffer
 * address:  0x020773D0
 * packet:   pkt_020773D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0215086C  0x0215086C  data
 *
 * Getter returning the address of a global (CARDi_GetOwnSignature).  Called
 * from the ov107 segment reader 0x021F2FA0.
 */

extern char g_0215086C[];

void *CARDi_GetRomCacheBuffer(void)
{
    return g_0215086C;
}
