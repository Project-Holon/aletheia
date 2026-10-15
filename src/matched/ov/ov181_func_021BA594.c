/*
 * function: STAFF_ROLL_PrintEntry
 * address: 0x021BA594
 * packet: pkt_ov181_021BA594
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STAFF_ROLL_PrintText 0x021BA4AC thumb ov181
 */
#include "../include/Obj01071.h"
#include "../include/Obj08305.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void STAFF_ROLL_PrintText(char *, unsigned char *, void *, int);
void STAFF_ROLL_PrintEntry(char *p, unsigned char *q)
{
    void *s;
    int y;
    if (((struct Obj01071 *)q)->f4 < 0x100) {
        s = BMP_WIN_GetBmp(((struct Obj08305 *)p)->f2BC);
        y = ((struct Obj01071 *)q)->f4;
        ((struct Obj08305 *)p)->f2CF |= 1;
    } else {
        s = BMP_WIN_GetBmp(((struct Obj08305 *)p)->f2C4);
        y = ((struct Obj01071 *)q)->f4 - 0x100;
        ((struct Obj08305 *)p)->f2CF |= 2;
    }
    STAFF_ROLL_PrintText(p, q, s, y);
}
