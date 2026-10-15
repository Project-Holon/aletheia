/*
 * file:     zukan_detail_common.c
 * unit:     yes
 * function: ZUKAN_DETAIL_COMMON_CreateContext, ZUKAN_DETAIL_COMMON_DeleteContext, ZUKAN_DETAIL_COMMON_GetSource, ZUKAN_DETAIL_COMMON_GetDisplay, ZUKAN_DETAIL_COMMON_GetFont, ZUKAN_DETAIL_COMMON_GetGraphics, ZUKAN_DETAIL_COMMON_GetWorkPtr, ZUKAN_DETAIL_COMMON_GetCursorValue, ZUKAN_DETAIL_COMMON_GetMaxValue, ZUKAN_DETAIL_COMMON_GetCurrentEntry, ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies, ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies, ZUKAN_DETAIL_COMMON_AllocBlendWork, ZUKAN_DETAIL_COMMON_FreeBlendWork, ZUKAN_DETAIL_COMMON_UpdateBlendFades, ZUKAN_DETAIL_COMMON_IsBlendBusy, ZUKAN_DETAIL_COMMON_StartBlendIn, ZUKAN_DETAIL_COMMON_StartBlendOut, ZUKAN_DETAIL_COMMON_SetBrightnessFull, ZUKAN_DETAIL_COMMON_SetBrightnessNone, ZUKAN_DETAIL_COMMON_InitBrightnessTarget, ZUKAN_DETAIL_COMMON_ApplyBrightness, ZUKAN_DETAIL_COMMON_CreatePaletteAnim, ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault, ZUKAN_DETAIL_COMMON_DeletePaletteAnim, ZUKAN_DETAIL_COMMON_UpdatePaletteAnim, ZUKAN_DETAIL_COMMON_TransferPalettes, ZUKAN_DETAIL_COMMON_IsFadeBusy, ZUKAN_DETAIL_COMMON_StartFadeOut, ZUKAN_DETAIL_COMMON_StartFadeOutAlt, ZUKAN_DETAIL_COMMON_StartFadeIn, ZUKAN_DETAIL_COMMON_LoadPaletteToSlot, ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots, ZUKAN_DETAIL_COMMON_RequestFade, ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc, ZUKAN_DETAIL_COMMON_FreeBgPalette, ZUKAN_DETAIL_COMMON_TickFlashEffect, ZUKAN_DETAIL_COMMON_LoadBgPaletteRange, ZUKAN_DETAIL_COMMON_SetBgScrollPacked
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
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0  arm
 *   d_021C8D98     0x021C8D98  data  ov208  a4
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   func_0207D67C  0x0207D67C  arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_TransferPalettes 0x02021D50  thumb
 *   PALANM_LoadHandlePaletteToSlotAt 0x02021660 thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_020413B0  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C80E0  0x021C80E0  data
 *   data_021C80E8  0x021C80E8  data
 *   data_021C80F0  0x021C80F0  data
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_COMMON_GetCursorValue 0x021BC3B8 thumb
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
 *   ZUKAN_DETAIL_COMMON_GetMaxValue  0x021BC3BC  thumb  ov208
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
#include "../../matched/include/Obj03064.h"
#include "../../matched/include/Obj18183.h"
#include "../../matched/include/Obj25414.h"
#include "../../matched/include/Obj01178.h"
#include "../../matched/include/Obj02544.h"
#include "../../matched/include/Obj04893.h"
#include "../../matched/include/Obj18185.h"
#include "../../matched/include/Obj18186.h"
#include "../../matched/include/Obj18187.h"
#include "../../matched/include/Obj18188.h"
#include "../../matched/include/Obj18189.h"
#include "../../matched/include/Obj02252.h"
#include "../../matched/include/Obj12112.h"
#include "../../matched/include/Obj07226.h"
#include "zukan_detail_shared_types.h"

struct Obj02021EE4;

struct PalAnmSlot;

struct S02021D50;

struct Ov208Cur;

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

typedef struct {void *task,*memory,*slots;u16 mask,pad;u32 mode;} PalFade;

struct Ov208Gfx { int f0; int f4; void *gfx; };

struct Ov208PalFade {
    u32 f0;
    u32 f4;
    void *slots;
    u16 mask;
};

struct Ov208BgArc {
    u32 chr;
    u32 scr;
    u32 size;
};

struct Ov208Win {
    u32 chrOfs;
    u8  layer;
    u8  kind;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);

extern void func_0207D67C(unsigned int, int, int, int, int, int);

extern u32 func_02030CB0(u32);

extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

extern void *PALANM_Create(u32);

extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern u32 PALANM_Delete(void *a0);

extern void func_02030DA4(void *);

extern void func_02030D28(struct Ctx *c);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern void PALANM_TransferPalettes(struct S02021D50 *p);

extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern int PALANM_RequestFade(void *,unsigned short,unsigned short,short,unsigned char,unsigned char,unsigned short,void *);

extern void *func_020490F4(u32 id, u32 heap);

extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);

extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void func_02041B6C(u32 bit);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

void *ZUKAN_DETAIL_COMMON_CreateContext(u32 a, void *b, void *c, void *d, void *e, void *f, void *g, int h, unsigned short i, void *j);

void ZUKAN_DETAIL_COMMON_DeleteContext(void *a0);

int ZUKAN_DETAIL_COMMON_GetSource(struct Ov208Ctx *p);

int ZUKAN_DETAIL_COMMON_GetDisplay(struct Ov208Ctx *p);

int ZUKAN_DETAIL_COMMON_GetFont(struct Ov208Ctx *p);

int ZUKAN_DETAIL_COMMON_GetGraphics(struct Ov208Ctx *p);

int ZUKAN_DETAIL_COMMON_GetWorkPtr(struct Ov208Ctx *p);

int ZUKAN_DETAIL_COMMON_GetCursorValue(struct Ov208Ctx *p);

u16 ZUKAN_DETAIL_COMMON_GetMaxValue(struct Ov208Ctx *p);

unsigned short ZUKAN_DETAIL_COMMON_GetCurrentEntry(struct Ov208Ctx *p);

void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(struct Ov208Ctx *p);

void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Ctx *p);

void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);

void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *a0);

void ZUKAN_DETAIL_COMMON_UpdateBlendFades(struct Ov208Blend *main, struct Ov208Blend *sub);

int ZUKAN_DETAIL_COMMON_IsBlendBusy(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_StartBlendIn(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_StartBlendOut(struct Ov208Blend *p);

void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, int *p);

void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p);

void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);

void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, int *p);

PalFade *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32 heap,u16 mask);

void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap);

void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(char *p);

void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(char *p);

void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p);

int ZUKAN_DETAIL_COMMON_IsFadeBusy(char *p);

void ZUKAN_DETAIL_COMMON_StartFadeOut(char *p);

void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(char *p);

void ZUKAN_DETAIL_COMMON_StartFadeIn(char *p);

void ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);

void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(struct Ov208PalFade *p);

void ZUKAN_DETAIL_COMMON_RequestFade(char *p,short b,unsigned char c,unsigned char d);

struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);

void ZUKAN_DETAIL_COMMON_FreeBgPalette(char *p);

void ZUKAN_DETAIL_COMMON_TickFlashEffect(char *p);

u32 ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);

void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed);

extern const char d_021C8D98[];

extern const u8 data_021C80E0[2][4];

extern const u8 data_021C80E8[2][4];

extern const struct Ov208BgArc data_021C80F0[2];

void *ZUKAN_DETAIL_COMMON_CreateContext(u32 a, void *b, void *c, void *d, void *e, void *f, void *g, int h,
                    unsigned short i, void *j)
{
    struct Ov208Ctx *p = (struct Ov208Ctx *)func_02030734(a, 0x24, 1, d_021C8D98, 0x60);

    p->blk = b;
    p->display = c;
    p->font = d;
    p->graphics = e;
    p->work = f;
    p->headbar = g;
    p->speciesTable = (unsigned short *)h;
    p->entryCount = i;
    p->cursorPtr = (unsigned short *)j;
    return p;
}

/*
 * Tail call to the ARM9 function at 0x020307B0: loads the pointer from the pool and branches through it.
 */
