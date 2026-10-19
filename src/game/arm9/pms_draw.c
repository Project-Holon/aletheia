/*
 * file:     pms_draw.c
 * unit:     yes
 * function: PMS_DRAW_Create, PMS_DRAW_Main, PMS_DRAW_Delete, PMS_DRAW_Print, PMS_DRAW_PrintOffset, PMS_DRAW_IsPrintEnd, PMS_DRAW_Clear, PMS_DRAW_SetVisible, PMS_DRAW_IsActive, PMS_DRAW_SetDecoVisible, PMS_DRAW_SetDecoPriority, PMS_DRAW_Copy, PMS_DRAW_SetNullColorPalette, PMS_DRAW_SetPrintColor, PMS_DRAW_SetFollowBgScroll, PMS_DRAW_CalcDecoPos, PMS_DRAW_GetDecoCgrIndex, PMS_DRAW_GetDecoCelIndex, PMS_DRAW_GetDecoAnmIndex, PMS_DRAW_LoadResources, PMS_DRAW_ReleaseResources, PMS_DRAW_CreateDecoActor, PMS_DRAW_PlaceDecoActor, PMS_DRAW_InitElem, PMS_DRAW_DeleteElem, PMS_DRAW_UpdateElem, PMS_DRAW_PrintElem, PMS_DRAW_ClearElem, PMS_DRAW_SetElemVisible, PMS_DRAW_GetFrameSurface, PMS_DRAW_ClearWork, ITEM_GetRegisterFlagId
 * address:  0x0202DB0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter   0x0204A6C8  arm
 *   ARC_TOOL_CreateHandle   0x020490F4  arm
 *   CLACT_RegisterCellAnim   0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle   0x02049238  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   PmsDrawFileName   0x020A77B8  data  a1
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_CopyPixels  0x02043814  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   UI_GetFrameRate  0x02035630  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   BG_SYS_GetPriority  0x020416D4  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BG_SYS_GetChannelScrollX  0x02041648  arm
 *   BG_SYS_GetChannelScrollY  0x02041664  arm
 *   CLACT_GetActorPos  0x0204B53C  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   PMSI_PARAM_Validate  0x0202465C  thumb
 *   PMSI_PARAM_GetSourceString  0x0202441C  thumb
 *   PRINTSYS_CountControlTag  0x0201D478  thumb
 *   PMSI_PARAM_IsDecoWordAt  0x020244F8  thumb
 *   PMSI_PARAM_GetWordId  0x020244D4  thumb
 *   PMSI_PARAM_ToStringWords  0x02024368  thumb
 *   PRINTSYS_MeasureText  0x0201D528  thumb
 *   PRINTSYS_SearchIndex  0x0201D4BC  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   ItemValueTable  0x020A02A8  data
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"
#include "bgwinfrm_shared_types.h"

struct PmsDrawRes;

struct Actor;

struct PmsDraw;

struct PmsElem;

struct Cfg;

struct Bmp;

struct PtS;

struct Vec2;

struct PmsPos;

struct PrintSys;

struct Container;

struct PmsPos;

struct Rec8;

struct PmsData;

struct CharBuf;

struct U16Vec;

struct PmsFlagBits {
    u32 active : 1;
    u32 visible : 1;
    u32 decoVisible : 1;
    u32 rest : 29;
};

union PmsFlags {
    u32 word;
    struct PmsFlagBits bits;
};

struct PmsElem {
    void *bmpWin;
    u8    printing;
    u8    pad05[3];
    struct Actor *decoActor[2];
    s32   scrollX;
    s32   scrollY;
    union PmsFlags flags;
    u32   reserved1C;
    u32   isDeco[2];
};

struct PmsDraw {
    u16   heapId;
    u8    pad02[2];
    u32   font;
    void *printQue;
    struct PmsElem *elems;
    u32   res[5];      /* struct PmsDrawRes, kept as words: DB0C and DF68 index it */
    u16   printColor;
    u8    pad26[2];
    u32   printEnd;
    u32   followBgScroll;
    u8    elemMax;
    u8    nullColorPalette;
};

typedef signed short   s16;

struct PmsPoint { s16 x; s16 y; };

struct PmsPos {
    u32 x;
    u32 y;
};

typedef volatile unsigned int vu32;

struct DecoActorInit { u16 x; u16 y; u16 anmSeq; u16 softPri; };

struct PmsDrawRes {
    u32 clunit;
    u32 drawType;
    u32 plttIndex;
    u32 cgrIndex;
    u32 cellAnmIndex;
};

struct DecoPos  { u16 x; u16 y; };

typedef struct { u16 sentenceType; u16 sentenceId; u16 word[2]; } PmsData;

