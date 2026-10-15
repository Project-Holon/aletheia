/*
 * function: RESEARCH_LIST_EnterExit
 * address: 0x021BB84C
 * packet: pkt_ov217_021BB84C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: DISPCNT read at 021BB8FA and write at 021BB900.
 * arity: C09E0/C09EC overwrite r1 before their indexed targets; BD3A4 overwrites r1=300; BCC58/BCB60 overwrite r1/r2 before 02040DA8. Omit only unused legacy trailing inputs, retain each visibly supplied context and BB910 r1=14.
 * symbols:
 *   RESEARCH_LIST_SyncToListView 0x021BC688 thumb ov217
 *   RESEARCH_LIST_UnregisterVBlank 0x021BD5E0 thumb ov217
 *   RESEARCH_LIST_RestorePaletteAnime 0x021BD56C thumb ov217
 *   RESEARCH_LIST_DestroyPaletteAnime 0x021BD520 thumb ov217
 *   RESEARCH_COMMON_StopPaletteAnime 0x021C09E0 thumb ov217
 *   RESEARCH_COMMON_RestorePaletteAnime 0x021C09EC thumb ov217
 *   RESEARCH_LIST_DeletePalAnm 0x021BD4CC thumb ov217
 *   RESEARCH_LIST_DeleteBmps 0x021BD370 thumb ov217
 *   RESEARCH_LIST_DeleteOamObjects 0x021BD458 thumb ov217
 *   RESEARCH_LIST_DeleteOamSys 0x021BD3A4 thumb ov217
 *   RESEARCH_LIST_DeleteActors 0x021BD05C thumb ov217
 *   RESEARCH_LIST_DeleteUnits 0x021BCF98 thumb ov217
 *   RESEARCH_LIST_ReleaseEntryResources 0x021BCE5C thumb ov217
 *   RESEARCH_LIST_ReleaseCursorResources 0x021BCF20 thumb ov217
 *   RESEARCH_LIST_DestroyLabels 0x021BCD90 thumb ov217
 *   RESEARCH_LIST_ShowBackground3 0x021BCC58 thumb ov217
 *   RESEARCH_LIST_DummyBg3 0x021BCBCC thumb ov217
 *   RESEARCH_LIST_DummyListBg 0x021BCC3C thumb ov217
 *   RESEARCH_LIST_ShowBackground7 0x021BCB60 thumb ov217
 *   RESEARCH_LIST_DummyBg7 0x021BCB44 thumb ov217
 *   RESEARCH_LIST_ExitBackgrounds 0x021BCAC0 thumb ov217
 *   RESEARCH_LIST_DeleteMessages 0x021BC924 thumb ov217
 *   RESEARCH_LIST_DeleteFont 0x021BC8D8 thumb ov217
 *   RESEARCH_LIST_SetActive 0x021BB940 thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
extern void RESEARCH_LIST_SyncToListView(char *);
extern void RESEARCH_LIST_UnregisterVBlank(unsigned);
extern void RESEARCH_LIST_RestorePaletteAnime(int *);
extern void RESEARCH_LIST_DestroyPaletteAnime(int *);
extern void RESEARCH_COMMON_StopPaletteAnime(unsigned);
extern void RESEARCH_COMMON_RestorePaletteAnime(unsigned);
extern unsigned RESEARCH_LIST_DeletePalAnm(unsigned);
extern void RESEARCH_LIST_DeleteBmps(int *);
extern void RESEARCH_LIST_DeleteOamObjects(int *);
extern void RESEARCH_LIST_DeleteOamSys(u8 *);
extern void RESEARCH_LIST_DeleteActors(int *);
extern void RESEARCH_LIST_DeleteUnits(int *);
extern unsigned RESEARCH_LIST_ReleaseEntryResources(unsigned);
extern unsigned RESEARCH_LIST_ReleaseCursorResources(unsigned);
extern void RESEARCH_LIST_DestroyLabels(u8 *);
extern void RESEARCH_LIST_ShowBackground3(unsigned);
extern void RESEARCH_LIST_DummyBg3(u8 *);
extern void RESEARCH_LIST_DummyListBg(u8 *);
extern void RESEARCH_LIST_ShowBackground7(unsigned);
extern void RESEARCH_LIST_DummyBg7(u8 *);
extern unsigned RESEARCH_LIST_ExitBackgrounds(u8 *);
extern void RESEARCH_LIST_DeleteMessages(int *);
extern void RESEARCH_LIST_DeleteFont(u8 *);
extern void RESEARCH_LIST_SetActive(void *, unsigned);
extern void RESEARCH_LIST_SetCommandReady(void *);
extern void RESEARCH_LIST_PushCommand(u8 *, unsigned);
void RESEARCH_LIST_EnterExit(u8 *p)
{
    RESEARCH_LIST_SyncToListView((char *)p);
    RESEARCH_LIST_UnregisterVBlank((unsigned)p);
    RESEARCH_LIST_RestorePaletteAnime((int *)p);
    RESEARCH_LIST_DestroyPaletteAnime((int *)p);
    RESEARCH_COMMON_StopPaletteAnime(*(unsigned *)p);
    RESEARCH_COMMON_RestorePaletteAnime(*(unsigned *)p);
    RESEARCH_LIST_DeletePalAnm((unsigned)p);
    RESEARCH_LIST_DeleteBmps((int *)p);
    RESEARCH_LIST_DeleteOamObjects((int *)p);
    RESEARCH_LIST_DeleteOamSys(p);
    RESEARCH_LIST_DeleteActors((int *)p);
    RESEARCH_LIST_DeleteUnits((int *)p);
    RESEARCH_LIST_ReleaseEntryResources((unsigned)p);
    RESEARCH_LIST_ReleaseCursorResources((unsigned)p);
    RESEARCH_LIST_DestroyLabels(p);
    RESEARCH_LIST_ShowBackground3((unsigned)p);
    RESEARCH_LIST_DummyBg3(p);
    RESEARCH_LIST_DummyListBg(p);
    RESEARCH_LIST_ShowBackground7((unsigned)p);
    RESEARCH_LIST_DummyBg7(p);
    RESEARCH_LIST_ExitBackgrounds(p);
    RESEARCH_LIST_DeleteMessages((int *)p);
    RESEARCH_LIST_DeleteFont(p);
    RESEARCH_LIST_SetActive(p, 0);
    RESEARCH_LIST_SetCommandReady(p);
    RESEARCH_LIST_PushCommand(p, 14);
    ((struct Obj00025 *)p)->f164 = 1;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
}
