/*
 * function: BTL_SERVER_FLOW_ProcMemberOut
 * address:  0x021BDD00
 * packet:   pkt_ov093_021BDD00
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ProcPursuitBeforeSwitch  0x021C6190  thumb  ov093
 *   BTL_SERVER_FLOW_ForceExecuteMoveAction  0x021BD0C0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMemberOutCore  0x021BDD7C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Fl { u8 f : 1; };
extern int BTL_SERVER_FLOW_ProcPursuitBeforeSwitch(u8 *p, u8 *a);
extern int BTL_SERVER_FLOW_ForceExecuteMoveAction(u8 *p, u8 x, u32 y);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_SERVER_FLOW_ProcMemberOutCore(u8 *p, u8 *a, u32 c);

int BTL_SERVER_FLOW_ProcMemberOut(u8 *p, u8 *a, int c)
{
    u32 n, i;
    if (c == 0) {
        n = BTL_SERVER_FLOW_ProcPursuitBeforeSwitch(p, a);
        if (n != 0) {
            ((struct Fl *)(p + 0x78A))->f = 1;
            for (i = 0; i < n; i++) {
                BTL_SERVER_FLOW_ForceExecuteMoveAction(p, p[0x78B + i], BTL_POKEPARAM_GetPokeId(a));
                if (BTL_POKEPARAM_IsFainted(a)) break;
            }
            ((struct Fl *)(p + 0x78A))->f = 0;
        }
    }
    if (BTL_POKEPARAM_IsFainted(a) == 0) {
        BTL_SERVER_FLOW_ProcMemberOutCore(p, a, 0x26C);
        return 1;
    }
    return 0;
}
