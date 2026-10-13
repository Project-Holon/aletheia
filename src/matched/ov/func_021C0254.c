/*
 * function: WIFICLUB_StateOpenPartnerMenu
 * address:  0x021C0254
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_CreateMainMenu  0x021BAD50  thumb  ov099
 *   WIFICLUBACTOR_TickBlink  0x021B9B64  thumb  ov099
 *
 * Runs the setup, stamps selector 0x83 and re-arms the block 0x274 bytes in.
 */
#include "../include/Obj18265.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUB_CreateMainMenu(int a);
extern void WIFICLUBACTOR_TickBlink(char *p);

int WIFICLUB_StateOpenPartnerMenu(char *p, int v)
{
    WIFICLUB_CreateMainMenu((int)p);
    ((struct Obj18265 *)p)->f1CC = 0x83;
    WIFICLUBACTOR_TickBlink(p + 0x274);
    return v;
}
