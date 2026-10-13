/*
 * file:     field_menu.c
 * unit:     yes
 * function: func_021A836C, func_021A84A8, func_021A84BC, func_021A8588, func_021A85B4, func_021A87A8, func_021A8840, func_021A8874, func_021A8AFC, func_021A8B18, func_021A8B84, func_021A8BB8, func_021A8D40, func_021A8DD8, func_021A8E10, func_021A8E20, func_021A8E78, func_021A8E80, func_021A8EEC, func_021A8FFC, func_021A9080, func_021A90A4, func_021A90E0, func_021A9154, func_021A926C, func_021A9294, func_021A92A4
 * address:  0x021A836C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Holds the former field_menu_p01.c (0x021A87A8..0x021A92A4, the tail of field_menu.c).
 * The file ends at 0x021A92A4; field_encount.c starts at 0x021A9350.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DDF94     0x021DDF94  data  ov021  a1
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020355C4  0x020355C4  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021A8D40  0x021A8D40  thumb  ov021
 *   func_0201C440  0x0201C440  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_021A8874  0x021A8874  thumb  ov021
 *   func_021A8BB8  0x021A8BB8  thumb  ov021
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   func_021A90E0  0x021A90E0  thumb  ov021
 *   func_021A8DD8  0x021A8DD8  thumb  ov021
 *   func_020129C4  0x020129C4  thumb
 *   func_021A8E20  0x021A8E20  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_021A0FB4  0x021A0FB4  thumb
 *   func_021A926C  0x021A926C  thumb  ov021
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021A12D4  0x021A12D4  thumb  ov021
 *   func_021A9294  0x021A9294  thumb  ov021
 *   func_021A87A8  0x021A87A8  thumb  ov021
 *   func_020221A4  0x020221A4  thumb
 *   func_021A8EEC  0x021A8EEC  thumb  ov021
 *   func_021A8FFC  0x021A8FFC  thumb  ov021
 *   func_0204B98C  0x0204B98C  arm
 *   func_021A9080  0x021A9080  thumb  ov021
 *   func_0204B878  0x0204B878  arm
 *   func_021A0FA0  0x021A0FA0  thumb  ov021
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204B09C  0x0204B09C  arm
 *   func_0204B454  0x0204B454  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0207D534  0x0207D534  arm
 *   d_021D8BBC     0x021D8BBC  data  a4
 *   d_021D8B5C     0x021D8B5C  data  a4
 *   d_021D8B7C     0x021D8B7C  data  a4
 *   d_021D8B44     0x021D8B44  data  a4
 *   d_021D8C1C     0x021D8C1C  data  a4
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020142E8  0x020142E8  thumb
 *   d_021D8D24  0x021D8D24  data  a4
 *   func_02045B38  0x02045B38  arm
 *   d_021D8C0C     0x021D8C0C  data  ov021  a2
 *   func_020457B0  0x020457B0  arm
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02045924  0x02045924  arm
 *   d_021D8B34     0x021D8B34  data  a2
 *   func_02045EC0  0x02045EC0  arm
 *   d_021D8CAC     0x021D8CAC  data  ov021  a4
 *   func_02008550  0x02008550  thumb
 *   d_021D8B18     0x021D8B18  data  ov021  a1
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0203F684  0x0203F684  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   d_021D8C4C     0x021D8C4C  data  ov021  a1
 *   d_021D8B26     0x021D8B26  data  ov021  a1
 *   d_021D8B27     0x021D8B27  data  ov021  a1
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02035C08  0x02035C08  arm
 *   d_021D8C2C     0x021D8C2C  data  ov021  a1
 *   func_0204B404  0x0204B404  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0204B324  0x0204B324  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045334  0x02045334  arm
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_02049EF4  0x02049EF4  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_020061E4(u32 seId);

/* ------------------------------------------------------------------------ */
/* Field menu (field_menu.c, 0x021A836C..0x021A92A4)                        */
/* ------------------------------------------------------------------------ */

#define FIELD_MENU_ITEM_MAX 7

/* Slot of the back button; it is the last of the seven slots and has no icon. */
#define FIELD_MENU_ITEM_BACK 6

/* FieldMenuItem.buttonId values with a known meaning. */
#define FIELD_MENU_BUTTON_PLAYER 4 /* the trainer name button */
#define FIELD_MENU_BUTTON_EMPTY 7  /* slot without a button */

/* One icon slot: text window, icon resources and the actor that shows it. */
typedef struct FieldMenuItem {
    int inUse;
    void *bmpWin;
    int buttonId;
    void *charRes;
    void *cellRes;
    u8 cursorX;
    u8 cursorY;
    u8 reserved16[2];
    void *actor;
} FieldMenuItem;

/* Work of the sub screen menu (0x138 bytes). */
typedef struct FieldMenu {
    u16 heapId;
    u16 subHeapId;
    void *fieldMap;
    void *parent;
    int state;
    u32 mapInfo;
    void *eventWork;
    void *myStatus;
    u16 zoneId;
    u8 cursorCol;
    u8 cursorRow;
    u8 pressFrames;
    u8 layoutType;
    u8 reserved22[0x24 - 0x22];
    int cursorDirty;
    int exitRequested;
    int keyCursorActive;
    int chosenButton;
    FieldMenuItem items[FIELD_MENU_ITEM_MAX];
    FieldMenuItem *selectedItem;
    s16 scrollY;
    u8 reservedFE[0x100 - 0xFE];
    int scrollDirty;
    void *palRes;
    void *charRes;
    void *cellRes;
    void *palResB;
    void *charResB;
    void *cellResB;
    void *clactUnit;
    void *clactSurface;
    void *cursorActor;
    void *backActor;
    void *printQue;
    void *colorTask;
    u32 colorPhase;
} FieldMenu;

