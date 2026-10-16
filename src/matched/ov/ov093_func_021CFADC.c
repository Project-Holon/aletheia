/*
 * function: BTL_CLIENT_CanArenaTrapTrap
 * address:  0x021CFADC
 * packet:   pkt_ov093_021CFADC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsHeldItemEffective  0x021CF89C  thumb  ov093
 *   BTL_FIELD_IsSlotInUse  0x021EFCE4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 */
#include "../include/Obj01894.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct QI;
struct Unk021D62A8;
extern int BTL_CLIENT_IsHeldItemEffective(u8 *p, void *q);
extern void *BTL_FIELD_IsSlotInUse(char *arg0, int arg1);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_POKEPARAM_HasType(void *m, int k);

int BTL_CLIENT_CanArenaTrapTrap(u8 *g, void *m)
{
    u32 a;

    a = BTL_CLIENT_IsHeldItemEffective(g, m);
    if (BTL_FIELD_IsSlotInUse((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick(m, 0x1f) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick(m, 0x15) != 0)
        return 1;
    if (a != 0 && BTL_POKEPARAM_GetItem(m) == 0x116)
        return 1;
    if (BTL_POKEPARAM_GetValue(m, 0x11) == 0x1a)
        return 0;
    if (BTL_POKEPARAM_HasType(m, 2) != 0)
        return 0;
    if (BTL_POKEPARAM_HasSick(m, 0x1e) != 0)
        return 0;
    if (BTL_POKEPARAM_HasSick(m, 0x20) != 0)
        return 0;
    if (a != 0 && BTL_POKEPARAM_GetItem(m) == 0x21d)
        return 0;
    return 1;
}
