/*
 * file:     plist_plate.c
 * unit:     yes
 * function: func_021BA6A0, func_021BA81C, func_021BA890, func_021BA8CC, func_021BA954, func_021BAA50, func_021BAAE4, func_021BAB04, func_021BAE94, func_021BAF28, func_021BAFA0, func_021BB050, func_021BB0C4, func_021BB1A0, func_021BB200, func_021BB2C0, func_021BB2E0, func_021BB30C, func_021BB358, func_021BB3C4, func_021BB3D4, func_021BB3FC, func_021BB43C, func_021BB440, func_021BB464, func_021BB468, func_021BB46C, func_021BB4A0, func_021BB554, func_021BB56C
 * address:  0x021BA6A0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B878  0x0204B878  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_02030734 0x02030734 arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020450F0 0x020450F0 arm
 *   d_021BED18 0x021BED18 data ov091 a1
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020490F4  0x020490F4  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   g_020A7370     0x020A7370  data
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_020413B0  0x020413B0  arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   func_02041300  0x02041300  arm
 *   func_02043B5C  0x02043B5C  arm
 *   POKE_REGULATION_CheckPokemon 0x02019DA4 thumb
 *   func_0202D034 0x0202D034 thumb
 *   CLACT_GetSurfacePos 0x0204B0C8 arm
 *   func_021B9A84  0x021B9A84  thumb
 *   func_021B9AC8  0x021B9AC8  thumb
 *   func_021B9BF4  0x021B9BF4  thumb
 *   func_021B9C1C  0x021B9C1C  thumb
 *   func_021B9C64  0x021B9C64  thumb
 *   func_021B9CB0  0x021B9CB0  thumb
 *   func_021B9CF4  0x021B9CF4  thumb
 *   func_021B9D58  0x021B9D58  thumb
 *   func_021B9DC0  0x021B9DC0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#include "pokelist_types.h"
#include "plist_plate_types.h"

struct Obj;
struct Bank;
struct Descriptor;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Bmp;
struct CharBuf;

extern void func_0204B3DC(struct Obj *actor, unsigned int visible);
extern void func_0204B404(struct Obj *actor, const PlistPlatePos *delta, u32 which);
extern void func_0204B878(struct Obj *actor, u16 animation);
extern void func_02041B6C(u32 bit);
extern u32 func_02017E1C(void *mon, u32 id, u32 value);
extern u32 func_0202136C(u16 item);
extern u32 func_020307B0(void *mem);
extern void *func_0201AB28(void *party, u32 idx);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *window);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern struct Obj *func_0204B034(u16 *area, u32 mode, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B258(struct Bank *bank, void *unit);
extern void func_0204B09C(void *unit, int index, void *offset);
extern struct Descriptor *func_020450F0(int a0, u8 a1, u8 a2, int a3, u8 a4, u8 a5, u8 a6);
extern u32 func_020452E8(struct Descriptor *window);
extern void func_0204B3B4(struct Obj *actor);
extern void func_0204B084(void *unit);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A8D4(u32 iconResource);
extern u32 func_0201C6C4(void *printSys, void *bitmap);
extern void func_02045334(struct Descriptor *window);
extern void func_02045374(struct Descriptor *window);
extern u8 func_02045730(struct Descriptor *window);
extern u32 POKE_TOOL_GetStatusCondition(void *mon);
extern u32 CLACT_GetActorAnimFrame(struct Obj *actor);
extern struct Obj *func_0204B294(struct Bank *bank, unsigned int a1, unsigned int a2, unsigned int a3, const PlistPlateActorSpec *spec, u16 a5, u16 heapId);
extern void func_0204B92C(struct Obj *actor, unsigned int value);
extern void *func_020490F4(u32 id, u32 heapId);
extern void *POKE_TOOL_GetBoxParam(void *mon);
extern u32 func_0201BA68(void *boxMon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 d, u16 heapId);
extern void func_02049238(void *a);
extern int POKE_TOOL_GetIconPalette(void *boxMon);
extern void func_0204B6F4(struct Obj *actor, u32 palette, u32 flag);
extern struct WordSet *func_0201EC64(u32 heapId);
extern void func_0201EEF4(struct WordSet *wordSet, u32 index, void *mon);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 value, u32 digits, u32 padMode, u32 d);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern u32 POKE_TOOL_CalcLevel(void *mon);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
extern void func_02043AF4(struct Bmp *bmp, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const void *src, u32 n, u32 f, u32 c);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BMP_WIN_SetPosX(struct Descriptor *window, u8 x);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int POKE_REGULATION_CheckPokemon(void *regulation, void *mon);
extern u8 func_0202D034(u32 a, u32 b);
extern void CLACT_GetSurfacePos(struct Obj *unit, u32 index, PlistPlatePos *out);
extern int func_021B9A84(PokelistWork *work);
extern int func_021B9AC8(PokelistWork *work, void *mon, u8 bit);
extern u32 func_021B9BF4(PokelistWork *work, void *mon, u32 param);
extern void func_021B9C1C(PokelistWork *work, struct Descriptor *window, u32 id, int x, s16 y, u16 color);
extern void func_021B9C64(PokelistWork *work, struct Descriptor *window, u32 idx, u32 x, s16 y, u16 color);
extern void func_021B9CB0(PokelistWork *work, struct Descriptor *window, u32 idx, u32 x, s16 y, u16 color);
extern void func_021B9CF4(PokelistWork *work, struct Descriptor *window, struct WordSet *wordSet, u32 idx, s16 x, s16 y, u16 color);
extern void func_021B9D58(PokelistWork *work, struct Descriptor *window, struct WordSet *wordSet, u32 idx, s16 x, s16 y, u16 color);
extern void func_021B9DC0(PokelistWork *work, struct Descriptor *window, struct WordSet *wordSet, u32 idx, s16 x, s16 y, u16 color);

PlistPlate *func_021BA6A0(PokelistWork *work, int slot, void *mon);
PlistPlate *func_021BA81C(PokelistWork *work, int slot);
void func_021BA890(void *unused, PlistPlate *plate);
void func_021BA8CC(PokelistWork *work, PlistPlate *plate);
void func_021BA954(PokelistWork *work, PlistPlate *plate);
void func_021BAA50(PokelistWork *work, PlistPlate *plate);
void func_021BAAE4(PokelistWork *work, PlistPlate *plate, int isRefresh);
void func_021BAB04(PokelistWork *work, PlistPlate *plate, int isRefresh);
void func_021BAE94(PokelistWork *work, PlistPlate *plate);
void func_021BAF28(PokelistWork *work, PlistPlate *plate);
void func_021BAFA0(PokelistWork *work, PlistPlate *plate, int selected);
void func_021BB050(PokelistWork *work, PlistPlate *plate, int palette);
void func_021BB0C4(PokelistWork *work, const PlistPlate *plate, int slideX);
void func_021BB1A0(PokelistWork *work, PlistPlate *plate, int slideX);
void func_021BB200(PokelistWork *work, PlistPlate *plate, void *mon, int slideX);
void func_021BB2C0(PokelistWork *work, PlistPlate *plate);
void func_021BB2E0(PokelistWork *work, PlistPlate *plate);
void func_021BB30C(PokelistWork *work, PlistPlate *plate);
int func_021BB358(PokelistWork *work, PlistPlate *plate);
int func_021BB3C4(void *unused, PlistPlate *plate);
void func_021BB3D4(void *unused, PlistPlate *plate, PlistPlatePos *out);
void func_021BB3FC(PokelistWork *work, PlistPlate *plate, PlistPlateRect *out);
int func_021BB43C(PlistPlate *plate);
void func_021BB440(PokelistWork *work, PlistPlate *plate, int labelState);
u16 func_021BB464(PokelistWork *work, PlistPlate *plate);
int func_021BB468(PokelistWork *work, PlistPlate *plate);
void func_021BB46C(PokelistWork *work, PlistPlate *plate);
int func_021BB4A0(PokelistWork *work, PlistPlate *plate);
u8 func_021BB554(PlistPlate *plate);
void func_021BB56C(PlistPlate *plate, int x, int y, PlistPlatePos *out);


extern const char d_021BED18[];
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];
extern const u8 d_021BEC6C[];
extern const u8 d_021BEC6D[];
extern void *g_020A7370;

PlistPlate *func_021BA6A0(PokelistWork *work, int slot, void *mon)
{
    u8 x = d_021BEC74[slot * 2];
    u8 y = d_021BEC75[slot * 2];
    u8 i;
    PlistPlate *plate;
    int tileX;
    int isOther = 0;
    enum PlateKind { PLATE_KIND_LEAD, PLATE_KIND_OTHER } kind;
    PlistPlateSurface surface;
    plate = func_02030734(work->heapId, 0x44, 0, d_021BED18, 0x9f);
    plate->slot = slot;
    plate->mon = mon;
    plate->isEmpty = 0;
    plate->selected = 0;
    plate->textPending = 0;
    plate->hp = func_02017E1C(mon, POKE_TOOL_PARAM_HP, 0);
    plate->targetHp = plate->hp;
    if (slot != 0) isOther = 1;
    kind = slot != 0;
    tileX = x + 0x10;
    func_020410D0(2, (u8)tileX, y, 0x10, 6, (u32)((u8 *)work->paletteData + 0xc),
                 d_021BEC6C[kind * 2], d_021BEC6D[isOther * 2], 0x20, 0x20);
    plate->isEgg = func_02017E1C(plate->mon, POKE_TOOL_PARAM_IS_EGG, 0);
    surface.areaLeft = 0;
    surface.areaTop = 0;
    surface.areaWidth = 0x100;
    surface.areaHeight = 0xc0;
    surface.priority = 0;
    surface.bgPriority = 0;
    plate->clactUnit = func_0204B034(&surface.areaLeft, 1, work->heapId);
    plate->clactBank = func_0204B100(6, 0, work->heapId);
    func_0204B258(plate->clactBank, plate->clactUnit);
    func_021BA954(work, plate);
    func_021BAA50(work, plate);
    surface.offsetX = -x * 8;
    surface.offsetY = -y * 8;
    func_0204B09C(plate->clactUnit, 0, &surface);
    plate->window = func_020450F0(1, tileX, (u8)y, 0x10, 6, 0xd, 1);
    func_021BB46C(work, plate);
    if (func_021B9A84(work) == 1) {
        for (i = 0; i < 6; i++) {
            if (plate->slot + 1 == work->arg->slotOrder[i]) plate->labelState = i;
        }
    }
    func_021BAFA0(work, plate, 0);
    func_021BAAE4(work, plate, 0);
    return plate;
}

PlistPlate *func_021BA81C(PokelistWork *work, int slot)
{
    PlistPlate *plate = func_02030734(work->heapId, 0x44, 0, d_021BED18, 0xea);
    u8 *palette = (u8 *)work->paletteData + 0xc;

    func_020410D0(2, (u8)(d_021BEC74[slot * 2] + 0x10), d_021BEC75[slot * 2], 0x10, 6,
                  (u32)palette, 0, 0x13, 0x20, 0x20);
    plate->slot = slot;
    plate->mon = 0;
    plate->isEmpty = 1;
    plate->labelState = PLIST_PLATE_LABEL_NONE;
    func_02041B6C(2);
    return plate;
}

void func_021BA890(void *unused, PlistPlate *plate)
{
    if (!plate->isEmpty) {
        func_020452E8(plate->window);
        func_0204B3B4(plate->monIconActor);
        func_0204B3B4(plate->frameActor);
        func_0204B3B4(plate->hpBarActor);
        func_0204B084(plate->clactUnit);
        func_0204B1CC(plate->clactBank);
        func_0204A8D4(plate->iconResource);
    }
    func_020307B0(plate);
}

void func_021BA8CC(PokelistWork *work, PlistPlate *plate)
{
    PlistPlatePos offset;
    if (plate->isEmpty != 0)
        return;
    if (plate->textPending == 1) {
        void *bitmap = func_02045770(plate->window);
        if (func_0201C6C4(work->printSys, bitmap) == 0) {
            /* stand-in: the original reuses the work argument for the window pointer;
               a separate local swaps the r4 and r5 assignment. */
            work = (PokelistWork *)plate->window;
            plate->textPending = 0;
            func_02045334((struct Descriptor *)work);
            func_02045374((struct Descriptor *)work);
            func_02041B6C(func_02045730((struct Descriptor *)work));
        }
    }
    if (plate->selected == 1 && POKE_TOOL_GetStatusCondition(plate->mon) == 0 && plate->hp != 0) {
        func_021BB56C(plate, 0x1a, 0x13, &offset);
        if (CLACT_GetActorAnimFrame(plate->monIconActor) == 1)
            offset.y = offset.y - 6;
        func_0204B404(plate->monIconActor, &offset, 0);
    }
}

