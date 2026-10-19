/*
 * file:     worldtrade_adapter.c
 * unit:     yes
 * function: WORLDTRADE_ADAPTER_RemovePartyMon, WORLDTRADE_ADAPTER_RegisterReceivedMon, WORLDTRADE_ADAPTER_RegisterReceivedMonB, WORLDTRADE_ADAPTER_GetDateTime, WORLDTRADE_ADAPTER_RegisterLanguageVersion, WORLDTRADE_ADAPTER_CheckPartyHasOther, WORLDTRADE_ADAPTER_SetPair, WORLDTRADE_ADAPTER_CanProceed, WORLDTRADE_ADAPTER_CreateMail, WORLDTRADE_ADAPTER_CreateMonFromBox, WORLDTRADE_ADAPTER_AllocHeapBuf, WORLDTRADE_ADAPTER_CopyMon, WORLDTRADE_ADAPTER_ClearWindowScreen, WORLDTRADE_ADAPTER_CreateString, WORLDTRADE_ADAPTER_CopyBoxMon, WORLDTRADE_ADAPTER_GetBoxParam, WORLDTRADE_ADAPTER_StrObjThunk, WORLDTRADE_ADAPTER_InitPrinter, WORLDTRADE_ADAPTER_ExitPrinter, WORLDTRADE_ADAPTER_UpdatePrinter, WORLDTRADE_ADAPTER_IsStreamDone, WORLDTRADE_ADAPTER_QueuePrintDefaultColor, WORLDTRADE_ADAPTER_StartPrintStream, WORLDTRADE_ADAPTER_PrintQueColor, WORLDTRADE_ADAPTER_DeletePrintStream, WORLDTRADE_ADAPTER_InitMessageSystem, WORLDTRADE_ADAPTER_ExitMessageSystem, WORLDTRADE_ADAPTER_UpdateMessageSystem, WORLDTRADE_ADAPTER_PrintNumber, WORLDTRADE_ADAPTER_QueueMessagePrint
 * address:  0x022021F8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   WORLDTRADE_ADAPTER_InitPrinter  0x022026D8  thumb
 *   WORLDTRADE_ADAPTER_UpdatePrinter 0x02202770 thumb ov135
 *   MSGDATA_Delete 0x02045C04 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WORLDTRADE_ADAPTER_ExitPrinter 0x02202744 thumb ov135
 *   SAVEDATA_PanicFail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   STRBUF_Create 0x020457B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WORLDTRADE_ADAPTER_CreateMonFromBox  0x022025E4  thumb
 *   WORLDTRADE_ADAPTER_IsStreamDone  0x02202840  thumb  ov135
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   FILE_UTIL_Check136C  0x0202136C  thumb
 *   BOX_SAVEDATA_GetPokemon  0x02007A18  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   WORLDTRADE_ADAPTER_CopyMon  0x0220262C  thumb
 *   BOX_SAVEDATA_ClearPokemon  0x02007664  thumb
 *   BOX_SAVEDATA_FindFreeSlot  0x020076D0  thumb
 *   BOX_SAVEDATA_AddPokemonToBox  0x0200752C  thumb
 *   WORLDTRADE_ADAPTER_ClearWindowScreen 0x02202644 thumb ov135
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   WORLDTRADE_ADAPTER_CopyBoxMon  0x022026A0  thumb
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   WORLDTRADE_ADAPTER_StartPrintStream 0x02202878 thumb ov135
 *   WORLDTRADE_ADAPTER_StrObjThunk 0x022026C4 thumb ov135
 *   WORLDTRADE_ADAPTER_InitMessageSystem  0x02202974  thumb
 *   WORLDTRADE_ADAPTER_ExitMessageSystem  0x022029D4  thumb  ov135
 *   WORLDTRADE_ADAPTER_UpdateMessageSystem  0x022029F8  thumb
 *   WORLDTRADE_ADAPTER_QueueMessagePrint  0x02202B20  thumb
 *   WORLDTRADE_BOX_IsSpeciesFlagged 0x021F6DE8 thumb ov135
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BMP_WIN_ClearScreen   0x020456F8  arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORLDTRADE_GetIsDeposited  0x0200AD8C  thumb
 *   WORDSET_SetSlotMonSpecies  0x0201EEF4  thumb
 *   WORLDTRADE_SetIsDeposited  0x0200AD94  thumb
 *   WORLDTRADE_SetPokemon 0x0200ADB8 thumb
 *   POKEPARTY_RemoveMember 0x0201A9C8 thumb
 *   GAME_DATA_GetBoxSave 0x02012F98 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   PERAPVOICE_ClearIfNoChatot 0x02007C34 thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_CalcGender  0x02017F50  thumb
 *   DWC_GetDateTime  0x02167ED8  arm  ov009
 *   WORLDTRADE_SetLastSearchId  0x0200ADD8  thumb
 *   WORLDTRADE_SetLastTradeId  0x0200ADD0  thumb
 *   WIFI_HISTORY_GetCountryRegionState 0x0200949C thumb
 *   WIFI_HISTORY_SetCountryRegionState 0x020094D8 thumb
 *   POKE_TOOL_SetDefaultName  0x02019B58  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   MAIL_SetWriterName  0x02008F88  thumb
 *   g_02203F5C  0x02203F5C  data  ov135
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   TCBL_Main  0x020310C4  arm  arm9
 *   TCBL_Destroy  0x02031140  arm  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb  arm9
 */
