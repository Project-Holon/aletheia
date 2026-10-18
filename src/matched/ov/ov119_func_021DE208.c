/*
 * function: POKETRADE_NEGO_PollOfferCursorKeys
 * address: 0x021DE208
 * packet: pkt_ov119_021DE208
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 */
#include "../include/Obj00251.h"

typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
typedef unsigned char  u8;
extern void UI_SetInputMode(u8 v);
static inline int poll(void)
{
    int v=KEY_GetTrg();
    if(v) UI_SetInputMode(0);
    return v;
}
int POKETRADE_NEGO_PollOfferCursorKeys(char *p)
{
    int changed=0;
    int v;
    if(poll()==16) { ((struct Obj00251 *)p)->f10A0=(((struct Obj00251 *)p)->f10A0+3)%6; changed=1; }
    if(poll()==32) {
        ((struct Obj00251 *)p)->f10A0=(((struct Obj00251 *)p)->f10A0-3)%6;
        if(((struct Obj00251 *)p)->f10A0<0) ((struct Obj00251 *)p)->f10A0+=6;
        changed=1;
    }
    if(poll()==64) {
        v=((struct Obj00251 *)p)->f10A0;
        if(v==0 || v==3) ((struct Obj00251 *)p)->f10A0+=3;
        ((struct Obj00251 *)p)->f10A0-=1; changed=1;
    }
    if(poll()==128) {
        v=((struct Obj00251 *)p)->f10A0;
        if(v==2 || v==5) ((struct Obj00251 *)p)->f10A0-=3;
        ((struct Obj00251 *)p)->f10A0+=1; changed=1;
    }
    return changed;
}
