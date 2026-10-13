/*
 * file:     shortcut_menu.c
 * unit:     yes
 * function: func_021C4F7C, func_021C51A0, func_021C5224, func_021C5334, func_021C5348, func_021C536C, func_021C5380, func_021C5394, func_021C53A0, func_021C5424, func_021C5440, func_021C54C8, func_021C553C, func_021C56F8, func_021C5768, func_021C576C, func_021C577C, func_021C5880, func_021C58CC, func_021C59A8, func_021C59BC, func_021C59F8
 * address:  0x021C4F7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_splash.c at 0x021C4F7C (lane FXC, CL129: allocation with the shortcut_menu.c file string at 021C4F7C).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040C14  0x02040C14  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C450  0x0201C450  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C40C  0x0200C40C  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   d_021DE498     0x021DE498  data  ov021  a1
 *   d_021DAA60     0x021DAA60  data  a4
 *   d_021DAA54     0x021DAA54  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020202FC  0x020202FC  thumb
 *   func_02020324  0x02020324  thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020202EC 0x020202EC thumb
 *   func_02020350 0x02020350 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020200CC 0x020200CC thumb
 *   func_02020344 0x02020344 thumb
 *   func_0200C480 0x0200C480 thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02020314 0x02020314 thumb
 *   func_0200C468 0x0200C468 thumb
 *   func_0200C464 0x0200C464 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   d_021DAA80    0x021DAA80 data  a4
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   abs_id_C2      0x000000C2  data
 *   ov171_id       0x000000AB  data  a1
 */
#include "field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct X;
struct Actor;
struct Res_021C48A0;
struct IcaAnime;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
struct GfFont;
struct MsgBank;
struct Obj;
struct PrintSys;
struct Rec;
struct Node;
struct Descriptor;
struct Cfg;
struct Slot;
struct Src;
struct PtS;
struct Vec2;
struct Desc;
struct Evt;
struct BigObj;
struct Ctx;
struct Sub02008C20Obj;
struct Self;
struct S0201235C;

typedef signed short   s16_021C48A0;

typedef signed char    s8;

typedef int            s32_021C4E6C;

typedef signed int     s32_021C4F7C;

typedef struct ShortcutActorPos {
    u16 x;
    u16 y;
    u16 z;
    u8 animNo;
    u8 flags;
} ShortcutActorPos;

typedef struct ShortcutActorOffset {
    s16 x;
    s16 y;
} ShortcutActorOffset;

/* List menu template (0x34 bytes); the shortcut menu copies the const one and fills the pointers. */
typedef struct ShortcutListTemplate {
    void *items;                          /* 0x00 */
    void *moveCursorFunc;                 /* 0x04 */
    void *printFunc;                      /* 0x08 */
    struct Descriptor *window;            /* 0x0C */
    u16 totalItems;                       /* 0x10 */
    u16 maxShown;                         /* 0x12 */
    u8 headerX;                           /* 0x14 */
    u8 itemX;                             /* 0x15 */
    u8 cursorX;                           /* 0x16 */
    u8 upText;                            /* 0x17 */
    u8 cursorPal;                         /* 0x18 */
    u8 fillValue;                         /* 0x19 */
    u8 cursorShadowPal;                   /* 0x1A */
    u8 lettersSpacing;                    /* 0x1B */
    void *cbParam;                        /* 0x1C: the ShortcutMenu */
    u16 itemHeight;                       /* 0x20 */
    u16 scrollStep;                       /* 0x22 */
    struct MsgBank *msgBank;              /* 0x24 */
    struct Descriptor **windowRef;        /* 0x28 */
    struct PrintSys *printSys;            /* 0x2C */
    struct GfFont *font;                  /* 0x30 */
} ShortcutListTemplate;

/*
 * Work of the field shortcut menu (created at 0x021C4F7C, 0x88 bytes). The
 * first 0x4C bytes are cleared again by ShortcutMenu_InitList.
 */
