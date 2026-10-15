/*
 * function: RESEARCH_LIST_UpdateFadeInWait
 * address: 0x021BB69C
 * packet: pkt_ov217_021BB69C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BB70E..021BB710 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 * symbols:
 *   RESEARCH_LIST_GetSubState 0x021BB98C thumb ov217
 *   RESEARCH_LIST_IncSubState 0x021BB990 thumb ov217
 *   RESEARCH_LIST_GetFadeWaitFrames 0x021BB948 thumb ov217
 *   RESEARCH_LIST_FadeOut 0x021BC490 thumb ov217
 *   RESEARCH_LIST_IsFadeDone 0x021BC4A0 thumb ov217
 *   RESEARCH_LIST_HideEntryPalette 0x021BC50C thumb ov217
 *   RESEARCH_LIST_IsPaletteFadeDone 0x021BC55C thumb ov217
 *   BgTextLabel_SetPalette 0x021C1038 thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_GetSubState(void *);
extern void RESEARCH_LIST_IncSubState(void *);
extern unsigned RESEARCH_LIST_GetFadeWaitFrames(u8 *);
extern void RESEARCH_LIST_FadeOut(void);
extern int RESEARCH_LIST_IsFadeDone(void);
extern void RESEARCH_LIST_HideEntryPalette(char *p);
extern unsigned RESEARCH_LIST_IsPaletteFadeDone(unsigned);
extern void BgTextLabel_SetPalette(u8 *p, u8 palette);
extern void RESEARCH_LIST_SetCommandReady(void *);
extern void RESEARCH_LIST_PushCommand(u8 *, unsigned);
void RESEARCH_LIST_UpdateFadeInWait(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        if (RESEARCH_LIST_GetFadeWaitFrames(p) < ((struct Obj00025 *)p)->f24) {
            RESEARCH_LIST_FadeOut();
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 1:
        if (RESEARCH_LIST_IsFadeDone()) {
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsPaletteFadeDone((unsigned)p)) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 13);
        }
        break;
    }
}