typedef struct { s32 x; s32 y; } PmsOffset;

struct ItemValueEntry {
    u16 itemId : 10;
    u16 registerFlag : 6;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);
struct BmpWin;

extern u8 BMP_WIN_GetPosX(struct BmpWin *win);

extern u8 BMP_WIN_GetPosY(struct BmpWin *win);

extern u32 CLACT_RegisterPaletteEx(void *h, u32 file_idx, u32 engine, u32 vram_offset, u32 s0, u32 s1, u32 s2);

extern u32 CLACT_RegisterCharacter(void *h, u32 file_idx, u32 compressed, u32 engine, u32 s0);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void  ARC_TOOL_DeleteHandle(void *h);

extern void  MI_CpuFill8(void *p, u32 v, u32 n);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 val);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern void BG_SYS_MarkTileDirty(u32 bit);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern void CLACT_AddActorSurfacePos(struct Actor *p, const struct Vec2 *delta, u32 which);

extern u16 CLACT_GetActorAnimSeq(struct Actor *p);

extern void CLACT_SetActorAnimSeq(struct Actor *p, u16 value);

extern void CLACT_SetActorDrawEnable(struct Actor *p, u32 v);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern struct Actor *CLACT_CreateActor(void *a, u32 b, u32 c, u32 d,
                                const void *e, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct Actor *p, u32 v);

extern u8 UI_GetFrameRate(void);

extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);

extern u8 BG_SYS_GetPriority(u32 layer);

extern void  CLACT_SetActorBgPriority(struct Actor *actor, u32 priority);

extern void CLACT_DeleteActor(struct Actor *p);
struct PrintQueue;

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);

extern u32 BG_SYS_GetChannelScrollX(u8 channel);

extern u32 BG_SYS_GetChannelScrollY(u8 channel);
struct Pt16;

extern void CLACT_GetActorPos(struct Actor *actor, struct Pt16 *out);

extern void CLACT_SetActorPos(struct Actor *actor, struct Pt16 *pos);

extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);

extern u32 PMSI_PARAM_Validate(struct PmsData *p, u32 allowEmpty, u32 heapId);

extern void *PMSI_PARAM_GetSourceString(const struct PmsData *obj, u32 heapId);
struct Strbuf;

extern u32   PRINTSYS_CountControlTag(struct Strbuf *text);

extern u32 PMSI_PARAM_IsDecoWordAt(struct Container *p, u32 idx);

extern u16 PMSI_PARAM_GetWordId(PmsData *sentence, u32 index);

extern void *PMSI_PARAM_ToStringWords(u16 *slots, u32 heap, int count);
struct GfFont;

extern u32 PRINTSYS_MeasureText(struct Strbuf *text, u8 markerId, struct GfFont *font, u32 spacing);

extern u32   PRINTSYS_SearchIndex(struct Strbuf *text, u8 markerId);

extern void BMP_Clear(struct Bmp *bmp, u8 value);

extern void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

extern void  BMP_FillRect(u32 a, u32 b, s16 c, u32 d, u32 e, u8 f);

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern void BMP_WIN_ClearScreen(struct BmpWin *win);

extern void BG_SYS_PushTile(u32 index);

struct PmsDraw *PMS_DRAW_Create(u32 clunit, u32 drawType, u32 printQue, u32 font, u8 plttOffset, u8 elemMax, u16 heapId);

void PMS_DRAW_Main(struct PmsDraw *wk);

void PMS_DRAW_Delete(struct PmsDraw *wk);
struct BeaconDetailGraQuad;

void PMS_DRAW_Print(u32 wk, u32 bmpWin, struct BeaconDetailGraQuad *pms, u32 id);

void PMS_DRAW_PrintOffset(struct PmsDraw *wk, void *bmpWin, void *pms, u32 id, const void *offset);

u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *wk);

void PMS_DRAW_Clear(struct PmsDraw *wk, int id, u32 isTrans);

void PMS_DRAW_SetVisible(struct PmsDraw *wk, int id, u32 visible);

u32 PMS_DRAW_IsActive(const struct PmsDraw *wk, u32 id);

void PMS_DRAW_SetDecoVisible(struct PmsDraw *wk, u32 id, u32 visible);

void PMS_DRAW_SetDecoPriority(struct PmsDraw *wk, u32 id, u32 priority);

void PMS_DRAW_Copy(struct PmsDraw *wk, u32 srcId, u32 dstId);

void PMS_DRAW_SetNullColorPalette(struct PmsDraw *wk, u8 palette);

void PMS_DRAW_SetPrintColor(struct PmsDraw *wk, u16 color);

