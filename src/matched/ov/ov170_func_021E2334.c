/*
 * function: BOX2_SEQ_StateItemMenu
 * address:  0x021E2334
 * packet:   pkt_ov170_021E2334
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorAnim 0x021EA878 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb
 *   BOX2_SEQ_PrintPromptB 0x021EBCB4 thumb
 *   d_021EF9B4 0x021EF9B4 data
 *   d_021EF950 0x021EF950 data
 *   d_021EFA10 0x021EFA10 data
 *   d_021EF918 0x021EF918 data
 *   d_021EF8EC 0x021EF8EC data
 *
 * Two-step machine on the work word at 0xA194: step 0 opens the menu for
 * the current mode and fades, step 1 picks the next state from the mode.
 */

typedef short s16;

struct WinMgr;
extern void BOX2_SEQ_SetActorAnim(unsigned char *p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_SEQ_DrawFrameList(unsigned char *p, const void *e, unsigned n);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_SEQ_PrintPrompt(unsigned char *p, int sel, int kind, int i);
extern void BOX2_SEQ_PrintPromptB(unsigned char *p, int kind, int i);
extern const unsigned char d_021EF9B4[];
extern const unsigned char d_021EF950[];
extern const unsigned char d_021EFA10[];
extern const unsigned char d_021EF918[];
extern const unsigned char d_021EF8EC[];

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define TOP(p) (*(char **)(p))
#define MODE(p) (*(int *)(TOP(p) + 0x24))
#define SUB(p) (*(s16 *)(WORK(p) + 0xA16C))

int BOX2_SEQ_StateItemMenu(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        switch (MODE(p)) {
        case 1:
            BOX2_SEQ_DrawFrameList(p, d_021EF9B4, 5);
            break;
        case 0:
            BOX2_SEQ_DrawFrameList(p, d_021EF950, 5);
            break;
        case 2:
            BOX2_SEQ_DrawFrameList(p, d_021EFA10, 6);
            break;
        case 3:
            BOX2_SEQ_SetActorAnim(p, SUB(p));
            break;
        case 4:
            BOX2_SEQ_DrawFrameList(p, d_021EF918, 4);
            break;
        case 5:
            BOX2_SEQ_ShowWindowObject(WORK(p), 0x1B);
            BOX2_SEQ_DrawFrameList(p, d_021EF8EC, 2);
            break;
        }
        if (*(unsigned char *)(WORK(p) + 0xA170) == 1) {
            *(unsigned char *)(WORK(p) + 0xA170) = 0;
            if (MODE(p) == 3) {
                if (p[0x16] >= 0x1E) {
                    BOX2_SEQ_SetSlotActors((char *)p, 0x82, 0);
                } else {
                    BOX2_UI_ToggleSlotPair(WORK(p), 1);
                    BOX2_SEQ_SetSlotActors((char *)p, 0x81, 0);
                }
            } else {
                if (p[0x16] >= 0x1E) {
                    BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
                } else {
                    BOX2_UI_ToggleSlotPair(WORK(p), 1);
                    BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
                }
            }
        }
        BOX2_UI_CloseListPack(MGR(p));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0xE);
    case 1:
        STEP(p) = 0;
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        BOX2_SEQ_SetWindow9(p, 0xE, 1);
        switch (MODE(p)) {
        case 1:
            BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
            return 0x2C;
        case 0:
            BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
            return 0x31;
        case 2:
            BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x11;
            return 0x1B;
        case 3:
            if (*(unsigned short *)(WORK(p) + 0xA16C) == 0)
                BOX2_SEQ_PrintPromptB(p, 0, 0x18);
            else
                BOX2_SEQ_PrintPromptB(p, 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x39;
            return 0x46;
        case 4:
            BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x23;
            return 0x27;
        case 5:
            BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
            return 0x4B;
        }
        break;
    }
    return 0xE;
}
