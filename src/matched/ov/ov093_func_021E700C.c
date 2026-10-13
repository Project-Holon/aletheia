/*
 * function: func_021E700C
 * address:  0x021E700C
 * packet:   pkt_ov093_021E700C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTLV_CORE_EventScaleDamage(int a);

void func_021E700C(int x, int a, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam((int *)a, (u8)BTL_EVENT_GetVar(4))) != 0) {
            BTLV_CORE_EventScaleDamage(2);
        }
    }
}
