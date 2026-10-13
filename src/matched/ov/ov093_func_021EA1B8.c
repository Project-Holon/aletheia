/*
 * function: BTLV_CORE_StartHitAnim
 * address:  0x021EA1B8
 * packet:   pkt_ov093_021EA1B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_CORE_ProcHitAnim  0x021EA230  thumb  ov093
 */
#include "../include/Obj07843.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[4];
    u8 *f04;
    u8 pad08[0x1c - 8];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern int BTLV_CORE_ProcHitAnim(int *st, char *ctx);

void BTLV_CORE_StartHitAnim(struct S *s, u32 a, int b, int c)
{
    u8 *t;

    if (BTL_CLIENT_IsMainStepActive(s->f04) == 0) {
        t = BTLV_CORE_GetTaskWork((u8 *)s, 0xc);
        ((struct Obj07843 *)t)->f4 = c;
        t[0xa] = b;
        ((struct Obj07843 *)t)->f8 = 0;
        ((struct Obj07843 *)t)->f0 = a;
        s->f1c = 0;
        s->f20 = (u32)BTLV_CORE_ProcHitAnim;
        s->f24 = s;
        s->f28 = 0;
    }
}
