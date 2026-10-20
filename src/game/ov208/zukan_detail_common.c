/*
 * file:     zukan_detail_common.c
 * unit:     yes
 * function: ZUKAN_DETAIL_COMMON_CreateContext, ZUKAN_DETAIL_COMMON_DeleteContext, ZUKAN_DETAIL_COMMON_GetSource, ZUKAN_DETAIL_COMMON_GetDisplay, ZUKAN_DETAIL_COMMON_GetFont, ZUKAN_DETAIL_COMMON_GetGraphics, ZUKAN_DETAIL_COMMON_GetWorkPtr, ZUKAN_DETAIL_COMMON_GetHeadbar, ZUKAN_DETAIL_COMMON_GetEntryCount, ZUKAN_DETAIL_COMMON_GetCurrentEntry, ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies, ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies, ZUKAN_DETAIL_COMMON_AllocBlendWork, ZUKAN_DETAIL_COMMON_FreeBlendWork, ZUKAN_DETAIL_COMMON_UpdateBlendFades, ZUKAN_DETAIL_COMMON_IsBlendBusy, ZUKAN_DETAIL_COMMON_StartBlendIn, ZUKAN_DETAIL_COMMON_StartBlendOut, ZUKAN_DETAIL_COMMON_SetBrightnessFull, ZUKAN_DETAIL_COMMON_SetBrightnessNone, ZUKAN_DETAIL_COMMON_InitBrightnessTarget, ZUKAN_DETAIL_COMMON_ApplyBrightness, ZUKAN_DETAIL_COMMON_CreatePaletteAnim, ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault, ZUKAN_DETAIL_COMMON_DeletePaletteAnim, ZUKAN_DETAIL_COMMON_UpdatePaletteAnim, ZUKAN_DETAIL_COMMON_TransferPalettes, ZUKAN_DETAIL_COMMON_IsFadeBusy, ZUKAN_DETAIL_COMMON_StartFadeOut, ZUKAN_DETAIL_COMMON_StartFadeOutAlt, ZUKAN_DETAIL_COMMON_StartFadeIn, ZUKAN_DETAIL_COMMON_LoadPaletteToSlot, ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots, ZUKAN_DETAIL_COMMON_RequestFade, ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc, ZUKAN_DETAIL_COMMON_FreeBgPalette, ZUKAN_DETAIL_COMMON_TickFlashEffect, ZUKAN_DETAIL_COMMON_LoadBgPaletteRange, ZUKAN_DETAIL_COMMON_SetBgScrollPacked
 * address:  0x021BC35C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   d_021C8D98     0x021C8D98  data  ov208  a4
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   G2x_SetBlendBrightnessExt_  0x0207D67C  arm
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_TransferPalettes 0x02021D50  thumb
 *   PALANM_LoadHandlePaletteToSlotAt 0x02021660 thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   data_021C80E0  0x021C80E0  data
 *   data_021C80E8  0x021C80E8  data
 *   data_021C80F0  0x021C80F0  data
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_COMMON_GetHeadbar 0x021BC3B8 thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   ZUKAN_DETAIL_COMMON_GetGraphics 0x021BC3B0 thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetFont 0x021BC3AC thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreatePaletteAnim 0x021BC560 thumb ov208
 *   ZUKAN_DETAIL_COMMON_FreeBgPalette 0x021BC97C thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeletePaletteAnim 0x021BC61C thumb ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc  0x021BC844  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots  0x021BC758  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendIn  0x021BC4D8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetEntryCount  0x021BC3BC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_IsBlendBusy  0x021BC4C8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendOut  0x021BC4E4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades  0x021BC46C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull 0x021BC4F4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TransferPalettes 0x021BC6BC thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault  0x021BC610  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBgScrollPacked  0x021BCA54  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeIn 0x021BC718 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOut 0x021BC6D8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy 0x021BC6C8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOutAlt 0x021BC6F8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TickFlashEffect 0x021BC99C thumb ov208
 *   ZUKAN_DETAIL_COMMON_UpdatePaletteAnim 0x021BC678 thumb ov208
 *   ZUKAN_DETAIL_COMMON_LoadPaletteToSlot 0x021BC738 thumb ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteRange  0x021BC9BC  thumb  ov208
 */
