/*
 * function: COMM_PLAYER_SUPPORT_GetInfoCode
 * address:  0x0202E83C
 * packet:   pkt_0202E79C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetAreaSlotFlag  0x02158468  thumb
 */
typedef unsigned int   u32;
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetAreaSlotFlag(int a0);

int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0)
{
    return INTRUDE_COMM_GetAreaSlotFlag(GAMESYSTEM_GetGameComm(a0));
}