void func_021BA954(PokelistWork *work, PlistPlate *plate)
{
    PlistPlateActorSpec frameSpec;
    PlistPlateActorSpec hpBarSpec;
    PlistPlateActorSpec itemSpec;
    PlistPlateActorSpec statusSpec;
    struct Obj *actor;
    frameSpec.x = 16;
    frameSpec.y = 16;
    frameSpec.depth = 0;
    frameSpec.animation = 1;
    frameSpec.bgPriority = 2;
    actor = func_0204B294(plate->clactBank, work->palRes[1], work->charRes[0], work->cellRes[1], &frameSpec, 0, work->heapId);
    plate->frameActor = actor;
    func_0204B92C(actor, 1);
    hpBarSpec.x = 0x54;
    hpBarSpec.y = 0x1c;
    hpBarSpec.depth = 0;
    hpBarSpec.animation = 0;
    hpBarSpec.bgPriority = 2;
    plate->hpBarActor = func_0204B294(plate->clactBank, work->palRes[6], work->charRes[5], work->cellRes[6], &hpBarSpec, 0, work->heapId);
    itemSpec.x = 32;
    itemSpec.y = 24;
    itemSpec.depth = 0;
    itemSpec.animation = 0;
    itemSpec.bgPriority = 2;
    actor = func_0204B294(plate->clactBank, work->palRes[3], work->charRes[2], work->cellRes[3], &itemSpec, 0, work->heapId);
    plate->itemIconActor = actor;
    func_0204B3DC(actor, 0);
    statusSpec.x = 32;
    statusSpec.y = 42;
    statusSpec.depth = 0;
    statusSpec.animation = 0;
    statusSpec.bgPriority = 2;
    actor = func_0204B294(plate->clactBank, work->palRes[5], work->charRes[4], work->cellRes[5], &statusSpec, 0, work->heapId);
    plate->statusIconActor = actor;
    func_0204B3DC(actor, 0);
}

