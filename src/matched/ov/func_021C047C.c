/*
 * function: WIFICLUB_StateSendChoiceAfterDelay
 * address:  0x021C047C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_SetOwnStatusAndPublish  0x021C18C8  thumb  ov099
 *
 * Ages the counter at +0x1E0 and, when it underflows, hands the halfword at
 * +0x246 to WIFICLUB_SetOwnStatusAndPublish with mode 2 and stamps selector 0x9E.  The image
 * branches on the subs flags themselves (bpl), so the condition is the
 * decremented value, written as a prefix -- on the dereference.
 */
#include "../include/Obj09203.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int a, int b);

int WIFICLUB_StateSendChoiceAfterDelay(char *p, int v)
{
    if (--((struct Obj09203 *)p)->f1E0 < 0) {
        WIFICLUB_SetOwnStatusAndPublish(p, 2, ((struct Obj09203 *)p)->f246);
        ((struct Obj09203 *)p)->f1CC = 0x9E;
    }

    return v;
}
