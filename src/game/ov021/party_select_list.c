/*
 * file:     party_select_list.c
 * unit:     yes
 * function: func_021CC720, func_021CC7B4, func_021CC810, func_021CC8B0, func_021CC8DC, func_021CC9A4, func_021CCA00, func_021CCB98, func_021CCBE0, func_021CCC50, func_021CCCC4, func_021CCCE4, func_021CCDF8, func_021CCE48, func_021CCEB8, func_021CCEE4, func_021CCEFC, func_021CCF48, func_021CCF54, func_021CCF60, func_021CCF7C, func_021CCFC0, func_021CCFD8, func_021CCFE4, func_021CCFF8, func_021CD004, func_021CD038, func_021CD050, func_021CD184, func_021CD1AC
 * address:  0x021CC720
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): __FILE__ anchor 021CC7B0 (d_021DE5C0 "party_select_list.c"); 021CD050..021CD1AC take the same 0xC4 work.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02034714  0x02034714  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   d_021DE5BC  0x021DE5BC  data  a1
 *   d_021DE5C0  0x021DE5C0  data  ov021
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021CD1AC  0x021CD1AC  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021DB404     0x021DB404  data  a2
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02027694  0x02027694  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_02027698  0x02027698  thumb
 *   d_021DB40C  0x021DB40C  data
 *   func_0202136C  0x0202136C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190938  0x02190938  thumb  ov021
 *   d_021DB414     0x021DB414  data  a4
 *   d_021DB42C     0x021DB42C  data  ov021  a4
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021CD184  0x021CD184  thumb  ov021
 *   func_02020298  0x02020298  thumb
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021CD004  0x021CD004  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190764  0x02190764  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_021CCBE0  0x021CCBE0  thumb  ov021
 *   func_021CCE48  0x021CCE48  thumb  ov021
 *   func_021CD038  0x021CD038  thumb  ov021
 */
#include "field_msgbg_types.h"

struct Bank;
struct GfFont;
struct WordSet;
struct Strbuf;
struct BmpMenuList;
struct IconActor;

typedef struct IconPosition {
    u16 x;
    u16 y;
    u16 alt;
    u16 h6;
} IconPosition;

typedef struct ListPosition {
    u16 x;
    u16 y;
    u16 h4;
    u16 h6;
} ListPosition;

/*
 * Party selection list (0xC4 bytes, allocated by PARTY_SELECT_LIST_Create).
 * Shows one or two parties side by side, a text window and a two-entry menu.
 * The mon icon actors (0x1C) and the status icon actors (0x4C) are indexed
 * [side][slot].
 */