void func_021BAA50(PokelistWork *work, PlistPlate *plate)
{
    void *iconFile;
    void *boxMon;
    int palette;
    PlistPlateActorSpec spec;
    iconFile = func_020490F4(7, work->heapId);
    boxMon = POKE_TOOL_GetBoxParam(func_0201AB28(work->arg->party, plate->slot));
    plate->iconResource = func_0204A6C8(iconFile, func_0201BA68(boxMon), 0, 0, work->heapId);
    func_02049238(iconFile);
    palette = POKE_TOOL_GetIconPalette(boxMon);
    spec.x = 0x18;
    spec.y = 0x10;
    spec.depth = 1;
    spec.animation = 0;
    spec.bgPriority = 2;
    {
        struct Obj *actor = func_0204B294(plate->clactBank, plate->iconResource, work->charRes[6],
                                          work->cellRes[7], &spec, 0, work->heapId);
        plate->monIconActor = actor;
        func_0204B6F4(actor, palette, 1);
    }
    func_0204B92C(plate->monIconActor, 1);
}

void func_021BAAE4(PokelistWork *work, PlistPlate *plate, int isRefresh)
{
    if (plate->isEgg == 0) {
        func_021BAB04(work, plate, isRefresh);
        func_021BAE94(work, plate);
    } else
        func_021BAF28(work, plate);
}

