/*
 * file:     intro_mcss.c
 * unit:     yes
 * function: INTRO_MCSS_Create, INTRO_MCSS_Delete, INTRO_MCSS_Main, INTRO_MCSS_AddSlot
 * address:  0x021BF594
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from intro_cmd.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   gIntroSite 0x021C0AE4 data a1
 *   gIntroMcssSite 0x021C0AF0 data ov204
 *   MCSS_SetPaletteTransAdrs 0x02016024 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   sIntroMcssDefaultPos 0x021C08F0 data ov204
 *   INTRO_G3D_OnAnimEnd 0x021BF7F0 thumb ov204
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_Init  0x02014B08  thumb  arm9
 *   MCSS_Add  0x020159C8  thumb  arm9
 *   MCSS_SetAnimCallback  0x02015F2C  thumb  arm9
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb  arm9
 */
#include "../types.h"
#include "../arm9/mcss.h"
#include "intro_types.h"

/* Opaque MCSS system (defined in arm9 mcss.c). */
struct McssSys;

/* Opaque source row for MCSS_Add. */
struct Sub150;

#include "../arm9/gfl_heap_wrap.h"





struct McssWork;




struct McssAddWork;



#include "intro_g3d.h"


void *INTRO_MCSS_Create(unsigned int heap, int kind);

void INTRO_MCSS_Delete(u8 *p);

void INTRO_MCSS_Main(u8 *p);

void INTRO_MCSS_AddSlot(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);

extern const char gIntroMcssSite[];

extern const IntroVec sIntroMcssDefaultPos;

void *INTRO_MCSS_Create(unsigned int heap, int kind)
{
    IntroMcssWork *work = GFL_HEAP_Alloc(heap, 108, 1, gIntroMcssSite, 98);
    work->sys = MCSS_Init((unsigned int)8, (unsigned int)heap);
    work->heapId = heap;
    if (kind != 7)
        MCSS_SetTextureTransAdrs(work->sys, 7 << 16);
    MCSS_SetPaletteTransAdrs(work->sys, 1 << 14);
    MCSS_SetOrthoMode(work->sys);
    return work;
}

void INTRO_MCSS_Delete(u8 *p)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    int i;
    for(i=0;i<8;i++)if(work->slots[i].object!=0)MCSS_Del(work->sys,work->slots[i].object);
    MCSS_Exit(work->sys);
    GFL_HEAP_Free(p);
}

void INTRO_MCSS_Main(u8 *p)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    MCSS_Main(work->sys);
    MCSS_Draw(work->sys);
}

/*
 * Enum zero preserves the clear before the indexed base add.
 */
void INTRO_MCSS_AddSlot(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    IntroVec pos = sIntroMcssDefaultPos;
    enum { Zero } zero;
    work->slots[i].object = MCSS_Add(work->sys, a, b, c, d);
    MCSS_SetScale(work->slots[i].object, (u32 *)(&pos));
    zero = Zero;
    work->slots[i].animFinished = zero;
    work->slots[i].loopAnim = 1;
    MCSS_SetAnimCallback(work->slots[i].object, (uptr)(&work->slots[i]), (uptr)((void (*)(void *, void *))INTRO_G3D_OnAnimEnd), 0);
}
