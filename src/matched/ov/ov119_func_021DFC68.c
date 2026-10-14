/*
 * function: POKETRADE_MCSS_SlideUpdate
 * address:  0x021DFC68
 * packet:   pkt_ov119_021DFC68
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02 lane R1: the register shift (r2/r3 instead of r1/r2) was the incoming r1 kept
 * live: the function takes a second argument and forwards it to POKETRADE_MCSS_SlideApplyOffset (p, a1), whose
 * matched definition reads r1. Callers in ov118 pass two arguments.
 *
 * symbols:
 *   MCSS_GetPosition    0x02015C30  thumb
 *   MCSS_SetPosition    0x02015C48  thumb
 *   POKETRADE_MCSS_SlideApplyOffset    0x021DFC28  thumb  ov119
 *   POKETRADE_MCSS_SlideInterpolate    0x021DFBF0  thumb  ov119
 *   _s32_to_float    0x0209BDBC  arm
 *   __fdiv           0x0209CE10  arm
 *   __fmul           0x0209C77C  arm
 *   _fmul            0x0209C77C  arm
 *   _f2s             0x0209C494  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00826.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void POKETRADE_MCSS_SlideApplyOffset(void *, int);
extern u32 POKETRADE_MCSS_SlideInterpolate(u32, u32, void *, int);
extern float _s32_to_float(s32);
extern float __fdiv(float, float);
extern float __fmul(float, float);
extern s32 _f2s(float);

void POKETRADE_MCSS_SlideUpdate(void *p, int a1)
{
    u32 vec[6];
    s32 k, next, m;

    if (p == 0)
        return;
    k = *(s32 *)&((struct Obj00826 *)p)->f8;
    next = k + 1;
    m = ((struct Obj00826 *)p)->f4;
    *(s32 *)&((struct Obj00826 *)p)->f8 = next;
    if (m < next)
        return;
    if (m != next) {
        if (((struct Obj00826 *)p)->f34 != 0) {
            POKETRADE_MCSS_SlideApplyOffset(p, a1);
            return;
        }
        MCSS_GetPosition((void *)(((struct Obj00826 *)p)->f0), &vec[0]);
        vec[3] = POKETRADE_MCSS_SlideInterpolate(((struct Obj00826 *)p)->f1C, ((struct Obj00826 *)p)->f28, p, 0);
        if (((struct Obj00826 *)p)->f16 != 0) {
            float q = 374.0f * __fdiv(_s32_to_float((s32)(vec[0] - vec[3])), 4096.0f);
            ((struct Obj00826 *)p)->f14 -= (u16)_f2s(q);
        }
        vec[4] = POKETRADE_MCSS_SlideInterpolate(((struct Obj00826 *)p)->f20, ((struct Obj00826 *)p)->f2C, p, 1);
        vec[5] = POKETRADE_MCSS_SlideInterpolate(((struct Obj00826 *)p)->f24, ((struct Obj00826 *)p)->f30, p, 0);
        MCSS_SetPosition((void *)(((struct Obj00826 *)p)->f0), &vec[3]);
        return;
    }
    MCSS_SetPosition((void *)(((struct Obj00826 *)p)->f0), (u32 *)((char *)p + 0x28));
}
