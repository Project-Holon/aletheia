/*
 * function: SCRCMD_POKEMON_FLD_StoreMonRecord
 * address:  0x021B5B8C
 * packet:   pkt_ov021_021B5B8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0200C11C  0x0200C11C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk34;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, unsigned int a1, void **out);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void func_0200C11C(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d);

int SCRCMD_POKEMON_FLD_StoreMonRecord(void *a, void *b)
{
    void *rec;
    struct Blk34 *x;
    u16 v5, v6f, v4c, v6e;

    if (SCRCMD_PROC_GetPartyMember(b, SCRIPT_WORK_ReadWorkValue(a, b), &rec) == 1) {
        x = GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(b));
        v5 = POKE_TOOL_GetPartyValue(rec, 5, 0);
        v6f = POKE_TOOL_GetPartyValue(rec, 0x6f, 0);
        v4c = POKE_TOOL_GetPartyValue(rec, 0x4c, 0);
        v6e = POKE_TOOL_GetPartyValue(rec, 0x6e, 0);
        func_0200C11C(x, v5, v6f, v4c, v6e);
    }
    return 0;
}
