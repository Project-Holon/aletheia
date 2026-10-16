/*
 * file:     br_pokesearch.c
 * unit:     yes
 * function: BR_POKESEARCH_Create, BR_POKESEARCH_Destroy, BR_POKESEARCH_Main, BR_POKESEARCH_UpdatePrint, BR_POKESEARCH_Open, BR_POKESEARCH_Close, BR_POKESEARCH_GetResult, BR_POKESEARCH_CreateBackButton, BR_POKESEARCH_DestroyBackButton, BR_POKESEARCH_CreateGroupWindows, BR_POKESEARCH_DestroyGroupWindows, BR_POKESEARCH_CreateSpeciesList, BR_POKESEARCH_DestroySpeciesList, BR_POKESEARCH_PollGroupTouch, BR_POKESEARCH_HasSeenInGroup, BR_POKESEARCH_BuildSeenList
 * address:  0x021FFBD4
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_pokesearch.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   SAVEDATA_PanicFail 0x02034714 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02045CAC 0x02045CAC arm
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_MEMBER_COUNT_GetU16Count 0x02200228 thumb ov186
 *   gBrPokeSearchSourceFile 0x02200D9C data a1
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuHitId 0x021FCDA8 thumb ov186
 *   BR_UTIL_IsEffectDone 0x021FD938 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   gBrPokeSearchAssertString 0x02200DAC data
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BR_UTIL_CreateListMenu 0x021FC8C8 thumb ov186
 *   gSpeciesNameBank 0x020A7370 data
 *   gBrPokeSearchListConfig 0x02200CA8 data
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   gBrPokeSearchHitTable 0x02200CD0 data a1
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   gBrPokeSearchGroupStart 0x02200C94 data a4
 */
#include "br_types.h"

struct StrBuf;

extern void BR_RES_LoadBgGraphics(struct BrRes *res, unsigned kind, unsigned short heapId);

extern void BR_RES_ApplyBgSet(struct BrRes *res, unsigned kind);

extern void STRBUF_Delete(struct StrBuf *str);

extern u32 TOUCHPANEL_GetPointTrg(int *outX, int *outY);

extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void BG_SYS_PushTile(u32 index);

extern void * MI_CpuFill8(void *,u32,u32);

extern void func_02045CAC(struct MsgBank *bank, u32 index, struct StrBuf *dest);

extern int BR_RES_GetSprite(struct BrRes *res, int spriteIndex, struct BrResSprite *outSprite);

extern unsigned BR_RES_GetFont(struct BrRes *res);

extern int TOUCHPANEL_HitTrg(const void *hitTable);

extern int BR_RES_GetMsgData(struct BrRes *res);

extern void *GFL_HEAP_Alloc(unsigned int,unsigned int,int,const char *,u16);

extern u32 GFL_HEAP_Free(void *p);

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);

extern struct PrintSys *PRINTSYS_QUE_Create(u32 heapId);

extern u16 *BR_MEMBER_COUNT_GetU16Count(unsigned short heapId, unsigned *count);

extern void PRINTSYS_QUE_Delete(struct PrintSys *);

extern int BR_BTN_HitTestWithSound(struct BrButton *button, int x, int y);

extern void BR_UTIL_StartEffect(struct BrTapFx *tapFx, u32 mode, const struct BrPoint *point);

extern void BR_UTIL_MainListMenu(struct BrListMenu *menu);

extern int BR_UTIL_GetListMenuHitId(struct BrListMenu *menu);

extern int BR_UTIL_IsEffectDone(struct BrTapFx *tapFx);

extern void BR_FADE_Start(struct BrFade *fade, int stepIndex, int planeMask, int direction);

extern int BR_FADE_GetResult(struct BrFade *fade);

extern int BR_UTIL_FlushText(struct BrTextWin *win);

extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);

