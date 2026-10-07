/*
 * file:     unit_021F8480_p01.c
 * unit:     yes
 * function: func_021F8480, func_021F851C, func_021F857C, func_021F85DC, func_021F8624
 * address:  0x021F8480
 * region:   ov184
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
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_0200A640 0x0200A640 thumb
 *   func_021F88A4 0x021F88A4 thumb ov184
 *   func_021F891C 0x021F891C thumb ov184
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021F89D0 0x021F89D0 thumb ov184
 *   func_021F88E0 0x021F88E0 thumb ov184
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
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
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   func_021F8670   0x021F8670  thumb
 *   func_021FE784   0x021FE784  thumb
 *   func_021FE7B0   0x021FE7B0  thumb
 *   func_021FD73C   0x021FD73C  thumb
 *   func_021FD744   0x021FD744  thumb
 *   func_021F9BA0   0x021F9BA0  thumb
 */
#include "../../matched/include/Obj02898.h"
#include "../../matched/include/Obj06617.h"
#include "../../matched/include/Obj02233.h"
#include "../../matched/include/Obj04581.h"
#include "../../matched/include/Obj03336.h"
#include "../../matched/include/Obj24698.h"
#include "../../matched/include/Obj24699.h"
#include "../../matched/include/Obj14447.h"
#include "../../matched/include/Obj08318.h"

struct Obj24810;
struct Obj0203159C;
struct Big;
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
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A5F8(void *sys);
extern int func_0200A640(int);
extern void func_021F88A4(char *,char *);
extern void func_021F891C(char *p, const char *q);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD714(void *p);
extern void func_021F89D0(int *,char *);
extern void func_021F88E0(char *,char *);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_02025588(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_02034A5C(int);
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern void func_021F3C50(u8 *p);
extern void func_021F8670(int a, int b, char *p);
extern int func_021FE784(int, int, int, int);
extern int func_021FE7B0(int);
extern void func_021FD73C(int, void *);
extern void func_021FD744(int);
extern void func_021F9BA0(int);
int func_021F8480(void *obj,int b,char *q);
int func_021F851C(int obj,int b,char *q,char *p);
int func_021F857C(int a,int b,int c,char *p);
void func_021F85DC(int a, int *state, char *p);
void func_021F8624(int a, int *state, char *p);
extern char ov112_id[];

int func_021F8480(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=func_0203159C(obj,0x34,func_021F9B9C(((struct Obj06617 *)q)->f10));
    func_02082BCC(p,0,0x34);
    ((struct Obj02898 *)p)->f24=func_021F9B9C(((struct Obj06617 *)q)->f10);
    *(char * *)&((struct Obj02898 *)p)->f30=q;
    ((struct Obj02898 *)p)->f20=func_0201C440((void *)(unsigned int)((struct Obj02898 *)p)->f24);
    v=(void *)func_021FC4DC(((struct Obj06617 *)q)->f8);
    ((struct Obj02898 *)p)->f1C=func_02025538(((struct Obj02898 *)p)->f24,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x14)=func_021FD760((unsigned int)v,(char *)(((struct Obj06617 *)q)->fC),i,((struct Obj02898 *)p)->f24);
    ((struct Obj02898 *)p)->f28=func_0200A640((int)func_0200A5F8((void *)func_02012EBC((struct Big *)(((struct Obj06617 *)q)->f18))));
    func_021F88A4(p,q);
    func_021F891C(p,q);
    ((struct Obj02898 *)p)->fC=func_021FD6D8((int)p,(int)func_021F85DC,((struct Obj02898 *)p)->f24);
    return 1;
}

int func_021F851C(int obj,int b,char *q,char *p)
{
    int i;
    func_021FD714((void *)(((struct Obj02233 *)p)->fC));
    func_021F89D0((int *)p,q);
    func_021F88E0(p,q);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x14));
    if (((struct Obj02233 *)p)->f10) {
        func_021FD15C(((struct Obj02233 *)p)->f10,((struct Obj04581 *)q)->fC);
        *(int *)&((struct Obj02233 *)p)->f10=0;
    }
    func_02025588((void *)(((struct Obj02233 *)p)->f1C));
    func_0201C4C0((struct PrintSys *)(((struct Obj02233 *)p)->f20));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}

int func_021F857C(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char * *)&((struct Obj24698 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f14)==2) {
        func_021F9C6C(*(char * *)&((struct Obj24699 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(*(char * *)&((struct Obj03336 *)p)->fC));
    if (func_021FD72C(*(int * *)&((struct Obj03336 *)p)->fC)) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+20));
    func_0201C4E4((struct PrintSys *)(((struct Obj03336 *)p)->f20));
    if (*(char * *)&((struct Obj03336 *)p)->f10) func_021FD1BC(*(char * *)&((struct Obj03336 *)p)->f10);
    if (*(char * *)&((struct Obj03336 *)p)->f0) func_021F3C50((u8 *)(*(char * *)&((struct Obj03336 *)p)->f0));
    return 0;
}


/*
 *   wildcarded because that address lies outside ov184's own 0x5A0-byte
 *   region and no listing labels it -- the only branch image-wide is the
 *   one inside this range.
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   finish through 0x21FD73C on 2.
 */
void func_021F85DC(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784(*(int *)(((struct Obj14447 *)p)->f30), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int *)(((struct Obj14447 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD73C(a, func_021F8670);
        break;
    }
}


/*
 *   outside ov184's 0x5A0-byte region and no listing labels them, so the
 *   two calls stay wildcarded.
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   release the two child handles on 2.
 */
void func_021F8624(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784(*(int *)(((struct Obj08318 *)p)->f30), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int *)(((struct Obj08318 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD744(((struct Obj08318 *)p)->fC);
        func_021F9BA0(*(int *)(((struct Obj08318 *)p)->f30 + 0x10));
        break;
    }
}
