/*
 * file:     plist_battle.c
 * unit:     yes
 * function: func_021BD05C, func_021BD18C, func_021BD1BC, func_021BD218, func_021BD454, func_021BD480, func_021BD4EC, func_021BD504, func_021BD59C, func_021BD61C, func_021BD634, func_021BD8B0, func_021BD8E4, func_021BD9C8
 * address:  0x021BD05C
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
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02030734 0x02030734 arm
 *   func_020450F0 0x020450F0 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
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
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02006238  0x02006238  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045924 0x02045924 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 *   func_02061CA4 0x02061CA4 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02040588 0x02040588 arm
 *   func_021B7034 0x021B7034 thumb ov091
 *   func_021B6F28 0x021B6F28 thumb ov091
 *   func_021B7040 0x021B7040 thumb ov091
 *   func_021B6F0C 0x021B6F0C thumb ov091
 *   func_02051614 0x02051614 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   func_02047970 0x02047970 arm
 *   func_02006BD0 0x02006BD0 thumb
 *   func_021B9788  0x021B9788  thumb
 *   func_021B9C1C  0x021B9C1C  thumb
 *   func_021B9D58  0x021B9D58  thumb
 *   func_021B9E20  0x021B9E20  thumb
 *   func_021B9E3C  0x021B9E3C  thumb
 *   func_021BA4F8  0x021BA4F8  thumb
 *   func_021BB200  0x021BB200  thumb
 *   func_021BB714  0x021BB714  thumb
 *   func_021BB7D8  0x021BB7D8  thumb
 *   func_021BB7E8  0x021BB7E8  thumb
 *   func_021BB97C  0x021BB97C  thumb
 *   func_021BB98C  0x021BB98C  thumb
 *   func_021BB99C  0x021BB99C  thumb
 *   func_021BBA0C  0x021BBA0C  thumb
 *   func_021BBA54  0x021BBA54  thumb
 *   func_021BDABC  0x021BDABC  thumb
 *   func_021BDBE0  0x021BDBE0  thumb
 */
struct Obj;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct WordSet;
struct Cfg;
struct PrintSys;
struct CharBuf;
struct StrObj;
struct Strbuf;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;
typedef signed int     s32;

#include "plist_battle_types.h"

