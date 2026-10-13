/*
 * function: SCRIPT_SYS_ChangeNextEvent
 * address: 0x0215889C
 * packet: pkt_ov010_0215889C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 8-byte tail stub; existing labelled SCRIPT_SYS_SetNextEvent follows.
 * symbols:
 *   GAME_EVENT_ChangeEvent 0x0201235C thumb
 */
typedef unsigned int u32;
struct S0201235C;
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
void SCRIPT_SYS_ChangeNextEvent(void *p, u32 *out)
{
    GAME_EVENT_ChangeEvent(p, out);
}
