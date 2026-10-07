/*
 * file:     pokemontrade_proc_p19.c
 * unit:     yes
 * function: func_021DCB30, func_021DCBA4
 * address:  0x021DCB30
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DC854 0x021DC854 thumb ov119
 *   func_021DC894 0x021DC894 thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021E36C8 0x021E36C8 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_02015EA0 0x02015EA0 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_0204E720 0x0204E720 arm
 */
#include "../../matched/include/Obj04478.h"
#include "../../matched/include/Obj08060.h"
#include "../../matched/include/Obj22735.h"
#include "../../matched/include/Obj01728.h"
#include "../../matched/include/Obj03256.h"

typedef signed int     s32;

typedef unsigned int   u32;

extern void *func_021DC854(void *a, int t);
extern void func_021DC894(void *,int,void *,void *,int);
extern u32 func_020173EC(void);
extern void func_02082D44(void *,const void *,int);
extern void func_021E36C8(void *,int,int,void *,int);
extern int func_021D8AA8(void *);
extern void func_02015EA0(void *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
void func_021DCB30(void *a,int b,char *c);
void func_021DCBA4(char *a, char *p);

void func_021DCB30(void *a,int b,char *c) {const char *q=*(char * *)&((struct Obj04478 *)c)->f18;char *p=func_021DC854(a,0xc6000);if(q) {if(((struct Obj22735 *)q)->f1B0==2) {int i;for(i=0;i<2;i++) {const int *s=(const int *)(q+i*8);char *d=p+i*4;((struct Obj08060 *)d)->f1048=s[2];((struct Obj08060 *)d)->f1050=s[1];}} else {int j;for(j=0;j<2;j++){char *d=p+j*4;((struct Obj08060 *)d)->f1048=-1;((struct Obj08060 *)d)->f1050=-1;}}}func_021DC894(a,b,c,p,3);}

void func_021DCBA4(char *a, char *p)
{
    func_02082D44(((struct Obj01728 *)a)->f34,((struct Obj03256 *)p)->f5DC,func_020173EC());
    func_02082D44(((struct Obj01728 *)a)->f38,((struct Obj03256 *)p)->f5E0,func_020173EC());
    func_021E36C8(p,0,1,((struct Obj01728 *)a)->f34,1);
    func_021E36C8(p,1,1,((struct Obj01728 *)a)->f38,1);
    func_02015EA0((void *)(*(unsigned *)(p+(func_021D8AA8(p) == 0 ? 0x848 : 0x844))));
    ((struct Obj03256 *)p)->f830=((struct Obj01728 *)a)->f3C;
    ((struct Obj03256 *)p)->f834=((struct Obj01728 *)a)->f40;
    func_0203D34C(0,((struct Obj03256 *)p)->f5F4);
    func_0204E720(3,16,0,2);
}