void ZUKAN_DETAIL_COMMON_DeleteContext(void *a0)
{
    func_020307B0(a0);
}

/*
 * Returns the word at +0 of the object.
 */
int ZUKAN_DETAIL_COMMON_GetSource(struct Ov208Ctx *p)
{
    return (int)p->blk;
}

/*
 * Returns the word at +4.
 */
int ZUKAN_DETAIL_COMMON_GetDisplay(struct Ov208Ctx *p)
{
    return (int)p->display;
}

int ZUKAN_DETAIL_COMMON_GetFont(struct Ov208Ctx *p)
{
    return (int)p->font;
}

int ZUKAN_DETAIL_COMMON_GetGraphics(struct Ov208Ctx *p)
{
    return (int)p->graphics;
}

/*
 * Returns the word at +0x10.
 */
int ZUKAN_DETAIL_COMMON_GetWorkPtr(struct Ov208Ctx *p)
{
    return (int)p->work;
}

int ZUKAN_DETAIL_COMMON_GetCursorValue(struct Ov208Ctx *p)
{
    return (int)p->headbar;
}

u16 ZUKAN_DETAIL_COMMON_GetMaxValue(struct Ov208Ctx *p)
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
    } while (ZUKAN_SAVE_IsSeen((struct Blk37 *)h, p->speciesTable[*p->cursorPtr]) == 0);
}

