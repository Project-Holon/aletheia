/*
 * file:     pokemontrade_mcss.c
 * unit:     yes
 * function: POKETRADE_MCSS_SlideBegin, POKETRADE_MCSS_SlideCreate, POKETRADE_MCSS_SlideCreateWithOffsets, POKETRADE_MCSS_SlideInterpolate, POKETRADE_MCSS_SlideApplyOffset, POKETRADE_MCSS_SlideUpdate, POKETRADE_MCSS_StopAnimation
 * address:  0x021DFB4C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokemontrade_proc.c, pokemontrade_3d.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MCSS_GetPosition   0x02015C30  thumb
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   MCSS_SetPosition   0x02015C48  thumb
 *   _s32_to_float    0x0209BDBC  arm
 *   __fdiv           0x0209CE10  arm
 *   _f2s             0x0209C494  arm
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   POKETRADE_NEGO_PlaySeByEvent 0x021DFAD0 thumb ov119
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fmul                        0x0209C77C  arm
 */
#include "pokemontrade_types.h"

#define P(k) (*(void **)(p+(k)))







#include "../arm9/mi_memory.h"
struct McssWork;

#include "../arm9/mcss.h"

#include "../arm9/gfl_heap_wrap.h"



#include "pokemontrade_nego.h"

void POKETRADE_MCSS_SlideBegin(McssSlide *p, void *frameCount, void *targetPos);

void *POKETRADE_MCSS_SlideCreate(void *mcss, void *frameCount, void *targetPos, u32 heapId);

void *POKETRADE_MCSS_SlideCreateWithOffsets(void *mcss, void *frameCount, void *targetPos, void *offsetTable, u16 heapId);

int POKETRADE_MCSS_SlideInterpolate(int startValue, int targetValue, McssSlide *slide, int allowWobble);

void POKETRADE_MCSS_SlideApplyOffset(McssSlide *p, int eventArg);

void POKETRADE_MCSS_SlideUpdate(McssSlide *p, int eventArg);

void POKETRADE_MCSS_StopAnimation(TradeWork *p);

extern short FX_SinCosTable_[];

void POKETRADE_MCSS_SlideBegin(McssSlide *slide, void *frameCount, void *targetPos)
{
    u8 buf[12];

    MCSS_GetPosition(slide->mcss, (u32 *)buf);
    slide->frame = 0;
    slide->frameCount = (uptr)frameCount;
    MI_CpuCopy8(targetPos, &slide->target, 0xC);
    MI_CpuCopy8(buf, &slide->start, 0xC);
}

/*
 * Addresses are Black-image addresses.
 */
void *POKETRADE_MCSS_SlideCreate(void *mcss, void *frameCount, void *targetPos, u32 heapId)
{
    McssSlide *slide = GFL_HEAP_Alloc(heapId, 0x38, 1, (const char *)0x021E80F4, 0xD2);

    slide->mcss = mcss;
    POKETRADE_MCSS_SlideBegin(slide, frameCount, targetPos);
    slide->reserved0C = 0;
    return slide;
}

/*
 * Recursive MATCH unblocker: the alloc + store callee named by the parked
 * ov118 POKETRADE_DEMO_MIDDLE_CreateOfferSlide (+0014 / +001E... it is the same pokemontrade_mcss.c
 * helper family as ov119 0x021DFB84) and by all three ov119 0x021DFBxx
 * entries.  POKETRADE_MCSS_SlideCreate is the four-argument form (line 0xD2) and this is
 * the five-argument form (a3 stored at +0x34, line 0xE7); the heap id is the
 * fifth parameter and reaches the debug allocator through its own stack home
 * (`ldrh r0,[sp,#0x20]`, a u16), which is what forces the 8-byte frame.
 *
 * Addresses are Black-image addresses.
 */
void *POKETRADE_MCSS_SlideCreateWithOffsets(void *mcss, void *frameCount, void *targetPos, void *offsetTable, u16 heapId)
{
    McssSlide *slide = GFL_HEAP_Alloc(heapId, 0x38, 1, (const char *)0x021E80F4, 0xE7);

    slide->mcss = mcss;
    POKETRADE_MCSS_SlideBegin(slide, frameCount, targetPos);
    slide->reserved0C = 0;
    slide->offsetTable = (McssSlideVec *)(uptr)offsetTable;
    return slide;
}