typedef struct PartySelectList {
    void *owner;                       /* 0x00 */
    void *party[2];                    /* 0x04 */
    u16 heapId;                        /* 0x0C */
    u8 pad0E[2];
    u32 sideFlagFirst;                 /* 0x10, result 0 reports 1 when set to 1 */
    u32 sideFlagSecond;                /* 0x14, result 1 reports 1 when set to 1 */
    struct Bank *actorBank;            /* 0x18 */
    struct IconActor *monIcon[2][6];   /* 0x1C */
    struct IconActor *statusIcon[2][6]; /* 0x4C */
    u16 monIconPalette;                /* 0x7C */
    u16 monIconCell;                   /* 0x7E */
    u16 monIconRes[2][6];              /* 0x80 */
    u16 statusIconCell;                /* 0x98 */
    u16 statusIconAnim;                /* 0x9A */
    u16 statusIconRes;                 /* 0x9C */
    u8 pad9E[2];
    struct WordSet *wordSet;           /* 0xA0 */
    FieldMsgBg *msgBg;                 /* 0xA4 */
    struct MsgData *msgData;           /* 0xA8 */
    FieldMenuFunc *menu;               /* 0xAC */
    FieldSysWin *textWin;              /* 0xB0 */
    FieldMsgWin *listWin;              /* 0xB4 */
    struct GfFont *font;               /* 0xB8 */
    u32 result;                        /* 0xBC */
    u8 step;                           /* 0xC0 */
    u8 finished;                       /* 0xC1 */
    u8 padC2[2];
} PartySelectList;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02045808(struct Strbuf *str);
extern u32 func_020307B0(void *p);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0204B1CC(struct Bank *bank);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201AA18(void *p);
extern u32 func_020185F0(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern u32 func_0204ADA4(u32 v);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern struct IconActor *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B6F4(struct IconActor *o, u32 v, u32 flag);
extern void func_0204B3DC(struct IconActor *p, unsigned int v);
extern void func_0204B3B4(struct IconActor *p);
extern u32 func_02027694(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern u32 func_02027698(void);
extern u32 func_0202136C(u16 v);
extern FieldMsgBg *func_02188C54(void *owner);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02020D0C(struct BmpMenuList *menu);
extern void func_02020298(struct BmpMenuList *menu, u8 a, u8 b, u8 c);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgData *msgData, u32 index, struct Strbuf *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, struct Strbuf *dst, struct Strbuf *src);

extern int func_0219049C(FieldMsgBg *msgBg);
extern struct MsgData *func_021904B0(FieldMsgBg *msgBg, u32 fileId);
extern u32 func_021904C8(struct MsgData *msgData);
extern void func_02190764(FieldMsgWin *msgWin, u16 x, int y, struct Strbuf *str, u16 color, struct GfFont *font);
extern int func_02190740(FieldMsgWin *msgWin, int x, int y, u32 msgId);
extern FieldMsgWin *func_02190708(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
extern int func_02190728(FieldMsgWin *msgWin);
extern void func_02190788(FieldMsgWin *msgWin);
extern struct BmpMenuWork *func_02190A28(const FieldMenuItemData *itemData, int count, struct MsgData *msgData, u16 heapId);
extern FieldMenuFunc *func_02190938(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                                    u32 moveCallback, u32 lineCallback, u32 work);
extern int func_021909BC(FieldMenuFunc *menu);
extern int func_021909E4(FieldMenuFunc *menu);
extern int func_02190E40(FieldSysWin *sysWin);
extern void func_02190E74(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
extern u32 func_02190EF0(FieldSysWin *sysWin);
extern FieldSysWin *func_02190F64(FieldMsgBg *msgBg, struct MsgData *msgData);

extern const char d_021DE5BC[];
extern const char d_021DE5C0[];
extern ListPosition d_021DB404;
extern const IconPosition d_021DB40C;
extern FieldMenuItemData d_021DB414[];
extern FieldMenuHeader d_021DB42C;

PartySelectList *func_021CC720(void *owner, void *firstParty, void *secondParty, u32 sideFlagFirst, u32 sideFlagSecond, u16 heapId);
u32 func_021CC7B4(PartySelectList *list, u32 *outFlag);
int func_021CC810(PartySelectList *list);
u32 func_021CC8B0(PartySelectList *list, u32 *outFlag);
void func_021CC8DC(PartySelectList *list);
void func_021CC9A4(PartySelectList *list);
void func_021CCA00(PartySelectList *list);
void func_021CCB98(PartySelectList *list);
void func_021CCBE0(PartySelectList *list, int side);
void func_021CCC50(PartySelectList *list);
int func_021CCCC4(PartySelectList *list);
void func_021CCCE4(PartySelectList *list);
void func_021CCDF8(PartySelectList *list);
void func_021CCE48(PartySelectList *list, int side);
void func_021CCEB8(PartySelectList *list);
int func_021CCEE4(PartySelectList *list);
void func_021CCEFC(PartySelectList *list);
void func_021CCF48(PartySelectList *list);
u32 func_021CCF54(PartySelectList *list);
void func_021CCF60(struct BmpMenuList *menu, u32 sel);
void func_021CCF7C(struct BmpMenuList *menu, int k);
void func_021CCFC0(PartySelectList *list);
void func_021CCFD8(PartySelectList *list);
void func_021CCFE4(PartySelectList *list, u32 msgId);
int func_021CCFF8(PartySelectList *list);
void func_021CD004(PartySelectList *list);
void func_021CD038(PartySelectList *list);
void func_021CD050(PartySelectList *list, void *party);
void func_021CD184(PartySelectList *list, u32 sel);
void func_021CD1AC(PartySelectList *list);


PartySelectList *func_021CC720(void *owner, void *firstParty, void *secondParty, u32 sideFlagFirst, u32 sideFlagSecond, u16 heapId)
{
    PartySelectList *list;

    if (firstParty == 0 || secondParty == 0)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    list = func_02030734(heapId, 0xc4, 1, d_021DE5C0, 0xd3);
    list->owner = owner;
    list->party[0] = firstParty;
    list->party[1] = secondParty;
    list->heapId = heapId;
    list->sideFlagFirst = sideFlagFirst;
    list->sideFlagSecond = sideFlagSecond;
    list->actorBank = func_0204B100(0x20, 0xa, list->heapId);
    list->font = func_0201D7EC(0x17, 3, 0, 0, list->heapId);
    func_021CCEB8(list);
    func_021CC8DC(list);
    func_021CCA00(list);
    func_021CCC50(list);
    func_021CCCE4(list);
    return list;
}


u32 func_021CC7B4(PartySelectList *list, u32 *outFlag)
{
    u32 result;

    result = func_021CC8B0(list, outFlag);
    if (list->finished != 1)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    func_021CCDF8(list);
    func_021CCCC4(list);
    func_021CCB98(list);
    func_021CC9A4(list);
    func_021CCEE4(list);
    func_0201D83C(list->font);
    func_0204B1CC(list->actorBank);
    func_020307B0(list);
    return result;
}


/*
 * Main state machine on the byte at +0xc0 (step). The inner switch on an unsigned
 * result (cases 2, -2, -1) is what gives the compare order 2, -2, -1 and
 * the dead second -1 test.
 */
int func_021CC810(PartySelectList *list)
{
    u32 menuResult;

    switch (list->step) {
    case 0:
        func_021CCFC0(list);
        func_021CCFE4(list, 3);
        list->step = list->step + 1;
        break;
    case 1:
        if (func_021CCFF8(list) == 1) {
            func_021CCEFC(list);
            list->step = list->step + 1;
        }
        break;
    case 2:
        if (func_0219049C(list->msgBg) == 1) {
            menuResult = func_021CCF54(list);
            if (menuResult == -1)
                break;
            func_021CCF48(list);
            func_021CD1AC(list);
            func_021CCFD8(list);
            switch (menuResult) {
            case 2:
            case -2:
                list->result = 2;
                list->step = list->step + 1;
                break;
            case -1:
                break;
            default:
                list->result = menuResult;
                list->step = list->step + 1;
                break;
            }
        }
        break;
    default:
        list->finished = 1;
        return 1;
    }
    return 0;
}


u32 func_021CC8B0(PartySelectList *list, u32 *outFlag)
{
    u32 side;

    *outFlag = 0;
    side = list->result;
    if (side == 0 && list->sideFlagFirst == 1)
        *outFlag = 1;
    else if (side == 1 && list->sideFlagSecond == 1)
        *outFlag = 1;
    return list->result;
}


void func_021CC8DC(PartySelectList *list)
{
    void *arc;
    int i;
    int count;

    arc = func_020490F4(7, list->heapId);
    list->monIconPalette = func_0204ACEC(arc, func_0201BC3C(), 0, 0x60, list->heapId);
    list->monIconCell = func_0204AF28(arc, func_0201BC40(), func_0201BCB4(), list->heapId);
    count = func_0201AA18(list->party[0]);
    for (i = 0; i < count; i++) {
        list->monIconRes[0][i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(list->party[0], i))), 0, 0, list->heapId);
    }
    if (list->party[1] != 0) {
        count = func_0201AA18(list->party[1]);
        for (i = 0; i < count; i++) {
            list->monIconRes[1][i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(list->party[1], i))), 0, 0, list->heapId);
        }
    }
    func_02049238(arc);
}


