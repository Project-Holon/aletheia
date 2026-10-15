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
 */
#include "pokemontrade_types.h"

#define P(k) (*(void **)(p+(k)))







extern void MI_CpuCopy8(const void *,void *,unsigned);

extern void MCSS_GetPosition(void *p, u32 *out);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MCSS_SetPosition(void *p, u32 *src);

extern float _s32_to_float(int);

extern float __fdiv(float, float);

extern int _f2s(float);

extern void MCSS_SetAnmStopFlag(void *p);

void POKETRADE_NEGO_PlaySeByEvent(int a0, u8 *a1);

void POKETRADE_MCSS_SlideBegin(McssSlide *p, void *a1, void *a2);

void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);

void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId);

int POKETRADE_MCSS_SlideInterpolate(int a0, int a1, McssSlide *a2, int a3);

void POKETRADE_MCSS_SlideApplyOffset(McssSlide *p, int a1);

void POKETRADE_MCSS_SlideUpdate(McssSlide *p, int a1);

void POKETRADE_MCSS_StopAnimation(TradeWork *p);

extern short FX_SinCosTable_[];

void POKETRADE_MCSS_SlideBegin(McssSlide *p, void *a1, void *a2)
{
    u8 buf[12];

    MCSS_GetPosition(p->mcss, (u32 *)buf);
    p->frame = 0;
    p->frameCount = (u32)a1;
    MI_CpuCopy8(a2, &p->target, 0xC);
    MI_CpuCopy8(buf, &p->start, 0xC);
}

/*
 * Addresses are Black-image addresses.
 */
void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId)
{
    McssSlide *r = GFL_HEAP_Alloc(heapId, 0x38, 1, (const char *)0x021E80F4, 0xD2);

    r->mcss = a0;
    POKETRADE_MCSS_SlideBegin(r, a1, a2);
    r->fC = 0;
    return r;
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
void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId)
{
    McssSlide *r = GFL_HEAP_Alloc(heapId, 0x38, 1, (const char *)0x021E80F4, 0xE7);

    r->mcss = a0;
    POKETRADE_MCSS_SlideBegin(r, a1, a2);
    r->fC = 0;
    r->offsetTable = (McssSlideVec *)(u32)a3;
    return r;
}

/*
 * Recursive MATCH unblocker: callee of the parked ov119 POKETRADE_MCSS_SlideUpdate
 * (+0044) and part of the func_021D7130 tree.  Interpolates between a0 and a1
 * at record stride (the difference divided by f04, scaled by f08), then, when
 * the record's f16 is set and a3 is nonzero, re-derives the position from the
 * sine table FX_SinCosTable_ with the phase f14>>4.  The divide's destination
 * only reproduces when the quotient is bound to its own local first
 * (`int q = ...; int r = q * a2->frame + a0;`).
 *
 * Addresses are Black-image addresses.
 */
int POKETRADE_MCSS_SlideInterpolate(int a0, int a1, McssSlide *a2, int a3)
{
    int q = (a1 - a0) / a2->frameCount;
    int r = q * a2->frame + a0;

    if (a2->wobbleEnabled != 0 && a3 != 0)
        r = a1 + FX_SinCosTable_[2 * (a2->wobblePhase >> 4)] * 8;
    return r;
}

/*
 * Recursive MATCH unblocker: callee of the parked ov119 POKETRADE_MCSS_SlideUpdate
 * (+0060) and of func_021D7130's tree.  Reads the descriptor at p->f34 +
 * 0xc*p->f08 and hands three offset-adjusted words to MCSS_SetPosition, then
 * forwards p->f08 and its own second argument to POKETRADE_NEGO_PlaySeByEvent.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_MCSS_SlideApplyOffset(McssSlide *p, int a1)
{
    u32 vec[3];
    int idx = p->frame;
    u32 *e = (u32 *)((char *)p->offsetTable + idx * 0xc);

    vec[0] = e[0] + p->start.x;
    vec[1] = e[1] + p->start.y;
    vec[2] = e[2] + p->start.z;
    MCSS_SetPosition(p->mcss, vec);
    POKETRADE_NEGO_PlaySeByEvent(p->frame, (u8 *)a1);
}

/*
 * 2026-10-02 lane R1: the register shift (r2/r3 instead of r1/r2) was the incoming r1 kept
 * live: the function takes a second argument and forwards it to POKETRADE_MCSS_SlideApplyOffset (p, a1), whose
 * matched definition reads r1. Callers in ov118 pass two arguments.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_MCSS_SlideUpdate(McssSlide *p, int a1)
{
    u32 vec[6];
    int k, next, m;

    if (p == 0)
        return;
    k = p->frame;
    next = k + 1;
    m = p->frameCount;
    p->frame = next;
    if (m < next)
        return;
    if (m != next) {
        if (p->offsetTable != 0) {
            POKETRADE_MCSS_SlideApplyOffset(p, a1);
            return;
        }
        MCSS_GetPosition(p->mcss, &vec[0]);
        vec[3] = POKETRADE_MCSS_SlideInterpolate(p->start.x, p->target.x, p, 0);
        if (p->wobbleEnabled != 0) {
            float q = 374.0f * __fdiv(_s32_to_float((int)(vec[0] - vec[3])), 4096.0f);
            p->wobblePhase -= (u16)_f2s(q);
        }
        vec[4] = POKETRADE_MCSS_SlideInterpolate(p->start.y, p->target.y, p, 1);
        vec[5] = POKETRADE_MCSS_SlideInterpolate(p->start.z, p->target.z, p, 0);
        MCSS_SetPosition(p->mcss, &vec[3]);
        return;
    }
    MCSS_SetPosition(p->mcss, (u32 *)&p->target);
}

void POKETRADE_MCSS_StopAnimation(TradeWork *p)
{
    MCSS_SetAnmStopFlag(p->mcssPokemon[0]);
    p->mcssAnimStopped = 1;
}
