/*
 * function: SCRCMD_POKEMON_FLD_StorePartySpeciesRecord
 * address:  0x021B5BFC
 * packet:   pkt_ov021_021B5BFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_SetTeam  0x0200C2B0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk34;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *a0);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void *GAME_DATA_GetMiscSave(int *p);
extern void MISC_SetTeam(struct Blk34 *p, u32 i, const u16 *src);

int SCRCMD_POKEMON_FLD_StorePartySpeciesRecord(void *a, void *b)
{
    u16 buf[6];
    void *sav;
    unsigned int r;
    void *bag;
    void *mon;
    int i;
    int j;
    int n;

    sav = SCRCMD_WORK_GetGameData(b);
    bag = GAME_DATA_GetMyParty(sav);
    r = SCRIPT_WORK_ReadWorkValue(a, b);
    for (i = 0; i < 6; i++)
        buf[i] = 0;
    for (j = 0, n = 0; j < (int)POKEPARTY_GetCount(bag); j++) {
        mon = POKEPARTY_GetMember(bag, j);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0)
            buf[n++] = POKE_TOOL_GetPartyValue(mon, 5, 0);
    }
    MISC_SetTeam(GAME_DATA_GetMiscSave(sav), r, buf);
    return 0;
}