#include "worldtrade_types.h"

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 GFL_HEAP_Free(void *p);

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 KEY_GetTrg(void);

extern u32 POKEPARTY_GetCount(void *p);

extern int TOUCHPANEL_GetTrg(void);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);


extern u32 FILE_UTIL_Check136C(u16 v);

extern struct Sub020079BCEntry *BOX_SAVEDATA_GetPokemon(void **save, u32 box, u32 slot);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);

extern int BOX_SAVEDATA_FindFreeSlot(void *save, int *pbox, int *pslot);

extern int BOX_SAVEDATA_AddPokemonToBox(void **save, u32 box, const struct Sub02007454Entry *src);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern void BG_SYS_PushTile(u32 layer);

struct PerapVoice;

struct Sub02007AC8Entry;

struct Sub02008F80Obj;

struct Mon;

struct StrObj;

struct GfFont;

struct Tcbl;

struct PrintSys;

struct S02031140;

struct Rec3;

typedef struct {
    int year;
    int month;
    int day;
    int week;
} RTCDate;

typedef struct {
    int hour;
    int minute;
    int second;
} RTCTime;

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern int WORLDTRADE_BOX_IsSpeciesFlagged(unsigned int handle);



extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

extern void *POKE_TOOL_GetBoxParam(void *mon);

extern void BG_SYS_SetFlagField06(u32 v);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);


extern void MI_CpuCopy8(const void *src, void *dst, u32 n);

extern u16 *STRBUF_GetChars(struct U16Vec *);

struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);

extern u16 WORLDTRADE_GetIsDeposited(const struct Rec0200AD8C *p);

extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);

extern void WORLDTRADE_SetIsDeposited(struct Rec0200AD94 *p, u16 v);

extern void WORLDTRADE_SetPokemon(void *dest, const void *src, u32 boxPos);

extern void BOX_SAVEDATA_ClearPokemon(void *, unsigned, unsigned);

extern void *POKEPARTY_GetMember(void *, unsigned);

extern u32 POKEPARTY_RemoveMember(struct Party *p, s32 idx);

extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);

extern void *GAME_DATA_GetMyParty(const struct BigObj *p);

extern void PERAPVOICE_ClearIfNoChatot(struct PerapVoice *p, void *a);

extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);

extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);

extern u8 POKE_TOOL_CalcGender(u32 species, u16 form, u32 pid);

extern int DWC_GetDateTime(RTCDate *date, RTCTime *time);