void func_021BAB04(PokelistWork *work, PlistPlate *plate, int isRefresh)
{
    int isTeachMode = 0;
    struct WordSet *wordSet;
    struct WordSet *wordSetB;
    struct WordSet *wordSetC;
    u32 msgId;
    u32 label;
    u32 heldItem;
    u32 hpBarColor;
    u32 value;
    u16 iconAnim;
    PokelistArg *arg;
    if (work->arg->mode == PLIST_PLATE_MODE_BATTLE_ORDER || work->restoreMode18 == 1) {
        isTeachMode = 1;
    }
    if (isRefresh == 0) {
        wordSet = func_0201EC64(work->heapId);
        func_0201EEF4(wordSet, 0, plate->mon);
        func_021B9CF4(work, plate->window, wordSet, 3, 0x29, 9, 0x440);
        func_0201ED04(wordSet);
    }
    if (isRefresh == 0) {
        if (func_02017E1C(plate->mon, POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN, 0) == 1) {
            value = func_02017E1C(plate->mon, POKE_TOOL_PARAM_GENDER, 0);
            if (value == 0) {
                func_021B9C1C(work, plate->window, PLIST_PLATE_MSG_GENDER_MALE, 0x69, 9, 0x14c0);
            } else if (value == 1) {
                func_021B9C1C(work, plate->window, PLIST_PLATE_MSG_GENDER_FEMALE, 0x69, 9, 0xc80);
            }
        }
    }
    if (isTeachMode == 0) {
        if ((POKE_TOOL_GetStatusCondition(plate->mon) == 0 && plate->hp != 0) || plate->labelState != PLIST_PLATE_LABEL_NONE) {
            wordSetB = func_0201EC64(work->heapId);
            func_0201EFA4(wordSetB, 0, POKE_TOOL_CalcLevel(plate->mon), 3, 0, 1);
            if (isRefresh == 0) {
                func_021B9D58(work, plate->window, wordSetB, 2, 9, 0x23, 0x440);
            } else {
                func_021B9DC0(work, plate->window, wordSetB, 2, 9, 0x23, 0x440);
            }
            func_0201ED04(wordSetB);
            func_0204B3DC(plate->statusIconActor, 0);
        } else {
            if (plate->hp == 0) {
                func_0204B878(plate->statusIconActor, 6);
            } else {
                switch (POKE_TOOL_GetStatusCondition(plate->mon)) {
                case 1: func_0204B878(plate->statusIconActor, 1); break;
                case 2: func_0204B878(plate->statusIconActor, 3); break;
                case 3: func_0204B878(plate->statusIconActor, 2); break;
                case 4: func_0204B878(plate->statusIconActor, 5); break;
                case 5: func_0204B878(plate->statusIconActor, 4); break;
                }
            }
            func_0204B3DC(plate->statusIconActor, 1);
        }
    }
    label = plate->labelState;
    if (label != PLIST_PLATE_LABEL_NONE) {
        if (label == PLIST_PLATE_LABEL_NOT_ELIGIBLE) {
            label = PLIST_PLATE_MSG_NOT_ELIGIBLE;
        } else if (label == PLIST_PLATE_LABEL_ELIGIBLE) {
            label = PLIST_PLATE_MSG_ELIGIBLE;
        } else {
            label = label + PLIST_PLATE_MSG_ORDER_FIRST;
        }
        func_021B9C1C(work, plate->window, (u16)label, 0x2e, 0x1f, 0x440);
        func_0204B3DC(plate->hpBarActor, 0);
    } else if (isTeachMode == 1) {
        switch (func_021B9AC8(work, plate->mon, plate->slot)) {
        case 0:
        case 1: msgId = PLIST_PLATE_MSG_TEACH_ABLE; break;
        case 2: msgId = PLIST_PLATE_MSG_TEACH_KNOWN; break;
        case 3: msgId = PLIST_PLATE_MSG_TEACH_NOT_ABLE; break;
        }
        func_021B9C1C(work, plate->window, (u16)msgId, 0x1d, 0x1f, 0x440);
        func_0204B3DC(plate->hpBarActor, 0);
    } else {
        arg = work->arg;
        if (arg->mode == PLIST_PLATE_MODE_EVOLVE_ITEM) {
            value = func_021B9BF4(work, plate->mon, arg->itemId);
            label = PLIST_PLATE_MSG_EVOLVE_NOT_ABLE;
            if (value != 0) {
                label = PLIST_PLATE_MSG_EVOLVE_ABLE;
            }
            func_021B9C1C(work, plate->window, (u16)label, 0x2e, 0x1f, 0x440);
            func_0204B3DC(plate->hpBarActor, 0);
        } else {
            wordSetB = func_0201EC64(work->heapId);
            func_0201EFA4(wordSetB, 0, func_02017E1C(plate->mon, POKE_TOOL_PARAM_MAX_HP, 0), 3, 0, 1);
            if (isRefresh == 0) {
                func_021B9D58(work, plate->window, wordSetB, 4, 0x5b, 0x23, 0x440);
            } else {
                func_021B9DC0(work, plate->window, wordSetB, 4, 0x5b, 0x23, 0x440);
            }
            func_0201ED04(wordSetB);
            wordSetC = func_0201EC64(work->heapId);
            func_0201EFA4(wordSetC, 0, plate->hp, 3, 1, 1);
            if (isRefresh == 0) {
                func_021B9D58(work, plate->window, wordSetC, 5, 0x39, 0x23, 0x440);
            } else {
                func_021B9DC0(work, plate->window, wordSetC, 5, 0x39, 0x23, 0x440);
            }
            func_0201ED04(wordSetC);
            if (isRefresh == 0) {
                func_021B9C64(work, plate->window, 6, 0x52, 0x23, 0x440);
            } else {
                func_021B9CB0(work, plate->window, 6, 0x52, 0x23, 0x440);
            }
        }
    }
    heldItem = func_02017E1C(plate->mon, POKE_TOOL_PARAM_HELD_ITEM, 0);
    if (heldItem != 0) {
        func_0204B3DC(plate->itemIconActor, 1);
        if (func_0202136C(heldItem) == 1) {
            func_0204B878(plate->itemIconActor, 1);
        } else {
            func_0204B878(plate->itemIconActor, 0);
        }
    } else {
        func_0204B3DC(plate->itemIconActor, 0);
    }
    hpBarColor = func_021BB554(plate);
    iconAnim = 1;
    if (hpBarColor == PLIST_PLATE_HPBAR_FULL) {
        iconAnim = 0;
    } else if (POKE_TOOL_GetStatusCondition(plate->mon) != 0) {
        iconAnim = 5;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_GREEN) {
        iconAnim = 4;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_YELLOW) {
        iconAnim = 3;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_RED) {
        iconAnim = 2;
    }
    func_0204B878(plate->monIconActor, iconAnim);
    plate->textPending = 1;
}

