/*
 * function: BEACON_VIEW_UpdateSlide
 * address:  0x021F2714
 * packet:   pkt_ov032_021F2714
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     BEACON_VIEW_SetArrowAnim takes three arguments (its own matched file); the
 *           cleared zero is shared with its third argument, which is what
 *           puts the zero in r2 for the three stores.
 *
 * symbols:
 *   BEACON_VIEW_UpdateSlide 0x021F2714 thumb
 *   BEACON_VIEW_GetContTouchedRow 0x021F0050 thumb ov032
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb ov032
 *   BEACON_VIEW_RefreshActorAnims 0x021F067C thumb ov032
 *   BEACON_VIEW_SetPrintQueueLimit 0x021F029C thumb ov032
 *   BEACON_VIEW_ApplySlideTarget 0x021F028C thumb ov032
 */
#include "../include/Obj00007.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int BEACON_VIEW_GetContTouchedRow(unsigned char *p);
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void BEACON_VIEW_RefreshActorAnims(char *);
extern void BEACON_VIEW_SetPrintQueueLimit(char *, int);
extern void BEACON_VIEW_ApplySlideTarget(unsigned char *p);

int BEACON_VIEW_UpdateSlide(char *p)
{
    int r;

    if (((struct Obj00007 *)p)->f82 == 0) {
        r = BEACON_VIEW_GetContTouchedRow((unsigned char *)p);
        if (r != ((struct Obj00007 *)p)->f84 || r == -1) {
            ((struct Obj00007 *)p)->f82 = 1;
        }
        ((struct Obj00007 *)p)->f88 = ((struct Obj00007 *)p)->f88 + 1;
    }
    if (((struct Obj00007 *)p)->f82 != 0) {
        if (((struct Obj00007 *)p)->fA8 > 0) {
            return 3;
        }
        ((struct Obj00007 *)p)->f82 = 0;
        ((struct Obj00007 *)p)->f88 = 0;
        ((struct Obj00007 *)p)->f81 = 0;
        if (((struct Obj00007 *)p)->f83 == 0) {
            BEACON_VIEW_SetArrowAnim((u8 *)p, 4, 0);
        }
        BEACON_VIEW_RefreshActorAnims(p);
        BEACON_VIEW_SetPrintQueueLimit(p, 0);
        return ((struct Obj00007 *)p)->f83;
    }
    if (((struct Obj00007 *)p)->fA8 == 0) {
        BEACON_VIEW_ApplySlideTarget((unsigned char *)p);
    }
    return 3;
}
