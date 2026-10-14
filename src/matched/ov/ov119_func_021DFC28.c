/*
 * function: POKETRADE_MCSS_SlideApplyOffset
 * address:  0x021DFC28
 * packet:   pkt_ov119_021DFC28
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of the parked ov119 POKETRADE_MCSS_SlideUpdate
 * (+0060) and of func_021D7130's tree.  Reads the descriptor at p->f34 +
 * 0xc*p->f08 and hands three offset-adjusted words to MCSS_SetPosition, then
 * forwards p->f08 and its own second argument to POKETRADE_NEGO_PlaySeByEvent.
 *
 * symbols:
 *   MCSS_SetPosition   0x02015C48  thumb
 *   POKETRADE_NEGO_PlaySeByEvent   0x021DFAD0  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void MCSS_SetPosition(void *p, u32 *src);
extern void POKETRADE_NEGO_PlaySeByEvent(int a0, u8 *a1);

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
} P;

void POKETRADE_MCSS_SlideApplyOffset(P *p, int a1)
{
    u32 vec[3];
    int idx = p->f08;
    u32 *e = (u32 *)(p->f34 + idx * 0xc);

    vec[0] = e[0] + p->f1c;
    vec[1] = e[1] + p->f20;
    vec[2] = e[2] + p->f24;
    MCSS_SetPosition((void *)p->f00, vec);
    POKETRADE_NEGO_PlaySeByEvent(p->f08, (u8 *)a1);
}
