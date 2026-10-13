/*
 * function: HAND_WAZA_TeleportCheckFail
 * address:  0x021E5C18
 * packet:   pkt_ov093_021E5C18
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetCompetitor  0x021C8168  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_SERVER_FLOW_GetCompetitor(void *p);
extern int BTL_SERVER_FLOW_GetRule(int *p);
struct Unk021D62A8;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);

void HAND_WAZA_TeleportCheckFail(u8 *p, void *a, int b)
{
    void *r;
    if (BTL_SERVER_FLOW_GetCompetitor(a) != 0 || BTL_SERVER_FLOW_GetRule(a) != 0)
        BTL_EVENT_OverwriteVar(0x22, 0x1a);
    r = BTL_SERVER_FLOW_GetPokeParam(a, b);
    if (BTL_POKEPARAM_HasSick(r, 8) != 0 && BTL_POKEPARAM_HasSick(r, 0x16) != 0)
        BTL_EVENT_OverwriteVar(0x22, 0x1a);
}
