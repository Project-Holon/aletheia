/*
 * function: EGG_DEMO_MENU_Main
 * address: 0x021F6158
 * packet: pkt_ov215_021F6158
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 */
#include "../include/Obj25747.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
void EGG_DEMO_MENU_Main(void *unused, char *p)
{
    TCBL_Main(((struct Obj25747 *)p)->f54);
}
