/*
 * file:     party_select_list.c
 * unit:     yes
 * function: PARTY_SELECT_LIST_Create, PARTY_SELECT_LIST_Delete, PARTY_SELECT_LIST_Main, PARTY_SELECT_LIST_GetResult, PARTY_SELECT_LIST_LoadMonIconResources, PARTY_SELECT_LIST_FreeMonIconResources, PARTY_SELECT_LIST_CreateMonIcons, PARTY_SELECT_LIST_DeleteMonIcons, PARTY_SELECT_LIST_SetMonIconsVisible, PARTY_SELECT_LIST_LoadStatusIconResources, PARTY_SELECT_LIST_FreeStatusIconResources, PARTY_SELECT_LIST_CreateStatusIcons, PARTY_SELECT_LIST_DeleteStatusIcons, PARTY_SELECT_LIST_SetStatusIconsVisible, PARTY_SELECT_LIST_InitMessageResources, PARTY_SELECT_LIST_FreeMessageResources, PARTY_SELECT_LIST_CreateMenu, PARTY_SELECT_LIST_ProcessMenu, PARTY_SELECT_LIST_GetMenuResult, PARTY_SELECT_LIST_MenuMoveCallback, PARTY_SELECT_LIST_MenuSelectCallback, PARTY_SELECT_LIST_CreateTextWindow, PARTY_SELECT_LIST_DeleteTextWindow, PARTY_SELECT_LIST_PrintText, PARTY_SELECT_LIST_IsTextDone, PARTY_SELECT_LIST_CreateListWindow, PARTY_SELECT_LIST_DeleteListWindow, PARTY_SELECT_LIST_PrintPartyNames, PARTY_SELECT_LIST_ShowParty, PARTY_SELECT_LIST_HideParty
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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   d_021DE5BC  0x021DE5BC  data  a1
 *   d_021DE5C0  0x021DE5C0  data  ov021
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   PARTY_SELECT_LIST_HideParty  0x021CD1AC  thumb  ov021
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcId  0x0201BC40  thumb
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   d_021DB404     0x021DB404  data  a2
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   APP_ICON_GetItemCellFileId  0x02027694  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   APP_ICON_GetItemAnimFileId  0x0202769C  thumb
 *   APP_ICON_GetItemFrameFileId  0x020276A0  thumb
 *   APP_ICON_GetItemPaletteFileId  0x02027698  thumb
 *   d_021DB40C  0x021DB40C  data
 *   FILE_UTIL_IsMailItem  0x0202136C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   FIELD_MSGBG_CreateMenuItemsFromTable  0x02190A28  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncCallback  0x02190938  thumb  ov021
 *   d_021DB414     0x021DB414  data  a4
 *   d_021DB42C     0x021DB42C  data  ov021  a4
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_MenuFuncMain  0x021909E4  thumb  ov021
 *   BMP_MENULIST_GetUserData  0x02020D0C  thumb
 *   PARTY_SELECT_LIST_ShowParty  0x021CD184  thumb  ov021
 *   BMP_MENULIST_SetOverrideColors  0x02020298  thumb
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   PARTY_SELECT_LIST_CreateListWindow  0x021CD004  thumb  ov021
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_MsgWinPrintStrColorFont  0x02190764  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   PARTY_SELECT_LIST_SetMonIconsVisible  0x021CCBE0  thumb  ov021
 *   PARTY_SELECT_LIST_SetStatusIconsVisible  0x021CCE48  thumb  ov021
 *   PARTY_SELECT_LIST_DeleteListWindow  0x021CD038  thumb  ov021
 */