void func_021BAE94(PokelistWork *work, PlistPlate *plate)
{
    u8 hpBarColor;
    int paletteA;
    int paletteB;
    int filledDots;
    struct Bmp *bitmap;
    if (func_021B9A84(work) != 0)
        return;
    if (work->arg->mode == PLIST_PLATE_MODE_BATTLE_ORDER)
        return;
    hpBarColor = func_021BB554(plate);
    filledDots = func_0202D01C(plate->hp, func_02017E1C(plate->mon, POKE_TOOL_PARAM_MAX_HP, 0), 0x30);
    bitmap = func_02045770(plate->window);
    if (hpBarColor == PLIST_PLATE_HPBAR_GREEN || hpBarColor == PLIST_PLATE_HPBAR_FULL) {
        paletteA = 0xe;
        paletteB = 0xf;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_YELLOW) {
        paletteA = 0xc;
        paletteB = 0xd;
    } else {
        paletteA = 0xa;
        paletteB = 0xb;
    }
    func_02043AF4(bitmap, 0x3d, 0x1b, filledDots, 1, paletteA);
    func_02043AF4(bitmap, 0x3d, 0x1c, filledDots, 1, paletteB);
    func_0204B3DC(plate->hpBarActor, 1);
}

void func_021BAF28(PokelistWork *work, PlistPlate *plate)
{
    struct WordSet *wordSet;
    void *eggText;
    wordSet = func_0201EC64(work->heapId);
    eggText = func_02045EC0(g_020A7370, PLIST_PLATE_MSG_EGG);
    func_0201EE0C(wordSet, 0, eggText, 0, 1, 2);
    func_021B9CF4(work, plate->window, wordSet, 3, 0x29, 9, 0x440);
    func_02045808(eggText);
    func_0201ED04(wordSet);
    func_0204B3DC(plate->hpBarActor, 0);
    func_0204B878(plate->monIconActor, 1);
    plate->textPending = 1;
}

