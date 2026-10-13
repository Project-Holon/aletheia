/*
 * function: WIFICLUB_ShowStreamedMessage
 * address:  0x021BAAB8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_DeleteWindow  0x021BA8BC  thumb  ov099
 *   WIFICLUB_PrintTalkMessage  0x021BA978  thumb  ov099
 *
 * Releases the pointer at +0x19C and re-arms the block with the one-flag.
 */
#include "../include/Obj13683.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUB_DeleteWindow(void *p);
extern void WIFICLUB_PrintTalkMessage(char *p, int a, int b, int c);

void WIFICLUB_ShowStreamedMessage(char *p, int a, int b)
{
    ((struct Obj13683 *)p)->f19C = (void *)WIFICLUB_DeleteWindow(((struct Obj13683 *)p)->f19C);
    WIFICLUB_PrintTalkMessage(p, a, b, 1);
}
