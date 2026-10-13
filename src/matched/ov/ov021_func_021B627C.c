/*
 * function: SCRCMD_POKEMON_FLD_CheckPartyFlagged
 * address:  0x021B627C
 * packet:   pkt_ov021_021B627C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *a);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);

int SCRCMD_POKEMON_FLD_CheckPartyFlagged(u32 a, u32 b)
{
    u16 *o;
    void *lst;
    u32 n;
    u32 i;

    o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *o = 0;
    lst = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData((void *)b));
    n = func_0201AA18(lst);
    for (i = 0; i < n; i++) {
        if (POKE_TOOL_GetPartyValue(func_0201AB28(lst, i), 0x97, 0) != 0) {
            *o = 1;
            break;
        }
    }
    return 0;
}