#include "../arm9/tcb_list.h"
#include "zukan_detail_shared_types.h"

struct PaletteFade;

/*
 * Brightness/blend controller, 0x14 bytes, one per engine, allocated by
 * ZUKAN_DETAIL_COMMON_AllocBlendWork. plane1/plane2 are the two BLDCNT plane
 * masks, brightness the current blend level (0 none to 16 full), step the
 * per-frame delta and wait the per-frame delay.
 */
struct Ov208Blend {
    int plane1;
    int plane2;
    int brightness;
    int step;
    int wait;
};

struct Ov208BgArc {
    u32 chr;
    u32 scr;
    u32 size;
};

/*
 * Palette window object, 8 bytes, returned by
 * ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc: chrOfs is the character base of the
 * uploaded palette, layer the BG layer it was loaded into and flashTimer a
 * per-frame countdown that drives the flash effect (4 down to 0).
 */
struct Ov208Win {
    u32 chrOfs;
    u8  layer;
    u8  flashTimer;
};

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/zukan_save.h"
struct ZukanSave;


#include "../arm9/g2.h"

extern u32 TCB_GetTaskOffset(u32);


#include "../arm9/palanm.h"

struct TcbSystem;
extern void PALANM_SetAutoTransfer(PaletteFade *o, int v);




extern void TCB_Noop(struct TcbSystem *sys);
struct TcbSystem;

extern void TCB_Main(struct TcbSystem *sys);

extern u32 PALANM_GetFadeRequestBits(const PaletteFade *ptr);

extern void PALANM_TransferPalettes(PaletteFade *p);



extern int PALANM_RequestFade(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

#include "../arm9/arc_tool.h"

#include "../arm9/arc_util.h"



#include "../arm9/bg_sys.h"





void *ZUKAN_DETAIL_COMMON_CreateContext(u32 a, void *b, void *c, void *d, void *e, void *f, void *g, int h, unsigned short i, void *j);

void ZUKAN_DETAIL_COMMON_DeleteContext(void *ctx);

void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);

void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *blend);

void ZUKAN_DETAIL_COMMON_UpdateBlendFades(struct Ov208Blend *main, struct Ov208Blend *sub);

int ZUKAN_DETAIL_COMMON_IsBlendBusy(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_StartBlendIn(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_StartBlendOut(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, struct Ov208Blend *p);

struct Ov208PalFade *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32 heap,u16 mask);

void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap);

void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_TransferPalettes(struct Ov208PalFade *p);

int ZUKAN_DETAIL_COMMON_IsFadeBusy(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_StartFadeOut(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_StartFadeIn(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(struct Ov208PalFade *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);

void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_RequestFade(struct Ov208PalFade *p, short b, unsigned char c, unsigned char d);

struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);

void ZUKAN_DETAIL_COMMON_FreeBgPalette(struct Ov208Win *p);

void ZUKAN_DETAIL_COMMON_TickFlashEffect(struct Ov208Win *p);

u32 ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);

void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed);

extern const char d_021C8D98[];

extern const u8 data_021C80E0[2][4];

extern const u8 data_021C80E8[2][4];

extern const struct Ov208BgArc data_021C80F0[2];

void *ZUKAN_DETAIL_COMMON_CreateContext(u32 heapId, void *blk, void *display, void *font, void *graphics, void *work, void *headbar, int speciesTable,
                    unsigned short entryCount, void *cursorPtr)
{
    struct Ov208Ctx *p = (struct Ov208Ctx *)GFL_HEAP_Alloc(heapId, 0x24, 1, d_021C8D98, 0x60);

    p->blk = blk;
    p->display = display;
    p->font = font;
    p->graphics = graphics;
    p->work = work;
    p->headbar = headbar;
    p->speciesTable = (unsigned short *)speciesTable;
    p->entryCount = entryCount;
    p->cursorPtr = (unsigned short *)cursorPtr;
    return p;
}

/*
 * Tail call to the ARM9 function at 0x020307B0: loads the pointer from the pool and branches through it.
 */
void ZUKAN_DETAIL_COMMON_DeleteContext(void *ctx)
{
    GFL_HEAP_Free(ctx);
}

/*
 * Returns the word at +0 of the object.
 */
void *ZUKAN_DETAIL_COMMON_GetSource(struct Ov208Ctx *p)
{
    return p->blk;
}

