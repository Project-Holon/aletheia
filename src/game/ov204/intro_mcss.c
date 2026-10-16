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
 *   defaultPos 0x021C08F0 data ov204
 *   INTRO_G3D_OnAnimEnd 0x021BF7F0 thumb ov204
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_Init  0x02014B08  thumb  arm9
 *   MCSS_Add  0x020159C8  thumb  arm9
 *   MCSS_SetAnimCallback  0x02015F2C  thumb  arm9
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb  arm9
 */
#include "intro_types.h"

/* Opaque MCSS system (defined in arm9 mcss.c). */
struct McssSys;

/* Opaque source row for MCSS_Add. */
struct Sub150;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *sitePath, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void *MCSS_Init(u32 id, void *heap);

extern void MCSS_SetTextureTransAdrs(void *, unsigned int);

extern void MCSS_SetPaletteTransAdrs(char *p, unsigned int v);

extern void MCSS_SetOrthoMode(void *);

extern void MCSS_Del(void *,void *);

extern void MCSS_Exit(u8 *);

extern void MCSS_Main(char *);

extern void MCSS_Draw(struct McssSys *);

extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);

extern void MCSS_SetScale(void *p, u32 *src);

extern void INTRO_G3D_OnAnimEnd(u8 *p);

extern void MCSS_SetAnimCallback(void *, void *, void (*)(void *, void *), int);

void *INTRO_MCSS_Create(unsigned int heap, int kind);

void INTRO_MCSS_Delete(u8 *p);

void INTRO_MCSS_Main(u8 *p);

void INTRO_MCSS_AddSlot(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);

extern const char gIntroMcssSite[];

extern const IntroVec defaultPos;

void *INTRO_MCSS_Create(unsigned int heap, int kind)
{
    IntroMcssWork *work = GFL_HEAP_Alloc(heap, 108, 1, gIntroMcssSite, 98);
    work->sys = MCSS_Init(8, (void *)heap);
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
    IntroVec pos = defaultPos;
    enum { Zero } zero;
    work->slots[i].object = MCSS_Add(work->sys, a, b, c, d);
    MCSS_SetScale(work->slots[i].object, (u32 *)(&pos));
    zero = Zero;
    work->slots[i].animFinished = zero;
    work->slots[i].loopAnim = 1;
    MCSS_SetAnimCallback(work->slots[i].object, &work->slots[i], (void (*)(void *, void *))INTRO_G3D_OnAnimEnd, 0);
}
