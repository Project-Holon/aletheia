/*
 * function: RESEARCH_LIST_UpdateOpen
 * address: 0x021BB190
 * packet: pkt_ov217_021BB190
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BB1FE..021BB200 is two zero bytes of alignment padding.
 * symbols:
 *   RESEARCH_LIST_GetSubState 0x021BB98C thumb ov217
 *   RESEARCH_LIST_ComputeOpenScroll 0x021BBADC thumb ov217
 *   RESEARCH_LIST_SelectEntry 0x021BBAA4 thumb ov217
 *   RESEARCH_LIST_PrintCurrentEntry 0x021BC06C thumb ov217
 *   RESEARCH_LIST_IncSubState 0x021BB990 thumb ov217
 *   RESEARCH_LIST_StepScrollAnim 0x021BC2D8 thumb ov217
 *   RESEARCH_LIST_ApplyScrollRegs 0x021BC338 thumb ov217
 *   RESEARCH_LIST_UpdateTouchRects 0x021BC43C thumb ov217
 *   RESEARCH_LIST_UpdateScrollbarActor 0x021BC168 thumb ov217
 *   RESEARCH_LIST_UpdateEntryActor 0x021BC014 thumb ov217
 *   RESEARCH_LIST_UpdateWindowMask 0x021BBF60 thumb ov217
 *   RESEARCH_LIST_IsScrollAnimDone 0x021BC2FC thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 */
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_GetSubState(void *);
extern void RESEARCH_LIST_ComputeOpenScroll(u8 *);
typedef unsigned int   u32;
extern u32 RESEARCH_LIST_SelectEntry(u32 a0, u8 a1);
extern int RESEARCH_LIST_PrintCurrentEntry(char *);
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
void RESEARCH_LIST_UpdateOpen(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_ComputeOpenScroll(p);
        RESEARCH_LIST_SelectEntry((unsigned)p, p[0x33]);
        RESEARCH_LIST_PrintCurrentEntry((char *)p);
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
            RESEARCH_LIST_UpdateWindowMask(p);
            RESEARCH_LIST_SetCommandReady(p);
        }
        break;
    }
}
