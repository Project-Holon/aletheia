/*
 * function: FIELD_SUBSCREEN_ExitMenu
 * address:  0x021A1244
 * packet:   pkt_ov021_021A1244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FIELD_MENU_GetLayoutType  0x021A8B18  thumb  ov021
 *   INFOWIN_Exit  0x02024DCC  thumb
 *   FIELD_MENU_Delete  0x021A84BC  thumb  ov021
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
struct BigObj;
struct Ctx;
struct Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
struct Ctx;
extern unsigned char *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
extern unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 FIELD_MENU_GetLayoutType(void *a, void *b, u32 c);
extern int INFOWIN_Exit(void);
extern void FIELD_MENU_Delete(struct Obj *p);
extern void BG_SYS_FreeLayerBuf(u32);

void FIELD_SUBSCREEN_ExitMenu(u32 *p)
{
    u32 a, b, c;
    a = (u32)FIELDMAP_GetGameSystem((void *)p[5]);
    b = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a));
    c = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    if (FIELD_MENU_GetLayoutType((void *)c, (void *)GAME_DATA_GetEventWork((const struct BigObj *)c), b) != 1)
        INFOWIN_Exit();
    FIELD_MENU_Delete((struct Obj *)p[8]);
    BG_SYS_FreeLayerBuf(4);
}