void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *wk, u32 follow);

void PMS_DRAW_CalcDecoPos(u32 bmpWin, u32 charX, u32 line, const struct PmsPos *offset, struct PmsPos *out);

u32 PMS_DRAW_GetDecoCgrIndex(u32 engine);

u32 PMS_DRAW_GetDecoCelIndex(u32 engine);

u32 PMS_DRAW_GetDecoAnmIndex(u32 engine);

void PMS_DRAW_LoadResources(u32 *res, u32 plttOffset, u32 heapId);

void PMS_DRAW_ReleaseResources(struct PmsDrawRes *res);

void *PMS_DRAW_CreateDecoActor(struct PmsDrawRes *res, u16 heapId);

void PMS_DRAW_PlaceDecoActor(void *actor, struct Descriptor *bmpWin, u32 charX, u32 line, u32 wordId, const struct PmsPos *offset);

void PMS_DRAW_InitElem(struct PmsElem *elem, struct PmsDrawRes *res, u16 heapId);

void PMS_DRAW_DeleteElem(struct PmsElem *elem);

int PMS_DRAW_UpdateElem(struct PmsElem *elem, void *printQue, int followBgScroll);

void PMS_DRAW_PrintElem(struct PmsElem *elem, void *printQue, u32 font, struct Descriptor *bmpWin, const PmsData *param, const PmsOffset *offset, u16 color, u8 nullColorPalette, u16 heapId);

void PMS_DRAW_ClearElem(struct PmsElem *elem, u32 isTrans);

void PMS_DRAW_SetElemVisible(struct PmsElem *elem, u32 visible);

u32 PMS_DRAW_GetFrameSurface(u32 frame);

void PMS_DRAW_ClearWork(void *p);

u32 ITEM_GetRegisterFlagId(u32 id);

extern char  PmsDrawFileName[];

extern const struct ItemValueEntry ItemValueTable[];

/*
 * The PmsDraw constructor.  Closed 2026-09-23 from the 68-byte near miss
 * in docs/notes/pkt_0202DB0C.c.txt by two changes:
 *   - the second allocator's heap is a named u16 local read back from
 *     p->heap IMMEDIATELY after the store (`h = p->heap;`), so it is the
 *     same value as the strh operand and stays in r0 across the three
 *     field stores; `p->heap` written at the call re-reads it, the `heap`
 *     parameter makes it a callee-saved copy from the prologue;
 *   - the fifth parameter is u8 after all (`ldrb` at the PMS_DRAW_LoadResources
 *     site); it only looked like it cost four bytes while the heap value
 *     was wrong.
 * The allocator result still has to go through a named local before p.
 */
struct PmsDraw *PMS_DRAW_Create(u32 clunit, u32 drawType, u32 printQue, u32 font, u8 plttOffset, u8 elemMax, u16 heapId)
{
    struct PmsDraw *wk;
    u32 size;
    u16 heap;
    int i;
    struct PmsDraw *alloc = GFL_HEAP_Alloc(heapId, 0x34, 1, PmsDrawFileName, 0x81);

    wk = alloc;
    MI_CpuFill8(wk, 0, 0x34);
    wk->heapId = heapId;
    heap = wk->heapId;
    wk->printQue = (void *)printQue;
    wk->font = font;
    wk->elemMax = elemMax;
    wk->nullColorPalette = 0xf;
    wk->followBgScroll = 0;
    size = elemMax * 0x28;
    wk->elems = GFL_HEAP_Alloc(heap, size, 1, PmsDrawFileName, 0x8c);
    MI_CpuFill8(wk->elems, 0, size);
    wk->res[0] = clunit;
    wk->res[1] = drawType;
    wk->printColor = 0x11 << 6;
    PMS_DRAW_LoadResources(wk->res, plttOffset, wk->heapId);
    for (i = 0; i < wk->elemMax; i++) {
        PMS_DRAW_InitElem(&wk->elems[i], (struct PmsDrawRes *)wk->res, wk->heapId);
    }
    return wk;
}

/*
 * Picks the selected entry of the 0x28-byte element array hung off +0xc:
 * the selection at +0x28 is primed to 1, then every element whose +0x18
 * bit 0 is set is offered to PMS_DRAW_UpdateElem along with the two cursor
 * words at +8 and +0x2c; the first one that answers non-zero resets the
 * selection to 0.  The count at +0x30 is a signed char and is re-read at
 * the top of every iteration (the call may change it), which is what
 * keeps the `adds r0, r5, #0x30; ldrb` pair inside the loop -- 0x30 is
 * past the Thumb `ldrb` immediate reach of +31.
 */
