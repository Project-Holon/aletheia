/*
 * function: func_021F37EC
 * address: 0x021F37EC
 * packet: pkt_ov194_021F37EC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 2818 keeps live r0 from its callback, caller tests that result.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"
typedef unsigned char u8;
typedef struct {int x,y;} Pair;
typedef struct {int left,top,right,bottom;} Rect;
extern unsigned KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int func_021F2828(const char *,int,Pair *);
extern int func_021F2818(char *,int,int);
struct Rect;
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
int func_021F37EC(char *p,int *out)
{
    Rect rect;
    int changed;
    changed=0;
    if(KEY_GetTrg()==1) {
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);
        out[1]=1;changed=1;
    }
    if(KEY_GetTrg()==2) {
        func_021F2828(p,6,(Pair *)(out+2));out[0]=6;changed=1;
    }
    if(KEY_GetTrg()==4) {
        out[0]=((struct Obj00117 *)p)->f100+3;
        if(out[0]>5)out[0]=2;
        func_021F2828(p,out[0],(Pair *)(p+0xD8));
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);changed=1;
    }
    if(KEY_GetTrg()==256){((struct Obj00117 *)p)->fE8=10;changed=0;}
    if(changed && func_020355C4()==1) {
        if(func_021F2818(p,(int)(p+0xD8),(int)&rect)) {
            GFL_USE_PlaySeDefaultVolume(1352);func_020355D8(0);
            func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            return 0;
        }
    }
    return changed;
}
