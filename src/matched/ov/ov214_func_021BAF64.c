/*
 * unit: yes
 * function: BTL_REC_SEL_FadeMain,BTL_REC_SEL_TransferPalettes
 * address: 0x021BAF64
 * packet: pkt_ov214_021BAF64
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0202173C's third parameter is widened to the observed full-word
 *   caller payload; own u16 declaration inserted four extra truncation pairs.
 *   Both fixed-flag TU runs preserve its low-halfword colour; widening gives EXACT368.
 * extent: lead and tail-call follower 021BB0C4.
 * symbols:
 *   TCB_Main 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
#include "../include/Obj25729.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct PalAnmObj; struct S02021D50;
struct S { u8 pad[0x2D8]; void *heap; u32 unused2DC; char *anm; u32 request,state; };
struct Ctx;
extern void TCB_Main(struct Ctx *c);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern int PALANM_RequestFade(struct PalAnmObj *,u16,u32,s16,u8,u8,u16,void *);
extern void PALANM_TransferPalettes(struct S02021D50 *);
void BTL_REC_SEL_FadeMain(void *unused,struct S *p)
{
    u32 mask;
    u8 i;
    TCB_Main(p->heap);
    if (PALANM_GetFadeRequestBits(p->anm)!=0) return;
    switch (p->state) {
    case 1: p->state=2; break;
    case 3: p->state=0; break;
    }
    switch (p->request) {
    case 1:
        if (p->state==1) return;
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,1,mask,-2,16,0,0,p->heap);
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,4,mask,-2,16,0,0,p->heap);
        p->state=1;
        p->request=0;
        return;
    case 2:
        if (p->state==3) break;
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,1,mask,-2,0,16,0,p->heap);
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,4,mask,-2,0,16,0,p->heap);
        p->state=3;
        p->request=0;
        break;
    }
}
void BTL_REC_SEL_TransferPalettes(char *p)
{
    PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj25729 *)p)->f2E0);
}