#include "field_msgbg_types.h"
#include "poke_tool_param.h"

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

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, char *site, unsigned short tag);
extern void STRBUF_Delete(struct Strbuf *str);
extern u32 GFL_HEAP_Free(void *p);
struct PokemonParam;
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);
struct Party;
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);
extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *h, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 POKEPARTY_GetCount(struct Party *party);
extern struct PokemonParam *POKE_TOOL_CastToBoxParam(struct PokemonParam *mon);
struct BoxPokemon;
extern u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void CLACT_ReleaseCharacter(u32 v);
extern void CLACT_ReleaseCellAnim(u32 v);
extern u32 CLACT_ReleasePalette(u32 v);
extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);
extern struct IconActor *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
struct Actor;
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, u32 offset, u32 pltt_op);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);
extern void CLACT_DeleteActor(struct Actor *actor);
extern u32 APP_ICON_GetItemCellFileId(void);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 APP_ICON_GetItemAnimFileId(u32 a);
extern u32 APP_ICON_GetItemFrameFileId(u32 a);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern u32 FILE_UTIL_IsMailItem(u16 v);
struct FieldMap;
struct FieldMsgBg;
extern FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern struct WordSet *WORDSET_CreateDefault(u16 heapId);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 BMP_MENULIST_GetUserData(struct BmpMenuList *menu);
extern void BMP_MENULIST_SetOverrideColors(struct BmpMenuList *menu, u8 a, u8 b, u8 c);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, struct Strbuf *dst, struct Strbuf *src);

