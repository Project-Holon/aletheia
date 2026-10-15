/*
 * function: RESEARCH_LIST_UpdateDrag
 * address: 0x021BB200
 * packet: pkt_ov217_021BB200
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * symbols:
 *   RESEARCH_LIST_GetSubState 0x021BB98C thumb ov217
 *   RESEARCH_LIST_DampMomentum 0x021BC280 thumb ov217
 *   RESEARCH_LIST_SetMomentumDirection 0x021BC2B8 thumb ov217
 *   RESEARCH_LIST_IncSubState 0x021BB990 thumb ov217
 *   RESEARCH_LIST_GetScrollYFromPosition 0x021BC200 thumb ov217
 *   RESEARCH_LIST_SetScrollTarget 0x021BC30C thumb ov217
 *   RESEARCH_LIST_SetListScroll 0x021BC380 thumb ov217
 *   RESEARCH_LIST_UpdateTouchRects 0x021BC43C thumb ov217
 *   RESEARCH_LIST_UpdateScrollbarActor 0x021BC168 thumb ov217
 *   RESEARCH_LIST_UpdateEntryActor 0x021BC014 thumb ov217
 *   RESEARCH_LIST_ComputeMomentum 0x021BC274 thumb ov217
 *   RESEARCH_LIST_UpdateMomentum 0x021BC250 thumb ov217
 *   RESEARCH_LIST_IsMomentumActive 0x021BC264 thumb ov217
 *   RESEARCH_LIST_PrintCurrentEntry 0x021BC06C thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_ScrollSelectionIntoView 0x021BBA30 thumb ov217
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 */
struct S { char pad0[0x34]; int f34; char pad38[0x14]; int f4c; };
extern unsigned int TOUCHPANEL_GetPointCont(unsigned int *outA, unsigned int *outB);
typedef unsigned int   u32;
extern u32 RESEARCH_LIST_GetSubState(void *p);
extern void RESEARCH_LIST_DampMomentum(struct S *p);
extern void RESEARCH_LIST_SetMomentumDirection(void *p);
extern void RESEARCH_LIST_IncSubState(void *p);
extern int RESEARCH_LIST_GetScrollYFromPosition(void *p, int position);
extern void RESEARCH_LIST_SetScrollTarget(struct S *p, int v);
extern void RESEARCH_LIST_SetListScroll(struct S *p);
typedef unsigned char  u8;
extern void RESEARCH_LIST_UpdateTouchRects(u8 *p);
extern void RESEARCH_LIST_UpdateScrollbarActor(unsigned int p);
extern void RESEARCH_LIST_UpdateEntryActor(u8 *p);
extern void RESEARCH_LIST_ComputeMomentum(void *p);
extern void RESEARCH_LIST_UpdateMomentum(void *p);
extern int RESEARCH_LIST_IsMomentumActive(void *p);
extern int RESEARCH_LIST_PrintCurrentEntry(char *p);
extern void RESEARCH_LIST_SetCommandReady(void *p);
extern void RESEARCH_LIST_ScrollSelectionIntoView(u8 *p);

void RESEARCH_LIST_UpdateDrag(struct S *p)
{
    int a;
    int b;
    int r = TOUCHPANEL_GetPointCont((unsigned int *)(&a), (unsigned int *)(&b));
    int m = RESEARCH_LIST_GetSubState(p);
    switch (m) {
    case 0:
    {
        if (r == 0) {
            RESEARCH_LIST_DampMomentum(p);
            RESEARCH_LIST_SetMomentumDirection(p);
            RESEARCH_LIST_IncSubState(p);
        } else {
            RESEARCH_LIST_SetScrollTarget(p, RESEARCH_LIST_GetScrollYFromPosition(p, b));
            RESEARCH_LIST_SetListScroll(p);
            RESEARCH_LIST_UpdateTouchRects((u8 *)p);
            RESEARCH_LIST_UpdateScrollbarActor((unsigned int)p);
            RESEARCH_LIST_UpdateEntryActor((u8 *)p);
            RESEARCH_LIST_ComputeMomentum(p);
        }
        break;
    }
    case 1:
    {
        RESEARCH_LIST_SetScrollTarget(p, p->f34 + p->f4c);
        RESEARCH_LIST_SetListScroll(p);
        RESEARCH_LIST_UpdateTouchRects((u8 *)p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned int)p);
        RESEARCH_LIST_UpdateEntryActor((u8 *)p);
        RESEARCH_LIST_UpdateMomentum(p);
        if (RESEARCH_LIST_IsMomentumActive(p) == 0) {
            RESEARCH_LIST_PrintCurrentEntry((char *)p);
            RESEARCH_LIST_SetCommandReady(p);
        }
        break;
    }
    }
    RESEARCH_LIST_ScrollSelectionIntoView((u8 *)p);
}