void func_021CC9A4(PartySelectList *list)
{
    int i;
    int count;

    if (list->party[1]) {
        count = func_0201AA18(list->party[1]);
        for (i = 0; i < count; i++)
            func_0204A8D4(list->monIconRes[1][i]);
    }
    count = func_0201AA18(list->party[0]);
    for (i = 0; i < count; i++)
        func_0204A8D4(list->monIconRes[0][i]);
    func_0204AFD8(list->monIconCell);
    func_0204ADA4(list->monIconPalette);
}


void func_021CCA00(PartySelectList *list)
{
    ListPosition pos = d_021DB404;
    int count0;
    int count1;
    int i;
    void *mon;
    u32 species;
    u32 form;
    u32 isEgg;
    u32 iconKind;

    count0 = func_0201AA18(list->party[0]);
    for (i = 0; i < count0; i++) {
        pos.x = i * 0x28 + 0x18;
        list->monIcon[0][i] = func_0204B294(list->actorBank, list->monIconRes[0][i], list->monIconPalette, list->monIconCell, &pos, 0, list->heapId);
        mon = func_0201AB28(list->party[0], i);
        species = func_02017E1C(mon, 5, 0);
        form = func_02017E1C(mon, 0x6f, 0);
        isEgg = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
        iconKind = func_0201BB5C(species, form, func_02017E1C(mon, 0x6e, 0), isEgg);
        func_0204B6F4(list->monIcon[0][i], (u8)iconKind, 1);
        func_0204B3DC(list->monIcon[0][i], 0);
    }
    if (list->party[1] != 0) {
        count1 = func_0201AA18(list->party[1]);
        for (i = 0; i < count1; i++) {
            pos.x = i * 0x28 + 0x18;
            list->monIcon[1][i] = func_0204B294(list->actorBank, list->monIconRes[1][i], list->monIconPalette, list->monIconCell, &pos, 0, list->heapId);
            mon = func_0201AB28(list->party[1], i);
            species = func_02017E1C(mon, 5, 0);
            form = func_02017E1C(mon, 0x6f, 0);
            isEgg = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
            iconKind = func_0201BB5C(species, form, func_02017E1C(mon, 0x6e, 0), isEgg);
            func_0204B6F4(list->monIcon[1][i], (u8)iconKind, 1);
            func_0204B3DC(list->monIcon[1][i], 0);
        }
    }
}