extern void WORLDTRADE_SetLastSearchId(struct RegB *p, u32 value);

extern void WORLDTRADE_SetLastTradeId(struct RegB *p, u32 value);

extern u32 WIFI_HISTORY_GetCountryRegionState(const struct Sub02009470Obj *obj, int row, int col);

extern void WIFI_HISTORY_SetCountryRegionState(struct Sub02009470Obj *obj, int row, int col, int value);

extern void POKE_TOOL_SetDefaultName(void *mon);

extern void *MAIL_Create(int heapId);

extern void MAIL_SetWriterName(struct Sub02008F80Obj *obj, const void *src);

extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);

extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);

extern u32 PRINTSYS_QUE_Create(void *p);

extern void *APP_KEYCURSOR_CreateDefault(u32 id, u32 isLive, u32 isFlip, u32 heap);

extern int APP_KEYCURSOR_Delete(void *cursor);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void TCBL_Destroy(struct S02031140 *p);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void APP_KEYCURSOR_Update(Printer *ctx, void *p, void *cell);

extern u32 PRINTSYS_PrintStreamGetState(void *p);

extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);

extern void PRINTSYS_PrintStreamReleasePause(void *menu);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void TCBL_Main(struct Tcbl *p);

extern signed char MSG_SPEED_GetWait(void);

extern void *PRINTSYS_PrintStream(void *, s16, s16, unsigned, unsigned, int, unsigned, unsigned, unsigned, unsigned);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

void WORLDTRADE_ADAPTER_RemovePartyMon(Work *p, int flag);

void WORLDTRADE_ADAPTER_RegisterReceivedMon(Work *p, void *mon, u32 box, int hatch);

void WORLDTRADE_ADAPTER_RegisterReceivedMonB(Work *p,void *mon,void *unused2,void *unused3,u32 index);

void WORLDTRADE_ADAPTER_GetDateTime(void *p, int which);

void WORLDTRADE_ADAPTER_RegisterLanguageVersion(void *obj,Entry *p);

int WORLDTRADE_ADAPTER_CheckPartyHasOther(Work *p, void *mon);

void WORLDTRADE_ADAPTER_SetPair(Work *p, u16 a, u16 b);

u32 WORLDTRADE_ADAPTER_CanProceed(Work *p);

void WORLDTRADE_ADAPTER_CreateMail(void *mon, u32 heap);

void WORLDTRADE_ADAPTER_CreateMonFromBox(u32 a, u32 b, u32 c);

void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);

void WORLDTRADE_ADAPTER_CopyMon(u32 a, u32 b);

void WORLDTRADE_ADAPTER_ClearWindowScreen(u32 a, int kind);

u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d);

void WORLDTRADE_ADAPTER_CopyBoxMon(u8 *p, u32 k);

u32 WORLDTRADE_ADAPTER_GetBoxParam(void *mon);

int WORLDTRADE_ADAPTER_StrObjThunk(u32 *p, u32 b, u32 a, u32 c);

void WORLDTRADE_ADAPTER_InitPrinter(Printer *ctx, u32 arg);

void WORLDTRADE_ADAPTER_ExitPrinter(Printer *p);

void WORLDTRADE_ADAPTER_UpdatePrinter(Printer *p);

u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p);

u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p,u8 b,void *s,u32 x,u32 y,void *out);

void WORLDTRADE_ADAPTER_StartPrintStream(void *a, unsigned b, unsigned c, int d, int e, PrintStreamCtx *p);

u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u8 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Printer *g);

void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);

MsgSys *WORLDTRADE_ADAPTER_InitMessageSystem(u32 a, u32 b, u32 c, u32 heap);

void WORLDTRADE_ADAPTER_ExitMessageSystem(MsgSys *p);

void WORLDTRADE_ADAPTER_UpdateMessageSystem(MsgSys *q);

void WORLDTRADE_ADAPTER_PrintNumber(MsgSys *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);

