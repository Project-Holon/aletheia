/*
 * file:     unit_021B95A0_p03.c
 * unit:     yes
 * function: func_021B9D4C, func_021B9D80
 * address:  0x021B9D4C
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B98DC 0x021B98DC thumb ov213
 *   func_020061E4 0x020061E4 thumb
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021B9830 0x021B9830 thumb ov213
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021BA444 0x021BA444 thumb ov213
 *   func_021BA650 0x021BA650 thumb ov213
 *   func_021BA95C 0x021BA95C thumb ov213
 *   func_021BA68C 0x021BA68C thumb ov213
 *   func_021BA9D0 0x021BA9D0 thumb ov213
 *   func_0204E720 0x0204E720 arm
 */
#include "../../matched/include/Obj14692.h"
#include "../../matched/include/Obj25691.h"
#include "../../matched/include/Obj14693.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021B98DC(int,int);
extern void func_020061E4(u32 a);
extern void func_021B61F8(unsigned char *task, int value);
extern void func_021B9830(u8 *task, char *p);
extern unsigned func_021B61FC(const unsigned char *p);
extern int func_021BA9D0(unsigned char *p);
extern void func_021B6200(unsigned char *p);
extern void func_021BA444(void *);
extern void func_021BA650(char *p);
extern void func_021BA95C(unsigned char *p, int index);
extern void func_021BA68C(char *p, unsigned i, int kind);
extern void func_0204E720(unsigned,int,int,int);
int func_021B9D4C(u8 *task,char *p);
int func_021B9D80(void *state,char *p);

int func_021B9D4C(u8 *task,char *p) {if(((struct Obj14692 *)p)->f49CC==2){func_020061E4(func_021B98DC(4,((struct Obj25691 *)(*(char * *)&((struct Obj14692 *)p)->f4))->f50));func_021B61F8(task,2);return 1;}func_021B9830(task,p);return 1;}

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
