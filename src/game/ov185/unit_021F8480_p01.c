/*
 * file:     unit_021F8480_p01.c
 * unit:     yes
 * function: func_021F8480, func_021F8518, func_021F8590
 * address:  0x021F8480
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02025538 0x02025538 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_02040588 0x02040588 arm
 *   func_021F8EFC 0x021F8EFC thumb ov185
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021F8604 0x021F8604 thumb ov185
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E60 0x021F8E60 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F8F58 0x021F8F58 thumb ov185
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD6B0 0x021FD6B0 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 */
#include "../../matched/include/Obj00278.h"
#include "../../matched/include/Obj02526.h"
#include "../../matched/include/Obj03337.h"
#include "../../matched/include/Obj04583.h"
#include "../../matched/include/Obj01966.h"
#include "../../matched/include/Obj24716.h"
#include "../../matched/include/Obj24717.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

extern int func_02034AC4(s32 handle);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *);
extern u32 func_021FC4DC(u8 *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021F8EFC(char *p, int *source);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021F8604(int,int *,char *);
extern void func_021F8D5C(char *,char *);
extern void func_021F8E60(char *,char *);
extern void func_021F8EE8(char *p, int *a1);
extern void func_021F8F58(char *,char *);
extern void func_021F8FB0(char *,char *);
extern void func_021FD714(void *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
extern void func_02025588(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_02034A5C(int);
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021FC830(u8 *p);
extern int func_021FD6B0(u8 *p);
extern void func_021FD1BC(void *p);
extern void func_021F3C50(u8 *p);
int func_021F8480(void *obj,int b,char *q);
int func_021F8518(int obj,int b,char *q,char *p);
int func_021F8590(int a,int b,int c,char *p);
extern char ov112_id[];

int func_021F8480(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=func_0203159C(obj,88,func_021F9B9C(((struct Obj02526 *)q)->f10));
    func_02082BCC(p,0,88);
    *(char * *)&((struct Obj00278 *)p)->f34=q;
    ((struct Obj00278 *)p)->f30=func_021F9B9C(((struct Obj02526 *)q)->f10);
    ((struct Obj00278 *)p)->f2C=func_0201C440((void *)(unsigned int)((struct Obj00278 *)p)->f30);
    v=(void *)func_021FC4DC(((struct Obj02526 *)q)->f8);
    ((struct Obj00278 *)p)->f28=func_02025538(((struct Obj00278 *)p)->f30,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+56)=func_021FD760((unsigned int)v,(char *)(((struct Obj02526 *)q)->fC),i,((struct Obj00278 *)p)->f30);
    func_021FBE54((char *)(((struct Obj02526 *)q)->fC),6,((struct Obj00278 *)p)->f30);
    func_02040588(0,1);
    func_021F8EFC(p,(int *)q);
    ((struct Obj00278 *)p)->f24=func_021FD6D8((int)p,(int)func_021F8604,((struct Obj00278 *)p)->f30);
    return 1;
}

int func_021F8518(int obj,int b,char *q,char *p)
{
    int i;
    func_021F8D5C(p,q);
    func_021F8E60(p,q);
    func_021F8EE8(p,(int *)q);
    func_021F8F58(p,q);
    func_021F8FB0(p,q);
    func_021FD714((void *)(((struct Obj03337 *)p)->f24));
    func_021F8F58(p,q);
    func_021FC0C8((char *)(*(int *)&((struct Obj04583 *)q)->fC),6);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+56));
    func_02025588((void *)(((struct Obj03337 *)p)->f28));
    func_0201C4C0((struct PrintSys *)(((struct Obj03337 *)p)->f2C));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}

int func_021F8590(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char * *)&((struct Obj24716 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f14)==2) {
        func_021F9C6C(*(char * *)&((struct Obj24717 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(*(char * *)&((struct Obj01966 *)p)->f24));
    if (func_021FD72C(*(int * *)&((struct Obj01966 *)p)->f24)) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+56));
    func_0201C4E4((struct PrintSys *)(((struct Obj01966 *)p)->f2C));
    if (*(char * *)&((struct Obj01966 *)p)->f1C) func_021FC830((u8 *)(*(char * *)&((struct Obj01966 *)p)->f1C));
    if (*(char * *)&((struct Obj01966 *)p)->f10) func_021FD6B0((u8 *)(*(char * *)&((struct Obj01966 *)p)->f10));
    if (*(char * *)&((struct Obj01966 *)p)->f4) func_021FD1BC(*(char * *)&((struct Obj01966 *)p)->f4);
    if (*(char * *)&((struct Obj01966 *)p)->f14) func_021F3C50((u8 *)(*(char * *)&((struct Obj01966 *)p)->f14));
    return 0;
}
