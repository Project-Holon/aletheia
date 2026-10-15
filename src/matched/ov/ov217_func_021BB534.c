/*
 * function: RESEARCH_LIST_UpdateHideEntry
 * address: 0x021BB534
 * packet: pkt_ov217_021BB534
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BB910 retains visibly supplied r1=10 through C0E4C to C0EA4.
 * symbols:
 *   RESEARCH_LIST_GetSubState 0x021BB98C thumb ov217
 *   RESEARCH_LIST_SetSelectionModeField 0x021BBD14 thumb ov217
 *   RESEARCH_LIST_SetEntryPaletteActive 0x021BBD28 thumb ov217
 *   RESEARCH_LIST_SetEntryPaletteIdle 0x021BBD18 thumb ov217
 *   RESEARCH_LIST_StartListPaletteAnime 0x021BC580 thumb ov217
 *   RESEARCH_LIST_SetOamEnabled 0x021BC72C thumb ov217
 *   BgTextLabel_SetPalette 0x021C1038 thumb ov217
 *   RESEARCH_LIST_ShowEntryPalette 0x021BC4B4 thumb ov217
 *   RESEARCH_LIST_ComputeCenterScroll 0x021BBBE4 thumb ov217
 *   RESEARCH_LIST_IncSubState 0x021BB990 thumb ov217
 *   RESEARCH_LIST_StepScrollAnim 0x021BC2D8 thumb ov217
 *   RESEARCH_LIST_ApplyScrollRegs 0x021BC338 thumb ov217
 *   RESEARCH_LIST_UpdateTouchRects 0x021BC43C thumb ov217
 *   RESEARCH_LIST_UpdateScrollbarActor 0x021BC168 thumb ov217
 *   RESEARCH_LIST_UpdateEntryActor 0x021BC014 thumb ov217
 *   RESEARCH_LIST_UpdateWindowMask 0x021BBF60 thumb ov217
 *   RESEARCH_LIST_IsScrollAnimDone 0x021BC2FC thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_GetSubState(void *);
extern void RESEARCH_LIST_SetSelectionModeField(void *, unsigned);
extern void RESEARCH_LIST_SetEntryPaletteActive(int, int);
extern void RESEARCH_LIST_SetEntryPaletteIdle(int, int);
extern void RESEARCH_LIST_StartListPaletteAnime(char *p, int i);
extern void RESEARCH_LIST_SetOamEnabled(u8 *, unsigned, u8 *);
extern void BgTextLabel_SetPalette(u8 *p, u8 palette);
extern void RESEARCH_LIST_ShowEntryPalette(char *);
extern void RESEARCH_LIST_ComputeCenterScroll(u8 *);
extern void RESEARCH_LIST_IncSubState(void *);
struct S;
extern void RESEARCH_LIST_StepScrollAnim(struct S *p);
extern void RESEARCH_LIST_ApplyScrollRegs(u8 *);
extern void RESEARCH_LIST_UpdateTouchRects(u8 *);
extern void RESEARCH_LIST_UpdateScrollbarActor(unsigned);
extern void RESEARCH_LIST_UpdateEntryActor(u8 *);
extern void RESEARCH_LIST_UpdateWindowMask(u8 *);
extern int RESEARCH_LIST_IsScrollAnimDone(void *);
extern void RESEARCH_LIST_SetCommandReady(void *);
extern void RESEARCH_LIST_PushCommand(u8 *, unsigned);
void RESEARCH_LIST_UpdateHideEntry(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_SetSelectionModeField(p, 0);
        RESEARCH_LIST_SetEntryPaletteActive((int)p, 1);
        RESEARCH_LIST_SetEntryPaletteIdle((int)p, 0);
        RESEARCH_LIST_StartListPaletteAnime((char *)((unsigned)p), 3);
        RESEARCH_LIST_SetOamEnabled(p, 0, (u8 *)1);
        RESEARCH_LIST_SetOamEnabled(p, 1, (u8 *)1);
        RESEARCH_LIST_SetOamEnabled(p, 2, (u8 *)1);
        if (((struct Obj00025 *)p)->f15C == 0) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            RESEARCH_LIST_ShowEntryPalette((char *)p);
        }
        RESEARCH_LIST_ComputeCenterScroll(p);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        RESEARCH_LIST_StepScrollAnim((struct S *)p);
        RESEARCH_LIST_ApplyScrollRegs(p);
        RESEARCH_LIST_UpdateTouchRects(p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned)p);
        RESEARCH_LIST_UpdateEntryActor(p);
        RESEARCH_LIST_UpdateWindowMask(p);
        if (RESEARCH_LIST_IsScrollAnimDone(p)) {
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 10);
        }
        break;
    }
}
