/*
 * function: func_021F36E8
 * address: 0x021F36E8
 * packet: pkt_ov194_021F36E8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Integer address arithmetic for26E0 keeps p+D8 apart from2818's pointer arithmetic.
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F26E0 0x021F26E0 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"
typedef unsigned char u8;
typedef struct {int x,y;} Pair;
typedef struct {unsigned char pad[0xD8];Pair xy;} Ctx;
typedef struct {int left,top,right,bottom;} Rect;
extern unsigned func_0203633C(void),func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8),func_020061E4(unsigned);
extern int func_021F2828(const char *,int,Pair *);
extern int func_021F2818(char *,int,int);
extern void func_021F26E0(char *,int,int);
extern void func_021F1A1C(char *,int,const Rect *,int,int);
int func_021F36E8(char *p,int *out)
{
    Rect rect;
    Pair delta;
    int changed=0;
    if(func_0203633C()&64){delta.x=0;delta.y=-1;changed=1;}
    else if(func_0203633C()&128){delta.x=0;delta.y=1;changed=1;}
    else if(func_0203633C()&32){delta.x=-1;delta.y=0;changed=1;}
    else if(func_0203633C()&16){delta.x=1;delta.y=0;changed=1;}
    else if(func_020362DC()&8){
        delta.x=0;delta.y=0;changed=1;
        func_021F2828(p,7,(Pair *)(p+0xD8));
        func_021F26E0(p,(int)(p+0xD8),(int)&delta);
    }
    if(changed){
        if(func_020355C4()==1){
            if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                func_020355D8(0);
                func_021F1A1C(p+0x24,1,&rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                func_020061E4(1352);
            }
        }else{
            func_021F26E0(p,(int)p+0xD8,(int)&delta);
            if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                func_020061E4(1352);
                func_021F1A1C(p+0x24,1,&rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            }
        }
    }
    return 0;
}
