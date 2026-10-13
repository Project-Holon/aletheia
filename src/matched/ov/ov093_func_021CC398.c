/*
 * function: BTL_SERVER_FLOW_ItemEffectCureAllSick
 * address:  0x021CC398
 * packet:   pkt_ov093_021CC398
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021CC418  0x021CC418  thumb  ov093
 *   func_021CC428  0x021CC428  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj09983.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021CC418(void *p, int id);
extern u32 func_021CC428(int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

int BTL_SERVER_FLOW_ItemEffectCureAllSick(char *p, void *m)
{
    u32 k;
    int ret;
    int id;
    u8 *r;
    int i;

    if (BTL_POKEPARAM_IsFainted(m) == 0) {
        if (func_021CC418(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(m)) == 0) {
            ret = 0;
            i = 0;
            for (;;) {
                k = func_021CC428(i++);
                if (k == 0)
                    break;
                if (BTL_POKEPARAM_HasSick(m, k) != 0) {
                    id = BTL_POKEPARAM_GetPokeId(m);
                    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(p, 11, id);
                    r[0x14] = 1;
                    r[8] = id;
                    ((struct Obj09983 *)r)->f4 = k;
                    BTL_SERVER_FLOW_CommitCmdRecord(p, r);
                    ret = 1;
                }
            }
            return ret;
        }
    }
    return 0;
}
