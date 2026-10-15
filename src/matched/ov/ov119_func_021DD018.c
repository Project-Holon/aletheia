/*
 * function: POKETRADE_PROC_ClampScrollColumn
 * address: 0x021DD018
 * packet: pkt_ov119_021DD018
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_GetScrollColumn 0x021E4DBC thumb ov119
 *   gScrollSnapPos 0x021E7FE0 data ov119 a4
 */
#include "../include/Obj03257.h"
extern int POKETRADE_2D_GetScrollColumn(char *);
extern const int gScrollSnapPos[];
void POKETRADE_PROC_ClampScrollColumn(char *p, int flag)
{
    int n;
    if (flag) {
        n = POKETRADE_2D_GetScrollColumn(p) + 2;
        if (n >= ((struct Obj03257 *)p)->f634) n -= ((struct Obj03257 *)p)->f634;
        if (((struct Obj03257 *)p)->f107C == gScrollSnapPos[0]) n = 2;
        else if (((struct Obj03257 *)p)->f107C == gScrollSnapPos[((struct Obj03257 *)p)->f630]) {
            n = 0;
            if (((struct Obj03257 *)p)->fF78 >= 3) ((struct Obj03257 *)p)->fF78 = 2;
        }
        ((struct Obj03257 *)p)->fF74 = n;
        ((struct Obj03257 *)p)->f1080 = -1;
    }
}
