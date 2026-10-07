/*
 * file:     namein_graphic_p13.c
 * unit:     yes
 * function: func_021F37EC, func_021F38CC, func_021F391C, func_021F3A0C
 * address:  0x021F37EC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 *   func_02035D20 0x02035D20 arm
 *   func_021F265C 0x021F265C thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_021F3364 0x021F3364 thumb ov194
 *   func_021F366C 0x021F366C thumb ov194
 *   func_021F26E0 0x021F26E0 thumb ov194
 */
#include "../../matched/include/Obj00117.h"
#include "../../matched/include/Obj14503.h"

struct Rect;
typedef unsigned char u8;

typedef struct {int x,y;} Pair;

typedef struct {int left,top,right,bottom;} Rect;

extern unsigned func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void func_020061E4(unsigned);
extern int func_021F2828(const char *,int,Pair *);
extern int func_021F2818(char *,int,int);
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F265C(char *,int *,int *);
extern unsigned func_021F2614(char *,int *,unsigned short *);
extern void func_020061E4(unsigned),func_021F366C(char *,int,int);
extern void func_021F26E0(char *,int,int);
int func_021F37EC(char *p,int *out);
int func_021F38CC(char *p,int *out);
void func_021F391C(char *p,int *input);
int func_021F3A0C(char *p,int *out);

int func_021F37EC(char *p,int *out)
{
    Rect rect;
    int changed;
    changed=0;
    if(func_020362DC()==1) {
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);
        out[1]=1;changed=1;
    }
    if(func_020362DC()==2) {
        func_021F2828(p,6,(Pair *)(out+2));out[0]=6;changed=1;
    }
    if(func_020362DC()==4) {
        out[0]=((struct Obj00117 *)p)->f100+3;
        if(out[0]>5)out[0]=2;
        func_021F2828(p,out[0],(Pair *)(p+0xD8));
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);changed=1;
    }
    if(func_020362DC()==256){((struct Obj00117 *)p)->fE8=10;changed=0;}
    if(changed && func_020355C4()==1) {
        if(func_021F2818(p,(int)(p+0xD8),(int)&rect)) {
            func_020061E4(1352);func_020355D8(0);
            func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            return 0;
        }
    }
    return changed;
}

int func_021F38CC(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(func_02035D20(&x,&y)) {
 point[0]=x;point[1]=y;
 if(func_021F265C(p,point,(int *)(p+0xD8))) {
 u=((struct Obj14503 *)p)->fD8;out[3]=((struct Obj14503 *)p)->fDC;out[1]=1;out[2]=u;func_020355D8(1);return 1;
 }}return 0;
}

void func_021F391C(char *p,int *input)
{
    unsigned code;
    Rect rect;
    if(input[1])code=func_021F2614(p,(int *)(p+0xD8),(unsigned short *)(p+0xFC));
    else code=input[0];
    switch(code){
    case 0:break;
    case 1:((struct Obj00117 *)p)->fE8=1;((struct Obj00117 *)p)->fE4=1;break;
    case 9:((struct Obj00117 *)p)->fE8=9;((struct Obj00117 *)p)->fE4=1;break;
    case 2:case 3:case 4:case 5:
        if(func_021F3364(p,code-2)){
            func_020061E4(1611);((struct Obj00117 *)p)->fE4=2;((struct Obj00117 *)p)->fE8=6;
        }break;
    case 6:((struct Obj00117 *)p)->fE8=5;break;
    case 7:((struct Obj00117 *)p)->fE8=7;break;
    case 8:
        func_020061E4(1356);((struct Obj00117 *)p)->fE8=8;
        func_021F366C(p,((struct Obj00117 *)p)->f104^1,((struct Obj00117 *)p)->f108);break;
    case 10:((struct Obj00117 *)p)->fE8=3;break;
    case 11:((struct Obj00117 *)p)->fE8=4;break;
    }
    if(func_021F2818(p,(int)(input+2),(int)&rect))
        func_021F1A1C(p+0x24,2,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}

/*
 * lever: Integer address arithmetic for26E0 avoids caching p+D8 across2818.
 */
int func_021F3A0C(char *p,int *out)
{
    Rect rect;
    Pair delta;
    Pair point;
    int changed=0;
    if(((struct Obj00117 *)p)->f118==0){
        if(func_020362DC()&64){delta.x=0;delta.y=-1;changed=1;}
        else if(func_020362DC()&128){delta.x=0;delta.y=1;changed=1;}
        else if(func_020362DC()&32){delta.x=-1;delta.y=0;changed=1;}
        else if(func_020362DC()&16){delta.x=1;delta.y=0;changed=1;}
    }
    if(changed){
        point=*(Pair *)(p+0xD8);
        func_021F26E0(p,(int)&point,(int)&delta);
        if(func_021F2614(p,&point.x,0)-2<=3){
            if(func_020355C4()==1){
                if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                    func_020061E4(1352);func_020355D8(0);
                    func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                }
            }else{
                func_021F26E0(p,(int)p+0xD8,(int)&delta);
                if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                    func_020061E4(1352);
                    func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                }
            }
        }
    }
    return 0;
}
