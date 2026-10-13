/*
 * function: func_021F03EC
 * address:  0x021F03EC
 * packet:   pkt_ov032_021F03EC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_SetArrowAnim  0x021F05E8  thumb  ov032
 *   BEACON_VIEW_SetPrintQueueLimit  0x021F029C  thumb  ov032
 *   func_021F1A08  0x021F1A08  thumb  ov032
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void BEACON_VIEW_SetPrintQueueLimit(char *p, int flag);
extern void func_021F1A08(char *p);

int func_021F03EC(u8 *p)
{
    int s = ((struct Obj00007 *)p)->f6C;

    switch (s) {
    case 0:
        BEACON_VIEW_SetArrowAnim(p, 0, 1);
        BEACON_VIEW_SetPrintQueueLimit((char *)p, 1);
        func_021F1A08((char *)p);
        ((struct Obj00007 *)p)->f6C = ((struct Obj00007 *)p)->f6C + 1;
        break;
    case 1:
        if (((struct Obj00007 *)p)->fA8 == 0) {
            BEACON_VIEW_SetPrintQueueLimit((char *)p, 0);
            ((struct Obj00007 *)p)->f6C = 0;
            return 1;
        }
        break;
    }
    return 0;
}
