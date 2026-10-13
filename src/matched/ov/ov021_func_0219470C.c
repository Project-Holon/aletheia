/*
 * function: TALKMSGWIN_Update
 * address:  0x0219470C
 * packet:   pkt_ov021_0219470C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   TALKMSGWIN_SaveCamera  0x0219545C  thumb  ov021
 *   TALKMSGWIN_SetupCamera  0x021953D4  thumb  ov021
 *   TALKMSGWIN_UpdateBalloon  0x02194B84  thumb  ov021
 *   TALKMSGWIN_UpdatePlainWindow  0x02194C60  thumb  ov021
 *   TALKMSGWIN_RestoreCamera  0x02195490  thumb  ov021
 */
#include "../include/Obj01351.h"

typedef unsigned char  u8;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void TALKMSGWIN_SaveCamera(void *a);
extern void TALKMSGWIN_SetupCamera(u8 *p, int m);
extern void TALKMSGWIN_UpdateBalloon(u8 *p, u8 *e);
extern void TALKMSGWIN_UpdatePlainWindow(u8 *p, u8 *e);
extern void TALKMSGWIN_RestoreCamera(void *a);

void TALKMSGWIN_Update(unsigned char *a)
{
    int i;

    TCBL_Main(((struct Obj01351 *)a)->fC98);
    TALKMSGWIN_SaveCamera(a);
    TALKMSGWIN_SetupCamera(a, 0);
    for (i = 0; i < 0x20; i++) {
        if (a[i * 0x64 + 0x1a] == 0)
            TALKMSGWIN_UpdateBalloon(a, a + 0x18 + i * 0x64);
        else
            TALKMSGWIN_UpdatePlainWindow(a, a + 0x18 + i * 0x64);
    }
    TALKMSGWIN_RestoreCamera(a);
}
