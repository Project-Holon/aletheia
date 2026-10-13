/*
 * function: func_021BBB28
 * address: 0x021BBB28
 * packet: pkt_ov223_021BBB28
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C60 return consumed at BB B2, as in matched BB0B0, despite own void forwarding declaration.
 * symbols:
 *   func_021B9914 0x021B9914 thumb ov223
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj00792.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B9914(char *);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_020061E4(u32);
extern void func_0207D63C(u32,int,int,int,int);
int func_021BBB28(char *p,u32 *state)
{
    int changed=0;
    switch(*state) {
    case 0: func_021B9914(p);if(((struct Obj00792 *)p)->f50==134) ++*state;break;
    case 1:
        if(((struct Obj00792 *)p)->f268<8) {++((struct Obj00792 *)p)->f268;changed=1;}
        func_021B9914(p);if(((struct Obj00792 *)p)->f50==138) ++*state;break;
    case 2:
        if(((struct Obj00792 *)p)->f268<8) {++((struct Obj00792 *)p)->f268;changed=1;}
        else {((struct Obj00792 *)p)->f24|=1;++*state;}
        break;
    case 3: ++*state;break;
    case 4:
        if((func_020362DC()&3)!=0||TOUCHPANEL_GetTrg()!=0) {
            if((func_020362DC()&3)!=0) ((struct Obj00792 *)p)->f8=0;
            else ((struct Obj00792 *)p)->f8=1;
            func_020061E4(1356);++*state;
        }
        break;
    case 5:
        ((struct Obj00792 *)p)->f24|=2;
        if(((struct Obj00792 *)p)->f268!=0) {--((struct Obj00792 *)p)->f268;changed=1;}
        ++*state;break;
    case 6:
        if(((struct Obj00792 *)p)->f268!=0) {--((struct Obj00792 *)p)->f268;changed=1;}
        if(((struct Obj00792 *)p)->f268==4) ++*state;break;
    case 7:
        if(((struct Obj00792 *)p)->f268!=0) {--((struct Obj00792 *)p)->f268;changed=1;}
        func_021B9914(p);
        if(((struct Obj00792 *)p)->f50==180) func_020061E4(1956);
        if(((struct Obj00792 *)p)->f50==199) {((struct Obj00792 *)p)->f10=0;return 5;}
        break;
    }
    if(changed) func_0207D63C(0x04000050,5,63,((struct Obj00792 *)p)->f268,16-((struct Obj00792 *)p)->f268);
    ++((struct Obj00792 *)p)->f10;
    return 4;
}
