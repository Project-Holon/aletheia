/*
 * function: BTL_SERVER_GetShiftPromptMon
 * address:  0x021BB0A0
 * packet:   pkt_ov093_021BB0A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_IsClientSlotUsed  0x021BB830  thumb  ov093
 *   BTL_ADAPTER_GetSendBuffer  0x021EEB64  thumb  ov093
 *   BTL_CALC_ActionGetKind  0x021D8454  thumb  ov093
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */
#include "../include/Obj21031.h"
#include "../include/Obj21032.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 pad : 7;
    u32 f : 3;
} B;

extern int BTL_SERVER_IsClientSlotUsed(u8 *);
struct QW;
extern u32 BTL_ADAPTER_GetSendBuffer(struct QW *p, u32 *out);
extern u32 BTL_CALC_ActionGetKind(B *);
extern u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

u32 BTL_SERVER_GetShiftPromptMon(u8 *p)
{
    u8 *q = p + 0x20;
    B *b;

    if (BTL_SERVER_IsClientSlotUsed(q) != 0) {
        b = (B *)BTL_ADAPTER_GetSendBuffer((struct QW *)(((struct Obj21032 *)q)->f0), 0);
        if (BTL_CALC_ActionGetKind(b) == 3) {
            u8 *r = BTL_SIDE_GetClientPoke(((struct Obj21031 *)p)->f10, 1, b->f);
            return BTL_POKEPARAM_GetPokeId(r);
        }
    }
    return 0x1f;
}
