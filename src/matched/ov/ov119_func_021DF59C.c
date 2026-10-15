/*
 * function: POKETRADE_NEGO_StepOpenCancelMenu
 * address: 0x021DF59C
 * packet: pkt_ov119_021DF59C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gCancelMenuPos 0x021E76EC data a4
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepCancelMenuChoice 0x021DF548 thumb ov119
 */
typedef struct { int a, b; } Pair;
extern const Pair gCancelMenuPos;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_OpenTaskMenuAt(char *p, int *ids, int count, int x, int y);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_NEGO_StepCancelMenuChoice(void *);
void POKETRADE_NEGO_StepOpenCancelMenu(void *p)
{
    Pair t;
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        t = gCancelMenuPos;
        POKETRADE_SAVE_OpenTaskMenuAt(p, (int *)&t, 2, 0x20, 0xc);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepCancelMenuChoice);
    }
}
