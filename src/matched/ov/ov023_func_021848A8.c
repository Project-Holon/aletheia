/*
 * function: OEKAKI_OnMemberJoined
 * address: 0x021848A8
 * packet: pkt_ov023_021848A8
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   OEKAKI_QueueCommand 0x02186860 thumb ov023
 *   OEKAKI_RegisterMetPlayers 0x021866C4 thumb ov023
 * Extent follower 0x021848CC is already matched separately.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void OEKAKI_QueueCommand(char *p, int x, int y);
extern void OEKAKI_RegisterMetPlayers(u32 *p);
void OEKAKI_OnMemberJoined(int a, int unused, char *p)
{
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
        OEKAKI_QueueCommand(p, 0x2903, a);
    OEKAKI_RegisterMetPlayers((u32 *)p);
}