extern int FIELD_MSGBG_IsPrintQueFinished(FieldMsgBg *msgBg);
extern struct MsgData *FIELD_MSGBG_CreateMsgData(FieldMsgBg *msgBg, u32 fileId);
extern u32 FIELD_MSGBG_DeleteMsgData(struct MsgData *msgData);
extern void FIELD_MSGBG_MsgWinPrintStrColorFont(FieldMsgWin *msgWin, u16 x, int y, struct Strbuf *str, u16 color, struct GfFont *font);
extern int FIELD_MSGBG_MsgWinPrintMsg(FieldMsgWin *msgWin, int x, int y, u32 msgId);
extern FieldMsgWin *FIELD_MSGBG_CreateMsgWin(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
extern int FIELD_MSGBG_DeleteMsgWin(FieldMsgWin *msgWin);
extern void FIELD_MSGBG_ClearMsgWin(FieldMsgWin *msgWin);
extern struct BmpMenuWork *FIELD_MSGBG_CreateMenuItemsFromTable(const FieldMenuItemData *itemData, int count, struct MsgData *msgData, u16 heapId);
extern FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncCallback(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                                    u32 moveCallback, u32 lineCallback, u32 work);
extern int FIELD_MSGBG_DeleteMenuFunc(FieldMenuFunc *menu);
extern int FIELD_MSGBG_MenuFuncMain(FieldMenuFunc *menu);
extern int FIELD_MSGBG_DeleteSysWin(FieldSysWin *sysWin);
extern void FIELD_MSGBG_SysWinPrintMsg(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
extern u32 FIELD_MSGBG_SysWinMain(FieldSysWin *sysWin);
extern FieldSysWin *FIELD_MSGBG_CreateBottomSysWin(FieldMsgBg *msgBg, struct MsgData *msgData);

extern const char d_021DE5BC[];
extern const char d_021DE5C0[];
extern ListPosition d_021DB404;
extern const IconPosition d_021DB40C;
extern FieldMenuItemData d_021DB414[];
extern FieldMenuHeader d_021DB42C;

PartySelectList *PARTY_SELECT_LIST_Create(void *owner, void *firstParty, void *secondParty, u32 sideFlagFirst, u32 sideFlagSecond, u16 heapId);
u32 PARTY_SELECT_LIST_Delete(PartySelectList *list, u32 *outFlag);
int PARTY_SELECT_LIST_Main(PartySelectList *list);
u32 PARTY_SELECT_LIST_GetResult(PartySelectList *list, u32 *outFlag);
void PARTY_SELECT_LIST_LoadMonIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_FreeMonIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_CreateMonIcons(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteMonIcons(PartySelectList *list);
void PARTY_SELECT_LIST_SetMonIconsVisible(PartySelectList *list, int side);
void PARTY_SELECT_LIST_LoadStatusIconResources(PartySelectList *list);
int PARTY_SELECT_LIST_FreeStatusIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_CreateStatusIcons(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteStatusIcons(PartySelectList *list);
void PARTY_SELECT_LIST_SetStatusIconsVisible(PartySelectList *list, int side);
void PARTY_SELECT_LIST_InitMessageResources(PartySelectList *list);
int PARTY_SELECT_LIST_FreeMessageResources(PartySelectList *list);
void PARTY_SELECT_LIST_CreateMenu(PartySelectList *list);
void PARTY_SELECT_LIST_ProcessMenu(PartySelectList *list);
u32 PARTY_SELECT_LIST_GetMenuResult(PartySelectList *list);
void PARTY_SELECT_LIST_MenuMoveCallback(struct BmpMenuList *menu, u32 sel);
void PARTY_SELECT_LIST_MenuSelectCallback(struct BmpMenuList *menu, int k);
void PARTY_SELECT_LIST_CreateTextWindow(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteTextWindow(PartySelectList *list);
void PARTY_SELECT_LIST_PrintText(PartySelectList *list, u32 msgId);
int PARTY_SELECT_LIST_IsTextDone(PartySelectList *list);
void PARTY_SELECT_LIST_CreateListWindow(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteListWindow(PartySelectList *list);
void PARTY_SELECT_LIST_PrintPartyNames(PartySelectList *list, void *party);
void PARTY_SELECT_LIST_ShowParty(PartySelectList *list, u32 sel);
void PARTY_SELECT_LIST_HideParty(PartySelectList *list);


PartySelectList *PARTY_SELECT_LIST_Create(void *owner, void *firstParty, void *secondParty, u32 sideFlagFirst, u32 sideFlagSecond, u16 heapId)
{
    PartySelectList *list;

    if (firstParty == 0 || secondParty == 0)
        GF_PANIC_Fail(d_021DE5BC, 0, d_021DE5BC);
    list = GFL_HEAP_Alloc(heapId, 0xc4, 1, (char *)d_021DE5C0, 0xd3);
    list->owner = owner;
    list->party[0] = firstParty;
    list->party[1] = secondParty;
    list->heapId = heapId;
    list->sideFlagFirst = sideFlagFirst;
    list->sideFlagSecond = sideFlagSecond;
    list->actorBank = CLACT_CreateUnit(0x20, 0xa, list->heapId);
    list->font = GF_FONT_Create(0x17, 3, 0, 0, list->heapId);
    PARTY_SELECT_LIST_InitMessageResources(list);
    PARTY_SELECT_LIST_LoadMonIconResources(list);
    PARTY_SELECT_LIST_CreateMonIcons(list);
    PARTY_SELECT_LIST_LoadStatusIconResources(list);
    PARTY_SELECT_LIST_CreateStatusIcons(list);
    return list;
}


u32 PARTY_SELECT_LIST_Delete(PartySelectList *list, u32 *outFlag)
{
    u32 result;

    result = PARTY_SELECT_LIST_GetResult(list, outFlag);
    if (list->finished != 1)
        GF_PANIC_Fail(d_021DE5BC, 0, d_021DE5BC);
    PARTY_SELECT_LIST_DeleteStatusIcons(list);
    PARTY_SELECT_LIST_FreeStatusIconResources(list);
    PARTY_SELECT_LIST_DeleteMonIcons(list);
    PARTY_SELECT_LIST_FreeMonIconResources(list);
    PARTY_SELECT_LIST_FreeMessageResources(list);
    GF_FONT_Delete(list->font);
    CLACT_DeleteUnit(list->actorBank);
    GFL_HEAP_Free(list);
    return result;
}


/*
 * Main state machine on the byte at +0xc0 (step). The inner switch on an unsigned
 * result (cases 2, -2, -1) is what gives the compare order 2, -2, -1 and
 * the dead second -1 test.
 */
int PARTY_SELECT_LIST_Main(PartySelectList *list)
{
    u32 menuResult;

    switch (list->step) {
    case 0:
        PARTY_SELECT_LIST_CreateTextWindow(list);
        PARTY_SELECT_LIST_PrintText(list, 3);
        list->step = list->step + 1;
        break;
    case 1:
        if (PARTY_SELECT_LIST_IsTextDone(list) == 1) {
            PARTY_SELECT_LIST_CreateMenu(list);
            list->step = list->step + 1;
        }
        break;
    case 2:
        if (FIELD_MSGBG_IsPrintQueFinished(list->msgBg) == 1) {
            menuResult = PARTY_SELECT_LIST_GetMenuResult(list);
            if (menuResult == -1)
                break;
            PARTY_SELECT_LIST_ProcessMenu(list);
            PARTY_SELECT_LIST_HideParty(list);
            PARTY_SELECT_LIST_DeleteTextWindow(list);
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


u32 PARTY_SELECT_LIST_GetResult(PartySelectList *list, u32 *outFlag)
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


void PARTY_SELECT_LIST_LoadMonIconResources(PartySelectList *list)
{
    void *arc;
    int i;
    int count;

    arc = ARC_TOOL_CreateHandle(7, list->heapId);
    list->monIconPalette = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 0, 0x60, list->heapId);
    list->monIconCell = CLACT_RegisterCellAnim(arc, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), list->heapId);
    count = POKEPARTY_GetCount(list->party[0]);
    for (i = 0; i < count; i++) {
        list->monIconRes[0][i] = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex((void *)POKE_TOOL_CastToBoxParam(POKEPARTY_GetMember(list->party[0], i))), 0, 0, list->heapId);
    }
    if (list->party[1] != 0) {
        count = POKEPARTY_GetCount(list->party[1]);
        for (i = 0; i < count; i++) {
            list->monIconRes[1][i] = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex((void *)POKE_TOOL_CastToBoxParam(POKEPARTY_GetMember(list->party[1], i))), 0, 0, list->heapId);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}


void PARTY_SELECT_LIST_FreeMonIconResources(PartySelectList *list)
{
    int i;
    int count;

    if (list->party[1]) {
        count = POKEPARTY_GetCount(list->party[1]);
        for (i = 0; i < count; i++)
            CLACT_ReleaseCharacter(list->monIconRes[1][i]);
    }
    count = POKEPARTY_GetCount(list->party[0]);
    for (i = 0; i < count; i++)
        CLACT_ReleaseCharacter(list->monIconRes[0][i]);
    CLACT_ReleaseCellAnim(list->monIconCell);
    CLACT_ReleasePalette(list->monIconPalette);
}


void PARTY_SELECT_LIST_CreateMonIcons(PartySelectList *list)
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

    count0 = POKEPARTY_GetCount(list->party[0]);
    for (i = 0; i < count0; i++) {
        pos.x = i * 0x28 + 0x18;
        list->monIcon[0][i] = CLACT_CreateActor(list->actorBank, list->monIconRes[0][i], list->monIconPalette, list->monIconCell, &pos, 0, list->heapId);
        mon = POKEPARTY_GetMember(list->party[0], i);
        species = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_SPECIES, 0);
        form = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_FORM, 0);
        isEgg = (POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_SPECIES_OR_EGG, 0) == 0x28a) ? 1 : 0;
        iconKind = POKE_TOOL_CalcIconPalette(species, form, POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_GENDER, 0), isEgg);
        CLACT_SetActorPaletteOffset((struct Actor *)list->monIcon[0][i], (u8)iconKind, 1);
        CLACT_SetActorDrawEnable((struct Actor *)list->monIcon[0][i], 0);
    }
    if (list->party[1] != 0) {
        count1 = POKEPARTY_GetCount(list->party[1]);
        for (i = 0; i < count1; i++) {
            pos.x = i * 0x28 + 0x18;
            list->monIcon[1][i] = CLACT_CreateActor(list->actorBank, list->monIconRes[1][i], list->monIconPalette, list->monIconCell, &pos, 0, list->heapId);
            mon = POKEPARTY_GetMember(list->party[1], i);
            species = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_SPECIES, 0);
            form = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_FORM, 0);
            isEgg = (POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_SPECIES_OR_EGG, 0) == 0x28a) ? 1 : 0;
            iconKind = POKE_TOOL_CalcIconPalette(species, form, POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_GENDER, 0), isEgg);
            CLACT_SetActorPaletteOffset((struct Actor *)list->monIcon[1][i], (u8)iconKind, 1);
            CLACT_SetActorDrawEnable((struct Actor *)list->monIcon[1][i], 0);
        }
    }
}