static inline PlistPlatePos *getActorOffset(PlistPlate *plate, int x, int y, PlistPlatePos *buf)
{
    func_021BB56C(plate, x, y, buf);
    return buf;
}

void func_021BAFA0(PokelistWork *work, PlistPlate *plate, int selected)
{
    PlistPlatePos selectedOffset;
    PlistPlatePos normalOffset;
    PlistPlatePos *offset;
    if (selected == 1) {
        if (work->phase == PLIST_PLATE_PHASE_SWAP || work->phase == PLIST_PLATE_PHASE_HEAL)
            func_021BB050(work, plate, 8);
        else if (func_021B9A84(work) == 1 && plate->labelState < 6)
            func_021BB050(work, plate, 8);
        else
            func_021BB050(work, plate, 6);
        func_0204B878(plate->frameActor, 1);
        offset = getActorOffset(plate, 0x1a, 0x13, &selectedOffset);
    } else {
        if ((work->phase == PLIST_PLATE_PHASE_SWAP && work->swapSourceSlot == plate->slot) ||
            (work->phase == PLIST_PLATE_PHASE_HEAL && work->healSourceSlot == plate->slot))
            func_021BB050(work, plate, 5);
        else if (func_021B9A84(work) == 1 && plate->labelState < 6)
            func_021BB050(work, plate, 5);
        else
            func_021BB050(work, plate, 3);
        func_0204B878(plate->frameActor, 0);
        offset = getActorOffset(plate, 0x18, 0x10, &normalOffset);
    }
    func_0204B404(plate->monIconActor, offset, 0);
    plate->selected = selected;
}

void func_021BB050(PokelistWork *work, PlistPlate *plate, int palette)
{
    if (palette == 3 && func_021BB554(plate) == PLIST_PLATE_HPBAR_FULL)
        func_020413B0(2, d_021BEC74[plate->slot * 2] + 0x10, d_021BEC75[plate->slot * 2], 0x10, 6, 4);
    else if (palette == 6 && func_021BB554(plate) == PLIST_PLATE_HPBAR_FULL)
        func_020413B0(2, d_021BEC74[plate->slot * 2] + 0x10, d_021BEC75[plate->slot * 2], 0x10, 6, 7);
    else
        func_020413B0(2, d_021BEC74[plate->slot * 2] + 0x10, d_021BEC75[plate->slot * 2], 0x10, 6, palette);
    func_02041B6C(2);
}

