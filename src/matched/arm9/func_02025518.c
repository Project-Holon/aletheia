/*
 * function: ACTOR_TOOL_FreeChar
 * address:  0x02025518
 * packet:   pkt_02025518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker:  +0012 THM_CALL ACTOR_TOOL_FreeRun       -> unresolved: 020253D4 (thumb, from name) has no witness outside 02025518..02025536
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *           Verdict MATCH*: the listing's extent for the original is 32 bytes against 30 compiled.
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *   ACTOR_TOOL_FreeRun  0x020253D4  thumb
 *   ACTOR_TOOL_GetCharBlock  0x02025508  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern unsigned int ACTOR_TOOL_GetCharBlock(int a0, int a1, int a2);
struct ActorTool;
extern void ACTOR_TOOL_FreeRun(struct ActorTool *p, u32 i, u32 bank);
extern void func_0204ADA4(u32 a0);

void ACTOR_TOOL_FreeChar(u32 a0, u32 a1, u32 a2)
{
    u32 v = ACTOR_TOOL_GetCharBlock(a0, a1, a2);

    ACTOR_TOOL_FreeRun((struct ActorTool *)a0, v, a2);
    func_0204ADA4(a1);
}
