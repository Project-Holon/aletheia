/*
 * function: FIELD_PLACE_NAME_LoadZoneFromSave
 * address:  0x021BD0E0
 * packet:   pkt_ov021_021BD0E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008998  0x02008998  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 */

typedef unsigned short u16;

typedef struct {
    void *f0;
    char pad[0x42];
    u16 h46;
} Obj;

struct Big;
struct Ctx;
struct Sub02008828Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008998(const struct Sub02008828Obj *obj);

void FIELD_PLACE_NAME_LoadZoneFromSave(Obj *p)
{
    p->h46 = func_02008998(func_02008854(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(p->f0))));
}
