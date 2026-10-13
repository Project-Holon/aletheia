/*
 * function: func_021BCB70
 * address: 0x021BCB70
 * packet: pkt_ov099_021BCB70
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 */
typedef unsigned int u32;
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *);
extern int POKE_REGULATION_CheckParty(void *, void *, u32 *);
int func_021BCB70(void *rules, const struct BigObj *obj, u32 *mask)
{
    *mask = 0;
    return POKE_REGULATION_CheckParty(rules, GAME_DATA_GetMyParty(obj), mask);
}