void PARTY_SELECT_LIST_DeleteMonIcons(PartySelectList *list)
{
    int i;
    int count;

    count = POKEPARTY_GetCount(list->party[0]);
    for (i = 0; i < count; i++)
        CLACT_DeleteActor((struct Actor *)list->monIcon[0][i]);
    if (list->party[1]) {
        count = POKEPARTY_GetCount(list->party[1]);
        for (i = 0; i < count; i++)
            CLACT_DeleteActor((struct Actor *)list->monIcon[1][i]);
    }
}


void PARTY_SELECT_LIST_SetMonIconsVisible(PartySelectList *list, int side)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (list->monIcon[0][i] != 0)
            CLACT_SetActorDrawEnable((struct Actor *)list->monIcon[0][i], 0);
        if (list->monIcon[1][i] != 0)
            CLACT_SetActorDrawEnable((struct Actor *)list->monIcon[1][i], 0);
    }
    if (side == 0) {
        for (i = 0; i < 6; i++) {
            if (list->monIcon[0][i] != 0)
                CLACT_SetActorDrawEnable((struct Actor *)list->monIcon[0][i], 1);
        }
    } else if (side == 1) {
        for (i = 0; i < 6; i++) {
            if (list->monIcon[1][i] != 0)
                CLACT_SetActorDrawEnable((struct Actor *)list->monIcon[1][i], 1);
        }
    }
}