void PMS_DRAW_Main(struct PmsDraw *wk)
{
    s32 i;

    wk->printEnd = 1;
    for (i = 0; i < (s32)wk->elemMax; i++) {
        struct PmsElem *elem = wk->elems + i;
        if (elem->flags.bits.active != 0) {
            if (PMS_DRAW_UpdateElem(elem, wk->printQue, wk->followBgScroll) != 0) {
                wk->printEnd = 0;
            }
        }
    }
}

void PMS_DRAW_Delete(struct PmsDraw *wk)
{
    int i;

    for (i = 0; i < wk->elemMax; i++) {
        PMS_DRAW_DeleteElem(wk->elems + i);
    }

    GFL_HEAP_Free(wk->elems);
    PMS_DRAW_ReleaseResources((struct PmsDrawRes *)wk->res);
    GFL_HEAP_Free(wk);
}

void PMS_DRAW_Print(u32 wk, u32 bmpWin, struct BeaconDetailGraQuad *pms, u32 id)
{
    u32 offset[2] = { 0, 0 };

    PMS_DRAW_PrintOffset((struct PmsDraw *)wk, (void *)bmpWin, (void *)pms, id, offset);
}

/*
 * The forwarding shim in front of PMS_DRAW_PrintElem: it copies four of the
 * object's own fields into the callee's five stack arguments and clears
 * the selection word at +0x28 afterwards.
 *
 * The ARGUMENT ORDER is what this function pins, and it corrects the
 * reading in docs/notes/pkt_0202E1F0.anmSeq.txt: r1 is the object pointer at
 * +8, r2 the word at +4 and r3 the caller's own `a`, which the prologue
 * parks in r4 (`adds r4, r1, #0`) precisely because it is consumed LAST.
 * Spelling the call (e, a, p->plttIndex, p->drawType, ...) instead leaves `a` in r1
 * and loses the r4 copy, four bytes short.
 *
 * The five stack words are four plain u32 arguments behind `w`, not a
 * 16-byte struct passed by value: a by-value struct makes the compiler
 * build a local and ldm/stm it into the outgoing area (18 bytes more),
 * whereas the original stores each field straight to its slot. The
 * halfword fields at +0x24, +0x31 and +0x00 are widened to words at the
 * call, so the parameters are u32.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_PrintOffset.anmSeq \
 *       --func PMS_DRAW_PrintOffset --addr 0x0202DC60 --cc 1.1p1 --thumb
 */
void PMS_DRAW_PrintOffset(struct PmsDraw *wk, void *bmpWin, void *pms, u32 id, const void *offset)
{
    PMS_DRAW_PrintElem(wk->elems + id, wk->printQue, wk->font, bmpWin, pms,
                  offset, wk->printColor, wk->nullColorPalette, wk->heapId);
    wk->printEnd = 0;
}

/*
 * Three leaves before PMS_DRAW_IsActive over an object with a count at +0x28 and
 * an array of 0x28-byte elements at +0xc: the count getter, and two
 * forwarders that pass element i and one argument to PMS_DRAW_ClearElem and
 * PMS_DRAW_SetElemVisible.  Seeded from ov031 0x021F069A, ov110 0x021C0CC6, ov111
 * 0x021C61D2, ov216 0x021BD12A.
 *
 * Addresses are Black-image addresses.
 */
u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *wk)
{
    return wk->printEnd;
}

void PMS_DRAW_Clear(struct PmsDraw *wk, int id, u32 isTrans)
{
    PMS_DRAW_ClearElem(&wk->elems[id], isTrans);
}

void PMS_DRAW_SetVisible(struct PmsDraw *wk, int id, u32 visible)
{
    PMS_DRAW_SetElemVisible(&wk->elems[id], visible);
}

u32 PMS_DRAW_IsActive(const struct PmsDraw *wk, u32 id)
{
    return wk->elems[id].flags.bits.active;
}

void PMS_DRAW_SetDecoVisible(struct PmsDraw *wk, u32 id, u32 visible)
{
    if (PMS_DRAW_IsActive(wk, id) != 0) {
        wk->elems[id].flags.bits.decoVisible = visible;
    }
}

void PMS_DRAW_SetDecoPriority(struct PmsDraw *wk, u32 id, u32 priority)
{
    int i;

    for (i = 0; i < 2; i++) {
        CLACT_SetActorObjMode(wk->elems[id].decoActor[i], priority);
    }
}

