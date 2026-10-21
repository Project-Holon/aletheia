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
 *   GF_PANIC_Fail 0x02034714 arm
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
 *   MSGDATA_ReadString 0x02045CAC arm
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
#include "../arm9/touchpanel.h"
#include "../ov186/br_util.h"

struct U16Vec;

#include "br_res.h"

struct Strbuf;

#include "../arm9/strbuf.h"


#include "../arm9/gfl_use.h"


#include "../arm9/bg_sys.h"

#include "../arm9/mi_memory.h"
struct MsgBank;

#include "../arm9/msgdata.h"





#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gf_panic.h"
struct PrintQueue;

#include "../arm9/printsys.h"



#include "br_btn.h"





#include "br_fade.h"
#include "br_member_count.h"















#include "../arm9/zukan_save.h"

#include "../arm9/bmp_menuwork.h"
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
    ps->printQue = (struct PrintSys *)PRINTSYS_QUE_Create(ps->heapId);
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
    PRINTSYS_QUE_Delete((struct PrintQueue *)ps->printQue);
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
            held=TOUCHPANEL_GetPointTrg((u32 *)((unsigned int *)(&x)),(u32 *)((unsigned int *)(&y)));
            if (BR_BTN_HitTestWithSound((unsigned int *)ps->backButton,x,y)&held) {
                point.x=x; point.y=y;
                BR_UTIL_StartEffect((char *)ps->tapFx,1,(const BrPair *)&point);
                ps->state=8; ps->result=1;
            } else if (ps->touchedGroup!=9) {
                ps->state=4; ps->nextState=3;
            }
            break;
        }
        case BR_POKESEARCH_PHASE_LIST: {
            int x,y,held;
            struct BrPoint point;
            BR_UTIL_MainListMenu((char *)ps->listMenu);
            ps->listChoice=BR_UTIL_GetListMenuHitId((char *)ps->listMenu);
            held=TOUCHPANEL_GetPointTrg((u32 *)((unsigned int *)(&x)),(u32 *)((unsigned int *)(&y)));
            if (BR_BTN_HitTestWithSound((unsigned int *)ps->backButton,x,y)&held) {
                point.x=x; point.y=y;
                BR_UTIL_StartEffect((char *)ps->tapFx,1,(const BrPair *)&point);
                ps->state=4; ps->nextState=2;
            } else if (ps->listChoice!=-1) {
                ps->state=8; ps->result=2;
            }
            break;
        }
        case BR_POKESEARCH_PHASE_TAP_WAIT:
            if (BR_UTIL_IsEffectDone((char *)ps->tapFx)) {
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
                if (ps->seenList) GF_PANIC_Fail(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
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
        if(win)r &= BR_UTIL_FlushText((unsigned char *)win);
    }
    return r & PRINTSYS_QUE_Main((struct PrintQueue *)ps->printQue);
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
 * ov185 caller BR_POKESEARCH_MainTask.
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
    if (!BR_RES_GetSprite((struct BrRes *)ps->res, 6, (void *)&sprite))
        GF_PANIC_Fail((const char *)gBrPokeSearchAssertString, 0, (const char *)gBrPokeSearchAssertString);
    ps->backButton = BR_BTN_CreateFromMessage((void *)(&pos), 4, 0x60, 1, (void *)ps->uiParamA, (void *)ps->uiParamB, (void *)font, (struct MsgBank *)msgData, (void *)&sprite, ps->heapId);
}

void BR_POKESEARCH_DestroyBackButton(struct BrPokeSearch *ps)
{
    BR_BTN_DeleteObject((char *)ps->backButton);
}

void BR_POKESEARCH_CreateGroupWindows(struct BrPokeSearch *ps)
{
    sptr font, msgData, i;
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
        BR_UTIL_SetTextLayout((unsigned char *)ps->groupWin[i], 0, 0, 1);
        BR_UTIL_SetTextFromMessage((char *)ps->groupWin[i], (void *)msgData, (void *)(i + 0x3a), (void *)font, color);
    }
}

void BR_POKESEARCH_DestroyGroupWindows(struct BrPokeSearch *ps)
{
    int i;
    for(i=0;i<BR_POKESEARCH_GROUP_COUNT;i++){
        BR_UTIL_Delete((unsigned char *)ps->groupWin[i]);
        ps->groupWin[i]=0;
    }
    BG_SYS_PushTile(4);
    BR_RES_ApplyBgSet(ps->res,20);
}

/*
 *   021FFFF8..022000D0. Singleton tu --suggest-split confirms no viable cut.
 *   Existing integrator-owned unit_02045C44.c function verified EXACT344 with
 *   read-only fixed-flag one (ARM9-45CAC.log). No ARM9 file/shard writes.
 *   Its function: header lists only MSGDATA_CreateFromMemory, omitting MSGDATA_ReadString.
 *   Verified C follows, using that unit's declarations:
 *   void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest) {
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
    struct U16Vec *str;
    u32 i;
    ps->listShown=1;
    BR_RES_LoadBgGraphics(ps->res,21,ps->heapId);
    if (ps->menuItems) GF_PANIC_Fail(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
    if (ps->listMenu) GF_PANIC_Fail(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
    ps->menuItems=(struct BrMenuItem *)BMP_MENUWORK_Create(ps->seenCount,ps->heapId);
    str=(struct U16Vec *)STRBUF_Create(11,ps->heapId);
    for(i=0;i<ps->seenCount;i++) {
        MSGDATA_ReadString(gSpeciesNameBank,ps->seenList[i],(struct Strbuf *)str);
        BMP_MENUWORK_AddStrItem((struct BmpMenuWork *)ps->menuItems+i,str,ps->seenList[i],ps->heapId);
    }
    STRBUF_Delete((struct Strbuf *)str);
    cfg=gBrPokeSearchListConfig;
    cfg.list=ps->menuItems;
    cfg.count=ps->seenCount;
    cfg.resources=ps->res;
    cfg.manager=ps->uiParamA;
    cfg.cursor=ps->listParam;
    cfg.other=(uptr)ps->tapFx;
    ps->listMenu=BR_UTIL_CreateListMenu(&cfg,ps->heapId);
}

void BR_POKESEARCH_DestroySpeciesList(struct BrPokeSearch *ps)
{
    BR_UTIL_DeleteListMenu((char *)ps->listMenu);
    ps->listMenu=0;
    BMP_MENUWORK_Delete(ps->menuItems);
    ps->menuItems=0;
    BR_RES_ApplyBgSet(ps->res,21);
}

int BR_POKESEARCH_PollGroupTouch(struct BrPokeSearch *ps)
{
    int x, y;
    struct BrPoint point;
    int index = TOUCHPANEL_HitTrg((const TouchHitTable *)gBrPokeSearchHitTable);
    if (index != -1) {
        if (ps->groupHasSeen[index]) {
            TOUCHPANEL_GetPointTrg((u32 *)((unsigned int *)(&x)), (u32 *)((unsigned int *)(&y)));
            point.x = x;
            point.y = y;
            BR_UTIL_StartEffect((char *)ps->tapFx, 1, (const BrPair *)&point);
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
        if(ZUKAN_SAVE_IsSeen(zukan,*(const u16 *)((uptr)speciesTable+i*2)))found=1;
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