/* Values of FieldMenu.state */
#define FIELD_MENU_STATE_SLIDE_IN 0
#define FIELD_MENU_STATE_WAIT_PRINT 1
#define FIELD_MENU_STATE_WAIT_WIPE 2
#define FIELD_MENU_STATE_IDLE 3
#define FIELD_MENU_STATE_BACK_ANIM 4
#define FIELD_MENU_STATE_DECIDE 5
#define FIELD_MENU_STATE_PRESS_ANIM 6
#define FIELD_MENU_STATE_NOTIFY_CLOSE 7
#define FIELD_MENU_STATE_NOTIFY_SELECT 8
#define FIELD_MENU_STATE_SLIDE_OUT 9
#define FIELD_MENU_STATE_DONE 10

/* Mode numbers the menu hands to its parent when it ends. */
#define FIELD_MENU_NEXT_SELECT 3
#define FIELD_MENU_NEXT_CLOSE 4

#define FIELD_MENU_SCROLL_STEP 0x40
#define FIELD_MENU_SCROLL_HIDDEN 0xC0

/* Layer 6 sits 5 pixels higher than layer 5 (the icon layer). */
#define FIELD_MENU_LAYER6_OFFSET 5

/* Actors whose screen Y is at or past these limits are hidden while scrolling. */
#define FIELD_MENU_ICON_CULL_Y 0xD0
#define FIELD_MENU_CURSOR_CULL_Y 0xD6

#define SE_FIELD_MENU_SLIDE_IN 0x554
#define SE_FIELD_MENU_CLOSE 0x556
#define SE_FIELD_MENU_PRESS 0x54C
#define SE_FIELD_MENU_MOVE 0x548

/* Bits of the pad words returned by func_020362DC (pressed) and func_0203633C (repeat). */
#define FIELD_MENU_PAD_A 0x0001
#define FIELD_MENU_PAD_B 0x0002
#define FIELD_MENU_PAD_RIGHT 0x0010
#define FIELD_MENU_PAD_LEFT 0x0020
#define FIELD_MENU_PAD_UP 0x0040
#define FIELD_MENU_PAD_DOWN 0x0080
#define FIELD_MENU_PAD_X 0x0400

/* Position on the sub screen, in pixels. */
typedef struct FieldMenuScreenPos {
    s16 x;
    s16 y;
} FieldMenuScreenPos;

/* Position and display flags for an actor added by func_0204B294. */
typedef struct FieldMenuActorPos {
    s16 x;
    s16 y;
    s16 z;
    u8 flip;
    u8 palOffset;
} FieldMenuActorPos;

/* Setup record for an actor added by func_0204B324. */
typedef struct FieldMenuActorSetup {
    u16 x;
    u16 y;
    u16 z;
    u8 flip;
    u8 palOffset;
    u16 bgPriority;
    u16 reserved0A;
    u32 scaleX;
    u32 scaleY;
    u16 rotation;
    u16 drawArea;
} FieldMenuActorSetup;

/* Rectangle of the actor surface (4 words). */
typedef struct FieldMenuSurfaceRect {
    u32 x;
    u32 y;
    u32 width;
    u32 height;
} FieldMenuSurfaceRect;

/* Ids of the icon resources of one button (d_021D8CAC, per button id). */
typedef struct FieldMenuIconRes {
    int charId;
    int cellId;
    int animId;
} FieldMenuIconRes;

/* Tile position of the text window of one slot (d_021D8B18, per slot). */
typedef struct FieldMenuWindowPos {
    u8 tileX;
    u8 tileY;
} FieldMenuWindowPos;

/* Name shown on the player button when the trainer has no name (7 characters). */
typedef struct FieldMenuName {
    u16 chars[7];
} FieldMenuName;

/* Touch rectangles of the seven slots for func_02035C08. */
typedef struct FieldMenuTouchTable {
    u8 rects[32];
} FieldMenuTouchTable;

/* Header and tile map of a loaded screen file. */
typedef struct FieldMenuScreenData {
    u8 header[0xC];
    u16 tiles[0x300];
} FieldMenuScreenData;

/* Everything FIELD_MENU_CreateItem needs to build one slot. */
typedef struct FieldMenuItemInit {
    int buttonId;
    u8 cursorX;
    u8 cursorY;
    u8 winTileX;
    u8 winTileY;
    u8 iconX;
    u8 iconY;
    u8 reserved0A[2];
    void *text;
    void *arcHandle;
    u32 charId;
    u32 cellId;
    u32 animId;
} FieldMenuItemInit;

