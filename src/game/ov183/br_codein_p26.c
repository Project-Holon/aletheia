/*
 * file:     br_codein_p26.c
 * unit:     yes
 * function: func_021E1C80, func_021E1D10, func_021E1D48
 * address:  0x021E1C80
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021E1DA8 0x021E1DA8 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   d_021E38E0 0x021E38E0 data a4
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 */
#include "../../matched/include/Obj02232.h"
#include "../../matched/include/Obj05482.h"
#include "../../matched/include/Obj10753.h"
#include "../../matched/include/Obj24629.h"
#include "../../matched/include/Obj04579.h"
#include "../../matched/include/Obj24630.h"
#include "../../matched/include/Obj24631.h"
#include "../../matched/include/Obj24632.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef struct {int a,b;} Pair;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021E1DA8(int,int *,char *);
extern u32 func_0201C440(void *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD860(int,int,Pair *);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void func_020315D4(struct S020315D4 *);
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(int);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
int func_021E1C80(struct Obj0203159C *obj,int unused,char *arg);
int func_021E1D10(struct S020315D4 *a,int b,char *q,char *p);
int func_021E1D48(int a,int b,int c,char *p);
extern const Pair d_021E38E0;

int func_021E1C80(struct Obj0203159C *obj,int unused,char *arg)
{
    char *p;
    int i;
    Pair pair;
    p=func_0203159C(obj,32,func_021F9B9C((struct Obj24810 *)(((struct Obj05482 *)arg)->fC)));
    func_02082BCC(p,0,32);
    *(char * *)&((struct Obj02232 *)p)->f18=arg;
    ((struct Obj02232 *)p)->f8=func_021F9B9C((struct Obj24810 *)(((struct Obj05482 *)arg)->fC));
    ((struct Obj02232 *)p)->f4=(int)func_021FD6D8((int)p,(int)func_021E1DA8,((struct Obj02232 *)p)->f8);
    ((struct Obj02232 *)p)->f0=func_0201C440((void *)(((struct Obj02232 *)p)->f8));
    ((struct Obj02232 *)p)->fC=(int)func_021FD12C(((struct Obj05482 *)arg)->f8,(void *)(((struct Obj02232 *)p)->f0),((struct Obj02232 *)p)->f8);
    func_021FD170((char *)(((struct Obj02232 *)p)->fC),(char *)(((struct Obj05482 *)arg)->f8),(void *)111);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x10)=(int)func_021FD760(((struct Obj05482 *)arg)->f4,(char *)(((struct Obj05482 *)arg)->f8),i,((struct Obj02232 *)p)->f8);
    pair=d_021E38E0;
    func_021FD860(((struct Obj02232 *)p)->f10,4,&pair);
    return 1;
}

int func_021E1D10(struct S020315D4 *a,int b,char *q,char *p){int i;for(i=0;i<2;i++)func_021FD820(*(char **)(p+i*4+16));func_021FD15C(((struct Obj10753 *)p)->fC,((struct Obj24629 *)q)->f8);func_0201C4C0(((struct Obj10753 *)p)->f0);func_021FD714((void *)(((struct Obj10753 *)p)->f4));func_020315D4(a);return 1;}

int func_021E1D48(int a,int b,int c,char *p)
{
    int i;
    if (!func_02012E40((const u8 *)(((struct Obj24630 *)(*(char * *)&((struct Obj04579 *)p)->f18))->f14)) && func_021FF88C((char *)(((struct Obj24631 *)(*(char * *)&((struct Obj04579 *)p)->f18))->f10))==2) {
        func_021F9C6C(((struct Obj24632 *)(*(char * *)&((struct Obj04579 *)p)->f18))->fC);
        return 1;
    }
    func_021FD71C((u8 *)(((struct Obj04579 *)p)->f4));
    if (func_021FD72C((int *)(((struct Obj04579 *)p)->f4))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x10)));
    func_0201C4E4((struct PrintSys *)(((struct Obj04579 *)p)->f0));
    func_021FD1BC((void *)(((struct Obj04579 *)p)->fC));
    return 0;
}
