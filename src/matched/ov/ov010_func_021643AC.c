/*
 * function: FIELD_MAP_CHANGE_ApplyZoneHeader
 * address: 0x021643AC
 * packet: pkt_ov010_021643AC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: FIELDMAP_GetZoneId reads the u16 field at +0xD8;
 * MOVE_POKEMON_SetCommonArea forwards its second argument to MOVE_POKEMON_SAVE_SetCommonArea,
 * whose matched ARM9 body takes u16 and stores only that halfword.
 * The legacy ov010_func_021643E8 declaration uses a pointer for this ID.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MOVE_POKEMON_SAVE_GetBlock 0x0200D418 thumb
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   MOVE_POKEMON_SetCommonArea 0x0215E428 thumb ov010
 *   MOVE_POKEMON_MoveActiveEntriesChecked 0x0215E3A0 thumb ov010
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_ResetEventFlag 0x0201433C thumb
 *   FIELD_ENCOUNT_ST_GetEffectEncount 0x0215E33C thumb ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *);
extern u16 FIELDMAP_GetZoneId(u8 *p);
typedef unsigned int   u32;
struct BigObj;
extern void MOVE_POKEMON_SetCommonArea(int a0, int a1);
extern void MOVE_POKEMON_MoveActiveEntriesChecked(void *);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_ResetEventFlag(char *, int);
extern int FIELD_ENCOUNT_ST_GetEffectEncount(int a0);
void FIELD_MAP_CHANGE_ApplyZoneHeader(void *a, void *b) { void *p=MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(a)); MOVE_POKEMON_SetCommonArea((int)p,FIELDMAP_GetZoneId(b)); MOVE_POKEMON_MoveActiveEntriesChecked(a); ZONEDATA_ResetEventFlag((char *)GAME_DATA_GetEventWork(a),0x964); FIELD_ENCOUNT_ST_GetEffectEncount((int)b); }