extern const char g_02203F5C[];

/*
 * tail: 022022B6..022022B8 zero alignment padding.
 */
void WORLDTRADE_ADAPTER_RemovePartyMon(Work *p, int flag)
{
    void *mon;
    void *save;
    void *box;
    if (p->box != 0xFF) {
        mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
        WORLDTRADE_ADAPTER_CopyBoxMon((u8 *)BOX_SAVEDATA_GetPokemon(p->ctx->save, p->box, p->slot), (u32)mon);
        if (flag) WORLDTRADE_SetPokemon(p->ctx->sys, mon, p->box);
        BOX_SAVEDATA_ClearPokemon(p->ctx->save, p->box, p->slot);
        GFL_HEAP_Free(mon);
    } else {
        mon = POKEPARTY_GetMember(p->ctx->party, p->slot);
        if (flag) WORLDTRADE_SetPokemon(p->ctx->sys, mon, p->box);
        POKEPARTY_RemoveMember(p->ctx->party, p->slot);
        save = GAMESYSTEM_GetGameData((const struct Ctx *)p->ctx->gameData);
        box = GAME_DATA_GetBoxSave(save);
        PERAPVOICE_ClearIfNoChatot(box, GAME_DATA_GetMyParty(save));
    }
    if (flag) WORLDTRADE_SetIsDeposited(p->ctx->sys, 1);
}

void WORLDTRADE_ADAPTER_RegisterReceivedMon(Work *p, void *mon, u32 box, int hatch)
{
    u32 pos;
    u32 species;
    u32 form;
    u32 slot;

    POKE_TOOL_GetPartyValue(mon, 6, 0);
    ZUKAN_SAVE_RegisterCaught(p->ctx->dex, mon);
    box = 0xFF;
    if (POKEPARTY_GetCount(p->ctx->party) == 6) {
        box = 0;
    }
    if (hatch != 0) {
        POKE_TOOL_SetPartyValue(mon, 9, 0x46);
        species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
        POKE_TOOL_SetPartyValue(mon, 0x6E, POKE_TOOL_CalcGender((u16)species, form, POKE_TOOL_GetPartyValue(mon, 0, 0)));
        WORLDTRADE_ADAPTER_GetDateTime(p->ctx->sys, 0);
    }
    if (box == 0xFF) {
        POKEPARTY_Add(p->ctx->party, mon);
        slot = POKEPARTY_GetCount(p->ctx->party);
        p->box_u = 0xFF;
        slot -= 1;
    } else {
        pos = 0;
        BOX_SAVEDATA_FindFreeSlot((void *)p->ctx->box, (int *)(&box), (int *)(&pos));
        BOX_SAVEDATA_AddPokemonToBox((void **)p->ctx->box, box, (const struct Sub02007454Entry *)WORLDTRADE_ADAPTER_GetBoxParam(mon));
        p->box_u = box;
        slot = pos;
    }
    p->pos = slot;
    WORLDTRADE_SetIsDeposited(p->ctx->sys, 0);
}

/*
 * evidence: ZUKAN_SAVE_RegisterCaught receives the entry r1 Pokemon pointer; fifth parameter is reassigned in its incoming stack slot.
 */
void WORLDTRADE_ADAPTER_RegisterReceivedMonB(Work *p,void *mon,void *unused2,void *unused3,u32 index)
{
    u32 species, form, pos;
    ZUKAN_SAVE_RegisterCaught(p->ctx->dex,mon);
    index=0xFF;
    if(POKEPARTY_GetCount(p->ctx->party)==6) index=0;
    POKE_TOOL_SetPartyValue(mon,9,0x46);
    species=POKE_TOOL_GetPartyValue(mon,5,0);
    form=POKE_TOOL_GetPartyValue(mon,0x6F,0);
    POKE_TOOL_SetPartyValue(mon,0x6E,POKE_TOOL_CalcGender((u16)species,form,POKE_TOOL_GetPartyValue(mon,0,0)));
    if(index==0xFF) {
        POKEPARTY_Add(p->ctx->party,(const struct PartyMon *)mon);
        pos=POKEPARTY_GetCount(p->ctx->party);
        p->box_u=0xFF;
        pos--;
    } else {
        u32 slot=0;
        BOX_SAVEDATA_FindFreeSlot(p->ctx->save,(int *)(&index),(int *)(&slot));
        BOX_SAVEDATA_AddPokemonToBox(p->ctx->save,index,(const struct Sub02007454Entry *)WORLDTRADE_ADAPTER_GetBoxParam(mon));
        p->box_u=index;
        pos=slot;
    }
    p->pos=pos;
    WORLDTRADE_ADAPTER_GetDateTime(p->ctx->sys,1);
}