extern struct BrButton *BR_BTN_CreateFromMessage(const struct BrActorPos *pos, int file, int width, int param, int uiParamA, int uiParamB, int font, int msgData, struct BrResSprite *sprite, unsigned short heapId);

extern void BR_BTN_DeleteObject(struct BrButton *button);

extern struct BrTextWin *BR_UTIL_Create(unsigned short plane, unsigned x, unsigned short y, unsigned short width, unsigned char height, unsigned char palette, struct PrintSys *printQue, unsigned short heapId);

extern void BR_UTIL_SetTextLayout(struct BrTextWin *win, u32 a, u32 b, u32 c);

extern void BR_UTIL_SetTextFromMessage(struct BrTextWin *win, int msgData, int msgId, int font, unsigned short color);

extern void BR_UTIL_Delete(struct BrTextWin *win);

extern struct BrMenuItem *BMP_MENUWORK_Create(u32 count, u32 heapId);

extern void BMP_MENUWORK_AddStrItem(struct BrMenuItem *item, struct StrBuf *str, u32 value, u32 heapId);

extern struct BrListMenu *BR_UTIL_CreateListMenu(struct BrListMenuConfig *config, u32 heapId);

extern void BR_UTIL_DeleteListMenu(struct BrListMenu *menu);

extern u32 BMP_MENUWORK_Delete(struct BrMenuItem *items);

extern u32 ZUKAN_SAVE_IsSeen(struct ZukanSave *zukan, u16 speciesId);

struct BrPokeSearch *BR_POKESEARCH_Create(struct ZukanSave *zukan, struct BrRes *res, int uiParamA, int uiParamB, struct BrFade *fade, int listParam, struct BrTapFx *tapFx, unsigned short heapId);

void BR_POKESEARCH_Destroy(struct BrPokeSearch *ps);

int BR_POKESEARCH_Main(struct BrPokeSearch *ps);

unsigned BR_POKESEARCH_UpdatePrint(struct BrPokeSearch *ps);

void BR_POKESEARCH_Open(struct BrPokeSearch *ps);

void BR_POKESEARCH_Close(struct BrPokeSearch *ps);

int BR_POKESEARCH_GetResult(struct BrPokeSearch *ps, unsigned short *speciesOut);

void BR_POKESEARCH_CreateBackButton(struct BrPokeSearch *ps);

void BR_POKESEARCH_DestroyBackButton(struct BrPokeSearch *ps);

void BR_POKESEARCH_CreateGroupWindows(struct BrPokeSearch *ps);

void BR_POKESEARCH_DestroyGroupWindows(struct BrPokeSearch *ps);

void BR_POKESEARCH_CreateSpeciesList(struct BrPokeSearch *ps);

void BR_POKESEARCH_DestroySpeciesList(struct BrPokeSearch *ps);

int BR_POKESEARCH_PollGroupTouch(struct BrPokeSearch *ps);

int BR_POKESEARCH_HasSeenInGroup(struct ZukanSave *zukan, u32 group, const u16 *speciesTable);

u16 *BR_POKESEARCH_BuildSeenList(struct ZukanSave *zukan, u32 group, const u16 *speciesTable, u32 *countOut, u16 heapId);

extern const char gBrPokeSearchSourceFile[];
extern char gBrPokeSearchAssertString[];
extern struct MsgBank *gSpeciesNameBank;
extern const struct BrListMenuConfig gBrPokeSearchListConfig;
extern const char gBrPokeSearchHitTable[];
extern const u16 gBrPokeSearchGroupStart[];

typedef char BrPokeSearchCheckSize[sizeof(struct BrPokeSearch) == 0x90 ? 1 : -1];
typedef char BrListMenuConfigCheckSize[sizeof(struct BrListMenuConfig) == 40 ? 1 : -1];