void func_021CCB98(PartySelectList *list)
{
    int i;
    int count;

    count = func_0201AA18(list->party[0]);
    for (i = 0; i < count; i++)
        func_0204B3B4(list->monIcon[0][i]);
    if (list->party[1]) {
        count = func_0201AA18(list->party[1]);
        for (i = 0; i < count; i++)
            func_0204B3B4(list->monIcon[1][i]);
    }
}


void func_021CCBE0(PartySelectList *list, int side)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (list->monIcon[0][i] != 0)
            func_0204B3DC(list->monIcon[0][i], 0);
        if (list->monIcon[1][i] != 0)
            func_0204B3DC(list->monIcon[1][i], 0);
    }
    if (side == 0) {
        for (i = 0; i < 6; i++) {
            if (list->monIcon[0][i] != 0)
                func_0204B3DC(list->monIcon[0][i], 1);
        }
    } else if (side == 1) {
        for (i = 0; i < 6; i++) {
            if (list->monIcon[1][i] != 0)
                func_0204B3DC(list->monIcon[1][i], 1);
        }
    }
}


void func_021CCC50(PartySelectList *list)
{
    void *arc;
    u32 cellRes;
    u32 animRes;

    arc = func_020490F4(0x53, list->heapId);
    list->statusIconCell = func_0204AC18(arc, func_02027694(), 0, 0xc0, 0, 1, list->heapId);
    cellRes = func_0202769C(1);
    animRes = func_020276A0(1);
    list->statusIconAnim = func_0204AF28(arc, cellRes, animRes, list->heapId);
    list->statusIconRes = func_0204A6C8(arc, func_02027698(), 0, 0, list->heapId);
    func_02049238(arc);
}


int func_021CCCC4(PartySelectList *list)
{
    func_0204A8D4(list->statusIconRes);
    func_0204AFD8(list->statusIconAnim);
    return func_0204ADA4(list->statusIconCell);
}