void WORLDTRADE_ADAPTER_GetDateTime(void *p, int which)
{
    RTCDate date;
    RTCTime time;
    u32 v;

    DWC_GetDateTime(&date, &time);
    v = ((u32)date.year << 24) | (((u32)date.month << 24) >> 8) | (((u32)date.day << 24) >> 16) | date.week;
    if (which == 1) {
        WORLDTRADE_SetLastSearchId(p, v);
    } else {
        WORLDTRADE_SetLastTradeId(p, v);
    }
}

void WORLDTRADE_ADAPTER_RegisterLanguageVersion(void *obj,Entry *p) { int b=p->ver,a=p->lang; if(WIFI_HISTORY_GetCountryRegionState(obj,a,b)==0) WIFI_HISTORY_SetCountryRegionState(obj,a,b,1); }

int WORLDTRADE_ADAPTER_CheckPartyHasOther(Work *p, void *mon)
{
    if (WORLDTRADE_BOX_IsSpeciesFlagged((u32)mon) != 0 && POKEPARTY_GetCount(p->ctx->party) == 6) {
        return 2;
    }
    if (p->species == 0x2D0 && POKEPARTY_GetCount(p->ctx->party) == 6) {
        return 1;
    }
    return 0;
}

/*
 * Store a pair of u16 values at +0xe0c and +0xe0e.
 */
void WORLDTRADE_ADAPTER_SetPair(Work *p, u16 stateAfterSaveWait, u16 stateAfterSave)
{
    p->stateAfterSaveWait = stateAfterSaveWait;
    p->stateAfterSave = stateAfterSave;
}

/*
 * 1 only when the query is clear and the u16 at +0x32 is set.
 */
u32 WORLDTRADE_ADAPTER_CanProceed(Work *p)
{
    if (WORLDTRADE_GetIsDeposited((const struct Rec0200AD8C *)p->ctx->sys) == 0) {
        if (p->busy != 0) {
            return 1;
        }
    }
    return 0;
}

void WORLDTRADE_ADAPTER_CreateMail(void *mon, u32 heap)
{
    void *bank;
    void *str;
    void *buf;
    u32 id;

    id = (heap & 0x7FFF) | 0x8000;
    bank = MSGDATA_CreateFromArchive(0, 2, 0x51, (u16)id);
    str = MSGDATA_AllocString(bank, 0xF);
    MSGDATA_Delete(bank);
    POKE_TOOL_SetDefaultName(mon);
    POKE_TOOL_SetPartyValue(mon, 0x8E, (u32)STRBUF_GetChars(str));
    if (FILE_UTIL_Check136C((u16)POKE_TOOL_GetPartyValue(mon, 6, 0)) != 0) {
        buf = MAIL_Create((u16)id);
        POKE_TOOL_GetPartyValue(mon, 0xA7, (u32)buf);
        MAIL_SetWriterName(buf, STRBUF_GetChars(str));
        POKE_TOOL_SetPartyValue(mon, 0xA7, (u32)buf);
        GFL_HEAP_Free(buf);
    }
    STRBUF_Delete(str);
}

/*
 * Allocate a 0x48-byte block and hand it to the writer, then free the block.
 */
