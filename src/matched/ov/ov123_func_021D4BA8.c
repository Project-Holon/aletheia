/*
 * function: GSYNC_MENU_OnButtonPressed
 * address: 0x021D4BA8
 * packet: pkt_ov123_021D4BA8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StatePlayButtonAnim 0x021D4B44 thumb ov123
 */
#include "../include/Obj06458.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
extern void GSYNC_MENU_StatePlayButtonAnim(char *);
int GSYNC_MENU_OnButtonPressed(int n, char *p)
{
    ((struct Obj06458 *)p)->f270 = n;
    switch (n) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73b);
        CLACT_SetActorAnimSeq(((struct Obj06458 *)p)->f2A0, 14);
        GSYNC_MENU_ChangeState(p, GSYNC_MENU_StatePlayButtonAnim, 0x389);
        ((struct Obj06458 *)p)->f8 = 2;
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73b);
        ((struct Obj06458 *)p)->f8 = 3;
        GSYNC_MENU_ChangeState(p, GSYNC_MENU_StatePlayButtonAnim, 0x393);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73c);
        ((struct Obj06458 *)p)->f8 = 0;
        GSYNC_MENU_ChangeState(p, GSYNC_MENU_StatePlayButtonAnim, 0x399);
        break;
    }
    return 1;
}
