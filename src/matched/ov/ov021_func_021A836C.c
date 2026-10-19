/*
 * function: FIELD_MENU_Create
 * address:  0x021A836C
 * packet:   pkt_ov021_021A836C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gFieldMenuFileName     0x021DDF94  data  ov021  a1
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   func_020355C4  0x020355C4  arm
 *   func_020056A0  0x020056A0  thumb
 *   FIELD_MENU_ColorTask  0x021A8D40  thumb  ov021
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_020490F4  0x020490F4  arm
 *   FIELD_MENU_GetLayoutType  0x021A8B18  thumb  ov021
 *   FIELD_MENU_LoadGraphics  0x021A8874  thumb  ov021
 *   FIELD_MENU_CreateItems  0x021A8BB8  thumb  ov021
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   FIELD_MENU_UpdateSelection  0x021A90E0  thumb  ov021
 *   FIELD_MENU_SetScrolledOut  0x021A8DD8  thumb  ov021
 *   GAME_DATA_GetFrameRate  0x020129C4  thumb
 *   FIELD_MENU_SelectButton  0x021A8E20  thumb  ov021
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *
 * 0x021DDF94 is the "field_menu.c" file-name string; 0x134 is its line.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    int f08;
    int f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[2];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item items[7];
    int fF8;
    u16 fFC;
    u8 padFE[2];
    int f100;
    u8 pad104[0x124 - 0x104];
    u32 f124;
    u32 f128;
    void *f12C;
    void *f130;
    u32 f134;
} Obj;

extern char gFieldMenuFileName[];

struct W;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct BigObj;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern unsigned char *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
extern unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u8 func_020355C4(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void FIELD_MENU_ColorTask(void *unused, struct W *w);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 FIELD_MENU_GetLayoutType(void *a, void *b, u32 c);
extern void FIELD_MENU_LoadGraphics(struct Obj *p, void *q, int r, u32 unused);
extern void FIELD_MENU_CreateItems(struct Obj *p, void *q, int r);
extern void ARC_TOOL_DeleteHandle(void *q);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void FIELD_MENU_UpdateSelection(struct W *w);
extern void FIELD_MENU_SetScrolledOut(Obj *p);
extern u8 GAME_DATA_GetFrameRate(const struct BigObj *p);
extern void FIELD_MENU_SelectButton(struct W *w, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);

Obj *FIELD_MENU_Create(u16 heap, u16 a1, int a2, void *a3, int a4)
{
    Obj *p;
    u32 x;
    u32 y;
    void *q;
    u32 r;

    p = func_02030734(heap, 0x138, 0, gFieldMenuFileName, 0x134);
    x = (u32)FIELDMAP_GetGameSystem(a3);
    y = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)x);
    p->f00 = heap;
    p->f02 = a1;
    p->f04 = a3;
    p->f08 = a2;
    p->f0C = 1;
    p->f1C = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)x));
    p->f14 = GAME_DATA_GetEventWork((const struct BigObj *)y);
    p->f18 = (u32)GAME_DATA_GetMyStatus((void *)y);
    p->f10 = FIELDMAP_GetMsgBg(a3);
    p->f1E = 0;
    p->f1F = 0;
    p->f24 = p->f2C = func_020355C4() ^ 1;
    p->fF8 = 0;
    p->f130 = func_020056A0(FIELD_MENU_ColorTask, p, 0);
    p->f12C = (void *)PRINTSYS_QUE_Create((void *)p->f00);
    p->f100 = 0;
    p->fFC = 0;
    q = func_020490F4(0x47, p->f02);
    r = FIELD_MENU_GetLayoutType((void *)y, (void *)p->f14, p->f1C);
    p->f21 = r;
    FIELD_MENU_LoadGraphics(p, q, r, p->f10);
    FIELD_MENU_CreateItems(p, q, r);
    ARC_TOOL_DeleteHandle(q);
    func_02040588(1, 1);
    if (a4 == 1) {
        p->f1E = 0;
        p->f1F = 0;
        p->f24 = 1;
        FIELD_MENU_UpdateSelection((struct W *)p);
        FIELD_MENU_SetScrolledOut(p);
    } else {
        FIELD_MENU_SelectButton((struct W *)p, GAME_DATA_GetFrameRate((const struct BigObj *)y));
        p->f24 = 1;
        if (p->f2C != 0) {
            CLACT_SetActorDrawEnable((struct Obj *)p->f124, 1);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)p->f124, 0);
        }
    }
    GFL_NET_RefreshWmIconAtTopRight(0, p->f02);
    return p;
}