void WORLDTRADE_ADAPTER_CreateMonFromBox(u32 wordSet, u32 slot, u32 boxMon)
{
    void *blk = POKE_TOOL_CreateFromBoxParam((void *)boxMon, 0x48);

    WORDSET_SetSlotMonSpecies((void *)wordSet, slot, blk);
    GFL_HEAP_Free(blk);
}

/*
 * Create the table entry and register the 0x47 callback against it.
 */
void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap)
{
    return GFL_HEAP_Alloc(heap, POKE_TOOL_GetPartyParamSize(), 0, g_02203F5C, 0x47);
}

/*
 * Hand the size guess back to the main writer with the caller's handle.
 */
void WORLDTRADE_ADAPTER_CopyMon(u32 src, u32 dst)
{
    MI_CpuCopy8((const void *)src, (void *)dst, POKE_TOOL_GetPartyParamSize());
}

/*
 * switch on kind
 */
void WORLDTRADE_ADAPTER_ClearWindowScreen(u32 win, int kind)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    switch (kind) {
    case 0:
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)win));
        break;
    case 1:
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)win));
        break;
    }
}

/*
 * Encode one record through the two stage helpers and flush it to the writer.
 */
u32 WORLDTRADE_ADAPTER_CreateString(u32 wordSet, u32 bank, u32 msgId, u32 heapId)
{
    u32 t1 = (u32)MSGDATA_AllocString((struct MsgBank *)bank, msgId);
    u32 t2 = (u32)STRBUF_Create(0x200, heapId);

    WORDSET_CopyTaggedText((struct WordSet *)wordSet, (void *)t2, (void *)t1);
    STRBUF_Delete((struct U16Vec *)t1);
    return t2;
}

/*
 * Create the 0x48 sub-object, register the handle and hand it to the callback.
 */
void WORLDTRADE_ADAPTER_CopyBoxMon(u8 *p, u32 dst)
{
    u32 h = (u32)POKE_TOOL_CreateFromBoxParam((struct Mon *)p, 0x48);

    WORLDTRADE_ADAPTER_CopyMon(h, dst);
    GFL_HEAP_Free((void *)h);
}

/*
 * Tail-call thunk to the thumb routine at 0x020185F4.
 */
u32 WORLDTRADE_ADAPTER_GetBoxParam(void *mon)
{
    return (u32)POKE_TOOL_GetBoxParam(mon);
}

/*
 * Tail call: the third argument goes first, the dereferenced pointer second, the u16 last.
 */
int WORLDTRADE_ADAPTER_StrObjThunk(u32 *p, u32 unused1, u32 str, u32 margin)
{
    return GF_FONT_MeasureWidestLine((struct StrObj *)str, *p, (u16)margin);
}

void WORLDTRADE_ADAPTER_InitPrinter(Printer *ctx, u32 arg)
{
    int i;
    PrinterSlot *s;

    MI_CpuFill8(ctx, 0, 0x13C);
    ctx->tcb = TCBL_Create(0x48, 0x48, 0x20, 0x20);
    ctx->arg = arg;
    ctx->font = GF_FONT_Create(0x17, 0, 0, 0, 0x48);
    ctx->queue = (void *)PRINTSYS_QUE_Create((void *)0x48);
    ctx->cursor = APP_KEYCURSOR_CreateDefault(0xF, 1, 1, 0x48);
    for (i = 0; i < 0x18; i++) {
        s = &ctx->slots[i];
        MI_CpuFill8(s, 0, 8);
        s->used = 0;
    }
}

/*
 * Free every buffer the object owns and blank the 0x13c-byte tail.
 */
void WORLDTRADE_ADAPTER_ExitPrinter(Printer *p)
{
    APP_KEYCURSOR_Delete(p->cursor);
    PRINTSYS_QUE_Delete((struct PrintSys *)p->queue);
    GF_FONT_Delete(p->font);
    TCBL_Destroy((struct S02031140 *)p->tcb);
    MI_CpuFill8(p, 0, 0x13c);
}

