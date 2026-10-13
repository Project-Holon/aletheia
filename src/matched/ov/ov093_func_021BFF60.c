/*
 * function: BTL_SERVER_FLOW_ReleaseBindingTarget
 * address:  0x021BFF60
 * packet:   pkt_ov093_021BFF60
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The k clamp is written with gotos: the original branches n == 0 straight to
 * the shared `k = 0x1f`, and the if/else and `||` spellings reorder that.
 *
 * symbols:
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_CureSick  0x021C5620  thumb  ov093
 *   BTL_SERVER_FLOW_ClearContFlag  0x021C6110  thumb  ov093
 *   func_021C000C  0x021C000C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke  0x021C5D88  thumb  ov093
 *   BTL_SERVER_FLOW_SetPokeCounter  0x021C0780  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetCounter(u8 *a, int i);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct Unk021D62A8;
struct Slot;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void BTL_SERVER_FLOW_ClearContFlag(u8 *p, u8 *a, unsigned int n);
extern int func_021C000C(u8 *p, int k);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *p, u8 *a, int b);
extern void BTL_SERVER_FLOW_SetPokeCounter(u8 *p, u8 *a, int i, u8 v);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

void BTL_SERVER_FLOW_ReleaseBindingTarget(u8 *p, u8 *a, int z)
{
    u8 k;
    int n;
    u8 *w;
    n = BTL_POKEPARAM_GetCounter(a, 4);
    if (n == 0) goto bad;
    k = n - 1;
    if (k < 0x18) goto ok;
bad:
    k = 0x1f;
ok:
    if (k != 0x1f) {
        w = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, k);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)w, 0x21) != 0) {
            BTL_SERVER_FLOW_CureSick(p, w, 0x21, 0);
            BTL_SERVER_FLOW_ClearContFlag(p, w, 3);
            if (func_021C000C(p + 0x1ab8, k) != 0) {
                BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x31, k, 0);
                BTL_SERVER_FLOW_PushMsgSetPoke(p, w, 0x465);
            }
        }
        BTL_SERVER_FLOW_SetPokeCounter(p, a, 4, 0);
        k = 0;
        if (z == 0 && BTL_POKEPARAM_IsFainted(a) == 0) {
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x31, BTL_POKEPARAM_GetPokeId(a), k);
        }
    }
}
