/*
 * function: RESEARCH_TOP_MainProc
 * address: 0x021B9620
 * packet: pkt_ov217_021B9620
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 * symbols:
 *   RESEARCH_TOP_UpdateNetwork 0x021B96A0 thumb ov217
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   RESEARCH_COMMON_SetInputFlag 0x021C09FC thumb ov217
 *   RESEARCH_TOP_StateIdle 0x021B97B8 thumb ov217
 *   RESEARCH_TOP_StateList 0x021B97BC thumb ov217
 *   RESEARCH_TOP_StateGraph 0x021B97F8 thumb ov217
 *   RESEARCH_TOP_StateDetail 0x021B9824 thumb ov217
 *   RESEARCH_TOP_UpdateFrameGraphic 0x021B99EC thumb ov217
 *   RESEARCH_TOP_IncFrameCount 0x021B9854 thumb ov217
 *   RESEARCH_TOP_ChangeScreen 0x021B96C8 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx;
extern void RESEARCH_TOP_UpdateNetwork(u32);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *);
extern void RESEARCH_COMMON_SetInputFlag(void *);
extern int RESEARCH_TOP_StateIdle(void *a0);
extern u32 RESEARCH_TOP_StateList(u8 *);
extern u32 RESEARCH_TOP_StateGraph(u32);
extern u32 RESEARCH_TOP_StateDetail(u32);
extern void RESEARCH_TOP_UpdateFrameGraphic(const void *p);
extern void RESEARCH_TOP_IncFrameCount(void *);
extern void RESEARCH_TOP_ChangeScreen(void *, int *, int);
int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, u32 *p)
{
    u32 next;
    RESEARCH_TOP_UpdateNetwork((u32)p);
    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)p[1]) != 0)
        RESEARCH_COMMON_SetInputFlag((void *)p[3]);
    switch (*state) {
    case 0: next = RESEARCH_TOP_StateIdle(p); break;
    case 1: next = RESEARCH_TOP_StateList((u8 *)p); break;
    case 2: next = RESEARCH_TOP_StateGraph((u32)p); break;
    case 3: next = RESEARCH_TOP_StateDetail((u32)p); break;
    case 4: return 1;
    }
    RESEARCH_TOP_UpdateFrameGraphic(p);
    RESEARCH_TOP_IncFrameCount(p);
    if (*state != next)
        RESEARCH_TOP_ChangeScreen(p, (int *)state, next);
    return 0;
}
