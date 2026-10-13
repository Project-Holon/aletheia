/*
 * function: HAND_ITEM_AddFactor
 * address:  0x021DCEC4
 * packet:   pkt_ov093_021DCEC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   gItemHandlerRegistry     0x021F1EA4  data  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D58A8(u8 *p, int k);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Node;
extern struct Node *BTL_EVENT_AddFactor(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);

struct Ent { u32 key; u32 (*fn)(u32 *); };
extern struct Ent gItemHandlerRegistry[0xac];

void *HAND_ITEM_AddFactor(void *a, u32 k)
{
    u32 i;
    u16 t;
    u8 sub;
    u32 f8;
    u32 loc;

    for (i = 0; i < 0xac; i++) {
        if (k == gItemHandlerRegistry[i].key) {
            t = func_021D58A8(a, 0xc);
            sub = BTL_POKEPARAM_GetPokeId(a);
            f8 = gItemHandlerRegistry[i].fn(&loc);
            return BTL_EVENT_AddFactor(5, k, 6, t, sub, f8, loc);
        }
    }
    return 0;
}
