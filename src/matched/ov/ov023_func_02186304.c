/*
 * function: OEKAKI_NotifyHostSync
 * address: 0x02186304
 * packet: pkt_ov023_02186304
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x02186320.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   OEKAKI_GetJoinedCount 0x0218654C thumb ov023
 *   OEKAKI_OpenGroup 0x02184560 thumb ov023
 * Caller explicitly sets r1 for OEKAKI_OpenGroup, retained despite its legacy one-argument definition.
 */
extern unsigned short GFL_NET_SYSTEM_GetCurrentAid(void);
extern int OEKAKI_GetJoinedCount(char *p);
extern void OEKAKI_OpenGroup(char *, int);
void OEKAKI_NotifyHostSync(char *p, int a)
{
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        OEKAKI_GetJoinedCount(p);
        OEKAKI_OpenGroup(p, a);
    }
}
