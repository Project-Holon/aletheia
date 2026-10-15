/*
 * function: RESEARCH_LIST_UpdateReturn
 * address: 0x021BB784
 * packet: pkt_ov217_021BB784
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetSubState 0x021BB98C thumb ov217
 *   RESEARCH_LIST_IncSubState 0x021BB990 thumb ov217
 *   RESEARCH_LIST_ComputeReturnScroll 0x021BBB60 thumb ov217
 *   RESEARCH_LIST_StepScrollAnim 0x021BC2D8 thumb ov217
 *   RESEARCH_LIST_ApplyScrollRegs 0x021BC338 thumb ov217
 *   RESEARCH_LIST_UpdateTouchRects 0x021BC43C thumb ov217
 *   RESEARCH_LIST_UpdateScrollbarActor 0x021BC168 thumb ov217
 *   RESEARCH_LIST_UpdateEntryActor 0x021BC014 thumb ov217
 *   RESEARCH_LIST_UpdateWindowMask 0x021BBF60 thumb ov217
 *   RESEARCH_LIST_IsScrollAnimDone 0x021BC2FC thumb ov217
 *   RESEARCH_LIST_IsListPaletteAnimeRunning 0x021BC5B8 thumb ov217
 *   RESEARCH_LIST_SetOamEnabled 0x021BC72C thumb ov217
 *   RESEARCH_LIST_HideEntryPalette 0x021BC50C thumb ov217
 *   RESEARCH_LIST_IsPaletteFadeDone 0x021BC55C thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   BgTextLabel_SetPalette 0x021C1038 thumb ov217
 */
struct S { char pad0[0x32]; unsigned char f32; char pad33[0x81]; void *arr[8]; };
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 RESEARCH_LIST_GetSubState(void *p);
extern void RESEARCH_LIST_IncSubState(void *p);
extern void RESEARCH_LIST_ComputeReturnScroll(u8 *p);
extern void RESEARCH_LIST_StepScrollAnim(struct S *p);
extern void RESEARCH_LIST_ApplyScrollRegs(u8 *p);
extern void RESEARCH_LIST_UpdateTouchRects(u8 *p);
extern void RESEARCH_LIST_UpdateScrollbarActor(unsigned int p);
extern void RESEARCH_LIST_UpdateEntryActor(u8 *p);
extern void RESEARCH_LIST_UpdateWindowMask(u8 *p);
extern int RESEARCH_LIST_IsScrollAnimDone(void *p);
extern u32 RESEARCH_LIST_IsListPaletteAnimeRunning(u32 a0, u32 a1);
extern void RESEARCH_LIST_SetOamEnabled(u8 *a0, u32 a1, u8 *a2);
extern void RESEARCH_LIST_HideEntryPalette(char *p);
extern u32 RESEARCH_LIST_IsPaletteFadeDone(u32 a0);
extern void RESEARCH_LIST_SetCommandReady(void *p);
extern void BgTextLabel_SetPalette(u8 *p, u8 palette);

void RESEARCH_LIST_UpdateReturn(struct S *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_ComputeReturnScroll((u8 *)p);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        RESEARCH_LIST_StepScrollAnim(p);
        RESEARCH_LIST_ApplyScrollRegs((u8 *)p);
        RESEARCH_LIST_UpdateTouchRects((u8 *)p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned int)p);
        RESEARCH_LIST_UpdateEntryActor((u8 *)p);
        RESEARCH_LIST_UpdateWindowMask((u8 *)p);
        if (RESEARCH_LIST_IsScrollAnimDone(p) != 0) {
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsListPaletteAnimeRunning((u32)p, 5) != 0) {
            RESEARCH_LIST_SetOamEnabled((u8 *)p, 0, 0);
            RESEARCH_LIST_SetOamEnabled((u8 *)p, 1, 0);
            RESEARCH_LIST_SetOamEnabled((u8 *)p, 2, 0);
            RESEARCH_LIST_UpdateWindowMask((u8 *)p);
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 3:
        if (RESEARCH_LIST_IsPaletteFadeDone((u32)p) != 0) {
            BgTextLabel_SetPalette(p->arr[p->f32], 15);
            RESEARCH_LIST_SetCommandReady(p);
        }
        break;
    }
}
