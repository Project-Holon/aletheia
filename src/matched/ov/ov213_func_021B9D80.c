/*
 * function: func_021B9D80
 * address: 0x021B9D80
 * packet: pkt_ov213_021B9D80
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021BA444 0x021BA444 thumb ov213
 *   func_021BA650 0x021BA650 thumb ov213
 *   func_021BA95C 0x021BA95C thumb ov213
 *   func_021BA68C 0x021BA68C thumb ov213
 *   func_021BA9D0 0x021BA9D0 thumb ov213
 *   func_0204E720 0x0204E720 arm
 */
#include "../include/Obj14693.h"
extern unsigned func_021B61FC(const unsigned char *p);
extern int func_021BA9D0(unsigned char *p);
extern void func_021B6200(unsigned char *p);
extern void func_021BA444(void *);
extern void func_021BA650(char *p);
extern void func_021BA95C(unsigned char *p, int index);
extern void func_021BA68C(char *p, unsigned i, int kind);
extern void func_0204E720(unsigned,int,int,int);
int func_021B9D80(void *state,char *p)
{
    int stage;
    stage=func_021B61FC(state);
    func_021BA444(p);func_021BA650(p+0x498C);
    switch(stage) {
    case 0:
        func_021BA95C((unsigned char *)(p+0x24),5);((struct Obj14693 *)p)->f49D0=0;func_021B6200(state);break;
    case 1:
        if((((struct Obj14693 *)p)->f49D0)++==30) func_021BA68C(p+0x498C,2,2);
        if(func_021BA9D0((unsigned char *)(p+0x24))==0) {func_0204E720(3,0,16,-3);return 1;}
        break;
    case 2:break;
    }
    return 0;
}
