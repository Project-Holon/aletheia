/*
 * function: POKETRADE_NEGO_StepOpenDeclineMenu
 * address:  0x021DE9E8
 * packet:   pkt_ov119_021DE9E8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone  0x021E12AC  thumb  ov119
 *   gDeclineMenuPos     0x021E76DC  data  a4
 *   POKETRADE_SAVE_OpenTaskMenuAt  0x021E131C  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepDeclineMenuChoice  0x021DE988  thumb  ov119
 */

typedef struct {
    int a;
    int b;
} Pair;

extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern const Pair gDeclineMenuPos;
extern void POKETRADE_SAVE_OpenTaskMenuAt(char *p, int *ids, int count, int x, int y);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepDeclineMenuChoice(char *p);

void POKETRADE_NEGO_StepOpenDeclineMenu(void *p)
{
    Pair t;
    if (POKETRADE_SAVE_IsMessagePrintDone(p) != 0) {
        t = gDeclineMenuPos;
        POKETRADE_SAVE_OpenTaskMenuAt(p, (int *)&t, 2, 0x20, 12);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepDeclineMenuChoice);
    }
}
