/*
 * file:     c_gear_power_onoff.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF2C, func_021EFF3C, func_021EFF78, func_021EFFD4, func_021F000C, func_021F0100, func_021F0140, func_021F015C, func_021F0168, func_021F0218, func_021F0254, func_021F0298, func_021F02FC, func_021F0340, func_021F0354, func_021F0364, func_021F0370, func_021F037C, func_021F0468
 * address:  0x021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F0678    0x021F0678 data ov035 a1
 *   func_02012138 0x02012138 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0201214C 0x0201214C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021F0640 0x021F0640 data ov035 a4
 *   func_021A0FA0 0x021A0FA0 thumb ov021
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_021A12D4 0x021A12D4 thumb ov021
 *   func_021A0FB4 0x021A0FB4 thumb ov021
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   d_021F05B0    0x021F05B0 data a4
 *   d_021F05BC    0x021F05BC data ov035 a4
 *   d_021F05C8    0x021F05C8 data ov035 a4
 *   d_021F05E8    0x021F05E8 data ov035 a4
 *   d_021F0608    0x021F0608 data ov035 a4
 *   func_0203FB44 0x0203FB44 arm
 *   sub_020403F4  0x020403F4 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020450F0 0x020450F0 arm
 *   BMP_WIN_SetDispHeight 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   d_021F064C    0x021F064C data ov035 a4
 *   APP_TASKMENU_OpenMenuFastDecide 0x0202784C thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02027974 0x02027974 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02012204 0x02012204 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02026400 0x02026400 thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 *   func_020121CC 0x020121CC thumb
 */
#include "c_gear_power_onoff_types.h"

struct GameData;
struct MyStatus;
struct BgTemplate;
struct TaskMenuInit;
struct PrintStream;
struct SaveControl;
struct ArcHandle;
struct CharBuf;
struct Task;

typedef signed short s16;

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8 screenSize;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 extPaletteSlot;
    u8 priority;
    u8 areaOver;
    u8 dummy;
    u8 mosaicFlag;
    u32 mosaic;
};

/*
 * Static data of the panel: the three scene step functions, followed by the
 * init block of the yes/no task menu that C_GEAR_POWER_ONOFF_OpenYesNoMenu
 * fills in before opening it.
 */
