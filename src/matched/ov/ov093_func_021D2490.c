/*
 * function: BTL_CLIENT_StepStartWeather
 * address:  0x021D2490
 * packet:   pkt_ov093_021D2490
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_StoreCountdown  0x021EF9C0  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   gWeatherEffects     0x021EFFAE  data   ov093  a2
 */
#include "../include/Obj10019.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u16 a; u16 b; } Pair16;

extern int *BTL_FIELD_StoreCountdown(int *p, int a, int b);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021F7998(u32 a);
extern int func_021F7EB4(void);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern Pair16 gWeatherEffects[5];

int BTL_CLIENT_StepStartWeather(u8 *p, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        BTL_FIELD_StoreCountdown(((struct Obj10019 *)p)->f34, (u8)id, (u16)c[1]);
        if (BTL_CLIENT_IsMainStepActive(p))
            return 1;
        if (id < 5)
            func_021F7998(gWeatherEffects[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(((struct Obj10019 *)p)->f54, gWeatherEffects[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj10019 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