struct BgTemplate;
struct BigObj;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void *func_02188C80(void *fieldMap);
extern void *func_020120F4(void *gameSystem);
extern void *func_020120F8(void *gameSystem);
extern u16 func_02012AC8(void *playerWork);
extern void *func_0201296C(void *gameData);
extern void *func_02012944(void *gameData);
extern u32 func_02188C54(void *fieldMap);
extern u8 func_020355C4(void);
extern void *func_020056A0(void *callback, void *work, int priority);
extern void *func_0201C440(u32 heapId);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049238(void *arcHandle);
extern u32 func_02040588(u8 layer, u8 visible);
extern u8 func_020129C4(void *gameData);
extern void func_0204B3DC(void *actor, u32 drawEnable);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021A0FB4(void *parent, u32 heapId);
extern void func_02030EAC(void *tcb);
extern void func_0204B3B4(void *actor);
extern void func_0204B084(void *surface);
extern u32 func_0204B1CC(void *unit);
extern void func_0204AFD8(void *cellRes);
extern void func_0204A8D4(void *charRes);
extern void func_0204ADA4(void *palRes);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020403F4(u32 layer);
extern void func_0201C6EC(void *printQue);
extern void func_0201C4C0(void *printQue);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32 layer);
extern u32 func_0201C6B4(void *printQue);
extern void func_021A12D4(void *parent, u32 heapId);
extern u32 func_020221A4(void);
extern u32 func_0204B98C(void *actor);
extern void func_0204B878(void *actor, u16 animSeq);
extern void func_021A0FA0(void *parent, int mode);
extern u32 func_0201C4E4(void *printQue);
extern void func_0204B09C(void *surface, int a, FieldMenuScreenPos *offset);
extern void func_0204B454(void *actor, FieldMenuScreenPos *out, u16 space);
extern void func_02041EE4(u32 layer, u32 type, u32 value);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *template, u32 type);
extern void func_020414EC(u32 layer);
extern void func_02049B68(void *arcHandle, u32 b, u32 c, u32 d, u32 e, u32 heapId);
extern void func_02049658(void *arcHandle, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heapId);
extern void func_020498F4(void *arcHandle, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void *func_0204AC18(void *arcHandle, u32 b, u32 c, u32 d, u16 e, u16 f, u16 heapId);
extern void *func_0204A6C8(void *arcHandle, u32 b, u32 c, u32 d, u16 heapId);
extern void *func_0204AF28(void *arcHandle, u32 first, u32 second, u32 heapId);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_0204B034(FieldMenuSurfaceRect *rect, u32 a1, u32 heapId);
extern void func_0204B258(void *unit, void *surface);
extern void *func_0204B294(void *unit, void *charRes, void *palRes, void *cellRes, const FieldMenuActorPos *pos, u16 space, u16 heapId);
extern void func_0204B954(void *actor, u32 scale);
extern void func_0204B92C(void *actor, u32 value);
extern void func_0204B84C(void *actor, int value);
extern u32 func_02013CC8(u32 zoneId);
extern u32 func_02013CE0(u16 zoneId);
extern u32 func_02013D20(u16 zoneId);
extern int func_02012B70(void *gameData);
extern u32 func_020142E8(void *eventWork, s32 flagId);
extern void *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020457B0(u32 capacity, u32 heapId);
extern int func_020084BC(const void *myStatus);
extern const void *func_020084F4(const void *myStatus);
extern void func_02045924(void *strbuf, const void *src);
extern void *func_02045EC0(void *msgBank, u32 index);
extern u8 func_02008550(const void *myStatus);
extern void func_02045808(void *strbuf);
extern u32 func_02045C04(void *msgBank);
extern short func_0203F684(unsigned short x);
extern void func_0207E5D0(void *src, u32 off, u32 n);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020355D8(u8 v);
extern int func_02035C08(const void *touchTable);
extern void func_0204B404(void *actor, const FieldMenuScreenPos *delta, u32 which);
extern u32 func_021904AC(u32 mapInfo);
extern void *func_020450F0(u32 layer, u32 x, u32 y, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(void *bmpWin);
extern void *func_02045770(void *bmpWin);
extern void func_02043B5C(void *buf, u8 value);
extern void func_0201C724(void *printQue, void *buf, u32 b, u32 c, void *text, u32 e, u16 f);
extern void *func_0204B324(void *unit, void *charRes, void *palRes, void *cellRes, const FieldMenuActorSetup *setup, u16 space, u16 heapId);
extern unsigned int func_020452E8(void *bmpWin);
extern void func_02045334(void *bmpWin);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_02049EF4(void *arcHandle, u32 a, u32 b, void **out, u32 heapId);
extern void func_020410D0(u32 layer, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u8 layer);

extern const struct BgTemplate d_021D8BBC;
extern const struct BgTemplate d_021D8B5C;
extern const struct BgTemplate d_021D8B7C;
extern const u32 d_021D8B44[];
extern const FieldMenuSurfaceRect d_021D8C1C;
extern const int d_021D8D24[][FIELD_MENU_ITEM_MAX];
extern const FieldMenuName d_021D8C0C;
extern const u16 d_021D8B34[];
extern const FieldMenuIconRes d_021D8CAC[];
extern const FieldMenuWindowPos d_021D8B18[];
extern u8 d_021D8C4C[][8][4];
extern u8 d_021D8B26[];
extern u8 d_021D8B27[];
extern FieldMenuTouchTable d_021D8C2C;
extern char d_021DDF94[];

FieldMenu *func_021A836C(u16 heapId, u16 subHeapId, void *parent, void *fieldMap, int slideIn);
void func_021A84A8(FieldMenu *menu);
void func_021A84BC(FieldMenu *menu);
int func_021A8588(void);
u32 func_021A85B4(FieldMenu *menu);
void func_021A87A8(FieldMenu *menu);
void func_021A8840(FieldMenu *menu);
void func_021A8874(FieldMenu *menu, void *arcHandle, int layoutType, u32 mapInfo);
void func_021A8AFC(int heapId, int hideFrame);
u32 func_021A8B18(void *gameData, void *eventWork, u32 zoneId);
int func_021A8B84(int layoutType);
void func_021A8BB8(FieldMenu *menu, void *arcHandle, int layoutType);
void func_021A8D40(void *taskHandle, FieldMenu *menu);
void func_021A8DD8(FieldMenu *menu);
int func_021A8E10(FieldMenu *menu);
void func_021A8E20(FieldMenu *menu, u32 buttonId);
int func_021A8E78(u32 col, u32 row);
u32 func_021A8E80(FieldMenu *menu, u32 dir);
void func_021A8EEC(FieldMenu *menu);
void func_021A8FFC(FieldMenu *menu);
void func_021A9080(FieldMenu *menu, s16 x, s16 y);
void func_021A90A4(FieldMenu *menu, int back);
void func_021A90E0(FieldMenu *menu);
void func_021A9154(FieldMenu *menu, FieldMenuItem *item, const FieldMenuItemInit *init);
void func_021A926C(FieldMenu *menu, FieldMenuItem *item);
void func_021A9294(FieldMenu *menu, FieldMenuItem *item);
void func_021A92A4(u32 heapId, u32 layer);

/*
 * 0x021DDF94 is the "field_menu.c" file-name string; 0x134 is its line.
 */
FieldMenu *func_021A836C(u16 heapId, u16 subHeapId, void *parent, void *fieldMap, int slideIn)
{
    FieldMenu *menu;
    void *gameSystem;
    void *gameData;
    void *arcHandle;
    u32 layoutType;

    menu = func_02030734(heapId, 0x138, 0, d_021DDF94, 0x134);
    gameSystem = func_02188C80(fieldMap);
    gameData = func_020120F4(gameSystem);
    menu->heapId = heapId;
    menu->subHeapId = subHeapId;
    menu->fieldMap = fieldMap;
    menu->parent = parent;
    menu->state = FIELD_MENU_STATE_WAIT_PRINT;
    menu->zoneId = func_02012AC8(func_020120F8(gameSystem));
    menu->eventWork = func_0201296C(gameData);
    menu->myStatus = func_02012944(gameData);
    menu->mapInfo = func_02188C54(fieldMap);
    menu->cursorCol = 0;
    menu->cursorRow = 0;
    menu->cursorDirty = menu->keyCursorActive = func_020355C4() ^ 1;
    menu->selectedItem = 0;
    menu->colorTask = func_020056A0(func_021A8D40, menu, 0);
    menu->printQue = func_0201C440(menu->heapId);
    menu->scrollDirty = 0;
    menu->scrollY = 0;
    arcHandle = func_020490F4(0x47, menu->subHeapId);
    layoutType = func_021A8B18(gameData, menu->eventWork, menu->zoneId);
    menu->layoutType = layoutType;
    func_021A8874(menu, arcHandle, layoutType, menu->mapInfo);
    func_021A8BB8(menu, arcHandle, layoutType);
    func_02049238(arcHandle);
    func_02040588(1, 1);
    if (slideIn == 1) {
        menu->cursorCol = 0;
        menu->cursorRow = 0;
        menu->cursorDirty = 1;
        func_021A90E0(menu);
        func_021A8DD8(menu);
    } else {
        func_021A8E20(menu, func_020129C4(gameData));
        menu->cursorDirty = 1;
        if (menu->keyCursorActive != 0) {
            func_0204B3DC(menu->cursorActor, 1);
        } else {
            func_0204B3DC(menu->cursorActor, 0);
        }
    }
    func_0203D34C(0, menu->subHeapId);
    return menu;
}

/* Tells the parent the menu is leaving when the player asked to close it. */
void func_021A84A8(FieldMenu *menu)
{
    if (menu->exitRequested == 1) {
        func_021A0FB4(menu->parent, menu->heapId);
    }
}

void func_021A84BC(FieldMenu *menu)
{
    u8 i;

    for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
        func_021A926C(menu, &menu->items[i]);
    }
    func_021A84A8(menu);
    func_02030EAC(menu->colorTask);
    func_0204B3B4(menu->backActor);
    func_0204B3B4(menu->cursorActor);
    func_0204B084(menu->clactSurface);
    func_0204B1CC(menu->clactUnit);
    func_0204AFD8(menu->cellRes);
    func_0204A8D4(menu->charRes);
    func_0204ADA4(menu->palRes);
    func_0204AFD8(menu->cellResB);
    func_0204A8D4(menu->charResB);
    func_0204ADA4(menu->palResB);
    func_02040618(6, 3, 0);
    func_020403F4(7);
    func_020403F4(5);
    func_020403F4(6);
    func_0201C6EC(menu->printQue);
    func_0201C4C0(menu->printQue);
    func_020307B0(menu);
}

/* Shows the menu BG layers again after a slide or a wipe. */
int func_021A8588(void)
{
    func_020409B4(6);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    return func_02040588(7, 1);
}

/* Per-frame update; returns the print queue state for the parent's main. */
u32 func_021A85B4(FieldMenu *menu)
{
    u8 i;
    s16 scrollY;
    FieldMenuItem *item;

    switch (menu->state) {
    case FIELD_MENU_STATE_WAIT_PRINT:
        if (func_0201C6B4(menu->printQue) == 1) {
            func_021A12D4(menu->parent, menu->subHeapId);
            for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
                func_021A9294(menu, &menu->items[i]);
            }
            if (menu->scrollY != 0) {
                func_020061E4(SE_FIELD_MENU_SLIDE_IN);
                menu->state = FIELD_MENU_STATE_SLIDE_IN;
            } else {
                menu->state = FIELD_MENU_STATE_WAIT_WIPE;
                func_021A8588();
            }
        }
        break;
    case FIELD_MENU_STATE_SLIDE_IN:
        scrollY = menu->scrollY;
        if (scrollY < FIELD_MENU_SCROLL_STEP) {
            menu->scrollY = 0;
            menu->state = FIELD_MENU_STATE_IDLE;
            func_021A8588();
        } else {
            menu->scrollY = scrollY - FIELD_MENU_SCROLL_STEP;
            func_021A87A8(menu);
        }
        menu->scrollDirty = 1;
        break;
    case FIELD_MENU_STATE_WAIT_WIPE:
        if (func_020221A4() == 1) {
            func_021A12D4(menu->parent, menu->subHeapId);
            menu->state = FIELD_MENU_STATE_IDLE;
        }
        break;
    case FIELD_MENU_STATE_IDLE:
        func_021A8EEC(menu);
        func_021A8FFC(menu);
        func_021A90E0(menu);
        break;
    case FIELD_MENU_STATE_BACK_ANIM:
        if (func_0204B98C(menu->backActor) != 0) {
            break;
        }
        menu->state = FIELD_MENU_STATE_DECIDE;
        func_02040588(5, 1);
        func_02040588(6, 1);
        func_02040588(7, 1);
        func_02040588(4, 1);
        break;
    case FIELD_MENU_STATE_DECIDE:
        if (menu->exitRequested == 1 || menu->cursorRow == 3) {
            menu->state = FIELD_MENU_STATE_SLIDE_OUT;
            func_020061E4(SE_FIELD_MENU_CLOSE);
            func_02040588(4, 0);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02040588(7, 1);
            func_0204B3DC(menu->backActor, 0);
        } else {
            item = menu->selectedItem;
            if (item->actor != 0) {
                menu->pressFrames = 0;
                func_021A9080(menu, item->cursorX, item->cursorY);
                func_0204B878(menu->cursorActor, 1);
                func_0204B3DC(menu->cursorActor, 1);
                menu->state = FIELD_MENU_STATE_PRESS_ANIM;
                func_020061E4(SE_FIELD_MENU_PRESS);
            } else {
                menu->state = FIELD_MENU_STATE_NOTIFY_SELECT;
            }
        }
        break;
    case FIELD_MENU_STATE_PRESS_ANIM:
        menu->pressFrames++;
        if (func_0204B98C(menu->cursorActor) == 0) {
            menu->state = FIELD_MENU_STATE_NOTIFY_SELECT;
        }
        break;
    case FIELD_MENU_STATE_NOTIFY_CLOSE:
        func_021A0FA0(menu->parent, FIELD_MENU_NEXT_CLOSE);
        menu->state = FIELD_MENU_STATE_DONE;
        break;
    case FIELD_MENU_STATE_NOTIFY_SELECT:
        func_021A0FA0(menu->parent, FIELD_MENU_NEXT_SELECT);
        menu->state = FIELD_MENU_STATE_DONE;
        break;
    case FIELD_MENU_STATE_SLIDE_OUT:
        if (menu->scrollY + FIELD_MENU_SCROLL_STEP > FIELD_MENU_SCROLL_HIDDEN) {
            menu->scrollY = FIELD_MENU_SCROLL_HIDDEN;
            menu->state = FIELD_MENU_STATE_NOTIFY_CLOSE;
        } else {
            menu->scrollY += FIELD_MENU_SCROLL_STEP;
            func_021A87A8(menu);
        }
        menu->scrollDirty = 1;
        break;
    }
    return func_0201C4E4(menu->printQue);
}