void func_021BB0C4(PokelistWork *work, const PlistPlate *plate, int slideX)
{
    int slot = plate->slot;
    int x = d_021BEC74[slot * 2];
    u8 y = d_021BEC75[slot * 2];
    PlistPlatePos pos;
    int isOther;
    enum PlateKind { PLATE_KIND_LEAD, PLATE_KIND_OTHER } kind;
    if (slot % 2 == 0) slideX = -slideX;
    BMP_WIN_SetPosX(plate->window, slideX + (x + 16));
    pos.x = -(x + slideX) * 8;
    pos.y = -y * 8;
    func_0204B09C(plate->clactUnit, 0, &pos);
    isOther = 0;
    if (plate->slot != 0) isOther = 1;
    kind = plate->slot != 0;
    x += 16;
    slideX = (unsigned)x + slideX;
    func_020410D0(2, (u8)slideX, y, 16, 6, (u32)((u8 *)work->paletteData + 12), d_021BEC6C[kind * 2], d_021BEC6D[isOther * 2], 32, 32);
    func_020413B0(2, slideX, y, 16, 6, 5);
    func_02045374(plate->window);
    func_02041B6C(1);
    func_02041B6C(2);
}

void func_021BB1A0(PokelistWork *work, PlistPlate *plate, int slideX)
{
    int slot = plate->slot;
    int x = d_021BEC74[slot * 2];
    u8 y = d_021BEC75[slot * 2];
    int left;
    if (slot % 2 == 0)
        slideX = -slideX;
    left = x + 0x10 + slideX;
    func_02041300(2, 0, left, y, 0x10, 6, 5);
    func_02041300(1, 0, left, y, 0x10, 6, 5);
}

void func_021BB200(PokelistWork *work, PlistPlate *plate, void *mon, int slideX)
{
    PlistPlatePos pos[2];
    int slot = plate->slot;
    int x = d_021BEC74[slot * 2];
    int y = d_021BEC75[slot * 2];
    if (slot % 2 == 0)
        slideX = -slideX;
    plate->mon = mon;
    plate->textPending = 0;
    plate->isEgg = func_02017E1C(mon, POKE_TOOL_PARAM_IS_EGG, 0);
    plate->hp = func_02017E1C(plate->mon, POKE_TOOL_PARAM_HP, 0);
    plate->targetHp = plate->hp;
    func_0204B3B4(plate->monIconActor);
    func_0204A8D4(plate->iconResource);
    func_02043B5C(func_02045770(plate->window), 0);
    func_0204B3DC(plate->itemIconActor, 0);
    func_0204B3DC(plate->statusIconActor, 0);
    pos[1].x = 0;
    pos[1].y = 0;
    func_0204B09C(plate->clactUnit, 0, &pos[1]);
    func_021BAA50(work, plate);
    pos[0].x = -(x + slideX) * 8;
    pos[0].y = -y * 8;
    func_0204B09C(plate->clactUnit, 0, pos);
    func_021BAAE4(work, plate, 0);
}

void func_021BB2C0(PokelistWork *work, PlistPlate *plate)
{
    func_02043B5C(func_02045770(plate->window), 0);
    func_021BAAE4(work, plate, 0);
}

void func_021BB2E0(PokelistWork *work, PlistPlate *plate)
{
    func_02043AF4(func_02045770(plate->window), 0, 26, 128, 22, 0);
    func_021BAAE4(work, plate, 1);
}

void func_021BB30C(PokelistWork *work, PlistPlate *plate)
{
    plate->targetHp = func_02017E1C(plate->mon, POKE_TOOL_PARAM_HP, 0);
    PLIST_PLATE_HP_STEP(work) = (plate->targetHp - plate->hp) / 100;
    if (plate->targetHp > plate->hp)
        PLIST_PLATE_HP_STEP(work) = PLIST_PLATE_HP_STEP(work) + 1;
    else
        PLIST_PLATE_HP_STEP(work) = PLIST_PLATE_HP_STEP(work) - 1;
}

