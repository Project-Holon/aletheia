/*
 * function: FIELD_MENU_Update
 * address:  0x021A85B4
 * packet:   pkt_ov021_021A85B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   FIELD_SUBSCREEN_LoadBackdrop  0x021A12D4  thumb  ov021
 *   FIELD_MENU_ShowItemWindow  0x021A9294  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_MENU_ShowBgLayers  0x021A8588  thumb  ov021
 *   FIELD_MENU_UpdateActorsForScroll  0x021A87A8  thumb  ov021
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   FIELD_MENU_HandleKeys  0x021A8EEC  thumb  ov021
 *   FIELD_MENU_HandleTouch  0x021A8FFC  thumb  ov021
 *   FIELD_MENU_UpdateSelection  0x021A90E0  thumb  ov021
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   func_02040588  0x02040588  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   FIELD_MENU_PlaceCursor  0x021A9080  thumb  ov021
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   FIELD_SUBSCREEN_SetPanelResult  0x021A0FA0  thumb  ov021
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
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

typedef struct Sel {
    u8 pad00[0x14];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    int f18;
} Sel;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    void *f08;
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
    Sel *fF8;
    s16 fFC;
    u8 padFE[2];
    int f100;
    u8 pad104[0x124 - 0x104];
    u32 f124;
    u32 f128;
    void *f12C;
    void *f130;
} Obj;

struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void FIELD_SUBSCREEN_LoadBackdrop(u32 *p, u32 x);
extern void FIELD_MENU_ShowItemWindow(Obj *p, Item *it);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern int FIELD_MENU_ShowBgLayers();
extern void FIELD_MENU_UpdateActorsForScroll(Obj *p);
extern u32 WIPE_SYS_EndCheck(void);
extern void FIELD_MENU_HandleKeys(Obj *p);
struct W;
extern void FIELD_MENU_HandleTouch(struct W *w);
extern void FIELD_MENU_UpdateSelection(struct W *w);
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void FIELD_MENU_PlaceCursor(Obj *p, u8 a, u8 b);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void FIELD_SUBSCREEN_SetPanelResult(int *p, int v);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

u32 FIELD_MENU_Update(Obj *p)
{
    u8 i;
    s16 v;
    Sel *s;

    switch (p->f0C) {
    case 1:
        if (PRINTSYS_QUE_IsFinished(p->f12C) == 1) {
            FIELD_SUBSCREEN_LoadBackdrop(p->f08, p->f02);
            for (i = 0; i < 7; i++) {
                FIELD_MENU_ShowItemWindow(p, &p->items[i]);
            }
            if (p->fFC != 0) {
                GFL_USE_PlaySeDefaultVolume(0x554);
                p->f0C = 0;
            } else {
                p->f0C = 2;
                FIELD_MENU_ShowBgLayers();
            }
        }
        break;
    case 0:
        v = p->fFC;
        if (v < 0x40) {
            p->fFC = 0;
            p->f0C = 3;
            FIELD_MENU_ShowBgLayers();
        } else {
            p->fFC = v - 0x40;
            FIELD_MENU_UpdateActorsForScroll(p);
        }
        p->f100 = 1;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1) {
            FIELD_SUBSCREEN_LoadBackdrop(p->f08, p->f02);
            p->f0C = 3;
        }
        break;
    case 3:
        FIELD_MENU_HandleKeys(p);
        FIELD_MENU_HandleTouch((struct W *)p);
        FIELD_MENU_UpdateSelection((struct W *)p);
        break;
    case 4:
        if (CLACT_IsActorAnimActive((struct Actor *)p->f128) != 0) {
            break;
        }
        p->f0C = 5;
        func_02040588(5, 1);
        func_02040588(6, 1);
        func_02040588(7, 1);
        func_02040588(4, 1);
        break;
    case 5:
        if (p->f28 == 1 || p->f1F == 3) {
            p->f0C = 9;
            GFL_USE_PlaySeDefaultVolume(0x556);
            func_02040588(4, 0);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02040588(7, 1);
            CLACT_SetActorDrawEnable((struct Obj *)p->f128, 0);
        } else {
            s = p->fF8;
            if (s->f18 != 0) {
                p->f20 = 0;
                FIELD_MENU_PlaceCursor(p, s->f14, s->f15);
                CLACT_SetActorAnimSeq((struct Obj *)p->f124, 1);
                CLACT_SetActorDrawEnable((struct Obj *)p->f124, 1);
                p->f0C = 6;
                GFL_USE_PlaySeDefaultVolume(0x54C);
            } else {
                p->f0C = 8;
            }
        }
        break;
    case 6:
        p->f20++;
        if (CLACT_IsActorAnimActive((struct Actor *)p->f124) == 0) {
            p->f0C = 8;
        }
        break;
    case 7:
        FIELD_SUBSCREEN_SetPanelResult(p->f08, 4);
        p->f0C = 10;
        break;
    case 8:
        FIELD_SUBSCREEN_SetPanelResult(p->f08, 3);
        p->f0C = 10;
        break;
    case 9:
        if (p->fFC + 0x40 > 0xC0) {
            p->fFC = 0xC0;
            p->f0C = 7;
        } else {
            p->fFC += 0x40;
            FIELD_MENU_UpdateActorsForScroll(p);
        }
        p->f100 = 1;
        break;
    }
    return PRINTSYS_QUE_Main(p->f12C);
}
