/*
 * function: WIFICLUB_StateStartPrompt
 * address:  0x021C017C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_TickBlink  0x021B9B64  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *
 * Re-arms, runs the seven/zero setup and stamps selector 0x20.
 */
#include "../include/Obj18264.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_TickBlink(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);

int WIFICLUB_StateStartPrompt(char *p, int v)
{
    WIFICLUBACTOR_TickBlink(p + 0x274);
    WIFICLUB_ShowStreamedMessage(p, 7, 0);
    ((struct Obj18264 *)p)->f1CC = 0x20;
    return v;
}
