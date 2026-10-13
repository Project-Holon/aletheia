/*
 * function: WIFICLUB_StateShowPartnerMenuMessage
 * address:  0x021C0274
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *
 * Runs the five/zero setup and stamps selector 0x1D 0x1CC bytes in.
 */
#include "../include/Obj18266.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);

int WIFICLUB_StateShowPartnerMenuMessage(char *p, int v)
{
    WIFICLUB_ShowStreamedMessage(p, 5, 0);
    ((struct Obj18266 *)p)->f1CC = 0x1D;
    return v;
}
