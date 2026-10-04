/*
 * function: func_021F8C30
 * address: 0x021F8C30
 * packet: pkt_ov185_021F8C30
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: 021F8C9E passes r1 to func_021F8EE8 despite its unused second input.
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021F8D18 0x021F8D18 thumb ov185
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E90 0x021F8E90 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F86E4 0x021F86E4 thumb ov185
 */
#include "../include/Obj01769.h"
#include "../include/Obj24755.h"
#include "../include/Obj24756.h"
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,int);
extern int func_021FC20C(char *),func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
extern void func_021F8D18(char *,int *),func_021F8D5C(char *,int *),func_021F8E90(char *,int *),func_021F8EE8(char *,int *);
extern void func_021F86E4(int,int,char *);
void func_021F8C30(int *task,int *state,char *p)
{
    int flag,a,b,c;
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj01769 *)p)->f34,1,1,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=2;break;
    case 2:
        flag=1;
        if(!((struct Obj01769 *)p)->f14) flag=0;
        if(flag) {
            func_021F8D5C(p,*(int * *)&((struct Obj01769 *)p)->f34);
            func_021F8E90(p,*(int * *)&((struct Obj01769 *)p)->f34);
        } else {
            func_021F8EE8(p,*(int * *)&((struct Obj01769 *)p)->f34);
            func_021F8D18(p,*(int * *)&((struct Obj01769 *)p)->f34);
        }
        a=func_021FC20C(*(char * *)&((struct Obj24755 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        b=func_021FC214(*(char * *)&((struct Obj24756 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        if(flag) {((struct Obj01769 *)p)->f20=0;c=0x72;}
        else {((struct Obj01769 *)p)->f20=1;c=0x71;}
        func_021FC754(*(char * *)&((struct Obj01769 *)p)->f1C,(void *)b,(void *)c,(void *)a,0x3da0);
        *state=3;break;
    case 3: func_021FE784(**(int * *)&((struct Obj01769 *)p)->f34,1,1,0);*state=4;break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=5;break;
    case 5: func_021FD73C(task,(int)func_021F86E4);break;
    }
}