/* Phases of the screen state machine. */
enum {
    BR_POKESEARCH_PHASE_INIT = 0,
    BR_POKESEARCH_PHASE_ARM = 1,
    BR_POKESEARCH_PHASE_GROUPS = 2,       /* waits for a touch on a group or the back button */
    BR_POKESEARCH_PHASE_LIST = 3,         /* waits for a list choice or the back button */
    BR_POKESEARCH_PHASE_TAP_WAIT = 4,
    BR_POKESEARCH_PHASE_FADE_OUT_WAIT = 5,
    BR_POKESEARCH_PHASE_SWITCH = 6,       /* builds the next screen, starts the fade in */
    BR_POKESEARCH_PHASE_FADE_IN_WAIT = 7,
    BR_POKESEARCH_PHASE_EXIT_DELAY1 = 8,
    BR_POKESEARCH_PHASE_EXIT_DELAY2 = 9,
    BR_POKESEARCH_PHASE_DONE = 10
};

struct BrPokeSearch *BR_POKESEARCH_Create(struct ZukanSave *zukan, struct BrRes *res, int uiParamA, int uiParamB, struct BrFade *fade, int listParam, struct BrTapFx *tapFx, unsigned short heapId)
{
    struct BrPokeSearch *ps;
    int i = 0;
    ps = GFL_HEAP_Alloc(heapId, sizeof(struct BrPokeSearch), 0, gBrPokeSearchSourceFile, 0x11a);
    MI_CpuFill8(ps, 0, sizeof(struct BrPokeSearch));
    ps->heapId = heapId;
    ps->zukan = zukan;
    ps->res = res;
    ps->fade = fade;
    ps->uiParamA = uiParamA;
    ps->uiParamB = uiParamB;
    ps->printQue = PRINTSYS_QUE_Create(ps->heapId);
    ps->groupTable = BR_MEMBER_COUNT_GetU16Count((heapId & 0x7fff) | 0x8000, &ps->groupTableCount);
    ps->listParam = listParam;
    ps->tapFx = tapFx;
    for (; i < BR_POKESEARCH_GROUP_COUNT; i++) ps->groupHasSeen[i] = BR_POKESEARCH_HasSeenInGroup(ps->zukan, i, ps->groupTable);
    return ps;
}

void BR_POKESEARCH_Destroy(struct BrPokeSearch *ps)
{
    if(ps->seenList){
        GFL_HEAP_Free(ps->seenList);
        ps->seenList=0;
    }
    GFL_HEAP_Free(ps->groupTable);
    PRINTSYS_QUE_Delete(ps->printQue);
    GFL_HEAP_Free(ps);
}

