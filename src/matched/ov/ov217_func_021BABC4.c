/*
 * function: RESEARCH_LIST_Update
 * address:  0x021BABC4
 * packet:   pkt_ov217_021BABC4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetState  0x021BB974  thumb  ov217
 *   RESEARCH_LIST_EnterSetup  0x021BACA0  thumb  ov217
 *   RESEARCH_LIST_HandleScrollInput  0x021BAE00  thumb  ov217
 *   RESEARCH_LIST_HandleSelectInput  0x021BAF70  thumb  ov217
 *   RESEARCH_LIST_UpdateOpen  0x021BB190  thumb  ov217
 *   RESEARCH_LIST_UpdateDrag  0x021BB200  thumb  ov217
 *   RESEARCH_LIST_UpdateFadeOutWait  0x021BB710  thumb  ov217
 *   RESEARCH_LIST_UpdateFadeInWait  0x021BB69C  thumb  ov217
 *   RESEARCH_LIST_UpdateShowEntry  0x021BB484  thumb  ov217
 *   RESEARCH_LIST_HandleConfirm  0x021BB2B4  thumb  ov217
 *   RESEARCH_LIST_UpdateHideEntry  0x021BB534  thumb  ov217
 *   RESEARCH_LIST_HandleCancel  0x021BB37C  thumb  ov217
 *   RESEARCH_LIST_UpdateReturn  0x021BB784  thumb  ov217
 *   RESEARCH_LIST_UpdateSaveExit  0x021BB5F4  thumb  ov217
 *   RESEARCH_LIST_EnterExit  0x021BB84C  thumb  ov217
 *   RESEARCH_LIST_GetVisible  0x021BAC90  thumb  ov217
 *   RESEARCH_LIST_UpdateCommonPaletteAnime  0x021BC5F0  thumb  ov217
 *   RESEARCH_LIST_UpdatePaletteAnimes  0x021BC5D4  thumb  ov217
 *   RESEARCH_LIST_IncStateTimer  0x021BB908  thumb  ov217
 *   RESEARCH_LIST_ProcessCommand  0x021BB94C  thumb  ov217
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct S;
extern u32 RESEARCH_LIST_GetState(void *p);
extern void RESEARCH_LIST_EnterSetup(u8 *p);
extern void RESEARCH_LIST_HandleScrollInput(u8 *p);
extern void RESEARCH_LIST_HandleSelectInput(char *p);
extern void RESEARCH_LIST_UpdateOpen(u8 *p);
extern void RESEARCH_LIST_UpdateDrag(struct S *p);
extern void RESEARCH_LIST_UpdateFadeOutWait(u8 *p);
extern void RESEARCH_LIST_UpdateFadeInWait(u8 *p);
extern void RESEARCH_LIST_UpdateShowEntry(u8 *p);
extern void RESEARCH_LIST_HandleConfirm(char *p);
extern void RESEARCH_LIST_UpdateHideEntry(u8 *p);
extern void RESEARCH_LIST_HandleCancel(char *p);
extern void RESEARCH_LIST_UpdateReturn(struct S *p);
extern void RESEARCH_LIST_UpdateSaveExit(u8 *p);
extern void RESEARCH_LIST_EnterExit(u8 *p);
extern u32 RESEARCH_LIST_GetVisible(void *p);
extern void RESEARCH_LIST_UpdateCommonPaletteAnime(u8 *a0);
extern void RESEARCH_LIST_UpdatePaletteAnimes(int *p);
extern void CLACT_DrawSystem(void);
extern void RESEARCH_LIST_IncStateTimer(void *);
extern void RESEARCH_LIST_ProcessCommand(u32 a0);

void RESEARCH_LIST_Update(void *self)
{
    switch (RESEARCH_LIST_GetState(self)) {
    case 0: RESEARCH_LIST_EnterSetup(self); break;
    case 1: RESEARCH_LIST_HandleScrollInput(self); break;
    case 2: RESEARCH_LIST_HandleSelectInput(self); break;
    case 3: RESEARCH_LIST_UpdateOpen(self); break;
    case 4: RESEARCH_LIST_UpdateDrag(self); break;
    case 6: RESEARCH_LIST_UpdateFadeInWait(self); break;
    case 5: RESEARCH_LIST_UpdateFadeOutWait(self); break;
    case 7: RESEARCH_LIST_UpdateShowEntry(self); break;
    case 8: RESEARCH_LIST_HandleConfirm(self); break;
    case 9: RESEARCH_LIST_UpdateHideEntry(self); break;
    case 10: RESEARCH_LIST_HandleCancel(self); break;
    case 11: RESEARCH_LIST_UpdateReturn(self); break;
    case 12: RESEARCH_LIST_UpdateSaveExit(self); break;
    case 13: RESEARCH_LIST_EnterExit(self); break;
    case 14: break;
    }
    if (!RESEARCH_LIST_GetVisible(self)) {
        RESEARCH_LIST_UpdateCommonPaletteAnime(self);
        RESEARCH_LIST_UpdatePaletteAnimes(self);
        CLACT_DrawSystem();
    }
    RESEARCH_LIST_IncStateTimer(self);
    RESEARCH_LIST_ProcessCommand((u32)self);
}
