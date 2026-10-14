/*
 * function: POKETRADE_NEGO_IsMonOwnOffer
 * address: 0x021DF614
 * packet: pkt_ov119_021DF614
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 */
#include "../include/Obj04479.h"
extern int POKETRADE_PROC_GetBoxIndexForSlot(int,char *);
extern int POKETRADE_PROC_GetSlotIndexInBox(int,int);
extern int POKETRADE_PROC_IsHostSide(void *);
int POKETRADE_NEGO_IsMonOwnOffer(char *p,int a,int b)
{
    int x,y,i;
    x=POKETRADE_PROC_GetBoxIndexForSlot(a,p);
    y=POKETRADE_PROC_GetSlotIndexInBox(a,b);
    if(((struct Obj04479 *)p)->fF7C==y && ((struct Obj04479 *)p)->fF80==x) return 1;
    if(POKETRADE_PROC_IsHostSide(p)) {
        for(i=0;i<3;i++) {
            if(*(int *)(p+i*4+0xfa4)==-1) continue;
            if(y==*(int *)(p+i*4+0xfa4) && x==*(int *)(p+i*4+0xfbc)) return 1;
        }
    } else {
        if(((struct Obj04479 *)p)->fF84==y && ((struct Obj04479 *)p)->fF88==x && ((struct Obj04479 *)p)->fF7C==-1 && ((struct Obj04479 *)p)->fF80==-1) return 1;
    }
    return 0;
}