/*
 * Moves the icon surface to the current scroll and hides the icons and the
 * cursor that have slid below the visible part of the screen.
 */
void func_021A87A8(FieldMenu *menu)
{
    FieldMenuScreenPos surfaceOffset;
    FieldMenuScreenPos iconPos;
    FieldMenuScreenPos cursorPos;
    u8 i;

    surfaceOffset.x = 0;
    surfaceOffset.y = -menu->scrollY;
    func_0204B09C(menu->clactSurface, 0, &surfaceOffset);
    for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
        if (menu->items[i].actor != 0 && menu->items[i].buttonId != FIELD_MENU_BUTTON_EMPTY) {
            func_0204B454(menu->items[i].actor, &iconPos, 0);
            if (iconPos.y < FIELD_MENU_ICON_CULL_Y) {
                func_0204B3DC(menu->items[i].actor, 1);
            } else {
                func_0204B3DC(menu->items[i].actor, 0);
            }
        }
    }
    func_0204B454(menu->cursorActor, &cursorPos, 0);
    if (menu->keyCursorActive != 0 && cursorPos.y < FIELD_MENU_CURSOR_CULL_Y) {
        func_0204B3DC(menu->cursorActor, 1);
    } else {
        func_0204B3DC(menu->cursorActor, 0);
    }
}