void WORLDTRADE_ADAPTER_UpdatePrinter(Printer *p)
{
    int i;
    PrinterSlot *e;
    void *queue;

    for (i = 0; i < 24; i++) {
        e = &p->slots[i];
        if (e->used != 0) {
            queue = p->queue;
            if (e->busy != 0 && PRINTSYS_QUE_IsExistTarget(queue, BMP_WIN_GetBmp(e->win)) == 0) {
                BMP_WIN_TransferChars(e->win);
                e->busy = 0;
            }
            if (e->busy == 0) {
                e->used = 0;
            }
        }
    }
    if (p->yesno != 0) {
        APP_KEYCURSOR_Update((Printer *)p->cursor, p->yesno, p->yesnoArg);
        switch (PRINTSYS_PrintStreamGetState(p->yesno)) {
        case 0:
            if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamShortWait(p->yesno, 0);
            }
            break;
        case 1:
            if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(p->yesno);
            }
            break;
        case 2:
            PRINTSYS_PrintStreamDelete(p->yesno);
            p->yesno = 0;
            p->yesnoArg = 0;
            break;
        }
    }
    PRINTSYS_QUE_Main(p->queue);
    TCBL_Main(p->tcb);
}

/*
 * Non-zero unless the +0x10 handle is absent or the query answers 2.
 */
u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p)
{
    u32 r;
    u32 x;

    r = 0;
    x = (u32)p->stream;
    if (x != 0 && PRINTSYS_PrintStreamGetState((void *)x) != 2) {
        r = 1;
    }
    return r;
}

u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *win,u8 unused1,void *str,u32 x,u32 y,void *printer) { return WORLDTRADE_ADAPTER_PrintQueColor(win, unused1, (u32)str, x, y, 0, 0x44f, (Printer *)printer); }

/*
 * tail: 022028C6..022028C8 zero alignment padding.
 */
void WORLDTRADE_ADAPTER_StartPrintStream(void *win, unsigned unused1, unsigned str, int x, int y, PrintStreamCtx *p)
{
    int v;
    if (p->stream) {
        PRINTSYS_PrintStreamDelete(p->stream);
        p->stream = 0;
    }
    v = MSG_SPEED_GetWait();
    p->stream = PRINTSYS_PrintStream(win, x, y, str, p->font, v, p->msgData, 0, 0x48, 0xF);
    p->streamWin = win;
}

u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u8 unused1, u32 str, u32 x, u32 y, u32 unused2, u16 color, Printer *printer)
{
    PrinterSlot *found = 0;
    int i;
    u32 print;

    for (i = 0; i < 24; i++) {
        if (printer->slots[i].used == 0) {
            found = &printer->slots[i];
        }
    }
    if (found == 0) {
        SAVEDATA_PanicFail((void *)0x02203F74, 0, (void *)0x02203F74);
    }
    found->win = win;
    found->busy = 0;
    print = (u32)printer->queue;
    PRINTSYS_PrintQueColor((void *)print, (u32)BMP_WIN_GetBmp((struct Descriptor *)win), (s16)x, (s16)y, str, (u32)printer->font, color);
    found->busy = 1;
    found->used = 1;
    return 1;
}

/*
 * note: 2026-10-05 P22L9: array base reached through a static inline accessor p->e (the bare field, a local pointer and u32 arithmetic all kept the base in r1, DIFF16/13). The zero stored is the counter's initial copy (idiom a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero).
 */
void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p) {
    int i;
    for (i = 0; i < 24; i++) {
        PrinterSlot *e = p->e + i;
        if (e->used != 0) e->used = 0;
    }
    if (p->h != 0) {
        PRINTSYS_PrintStreamDelete(p->h);
        p->h = 0;
        p->n = 0;
    }
}

