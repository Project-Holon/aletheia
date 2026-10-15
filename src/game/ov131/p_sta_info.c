/*
 * file:     p_sta_info.c
 * unit:     yes
 * function: P_STA_INFO_AllocWork, P_STA_INFO_FreeWork, P_STA_INFO_Main, P_STA_INFO_LoadResources, P_STA_INFO_FreeResources, P_STA_INFO_Setup, P_STA_INFO_ShowPage, P_STA_INFO_DeleteWindows, P_STA_INFO_HidePage, P_STA_INFO_DrawStats, P_STA_INFO_DrawMemo, P_STA_INFO_GetPlaceName
 * address:  0x021D7B00
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from p_sta_oam.c: 0x021D7B00-0x021D87E0. Cuts at the __FILE__ anchor functions (layout/file_anchors.txt);
 * the functions in this range use struct StaOamSub8C (PStatusWork.infoWork).
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_02030734 0x02030734 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   d_021DC824 0x021DC824 data a1
 *   func_02049EF4 0x02049EF4 arm
 *   d_021DC288 0x021DC288 data a1
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   POKE_TOOL_IsBoxShiny 0x02017EB4 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   func_02018584 0x02018584 thumb
 *   BMP_FillRect 0x02043AF4 arm
 *   gSpeciesNameBank 0x020A7370 data
 *   d_021DC24C 0x021DC24C data
 *   d_021DC264 0x021DC264 data
 *   EVENT_ID_GetBank 0x0202F688 thumb
 *   EVENT_ID_GetIndex 0x0202F6D8 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_PrintMsgToWin 0x021D618C thumb ov131
 *   P_STATUS_PrintWordSetMsgToWin 0x021D6214 thumb ov131
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   GF_FONT_CountLine  0x0201D2C8  thumb  arm9
 *   SAVE_EVENT_CheckStage  0x0202F498  thumb  arm9
 */

#include "p_status_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct Actor;
struct BmpWin;
struct Bmp;
struct MsgBank;
struct Strbuf;
struct WordSet;

/* Indices of PStaInfoWork.win. */
enum {
    STA_INFO_WIN_DEX_NO,            /* national or regional dex number */
    STA_INFO_WIN_SPECIES,           /* species name */
    STA_INFO_WIN_TYPE,              /* "Type" label (the icons are actors) */
    STA_INFO_WIN_OT_NAME,           /* trainer name label and value */
    STA_INFO_WIN_ID_NO,             /* ID number label and value */
    STA_INFO_WIN_EXP_LABEL,         /* "Exp. Points" label */
    STA_INFO_WIN_EXP_VALUE,         /* experience points */
    STA_INFO_WIN_NEXT_LV_LABEL,     /* "Next Lv." label */
    STA_INFO_WIN_NEXT_LV_VALUE,     /* experience needed for the next level */
    STA_INFO_WIN_EXP_BAR,           /* the experience bar */
    STA_INFO_WIN_MEMO,              /* trainer memo text */
    STA_INFO_WIN_MAX
};

/* Info page work (page 0, PStatusWork.infoWork, 0x6C bytes). */
struct PStaInfoWork {
    unsigned int isDrawn;               /* 0x00: 1 once the stat texts were printed */
    int isWinActive;                    /* 0x04: 1 while the windows exist */
    u16 *dexTable;                      /* 0x08: national dex number to regional dex number */
    struct BmpWin *win[STA_INFO_WIN_MAX];       /* 0x0C: STA_INFO_WIN_* */
    struct MsgBank *msgInfo;            /* 0x38: status screen texts (labels, trainer memo) */
    struct MsgBank *msgPlaceBank89;     /* 0x3C: place names, bank 89, also the fallback */
    struct MsgBank *msgPlaceBank92;     /* 0x40: place names, bank 92 */
    struct MsgBank *msgPlaceBank90;     /* 0x44: place names, bank 90 */
    struct MsgBank *msgPlaceBank91;     /* 0x48: place names, bank 91 */
    void *bgScrnData;                   /* 0x4C: contents of bgScrnFile (normal Pokemon background) */
    void *bgScrnFile;                   /* 0x50: archive file 63 */
    void *eggScrnData;                  /* 0x54: contents of eggScrnFile (egg background) */
    void *eggScrnFile;                  /* 0x58: archive file 72 */
    void *palData;                      /* 0x5C: contents of palFile */
    void *palFile;                      /* 0x60: archive file 64, palette */
    void *barScrnData;                  /* 0x64: contents of barScrnFile */
    void *barScrnFile;                  /* 0x68: archive file 65, experience bar screen */
};