int BR_POKESEARCH_Main(struct BrPokeSearch *ps)
{
    if (ps->active) {
        switch (ps->state) {
        case BR_POKESEARCH_PHASE_INIT: (ps->state)++; break;
        case BR_POKESEARCH_PHASE_ARM: ps->state=2; break;
        case BR_POKESEARCH_PHASE_GROUPS: {
            int x,y,held;
            struct BrPoint point;
            ps->touchedGroup=BR_POKESEARCH_PollGroupTouch(ps);
            held=TOUCHPANEL_GetPointTrg(&x,&y);
            if (BR_BTN_HitTestWithSound(ps->backButton,x,y)&held) {
                point.x=x; point.y=y;
                BR_UTIL_StartEffect(ps->tapFx,1,&point);
                ps->state=8; ps->result=1;
            } else if (ps->touchedGroup!=9) {
                ps->state=4; ps->nextState=3;
            }
            break;
        }
        case BR_POKESEARCH_PHASE_LIST: {
            int x,y,held;
            struct BrPoint point;
            BR_UTIL_MainListMenu(ps->listMenu);
            ps->listChoice=BR_UTIL_GetListMenuHitId(ps->listMenu);
            held=TOUCHPANEL_GetPointTrg(&x,&y);
            if (BR_BTN_HitTestWithSound(ps->backButton,x,y)&held) {
                point.x=x; point.y=y;
                BR_UTIL_StartEffect(ps->tapFx,1,&point);
                ps->state=4; ps->nextState=2;
            } else if (ps->listChoice!=-1) {
                ps->state=8; ps->result=2;
            }
            break;
        }
        case BR_POKESEARCH_PHASE_TAP_WAIT:
            if (BR_UTIL_IsEffectDone(ps->tapFx)) {
                BR_FADE_Start(ps->fade,2,2,1);
                (ps->state)++;
            }
            break;
        case BR_POKESEARCH_PHASE_FADE_OUT_WAIT:
            if (BR_FADE_GetResult(ps->fade)) (ps->state)++;
            break;
        case BR_POKESEARCH_PHASE_SWITCH:
            if (ps->nextState==3) {
                BR_POKESEARCH_DestroyGroupWindows(ps);
                if (ps->seenList) SAVEDATA_PanicFail(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
                ps->seenList=BR_POKESEARCH_BuildSeenList(ps->zukan,ps->touchedGroup,ps->groupTable,&ps->seenCount,ps->heapId);
                BR_POKESEARCH_CreateSpeciesList(ps);
            } else {
                BR_POKESEARCH_DestroySpeciesList(ps);
                if (ps->seenList) {
                    GFL_HEAP_Free(ps->seenList);
                    ps->seenList=0;
                }
                BR_POKESEARCH_CreateGroupWindows(ps);
            }
            BR_FADE_Start(ps->fade,2,2,0);
            (ps->state)++;
            break;
        case BR_POKESEARCH_PHASE_FADE_IN_WAIT:
            if (BR_FADE_GetResult(ps->fade)) ps->state=ps->nextState;
            break;
        case BR_POKESEARCH_PHASE_EXIT_DELAY1: (ps->state)++; break;
        case BR_POKESEARCH_PHASE_EXIT_DELAY2: (ps->state)++; break;
        case BR_POKESEARCH_PHASE_DONE: ps->done=1; break;
        }
    }
    return BR_POKESEARCH_UpdatePrint(ps);
}

unsigned BR_POKESEARCH_UpdatePrint(struct BrPokeSearch *ps)
{
    unsigned r=1;
    int i;
    for(i=0;i<BR_POKESEARCH_GROUP_COUNT;i++){
        struct BrTextWin *win=ps->groupWin[i];
        if(win)r &= BR_UTIL_FlushText(win);
    }
    return r & PRINTSYS_QUE_Main(ps->printQue);
}

void BR_POKESEARCH_Open(struct BrPokeSearch *ps)
{
    BR_POKESEARCH_CreateBackButton(ps);
    BR_POKESEARCH_CreateGroupWindows(ps);
    ps->active = 1;
}

void BR_POKESEARCH_Close(struct BrPokeSearch *ps)
{
    ps->active=0;
    if(ps->listShown==1)BR_POKESEARCH_DestroySpeciesList(ps);
    else BR_POKESEARCH_DestroyGroupWindows(ps);
    BR_POKESEARCH_DestroyBackButton(ps);
}

/*
 * Unlabelled ov186 leaf: if the done flag is zero return 0; otherwise, when
 * the result is 2, publish the chosen species id through the out pointer and
 * return the result.  Matched to supply the `matched` witness for the
 * pending ov185 caller func_021F86A4.
 */
int BR_POKESEARCH_GetResult(struct BrPokeSearch *ps, unsigned short *speciesOut)
{
    if (ps->done != 0) {
        if (ps->result == 2)
            *speciesOut = (unsigned short)ps->listChoice;
        return ps->result;
    }
    return 0;
}

void BR_POKESEARCH_CreateBackButton(struct BrPokeSearch *ps)
{
    struct BrActorPos pos;
    struct BrResSprite sprite;
    int font = BR_RES_GetFont(ps->res);
    int msgData = BR_RES_GetMsgData(ps->res);
    MI_CpuFill8(&pos, 0, 8);
    pos.x = 0x50; pos.y = 0xa8; pos.animSeq = 0; pos.drawPriority = 1;
    if (!BR_RES_GetSprite(ps->res, 6, &sprite))
        SAVEDATA_PanicFail(gBrPokeSearchAssertString, 0, gBrPokeSearchAssertString);
    ps->backButton = BR_BTN_CreateFromMessage(&pos, 4, 0x60, 1, ps->uiParamA, ps->uiParamB, font, msgData, &sprite, ps->heapId);
}

void BR_POKESEARCH_DestroyBackButton(struct BrPokeSearch *ps)
{
    BR_BTN_DeleteObject(ps->backButton);
}

void BR_POKESEARCH_CreateGroupWindows(struct BrPokeSearch *ps)
{
    int font, msgData, i;
    unsigned color;
    unsigned char x, y;
    ps->listShown = 0;
    BR_RES_LoadBgGraphics(ps->res, 20, ps->heapId);
    font = BR_RES_GetFont(ps->res);
    msgData = BR_RES_GetMsgData(ps->res);
    for (i = 0; i < BR_POKESEARCH_GROUP_COUNT; i++) {
        x = (i % 5) * 6 + 2;
        y = 6;
        if (i < 5) y = 0;
        ps->groupWin[i] = BR_UTIL_Create(4, (unsigned char)x, (unsigned char)(y + 4), (unsigned)4, 2, 14, ps->printQue, ps->heapId);
        color = 0x3da0;
        if (!ps->groupHasSeen[i]) color = 0x2da0;
        BR_UTIL_SetTextLayout(ps->groupWin[i], 0, 0, 1);
        BR_UTIL_SetTextFromMessage(ps->groupWin[i], msgData, i + 0x3a, font, color);
    }
}

void BR_POKESEARCH_DestroyGroupWindows(struct BrPokeSearch *ps)
{
    int i;
    for(i=0;i<BR_POKESEARCH_GROUP_COUNT;i++){
        BR_UTIL_Delete(ps->groupWin[i]);
        ps->groupWin[i]=0;
    }
    BG_SYS_PushTile(4);
    BR_RES_ApplyBgSet(ps->res,20);
}

/*
 *   021FFFF8..022000D0. Singleton tu --suggest-split confirms no viable cut.
 *   Existing integrator-owned unit_02045C44.c function verified EXACT344 with
 *   read-only fixed-flag one (ARM9-45CAC.log). No ARM9 file/shard writes.
 *   Its function: header lists only MSGDATA_CreateFromMemory, omitting func_02045CAC.
 *   Verified C follows, using that unit's declarations:
 *   void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *     u32 size; struct MsgEntry *e;
 *     if (index >= bank->file->count) { STRBUF_Clear(dest); return; }
 *     MSGDATA_RefreshLanguage(bank);
 *     if (bank->resident == 0) {
 *       u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *       ARC_TOOL_SeekHandle(bank->stream, pos + (index * 8 + 4));
 *       ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache); e = &bank->cache;
 *     } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *     if (bank->resident == 0) {
 *       void *buf; size = e->len * 2;
 *       buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                         size, 0, MSGDATA_AllocSite, 0xd6);
 *       if (buf != 0) {
 *         ARC_TOOL_SeekHandle(bank->stream, e->off + (bank->origin
 *                       + bank->file->langOff[bank->langIndex]));
 *         ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *         STRBUF_SetChars(dest, buf, e->len); GFL_HEAP_Free(buf);
 *       }
 *     } else { STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len); }
 *     MSGDATA_DecryptStrbuf(dest, index);
 *   }
 */
void BR_POKESEARCH_CreateSpeciesList(struct BrPokeSearch *ps)
{
    struct BrListMenuConfig cfg;
    struct StrBuf *str;
    u32 i;
    ps->listShown=1;
    BR_RES_LoadBgGraphics(ps->res,21,ps->heapId);
    if (ps->menuItems) SAVEDATA_PanicFail(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
    if (ps->listMenu) SAVEDATA_PanicFail(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
    ps->menuItems=BMP_MENUWORK_Create(ps->seenCount,ps->heapId);
    str=STRBUF_Create(11,ps->heapId);
    for(i=0;i<ps->seenCount;i++) {
        func_02045CAC(gSpeciesNameBank,ps->seenList[i],str);
        BMP_MENUWORK_AddStrItem(ps->menuItems+i,str,ps->seenList[i],ps->heapId);
    }
    STRBUF_Delete(str);
    cfg=gBrPokeSearchListConfig;
    cfg.items=ps->menuItems;
    cfg.itemCount=ps->seenCount;
    cfg.res=ps->res;
    cfg.uiParamA=ps->uiParamA;
    cfg.listParam=ps->listParam;
    cfg.tapFx=ps->tapFx;
    ps->listMenu=BR_UTIL_CreateListMenu(&cfg,ps->heapId);
}

void BR_POKESEARCH_DestroySpeciesList(struct BrPokeSearch *ps)
{
    BR_UTIL_DeleteListMenu(ps->listMenu);
    ps->listMenu=0;
    BMP_MENUWORK_Delete(ps->menuItems);
    ps->menuItems=0;
    BR_RES_ApplyBgSet(ps->res,21);
}

int BR_POKESEARCH_PollGroupTouch(struct BrPokeSearch *ps)
{
    int x, y;
    struct BrPoint point;
    int index = TOUCHPANEL_HitTrg(gBrPokeSearchHitTable);
    if (index != -1) {
        if (ps->groupHasSeen[index]) {
            TOUCHPANEL_GetPointTrg(&x, &y);
            point.x = x;
            point.y = y;
            BR_UTIL_StartEffect(ps->tapFx, 1, &point);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return index;
        }
        GFL_USE_PlaySeDefaultVolume(0x704);
    }
    return 9;
}

/*
 * lever: unsigned table indices preserve load scheduling; raw address casts differ by 12 bytes.
 */
int BR_POKESEARCH_HasSeenInGroup(struct ZukanSave *zukan, u32 group, const u16 *speciesTable)
{
    u32 i;
    u32 end;
    int found;
    end=gBrPokeSearchGroupStart[group+1];
    found=0;
    for(i=gBrPokeSearchGroupStart[group];i<end;i++) {
        if(ZUKAN_SAVE_IsSeen(zukan,*(const u16 *)((u32)speciesTable+i*2)))found=1;
    }
    return found;
}

/*
 * lever: loop-2 store written as two statements (dst[filled] = ...; filled++;) with braced
 *   loop and if bodies; the one-line dst[filled++] form left a 3-register rotation (18 B).
 */
u16 *BR_POKESEARCH_BuildSeenList(struct ZukanSave *zukan, u32 group, const u16 *speciesTable, u32 *countOut, u16 heapId)
{
    u32 end, start;
    u16 *dst;
    int filled;
    int count, bytes;
    end = gBrPokeSearchGroupStart[group + 1];
    count = 0;
    start = gBrPokeSearchGroupStart[group];
    for (filled = start; filled < end; filled++) {
        if (ZUKAN_SAVE_IsSeen(zukan, speciesTable[filled])) {
            count++;
        }
    }
    bytes = count * 2;
    dst = GFL_HEAP_Alloc(heapId, bytes, 0, gBrPokeSearchSourceFile, 0x3c3);
    filled = 0;
    MI_CpuFill8(dst, 0, bytes);
    for (; start < end; start++) {
        if (ZUKAN_SAVE_IsSeen(zukan, speciesTable[start])) {
            dst[filled] = speciesTable[start];
            filled++;
        }
    }
    if (countOut) *countOut = filled;
    return dst;
}
