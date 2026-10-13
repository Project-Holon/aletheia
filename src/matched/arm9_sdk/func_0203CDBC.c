/*
 * function: GFL_NET_IsSessionNull
 * address:  0x0203CDBC
 * packet:   pkt_0203CDBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 */

extern void *GFL_NET_GetSession(void);

int GFL_NET_IsSessionNull(void)
{
    return GFL_NET_GetSession() == 0;
}
