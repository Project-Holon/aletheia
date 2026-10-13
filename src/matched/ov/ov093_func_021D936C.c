/*
 * function: BTL_ABILITY_LeafGuardBlockStatus
 * address: 0x021D936C
 * packet: pkt_ov093_021D936C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern int func_021C8288(u8 *p);
extern int BTL_CALC_HasDefaultSickCont(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
void BTL_ABILITY_LeafGuardBlockStatus(int a, void *b, int c, int *d)
{
    int v;
    if (c == BTL_EVENT_GetVar(4) && func_021C8288(b) == 1) {
        v = BTL_EVENT_GetVar(0x1d);
        if (BTL_CALC_HasDefaultSickCont(v) || v == 0xe) *d = BTL_EVENT_OverwriteVar(0x41, 1);
    }
}