/*
 * Copies element i onto element j of the pms_draw owner, sprite state
 * included (docs/families/pms_draw.h). EXACT* only because the listing
 * extent runs on over the three unlabelled setters at 0x0202DE5C
 * (src/matched/unit_0202DE5C.anmSeq); the function itself is 310 bytes.
 *
 * Closed in wave 14 from the wave-12 note (8 bytes, dst/dy spill slots):
 *   - the handles are read through the element pointers, src->bmpWin and
 *     dst->bmpWin, not e[i]/e[j]; the compiler still folds them to the
 *     image's `ldr r0,[r6,r7]` / `ldr r0,[r6,dj]`, but dst now stays a
 *     named value and takes the image's slot sp+8;
 *   - no `e` local: src = &p->elems[i]; dst = &p->elems[j];
 *   - dx declared before dy (dx at sp+4, dy at sp+0);
 *   - the loop counter k declared FIRST: with src declared ahead of it,
 *     src takes r4 and the call temporaries/k take r5, the mirror image.
 */
void PMS_DRAW_Copy(struct PmsDraw *wk, u32 srcId, u32 dstId)
{
    int i;
    struct PmsElem *src;
    struct PmsElem *dst;
    s32 dx;
    s32 dy;
    u32 surface;
    struct PmsPoint pt;
    void *bmpWin;

    src = &wk->elems[srcId];
    dst = &wk->elems[dstId];
    dx = BMP_WIN_GetPosX(dst->bmpWin) - BMP_WIN_GetPosX(src->bmpWin);
    dy = BMP_WIN_GetPosY(dst->bmpWin) - BMP_WIN_GetPosY(src->bmpWin);
    BMP_CopyPixels((struct Bmp *)((u32)BMP_WIN_GetBmp((struct BmpWin *)src->bmpWin)), (const struct Bmp *)((u32)BMP_WIN_GetBmp((struct BmpWin *)dst->bmpWin)));
    bmpWin = dst->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(bmpWin));

    for (i = 0; i < 2; i++) {
        surface = PMS_DRAW_GetFrameSurface(BMP_WIN_GetBgLayer(src->bmpWin));
        CLACT_GetActorSurfacePos(src->decoActor[i], (struct PtS *)&pt, (u16)surface);
        pt.x += dx * 8;
        pt.y += dy * 8;
        CLACT_AddActorSurfacePos(dst->decoActor[i], (const struct Vec2 *)(&pt), (u16)surface);
        CLACT_SetActorAnimSeq(dst->decoActor[i], CLACT_GetActorAnimSeq(src->decoActor[i]));
        CLACT_SetActorDrawEnable(dst->decoActor[i], src->isDeco[i]);
    }
    dst->printing = src->printing;
    dst->flags.bits.active = src->flags.bits.active;
    dst->flags.bits.visible = src->flags.bits.visible;
    for (i = 0; i < 2; i++) {
        dst->isDeco[i] = src->isDeco[i];
    }
}

void PMS_DRAW_SetNullColorPalette(struct PmsDraw *wk, u8 palette)
{
    wk->nullColorPalette = palette;
}

void PMS_DRAW_SetPrintColor(struct PmsDraw *wk, u16 color)
{
    wk->printColor = color;
}

void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *wk, u32 follow)
{
    wk->followBgScroll = follow;
}

void PMS_DRAW_CalcDecoPos(u32 bmpWin, u32 charX, u32 line, const struct PmsPos *offset,
                  struct PmsPos *out)
{
    out->x = offset->x + (charX + BMP_WIN_GetPosX((struct BmpWin *)bmpWin) * 8);
    out->y = offset->y + ((line << 4) + BMP_WIN_GetPosY((struct BmpWin *)bmpWin) * 8);
}

u32 PMS_DRAW_GetDecoCgrIndex(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x21;
    case 0x00100010:
        return 0x22;
    case 0x00200010:
        return 0x20;
    }
    return 0x20;
}

u32 PMS_DRAW_GetDecoCelIndex(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x27;
    case 0x00100010:
        return 0x28;
    case 0x00200010:
        return 0x26;
    }
    return 0x26;
}

u32 PMS_DRAW_GetDecoAnmIndex(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x2D;
    case 0x00100010:
        return 0x2E;
    case 0x00200010:
        return 0x2C;
    }
    return 0x26;
}

/*
 * Builds the four handles of the pms_draw sub-object at +0x10 of its
 * owner: the three VRAM-bank queries of unit_0202DE9C are taken first
 * (off the engine word at +4), a 0x2b resource set is opened on the
 * caller's heap, and ENV_SetResourceSet / CLACT_RegisterCharacter / CLACT_RegisterCellAnim
 * fill +8, +0xc and +0x10 before the set is closed again.
 *
 * The screen-size argument to ENV_SetResourceSet is `(u16)(a1 << 5)`, the
 * unequal shift pair lsls #0x15 / lsrs #0x10 -- a narrowing cast folded
 * with the shift, not an 11-bit bitfield.
 */
