/*
 * function: IRC_RANKING_ListUpdate
 * address: 0x021B838C
 * packet: pkt_ov106_021B838C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   IRC_RANKING_ListDrawRows 0x021B8524 thumb ov106
 */
#include "../include/Obj02814.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void IRC_RANKING_ListDrawRows(u8 *);
void IRC_RANKING_ListUpdate(u8 *p) {
    int value;
    if(((struct Obj02814 *)p)->f594==0)return;
    ((struct Obj02814 *)p)->f594=0;
    value=((struct Obj02814 *)p)->f556;
    if(value%24==0) {
        if(((struct Obj02814 *)p)->f55C!=value/24)GFL_USE_PlaySeDefaultVolume(1605);
        ((struct Obj02814 *)p)->f55C=((struct Obj02814 *)p)->f556/24;
        ((struct Obj02814 *)p)->f564=-40;
        ((struct Obj02814 *)p)->f566=24;
        IRC_RANKING_ListDrawRows(p);
        ((struct Obj02814 *)p)->f590=1;
    } else ((struct Obj02814 *)p)->f598=1;
}
