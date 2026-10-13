/*
 * function: BTL_CALC_AddAbilityHandlers
 * address:  0x021D8484
 * packet:   pkt_ov093_021D8484
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_GetPokeSpeed  0x021D85B0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_CALC_UnpackAbilityPriority  0x021D84F8  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   gAbilityHandlerRegistry     0x021F0E74  data  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);
struct Node;
u16 BTL_CALC_GetPokeSpeed(u8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
int BTL_CALC_UnpackAbilityPriority(u32 *p);
struct Node *BTL_EVENT_AddFactor(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);

struct Ent { u32 key; u32 (*fn)(u32 *); };
extern struct Ent gAbilityHandlerRegistry[0x9e];

void *BTL_CALC_AddAbilityHandlers(void *a)
{
    u16 k = func_021D59B4(a, 0x10);
    u32 i;
    u32 t;
    u32 f8;
    u8 sub;
    int pri;
    u32 loc;

    for (i = 0; i < 0x9e; i++) {
        if (k == gAbilityHandlerRegistry[i].key) {
            t = BTL_CALC_GetPokeSpeed(a);
            sub = BTL_POKEPARAM_GetPokeId(a);
            f8 = gAbilityHandlerRegistry[i].fn(&loc);
            pri = BTL_CALC_UnpackAbilityPriority(&loc);
            return BTL_EVENT_AddFactor(4, k, pri, t, sub, f8, loc);
        }
    }
    return 0;
}