/* Applies the scroll to the BG layers 5 and 6 when it changed. */
void func_021A8840(FieldMenu *menu)
{
    if (menu->scrollDirty == 1) {
        func_02041EE4(5, 3, -menu->scrollY);
        func_02041EE4(6, 3, -FIELD_MENU_LAYER6_OFFSET - menu->scrollY);
        menu->scrollDirty = 0;
    }
}

/*
 * Sets up the BG layers 5 to 7, loads the screen, palette, icon and cursor
 * resources and creates the cursor and back button actors.
 */
void func_021A8874(FieldMenu *menu, void *arcHandle, int layoutType, u32 mapInfo)
{
    void *commonArc;
    u32 cellId;
    FieldMenuActorPos pos;
    FieldMenuSurfaceRect surfaceRect;

    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0203FCA0(5, &d_021D8BBC, 0);
    func_02040588(5, 1);
    func_020414EC(5);
    func_0203FCA0(6, &d_021D8B5C, 0);
    func_02040588(6, 1);
    func_020414EC(6);
    func_0203FCA0(7, &d_021D8B7C, 0);
    func_02040588(7, 1);
    func_020414EC(7);
    func_02040618(6, 3, -FIELD_MENU_LAYER6_OFFSET);
    func_02049B68(arcHandle, 0, 4, 0, 0, menu->subHeapId);
    func_02049658(arcHandle, 2, 5, 0, 0, 0, menu->subHeapId);
    func_020498F4(arcHandle, d_021D8B44[layoutType], 5, 0, 0, 0, menu->subHeapId);
    func_020498F4(arcHandle, 0xE, 7, 0, 0, 0, menu->subHeapId);
    menu->palRes = func_0204AC18(arcHandle, 1, 1, 0, 0, 0xB, menu->heapId);
    menu->charRes = func_0204A6C8(arcHandle, 0xD, 0, 1, menu->heapId);
    menu->cellRes = func_0204AF28(arcHandle, 0x1C, 0x26, menu->heapId);
    commonArc = func_020490F4(func_020275E4(), menu->subHeapId);
    menu->palResB = func_0204AC18(commonArc, func_02027614(), 1, 0x160, 0, 2, menu->heapId);
    menu->charResB = func_0204A6C8(commonArc, func_02027618(), 0, 1, menu->heapId);
    cellId = func_0202761C(0);
    menu->cellResB = func_0204AF28(commonArc, cellId, func_02027620(0), menu->heapId);
    func_02049238(commonArc);
    func_020409B4(5);
    menu->clactUnit = func_0204B100(8, 0, menu->heapId);
    surfaceRect = d_021D8C1C;
    menu->clactSurface = func_0204B034(&surfaceRect, 1, menu->heapId);
    func_0204B258(menu->clactUnit, menu->clactSurface);
    pos.x = 0x40;
    pos.y = 0x2C;
    pos.z = 0;
    pos.flip = 0;
    pos.palOffset = 0;
    menu->cursorActor = func_0204B294(menu->clactUnit, menu->charRes, menu->palRes, menu->cellRes, &pos, 0, menu->heapId);
    func_0204B954(menu->cursorActor, 0x1000);
    func_0204B92C(menu->cursorActor, 1);
    func_0204B84C(menu->cursorActor, 2);
    pos.x = 0xE0;
    pos.y = 0xA8;
    menu->backActor = func_0204B294(menu->clactUnit, menu->charResB, menu->palResB, menu->cellResB, &pos, 0, menu->heapId);
    func_0204B954(menu->backActor, 0x1000);
    func_0204B92C(menu->backActor, 1);
    func_0204B3DC(menu->backActor, 1);
    func_0204B954(menu->backActor, 0x2000);
}