typedef struct ShortcutMenu {
    void *listItems;                      /* 0x00: list entry table */
    struct Obj *list;                     /* 0x04: the list menu */
    struct Descriptor *window;            /* 0x08 */
    struct PrintSys *printSys;            /* 0x0C */
    struct Descriptor *printWindow;       /* 0x10 */
    u8 printBusy;                         /* 0x14 */
    u8 pad15[3];
    int selection;                        /* 0x18: -1 none, -2 cancelled */
    u16 savedScroll;                      /* 0x1C: list scroll when move mode started */
    u16 savedCursor;                      /* 0x1E: list cursor when move mode started */
    void *menuData;                       /* 0x20: the shortcut entries */
    u32 moveMode;                         /* 0x24: 1 while an entry is being moved */
    struct Obj *listActors[3];            /* 0x28: copy of actors, set by InitList */
    u16 heapId;                           /* 0x34 */
    u16 pad36;
    struct MsgBank *msgBank;              /* 0x38 */
    struct GfFont *font;                  /* 0x3C */
    u32 cursorWrapped;                    /* 0x40 */
    u32 redrawBg;                         /* 0x44 */
    u32 showActors;                       /* 0x48 */
    struct Bank *actorBank;               /* 0x4C */
    u16 charResId;                        /* 0x50 */
    u16 palResId;                         /* 0x52 */
    u16 cellResId;                        /* 0x54 */
    u16 pad56;
    struct Obj *actors[3];                /* 0x58: the three cursor actors */
    struct MsgBank *ownedMsgBank;         /* 0x64 */
    struct GfFont *ownedFont;             /* 0x68 */
    struct PrintSys *ownedPrintSys;       /* 0x6C */
    u16 state;                            /* 0x70 */
    u16 scrollFrame;                      /* 0x72 */
    u32 resultKind;                       /* 0x74: 0 none, 1 picked, 2 cancelled */
    int resultValue;                      /* 0x78 */
    const u16 *savedState;                /* 0x7C: {scroll, cursor} kept by the caller */
    u32 scrollDone;                       /* 0x80 */
    struct Node *scrollTask;              /* 0x84 */
} ShortcutMenu;

typedef signed short   s16_021C59A8;

typedef short s16_021C577C;

typedef struct { fx32 m[3][3]; } MtxFx33;

/* Entry template for BILLBOARD_ACT_CreateEntries (0x24 bytes). */
typedef struct BbActDesc {
    u16 imageIdx;
    u16 scaleX;
    u16 scaleY;
    u8 alpha;
    u8 pad07;
    u32 visible;
    u32 animEnable;
    VecFx32 pos;
    void (*onEnd)(void);
    void *userData;
} BbActDesc;

