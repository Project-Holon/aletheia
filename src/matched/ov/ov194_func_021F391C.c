/*
 * function: func_021F391C
 * address: 0x021F391C
 * packet: pkt_ov194_021F391C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_021F3364 0x021F3364 thumb ov194
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021F366C 0x021F366C thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"
typedef struct {int left,top,right,bottom;} Rect;
extern unsigned func_021F2614(char *,int *,unsigned short *);
extern int func_021F3364(char *,int),func_021F2818(char *,int,int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned),func_021F366C(char *,int,int);
struct Rect;
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
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
            GFL_USE_PlaySeDefaultVolume(1611);((struct Obj00117 *)p)->fE4=2;((struct Obj00117 *)p)->fE8=6;
        }break;
    case 6:((struct Obj00117 *)p)->fE8=5;break;
    case 7:((struct Obj00117 *)p)->fE8=7;break;
    case 8:
        GFL_USE_PlaySeDefaultVolume(1356);((struct Obj00117 *)p)->fE8=8;
        func_021F366C(p,((struct Obj00117 *)p)->f104^1,((struct Obj00117 *)p)->f108);break;
    case 10:((struct Obj00117 *)p)->fE8=3;break;
    case 11:((struct Obj00117 *)p)->fE8=4;break;
    }
    if(func_021F2818(p,(int)(input+2),(int)&rect))
        func_021F1A1C(p+0x24,2,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}
