/*
 * function: BEACON_DETAIL_ReadTouchInput
 * address: 0x02184798
 * packet: pkt_ov219_02184798
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02185E00 0x02185E00 data a4
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   BEACON_DETAIL_CalcTouchDelta 0x021848F4 thumb ov219
 */
#include "../include/Obj00302.h"
extern const char d_02185E00[];
extern int TOUCHPANEL_HitTrg(const void *);
extern void BEACON_DETAIL_CalcTouchDelta(const char *,int,int,int *,int *,int *,int *);
void BEACON_DETAIL_ReadTouchInput(char *p)
{
    int flag=0;
    int result;
    int xf,dx,yf,dy;
    ((struct Obj00302 *)p)->fC320=0;
    result=TOUCHPANEL_HitTrg(d_02185E00);
    if(result==0)flag=0x400;
    else if(result==1)flag=2;
    if(((struct Obj00302 *)p)->fC35C!=0){
        if(flag!=0){((struct Obj00302 *)p)->fC320=flag;return;}
        ((struct Obj00302 *)p)->fC324=0;
        ((struct Obj00302 *)p)->fC330=0;
        ((struct Obj00302 *)p)->fC334=0;
        ((struct Obj00302 *)p)->fC338=0;
        ((struct Obj00302 *)p)->fC320=0;
        ((struct Obj00302 *)p)->fC328=((struct Obj00302 *)p)->fC364;
        ((struct Obj00302 *)p)->fC32C=((struct Obj00302 *)p)->fC368;
        ((struct Obj00302 *)p)->fC338=4;
    }
    if(((struct Obj00302 *)p)->fC360!=0){
        switch(((struct Obj00302 *)p)->fC324){
        case 0:
            if(((struct Obj00302 *)p)->fC338==0)(((struct Obj00302 *)p)->fC324)++;
            else (((struct Obj00302 *)p)->fC338)--;
        case 1:
            if(flag!=0)return;
            BEACON_DETAIL_CalcTouchDelta(p,((struct Obj00302 *)p)->fC328,((struct Obj00302 *)p)->fC32C,&xf,&dx,&yf,&dy);
            ((struct Obj00302 *)p)->fC320=xf|yf;
            ((struct Obj00302 *)p)->fC330=dx;
            ((struct Obj00302 *)p)->fC334=dy;
            ((struct Obj00302 *)p)->fC328=((struct Obj00302 *)p)->fC364;
            ((struct Obj00302 *)p)->fC32C=((struct Obj00302 *)p)->fC368;
            return;
        default:return;
        }
    }else{
        if(flag==0 && ((struct Obj00302 *)p)->fC338!=0 && ((struct Obj00302 *)p)->fC330<4 && ((struct Obj00302 *)p)->fC334<4)
            ((struct Obj00302 *)p)->fC320=1;
        ((struct Obj00302 *)p)->fC324=0;
        ((struct Obj00302 *)p)->fC330=0;
        ((struct Obj00302 *)p)->fC334=0;
        ((struct Obj00302 *)p)->fC338=0;
    }
}