void PARTY_SELECT_LIST_LoadStatusIconResources(PartySelectList *list)
{
    void *arc;
    u32 cellRes;
    u32 animRes;

    arc = ARC_TOOL_CreateHandle(0x53, list->heapId);
    list->statusIconCell = CLACT_RegisterPaletteEx(arc, APP_ICON_GetItemCellFileId(), 0, 0xc0, 0, 1, list->heapId);
    cellRes = APP_ICON_GetItemAnimFileId(1);
    animRes = APP_ICON_GetItemFrameFileId(1);
    list->statusIconAnim = CLACT_RegisterCellAnim(arc, cellRes, animRes, list->heapId);
    list->statusIconRes = CLACT_RegisterCharacter(arc, APP_ICON_GetItemPaletteFileId(), 0, 0, list->heapId);
    ARC_TOOL_DeleteHandle(arc);
}


int PARTY_SELECT_LIST_FreeStatusIconResources(PartySelectList *list)
{
    CLACT_ReleaseCharacter(list->statusIconRes);
    CLACT_ReleaseCellAnim(list->statusIconAnim);
    return CLACT_ReleasePalette(list->statusIconCell);
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
void PARTY_SELECT_LIST_CreateStatusIcons(PartySelectList *list)
{
    IconPosition pos = d_021DB40C;
    int count0;
    int count1;
    int i;
    u32 species;

    count0 = POKEPARTY_GetCount(list->party[0]);
    for (i = 0; i < count0; i++) {
        species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(list->party[0], i), 6, 0);
        if (species != 0) {
            if (FILE_UTIL_IsMailItem(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
            pos.x = i * 0x28 + 0x20;
            list->statusIcon[0][i] = CLACT_CreateActor(list->actorBank, list->statusIconRes, list->statusIconCell, list->statusIconAnim, &pos, 0, list->heapId);
            CLACT_SetActorDrawEnable((struct Actor *)list->statusIcon[0][i], 0);
        }
    }
    if (list->party[1] != 0) {
        count1 = POKEPARTY_GetCount(list->party[1]);
        for (i = 0; i < count1; i++) {
            species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(list->party[1], i), 6, 0);
            if (species != 0) {
                if (FILE_UTIL_IsMailItem(species) == 1) {
                    pos.alt = 1;
                } else {
                    pos.alt = 0;
                }
                pos.x = i * 0x28 + 0x20;
                list->statusIcon[1][i] = CLACT_CreateActor(list->actorBank, list->statusIconRes, list->statusIconCell, list->statusIconAnim, &pos, 0, list->heapId);
                CLACT_SetActorDrawEnable((struct Actor *)list->statusIcon[1][i], 0);
            }
        }
    }
}


void PARTY_SELECT_LIST_DeleteStatusIcons(PartySelectList *list)
{
    int i;
    int count;

    count = POKEPARTY_GetCount(list->party[0]);
    for (i = 0; i < count; i++) {
        if (list->statusIcon[0][i])
            CLACT_DeleteActor((struct Actor *)list->statusIcon[0][i]);
    }
    if (list->party[1]) {
        count = POKEPARTY_GetCount(list->party[1]);
        for (i = 0; i < count; i++) {
            if (list->statusIcon[1][i])
                CLACT_DeleteActor((struct Actor *)list->statusIcon[1][i]);
        }
    }
}


void PARTY_SELECT_LIST_SetStatusIconsVisible(PartySelectList *list, int side)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (list->statusIcon[0][i] != 0)
            CLACT_SetActorDrawEnable((struct Actor *)list->statusIcon[0][i], 0);
        if (list->statusIcon[1][i] != 0)
            CLACT_SetActorDrawEnable((struct Actor *)list->statusIcon[1][i], 0);
    }
    if (side == 0) {
        for (i = 0; i < 6; i++) {
            if (list->statusIcon[0][i] != 0)
                CLACT_SetActorDrawEnable((struct Actor *)list->statusIcon[0][i], 1);
        }
    } else if (side == 1) {
        for (i = 0; i < 6; i++) {
            if (list->statusIcon[1][i] != 0)
                CLACT_SetActorDrawEnable((struct Actor *)list->statusIcon[1][i], 1);
        }
    }
}


