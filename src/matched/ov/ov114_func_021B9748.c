/*
 * function: NHTTP_RAP_StartConnection
 * address:  0x021B9748
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NHTTP_StartConnection  0x021BF308  arm  ov114
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm  arm9
 *
 * Unlinks the record's +0x0c owner from list class 2, keyed 0x3f6.  Both
 * early exits are the ELSE arm of their test, which sinks each tiny return
 * block out of line (0x021B9766, then 0x021B976A last).
 */
#include "../include/Obj22571.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTP_StartConnection(int);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);

int NHTTP_RAP_StartConnection(u8 *p)
{
    int h;

    if (p != 0) {
        h = NHTTP_StartConnection(((struct Obj22571 *)p)->fC);
        if (h != 0) {
            GFL_NET_STATE_SetError(h, 2, h, 0x3f6);
            return h;
        }
        return 0;
    }
    return 1;
}