/*
 * Returns the word at +4.
 */
void *ZUKAN_DETAIL_COMMON_GetDisplay(struct Ov208Ctx *p)
{
    return p->display;
}

void *ZUKAN_DETAIL_COMMON_GetFont(struct Ov208Ctx *p)
{
    return p->font;
}

void *ZUKAN_DETAIL_COMMON_GetGraphics(struct Ov208Ctx *p)
{
    return p->graphics;
}

/*
 * Returns the word at +0x10.
 */
void *ZUKAN_DETAIL_COMMON_GetWorkPtr(struct Ov208Ctx *p)
{
    return p->work;
}

void *ZUKAN_DETAIL_COMMON_GetHeadbar(struct Ov208Ctx *p)
{
    return p->headbar;
}

unsigned short ZUKAN_DETAIL_COMMON_GetEntryCount(struct Ov208Ctx *p)
{
    return p->entryCount;
}

/*
 * Returns the halfword of the table at +0x18 indexed by the halfword read through the pointer at +0x20.
 */
unsigned short ZUKAN_DETAIL_COMMON_GetCurrentEntry(struct Ov208Ctx *p)
{
    return p->speciesTable[*p->cursorPtr];
}

void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(struct Ov208Ctx *p)
{
    unsigned short old=*p->cursorPtr;
    void *owner=ZUKAN_SAVE_GetFromGameData(p->blk);
    do {
        ++*p->cursorPtr;
        if(*p->cursorPtr>=p->entryCount)
            *p->cursorPtr=0;
        if(*p->cursorPtr==old)break;
    }while(ZUKAN_SAVE_IsSeen(owner,p->speciesTable[*p->cursorPtr])==0);
}

void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Ctx *p)
{
    u16 start = *p->cursorPtr;
    u32 h = (u32)ZUKAN_SAVE_GetFromGameData(p->blk);
    do {
        if (*p->cursorPtr == 0)
            *p->cursorPtr = p->entryCount - 1;
        else
            *p->cursorPtr = *p->cursorPtr - 1;
        if (*p->cursorPtr == start)
            break;
    } while (ZUKAN_SAVE_IsSeen((struct ZukanSave *)h, p->speciesTable[*p->cursorPtr]) == 0);
}

void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap)
{
    return GFL_HEAP_Alloc(heap, 20, 1, d_021C8D98, 0x113);
}

void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *blend)
{
    GFL_HEAP_Free(blend);
}

void ZUKAN_DETAIL_COMMON_UpdateBlendFades(struct Ov208Blend *main, struct Ov208Blend *sub)
{
    struct Ov208Blend *b[2];
    struct Ov208Blend *p;
    u8 i;

    b[0] = main;
    b[1] = sub;
    for (i = 0; i < 2; i++) {
        p = b[i];
        if (p->step != 0) {
            if (p->wait == 0) {
                p->wait = 0;
                p->brightness += p->step;
                if (p->step > 0) {
                    if (p->brightness >= 16) {
                        p->brightness = 16;
                        p->step = 0;
                    }
                } else if (p->brightness <= 0) {
                    p->brightness = 0;
                    p->step = 0;
                }
                ZUKAN_DETAIL_COMMON_ApplyBrightness(i, p);
            } else {
                p->wait--;
            }
        }
    }
}

int ZUKAN_DETAIL_COMMON_IsBlendBusy(struct Ov208Blend *p)
{
    if (p->step != 0)
        return 1;
    return 0;
}

void ZUKAN_DETAIL_COMMON_StartBlendIn(struct Ov208Blend *p)
{
    p->brightness = 0;
    p->step = 2;
    p->wait = 0;
}

void ZUKAN_DETAIL_COMMON_StartBlendOut(struct Ov208Blend *p)
{
    p->brightness = 16;
    p->step = -2;
    p->wait = 0;
}

void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, struct Ov208Blend *p)
{
    p->brightness = 0x10;
    p->step = 0;
    p->wait = 0;
    ZUKAN_DETAIL_COMMON_ApplyBrightness(flag, p);
}

void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, struct Ov208Blend *p)
{
    p->brightness = 0;
    p->step = 0;
    p->wait = 0;
    ZUKAN_DETAIL_COMMON_ApplyBrightness(flag, p);
}

