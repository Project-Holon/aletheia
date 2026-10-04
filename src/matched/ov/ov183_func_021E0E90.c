/*
 * function: func_021E0E90
 * address: 0x021E0E90
 * packet: pkt_ov183_021E0E90
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj00143.h"
#include "../include/Obj05480.h"
#include "../include/Obj05481.h"
typedef unsigned char u8;
typedef short s16;
typedef unsigned long u32;
typedef struct {s16 a,b,x,y;} Coords;
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *,struct PtS *,unsigned int);
extern void func_0204B404(void *,s16 *,int);
void func_021E0E90(char *p,int animated) {
    int i,group;
    s16 pos;
    char *record,*special;
    Coords coords;
    pos=*(s16 *)((u32)p+((struct Obj00143 *)p)->f240*2+0x214);
    group=0;
    for(i=0;i<((struct Obj00143 *)p)->f23C;i++){
        if(i>=((struct Obj00143 *)p)->f248&&i<((struct Obj00143 *)p)->f24C){
            if(i==((struct Obj00143 *)p)->f248)pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=(char *)((u32)p+i*28);
        func_0204B454(((struct Obj05480 *)record)->fC,(struct PtS *)&coords.x,1);
        if(animated==0){
            coords.x=pos;
            func_0204B404(((struct Obj05480 *)record)->fC,&coords.x,1);
        }else{
            ((struct Obj05480 *)record)->f14=(pos-coords.x)/4;
            ((struct Obj05480 *)record)->f16=0;
            ((struct Obj05480 *)record)->f18=4;
            ((struct Obj05480 *)record)->f19=0;
        }
        special=(char *)((u32)p+group*28);
        if(i==((struct Obj05481 *)special)->f150&&group!=2){
            func_0204B454(((struct Obj05481 *)special)->f15C,(struct PtS *)&coords.a,1);
            if(((struct Obj00143 *)p)->f248==((struct Obj00143 *)p)->f24C)pos+=8;
            else {
                if(i>((struct Obj00143 *)p)->f248&&i<((struct Obj00143 *)p)->f24C)pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                func_0204B404(((struct Obj05481 *)special)->f15C,&coords.a,1);
            }else{
                ((struct Obj05481 *)special)->f164=(pos-coords.a)/4;
                ((struct Obj05481 *)special)->f166=0;
                ((struct Obj05481 *)special)->f168=4;
            }
            group++;
        }
    }
}