/* Parameter ids read in the memo, in the order of the characteristic table rows. */
struct StaInfoStatIds { u32 id[6]; };
struct StaInfoStatRows { u8 row[6][6]; };

extern u32 func_020307B0(void *p);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 anim);
extern void BG_SYS_PushTile(u32);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 enable);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
extern u32 func_02017E88(void *mon, int paramId, void *out);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct Strbuf *str);
extern void PRINTSYS_PrintQueColor(void *printQue, struct Bmp *bmp, u32 x, u32 y, struct Strbuf *str, void *font, u16 color);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void func_02041B6C(u32);
extern u32 POKE_TOOL_IsBoxShiny(void *mon);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotTag(struct WordSet *wordSet, u32 index, const struct Strbuf *src, u32 a, u32 b, u32 c);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 a, u32 b);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern void *func_02049EF4(void *arc, unsigned int fileId, unsigned int a, void **dataOut, unsigned short heapId);
extern void BG_SYS_DrawTileEx(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);
extern void CLACT_GetCharacterProxy(u32 res, StaSpriteRes *out);
extern void CLACT_SetActorImageProxy(struct Actor *actor, const StaSpriteRes *src);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, u32 v, u32 flag);
extern void CLACT_AddActorSurfacePos(struct Actor *actor, const StaOamPoint *delta, u32 which);
extern void CLACT_SetActorBgPriority(struct Actor *actor, u32 enable);
extern void BG_SYS_SetTileEntry(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern u32 func_02018584(u16,u16,u16);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern int SAVE_EVENT_CheckStage(void *mon, int index);
extern u8 *func_02012944(void *p);
extern u32 POKE_TOOL_IsBoxOwnedByPlayer(void *mon, void *trainer);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern u32 GF_FONT_CountLine(struct Strbuf *s);
extern unsigned int EVENT_ID_GetBank(unsigned int);
extern unsigned int EVENT_ID_GetIndex(unsigned int);
void *P_STATUS_GetPokePara(PStatusWork *wk);
void P_STATUS_PrintMsgToWin(PStatusWork *wk, struct BmpWin *win, int msgId, int x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsgToWin(PStatusWork *wk, struct BmpWin *win, void *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);
PStaInfoWork *P_STA_INFO_AllocWork(PStatusWork *wk);
void P_STA_INFO_FreeWork(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_Main(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_LoadResources(PStatusWork *wk, PStaInfoWork *work, void *arc);
void P_STA_INFO_FreeResources(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_Setup(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_ShowPage(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_DeleteWindows(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_HidePage(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_DrawStats(PStatusWork *wk, PStaInfoWork *work, void *mon);
void P_STA_INFO_DrawMemo(PStatusWork *wk, PStaInfoWork *work, void *mon);
void *P_STA_INFO_GetPlaceName(PStatusWork *wk, PStaInfoWork *work, unsigned int placeId);
extern const char d_021DC824[];
extern const unsigned char d_021DC288[];
extern struct MsgBank *gSpeciesNameBank;
extern const u32 d_021DC24C[6];
extern const u8 d_021DC264[6][6];

PStaInfoWork *P_STA_INFO_AllocWork(PStatusWork *wk) {
 PStaInfoWork *work=func_02030734(wk->heapId,0x6c,0,d_021DC824,0xc1);
 work->isDrawn=0;
 work->isWinActive=0;
 work->dexTable=POKE_PERSONAL_LoadFormTable(wk->heapId,0);
 return work;
}

void P_STA_INFO_FreeWork(PStatusWork *wk, PStaInfoWork *work)
{
    func_020307B0(work->dexTable);
    func_020307B0(work);
}

/*
 * interface: caller 021D44C8 loads r0=context,r1=child; complete leaf
 *   021D7B48 is bx lr, consumes neither input and supplies no return value.
 */
void P_STA_INFO_Main(PStatusWork *wk, PStaInfoWork *work) {}

void P_STA_INFO_LoadResources(PStatusWork *wk, PStaInfoWork *work, void *arc)
{
    work->bgScrnFile = func_02049EF4(arc, 63, 0, &work->bgScrnData, wk->heapId);
    work->eggScrnFile = func_02049EF4(arc, 72, 0, &work->eggScrnData, wk->heapId);
    work->palFile = func_02049EF4(arc, 64, 0, &work->palData, wk->heapId);
    work->barScrnFile = func_02049EF4(arc, 65, 0, &work->barScrnData, wk->heapId);
    work->msgInfo = func_02045B38(0, 2, 188, wk->heapId);
    work->msgPlaceBank89 = func_02045B38(0, 2, 89, wk->heapId);
    work->msgPlaceBank92 = func_02045B38(0, 2, 92, wk->heapId);
    work->msgPlaceBank90 = func_02045B38(0, 2, 90, wk->heapId);
    work->msgPlaceBank91 = func_02045B38(0, 2, 91, wk->heapId);
}

void P_STA_INFO_FreeResources(PStatusWork *wk, PStaInfoWork *work)
{
    if (work->isWinActive == 1) P_STA_INFO_DeleteWindows(wk, work);
    MSGDATA_Delete(work->msgInfo);
    MSGDATA_Delete(work->msgPlaceBank89);
    MSGDATA_Delete(work->msgPlaceBank92);
    MSGDATA_Delete(work->msgPlaceBank90);
    MSGDATA_Delete(work->msgPlaceBank91);
    func_020307B0(work->bgScrnFile);
    func_020307B0(work->eggScrnFile);
    func_020307B0(work->palFile);
    func_020307B0(work->barScrnFile);
}

void P_STA_INFO_Setup(PStatusWork *wk, PStaInfoWork *work)
{
    void *mon=P_STATUS_GetPokePara(wk);
    unsigned char i;
    for(i=0;i<10;i++) {
        unsigned int winOffset=i*4;
        *(struct BmpWin **)((u8 *)work->win+winOffset)=BMP_WIN_Create(1,d_021DC288[winOffset],d_021DC288[winOffset+1],d_021DC288[winOffset+2],d_021DC288[winOffset+3],14,1);
    }
    work->win[STA_INFO_WIN_MEMO]=BMP_WIN_Create(4,4,5,24,20,14,1);
    P_STA_INFO_DrawStats(wk,work,mon);
    P_STA_INFO_DrawMemo(wk,work,mon);
    work->isWinActive=1;
}

void P_STA_INFO_ShowPage(PStatusWork *wk, PStaInfoWork *work)
{
    StaSpriteRes header1,header2;
    StaOamPoint offset;
    u8 i;
    void *mon;
    struct BmpWin *win;
    u32 type1,type2;
    mon=P_STATUS_GetPokePara(wk);
    if(wk->isEgg==0) BG_SYS_DrawTileEx(2,0,0,32,24,(u32)((u8 *)work->bgScrnData+12),0,0,32,32);
    else BG_SYS_DrawTileEx(2,0,0,32,24,(u32)((u8 *)work->eggScrnData+12),0,0,32,32);
    func_02041B6C(2);
    BG_SYS_DecodeTile(6,(u8 *)work->palData+12,((StaGraphicsFile *)((u8 *)work->palData))->dataSize);
    func_02041B6C(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,(u32)((u8 *)work->barScrnData+12),0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        win=work->win[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    }
    win=work->win[STA_INFO_WIN_MEMO];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    if(wk->isEgg==0) {
        type1=func_02017E88(mon,174,0);
        type2=func_02017E88(mon,175,0);
        CLACT_GetCharacterProxy(wk->typeChrRes[type1],&header1);
        CLACT_SetActorImageProxy(wk->typeIconActor[0],&header1);
        CLACT_SetActorPaletteOffset(wk->typeIconActor[0],APP_ICON_GetTypePaletteOffset((u8)type1),1);
        offset.x=96;
        offset.y=48;
        CLACT_AddActorSurfacePos(wk->typeIconActor[0],&offset,0);
        CLACT_SetActorDrawEnable(wk->typeIconActor[0],1);
        CLACT_SetActorBgPriority(wk->typeIconActor[0],1);
        if(type1!=type2) {
            CLACT_GetCharacterProxy(wk->typeChrRes[type2],&header2);
            CLACT_SetActorImageProxy(wk->typeIconActor[1],&header2);
            CLACT_SetActorPaletteOffset(wk->typeIconActor[1],APP_ICON_GetTypePaletteOffset((u8)type2),1);
            offset.x=130;
            offset.y=48;
            CLACT_AddActorSurfacePos(wk->typeIconActor[1],&offset,0);
            CLACT_SetActorDrawEnable(wk->typeIconActor[1],1);
            CLACT_SetActorBgPriority(wk->typeIconActor[1],1);
        } else CLACT_SetActorDrawEnable(wk->typeIconActor[1],0);
    } else {
        CLACT_SetActorDrawEnable(wk->typeIconActor[0],0);
        CLACT_SetActorDrawEnable(wk->typeIconActor[1],0);
    }
    CLACT_SetActorAnimSeq(wk->buttonActor[0],3);
}

void P_STA_INFO_DeleteWindows(PStatusWork *wk, PStaInfoWork *work) {
 unsigned char i;
 for(i=0;i<10;i++) {
  BMP_WIN_Delete(work->win[i]);
 }
 BMP_WIN_Delete(work->win[STA_INFO_WIN_MEMO]);
 work->isWinActive=0;
}

void P_STA_INFO_HidePage(PStatusWork *wk, PStaInfoWork *work)
{
    BG_SYS_SetTileEntry(1, 0, 0, 0, 19, 21, 16);
    func_02041B6C(1);
    BG_SYS_ClearLayerEx(4, 0);
    func_02041B6C(4);
    CLACT_SetActorDrawEnable(wk->typeIconActor[0], 0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[1], 0);
    CLACT_SetActorAnimSeq(wk->buttonActor[0], 0);
}

/*
 * note (2026-10-02): slot order closed by two source facts. (1) func_02017E88's third parameter is
 *   a buffer pointer (void *), so the 0x9a and 0x8d calls pass the otName buffer directly with no
 *   conversion; casting it to u32 lets the compiler share one conversion temp, which moves otName below
 *   the named locals. (2) The species argument in the first speciesName arm is a named local; nested, speciesName lands lowest.
 */
void P_STA_INFO_DrawStats(PStatusWork *wk, PStaInfoWork *work, void *mon)
{
    struct WordSet *dexWordSet;
    u32 dexNo;
    struct Strbuf *speciesName;
    struct Strbuf *otName;
    struct WordSet *otWordSet;
    u32 exp;
    u32 expNextLv;
    u32 expThisLv;
    u32 expToNext;
    struct WordSet *idWordSet,*expWordSet,*toNextWordSet;
    u32 species1,species2,level,growthRate,tmpValue,barPixels;
    u16 color;
    struct Bmp *bmp;
    u16 idNo;
    u32 species;
    if(wk->isEgg==0) {
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_DEX_NO],8,1,1,0x3c40);
        dexWordSet=WORDSET_CreateDefault(wk->heapId);
        dexNo=func_02017E88(mon,5,0);
        color=0x440;
        if(wk->param->isNationalDex==0) dexNo=work->dexTable[dexNo];
        if(POKE_TOOL_IsBoxShiny(mon)==1) color=0xc80;
        if(dexNo==999) {
            P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_INFO_WIN_DEX_NO],dexWordSet,0x16,0x41,1,color);
        } else {
            WORDSET_SetSlotNumber(dexWordSet,0,dexNo,3,2,1);
            P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_INFO_WIN_DEX_NO],dexWordSet,9,0x41,1,color);
        }
        WORDSET_DeleteStrbufED04(dexWordSet);
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_SPECIES],10,1,1,0x3c40);
        if(wk->isEgg==0) {species=func_02017E88(mon,5,0); speciesName=func_02045EC0(gSpeciesNameBank,species);}
        else speciesName=func_02045EC0(gSpeciesNameBank,0x28a);
        bmp=BMP_WIN_GetBmp(work->win[STA_INFO_WIN_SPECIES]);
        color=0x440;
        PRINTSYS_PrintQueColor(wk->printQue,bmp,0x41,1,speciesName,wk->font,color);
        STRBUF_Delete(speciesName);
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_TYPE],12,1,1,0x3c40);
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_OT_NAME],13,1,1,0x3c40);
        otName=STRBUF_Create(0x20,wk->heapId);
        otWordSet=WORDSET_CreateDefault(wk->heapId);
        tmpValue=func_02017E88(mon,0x9a,otName);
        if(tmpValue==0) color=0x14c0;
        else if(tmpValue==1) color=0xc80;
        func_02017E88(mon,0x8d,otName);
        WORDSET_SetSlotTag(otWordSet,0,otName,0,1,2);
        P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_INFO_WIN_OT_NAME],otWordSet,14,0x41,1,color);
        WORDSET_DeleteStrbufED04(otWordSet);
        STRBUF_Delete(otName);
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_ID_NO],15,1,1,0x3c40);
        idWordSet=WORDSET_CreateDefault(wk->heapId);
        idNo=func_02017E88(mon,7,0);
        WORDSET_SetSlotNumber(idWordSet,0,idNo,5,2,1);
        P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_INFO_WIN_ID_NO],idWordSet,16,0x41,1,0x440);
        WORDSET_DeleteStrbufED04(idWordSet);
        level=func_02017E88(mon,0x9e,0);
        exp=func_02017E88(mon,8,0);
        species1=func_02017E88(mon,5,0);
        growthRate=func_02017E88(mon,0x6f,0);
        expNextLv=func_02018584((u16)species1,(u16)growthRate,(u16)(level+1));
        species2=func_02017E88(mon,5,0);
        growthRate=func_02017E88(mon,0x6f,0);
        expThisLv=func_02018584((u16)species2,(u16)growthRate,(u16)level);
        expToNext=expNextLv-exp;
        if(level==100) expToNext=0;
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_EXP_LABEL],17,1,1,0x3c40);
        expWordSet=WORDSET_CreateDefault(wk->heapId);
        WORDSET_SetSlotNumber(expWordSet,0,exp,7,0,1);
        P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_INFO_WIN_EXP_VALUE],expWordSet,18,1,1,0x440);
        WORDSET_DeleteStrbufED04(expWordSet);
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_NEXT_LV_LABEL],19,1,1,0x3c40);
        P_STATUS_PrintMsgToWin(wk,work->win[STA_INFO_WIN_NEXT_LV_VALUE],20,1,1,0x440);
        toNextWordSet=WORDSET_CreateDefault(wk->heapId);
        WORDSET_SetSlotNumber(toNextWordSet,0,expToNext,6,0,1);
        P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_INFO_WIN_NEXT_LV_VALUE],toNextWordSet,21,0x21,1,0x440);
        WORDSET_DeleteStrbufED04(toNextWordSet);
        if(level!=100) {
            tmpValue=expNextLv-expThisLv-expToNext;
            barPixels=(tmpValue<<6)/(expNextLv-expThisLv);
            if(tmpValue!=0 && barPixels==0) barPixels=1;
            if(barPixels==0x40) barPixels=barPixels-1;
            BMP_FillRect(BMP_WIN_GetBmp(work->win[STA_INFO_WIN_EXP_BAR]),0,3,(u16)barPixels,3,5);
        }
    }
    work->isDrawn=1;
}