void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap)
{
    return func_02030734(heap, 20, 1, d_021C8D98, 0x113);
}

void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *a0)
{
    func_020307B0(a0);
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
                p->ev += p->step;
                if (p->step > 0) {
                    if (p->ev >= 16) {
                        p->ev = 16;
                        p->step = 0;
                    }
                } else if (p->ev <= 0) {
                    p->ev = 0;
                    p->step = 0;
                }
                ZUKAN_DETAIL_COMMON_ApplyBrightness(i, (int *)p);
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
    p->ev = 0;
    p->step = 2;
    p->wait = 0;
}

void ZUKAN_DETAIL_COMMON_StartBlendOut(struct Ov208Blend *p)
{
    p->ev = 16;
    p->step = -2;
    p->wait = 0;
}

void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, int *p)
{
    p[2] = 0x10;
    p[3] = 0;
    p[4] = 0;
    ZUKAN_DETAIL_COMMON_ApplyBrightness(flag, p);
}

void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p)
{
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    ZUKAN_DETAIL_COMMON_ApplyBrightness(flag, p);
}

/*
 * Writes 0x2D to the first two words.
 */
void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p)
{
    p[0] = 0x2d;
    p[1] = 0x2d;
}

void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, int *p)
{
    if (flag == 0) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], 0, p[2] - 0x10);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], 0, p[2] - 0x10);
    }
}

PalFade *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32 heap,u16 mask)
{
    PalFade *p=func_02030734(heap,20,1,d_021C8D98,0x1e5);
    p->memory=func_02030734(heap,func_02030CB0(2),1,d_021C8D98,0x1e8);
    p->task=func_02030CBC(2,p->memory);
    p->slots=PALANM_Create(heap);
    PALANM_SetAutoTransfer(p->slots,1);
    p->mask=mask;
    if(p->mask&1)PALANM_AllocSlotBuffers(p->slots,0,0x1a0,heap);
    if(p->mask&4)PALANM_AllocSlotBuffers(p->slots,2,0x100,heap);
    if(p->mask&2)PALANM_AllocSlotBuffers(p->slots,1,0x1a0,heap);
    if(p->mask&8)PALANM_AllocSlotBuffers(p->slots,3,0x1c0,heap);
    p->mode=0;
    return p;
}

void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap)
{
    return ZUKAN_DETAIL_COMMON_CreatePaletteAnim(heap, 0xf);
}

void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(char *p)
{
    if(((struct Obj02544 *)p)->fC&8)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,3);
    if(((struct Obj02544 *)p)->fC&2)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,1);
    if(((struct Obj02544 *)p)->fC&4)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,2);
    if(((struct Obj02544 *)p)->fC&1)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,0);
    PALANM_Delete(((struct Obj02544 *)p)->f8);
    func_02030DA4(((struct Obj02544 *)p)->f0);
    func_020307B0((void *)(((struct Obj02544 *)p)->f4));
    func_020307B0((void *)((unsigned)p));
}

/*
 * Releases +0 and re-checks the handle at +8 for the two armed states at +0x10.
 */
void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(char *p)
{
    func_02030D28((struct Ctx *)(((struct Obj04893 *)p)->f0));
    switch (((struct Obj04893 *)p)->f10) {
    case 0:
    case 1:
        break;
    case 2:
        if (PALANM_GetFadeRequestBits((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 0;
        break;
    case 3:
        if (PALANM_GetFadeRequestBits((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 1;
        break;
    }
}

/*
 * Loads the word at +8 and tail-calls the function at 0x02021D51 (the thumb
 * address of the ARM9 function at 0x02021D50).
 */
void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p)
{
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj18185 *)p)->f8));
}

/*
 * True when the word at +0x10, less two, is 0 or 1.
 */
int ZUKAN_DETAIL_COMMON_IsFadeBusy(char *p)
{
    unsigned int v = ((struct Obj18186 *)p)->f10;

    v -= 2;
    return v <= 1;
}

void ZUKAN_DETAIL_COMMON_StartFadeOut(char *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, -1, 0x10, 0);
    ((struct Obj18187 *)p)->f10 = 2;
}

