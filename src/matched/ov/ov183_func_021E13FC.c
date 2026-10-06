/*
 * function: func_021E13FC
 * address: 0x021E13FC
 * packet: pkt_ov183_021E13FC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 *   func_021E1008 0x021E1008 thumb ov183
 *   func_021E1C14 0x021E1C14 thumb ov183
 *   func_021E1C44 0x021E1C44 thumb ov183
 *   func_021E0D00 0x021E0D00 thumb ov183
 *   func_021E1C00 0x021E1C00 thumb ov183
 *   func_021E1374 0x021E1374 thumb ov183
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 */
#include "../include/Obj00417.h"
#include "../include/Obj00478.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef struct {s16 a,b,x,y;} Coords;
typedef struct {u32 x,y;} Pair;
extern const int d_021E3998[],d_021E397C[];
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *,struct PtS *,unsigned int);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Pair;
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021E0E40(int,int);
extern void func_021E0CE8(char *p, int index, int a2);
extern void func_021E1008(char *);
extern int func_021E1C14(char *,int);
extern int func_021E1C44(const char *p, int a);
extern void func_021E0D00(char *,int);
extern void func_021E1C00(char *);
extern void func_021E1374(char *,int);
int func_021E13FC(char *p) {
    int i,factor,selected;
    char *record;
    Pair scale;
    Coords coords;
    switch(((struct Obj00478 *)p)->f234){
    case 0:
        func_021E0CE8(p,0,0);
        for(i=0;i<((struct Obj00478 *)p)->f23C;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f18!=0){
                func_0204B454(((struct Obj00417 *)record)->fC,(struct PtS *)&coords.x,1);
                coords.x+=((struct Obj00417 *)record)->f14;
                coords.y+=((struct Obj00417 *)record)->f16;
                func_0204B404(((struct Obj00417 *)record)->fC,(const struct Vec2 *)(&coords.x),1);
                --((struct Obj00417 *)record)->f18;
                if(i>=((struct Obj00478 *)p)->f248&&i<((struct Obj00478 *)p)->f24C){
                    factor=*(int *)((u32)d_021E3998+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
                if(i>=((struct Obj00478 *)p)->f250&&i<((struct Obj00478 *)p)->f254){
                    factor=*(int *)((u32)d_021E397C+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
            }
        }
        for(i=0;i<2;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f168!=0){
                func_0204B454(((struct Obj00417 *)record)->f15C,(struct PtS *)&coords.a,1);
                coords.a+=((struct Obj00417 *)record)->f164;
                coords.b+=((struct Obj00417 *)record)->f166;
                func_0204B404(((struct Obj00417 *)record)->f15C,(const struct Vec2 *)(&coords.a),1);
                --((struct Obj00417 *)record)->f168;
            }
        }
        if(((struct Obj00478 *)p)->f18==0){
            for(i=((struct Obj00478 *)p)->f248;i<((struct Obj00478 *)p)->f24C;i++){
                record=(char *)((u32)p+i*28);
                func_0204B878(((struct Obj00417 *)record)->fC,func_021E0E40(((struct Obj00417 *)record)->f0,((struct Obj00417 *)record)->f8));
            }
            for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
                record=(char *)((u32)p+i*28);
                func_0204B878(((struct Obj00417 *)record)->fC,func_021E0E40(((struct Obj00417 *)record)->f0,((struct Obj00417 *)record)->f8));
            }
            ++((struct Obj00478 *)p)->f234;
        }
        ++((struct Obj00478 *)p)->f238;
        break;
    case 1:
        for(i=((struct Obj00478 *)p)->f248;i<((struct Obj00478 *)p)->f24C;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32)d_021E3998+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32)d_021E397C+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        if(++((struct Obj00478 *)p)->f238==6)++((struct Obj00478 *)p)->f234;
        break;
    default:
        func_021E1008(p);
        if(((struct Obj00478 *)p)->f320==0)selected=func_021E1C14(p,((struct Obj00478 *)p)->f31C);
        else selected=func_021E1C44(p,((struct Obj00478 *)p)->f31C);
        func_021E0D00(p,selected);
        if(((struct Obj00478 *)p)->f240!=0)func_021E0CE8(p,0,1);
        func_021E1C00(p);
        func_021E1374(p,1);
        break;
    }
    return 0;
}