/* Image record for BILLBOARD_ACT_CreateSlots. */
typedef struct BbActRec {
    void *resource;
    u8 type;
    u8 imageId;
    u8 cellWidth;
    u8 cellHeight;
    u32 count;
} BbActRec;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02082BCC(void *p, int v, int n);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern s32_021C4F7C func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021C4F7C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C4F7C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *obj, unsigned int v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0201C450(u16 n, u32 heap);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C40C(void *sys);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204B3B4(struct Obj *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_020061E4(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_02030EAC(struct Node *n);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02020350(struct Obj *obj, u32 what);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_020355D8(u8 v);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020344(struct Obj *obj, u32 n);
extern u8 func_0200C480(u8 *a, int id, u8 pos);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u16 func_02020314(struct Obj *obj);
extern u16 func_0200C468(const u8 *a);
extern u8 func_0200C464(const u8 *a, u32 i);
extern void *func_0201F81C(int n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern u32 func_0201F868(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
/* Retain the mode used to store f59 for the helper's second argument. */
ShortcutMenu *func_021C4F7C(void *gameSystem, int mode, const u16 *savedState, u16 textHeapId, u16 heapId);
void func_021C51A0(ShortcutMenu *menu);
void func_021C5224(ShortcutMenu *menu);
int func_021C5334(ShortcutMenu *menu);
void func_021C5348(ShortcutMenu *menu);
void func_021C536C(ShortcutMenu *menu);
int func_021C5380(ShortcutMenu *menu);
u32 func_021C5394(ShortcutMenu *menu, u32 *outValue);
void func_021C53A0(ShortcutMenu *menu, const u16 *savedState, struct MsgBank *msgBank, struct GfFont *font, struct PrintSys *printSys, void *menuData, struct Obj **actors, u16 heapId);
int func_021C5424(ShortcutMenu *menu, u16 *savedState);
void func_021C5440(ShortcutMenu *menu, int cursor, u32 itemCount, u32 *done);
void func_021C54C8(ShortcutMenu *menu, int cursor, int itemCount, int *done);
void func_021C553C(ShortcutMenu *menu);
int func_021C56F8(ShortcutMenu *menu);
int func_021C5768(ShortcutMenu *menu);
void func_021C576C(void *list);
void func_021C577C(void *list, int unused0, int unused1);
void func_021C5880(u16 *scroll, u16 *cursor, u16 itemCount);
void func_021C58CC(ShortcutMenu *menu, u16 scroll, u16 cursor, u32 heapId);
int func_021C59A8(ShortcutMenu *menu, u16 *outScroll, u16 *outCursor);
void func_021C59BC(void *task, ShortcutMenu *menu);
void func_021C59F8(ShortcutMenu *menu, int offsetY);
extern char d_021DE498[];
extern const u32 d_021DAA60[];
extern const u32 d_021DAA54[];
extern const ShortcutListTemplate d_021DAA80;
extern unsigned char abs_id_C2[];
extern char ov171_id[];
/*
 * The heap id is a u16 stack parameter, and the callees it feeds take a u16
 * heap too (docs/idioms/narrow-stack-parameters-and-callee-prototype-free-
 * the-narrow-home-store.md): only then does the u16 textHeapId home store
 * `str r3, [sp, #0x18]` lead the prologue. With u32 heap it sank below
 * `ldr r7, [sp, #0x40]; str r0, [sp, #0x10]` (6 bytes). pos.y = 0x60 is
 * written once before the loop, and the element address is spelled
 * menu + i * 4 + 0x58 (r6 = menu + i*4 shared with the table index).
 */
ShortcutMenu *func_021C4F7C(void *gameSystem, int mode, const u16 *savedState, u16 textHeapId, u16 heapId)
{
    ShortcutActorPos pos;
    int tileBase;
    ShortcutMenu *menu;
    void *resArchive;
    int i;

    i = 0;
    menu = func_02030734(heapId, 0x88, 0, d_021DE498, 0xFC);
    func_02082BCC(menu, 0, 0x88);
    menu->resultKind = 0;
    menu->resultValue = 25;
    menu->savedState = savedState;
    func_0203FCA0(1, (const struct BgTemplate *)d_021DAA60, 0);
    func_020414AC(1);
    func_02040C14(1, 0, 1, 0);
    menu->actorBank = func_0204B100(8, 0, heapId);
    tileBase = 0x80;
    resArchive = func_020490F4(0x80, heapId);
    func_02049B68(resArchive, 0, 0, tileBase + 0xE0, 0x40, heapId);
    menu->charResId = func_0204ABF0(resArchive, 4, 0, 0x40, heapId);
    menu->palResId = func_0204A6C8(resArchive, 3, 0, 0, heapId);
    menu->cellResId = func_0204AF28(resArchive, 2, 1, heapId);
    tileBase += 0xC0;
    func_02049B68(resArchive, 6, 0, tileBase, 0x20, heapId);
    func_02049658(resArchive, 5, 1, 0, 0, 0, heapId);
    func_020498F4(resArchive, 7, 1, 0, 0, 0, heapId);
    func_020413B0(1, 0, 11, 32, 1, 10);
    func_02049238(resArchive);
    func_02082BCC(&pos, 0, 8);
    pos.y = 0x60;
    for (i = 0; i < 3; i++) {
        pos.z = i;
        pos.x = d_021DAA54[i];
        menu->actors[i] = func_0204B294(menu->actorBank, menu->palResId, menu->charResId, menu->cellResId, &pos, 0, heapId);
        func_0204B3DC(menu->actors[i], 0);
        func_0204B92C(menu->actors[i], 1);
    }
    menu->ownedMsgBank = func_02045B38(0, 2, 0xAD, heapId);
    menu->ownedFont = func_0201D7EC(0x17, 0, 0, 0, textHeapId);
    menu->ownedPrintSys = func_0201C450(0x1000, heapId);
    func_021C53A0(menu, menu->savedState, menu->ownedMsgBank, menu->ownedFont,
        menu->ownedPrintSys, func_0200C40C(func_02012EBC(gameSystem)), menu->actors, textHeapId);
    func_02041B6C(1);
    func_0207D63C(0x04000050, 2, 1, 12, 4);
    switch (mode) {
    case 0:
        func_02040618(1, 3, -0xC0);
        func_02040588(1, 0);
        menu->state = 0;
        break;
    case 1:
        func_02040618(1, 3, 0);
        func_02040588(1, 1);
        menu->state = 3;
        break;
    }
    return menu;
}

void func_021C51A0(ShortcutMenu *menu)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    func_021C5424(menu, (u16 *)menu->savedState);
    for (i = 0; i < 3; i++) {
        func_0204B3B4(menu->actors[i]);
    }
    func_0201C6EC(menu->ownedPrintSys);
    func_0201C4C0(menu->ownedPrintSys);
    func_0201D83C(menu->ownedFont);
    func_02045C04((struct Rec *)menu->ownedMsgBank);
    func_0204ADA4(menu->charResId);
    func_0204A8D4(menu->palResId);
    func_0204AFD8(menu->cellResId);
    func_0204B1CC(menu->actorBank);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0(menu);
}

void func_021C5224(ShortcutMenu *menu)
{
    int selection;
    int i;

    if (func_021C5334(menu) == 0) {
        return;
    }
    switch (menu->state) {
    case 0:
        break;
    case 1:
        func_020061E4(0x54C);
        menu->scrollFrame = 0;
        menu->scrollDone = 0;
        menu->scrollTask = func_020056A0((void *)func_021C59BC, menu, 0);
        menu->state = 2;
        break;
    case 2:
        if (menu->scrollDone != 0) {
            func_02030EAC(menu->scrollTask);
            menu->state = 3;
        }
        break;
    case 3:
        func_021C553C(menu);
        selection = func_021C5768(menu);
        switch (selection) {
        case -1:
            menu->resultKind = 0;
            break;
        case -2:
            menu->resultKind = 2;
            break;
        default:
            menu->resultKind = 1;
            menu->resultValue = selection;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_0204B3DC(menu->actors[i], 0);
        }
        menu->scrollFrame = 4;
        menu->state = 5;
        break;
    case 5:
        func_02040618(1, 3, menu->scrollFrame * 0xC0 / 4 - 0xC0);
        if ((menu->scrollFrame)-- == 0) {
            menu->state = 0;
        }
        break;
    }
}

int func_021C5334(ShortcutMenu *menu)
{
    func_0201C4E4(menu->ownedPrintSys);
    return func_021C56F8(menu);
}

/*
 * Starts the fade sequence once (state 0 to 1).
 */
void func_021C5348(ShortcutMenu *menu)
{
    if (menu->state == 0) {
        menu->resultKind = 0;
        menu->resultValue = 0x19;
        func_02040588(1, 1);
        menu->state = 1;
    }
}

/*
 * Advances the sequence from state 3 to 4 (EXACT*: pad).
 */
void func_021C536C(ShortcutMenu *menu)
{
    if (menu->state == 3)
        menu->state = 4;
}

/*
 * Returns 1 in states 2 and 5.
 */
int func_021C5380(ShortcutMenu *menu)
{
    int waiting = 1;

    if (menu->state != 2 && menu->state != 5)
        waiting = 0;
    return waiting;
}

/*
 * Returns the result word and optionally its argument.
 */
u32 func_021C5394(ShortcutMenu *menu, u32 *outValue)
{
    if (outValue != 0)
        *outValue = menu->resultValue;
    return menu->resultKind;
}

void func_021C53A0(ShortcutMenu *menu, const u16 *savedState, struct MsgBank *msgBank, struct GfFont *font, struct PrintSys *printSys, void *menuData, struct Obj **actors, u16 heapId)
{
    int i = 0;
    struct Descriptor *window;

    func_02082BCC(menu, 0, 0x4c);
    menu->printSys = printSys;
    menu->menuData = menuData;
    menu->heapId = heapId;
    menu->msgBank = msgBank;
    menu->font = font;
    for (i = 0; i < 3; i++) {
        menu->listActors[i] = actors[i];
    }
    window = (struct Descriptor *)func_020450F0(1, 1, 0xc, 0x1e, 0xc, 0xb, 1);
    menu->window = window;
    func_02045334(window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730(window));
    menu->printWindow = menu->window;
    menu->printBusy = 0;
    func_021C58CC(menu, savedState[0], savedState[1], heapId);
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C5424(ShortcutMenu *menu, u16 *savedState)
{
    func_021C59A8(menu, savedState, savedState + 1);
    func_020452E8(menu->window);
    return func_02082BCC(menu, 0, 76);
}

/*
 * Message-window step: opens the window and plays SE 0x548, or scrolls to
 * the cursor line. Load-bearing: int-typed line count (stops (c-1)-(n-1)
 * folding) and the u16 local for the line index.
 */
void func_021C5440(ShortcutMenu *menu, int cursor, u32 itemCount, u32 *done)
{
    int lastIndex;
    u16 cursorIndex;
    u16 row;

    if (cursor == 0) {
        lastIndex = func_02020350(menu->list, 3);
        func_021C59A8(menu, 0, 0);
        func_021C58CC(menu, (itemCount - 1) - (lastIndex - 1), lastIndex - 1, menu->heapId);
        if (menu->moveMode == 1)
            menu->cursorWrapped = 1;
        func_020061E4(0x548);
        *done = 1;
    } else if (menu->cursorWrapped == 1 && menu->moveMode == 1) {
        func_020202FC(menu->list, 0, &cursorIndex);
        row = func_02020324(menu->list, cursorIndex) >> 3;
        func_021C59F8(menu, (row + 0xC) * 8);
        menu->cursorWrapped = 0;
        *done = 1;
    }
}

void func_021C54C8(ShortcutMenu *menu, int cursor, int itemCount, int *done)
{
    u16 cursorIndex;
    u16 row;

    if (cursor == itemCount - 1) {
        if (menu->moveMode == 1) {
            func_020202FC(menu->list, 0, &cursorIndex);
            row = func_02020324(menu->list, (u16)(cursorIndex + 1)) >> 3;
            func_021C59F8(menu, (row + 0xc) << 3);
            menu->cursorWrapped ^= 1;
        }
        if (menu->cursorWrapped == 0) {
            func_021C59A8(menu, 0, 0);
            func_021C58CC(menu, 0, 0, menu->heapId);
        }
        func_020061E4(0x548);
        *done = 1;
        return;
    }
    menu->cursorWrapped = 0;
}

void func_021C553C(ShortcutMenu *menu)
{
    int wrapped;
    u16 pickCursor[2];
    u16 moveCursor[2];
    u16 listWindow[2];
    int toggleMode;
    int selection;
    u32 itemCount;
    int i;

    selection = -1;
    toggleMode = 0;
    wrapped = 0;
    func_020355D8(0);
    func_020202EC(menu->list, &pickCursor[1]);
    itemCount = func_02020350(menu->list, 2);
    if (func_0203633C() & 0x40) {
        func_021C5440(menu, pickCursor[1], itemCount, (u32 *)&wrapped);
    } else if (func_0203633C() & 0x80) {
        func_021C54C8(menu, pickCursor[1], itemCount, &wrapped);
    }
    if (wrapped == 0) {
        selection = func_020200CC(menu->list);
    }
    if (selection == -1) {
        if (func_020362DC() & 0x400) {
            selection = -2;
            func_020061E4(0x551);
        } else if (func_020362DC() & 0x800) {
            func_020202EC(menu->list, &pickCursor[0]);
            selection = func_02020344(menu->list, pickCursor[0]);
            func_020061E4(0x54C);
        } else if ((func_020362DC() & 4) && menu->moveMode == 1) {
            func_020202EC(menu->list, &moveCursor[1]);
            selection = func_02020344(menu->list, moveCursor[1]);
            func_020061E4(0x54C);
        }
    }
    if (menu->moveMode == 0) {
        menu->selection = selection;
    } else if (menu->moveMode == 1) {
        if (selection == -2) {
            toggleMode = 1;
        } else if (selection != -1) {
            selection = func_02020344(menu->list, (u16)(menu->savedScroll + menu->savedCursor));
            func_020202EC(menu->list, &moveCursor[0]);
            if (menu->cursorWrapped != 0) {
                selection = func_0200C480(menu->menuData, selection, 0xFF);
            } else {
                selection = func_0200C480(menu->menuData, selection, moveCursor[0]);
            }
            func_021C59A8(menu, &listWindow[0], &listWindow[1]);
            if (moveCursor[0] - 1 == selection) {
                listWindow[1]--;
            }
            func_021C58CC(menu, listWindow[0], listWindow[1], menu->heapId);
            toggleMode = 1;
        }
    }
    if ((func_020362DC() & 4) && menu->moveMode == 0 && func_02020350(menu->list, 2) > 1) {
        func_020061E4(0x54C);
        toggleMode = 1;
    }
    if (toggleMode) {
        menu->moveMode ^= 1;
        if (menu->moveMode == 0) {
            menu->cursorWrapped = 0;
            for (i = 0; i < 3; i++) {
                func_0204B3DC(menu->listActors[i], 0);
            }
            func_021C577C(menu->list, 0, 0);
            return;
        }
        if (menu->moveMode == 1) {
            func_020202FC(menu->list, &menu->savedScroll, &menu->savedCursor);
            menu->showActors = 1;
        }
    }
}

int func_021C56F8(ShortcutMenu *menu)
{
    struct PrintSys *printSys = menu->printSys;
    int i;
    int finished;

    if (menu->printBusy != 0) {
        if (func_0201C6C4(printSys, (void *)((int)func_02045770(menu->printWindow))) == 0) {
            func_02045334(menu->printWindow);
            menu->printBusy = 0;
        }
    }
    finished = 1;
    if (menu->printBusy != 0) {
        finished = 0;
    }
    if (finished != 0) {
        if (menu->redrawBg != 0) {
            func_021C577C(menu->list, 0, 0);
            menu->redrawBg = 0;
        }
        if (menu->showActors != 0) {
            for (i = 0; i < 3; i++) {
                func_0204B3DC(menu->listActors[i], 1);
            }
            menu->showActors = 0;
        }
    }
    return finished;
}

/*
 * Unlabelled leaf (no lr save): returns the selection func_021C553C
 * stores at +0x18. Called from func_021C5224.
 */
int func_021C5768(ShortcutMenu *menu)
{
    return menu->selection;
}

/*
 * Raises the redraw flag on the menu stored as the list's user pointer
 * (EXACT*: pad).
 */
void func_021C576C(void *list)
{
    *(u32 *)(func_02020350(list, 0x13) + 0x44) = 1;
}

void func_021C577C(void *list, int unused0, int unused1)
{
    u16 listPos[2];
    ShortcutMenu *menu;
    u16 cursorRow;
    u32 rowHeightTiles;
    u32 baseY;
    u32 rowHeight;
    u32 cursorOffset;
    u16 row;

    menu = (ShortcutMenu *)func_02020350(list, 0x13);
    cursorRow = func_02020314(list) >> 3;
    rowHeightTiles = func_02020350(list, 9) >> 3;
    if (menu->moveMode == 0) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020413B0(1, 1, cursorRow + 12, 30, rowHeightTiles, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    } else if (menu->moveMode == 1) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020202FC(list, &listPos[1], &listPos[0]);
        baseY = func_02020350(list, 8);
        rowHeight = func_02020350(list, 9);
        cursorOffset = menu->savedCursor + menu->savedScroll - listPos[1];
        baseY = baseY + cursorOffset * rowHeight;
        func_020413B0(1, 1, (baseY >> 3) + 12, 30, rowHeightTiles, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    }
    if (menu->cursorWrapped == 1) {
        row = func_02020350(menu->list, 3);
        row = func_02020324(menu->list, row) >> 3;
        func_021C59F8(menu, (row + 12) << 3);
    } else {
        func_021C59F8(menu, (cursorRow + 12) << 3);
    }
}

void func_021C5880(u16 *scroll, u16 *cursor, u16 itemCount)
{
    int total = *scroll + *cursor;

    if (itemCount <= 5) {
        *cursor = total;
        *scroll = 0;
        return;
    }
    if (total <= 3) {
        *cursor = total;
        *scroll = 0;
        return;
    }
    if (total <= (int)itemCount - 2 && total > 3) {
        *scroll = total - 3;
        *cursor = 3;
        return;
    }
    if (total == (int)itemCount - 1) {
        *scroll = total - 4;
        *cursor = 4;
    }
}

void func_021C58CC(ShortcutMenu *menu, u16 scroll, u16 cursor, u32 heapId)
{
    ShortcutListTemplate tmpl;
    u32 itemCount;
    u32 i;

    itemCount = func_0200C468(menu->menuData);
    menu->listItems = func_0201F81C(itemCount, heapId);
    for (i = 0; i < itemCount; i++) {
        u8 entryId = func_0200C464(menu->menuData, (u8)i);
        func_0201F878(menu->listItems, (u32)menu->msgBank, (int)entryId, (int)entryId, heapId);
    }
    while (cursor + scroll >= itemCount) {
        if (cursor != 0) {
            cursor--;
        } else if (scroll != 0) {
            scroll--;
        }
    }
    func_021C5880(&scroll, &cursor, itemCount);
    tmpl = d_021DAA80;
    tmpl.items = menu->listItems;
    tmpl.totalItems = itemCount;
    tmpl.moveCursorFunc = (void *)func_021C576C;
    tmpl.printFunc = 0;
    tmpl.window = menu->window;
    tmpl.cbParam = menu;
    tmpl.msgBank = menu->msgBank;
    tmpl.windowRef = &menu->printWindow;
    tmpl.printSys = menu->printSys;
    tmpl.font = menu->font;
    menu->list = func_0201FF30((struct Src *)(&tmpl), scroll, cursor, heapId);
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C59A8(ShortcutMenu *menu, u16 *outScroll, u16 *outCursor)
{
    func_0202020C(menu->list, outScroll, outCursor);
    return func_0201F868(menu->listItems);
}

/*
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 */
void func_021C59BC(void *task, ShortcutMenu *menu)
{
    u16 frame = menu->scrollFrame;
    int offset = frame * 0xC0 / 4 - 0xC0;

    (menu->scrollFrame)++;
    if (frame >= 4) {
        offset = 0;
        menu->scrollDone = 1;
    }
    func_02040618(1, 3, offset);
}

/*
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 */
void func_021C59F8(ShortcutMenu *menu, int offsetY)
{
    s16 y;
    int i;
    ShortcutActorOffset offset;

    i = 0;
    y = offsetY;
    for (; i < 3; i++) {
        func_0204B454((struct Actor *)menu->listActors[i], (struct PtS *)&offset, 0);
        offset.y = y;
        func_0204B404(menu->listActors[i], (const struct Vec2 *)(&offset), 0);
    }
}