/*
 * Recursive MATCH unblocker: callee of the parked ov119 POKETRADE_MCSS_SlideUpdate
 * (+0044) and part of the ov118 POKETRADE_DEMO_MIDDLE_UpdateScene tree.  Interpolates between a0 and a1
 * at record stride (the difference divided by f04, scaled by f08), then, when
 * the record's f16 is set and a3 is nonzero, re-derives the position from the
 * sine table FX_SinCosTable_ with the phase f14>>4.  The divide's destination
 * only reproduces when the quotient is bound to its own local first
 * (`int q = ...; int r = q * a2->frame + a0;`).
 *
 * Addresses are Black-image addresses.
 */
int POKETRADE_MCSS_SlideInterpolate(int startValue, int targetValue, McssSlide *slide, int allowWobble)
{
    int step = (targetValue - startValue) / slide->frameCount;
    int result = step * slide->frame + startValue;

    if (slide->wobbleEnabled != 0 && allowWobble != 0)
        result = targetValue + FX_SinCosTable_[2 * (slide->wobblePhase >> 4)] * 8;
    return result;
}

/*
 * Recursive MATCH unblocker: callee of the parked ov119 POKETRADE_MCSS_SlideUpdate
 * (+0060) and of ov118 POKETRADE_DEMO_MIDDLE_UpdateScene's tree.  Reads the descriptor at p->f34 +
 * 0xc*p->f08 and hands three offset-adjusted words to MCSS_SetPosition, then
 * forwards p->f08 and its own second argument to POKETRADE_NEGO_PlaySeByEvent.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_MCSS_SlideApplyOffset(McssSlide *slide, int eventArg)
{
    u32 vec[3];
    int frameIndex = slide->frame;
    u32 *offset = (u32 *)((char *)slide->offsetTable + frameIndex * 0xc);

    vec[0] = offset[0] + slide->start.x;
    vec[1] = offset[1] + slide->start.y;
    vec[2] = offset[2] + slide->start.z;
    MCSS_SetPosition(slide->mcss, vec);
    POKETRADE_NEGO_PlaySeByEvent(slide->frame, (u8 *)eventArg);
}

/*
 * 2026-10-02 lane R1: the register shift (r2/r3 instead of r1/r2) was the incoming r1 kept
 * live: the function takes a second argument and forwards it to POKETRADE_MCSS_SlideApplyOffset (p, a1), whose
 * matched definition reads r1. Callers in ov118 pass two arguments.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_MCSS_SlideUpdate(McssSlide *slide, int eventArg)
{
    u32 vec[6];
    int prevFrame, next, frameCount;

    if (slide == 0)
        return;
    prevFrame = slide->frame;
    next = prevFrame + 1;
    frameCount = slide->frameCount;
    slide->frame = next;
    if (frameCount < next)
        return;
    if (frameCount != next) {
        if (slide->offsetTable != 0) {
            POKETRADE_MCSS_SlideApplyOffset(slide, eventArg);
            return;
        }
        MCSS_GetPosition(slide->mcss, &vec[0]);
        vec[3] = POKETRADE_MCSS_SlideInterpolate(slide->start.x, slide->target.x, slide, 0);
        if (slide->wobbleEnabled != 0) {
            float q = 374.0f * ((float)((int)(vec[0] - vec[3])) / 4096.0f);
            slide->wobblePhase -= (u16)(int)q;
        }
        vec[4] = POKETRADE_MCSS_SlideInterpolate(slide->start.y, slide->target.y, slide, 1);
        vec[5] = POKETRADE_MCSS_SlideInterpolate(slide->start.z, slide->target.z, slide, 0);
        MCSS_SetPosition(slide->mcss, &vec[3]);
        return;
    }
    MCSS_SetPosition(slide->mcss, (u32 *)&slide->target);
}

void POKETRADE_MCSS_StopAnimation(TradeWork *p)
{
    MCSS_SetAnmStopFlag(p->mcssPokemon[0]);
    p->mcssAnimStopped = 1;
}
