/*
 * function: WIFICLUB_StateShowRuleSet
 * address:  0x021BCE80
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_LoadPickedRegulation  0x021BCBD8  thumb  ov099
 *   WIFICLUB_ShowRuleWindow  0x021BBEB4  thumb  ov099
 *
 * Re-arms through WIFICLUB_LoadPickedRegulation, hands the owner record class byte to
 * WIFICLUB_ShowRuleWindow and stamps selector 0x5D; returns the selector.
 */
#include "../include/Obj12113.h"
#include "../include/Obj18202.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern u32 WIFICLUB_LoadPickedRegulation(char *p, int m);
struct O;
extern void WIFICLUB_ShowRuleWindow(struct O *p, int mask, u32 a, int mode);

int WIFICLUB_StateShowRuleSet(char *p, int v)
{
    WIFICLUB_LoadPickedRegulation(p, 1);
    WIFICLUB_ShowRuleWindow((struct O *)p, 0, ((struct Obj18202 *)(*(char * *)&((struct Obj12113 *)p)->f248))->f20, 0);
    ((struct Obj12113 *)p)->f1CC = 0x5D;
    return v;
}