/* Loads the frame screen into the given layer; hideFrame turns layer 4 off. */
void func_021A8AFC(int heapId, int hideFrame)
{
    func_021A92A4(heapId, 4);
    if (hideFrame != 0) {
        func_02040588(4, 0);
    }
}

/*
 * Picks the button layout from the story progress: 1 in the early-game
 * zones, 4 and 5 for the two special states, then 3 and 2 until the two
 * event flags are set; 0 is the full layout.
 */
u32 func_021A8B18(void *gameData, void *eventWork, u32 zoneId)
{
    u32 layoutType = 0;

    if (func_02013CC8((u16)zoneId) || func_02013CE0(zoneId)) {
        layoutType = 1;
    } else if (func_02013D20(zoneId)) {
        layoutType = 4;
    } else if (func_02012B70(gameData)) {
        layoutType = 5;
    } else if (!func_020142E8(eventWork, 0x961)) {
        layoutType = 3;
    } else if (!func_020142E8(eventWork, 0x962)) {
        layoutType = 2;
    }
    return layoutType;
}

/* Counts the slots of a layout that hold a button. */
int func_021A8B84(int layoutType)
{
    int i;
    int count;

    i = 0;
    count = 0;
    for (; d_021D8D24[layoutType][i] != 0; i++) {
        if (d_021D8D24[layoutType][i] != FIELD_MENU_BUTTON_EMPTY) {
            count++;
        }
    }
    return count;
}

/* Builds the seven slots of the layout from the button table and the message bank. */
void func_021A8BB8(FieldMenu *menu, void *arcHandle, int layoutType)
{
    void *msgBank;
    u8 i;
    u8 j;
    int buttonId;
    const int *layoutRow;
    FieldMenuItemInit init;
    FieldMenuName nameBuf;
    FieldMenuName defaultName;

    msgBank = func_02045B38(0, 2, 0x22, menu->subHeapId);
    for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
        menu->items[i].inUse = 0;
    }
    j = 0;
    layoutRow = d_021D8D24[layoutType];
    defaultName = d_021D8C0C;
    for (; j < FIELD_MENU_ITEM_MAX; j++) {
        buttonId = layoutRow[j];
        if (buttonId == FIELD_MENU_BUTTON_PLAYER) {
            init.text = func_020457B0(0x10, menu->subHeapId);
            if (func_020084BC(menu->myStatus) == 0) {
                func_02045924(init.text, func_020084F4(menu->myStatus));
            } else {
                nameBuf = defaultName;
                func_02045924(init.text, nameBuf.chars);
            }
        } else {
            init.text = func_02045EC0(msgBank, d_021D8B34[buttonId]);
        }
        init.buttonId = buttonId;
        if (j != FIELD_MENU_ITEM_BACK) {
            init.cursorX = (j % 2) * 128 + 0x40;
            init.cursorY = (j / 2) * 0x30 + 0x2C;
            init.iconX = init.cursorX - 0x20;
            init.iconY = init.cursorY;
            init.arcHandle = arcHandle;
            init.charId = d_021D8CAC[buttonId].charId;
            init.cellId = d_021D8CAC[buttonId].cellId;
            init.animId = d_021D8CAC[buttonId].animId;
            if (buttonId == 3 && func_02008550(menu->myStatus) == 1) {
                init.charId = 7;
                init.cellId = 0x16;
                init.animId = 0x20;
            }
            if (buttonId == 2 && func_02008550(menu->myStatus) == 1) {
                init.charId = 0xC;
                init.cellId = 0x1B;
                init.animId = 0x25;
            }
        } else {
            init.cursorX = 0x80;
            init.cursorY = 0xB4;
            init.iconX = 0;
            init.iconY = 0;
            init.arcHandle = 0;
            init.charId = 0;
            init.cellId = 0;
            init.animId = 0;
        }
        init.winTileX = d_021D8B18[j].tileX;
        init.winTileY = d_021D8B18[j].tileY;
        func_021A9154(menu, &menu->items[j], &init);
        func_02045808(init.text);
    }
    func_02045C04(msgBank);
}

