/*
 * function: RESEARCH_TOP_UpdateListObject
 * address: 0x021B9B08
 * packet: pkt_ov217_021B9B08
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_TOP_InitListObject 0x021B9B98 thumb ov217
 *   RESEARCH_TOP_HandleListInput 0x021B9C54 thumb ov217
 *   RESEARCH_TOP_HandleListInputAlt 0x021B9E44 thumb ov217
 *   RESEARCH_TOP_AdvanceListScroll 0x021BA078 thumb ov217
 *   RESEARCH_TOP_StepExitFade 0x021BA094 thumb ov217
 *   RESEARCH_TOP_CleanupListObject 0x021BA0C4 thumb ov217
 *   RESEARCH_TOP_IsListObjectDone 0x021B9B80 thumb ov217
 *   RESEARCH_TOP_CheckQuestionnaire 0x021BA1D4 thumb ov217
 *   RESEARCH_TOP_UpdateEntryPaletteAnime 0x021BA41C thumb ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   CLACT_DrawSystem 0x0204A600 arm
 *   RESEARCH_TOP_IncStateTimer 0x021BA374 thumb ov217
 *   RESEARCH_TOP_ProcessCommand 0x021BA158 thumb ov217
 * A600's complete body uses globals, no entry r0 reader or forwarder.
 */
#include "../include/Obj00511.h"
extern void RESEARCH_TOP_InitListObject(char *p);
extern void RESEARCH_TOP_HandleListInput(char *p);
extern void RESEARCH_TOP_HandleListInputAlt(char *p);
extern void RESEARCH_TOP_AdvanceListScroll(unsigned);
extern void RESEARCH_TOP_StepExitFade(unsigned);
extern unsigned RESEARCH_TOP_CleanupListObject(unsigned);
extern int RESEARCH_TOP_IsListObjectDone(void *);
extern void RESEARCH_TOP_CheckQuestionnaire(unsigned);
extern void RESEARCH_TOP_UpdateEntryPaletteAnime(int *);
extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);
extern void CLACT_DrawSystem(void);
extern void RESEARCH_TOP_IncStateTimer(void *);
extern void RESEARCH_TOP_ProcessCommand(unsigned);
void RESEARCH_TOP_UpdateListObject(char *p)
{
    switch (((struct Obj00511 *)p)->f18) {
    case 0:RESEARCH_TOP_InitListObject(p);break;
    case 1:RESEARCH_TOP_HandleListInput(p);break;
    case 2:RESEARCH_TOP_HandleListInputAlt(p);break;
    case 3:RESEARCH_TOP_AdvanceListScroll((unsigned)p);break;
    case 4:RESEARCH_TOP_StepExitFade((unsigned)p);break;
    case 5:RESEARCH_TOP_CleanupListObject((unsigned)p);break;
    case 6:return;
    }
    if (RESEARCH_TOP_IsListObjectDone(p)==0) {
        RESEARCH_TOP_CheckQuestionnaire((unsigned)p);RESEARCH_TOP_UpdateEntryPaletteAnime((int *)p);
        RESEARCH_COMMON_UpdatePaletteAnime(*(unsigned *)&((struct Obj00511 *)p)->f0);CLACT_DrawSystem();
    }
    RESEARCH_TOP_IncStateTimer(p);RESEARCH_TOP_ProcessCommand((unsigned)p);
}
