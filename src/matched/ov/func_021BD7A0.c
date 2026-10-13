/*
 * function: WIFICLUB_StateShowLeaveMessageByRoleB
 * address:  0x021BD7A0
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
 * The complement of WIFICLUB_StateShowLeaveMessageByRoleA on the same state word at +0x135C: when it
 * is 2 or 3 runs the 0x7C setup, otherwise the 0x7D one; clears +0x135C and
 * stamps selector 0x8E.  Returns the second argument.  Same shape as its pair,
 * with the two selectors exchanged.
 */
#include "../include/Obj09199.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);

int WIFICLUB_StateShowLeaveMessageByRoleB(char *p, int v)
{
    u32 x = ((struct Obj09199 *)p)->f135C;

    if (x - 2 <= 1) {
        WIFICLUB_ShowStreamedMessage(p, 0x7C, 0);
    } else {
        WIFICLUB_ShowStreamedMessage(p, 0x7D, 0);
    }

    ((struct Obj09199 *)p)->f135C = 0;
    ((struct Obj09199 *)p)->f1CC = 0x8E;
    return v;
}
