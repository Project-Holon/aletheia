/*
 * function: INTRO_MSG_MainMenuList
 * address: 0x021BF528
 * packet: pkt_ov204_021BF528
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENULIST_Main 0x020200CC thumb
 */
#include "../include/Obj14624.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern int BMP_MENULIST_Main(struct Obj *);
void INTRO_MSG_MainMenuList(u8 *p)
{
    u8 *q=p+36;
    ((struct Obj14624 *)q)->f8=BMP_MENULIST_Main(*(struct Obj * *)&((struct Obj14624 *)q)->f0);
}