extern void func_020061E4(u32 id);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_02041B6C(u32 bit);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern u32 func_020307B0(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, short b, short c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020450F0(int,u8,u8,int,u8,u8,u8);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void *func_020490F4(u32 id, u32 heap);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *a);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 POKE_TOOL_CalcLevel(void *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_02006238(void);
void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 func_0201AA18(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B7034(PlistWork *work);
extern void func_021B6F28(PlistWork *work);
extern void func_021B7040(PlistWork *work);
extern void func_021B6F0C(PlistWork *work);
extern int func_02051614(int **p);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern u32 func_02006BD0(u32 i);
extern int PARTICLE_UpdateAllSystems(void);
extern void func_02047964(void);
extern void func_020479D8(void);
extern int PARTICLE_DrawAllSystems(void);
extern void func_02047970(void);
void func_021B9788(PlistWork *work, int a1, int a2, int a3);
void func_021B9C1C(PlistWork *work, u32 win, u32 id, int x, s16 y, u16 color);
void func_021B9D58(PlistWork *work, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
void func_021B9E20(PlistWork *work);
void func_021B9E3C(PlistWork *work);
void func_021BA4F8(PlistWork *work);
void func_021BB200(PlistWork *work, u8 *plate, int mon, int q);
void func_021BB714(PlistWork *work, u32 *window, u32 k);
int func_021BB7D8(PlistWork *work, u32 window);
void func_021BB7E8(PlistWork *work, u32 *window, u32 x);
void func_021BB97C(PlistWork *work, u32 window);
void func_021BB98C(PlistWork *work, u32 window);
void func_021BB99C(PlistWork *work, u32 window, int c, u32 mon);
void func_021BBA0C(PlistWork *work, u32 window, int c, const void *text, int gender);
void func_021BBA54(PlistWork *work, u32 window);
PlistTeamPanel *func_021BD05C(PlistWork *work, PlistTeamSource *source, u8 x, u8 y, u8 width);
void func_021BD18C(PlistWork *work, PlistTeamPanel *panel);
void func_021BD1BC(PlistWork *work, PlistTeamPanel *panel);
PlistMiniCell *func_021BD218(PlistWork *work, void *mon, s16 x, u16 y);
void func_021BD454(PlistWork *unusedWork, PlistMiniCell *cell);
void func_021BD480(PlistWork *work, PlistMiniCell *cell);
void func_021BD4EC(PlistWork *work);
void func_021BD504(PlistWork *work);
void func_021BD59C(PlistWork *work);
void func_021BD61C(PlistWork *work);
void func_021BD634(PlistWork *work);
void func_021BD8B0(PlistWork *work);
void func_021BD8E4(PlistWork *work);
void func_021BD9C8(PlistWork *work);
void func_021BDABC(PlistWork *work);
void func_021BDBE0(PlistWork *work);
extern const char d_021BED48[];
extern s16 d_020A1B38[];

PlistTeamPanel *func_021BD05C(PlistWork *work, PlistTeamSource *source, u8 x, u8 y, u8 width)
{
    PlistTeamPanel *panel;
    u8 count;
    u8 i;
    u32 nameBuf;
    u32 active;

    panel = (PlistTeamPanel *)func_02030734(work->heapId, 0x20, 0, d_021BED48, 0x143);
    count = func_0201AA18(source->party);
    for (i = 0; i < 6; i++) {
        if (i < count) {
            int column = i % 2;
            u8 cellX = x + column * (width + 5);
            u8 cellY = y + (i / 2) * 6 + 4;
            int pixelOffset = 4;
            if (column != 0) pixelOffset = 0;
            panel->cells[i] = func_021BD218(work, func_0201AB28(source->party, i), (u8)((u8)pixelOffset + (cellX << 3)), (u8)(cellY << 3));
        } else {
            panel->cells[i] = 0;
        }
    }
    active = 1;
    panel->nameWindow = func_020450F0((int)4, (u8)(x + 1 + ((u32)width >> 1)), (u8)(y + 1), (int)10, 2, 0xe, active);
    nameBuf = (u32)func_020457B0(0x10, work->heapId);
    func_02045924((struct Strbuf *)nameBuf, source->name);
    func_0201C724(work->printSys, (u32)func_02045770((struct Descriptor *)panel->nameWindow), 0, 0, nameBuf, work->fontMain, 0x3c40);
    func_02045808((struct U16Vec *)nameBuf);
    panel->active = active;
    return panel;
}

void func_021BD18C(PlistWork *work, PlistTeamPanel *panel)
{
    u8 i;
    for (i = 0; i < 6; i++) {
        PlistMiniCell *cell = panel->cells[i];
        if (cell) func_021BD454(work, cell);
    }
    func_020452E8((struct Descriptor *)panel->nameWindow);
    func_020307B0(panel);
}

void func_021BD1BC(PlistWork *work, PlistTeamPanel *panel)
{
    u8 i;
    u32 window;
    for (i = 0; i < 6; i++) {
        if (panel->cells[i] != 0)
            func_021BD480(work, panel->cells[i]);
    }
    if (panel->active == 1 && func_0201C6C4((struct PrintSys *)work->printSys, (void *)func_02045770((struct Descriptor *)panel->nameWindow)) == 0) {
        window = panel->nameWindow;
        panel->active = 0;
        func_02045334((struct Descriptor *)window);
        func_02045374((struct Cfg *)window);
        func_02041B6C(func_02045730((struct Descriptor *)window));
    }
}

/*
 * lever: u16 y pins x's front spill; declare the u8 offset before gx to restore r7/r6 allocation.
 */
PlistMiniCell *func_021BD218(PlistWork *work, void *mon, s16 x, u16 y)
{
    PlistActorParam iconParam;
    PlistActorParam markParam;
    PlistMiniCell *cell;
    void *iconFile;
    int boxMon;
    int paletteIndex;
    u32 heldItem;
    u32 sex;
    int level;
    int isEgg;
    int xOffset;
    u8 xShift;
    int cellX;
    u32 cellY;
    u32 wordSet;
    cell = func_02030734(work->heapId, 24, 0, d_021BED48, 0x199);
    isEgg = func_02017E1C(mon, PLIST_MON_EGG_FLAG, 0);
    iconFile = func_020490F4(7, work->heapId);
    boxMon = (int)POKE_TOOL_GetBoxParam(mon);
    cell->iconRes = func_0204A6C8(iconFile, func_0201BA68((void *)boxMon), 0, 1, work->heapId);
    func_02049238(iconFile);
    paletteIndex = POKE_TOOL_GetIconPalette((void *)boxMon);
    iconParam.x = x + 16; iconParam.y = y + 8; iconParam.animNo = 1; iconParam.softPriority = 16; iconParam.bgPriority = 2;
    {
        int actor = (int)func_0204B294(work->actorSystem, cell->iconRes, work->charRes[7], work->cellRes[7], &iconParam, 1, work->heapId);
        cell->iconActor = actor;
        func_0204B6F4((struct Obj *)actor, paletteIndex, 1);
    }
    func_0204B92C((struct Obj *)cell->iconActor, 1);
    heldItem = func_02017E1C(mon, PLIST_MON_HELD_ITEM, 0);
    markParam.x = x + 32; markParam.y = y + 16; markParam.animNo = 0; markParam.softPriority = 8; markParam.bgPriority = 2;
    cell->itemMarkActor = (u32)func_0204B294(work->actorSystem, work->palRes[4], work->charRes[3], work->cellRes[4], &markParam, 1, work->heapId);
    if (heldItem != 0) {
        func_0204B3DC((struct Obj *)cell->itemMarkActor, 1);
        if (func_0202136C(heldItem) == 1) func_0204B878((struct Obj *)cell->itemMarkActor, 1);
        else func_0204B878((struct Obj *)cell->itemMarkActor, 0);
    } else func_0204B3DC((struct Obj *)cell->itemMarkActor, 0);
    sex = func_02017E1C(mon, PLIST_MON_SEX, 0);
    xOffset = x % 8;
    xShift = xOffset;
    cellY = (u32)y >> 3;
    cellX = (u32)x >> 3;
    cell->sexWindow = func_020450F0(4, (u8)cellX + 3, cellY, 3, 2, 13, 1);
    if (isEgg == 0) {
        if (sex == 0) func_021B9C1C(work, cell->sexWindow, 7, (u16)(xShift + 4), 0, 0x14c0);
        else if (sex == 1) func_021B9C1C(work, cell->sexWindow, 8, (u16)(xShift + 4), 0, 0xc80);
    }
    level = POKE_TOOL_CalcLevel((void *)((int)mon));
    xShift = xOffset;
    cell->levelWindow = func_020450F0(4, (u8)cellX, (u8)cellY + 3, 6, 1, 14, 1);
    if (isEgg == 0) {
        wordSet = (u32)func_0201EC64(work->heapId);
        func_0201EFA4((struct WordSet *)wordSet, 0, level, 3, 0, 1);
        func_021B9D58(work, cell->levelWindow, (void *)wordSet, 2, (s16)xShift, (s16)0, 0x3c40);
        func_0201ED04((struct WordSet *)wordSet);
    }
    cell->active = 1;
    return cell;
}

void func_021BD454(PlistWork *unusedWork, PlistMiniCell *cell)
{
    func_020452E8((struct Descriptor *)cell->sexWindow);
    func_020452E8((struct Descriptor *)cell->levelWindow);
    func_0204B3B4((struct Obj *)cell->itemMarkActor);
    func_0204B3B4((struct Obj *)cell->iconActor);
    func_0204A8D4(cell->iconRes);
    func_020307B0(cell);
}

void func_021BD480(PlistWork *work, PlistMiniCell *cell)
{
    u32 window;
    if (cell->active == 1
        && func_0201C6C4((struct PrintSys *)work->printSys, (void *)func_02045770((struct Descriptor *)cell->sexWindow)) == 0
        && func_0201C6C4((struct PrintSys *)work->printSys, (void *)func_02045770((struct Descriptor *)cell->levelWindow)) == 0) {
        window = cell->sexWindow;
        cell->active = 0;
        func_02045334((struct Descriptor *)window);
        func_02045374((struct Cfg *)window);
        func_02041B6C(func_02045730((struct Descriptor *)window));
        window = cell->levelWindow;
        func_02045334((struct Descriptor *)window);
        func_02045374((struct Cfg *)window);
        func_02041B6C(func_02045730((struct Descriptor *)window));
    }
}

void func_021BD4EC(PlistWork *work)
{
    func_021BD504(work);
    work->timerShown = work->arg->timerExpired;
}

void func_021BD504(PlistWork *work)
{
    int text;
    if (work->arg->timerExpired == 0)
        return;
    if (func_021BB7D8(work, work->messageWindow) == 0)
        func_021BB714(work, (u32 *)work->messageWindow, 1);
    if (work->arg->battleKind == 1) {
        text = (int)func_020457B0(0x10, work->heapId);
        func_02045924((struct Strbuf *)text, work->arg->rivalName);
        func_021BB97C(work, work->messageWindow);
        func_021BBA0C(work, work->messageWindow, 0, (const void *)text, work->arg->rivalGender);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0xA9);
        func_021BB98C(work, work->messageWindow);
        func_02045808((struct U16Vec *)text);
    } else {
        func_021BB7E8(work, (u32 *)work->messageWindow, work->arg->timerExpired + 0xA9);
    }
}

void func_021BD59C(PlistWork *work)
{
    int text;
    work->timerLabelWindow = (void *)func_020450F0(4, 7, 0x15, 0xB, 3, 0xE, 1);
    work->timerValueWindow = (void *)func_020450F0(4, 0x14, 0x15, 5, 3, 0xE, 1);
    text = (int)func_02045EC0((struct MsgBank *)work->msgBank, 0xAD);
    func_0201C724(work->printSys, (int)func_02045770((struct Descriptor *)work->timerLabelWindow), 0, 4, text,
                  work->fontMain, 0x3C40);
    func_02045808((struct U16Vec *)text);
    work->timerLabelPrinting = 1;
}

void func_021BD61C(PlistWork *work)
{
    func_020452E8((struct Descriptor *)work->timerLabelWindow);
    func_020452E8((struct Descriptor *)work->timerValueWindow);
}

/*
 * note: minute and second are u8 locals: widening the explicit byte casts
 *   to u32 keeps the size but moves the text spill before outgoing stores.
 */
void func_021BD634(PlistWork *work)
{
    u32 width;
    u8 minute;
    u8 second;
    void *text;
    struct U16Vec *buf;
    struct WordSet *words;
    u16 timer;
    struct Descriptor *window;
    u8 amount;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;
    u16 color;
    int value;
    timer = work->arg->timeLeft;
    if (work->shownSeconds != timer) {
        minute = (u8)(timer / 60);
        second = (u8)(timer % 60);
        buf = func_020457B0(32, work->heapId);
        words = func_0201EC64(work->heapId);
        if (minute == 0) {
            text = func_02045EC0(work->msgBank, 175);
            func_0201EFA4(words, 1, second, 2, 1, 1);
        } else {
            text = func_02045EC0(work->msgBank, 174);
            func_0201EFA4(words, 0, minute, 2, 1, 1);
            func_0201EFA4(words, 1, second, 2, 2, 1);
        }
        func_02043B5C(func_02045770(work->timerValueWindow), 0);
        func_0201F250(words, buf, text);
        width = func_0201D304((struct StrObj *)buf, work->fontMain, 0);
        func_0201C724(work->printSys, (u32)func_02045770(work->timerValueWindow), (s16)(36 - width), 4, (u32)buf, work->fontMain, 0x3c40);
        func_0201ED04(words);
        func_02045808(buf);
        func_02045808(text);
        work->timerValuePrinting = 1;
        work->shownSeconds = work->arg->timeLeft;
    }
    if (work->arg->timeLeft == 0) func_021BA4F8(work);
    if (work->timerValuePrinting == 1) {
        if (func_0201C6C4(work->printSys, func_02045770(work->timerValueWindow)) == 0) {
            work->timerValuePrinting = 0;
            window = work->timerValueWindow;
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if (work->timerLabelPrinting == 1) {
        if (func_0201C6C4(work->printSys, func_02045770(work->timerLabelWindow)) == 0) {
            work->timerLabelPrinting = 0;
            window = work->timerLabelWindow;
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if (work->arg->timeLeft <= 10) {
        amount = (d_020A1B38[(((work->timerPalPhase << 16) / 60) >> 4) * 2 + 1] + 4096) * 32 / 8192;
        for (i = 0; i < 16; i++) {
            color = work->timerPalSrc[i];
            green = (color & 0x3e0) >> 5;
            blue = (color & 0x7c00) >> 10;
            red = color & 31;
            value = red + amount;
            if (value > 31) value = 31;
            red = value;
            work->timerPalDst[i] = (blue << 10) | (red | (green << 5));
        }
        func_02061CA4((void *)31, 64, (u32)work->timerPalDst, 32);
        work->timerPalPhase++;
        if (work->timerPalPhase >= 60) work->timerPalPhase = 0;
    }
}

void func_021BD8B0(PlistWork *work)
{
    work->effectFrame = 0;
    work->effectStarted = 0;
    work->cryStarted = 0;
    func_02040588(0, 0);
    func_021B7034(work);
    func_021B6F28(work);
    func_021BDABC(work);
    work->phase = 15;
}

void func_021BD8E4(PlistWork *work)
{
    void (*callback)(PlistWork *);
    func_021BDBE0(work);
    func_021B7040(work);
    func_021B6F0C(work);
    func_021BBA54(work, work->messageWindow);
    if (work->evolveCheckKind == 1) {
        callback = func_021B9E3C;
        if (work->arg->mode == 0) callback = func_021B9E20;
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021B9788(work, 0xa6, 1, (int)callback);
        func_021BB98C(work, work->messageWindow);
    } else if (work->evolveCheckKind == 2) {
        callback = func_021B9E3C;
        if (work->arg->mode == 0) callback = func_021B9E20;
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021B9788(work, 0xa6, 1, (int)callback);
        func_021BB98C(work, work->messageWindow);
    } else if (work->evolveCheckKind == 3) {
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021B9788(work, 0xa6, 1, (int)func_021B9E3C);
        func_021BB98C(work, work->messageWindow);
    } else {
        work->phase = 0x13;
    }
}

/*
 *   unsigned int func_02051614(unsigned int **p) { return (*p)[2]; }
 */
void func_021BD9C8(PlistWork *work)
{
    u32 species, form;
    if (work->effectStarted == 0) {
        work->effectFrame++;
        if (work->effectFrame == 1) {
            func_02040588(0, 1);
            if (work->evolveCheckKind - 1 <= 1) func_020061E4(0x643);
            else if (work->evolveCheckKind == 3) func_020061E4(0x644);
        }
        if (work->effectFrame > work->effectLength) {
            func_021BB200(work, (u8 *)work->plates[work->selectedSlot], work->selectedMon, 0);
            work->effectStarted = 1;
        }
    }
    if (func_02051614((int **)work->particleSystem) <= 0 && func_02006238() == 0) {
        if (work->cryStarted == 0) {
            species = func_02017E1C((void *)work->selectedMon, PLIST_MON_SPECIES, 0);
            form = func_02017E1C((void *)work->selectedMon, PLIST_MON_FORM, 0);
            work->cryHandle = func_02006984(species, form, 0x40, 0, 0, 0, 0, 0);
            work->cryStarted = 1;
        } else {
            if (func_02006BD0(work->cryHandle) == 0) work->phase = 0x10;
        }
    }
    PARTICLE_UpdateAllSystems();
    func_02047964();
    func_020479D8();
    PARTICLE_DrawAllSystems();
    func_02047970();
}