/* Task proc: cycles two palette colors of the menu with a sine of the phase counter. */
void func_021A8D40(void *taskHandle, FieldMenu *menu)
{
    s32 wave = func_0203F684((u16)menu->colorPhase) + 0x1000;
    u16 colors[2];

    colors[1] = (wave * 8 / 0x2000 + 9) | ((0x1F << 10) | ((wave * 5 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&colors[1], 0x142, 2);
    colors[0] = (wave * 0x1F / 0x2000) |
                (((wave * 6 / 0x2000 + 0x19) << 10) | ((wave * 13 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&colors[0], 0x15E, 2);
    menu->colorPhase += 6;
}

/* Puts the menu in its fully scrolled-out state. */
void func_021A8DD8(FieldMenu *menu)
{
    FieldMenuScreenPos offset;

    menu->scrollY = FIELD_MENU_SCROLL_HIDDEN;
    func_02040618(5, 3, -FIELD_MENU_SCROLL_HIDDEN);
    func_02040618(6, 3, -(FIELD_MENU_SCROLL_HIDDEN + FIELD_MENU_LAYER6_OFFSET));
    offset.x = 0;
    offset.y = FIELD_MENU_SCROLL_HIDDEN;
    func_0204B09C(menu->clactSurface, 0, &offset);
}

/* Returns the button id of the selected slot, or 0 when none is selected. */
int func_021A8E10(FieldMenu *menu)
{
    FieldMenuItem *item = menu->selectedItem;

    if (item == 0) {
        return 0;
    }
    return item->buttonId;
}

/* Moves the cursor to the slot that holds the given button. */
void func_021A8E20(FieldMenu *menu, u32 buttonId)
{
    u8 i;
    FieldMenuItem *items;

    for (i = 0, items = menu->items; i < FIELD_MENU_ITEM_MAX; i++) {
        if (menu->items[i].inUse == 1 && buttonId == menu->items[i].buttonId) {
            menu->cursorCol = i % 2;
            menu->cursorRow = i / 2;
            menu->cursorDirty = 1;
            func_021A9080(menu, items[menu->cursorCol + menu->cursorRow * 2].cursorX, items[menu->cursorCol + menu->cursorRow * 2].cursorY);
        }
    }
}

/* Slot index of a cursor position: two columns per row. */
int func_021A8E78(u32 col, u32 row)
{
    return (col + (row << 1));
}

/*
 * Moves the cursor one step in a direction (0 up, 1 down, 2 left, 3 right)
 * using the transition tables of the layout; returns 1 when it moved.
 */
u32 func_021A8E80(FieldMenu *menu, u32 dir)
{
    u32 index = func_021A8E78(menu->cursorCol, menu->cursorRow);
    u32 target = d_021D8C4C[func_021A8B84(menu->layoutType) - 4][index][dir];

    if (index != target) {
        if (target == 0xFF) {
            menu->cursorRow = 2;
            return 1;
        }
        if (target == 0xFE) {
            menu->cursorRow = 1;
            return 1;
        }
        if (target != FIELD_MENU_ITEM_BACK) {
            menu->cursorCol = d_021D8B26[target * 2];
        }
        menu->cursorRow = d_021D8B27[target * 2];
        return 1;
    }
    return 0;
}

/* Key input: moves the cursor, or selects the slot under it, or closes the menu. */
void func_021A8EEC(FieldMenu *menu)
{
    u32 pressed;
    u32 repeated;

    pressed = func_020362DC();
    repeated = func_0203633C();
    if (menu->keyCursorActive == 0 && (pressed | repeated) != 0) {
        if ((pressed & FIELD_MENU_PAD_B) || (pressed & FIELD_MENU_PAD_X)) {
            func_021A90A4(menu, 1);
            return;
        }
        func_020061E4(SE_FIELD_MENU_MOVE);
        menu->keyCursorActive = 1;
        menu->selectedItem = 0;
        menu->cursorDirty = 1;
        func_0204B3DC(menu->cursorActor, 1);
        return;
    }
    if (repeated & FIELD_MENU_PAD_UP) {
        if (func_021A8E80(menu, 0) != 0) {
            menu->cursorDirty = 1;
            func_020061E4(SE_FIELD_MENU_MOVE);
        }
    } else if (repeated & FIELD_MENU_PAD_DOWN) {
        if (func_021A8E80(menu, 1) != 0) {
            menu->cursorDirty = 1;
            func_020061E4(SE_FIELD_MENU_MOVE);
        }
    } else if (repeated & FIELD_MENU_PAD_LEFT) {
        if (func_021A8E80(menu, 2) != 0) {
            menu->cursorDirty = 1;
            func_020061E4(SE_FIELD_MENU_MOVE);
        }
    } else if (repeated & FIELD_MENU_PAD_RIGHT) {
        if (func_021A8E80(menu, 3) != 0) {
            menu->cursorDirty = 1;
            func_020061E4(SE_FIELD_MENU_MOVE);
        }
    } else if ((pressed & FIELD_MENU_PAD_B) || (pressed & FIELD_MENU_PAD_X)) {
        func_021A90A4(menu, 1);
    } else if (pressed & FIELD_MENU_PAD_A) {
        if (menu->items[func_021A8E78(menu->cursorCol, menu->cursorRow)].buttonId != FIELD_MENU_BUTTON_EMPTY) {
            func_021A90A4(menu, 0);
            func_020355D8(0);
        }
    }
}

/* Touch input: a tap on a slot moves the cursor there and selects it. */
void func_021A8FFC(FieldMenu *menu)
{
    FieldMenuTouchTable touchTable = d_021D8C2C;
    int hitSlot = func_02035C08(&touchTable);
    u32 zero;

    if (hitSlot != -1 && menu->items[hitSlot].buttonId != FIELD_MENU_BUTTON_EMPTY) {
        menu->cursorCol = hitSlot % 2;
        menu->cursorRow = hitSlot / 2;
        zero = 0;
        menu->keyCursorActive = zero;
        func_0204B3DC(menu->cursorActor, 0);
        if (hitSlot == FIELD_MENU_ITEM_BACK) {
            func_021A90A4(menu, 1);
            return;
        }
        menu->cursorDirty = 1;
        func_021A90A4(menu, zero);
        func_020355D8(1);
    }
}

/* Moves the cursor actor to a position and restarts the color phase. */
void func_021A9080(FieldMenu *menu, s16 x, s16 y)
{
    FieldMenuScreenPos pos;

    pos.x = x;
    pos.y = y;
    func_0204B404(menu->cursorActor, &pos, 0);
    menu->colorPhase = 0;
}

/* Starts leaving the menu: back = 1 plays the back button, else the slot is chosen. */
void func_021A90A4(FieldMenu *menu, int back)
{
    if (back == 1) {
        menu->exitRequested = 1;
        menu->state = FIELD_MENU_STATE_BACK_ANIM;
        func_0204B878(menu->backActor, 8);
    } else {
        menu->exitRequested = 0;
        menu->state = FIELD_MENU_STATE_DECIDE;
        menu->chosenButton = menu->items[func_021A8E78(menu->cursorCol, menu->cursorRow)].buttonId;
    }
}

/* Applies a cursor move: selects the new slot and swaps the highlighted icon animation. */
void func_021A90E0(FieldMenu *menu)
{
    FieldMenuItem *previous;

    if (menu->cursorDirty == 1) {
        previous = menu->selectedItem;
        menu->selectedItem = &menu->items[menu->cursorCol + menu->cursorRow * 2];
        func_0204B878(menu->cursorActor, 0);
        func_021A9080(menu, menu->selectedItem->cursorX, menu->selectedItem->cursorY);
        if (menu->selectedItem->actor != 0 && menu->keyCursorActive == 1) {
            func_0204B878(menu->selectedItem->actor, 1);
        }
        if (previous != 0 && previous->actor != 0) {
            func_0204B878(previous->actor, 0);
        }
        menu->cursorDirty = 0;
    }
}

/* Creates one slot: its text window, icon resources and icon actor. */
void func_021A9154(FieldMenu *menu, FieldMenuItem *item, const FieldMenuItemInit *init)
{
    FieldMenuActorSetup setup;
    u32 textColor;

    textColor = func_021904AC(func_02188C54(menu->fieldMap));
    item->inUse = 1;
    item->buttonId = init->buttonId;
    item->cursorX = init->cursorX;
    item->cursorY = init->cursorY;
    item->bmpWin = func_020450F0(6, init->winTileX, init->winTileY, 8, 2, 0xD, 1);
    func_02045374(item->bmpWin);
    func_02043B5C(func_02045770(item->bmpWin), 0);
    func_0201C724(menu->printQue, func_02045770(item->bmpWin), 2, 1, init->text, textColor, 0x440);
    if (init->arcHandle != 0) {
        item->charRes = func_0204A6C8(init->arcHandle, init->charId, 0, 1, menu->heapId);
        item->cellRes = func_0204AF28(init->arcHandle, init->cellId, init->animId, menu->heapId);
        setup.x = init->iconX;
        setup.y = init->iconY;
        setup.z = 0;
        setup.flip = 0;
        setup.palOffset = 0;
        setup.bgPriority = 0;
        setup.reserved0A = 0;
        setup.scaleX = 0x1000;
        setup.scaleY = 0x1000;
        setup.rotation = 0;
        setup.drawArea = 2;
        item->actor = func_0204B324(menu->clactUnit, item->charRes, menu->palRes, item->cellRes, &setup, 0, menu->heapId);
        func_0204B954(item->actor, 0x1000);
        func_0204B92C(item->actor, 1);
        func_0204B878(item->actor, 0);
        if (item->buttonId == FIELD_MENU_BUTTON_EMPTY) {
            func_0204B3DC(item->actor, 0);
        } else {
            func_0204B3DC(item->actor, 1);
        }
    } else {
        item->actor = 0;
    }
}

/* Frees the window and the icon resources of one slot. */
void func_021A926C(FieldMenu *menu, FieldMenuItem *item)
{
    if (item->inUse == 1) {
        func_020452E8(item->bmpWin);
        if (item->actor != 0) {
            func_0204B3B4(item->actor);
            func_0204AFD8(item->cellRes);
            func_0204A8D4(item->charRes);
        }
    }
}

/* Pushes the slot window to the screen once its text is printed. */
void func_021A9294(FieldMenu *menu, FieldMenuItem *item)
{
    if (item->inUse == 1) {
        func_02045334(item->bmpWin);
    }
}

/*
 * Loads the frame screen file and writes it to a BG layer with palette 3 and
 * tile base 0x80.
 * 0x021A8E14 is not a function: it lies inside func_021A8E10 (bytes
 * 0x021A8E10..0x021A8E1F), the listing has no label there and nothing calls it.
 * The old src/matched func_021A8E14 (an SDK signature hit on EL_GetLibSize)
 * matched the tail of func_021A8E10.
 */
void func_021A92A4(u32 heapId, u32 layer)
{
    FieldMenuScreenData *screen;
    void *screenBuf;
    int i;
    u16 *tiles;
    void *arcHandle;

    arcHandle = func_020490F4(func_020275E4(), heapId);
    func_02049B68(arcHandle, func_02027624(), 4, 0x60, 0x20, heapId);
    func_02049658(arcHandle, func_02027628(), layer, 0x80, 0, 0, heapId);
    screenBuf = func_02049EF4(arcHandle, func_0202762C(), 0, (void **)&screen, heapId);
    func_02049238(arcHandle);
    tiles = screen->tiles;
    for (i = 0; i < 0x300; i++) {
        tiles[i] = (tiles[i] + 0x80) | 0x3000;
    }
    func_020410D0((u8)layer, 0, 0x15, 0x20, 3, (u32)screen->tiles, 0, 0x15, 0x20, 0x18);
    func_02041B6C(layer);
    func_020307B0(screenBuf);
}
