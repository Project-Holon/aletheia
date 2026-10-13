/*
 * function: SCRCMD_POKEMON_FLD_GetRandomBagPocketValue
 * address:  0x021B6590
 * packet:   pkt_ov021_021B6590
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
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007FA0  0x02007FA0  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_020081DC  0x020081DC  thumb
 *   func_020212B0  0x020212B0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 func_02007FA0(u8 *base, u32 id);
extern u32 func_020056EC(u32);
extern u16 *func_020081DC(void *, int, u16);
extern u16 func_020212B0(u16);

u32 SCRCMD_POKEMON_FLD_GetRandomBagPocketValue(void *a, void *b)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a, b);
    void *sv = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(b));
    int k = 2;
    u32 t = func_02007FA0(sv, 2);
    u32 id = func_020056EC(t);
    u16 v;

    if (t == 0)
        v = 0;
    else
        v = func_020212B0(*func_020081DC(sv, k, id));
    *out = v;
    return 0;
}
