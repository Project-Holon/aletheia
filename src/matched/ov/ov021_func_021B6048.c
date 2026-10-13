/*
 * function: SCRCMD_POKEMON_FLD_FindTutorCandidates
 * address:  0x021B6048
 * packet:   pkt_ov021_021B6048
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SCRCMD_POKEMON_FLD_CheckTutorGroup  0x021B5FB8  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetTutorFriendship  0x021B5FB4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int SCRCMD_POKEMON_FLD_CheckTutorGroup(u32 a, int sel);
extern int SCRCMD_POKEMON_FLD_GetTutorFriendship(u32 a);

int SCRCMD_POKEMON_FLD_FindTutorCandidates(u32 a, u32 b, u32 key, u8 *mask, u32 flag)
{
    void *lst;
    int n;
    int i;
    int found;
    int all;
    u32 item;

    lst = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData((void *)b));
    n = POKEPARTY_GetCount(lst);
    found = 0;
    all = 0;
    *mask = found;
    for (i = 0; i < n; i++) {
        item = (u32)POKEPARTY_GetMember(lst, i);
        if (POKE_TOOL_GetPartyValue((void *)item, 0x4c, 0) == 1)
            continue;
        if (SCRCMD_POKEMON_FLD_CheckTutorGroup(item, key) == 0)
            continue;
        found = 1;
        if (flag != 0) {
            item = POKE_TOOL_GetPartyValue((void *)item, 9, 0);
            if (item < SCRCMD_POKEMON_FLD_GetTutorFriendship(key))
                continue;
        }
        all = 1;
        *mask = *mask | (u8)(1 << i);
    }
    if (found == 0)
        return 1;
    if (all == 0)
        return 2;
    return 0;
}
