/*
 * function: func_021B9DD0
 * address: 0x021B9DD0
 * packet: pkt_ov222_021B9DD0
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 021B9E42; no follower.
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj02560.h"
#include "../include/Obj26080.h"
typedef unsigned char u8;
typedef signed short s16;
typedef struct {s16 x,y;} Pt;
extern unsigned func_02040804(unsigned);
extern void func_02041EE4(unsigned,unsigned,unsigned);
extern void func_0204B454(void*,Pt*,unsigned);
extern void func_0204B404(void*,const Pt*,unsigned);
void func_021B9DD0(char*p)
{
    int v;
    Pt pos;
    if(((struct Obj26080 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4==0){
        v=func_02040804(1);
        if(v!=0){
            if(((struct Obj02560 *)p)->f44==0){
                if(v>=2)v=2;
                func_02041EE4(1,5,v);func_02041EE4(2,5,v);
                func_0204B454(*(void* *)&((struct Obj02560 *)p)->f54,&pos,0);
                pos.y=pos.y+(s16)v;
                func_0204B404(*(void* *)&((struct Obj02560 *)p)->f54,&pos,0);
                ((struct Obj02560 *)p)->f44=0;
            }else --((struct Obj02560 *)p)->f44;
        }
    }
}
