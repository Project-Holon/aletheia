/*
 * function: RESEARCH_TOP_AdvanceListScroll
 * address:  0x021BA078
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_TOP_SetCommandReady  0x021BA150  thumb  ov217
 *   RESEARCH_TOP_GetStateTimer  0x021BA37C  thumb  ov217
 *   RESEARCH_TOP_GetStateTimerLimit  0x021BA384  thumb  ov217
 *
 * Steps the record through RESEARCH_TOP_SetCommandReady while the running count is below
 * RESEARCH_TOP_GetStateTimer().
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_TOP_SetCommandReady(void *p);
extern u32 RESEARCH_TOP_GetStateTimer(void *p);
extern u32 RESEARCH_TOP_GetStateTimerLimit(void *p);
void RESEARCH_TOP_AdvanceListScroll(u32 a0)
{
    u32 v1 = RESEARCH_TOP_GetStateTimerLimit((void *)a0);
    if (v1 < RESEARCH_TOP_GetStateTimer((void *)a0)) {
    RESEARCH_TOP_SetCommandReady((void *)a0);
    }
}