MsgSys *WORLDTRADE_ADAPTER_InitMessageSystem(u32 unused1, u32 unused2, u32 unused3, u32 heap)
{
    MsgSys *ctx;

    ctx = GFL_HEAP_Alloc(heap, 0x74, 0, (const char *)g_02203F5C, 0x1DD);
    MI_CpuFill8(ctx, 0, 0x74);
    ctx->heap = heap;
    ctx->font = GF_FONT_Create(0x17, 3, 0, 0, heap);
    ctx->queue = (void *)PRINTSYS_QUE_Create((void *)heap);
    ctx->bank = MSGDATA_CreateFromArchive(0, 2, 0xD0, heap);
    ctx->words = WORDSET_CreateDefault(heap);
    return ctx;
}

/*
 * Release every buffer the object owns, then the object itself.
 */
void WORLDTRADE_ADAPTER_ExitMessageSystem(MsgSys *p)
{
    WORDSET_DeleteStrbufED04((struct WordSet *)p->words);
    MSGDATA_Delete((struct Rec *)p->bank);
    PRINTSYS_QUE_Delete((struct PrintSys *)p->queue);
    GF_FONT_Delete(p->font);
    GFL_HEAP_Free(p);
}

void WORLDTRADE_ADAPTER_UpdateMessageSystem(MsgSys *msgSys)
{
    int i;
    void *queue;

    for (i = 0; i < 8; i++) {
        if (msgSys->used[i] != 0) {
            queue = msgSys->queue;
            if (msgSys->slots[i].busy != 0 && PRINTSYS_QUE_IsExistTarget(queue, BMP_WIN_GetBmp(msgSys->slots[i].win)) == 0) {
                BMP_WIN_TransferChars(msgSys->slots[i].win);
                msgSys->slots[i].busy = 0;
            }
            if (msgSys->slots[i].busy == 0) {
                msgSys->used[i] = 0;
            }
        }
    }
    PRINTSYS_QUE_Main(msgSys->queue);
}

void WORLDTRADE_ADAPTER_PrintNumber(MsgSys *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y)
{
    void *str;
    void *fmt;
    void *print;
    int i;

    str = STRBUF_Create(0x20, ctx->heap);
    fmt = STRBUF_Create(0x20, ctx->heap);
    MSGDATA_ReadString(ctx->bank, 0xFD, fmt);
    WORDSET_SetSlotNumber(ctx->words, 0, num, digits, mode, 1);
    WORDSET_CopyTaggedText(ctx->words, str, fmt);
    for (i = 0; i < 8; i++) {
        if (ctx->used[i] == 0) {
            ctx->slots[i].win = win;
            ctx->slots[i].busy = 0;
            print = ctx->queue;
            PRINTSYS_PrintQueColor(print, (u32)BMP_WIN_GetBmp(ctx->slots[i].win), (s16)x, (s16)y, (u32)str, (u32)ctx->font, 0x3DC8);
            ctx->slots[i].busy = 1;
            ctx->used[i] = 1;
            STRBUF_Delete(fmt);
            STRBUF_Delete(str);
            return;
        }
    }
    SAVEDATA_PanicFail((void *)0x02203F74, 0, (void *)0x02203F74);
}

#pragma thumb on

void WORLDTRADE_ADAPTER_QueueMessagePrint(MsgSys *p, int unusedArg, void *win, int x, int y)
{
    void *buf = MSGDATA_AllocString(p->bank, 0xfe);
    int i;

    for (i = 0; i < 8; i++) {
        if (p->used[i] == 0) {
            void *owner;
            void *h;

            p->slots[i].win = win;
            p->slots[i].busy = 0;
            owner = p->queue;
            h = BMP_WIN_GetBmp(p->slots[i].win);
            PRINTSYS_PrintQueColor(owner, (u32)h, (s16)x, (s16)y, (u32)buf, (u32)p->font, (int)0x3DC8);
            p->slots[i].busy = 1;
            p->used[i] = 1;
            STRBUF_Delete(buf);
            return;
        }
    }
    SAVEDATA_PanicFail((void *)0x02203F74, 0, (void *)0x02203F74);
}
