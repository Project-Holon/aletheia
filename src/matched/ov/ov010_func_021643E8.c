/*
 * function: func_021643E8
 * address:  0x021643E8
 * packet:   pkt_ov010_021643E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-object setup: registers the object with the frame list, applies
 * the flag word and seeds the 177-entry table pass.
 *
 * symbols:
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   ZONEDATA_GetFieldSkillMapEffect  0x02013F6C  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   MOVE_POKEMON_SetCommonArea  0x0215E428  thumb ov010
 *   MOVE_POKEMON_MoveActiveEntries  0x0215E364  thumb ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   EVENTDATA_SYSTEM_RespawnHiddenItems  0x02164728  thumb ov010
 *   ZONEDATA_IsZoneInTableDFB8  0x02013FFC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008988  0x02008988  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct BigObj;
struct Sub02008828Obj;
struct Sub02014444Obj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u32 ZONEDATA_GetFieldSkillMapEffect(u32 id);
extern void FIELD_STATUS_SetFlashActive(struct Sub02014444Obj *o, u8 v);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200D418(void *a);
extern void MOVE_POKEMON_SetCommonArea(int a0, int a1);
extern void  MOVE_POKEMON_MoveActiveEntries(void *a);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);
extern void  EVENTDATA_SYSTEM_RespawnHiddenItems(void *a);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);

void func_021643E8(void *a, void *b)
{
    void *w = GAME_DATA_GetMoveModelSys(a);
    void *c;
    if ((ZONEDATA_GetFieldSkillMapEffect((u32)b) & 3) == 0) {
        FIELD_STATUS_SetFlashActive(w, 0);
    }
    MOVE_POKEMON_SetCommonArea((int)func_0200D418(GAME_DATA_GetSaveControl(a)), (int)b);
    MOVE_POKEMON_MoveActiveEntries(a);
    c = (void *)GAME_DATA_GetEventWork(a);
    ZONEDATA_ResetEventFlag(c, 0x964);
    EVENTDATA_SYSTEM_RespawnHiddenItems(c);
    if (ZONEDATA_IsZoneInTableDFB8((u32)b) == 0) {
        func_02008988(func_02008854(GAME_DATA_GetSaveControl(a)), 0);
    }
}
