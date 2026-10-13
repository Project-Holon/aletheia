/*
 * function: BTL_SERVER_FLOW_ProcTurnStartEvents
 * address:  0x021BBCD4
 * packet:   pkt_ov093_021BBCD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_InitFieldPokeIter  0x021BD2B4  thumb  ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter  0x021BD34C  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_ClearContFlag  0x021C6110  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *it, u8 **q);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *it, u8 **q, u8 **x);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_SERVER_FLOW_ClearContFlag(u8 *p, u8 *a, u32 n);

void BTL_SERVER_FLOW_ProcTurnStartEvents(u8 *p)
{
    u32 it;
    u8 *x;
    u32 n;

    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    if (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &x) != 0) {
        n = 12;
        do {
            if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)x, n) != 0)
                BTL_SERVER_FLOW_ClearContFlag(p, x, n);
        } while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &x) != 0);
    }
}