/*
 * Writes 0x2D to the two BLDCNT plane masks.
 */
void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(struct Ov208Blend *p)
{
    p->plane1 = 0x2d;
    p->plane2 = 0x2d;
}

void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, struct Ov208Blend *p)
{
    if (flag == 0) {
        G2x_SetBlendBrightnessExt_(0x04000050, p->plane1, p->plane2, p->brightness, 0, p->brightness - 0x10);
    } else {
        G2x_SetBlendBrightnessExt_(0x04001050, p->plane1, p->plane2, p->brightness, 0, p->brightness - 0x10);
    }
}

struct Ov208PalFade *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32 heap,u16 mask)
{
    struct Ov208PalFade *p=GFL_HEAP_Alloc(heap,20,1,d_021C8D98,0x1e5);
    p->memory=GFL_HEAP_Alloc(heap,TCB_GetTaskOffset(2),1,d_021C8D98,0x1e8);
    p->tcb=(struct Ctx *)TCB_Init(2,p->memory);
    p->slots=PALANM_Create(heap);
    PALANM_SetAutoTransfer(p->slots,1);
    p->slotMask=mask;
    if(p->slotMask&1)PALANM_AllocSlotBuffers(p->slots,0,0x1a0,heap);
    if(p->slotMask&4)PALANM_AllocSlotBuffers(p->slots,2,0x100,heap);
    if(p->slotMask&2)PALANM_AllocSlotBuffers(p->slots,1,0x1a0,heap);
    if(p->slotMask&8)PALANM_AllocSlotBuffers(p->slots,3,0x1c0,heap);
    p->fadeState=0;
    return p;
}

void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap)
{
    return ZUKAN_DETAIL_COMMON_CreatePaletteAnim(heap, 0xf);
}

void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(struct Ov208PalFade *p)
{
    if(p->slotMask&8)PALANM_FreeSlotBuffers(p->slots,3);
    if(p->slotMask&2)PALANM_FreeSlotBuffers(p->slots,1);
    if(p->slotMask&4)PALANM_FreeSlotBuffers(p->slots,2);
    if(p->slotMask&1)PALANM_FreeSlotBuffers(p->slots,0);
    PALANM_Delete(p->slots);
    TCB_Noop((struct TcbSystem *)p->tcb);
    GFL_HEAP_Free(p->memory);
    GFL_HEAP_Free((void *)((unsigned)p));
}

/*
 * Releases the TCB at +0 and re-checks the PALANM handle at +8 for the two
 * armed fade states at +0x10.
 */
void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(struct Ov208PalFade *p)
{
    TCB_Main((struct TcbSystem *)p->tcb);
    switch (p->fadeState) {
    case 0:
    case 1:
        break;
    case 2:
        if (PALANM_GetFadeRequestBits((const PaletteFade *)p->slots) == 0)
            p->fadeState = 0;
        break;
    case 3:
        if (PALANM_GetFadeRequestBits((const PaletteFade *)p->slots) == 0)
            p->fadeState = 1;
        break;
    }
}

/*
 * Passes the PALANM handle at +8 on to the ARM9 transfer at 0x02021D50.
 */
void ZUKAN_DETAIL_COMMON_TransferPalettes(struct Ov208PalFade *p)
{
    PALANM_TransferPalettes(p->slots);
}

/*
 * True when the fade state at +0x10, less two, is 0 or 1.
 */
int ZUKAN_DETAIL_COMMON_IsFadeBusy(struct Ov208PalFade *p)
{
    unsigned int v = p->fadeState;

    v -= 2;
    return v <= 1;
}

void ZUKAN_DETAIL_COMMON_StartFadeOut(struct Ov208PalFade *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, -1, 0x10, 0);
    p->fadeState = 2;
}

void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(struct Ov208PalFade *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, -1, 0, 0x10);
    p->fadeState = 3;
}

/*
 * Runs the idle transition with 0x10 twice and marks state 1.
 */
void ZUKAN_DETAIL_COMMON_StartFadeIn(struct Ov208PalFade *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, 0, 0x10, 0x10);
    p->fadeState = 1;
}

void ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(struct Ov208PalFade *p, u32 arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset)
{
    PALANM_LoadHandlePaletteToSlotAt(p->slots, (void *)arcHandle, fileId, heapId, slotIdx, byteSize, dstOffset, srcOffset);
}