/*
 * note: 2026-10-02 relaunch R8. The 0 passed as the number style to the
 *   later SetNumber calls is the same u8 local that later holds the best
 *   row index (stack slot 0x14); max is seeded from it before the table
 *   copies, and the loop counter is zeroed before the row lookup.
 *   WORDSET_Create takes an int heap here (no u8 narrowing in the caller).
 */
void P_STA_INFO_DrawMemo(PStatusWork *wk, PStaInfoWork *work, void *mon)
{
    void *metPlaceStr;
    void *eggPlaceStr;
    u32 natureMsg;
    int textY;
    u32 isOriginalTrainer;
    u32 isEgg;
    u32 eggSteps;
    u32 eggYear;
    u32 eggMonth;
    u32 eggDay;
    u32 metYear;
    u32 metMonth;
    u32 metDay;
    u32 metLevel;
    u32 isFatefulEncounter;
    u32 encounterType;
    u32 personalRandom;
    u32 eggPlace;
    u32 eventFlags;
    void *infoStr;
    void *wordSet;
    void *msgStr;
    u32 metPlace;
    u32 flag0;
    u32 flag1;
    u32 flag2;
    u32 flag3;
    u16 msgId;
    u16 msgIdAlt;
    u8 bestStat;

    textY = 0;
    isEgg = func_02017E88(mon, 0x4c, 0);
    natureMsg = func_02017E88(mon, 0x70, 0);
    eggSteps = func_02017E88(mon, 9, 0);
    eggYear = func_02017E88(mon, 0x8f, 0);
    eggMonth = func_02017E88(mon, 0x90, 0);
    eggDay = func_02017E88(mon, 0x91, 0);
    metYear = func_02017E88(mon, 0x92, 0);
    metMonth = func_02017E88(mon, 0x93, 0);
    metDay = func_02017E88(mon, 0x94, 0);
    metLevel = func_02017E88(mon, 0x99, 0);
    isFatefulEncounter = func_02017E88(mon, 0x6d, 0);
    encounterType = func_02017E88(mon, 0x77, 0);
    personalRandom = func_02017E88(mon, 0, 0);
    eggPlace = func_02017E88(mon, 0x95, 0);
    metPlace = func_02017E88(mon, 0x96, 0);
    flag0 = SAVE_EVENT_CheckStage(mon, 0);
    flag1 = SAVE_EVENT_CheckStage(mon, 1);
    flag2 = SAVE_EVENT_CheckStage(mon, 2);
    flag3 = SAVE_EVENT_CheckStage(mon, 3);
    eventFlags = flag0 | flag1 | flag2 | flag3;
    isOriginalTrainer = POKE_TOOL_IsBoxOwnedByPlayer(mon, func_02012944(wk->param->config));

    if (isEgg == 0) {
        msgStr = func_02045EC0(work->msgInfo, natureMsg);
        PRINTSYS_PrintQueColor(wk->printQue, BMP_WIN_GetBmp(work->win[STA_INFO_WIN_MEMO]), (s16)1, (s16)1, msgStr, wk->font, 0x440);
        STRBUF_Delete(msgStr);
        textY = 0x10;
    }
    infoStr = STRBUF_Create(0x100, wk->heapId);
    wordSet = WORDSET_Create(10, 0x20, wk->heapId);
    if (isEgg == 0) {
        if (metPlace == 0x7531) {
            msgIdAlt = 0x29;
            msgId = 0x2b;
            if (isFatefulEncounter == 1) {
                msgIdAlt = 0x2d;
                msgId = 0x2f;
            }
            switch (encounterType) {
            case 1: case 2: case 3:
                metPlace = 0x7536;
                break;
            case 4: case 5:
                metPlace = 0x7534;
                break;
            case 7: case 8:
                metPlace = 0x7535;
                msgId = msgIdAlt;
                break;
            case 10: case 11: case 12:
                metPlace = 0x7537;
                msgId = msgIdAlt;
                break;
            case 15:
                metPlace = 0x7538;
                break;
            default:
                eggPlace = 0x7539;
                msgId = msgIdAlt;
                break;
            }
        } else if (metPlace >= 0x753a && metPlace <= 0x753d && eventFlags == 1) {
            switch (metPlace - 0x753a) {
            case 0: msgId = 0x31; break;
            case 1: msgId = 0x32; break;
            case 2: msgId = 0x33; break;
            case 3: msgId = 0x34; break;
            }
        } else if (isFatefulEncounter == 0) {
            if (eggPlace == 0) {
                if (metPlace == 0x7532) {
                    msgId = 0x1b;
                } else {
                    msgId = 0x19;
                }
            } else if (eggPlace <= 60000) {
                msgId = 0x1d;
            } else {
                msgId = 0x1f;
            }
        } else {
            msgId = 0x21;
            if (eggPlace != 0) {
                msgId = 0x23;
            }
        }
        if (isOriginalTrainer == 0) {
            if (metPlace < 0x753a || metPlace > 0x753d) {
                msgId++;
            }
        }
    } else if (isFatefulEncounter == 0) {
        if (isOriginalTrainer == 1) {
            msgId = 0x53;
        } else {
            msgId = 0x54;
        }
    } else {
        msgId = 0x55;
        if (isOriginalTrainer != 1) {
            msgId = 0x56;
        }
    }
    eggPlaceStr = P_STA_INFO_GetPlaceName(wk, work, eggPlace);
    metPlaceStr = P_STA_INFO_GetPlaceName(wk, work, metPlace);
    WORDSET_SetSlotNumber(wordSet, 0, metYear, 2, 2, 1);
    bestStat = 0;
    WORDSET_SetSlotNumber(wordSet, 1, metMonth, 2, bestStat, 1);
    WORDSET_SetSlotNumber(wordSet, 2, metDay, 2, bestStat, 1);
    WORDSET_SetSlotNumber(wordSet, 3, metLevel, 3, bestStat, 1);
    WORDSET_SetSlotTag(wordSet, 4, metPlaceStr, 0, 1, 2);
    WORDSET_SetSlotNumber(wordSet, 5, eggYear, 2, 2, 1);
    WORDSET_SetSlotNumber(wordSet, 6, eggMonth, 2, bestStat, 1);
    WORDSET_SetSlotNumber(wordSet, 7, eggDay, 2, bestStat, 1);
    WORDSET_SetSlotTag(wordSet, 8, eggPlaceStr, bestStat, 1, 2);
    msgStr = func_02045EC0(work->msgInfo, msgId);
    WORDSET_CopyTaggedText(wordSet, infoStr, msgStr);
    PRINTSYS_PrintQueColor(wk->printQue, BMP_WIN_GetBmp(work->win[STA_INFO_WIN_MEMO]), (s16)1, (s16)(textY + 1), infoStr, wk->font, 0x440);
    WORDSET_DeleteStrbufED04(wordSet);
    textY += GF_FONT_CountLine(infoStr) << 4;
    STRBUF_Delete(eggPlaceStr);
    STRBUF_Delete(metPlaceStr);
    STRBUF_Delete(msgStr);
    STRBUF_Delete(infoStr);
    if (isEgg == 0) {
        struct StaInfoStatIds statIds;
        struct StaInfoStatRows statRows;
        u8 bestValue;
        u8 i;
        const u8 *row;
        u32 statValue;
        bestValue = bestStat;
        statIds = *(const struct StaInfoStatIds *)d_021DC24C;
        statRows = *(const struct StaInfoStatRows *)d_021DC264;
        i = 0;
        row = statRows.row[(u8)(personalRandom % 6)];
        for (; i < 6; i++) {
            statValue = func_02017E88(mon, statIds.id[row[i]], 0);
            if (bestValue < statValue) {
                bestValue = statValue;
                bestStat = row[i];
            }
        }
        msgStr = func_02045EC0(work->msgInfo, bestStat * 5 + 0x35 + bestValue % 5);
        PRINTSYS_PrintQueColor(wk->printQue, BMP_WIN_GetBmp(work->win[STA_INFO_WIN_MEMO]), (s16)1, (s16)(textY + 1), msgStr, wk->font, 0x440);
        STRBUF_Delete(msgStr);
    } else {
        u32 eggMsgId;
        if (eggSteps <= 5) {
            eggMsgId = 0x57;
        } else if (eggSteps <= 10) {
            eggMsgId = 0x58;
        } else if (eggSteps <= 40) {
            eggMsgId = 0x59;
        } else {
            eggMsgId = 0x5a;
        }
        msgStr = func_02045EC0(work->msgInfo, eggMsgId);
        PRINTSYS_PrintQueColor(wk->printQue, BMP_WIN_GetBmp(work->win[STA_INFO_WIN_MEMO]), (s16)1, (s16)(textY + 1), msgStr, wk->font, 0x440);
        STRBUF_Delete(msgStr);
    }
}

void *P_STA_INFO_GetPlaceName(PStatusWork *wk, PStaInfoWork *work, unsigned int placeId)
{
    unsigned int bank = EVENT_ID_GetBank(placeId);
    unsigned int index = EVENT_ID_GetIndex(placeId);
    switch (bank) {
    case 89: return func_02045EC0(work->msgPlaceBank89, index);
    case 92: return func_02045EC0(work->msgPlaceBank92, index);
    case 90: return func_02045EC0(work->msgPlaceBank90, index);
    case 91: return func_02045EC0(work->msgPlaceBank91, index);
    default: return func_02045EC0(work->msgPlaceBank89, 0);
    }
}
