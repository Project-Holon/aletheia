/*
 * function: FIELD_SUBSCREEN_InitMenu
 * address:  0x021A11A8
 * packet:   pkt_ov021_021A11A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_ClearLayer  0x0204152C  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   FIELD_MENU_Create  0x021A836C  thumb  ov021
 *   FIELD_MENU_GetLayoutType  0x021A8B18  thumb  ov021
 *   INFOWIN_Init  0x02024A20  thumb
 *   FIELD_MENU_LoadFrameBg  0x021A8AFC  thumb  ov021
 *   d_021D8708     0x021D8708  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
extern unsigned char d_021D8708[];
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
struct Ctx;
extern unsigned char *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *);
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_ClearLayer(int channel, u16 val);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern struct Obj *FIELD_MENU_Create(u16 heap, u16 a1, int a2, void *a3, int a4);
extern u32 FIELD_MENU_GetLayoutType(void *a, void *b, u32 c);
extern void INFOWIN_Init(u8 a0, u8 a1, void *a2, u16 heap);
extern void FIELD_MENU_LoadFrameBg(int a, int b);

void FIELD_SUBSCREEN_InitMenu(u32 *p, u32 x)
{
    u32 a, b, c, d;
    u32 f;
    a = (u32)FIELDMAP_GetGameSystem((void *)p[5]);
    b = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a));
    c = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    d = GAME_DATA_GetEventWork((const struct BigObj *)c);
    f = 0;
    if (x == 0 || x - 2 <= 4)
        f = 1;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021D8708, 0);
    func_02040588(4, 1);
    BG_SYS_FreeSlot(4);
    BG_SYS_ClearLayer(4, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    p[8] = (u32)FIELD_MENU_Create(0x70, ((u16 *)p)[6], (int)p, (void *)p[5], f);
    if (FIELD_MENU_GetLayoutType((void *)c, (void *)d, b) != 1)
        INFOWIN_Init(4, 0xe, (void *)c, ((u16 *)p)[6]);
    FIELD_MENU_LoadFrameBg(((u16 *)p)[6], f);
}