void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(char *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, -1, 0, 0x10);
    ((struct Obj18188 *)p)->f10 = 3;
}

/*
 * Runs the idle transition with 0x10 twice and marks state 1.
 */
void ZUKAN_DETAIL_COMMON_StartFadeIn(char *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, 0, 0x10, 0x10);
    ((struct Obj18189 *)p)->f10 = 1;
}

void ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g)
{
    PALANM_LoadHandlePaletteToSlotAt(p->gfx, (void *)a, b, c, d, e, f, g);
}

void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(struct Ov208PalFade *p)
{
    if (p->mask & 1)
        PALANM_CopyHwPaletteToSlot(p->slots, 0, 0, 0x1a0);
    if (p->mask & 4)
        PALANM_CopyHwPaletteToSlot(p->slots, 2, 0, 0x100);
    if (p->mask & 2)
        PALANM_CopyHwPaletteToSlot(p->slots, 1, 0, 0x1a0);
    if (p->mask & 8)
        PALANM_CopyHwPaletteToSlot(p->slots, 3, 0, 0x1c0);
}

void ZUKAN_DETAIL_COMMON_RequestFade(char *p,short b,unsigned char c,unsigned char d)
{
    if(((struct Obj02252 *)p)->fC&1)PALANM_RequestFade(((struct Obj02252 *)p)->f8,1,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&4)PALANM_RequestFade(((struct Obj02252 *)p)->f8,4,0xff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&2)PALANM_RequestFade(((struct Obj02252 *)p)->f8,2,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&8)PALANM_RequestFade(((struct Obj02252 *)p)->f8,8,0x3fff,b,c,d,0,((struct Obj02252 *)p)->f0);
}

struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal)
{
    struct Ov208Win *w;
    void *h;
    u32 sub;
    u32 type;
    u32 scr;

    w = func_02030734(heap, sizeof(*w), 1, d_021C8D98, 0x323);
    if (layer < 4) {
        sub = 0;
        type = 0;
    } else {
        sub = 1;
        type = 4;
    }
    h = func_020490F4(0x9f, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E8[sub][kind] << 5, pal << 5,
                  0x20, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E0[sub][kind] << 5,
                  objPal << 5, 0x20, heap);
    w->chrOfs = func_02049740(h, data_021C80F0[sub].scr, layer, 0, 0, heap);
    scr = data_021C80F0[sub].size;
    if (kind == 3 && sub == 0)
        scr = 0x20;
    func_02049990(h, scr, layer, 0, (u16)w->chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0x15, 0x20, 3, pal);
    func_020413B0(layer, 0, 0, 0x20, 0x15, objPal);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(layer);
    w->layer = layer;
    w->kind = 4;
    return w;
}

/*
 * Passes the byte at +4 and the two halfwords of the word at +0 on, then re-inits the object.
 */
void ZUKAN_DETAIL_COMMON_FreeBgPalette(char *p)
{
    unsigned int w;

    w = ((struct Obj12112 *)p)->f0;
    BG_SYS_DeleteHalf(((struct Obj12112 *)p)->f4, (unsigned short)w, (unsigned short)(w >> 16));
    func_020307B0((void *)((int)p));
}

void ZUKAN_DETAIL_COMMON_TickFlashEffect(char *p)
{
    unsigned char c;

    c = ((struct Obj07226 *)p)->f5;
    if (c == 0) {
        BG_SYS_ResetSlot(((struct Obj07226 *)p)->f4, 1, 1);
        ((struct Obj07226 *)p)->f5 = 4;
    } else {
        ((struct Obj07226 *)p)->f5 = c - 1;
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
    h = func_020490F4(arc, heap);
    if (skip == 0)
        ARC_UTIL_UploadPaletteFromHandle(h, chr, type, palOfs << 5, pal << 5, count << 5, heap);
    if (skip == 0)
        chrOfs = func_02049740(h, scr, layer, 0, 0, heap);
    func_02049990(h, cell, layer, 0, (u16)chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0, 0x20, 0x18, pal);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(layer);
    return chrOfs;
}

void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed)
{
    BG_SYS_DeleteHalf(a, (u16)packed, (u16)(packed >> 16));
}