/*
 * Creates the party icon sprites for both sides: one per non-empty slot, at x = 0x20 + 0x28 * slot, flagged for the alternate form, into the statusIcon arrays.
 *
 * The alternate-form flag is an if/else storing 1 or 0 into pos.alt, not a
 * ternary: the ternary version (114 bytes out) left the second party count in
 * a register and rematerialised &pos; the if/else spills both counts and
 * keeps &pos hoisted in each loop, as the original does.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCCE4(PartySelectList *list)
{
    IconPosition pos = d_021DB40C;
    int count0;
    int count1;
    int i;
    u32 species;

    count0 = func_0201AA18(list->party[0]);
    for (i = 0; i < count0; i++) {
        species = func_02017E1C(func_0201AB28(list->party[0], i), 6, 0);
        if (species != 0) {
            if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
            pos.x = i * 0x28 + 0x20;
            list->statusIcon[0][i] = func_0204B294(list->actorBank, list->statusIconRes, list->statusIconCell, list->statusIconAnim, &pos, 0, list->heapId);
            func_0204B3DC(list->statusIcon[0][i], 0);
        }
    }
    if (list->party[1] != 0) {
        count1 = func_0201AA18(list->party[1]);
        for (i = 0; i < count1; i++) {
            species = func_02017E1C(func_0201AB28(list->party[1], i), 6, 0);
            if (species != 0) {
                if (func_0202136C(species) == 1) {
                    pos.alt = 1;
                } else {
                    pos.alt = 0;
                }
                pos.x = i * 0x28 + 0x20;
                list->statusIcon[1][i] = func_0204B294(list->actorBank, list->statusIconRes, list->statusIconCell, list->statusIconAnim, &pos, 0, list->heapId);
                func_0204B3DC(list->statusIcon[1][i], 0);
            }
        }
    }
}


void func_021CCDF8(PartySelectList *list)
{
    int i;
    int count;

    count = func_0201AA18(list->party[0]);
    for (i = 0; i < count; i++) {
        if (list->statusIcon[0][i])
            func_0204B3B4(list->statusIcon[0][i]);
    }
    if (list->party[1]) {
        count = func_0201AA18(list->party[1]);
        for (i = 0; i < count; i++) {
            if (list->statusIcon[1][i])
                func_0204B3B4(list->statusIcon[1][i]);
        }
    }
}


void func_021CCE48(PartySelectList *list, int side)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (list->statusIcon[0][i] != 0)
            func_0204B3DC(list->statusIcon[0][i], 0);
        if (list->statusIcon[1][i] != 0)
            func_0204B3DC(list->statusIcon[1][i], 0);
    }
    if (side == 0) {
        for (i = 0; i < 6; i++) {
            if (list->statusIcon[0][i] != 0)
                func_0204B3DC(list->statusIcon[0][i], 1);
        }
    } else if (side == 1) {
        for (i = 0; i < 6; i++) {
            if (list->statusIcon[1][i] != 0)
                func_0204B3DC(list->statusIcon[1][i], 1);
        }
    }
}


/*
 * Fetches the message handles of the list: the message BG system of the
 * owner, its 0x54 message data and a new word set.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCEB8(PartySelectList *list)
{
    FieldMsgBg *msgBg = func_02188C54(list->owner);
    list->msgData = func_021904B0(msgBg, 0x54);
    list->msgBg = msgBg;
    list->wordSet = func_0201EC64(list->heapId);
}


int func_021CCEE4(PartySelectList *list)
{
    func_0201ED04(list->wordSet);
    return func_021904C8(list->msgData);
}


void func_021CCEFC(PartySelectList *list)
{
    struct BmpMenuWork *items;

    items = func_02190A28(d_021DB414, 3, list->msgData, list->heapId);
    list->menu = func_02190938(list->msgBg, &d_021DB42C, items, 0, 0,
        (u32)func_021CCF60, (u32)func_021CCF7C, (u32)list);
}


/*
 * Tail call on the menu at +0xac.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCF48(PartySelectList *list)
{
    func_021909BC(list->menu);
}


u32 func_021CCF54(PartySelectList *list)
{
    return func_021909E4(list->menu);
}


/*
 * Menu move callback: selector below two refreshes that side through
 * func_021CD184, otherwise the lists are hidden through func_021CD1AC.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCF60(struct BmpMenuList *menu, u32 sel)
{
    PartySelectList *list = (PartySelectList *)func_02020D0C(menu);
    if (sel < 2)
        func_021CD184(list, sel);
    else
        func_021CD1AC(list);
}


void func_021CCF7C(struct BmpMenuList *menu, int k)
{
    PartySelectList *list = (PartySelectList *)func_02020D0C(menu);

    if (k == 0 && list->sideFlagFirst == 1) {
        func_02020298(menu, 1, 0, 2);
        return;
    }
    if (k == 1) {
        func_02020298(menu, 1, 0, 2);
        return;
    }
    func_02020298(menu, 1, 0, 2);
}


/*
 * Builds the system window (+0xB0) of the list from its message BG system and message data.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCFC0(PartySelectList *list)
{
    list->textWin = func_02190F64(list->msgBg, list->msgData);
}


/*
 * Tail call on the system window at +0xb0.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCFD8(PartySelectList *list)
{
    func_02190E40(list->textWin);
}


void func_021CCFE4(PartySelectList *list, u32 msgId)
{
    func_02190E74(list->textWin, 0, 0, msgId);
}


int func_021CCFF8(PartySelectList *list)
{
    return func_02190EF0(list->textWin);
}


/*
 * Creates the message window (+0xB4) of the list once, from its message BG system and message data.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD004(PartySelectList *list)
{
    if (list->listWin == 0)
        list->listWin = func_02190708(list->msgBg, list->msgData, 1, 2, 0x1e, 6);
}


/*
 * Releases the message window (+0xB4) of the list if it is set and clears it.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD038(PartySelectList *list)
{
    if (list->listWin != 0) {
        func_02190728(list->listWin);
        list->listWin = 0;
    }
}

void func_021CD050(PartySelectList *list, void *party)
{
    struct Strbuf *nameBuf;
    struct Strbuf *templateBuf;
    int count;
    int i;
    void *mon;
    u32 species;
    u32 gender;
    u32 nickname;
    u32 isNicknamed;
    int x;

    func_021CD004(list);
    func_02190788(list->listWin);
    nameBuf = func_020457B0(0x40, list->heapId);
    templateBuf = func_020457B0(0x40, list->heapId);
    count = func_0201AA18(party);
    for (i = 0; i < count; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4c, 0) != 0) {
            continue;
        }
        species = func_02017E1C(mon, 5, 0);
        isNicknamed = func_02017E1C(mon, 0xad, 0);
        nickname = func_02017E1C(mon, 0x9e, 0);
        gender = func_02017E1C(mon, 0x6e, 0);
        func_02045CAC(list->msgData, 4, templateBuf);
        func_0201EFA4(list->wordSet, 0, nickname, 3, 0, 1);
        func_0201F250(list->wordSet, nameBuf, templateBuf);
        x = i * 0x28;
        func_02190764(list->listWin, x, 0x20, nameBuf, 0x440, list->font);
        if (gender == 2) {
            continue;
        }
        if ((species == 0x1d || species == 0x20) && isNicknamed == 0) {
            continue;
        }
        if (gender == 0) {
            func_02190740(list->listWin, (u16)(x + 0x1f), 0x10, 5);
        } else {
            func_02190740(list->listWin, (u16)(x + 0x1f), 0x10, 6);
        }
    }
    func_02045808(nameBuf);
    func_02045808(templateBuf);
}


/*
 * Selector 0 or 1 path of func_021CCF60: prints the names of that side, then refreshes the two per-side icon sets.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD184(PartySelectList *list, u32 sel)
{
    func_021CD050(list, sel == 0 ? list->party[0] : list->party[1]);
    func_021CCBE0(list, sel);
    func_021CCE48(list, sel);
}


/*
 * Hides the name window and all icons.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD1AC(PartySelectList *list)
{
    func_021CD038(list);
    func_021CCBE0(list, 2);
    func_021CCE48(list, 2);
}