/*
 * Fetches the message handles of the list: the message BG system of the
 * owner, its 0x54 message data and a new word set.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_InitMessageResources(PartySelectList *list)
{
    FieldMsgBg *msgBg = FIELDMAP_GetMsgBg(list->owner);
    list->msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0x54);
    list->msgBg = msgBg;
    list->wordSet = WORDSET_CreateDefault(list->heapId);
}


int PARTY_SELECT_LIST_FreeMessageResources(PartySelectList *list)
{
    WORDSET_Delete(list->wordSet);
    return FIELD_MSGBG_DeleteMsgData(list->msgData);
}


void PARTY_SELECT_LIST_CreateMenu(PartySelectList *list)
{
    struct BmpMenuWork *items;

    items = FIELD_MSGBG_CreateMenuItemsFromTable(d_021DB414, 3, list->msgData, list->heapId);
    list->menu = FIELD_MSGBG_CreateMenuFuncCallback(list->msgBg, &d_021DB42C, items, 0, 0,
        (u32)PARTY_SELECT_LIST_MenuMoveCallback, (u32)PARTY_SELECT_LIST_MenuSelectCallback, (u32)list);
}


/*
 * Tail call on the menu at +0xac.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_ProcessMenu(PartySelectList *list)
{
    FIELD_MSGBG_DeleteMenuFunc(list->menu);
}


u32 PARTY_SELECT_LIST_GetMenuResult(PartySelectList *list)
{
    return FIELD_MSGBG_MenuFuncMain(list->menu);
}


/*
 * Menu move callback: selector below two refreshes that side through
 * PARTY_SELECT_LIST_ShowParty, otherwise the lists are hidden through PARTY_SELECT_LIST_HideParty.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_MenuMoveCallback(struct BmpMenuList *menu, u32 sel)
{
    PartySelectList *list = (PartySelectList *)BMP_MENULIST_GetUserData(menu);
    if (sel < 2)
        PARTY_SELECT_LIST_ShowParty(list, sel);
    else
        PARTY_SELECT_LIST_HideParty(list);
}


void PARTY_SELECT_LIST_MenuSelectCallback(struct BmpMenuList *menu, int k)
{
    PartySelectList *list = (PartySelectList *)BMP_MENULIST_GetUserData(menu);

    if (k == 0 && list->sideFlagFirst == 1) {
        BMP_MENULIST_SetOverrideColors(menu, 1, 0, 2);
        return;
    }
    if (k == 1) {
        BMP_MENULIST_SetOverrideColors(menu, 1, 0, 2);
        return;
    }
    BMP_MENULIST_SetOverrideColors(menu, 1, 0, 2);
}


/*
 * Builds the system window (+0xB0) of the list from its message BG system and message data.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_CreateTextWindow(PartySelectList *list)
{
    list->textWin = FIELD_MSGBG_CreateBottomSysWin(list->msgBg, list->msgData);
}


/*
 * Tail call on the system window at +0xb0.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_DeleteTextWindow(PartySelectList *list)
{
    FIELD_MSGBG_DeleteSysWin(list->textWin);
}


void PARTY_SELECT_LIST_PrintText(PartySelectList *list, u32 msgId)
{
    FIELD_MSGBG_SysWinPrintMsg(list->textWin, 0, 0, msgId);
}


int PARTY_SELECT_LIST_IsTextDone(PartySelectList *list)
{
    return FIELD_MSGBG_SysWinMain(list->textWin);
}


/*
 * Creates the message window (+0xB4) of the list once, from its message BG system and message data.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_CreateListWindow(PartySelectList *list)
{
    if (list->listWin == 0)
        list->listWin = FIELD_MSGBG_CreateMsgWin(list->msgBg, list->msgData, 1, 2, 0x1e, 6);
}


/*
 * Releases the message window (+0xB4) of the list if it is set and clears it.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_DeleteListWindow(PartySelectList *list)
{
    if (list->listWin != 0) {
        FIELD_MSGBG_DeleteMsgWin(list->listWin);
        list->listWin = 0;
    }
}

void PARTY_SELECT_LIST_PrintPartyNames(PartySelectList *list, void *party)
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

    PARTY_SELECT_LIST_CreateListWindow(list);
    FIELD_MSGBG_ClearMsgWin(list->listWin);
    nameBuf = STRBUF_Create(0x40, list->heapId);
    templateBuf = STRBUF_Create(0x40, list->heapId);
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_IS_EGG, 0) != 0) {
            continue;
        }
        species = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_SPECIES, 0);
        isNicknamed = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN, 0);
        nickname = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_LEVEL, 0);
        gender = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_GENDER, 0);
        MSGDATA_ReadString((struct MsgBank *)list->msgData, 4, templateBuf);
        WORDSET_SetSlotNumber(list->wordSet, 0, nickname, 3, 0, 1);
        WORDSET_CopyTaggedText(list->wordSet, nameBuf, templateBuf);
        x = i * 0x28;
        FIELD_MSGBG_MsgWinPrintStrColorFont(list->listWin, x, 0x20, nameBuf, 0x440, list->font);
        if (gender == 2) {
            continue;
        }
        if ((species == 0x1d || species == 0x20) && isNicknamed == 0) {
            continue;
        }
        if (gender == 0) {
            FIELD_MSGBG_MsgWinPrintMsg(list->listWin, (u16)(x + 0x1f), 0x10, 5);
        } else {
            FIELD_MSGBG_MsgWinPrintMsg(list->listWin, (u16)(x + 0x1f), 0x10, 6);
        }
    }
    STRBUF_Delete(nameBuf);
    STRBUF_Delete(templateBuf);
}


/*
 * Selector 0 or 1 path of PARTY_SELECT_LIST_MenuMoveCallback: prints the names of that side, then refreshes the two per-side icon sets.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_ShowParty(PartySelectList *list, u32 sel)
{
    PARTY_SELECT_LIST_PrintPartyNames(list, sel == 0 ? list->party[0] : list->party[1]);
    PARTY_SELECT_LIST_SetMonIconsVisible(list, sel);
    PARTY_SELECT_LIST_SetStatusIconsVisible(list, sel);
}


/*
 * Hides the name window and all icons.
 *
 * Addresses are Black-image addresses.
 */
void PARTY_SELECT_LIST_HideParty(PartySelectList *list)
{
    PARTY_SELECT_LIST_DeleteListWindow(list);
    PARTY_SELECT_LIST_SetMonIconsVisible(list, 2);
    PARTY_SELECT_LIST_SetStatusIconsVisible(list, 2);
}