typedef struct CGearPowerOnOffTable {
    int (*sceneStep[3])(CGearPowerOnOffWork *);
    int menuHeapId;
    u8 menuHeader[0x10];
    struct Strbuf *yesLabel;
    u8 menuMiddle[0x8];
    struct Strbuf *noLabel;
} CGearPowerOnOffTable;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02012138(const void *gameSystem);
extern int func_0202EB44(void);
extern u32 func_0201214C(const void *gameSystem);
extern u32 func_020307B0(void *p);
extern void func_021A0FA0(FieldSubscreen *subscreen, int mode);
extern u32 func_0201C4E4(struct PrintQue *printQue);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern void func_0201DD68(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern struct PrintQue *func_0201C440(unsigned int heapId);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021A12D4(FieldSubscreen *subscreen, u32 heapId);
extern void func_021A0FB4(FieldSubscreen *subscreen, u32 heapId);
extern void func_0201C6EC(struct PrintQue *printQue);
extern void func_0201C4C0(struct PrintQue *printQue);
extern u32 func_02045C04(struct MsgBank *bank);
extern u32 func_0201D83C(struct GfFont *font);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 layer);
extern struct ArcHandle *func_020490F4(unsigned int id, unsigned int heap);
extern struct GameData *func_020120F4(const void *gameSystem);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern u8 func_02008550(const struct MyStatus *myStatus);
extern void func_02049B68(struct ArcHandle *arc, u32 fileId, u32 bgId, u32 offset, u32 compressed, u32 heapId);
extern u32 func_02049740(struct ArcHandle *arc, u32 fileId, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(struct ArcHandle *arc, u32 fileId, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void func_02049238(struct ArcHandle *arc);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void sub_020403F4(u32 i);
extern void *func_02027F60(u16 a0, u16 a1, struct GfFont *font, struct PrintQue *printQue, u16 heap);
extern u32 func_02027FD8(void *taskMenuRes);
extern void func_02049B40(int, int, int, int, int, int);
extern void *func_0201F5DC(u32 layer, unsigned int a1, unsigned int a2, unsigned int a3);
extern struct BmpWin *func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_SetDispHeight(struct BmpWin *window, u8 v);
extern void *func_02045770(struct BmpWin *window);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct BmpWin *window);
extern void func_02045374(struct BmpWin *window);
extern void *func_0203101C(int, int, int, int);
extern void *func_02028590(int, int, int, int);
extern void func_0201CE48(void *printStream);
extern void func_02045808(struct Strbuf *text);
extern int func_02028604(void *keyCursor);
extern void func_02031140(void *tcbl);
extern u32 func_020452E8(struct BmpWin *window);
extern void func_0201F614(int, unsigned int);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7A4(void *bitmap, s16 x, s16 y, struct Strbuf *msg, struct GfFont *font);
extern void func_0201F79C(struct BmpWin *window, u32 kind, void *menuWork, u32 pal);
extern void func_0201F7A8(struct BmpWin *window, u32 kind);
extern void *APP_TASKMENU_OpenMenuFastDecide(void *menuInit, void *taskMenuRes);
extern int func_02027CD8(void *taskMenu, int a1);
extern void func_02027858(void *taskMenu);
extern void func_02027974(void *taskMenu);
extern u8 func_02027A04(void *taskMenu);
extern u32 func_020279E8(void *taskMenu);
extern u32 func_020221A4(void);
extern int func_02035C60(void);
extern u32 func_02012204(const void *gameSystem);
extern u32 func_02026454(void *beacon);
extern void func_02026400(void *beacon);
extern void GAMESYSTEM_SetAlwaysNetFlag(void *gameSystem, unsigned int v);
extern u32 func_020121CC(void *gameSystem);
CGearPowerOnOffWork *func_021EFEC0(FieldSubscreen *subscreen, void *gameSystem, u16 heapId);
void func_021EFF2C(CGearPowerOnOffWork *work);
void func_021EFF3C(CGearPowerOnOffWork *work, int isInitialUpdate);
void func_021EFF78(CGearPowerOnOffWork *work, u16 heapId);
void func_021EFFD4(CGearPowerOnOffWork *work);
void func_021F000C(CGearPowerOnOffWork *work, u32 heapId);
void func_021F0100(CGearPowerOnOffWork *work);
void func_021F0140(CGearPowerOnOffWork *work, u16 heapId);
void func_021F015C(CGearPowerOnOffWork *work);
void func_021F0168(CGearPowerOnOffWork *work, int heapId);
void func_021F0218(CGearPowerOnOffWork *work);
void func_021F0254(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId);
void func_021F0298(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId, int height);
void func_021F02FC(CGearPowerOnOffWork *work, int heapId);
void func_021F0340(CGearPowerOnOffWork *work);
void func_021F0354(CGearPowerOnOffWork *work);
u8 func_021F0364(CGearPowerOnOffWork *work);
u32 func_021F0370(CGearPowerOnOffWork *work);
int func_021F037C(CGearPowerOnOffWork *work);
int func_021F0468(CGearPowerOnOffWork *work);
extern char d_021F0678[];
extern CGearPowerOnOffTable d_021F0640;
extern const u32 d_021F05B0[];
extern const u32 d_021F05BC[];
extern const struct BgTemplate d_021F05C8;
extern const struct BgTemplate d_021F05E8;
extern const struct BgTemplate d_021F0608;



CGearPowerOnOffWork *func_021EFEC0(FieldSubscreen *subscreen, void *gameSystem, u16 heapId)
{
    CGearPowerOnOffWork *work = func_02030734(heapId, 0x50, 1, d_021F0678, 0x12D);
    work->gameSystem = gameSystem;
    work->beacon = func_02012138(gameSystem);
    work->subscreen = subscreen;
    work->heapId = heapId;
    func_021EFF78(work, heapId);
    if (func_0202EB44() == 0)
        work->scene = C_GEAR_POWER_ONOFF_SCENE_UNAVAILABLE;
    else if (func_0201214C(gameSystem) == 1)
        work->scene = C_GEAR_POWER_ONOFF_SCENE_TURN_OFF;
    else
        work->scene = C_GEAR_POWER_ONOFF_SCENE_TURN_ON;
    func_021EFF3C(work, 1);
    return work;
}


void func_021EFF2C(CGearPowerOnOffWork *work) { func_021EFFD4(work); func_020307B0(work); }


void func_021EFF3C(CGearPowerOnOffWork *work, int isInitialUpdate) { if(work->closeRequested==0) { if(d_021F0640.sceneStep[work->scene](work)) { func_021A0FA0(work->subscreen,14); work->closeRequested=1; } } func_0201C4E4(work->printQue); }



void func_021EFF78(CGearPowerOnOffWork *work, u16 heapId)
{
    work->font = func_0201D7EC(0x17, 0, 0, 0, heapId);
    func_0201DD68();
    work->msgBank = func_02045B38(0, 2, 0x16, heapId);
    work->printQue = func_0201C440(heapId);
    func_021F000C(work, heapId);
    func_021F0140(work, heapId);
    func_021F0168(work, heapId);
    func_0203D34C(0, heapId);
    func_021A12D4(work->subscreen, heapId);
}


void func_021EFFD4(CGearPowerOnOffWork *work) { func_021A0FB4(work->subscreen,work->heapId); func_021F0218(work); func_021F015C(work); func_021F0100(work); func_0201C6EC(work->printQue); func_0201C4C0(work->printQue); func_02045C04(work->msgBank); func_0201D83C(work->font); }




void func_021F000C(CGearPowerOnOffWork *work, u32 heapId)
{
    int i;
    struct ArcHandle *arc;
    u32 charAlloc;

    for (i = 4; i <= 7; i++)
        func_02040588((u8)i, 0);
    func_0203FCA0(6, &d_021F0608, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588((u8)6, 1);
    func_0203FCA0(5, &d_021F05C8, 0);
    func_020414EC(5);
    func_020409B4(5);
    func_02040588((u8)5, 1);
    func_0203FCA0(4, &d_021F05E8, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02040588((u8)4, 1);
    arc = func_020490F4(0x1E, heapId);
    i = func_02008550(func_02012944(func_020120F4(work->gameSystem)));
    func_02049B68(arc, d_021F05BC[i], 4, 0, 1, heapId);
    charAlloc = func_02049740(arc, d_021F05B0[i], 6, 0, 0, heapId);
    work->bgCharAlloc = charAlloc;
    func_02049990(arc, 3, 6, 0, (u16)charAlloc, 0, 0, heapId);
    func_02049238(arc);
}




void func_021F0100(CGearPowerOnOffWork *work)
{
    unsigned int charAlloc = work->bgCharAlloc;
    func_0203FB44(6, (unsigned short)charAlloc, (unsigned short)(charAlloc >> 16));
    sub_020403F4(6);
    sub_020403F4(5);
    sub_020403F4(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}



void func_021F0140(CGearPowerOnOffWork *work, u16 heapId)
{
    work->taskMenuRes = func_02027F60(4, 3, work->font, work->printQue, heapId);
}




void func_021F015C(CGearPowerOnOffWork *work)
{
    func_02027FD8(work->taskMenuRes);
}




void func_021F0168(CGearPowerOnOffWork *work, int heapId)
{
    func_02049B40(0x17, 5, 4, 0x20, 0x20, heapId);
    work->bmpMenuWork = func_0201F5DC(5, 2, 0, heapId);
    work->messageWindow = func_020450F0(5, 1, 1, 0x1E, 6, 1, 1);
    work->menuWindow = func_020450F0(5, 1, 0xD, 0x1E, 0xA, 1, 1);
    BMP_WIN_SetDispHeight(work->messageWindow, 4);
    func_02043B5C(func_02045770(work->messageWindow), 0xF);
    func_02045334(work->messageWindow);
    func_02045374(work->messageWindow);
    func_02043B5C(func_02045770(work->menuWindow), 0xF);
    func_02045334(work->menuWindow);
    func_02045374(work->menuWindow);
    work->tcbl = func_0203101C(heapId, heapId, 1, 4);
    work->keyCursor = func_02028590(0xF, 0, 1, heapId);
}



/*
 * interface: 0201F614 forwards r0 and splits packed r1 into two halfwords;
 *            02028604 uses only r0; legacy trailing inputs are unread.
 * 2026-10-05 (D8 lane 15): 0201F614 now filed EXACT as src/matched/arm9/func_0201F614.c (u16 lo, u16 hi split of r1).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void func_021F0218(CGearPowerOnOffWork *work)
{
    if (work->printStream) {
        func_0201CE48(work->printStream);
        work->printStream = 0;
        func_02045808(work->streamMessage);
        work->streamMessage = 0;
    }
    func_02028604(work->keyCursor);
    func_02031140(work->tcbl);
    func_020452E8(work->menuWindow);
    func_020452E8(work->messageWindow);
    func_0201F614(5, (unsigned int)work->bmpMenuWork);
}




void func_021F0254(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId)
{
    struct Strbuf *msg = func_02045EC0(work->msgBank, msgId);
    func_0201C7A4(func_02045770(window), 0, 0, msg, work->font);
    func_0201F79C(window, 0, work->bmpMenuWork, 2);
    func_02045334(window);
    func_02045808(msg);
}




void func_021F0298(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId, int height)
{
    struct Strbuf *msg = func_02045EC0(work->msgBank, msgId);

    BMP_WIN_SetDispHeight(window, height);
    func_02043B5C(func_02045770(window), 15);
    func_0201F7A8(window, 2);
    func_02045374(window);
    func_0201C7A4(func_02045770(window), 0, 0, msg, work->font);
    func_0201F79C(window, 0, work->bmpMenuWork, 2);
    func_02045334(window);
    func_02045808(msg);
}




void func_021F02FC(CGearPowerOnOffWork *work, int heapId)
{
    CGearPowerOnOffTable *table = &d_021F0640;

    table->menuHeapId = heapId;
    table->yesLabel = func_02045EC0(work->msgBank, 5);
    table->noLabel = func_02045EC0(work->msgBank, 6);
    work->taskMenu = APP_TASKMENU_OpenMenuFastDecide(&table->menuHeapId, work->taskMenuRes);
    func_02027CD8(work->taskMenu, 1);
    func_02045808(table->yesLabel);
    func_02045808(table->noLabel);
}



void func_021F0340(CGearPowerOnOffWork *work)
{
    if (work->taskMenu != 0) {
        func_02027858(work->taskMenu);
        work->taskMenu = 0;
    }
}



/*
 * extent: followers 021F0364 and 021F0370 already filed separately.
 */
void func_021F0354(CGearPowerOnOffWork *work)
{
    if (work->taskMenu != 0)
        func_02027974(work->taskMenu);
}




/*
 * Unlabelled tail-call leaf of func_021F0468 (reads the menu handle at +0x44).
 */
u8 func_021F0364(CGearPowerOnOffWork *work)
{
    return func_02027A04(work->taskMenu);
}




u32 func_021F0370(CGearPowerOnOffWork *work)
{
    return func_020279E8(work->taskMenu);
}




int func_021F037C(CGearPowerOnOffWork *work)
{
    u16 nextStep;

    switch (work->step) {
    case 0:
        func_021F0254(work, work->messageWindow, 0);
        func_021F0254(work, work->menuWindow, 3);
        func_021F02FC(work, work->heapId);
        (work->step)++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (work->step)++;
        break;
    case 2:
        if (func_021F0370(work) != 0) {
            if (func_021F0364(work) == 0) {
                GAMESYSTEM_SetAlwaysNetFlag(work->gameSystem, 1);
                func_020121CC(work->gameSystem);
                nextStep = 3;
            } else {
                nextStep = 5;
            }
            work->step = nextStep;
            func_021F0340(work);
        }
        break;
    case 3:
        func_021F0298(work, work->messageWindow, 1, 6);
        (work->step)++;
        break;
    case 4:
        if (func_02035C60() != 0 || func_02012204(work->gameSystem) != 0)
            (work->step)++;
        break;
    case 5:
        if (func_02012204(work->gameSystem) != 0) {
            if (func_02026454(work->beacon))
                func_02026400(work->beacon);
            work->step = 6;
            break;
        }
        return 1;
    case 6:
        if (func_02026454(work->beacon) == 0)
            return 1;
        break;
    }
    func_021F0354(work);
    return 0;
}




int func_021F0468(CGearPowerOnOffWork *work)
{
    u16 closeComm;

    switch (work->step) {
    case 0:
        func_021F0254(work, work->messageWindow, 2);
        func_021F0254(work, work->menuWindow, 3);
        func_021F02FC(work, work->heapId);
        (work->step)++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (work->step)++;
        break;
    case 2:
        if (func_021F0370(work) != 0 || func_02012204(work->gameSystem) == 1) {
            if (func_021F0364(work) == 0 || func_02012204(work->gameSystem) == 1) {
                if (func_02026454(work->beacon))
                    func_02026400(work->beacon);
                closeComm = 1;
            } else {
                closeComm = 0;
            }
            work->closeComm = closeComm;
            work->step = 3;
            func_021F0340(work);
        }
        break;
    case 3:
        if (work->closeComm != 0) {
            if (func_02026454(work->beacon) != 0)
                break;
            GAMESYSTEM_SetAlwaysNetFlag(work->gameSystem, 0);
        }
        (work->step)++;
        break;
    case 4:
        return 1;
    }
    func_021F0354(work);
    return 0;
}