void PMS_DRAW_LoadResources(u32 *res, u32 plttOffset, u32 heapId)
{
    u32 cgrDatId;
    u32 celDatId;
    u32 anmDatId;
    void *handle;

    cgrDatId = PMS_DRAW_GetDecoCgrIndex(res[1]);
    celDatId = PMS_DRAW_GetDecoCelIndex(res[1]);
    anmDatId = PMS_DRAW_GetDecoAnmIndex(res[1]);
    handle = ARC_TOOL_CreateHandle(0x2b, heapId);
    res[2] = CLACT_RegisterPaletteEx(handle, 1, res[1], (u16)(plttOffset << 5), 0, 5, heapId);
    res[3] = CLACT_RegisterCharacter(handle, anmDatId, 0, res[1], heapId);
    res[4] = CLACT_RegisterCellAnim(handle, cgrDatId, celDatId, heapId);
    ARC_TOOL_DeleteHandle(handle);
}

void PMS_DRAW_ReleaseResources(struct PmsDrawRes *res)
{
    CLACT_ReleasePalette(res->plttIndex);
    CLACT_ReleaseCharacter(res->cgrIndex);
    CLACT_ReleaseCellAnim(res->cellAnmIndex);
}

/*
 * Creates one actor out of the five-word resource record the owner keeps
 * at +0x10 (PMS_DRAW_LoadResources is what fills it), disables it, enables its
 * second flag, and adds the 0x2000 bit only for language 0x1e.
 *
 * The four zero halfwords at sp+0xc must be written as a BRACE
 * INITIALISER, `struct DecoActorInit z = { 0, 0, 0, 0 };`.  Assigning the four
 * fields as statements -- with or without the address bound to a named
 * pointer local -- swaps r0 and r2 throughout the block (the compiler
 * materialises the zero first and the frame address second, and then
 * re-materialises `add r0, sp, #0xc` for the outgoing slot), which is
 * seventy concrete bytes out and is the whole residue this function had.
 * The permuter (hill and anneal, 3800 compiles, --types) could not reach
 * it from the statement form: no body mutation moves an initialiser's
 * definition order.
 *
 * `one` exists because the original materialises 1 twice, once as the
 * r1 argument to CLACT_SetActorAutoAnim and once into r4 to survive the
 * UI_GetFrameRate call and become `lsls r1, r4, #0xd`; writing the shift
 * as a bare `0x2000` costs a pool word instead.
 *
 * The follower at 0x0202E040 is reached across two bytes of linker fill
 * at 0x0202E03E, which is the 82-against-84 the star records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_CreateDecoActor.anmSeq \
 *       --func PMS_DRAW_CreateDecoActor --addr 0x0202DFEC --cc 1.1p1 --thumb
 */
void *PMS_DRAW_CreateDecoActor(struct PmsDrawRes *res, u16 heapId)
{
    struct DecoActorInit init = { 0, 0, 0, 0 };
    void *actor;
    u32 one;

    actor = CLACT_CreateActor((void *)res->clunit, res->cgrIndex, res->plttIndex, res->cellAnmIndex, &init, (u16)res->drawType, heapId);
    CLACT_SetActorDrawEnable(actor, 0);
    one = 1;
    CLACT_SetActorAutoAnim(actor, 1);
    if (UI_GetFrameRate() == 0x1e) {
        CLACT_SetActorAutoAnimSpeed(actor, one << 0xd);
    }
    return actor;
}

/*
 * Places one element sprite: PMS_DRAW_CalcDecoPos resolves the cell offset into a
 * pair of u32s, which are narrowed into the adjacent u16 pair the
 * CLACT_AddActorSurfacePos setter wants, then the cell's own id decides the priority
 * word through PMS_DRAW_GetFrameSurface and the last stack argument (a 1-based index)
 * is passed on as `(u16)(n - 1)`.
 */
void PMS_DRAW_PlaceDecoActor(void *actor, struct Descriptor *bmpWin, u32 charX, u32 line,
                   u32 wordId, const struct PmsPos *offset)
{
    struct PmsPos pos;
    struct DecoPos pt;
    u32 frame;

    PMS_DRAW_CalcDecoPos((u32)bmpWin, charX, line, (const struct PmsPos *)offset, (struct PmsPos *)(&pos));
    pt.x = (u16)pos.x;
    pt.y = (u16)pos.y;
    frame = BMP_WIN_GetBgLayer((struct BmpWin *)bmpWin);
    CLACT_AddActorSurfacePos(actor, (const struct Vec2 *)(&pt), (u16)PMS_DRAW_GetFrameSurface(frame));
    CLACT_SetActorBgPriority(actor, BG_SYS_GetPriority(frame));
    CLACT_SetActorAnimSeq(actor, (u16)(wordId - 1));
}

