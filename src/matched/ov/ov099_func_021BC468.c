/*
 * function: WIFICLUB_StateNoticeYesNo
 * address:  0x021BC468
 * packet:   pkt_ov099_021BC468
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_PollYesNoMenu  0x021BA858  thumb  ov099
 *   WIFICLUBACTOR_TickBlink  0x021B9B64  thumb  ov099
 *
 * Levers: the 0x274 offset is an enum-typed local (keeps r4 = 0x274 live and
 * derives 0x1CC as `o - 0xa8`); the two stores are written out in each arm.
 */
#include "../include/Obj13687.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef enum { K274 = 0x274 } Off;

extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUBACTOR_TickBlink(char *p);

int WIFICLUB_StateNoticeYesNo(char *p, int v)
{
    int r;
    Off o;

    r = WIFICLUB_PollYesNoMenu(p);
    o = K274;
    WIFICLUBACTOR_TickBlink(p + o);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((struct Obj13687 *)p)->f1353 = 0x4c;
        *(u32 *)(p + (o - 0xa8)) = 0x8a;
    } else {
        ((struct Obj13687 *)p)->f1353 = 0x9b;
        *(u32 *)(p + (o - 0xa8)) = 0x8a;
    }
    return v;
}
