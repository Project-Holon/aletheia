/*
 * function: POKETRADE_SAVE_DeleteOfferListWindows
 * address: 0x021E2680
 * packet: pkt_ov119_021E2680
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   POKETRADE_2D_DeleteOfferWindowActors 0x021E6DEC thumb
 */
#include "../include/Obj10374.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void POKETRADE_2D_DeleteOfferWindowActors(int p);
void POKETRADE_SAVE_DeleteOfferListWindows(char *p)
{
    int i;
    for (i=0;i<4;i++) {
        char *q = p+i*4;
        if (((struct Obj10374 *)q)->f1038) {
            BMP_WIN_Delete(((struct Obj10374 *)q)->f1038);
            ((struct Obj10374 *)q)->f1038=0;
        }
    }
    POKETRADE_2D_DeleteOfferWindowActors((int)p);
}