/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): the loop counter is signed,
 *           the image compares with blt; u32 gave blo (1 byte)
 */
void PMS_DRAW_InitElem(struct PmsElem *elem, struct PmsDrawRes *res, u16 heapId)
{
    int i;

    for (i = 0; i < 2; i++) {
        elem->decoActor[i] = PMS_DRAW_CreateDecoActor(res, heapId);
    }
    elem->flags.word = (elem->flags.word & ~1) | 4;
}

void PMS_DRAW_DeleteElem(struct PmsElem *elem)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor(elem->decoActor[i]);
    }
}

int PMS_DRAW_UpdateElem(struct PmsElem *elem, void *printQue, int followBgScroll)
{
    int ret;
    s32 i;

    if (elem->printing != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(elem->bmpWin)) == 0) {
            BMP_WIN_TransferChars(elem->bmpWin);
            elem->printing = 0;
        }
    }

    ret = (elem->printing != 0) ? 1 : 0;
    if (ret == 0) {
        if (elem->flags.bits.visible) {
            for (i = 0; i < 2; i++) {
                if (elem->isDeco[i] != 0 && elem->flags.bits.decoVisible) {
                    CLACT_SetActorDrawEnable(elem->decoActor[i], 1);
                } else {
                    CLACT_SetActorDrawEnable(elem->decoActor[i], 0);
                }
            }
        }
    }

    if (followBgScroll != 0) {
        s32 frame = (s32)BMP_WIN_GetBgLayer(elem->bmpWin);
        struct PmsPoint diff = { 0, 0 };
        struct PmsPoint pos;
        s32 scrollX;
        s32 scrollY;
        scrollX = BG_SYS_GetChannelScrollX((u8)frame);
        scrollY = BG_SYS_GetChannelScrollY((u8)frame);

        if (scrollX != elem->scrollX) {
            diff.x = elem->scrollX - scrollX;
            elem->scrollX = scrollX;
        }

        if (scrollY != elem->scrollY) {
            diff.y = elem->scrollY - scrollY;
            elem->scrollY = scrollY;
        }

        if (diff.x != 0 || diff.y != 0) {
            for (i = 0; i < 2; i++) {
                CLACT_GetActorPos(elem->decoActor[i], (struct Pt16 *)(&pos));
                pos.x += diff.x;
                pos.y += diff.y;
                CLACT_SetActorPos(elem->decoActor[i], (struct Pt16 *)(&pos));
            }
        }
    }

    return ret;
}

/*
 * blink_palanm: set up a message's blink palette animation.  Copy the
 * caller's PmsData into a local, build the string, mark which characters
 * blink (wk->blink[i]) or are blank (mark[i]), draw the window, then start
 * a palette animation (PMS_DRAW_PlaceDecoActor) on every blinking character and clear
 * every blank one.  Only caller: PMS_DRAW_PrintOffset, which passes the five stack
 * words (param, pos, pri, pal, heap).
 *
 * Closed 2026-09-24 (wave 21, lane E12) from DIFF 2
 * (docs/notes/pkt_0202E1F0.anmSeq.txt, waves 5-21).  Two things together,
 * neither enough on its own:
 *   - the parameter `param` is reused as `param = &mp` after the copy, and
 *     every later call, including PMSI_PARAM_ToStringWords after loop 1, takes
 *     `param` (with `&mp` there the image's `adds r0, r7, #0` at +0x8E is
 *     rematerialised as `add r0, sp, #0x38`, 2 out);
 *   - the two stores after PMSI_PARAM_Validate are written msg first, then
 *     active.  In the other order the compile puts wk in r7 and param in r6
 *     (21 out).  The scheduler emits the strb before the str in both
 *     orders, so the listing only shows the order through the allocation.
 * The lane-E7 draft (callee widths read from the callees' matched bodies)
 * is the starting point; only those two lines differ from it.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_PrintElem.anmSeq \
 *       --func PMS_DRAW_PrintElem --addr 0x0202E1F0 --cc 1.1p1 --thumb
 */