void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(struct Ov208PalFade *p)
{
    if (p->slotMask & 1)
        PALANM_CopyHwPaletteToSlot(p->slots, 0, 0, 0x1a0);
    if (p->slotMask & 4)
        PALANM_CopyHwPaletteToSlot(p->slots, 2, 0, 0x100);
    if (p->slotMask & 2)
        PALANM_CopyHwPaletteToSlot(p->slots, 1, 0, 0x1a0);
    if (p->slotMask & 8)
        PALANM_CopyHwPaletteToSlot(p->slots, 3, 0, 0x1c0);
}

void ZUKAN_DETAIL_COMMON_RequestFade(struct Ov208PalFade *p, short step, unsigned char startLevel, unsigned char endLevel)
{
    if(p->slotMask&1)PALANM_RequestFade(p->slots,1,0x1fff,step,startLevel,endLevel,0,p->tcb);
    if(p->slotMask&4)PALANM_RequestFade(p->slots,4,0xff,step,startLevel,endLevel,0,p->tcb);
    if(p->slotMask&2)PALANM_RequestFade(p->slots,2,0x1fff,step,startLevel,endLevel,0,p->tcb);
    if(p->slotMask&8)PALANM_RequestFade(p->slots,8,0x3fff,step,startLevel,endLevel,0,p->tcb);
}

struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal)
{
    struct Ov208Win *w;
    void *h;
    u32 sub;
    u32 type;
    u32 scr;

    w = GFL_HEAP_Alloc(heap, sizeof(*w), 1, d_021C8D98, 0x323);
    if (layer < 4) {
        sub = 0;
        type = 0;
    } else {
        sub = 1;
        type = 4;
    }
    h = ARC_TOOL_CreateHandle(0x9f, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E8[sub][kind] << 5, pal << 5,
                  0x20, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E0[sub][kind] << 5,
                  objPal << 5, 0x20, heap);
    w->chrOfs = ARC_UTIL_RegisterObjCharFromHandle(h, data_021C80F0[sub].scr, layer, 0, 0, heap);
    scr = data_021C80F0[sub].size;
    if (kind == 3 && sub == 0)
        scr = 0x20;
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, scr, layer, 0, (u16)w->chrOfs, 0, 0, heap);
    BG_SYS_FillTileMap(layer, 0, 0x15, 0x20, 3, pal);
    BG_SYS_FillTileMap(layer, 0, 0, 0x20, 0x15, objPal);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_MarkTileDirty(layer);
    w->layer = layer;
    w->flashTimer = 4;
    return w;
}

/*
 * Passes the layer at +4 and the two halfwords of the character base at +0 on,
 * then frees the window.
 */
void ZUKAN_DETAIL_COMMON_FreeBgPalette(struct Ov208Win *p)
{
    unsigned int w;

    w = p->chrOfs;
    BG_SYS_FreeTileRun(p->layer, (unsigned short)w, (unsigned short)(w >> 16));
    GFL_HEAP_Free((void *)((int)p));
}

void ZUKAN_DETAIL_COMMON_TickFlashEffect(struct Ov208Win *p)
{
    unsigned char c;

    c = p->flashTimer;
    if (c == 0) {
        BG_SYS_ChangeScroll(p->layer, 1, 1);
        p->flashTimer = 4;
    } else {
        p->flashTimer = c - 1;
    }
}

u32 ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc,
                        u32 chr, u32 scr, u32 cell, u32 chrOfs)
{
    void *h;
    u32 type;

    type = 0;
    if (layer >= 4)
        type = 4;
    h = ARC_TOOL_CreateHandle(arc, heap);
    if (skip == 0)
        ARC_UTIL_UploadPaletteFromHandle(h, chr, type, palOfs << 5, pal << 5, count << 5, heap);
    if (skip == 0)
        chrOfs = ARC_UTIL_RegisterObjCharFromHandle(h, scr, layer, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, cell, layer, 0, (u16)chrOfs, 0, 0, heap);
    BG_SYS_FillTileMap(layer, 0, 0, 0x20, 0x18, pal);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_MarkTileDirty(layer);
    return chrOfs;
}

void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 layer, u32 packed)
{
    BG_SYS_FreeTileRun(layer, (u16)packed, (u16)(packed >> 16));
}