int func_021BB358(PokelistWork *work, PlistPlate *plate)
{
    if (plate->hp < plate->targetHp) {
        if (plate->hp == 0) {
            func_021BB050(work, plate, 6);
        }
        {
            u16 current = plate->hp;
            signed char step = PLIST_PLATE_HP_STEP(work);
            u16 limit = plate->targetHp;
            if (current + step > limit) {
                plate->hp = limit;
            } else {
                plate->hp = current + (u16)step;
            }
        }
        func_021BB2E0(work, plate);
        return 0;
    }
    if (plate->hp > plate->targetHp) {
        signed char step = PLIST_PLATE_HP_STEP(work);
        if (plate->hp + step < plate->targetHp) {
            plate->hp = plate->targetHp;
        } else {
            plate->hp = plate->hp + (u16)step;
        }
        func_021BB2E0(work, plate);
        return 0;
    }
    return 1;
}

int func_021BB3C4(void *unused, PlistPlate *plate)
{
    if (plate->isEmpty != 1) return 1;
    return 0;
}

void func_021BB3D4(void *unused, PlistPlate *plate, PlistPlatePos *out)
{
    out->x = (d_021BEC74[plate->slot * 2] + 8) << 3;
    out->y = (d_021BEC75[plate->slot * 2] + 3) << 3;
}

void func_021BB3FC(PokelistWork *work, PlistPlate *plate, PlistPlateRect *out)
{
    out->left = d_021BEC74[plate->slot * 2] << 3;
    out->top = d_021BEC75[plate->slot * 2] << 3;
    out->right = (d_021BEC74[plate->slot * 2] + 16) << 3;
    out->bottom = (d_021BEC75[plate->slot * 2] + 6) << 3;
}

int func_021BB43C(PlistPlate *plate)
{
    return plate->labelState;
}

void func_021BB440(PokelistWork *work, PlistPlate *plate, int labelState)
{
    if (plate->labelState != labelState) {
        if (labelState < 6) {
            plate->labelState = labelState;
        } else {
            func_021BB46C(work, plate);
        }
        func_021BB2C0(work, plate);
    }
}

u16 func_021BB464(PokelistWork *work, PlistPlate *plate)
{
    return plate->hp;
}

int func_021BB468(PokelistWork *work, PlistPlate *plate)
{
    return plate->isEgg;
}

void func_021BB46C(PokelistWork *work, PlistPlate *plate)
{
    if (func_021B9A84(work) == 0) {
        plate->labelState = PLIST_PLATE_LABEL_NONE;
        return;
    }
    if (POKE_REGULATION_CheckPokemon(work->arg->regulation, plate->mon) == 0) {
        plate->labelState = PLIST_PLATE_LABEL_NOT_ELIGIBLE;
        return;
    }
    plate->labelState = PLIST_PLATE_LABEL_ELIGIBLE;
}

int func_021BB4A0(PokelistWork *work, PlistPlate *plate)
{
    int species;
    int heldItem;
    PlistPlateRules *rules;
    u8 i;
    if (plate->labelState != PLIST_PLATE_LABEL_NOT_ELIGIBLE) {
        return 1;
    }
    i = 0;
    species = func_02017E1C(plate->mon, POKE_TOOL_PARAM_SPECIES, 0);
    heldItem = func_02017E1C(plate->mon, POKE_TOOL_PARAM_HELD_ITEM, 0);
    rules = (PlistPlateRules *)work->arg->regulation;
    do {
        u8 order;
        order = work->arg->slotOrder[i];
        if (order >= 1) {
            void *other = ((PlistPlate *)work->plates[order - 1])->mon;
            int otherSpecies = func_02017E1C(other, POKE_TOOL_PARAM_SPECIES, 0);
            int otherItem = func_02017E1C(other, POKE_TOOL_PARAM_HELD_ITEM, 0);
            if (species == otherSpecies && rules->allowSameSpecies == 0) {
                return 2;
            }
            if (heldItem == otherItem && heldItem != 0 && rules->allowSameItem == 0) {
                return 3;
            }
        }
        i = i + 1;
    } while (i < 6);
    if (work->selectedCount == rules->maxPartySize) {
        return 4;
    }
    return 0;
}

u8 func_021BB554(PlistPlate *plate)
{
    return func_0202D034(plate->hp, func_02017E1C(plate->mon, POKE_TOOL_PARAM_MAX_HP, 0));
}

void func_021BB56C(PlistPlate *plate, int x, int y, PlistPlatePos *out)
{
    PlistPlatePos surfacePos;
    CLACT_GetSurfacePos(plate->clactUnit, 0, &surfacePos);
    out->x = x - surfacePos.x;
    out->y = y - surfacePos.y;
}
