/*
 * function: WIFICLUB_LoadSavedRegulation
 * address: 0x021BCB8C
 * packet: pkt_ov099_021BCB8C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow at 0x021BCBAE.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_HasMon 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 */
typedef unsigned int u32;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern u32 BATTLE_BOX_HasMon(void *);
extern void *func_0200BAF4(int a0, int a1);
int WIFICLUB_LoadSavedRegulation(void *p)
{
    void *obj = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(p));
    if (BATTLE_BOX_HasMon(obj) == 0) return 0;
    return (int)func_0200BAF4((int)obj, 0x21);
}
