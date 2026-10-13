/*
 * function: BTL_SERVER_FLOW_ItemEffectRaiseStatStage
 * address:  0x021CC438
 * packet:   pkt_ov093_021CC438
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021CC49C  0x021CC49C  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06230.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021CC49C(void *p, int id);
extern int BTL_POKEPARAM_IsFainted(void *m);
typedef signed char    s8;
extern int func_021D5D14(s8 *p, int i, int sign);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

int BTL_SERVER_FLOW_ItemEffectRaiseStatStage(char *p, void *m, int c, u8 d, u32 e)
{
    int id;
    u8 *r;

    id = BTL_POKEPARAM_GetPokeId(m);
    if (func_021CC49C(p + 0x1ab8, id) != 6) {
        if (BTL_POKEPARAM_IsFainted(m) == 0 && func_021D5D14(m, e, d) != 0) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(p, 14, id);
            r[0xf] = 1;
            r[0x10] = id;
            ((struct Obj06230 *)r)->f4 = e;
            r[0xc] = d;
            r[0xe] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(p, r);
            return 1;
        }
    }
    return 0;
}
