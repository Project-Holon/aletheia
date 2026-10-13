/*
 * function: BTL_SERVER_FLOW_CheckAllyMoveAutoHit
 * address:  0x021BFA00
 * packet:   pkt_ov093_021BFA00
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B9A6C  0x021B9A6C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 BTL_MAIN_GetRule(void **p);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021B9A6C(int a, u32 b);

int BTL_SERVER_FLOW_CheckAllyMoveAutoHit(u8 *p, u8 *a, u8 *b, void *item)
{
    int x;
    int y;
    if (BTL_MAIN_GetRule(*(void ** *)&((struct Obj00003 *)p)->f4) == 2) {
        if (item != 0 && WAZA_TOOL_GetFlag(item, 0xb) != 0) return 0;
        x = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, BTL_POKEPARAM_GetPokeId(a));
        y = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, BTL_POKEPARAM_GetPokeId(b));
        if (func_021B9A6C(x, y) == 0) return 1;
    }
    return 0;
}
