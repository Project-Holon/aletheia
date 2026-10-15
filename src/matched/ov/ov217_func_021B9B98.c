/*
 * function: RESEARCH_TOP_InitListObject
 * address: 0x021B9B98
 * packet: pkt_ov217_021B9B98
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021B9C52..021B9C54 zero alignment padding.
 * symbols:
 *   RESEARCH_TOP_CreateCommandQueue 0x021BA67C thumb ov217
 *   RESEARCH_TOP_CreateFont 0x021BA5BC thumb ov217
 *   RESEARCH_TOP_CreateMessages 0x021BA5F8 thumb ov217
 *   RESEARCH_TOP_InitPaletteRows 0x021BA63C thumb ov217
 *   RESEARCH_TOP_InitSelection 0x021BA560 thumb ov217
 *   RESEARCH_TOP_InitOverlayBackgrounds 0x021BA698 thumb ov217
 *   RESEARCH_TOP_LoadBackground6 0x021BA768 thumb ov217
 *   RESEARCH_TOP_UpdateBackground7 0x021BA7B8 thumb ov217
 *   RESEARCH_TOP_LoadBackground2 0x021BA7E0 thumb ov217
 *   RESEARCH_TOP_UpdateBackground3 0x021BA830 thumb ov217
 *   RESEARCH_TOP_CreateLabels 0x021BA86C thumb ov217
 *   RESEARCH_TOP_RegisterEntryResources 0x021BA910 thumb ov217
 *   RESEARCH_TOP_RegisterCursorResources 0x021BA978 thumb ov217
 *   RESEARCH_TOP_CreateUnits 0x021BA9FC thumb ov217
 *   RESEARCH_TOP_CreateActor 0x021BAA48 thumb ov217
 *   RESEARCH_TOP_CreatePaletteAnime 0x021BAAD8 thumb ov217
 *   RESEARCH_TOP_BindPaletteAnime 0x021BAB0C thumb ov217
 *   RESEARCH_TOP_RestartNetwork 0x021BAB70 thumb ov217
 *   RESEARCH_TOP_RegisterVBlank 0x021BAB58 thumb ov217
 *   RESEARCH_TOP_IsSelectionValid 0x021BA3B4 thumb ov217
 *   RESEARCH_TOP_SetupTextLabel 0x021BA2FC thumb ov217
 *   RESEARCH_TOP_GetTransitionKind 0x021BA19C thumb ov217
 *   RESEARCH_TOP_PushCommand 0x021BA144 thumb ov217
 *   RESEARCH_TOP_DrawSelector 0x021BA284 thumb ov217
 *   RESEARCH_TOP_StartEntryPaletteAnime 0x021BA3E8 thumb ov217
 *   RESEARCH_TOP_FadeIn 0x021BA354 thumb ov217
 *   RESEARCH_TOP_SetCommandReady 0x021BA150 thumb ov217
 * Original reloads p before 7B8/830/BAB58 despite their unused entry r0.
 * BA144 visibly receives classification in r1; retain that argument.
 */
#include "../include/Obj01785.h"
extern void RESEARCH_TOP_CreateCommandQueue(unsigned);
extern void RESEARCH_TOP_CreateFont(unsigned);
extern void RESEARCH_TOP_CreateMessages(char *self);
typedef unsigned char  u8;
extern void RESEARCH_TOP_InitPaletteRows(u8 *self);
extern void RESEARCH_TOP_InitSelection(char *);
extern void RESEARCH_TOP_InitOverlayBackgrounds(char *);
extern void RESEARCH_TOP_LoadBackground6(char *);
extern unsigned RESEARCH_TOP_UpdateBackground7(void *);
extern void RESEARCH_TOP_LoadBackground2(char *);
extern unsigned RESEARCH_TOP_UpdateBackground3(void *);
extern void RESEARCH_TOP_CreateLabels(char *);
struct Context;
extern void RESEARCH_TOP_RegisterEntryResources(struct Context *);
extern void RESEARCH_TOP_RegisterCursorResources(struct Context *);
extern void RESEARCH_TOP_CreateUnits(char *self);
extern void RESEARCH_TOP_CreateActor(char *);
extern void RESEARCH_TOP_CreatePaletteAnime(char *);
extern void RESEARCH_TOP_BindPaletteAnime(char *self);
extern void RESEARCH_TOP_RestartNetwork(unsigned);
extern void RESEARCH_TOP_RegisterVBlank(void *);
extern unsigned RESEARCH_TOP_IsSelectionValid(unsigned,unsigned);
extern unsigned RESEARCH_TOP_SetupTextLabel(unsigned);
extern unsigned RESEARCH_TOP_GetTransitionKind(unsigned char *);
extern void RESEARCH_TOP_PushCommand(unsigned char *,unsigned);
extern void RESEARCH_TOP_DrawSelector(int sel);
extern void RESEARCH_TOP_StartEntryPaletteAnime(char *self, int i);
extern void RESEARCH_TOP_FadeIn(void);
extern void RESEARCH_TOP_SetCommandReady(void *);
void RESEARCH_TOP_InitListObject(char *p)
{
    unsigned kind;
    RESEARCH_TOP_CreateCommandQueue((unsigned)p);RESEARCH_TOP_CreateFont((unsigned)p);
    RESEARCH_TOP_CreateMessages(p);RESEARCH_TOP_InitPaletteRows((u8 *)p);RESEARCH_TOP_InitSelection(p);
    RESEARCH_TOP_InitOverlayBackgrounds(p);RESEARCH_TOP_LoadBackground6(p);RESEARCH_TOP_UpdateBackground7(p);
    RESEARCH_TOP_LoadBackground2(p);RESEARCH_TOP_UpdateBackground3(p);RESEARCH_TOP_CreateLabels(p);
    RESEARCH_TOP_RegisterEntryResources((struct Context *)p);RESEARCH_TOP_RegisterCursorResources((struct Context *)p);
    RESEARCH_TOP_CreateUnits(p);RESEARCH_TOP_CreateActor(p);RESEARCH_TOP_CreatePaletteAnime(p);
    RESEARCH_TOP_BindPaletteAnime(p);RESEARCH_TOP_RestartNetwork((unsigned)p);RESEARCH_TOP_RegisterVBlank(p);
    if (RESEARCH_TOP_IsSelectionValid((unsigned)p,0)==0)RESEARCH_TOP_SetupTextLabel((unsigned)p);
    kind=RESEARCH_TOP_GetTransitionKind((unsigned char *)p);
    RESEARCH_TOP_PushCommand((unsigned char *)p,RESEARCH_TOP_GetTransitionKind((unsigned char *)p));
    if (kind==2) {RESEARCH_TOP_DrawSelector(((struct Obj01785 *)p)->f28);RESEARCH_TOP_StartEntryPaletteAnime((char *)((unsigned)p),0);}
    RESEARCH_TOP_FadeIn();RESEARCH_TOP_SetCommandReady(p);
}