void PMS_DRAW_PrintElem(struct PmsElem *elem, void *printQue, u32 font, struct Descriptor *bmpWin,
                   const PmsData *param, const PmsOffset *offset,
                   u16 color, u8 nullColorPalette, u16 heapId)
{
    u32 isBlank[2] = {0, 0};
    PmsData pmsCopy;
    void *str;
    void *word;
    int i;
    u16 heapID;
    int wordCount;

    PMSI_PARAM_Copy((struct Rec8 *)(&pmsCopy), (const struct Rec8 *)param);
    param = &pmsCopy;
    PMSI_PARAM_Validate((struct PmsData *)(&pmsCopy), 1, heapId);
    elem->bmpWin = bmpWin;
    elem->printing = 0;
    heapID = *(u16 *)&heapId;
    str = PMSI_PARAM_GetSourceString((const struct PmsData *)param, heapID);
    wordCount = (u8)PRINTSYS_CountControlTag(str);
    for (i = 0; i < wordCount; i++) {
        if (PMSI_PARAM_IsDecoWordAt((struct Container *)param, i)) {
            elem->isDeco[i] = 1;
        } else if (PMSI_PARAM_GetWordId((void *)param, i) == 0xffff) {
            isBlank[i] = 1;
        }
    }
    word = PMSI_PARAM_ToStringWords((u16 *)param, heapID, wordCount);
    BMP_Clear((struct Bmp *)((u32)BMP_WIN_GetBmp((struct BmpWin *)elem->bmpWin)), nullColorPalette);
    PRINTSYS_PrintQueColor(printQue, (struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)elem->bmpWin), (s16)offset->x, (s16)offset->y, (struct Strbuf *)word, (struct GfFont *)font, color);
    elem->printing = 1;
    for (i = 0; i < wordCount; i++) {
        if (elem->isDeco[i] == 1) {
            u32 x = PRINTSYS_MeasureText(word, i, (void *)font, 0);
            u32 y = PRINTSYS_SearchIndex(word, i);
            PMS_DRAW_PlaceDecoActor(elem->decoActor[i], bmpWin, x, y, PMSI_PARAM_GetWordId((void *)param, i), (const struct PmsPos *)offset);
        } else if (isBlank[i] == 1) {
            u32 x = PRINTSYS_MeasureText(word, i, (void *)font, 0);
            u32 y = PRINTSYS_SearchIndex(word, i);
            BMP_FillRect((u32)BMP_WIN_GetBmp((struct BmpWin *)bmpWin), x, y << 4, 0x54, 0x10, nullColorPalette);
        }
    }
    STRBUF_Delete(word);
    STRBUF_Delete(str);
    BMP_WIN_MakeScreen((struct BmpWin *)elem->bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)elem->bmpWin));
    elem->flags.bits.active = 1;
    elem->flags.bits.visible = 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_ClearElem.anmSeq \
 *       --func PMS_DRAW_ClearElem --addr 0x0202E38C --cc 1.1p1 --thumb
 */
void PMS_DRAW_ClearElem(struct PmsElem *elem, u32 isTrans)
{
    void *h;
    int i;

    BMP_Clear((struct Bmp *)((u32)BMP_WIN_GetBmp((struct BmpWin *)elem->bmpWin)), 0);
    if (isTrans != 0) {
        BMP_WIN_TransferChars((struct BmpWin *)elem->bmpWin);
        h = elem->bmpWin;
        BMP_WIN_ClearScreen((struct BmpWin *)h);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    }
    for (i = 0; i < 2; i++) {
        CLACT_SetActorDrawEnable(elem->decoActor[i], 0);
        elem->isDeco[i] = 0;
    }
    elem->scrollX = 0;
    elem->scrollY = 0;
    elem->flags.word &= ~1;
    elem->flags.word &= ~2;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_SetElemVisible.anmSeq \
 *       --func PMS_DRAW_SetElemVisible --addr 0x0202E3E4 --cc 1.1p1 --thumb
 */
void PMS_DRAW_SetElemVisible(struct PmsElem *elem, u32 visible)
{
    int i;

    elem->flags.word = (elem->flags.word & ~2) | ((visible & 1) << 1);
    if (visible != 0)
        BMP_WIN_MakeScreen((struct BmpWin *)elem->bmpWin);
    else
        BMP_WIN_ClearScreen((struct BmpWin *)elem->bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)elem->bmpWin));
    for (i = 0; i < 2; i++) {
        if (elem->isDeco[i] != 0)
            CLACT_SetActorDrawEnable(elem->decoActor[i], visible);
    }
}

u32 PMS_DRAW_GetFrameSurface(u32 frame)
{
    if (frame >= 4) {
        return 1;
    }
    return 0;
}

void PMS_DRAW_ClearWork(void *p)
{
    MI_CpuFill8(p, 0, 4);
}

u32 ITEM_GetRegisterFlagId(u32 id)
{
    u32 i;

    for (i = 0; i < 7; i++) {
        if (id == ItemValueTable[i].itemId) {
            return ItemValueTable[i].registerFlag;
        }
    }
    return 0x19;
}
