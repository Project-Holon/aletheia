/*
 * function: func_021844C8
 * address: 0x021844C8
 * packet: pkt_ov168_021844C8
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218449C 0x0218449C thumb ov168
 *   func_021845AC 0x021845AC thumb ov168
 *   func_021845E0 0x021845E0 thumb ov168
 *   func_02184600 0x02184600 thumb ov168
 *   func_0204B878 0x0204B878 arm
 *   d_02184A40 0x02184A40 data a4
 */
#include "../include/Obj01947.h"
#include "../include/Obj04544.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0218449C(void *);
extern int func_021845AC(u8);
struct Obj;
extern int func_021845E0(char *p);
extern int func_02184600(char *,int,u16,int,void *);
extern void func_0204B878(struct Obj *p, u16 value);
extern unsigned d_02184A40;
void func_021844C8(int event, char *p)
{
    char *q;
    int n,anim;
    if(event==0){
        q=p+0xf8;
        n=func_0218449C(q);
        if(((struct Obj04544 *)q)->f20<n){
            anim=func_021845AC(n);
            ((struct Obj04544 *)q)->f20=n;
            ((struct Obj04544 *)q)->f24=1;
        }else{
            anim=func_021845AC(((struct Obj04544 *)q)->f20);
            ((struct Obj04544 *)q)->f20-=2;
        }
        if(anim!=0){
            if(((struct Obj04544 *)q)->f24!=0){
                func_0204B878(((struct Obj01947 *)p)->f8,1);
                ((struct Obj04544 *)q)->f24=0;
            }
            if(func_021845E0(p)){
                func_02184600(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
            }else{
                --((struct Obj01947 *)p)->fE0;
                if(((struct Obj01947 *)p)->fE0==0){
                    func_02184600(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
                    ((struct Obj01947 *)p)->fE0=10;
                }
            }
            func_0204B878(((struct Obj01947 *)p)->f0,anim);
            func_0204B878(((struct Obj01947 *)p)->f4,anim);
        }else if(anim==0){
            func_0204B878(((struct Obj01947 *)p)->f8,0);
            func_0204B878(((struct Obj01947 *)p)->f0,0);
            func_0204B878(((struct Obj01947 *)p)->f4,0);
        }
        ++d_02184A40;
    }
}
