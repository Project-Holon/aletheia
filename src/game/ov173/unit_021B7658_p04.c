/*
 * file:     unit_021B7658_p04.c
 * unit:     yes
 * function: func_021B8040, func_021B80A4, func_021B80C4, func_021B80EC, func_021B8110, func_021B815C, func_021B817C
 * address:  0x021B8040
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_0202822C 0x0202822C thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_02028230 0x02028230 thumb
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   func_021B7460  0x021B7460  thumb  ov173
 *   func_021B7568 0x021B7568 thumb ov173
 */
#include "../../matched/include/Obj00180.h"
#include "../../matched/include/Obj24194.h"
#include "../../matched/include/Obj24195.h"
#include "../../matched/include/Obj10671.h"
#include "../../matched/include/Obj24196.h"
#include "../../matched/include/Obj08266.h"
#include "../../matched/include/Obj05452.h"
#include "../../matched/include/Obj14319.h"
#include "../../matched/include/Obj14320.h"

struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0202822C(char *,int);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_02028230(u8 *p);
extern void func_021B7EB0(char *p, int flag);
extern void func_021B7460(char *p, u32 v);
extern u8 func_021B7568(void ***p);
void func_021B8040(u8 *p);
int func_021B80A4(char *p, u16 v);
int func_021B80C4(u8 *p,u16 n);
int func_021B80EC(char *p,unsigned short id);
int func_021B8110(u8 *p);
int func_021B815C(char *p);
int func_021B817C(char *p);

void func_021B8040(u8 *p)
{
    if(((struct Obj00180 *)p)->f1B8<=4) {
        func_0204B878(((struct Obj00180 *)p)->f108,17);
        func_0204B878(((struct Obj00180 *)p)->f104,16);
        return;
    }
    if(((struct Obj24194 *)(*(u8 * *)&((struct Obj00180 *)p)->f0))->f16+4 < ((struct Obj00180 *)p)->f1B8) {
        func_0204B878(((struct Obj00180 *)p)->f108,17);
        func_0204B878(((struct Obj00180 *)p)->f104,2);
        return;
    }
    if(((struct Obj24195 *)(*(u8 * *)&((struct Obj00180 *)p)->f0))->f16==0) {
        func_0204B878(((struct Obj00180 *)p)->f108,3);
        func_0204B878(((struct Obj00180 *)p)->f104,16);
    }
}


int func_021B80A4(char *p, u16 v)
{
    char *q = p + 0x1d0;

    ((struct Obj10671 *)q)->fA = 0;
    ((struct Obj10671 *)q)->f6 = 0xd;
    ((struct Obj10671 *)q)->f8 = v;
    func_0204B878((struct Obj *)(((struct Obj24196 *)p)->f138), 9);
    return 0xd;
}

int func_021B80C4(u8 *p,u16 n) {u8 *q;q=p+464;((struct Obj08266 *)q)->fA=1;((struct Obj08266 *)q)->f6=0;((struct Obj08266 *)q)->f8=n;func_0202822C(*(char **)(p+((struct Obj08266 *)q)->f6*4+544),1);return 13;}

int func_021B80EC(char *p,unsigned short id) {unsigned short *q=(unsigned short *)(p+0x1d0);q[5]=1;q[3]=1;q[4]=id;func_0202822C(*(char **)((unsigned)p+q[3]*4+0x220),1);return 13;}

int func_021B8110(u8 *p)
{
    u8 *s;
    s=p+464;
    if(((struct Obj05452 *)s)->fA==0) {
        if(func_0204B98C(*(void **)(p+260+((struct Obj05452 *)s)->f6*4))==0) return ((struct Obj05452 *)s)->f8;
    } else if(((struct Obj05452 *)s)->fA==1) {
        if(func_02028230(*(void **)(p+544+((struct Obj05452 *)s)->f6*4))!=0) {
            func_021B7EB0((char *)p,0);
            return ((struct Obj05452 *)s)->f8;
        }
    }
    return 13;
}


int func_021B815C(char *p)
{
    func_021B7460(p, 2);
    ((struct Obj14319 *)p)->f1BA = 1;
    *(u32 *)(p + 0x1ba - 0xa) = 3;
    return 2;
}

int func_021B817C(char *p) {unsigned char flag;if(func_021B7568((void ***)p)<4) {func_021B7460(p,1);flag=0;} else {func_021B7460(p,4);flag=2;}((struct Obj14320 *)p)->f1BA=flag;*(unsigned *)(p+0x1ba-10)=3;return 2;}
