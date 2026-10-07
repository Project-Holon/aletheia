/*
 * file:     br_codein_p20.c
 * unit:     yes
 * function: func_021DF920, func_021DF9C8, func_021DFA10, func_021DFB90, func_021DFC88
 * address:  0x021DF920
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
 *   func_0201C440 0x0201C440 thumb
 *   func_02025538 0x02025538 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021E02F8 0x021E02F8 thumb ov183
 *   func_021E037C 0x021E037C thumb ov183
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   d_021E37A8 0x021E37A8 data a4
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 */
#include "../../matched/include/Obj01765.h"
#include "../../matched/include/Obj02230.h"
#include "../../matched/include/Obj10749.h"
#include "../../matched/include/Obj14433.h"
#include "../../matched/include/Obj05476.h"
#include "../../matched/include/Obj05477.h"
#include "../../matched/include/Obj05478.h"
#include "../../matched/include/Obj24620.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int (*Method)(char *,int *);

struct Methods { Method init,update,finish; };

struct Request { u16 x,y,id; u8 flag,pad; };

struct Rec6 { u8 x,y,id,pad; u16 file; };

struct Rec8 { u8 a,b,c,d; void *value; };

struct Triple { int a,b,c; };

extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned int);
extern u32 func_0201C440(void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_021E02F8(char *p, int *q);
extern void func_021E037C(char *, char *);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
extern void func_021FD15C(void *, int);
extern void func_02025588(void *);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern int func_021FC830(u8 *p);
extern void func_021FD1BC(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD854(char *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern int func_021FC124(int,int,struct Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_020409B4(unsigned int);
extern void func_021FBDA4(int a, unsigned mode);
int func_021DF920(void *obj, int unused, char *q);
int func_021DF9C8(void *p, int unused, char *q, char *data);
int func_021DFA10(void *unused,u32 *state,int *q,char *p);
int func_021DFB90(char *p,char *q);
int func_021DFC88(char *p, char *q);
extern const struct Methods d_021E37A8[];
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];

int func_021DF920(void *obj, int unused, char *q)
{
    char *p;
    int i;
    p = func_0203159C(obj, 0x58, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC)));
    func_02082BCC(p, 0, 0x58);
    ((struct Obj01765 *)p)->f54 = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC));
    ((struct Obj01765 *)p)->f48 = (void *)func_0201C440((void *)(((struct Obj01765 *)p)->f54));
    ((struct Obj01765 *)p)->f44 = func_02025538(((struct Obj01765 *)p)->f54, ((struct Obj02230 *)q)->f4);
    ((struct Obj01765 *)p)->f38 = (int)func_021FD12C(((struct Obj02230 *)q)->f8, (void *)(*(int *)&((struct Obj01765 *)p)->f48), ((struct Obj01765 *)p)->f54);
    func_021FD170((char *)(((struct Obj01765 *)p)->f38), (char *)(((struct Obj02230 *)q)->f8), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)(p + i * 4 + 0x3C) = (int)func_021FD760(*(int *)&((struct Obj02230 *)q)->f4, (char *)(((struct Obj02230 *)q)->f8), i, ((struct Obj01765 *)p)->f54);
    }
    ((struct Obj02230 *)q)->f14 = 0xFFFF;
    ((struct Obj02230 *)q)->f16 = 0xFF;
    ((struct Obj02230 *)q)->f17 = 0xFF;
    ((struct Obj02230 *)q)->f18 = 0x13;
    func_021FBE54((char *)(((struct Obj02230 *)q)->f8), 6, ((struct Obj01765 *)p)->f54);
    func_021E02F8(p, (int *)q);
    return 1;
}

int func_021DF9C8(void *p, int unused, char *q, char *data)
{
    int i;
    func_021E037C(data, q);
    func_021FC0C8((char *)(((struct Obj14433 *)q)->f8), 6);
    for (i = 0; i < 2; i++) func_021FD820(*(char **)(data + i * 4 + 0x3c));
    func_021FD15C(((struct Obj10749 *)data)->f38, ((struct Obj14433 *)q)->f8);
    func_02025588(((struct Obj10749 *)data)->f44);
    func_0201C4C0(((struct Obj10749 *)data)->f48);
    func_020315D4(p);
    return 1;
}

int func_021DFA10(void *unused,u32 *state,int *q,char *p)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 1: func_021FE784(q[0],2,3,0); ++*state; break;
    case 2: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(p+0x4c)].update(p,q)) {
        if(((struct Obj05476 *)p)->f50==-1) *state=10; else *state=4;
    } break;
    case 4: func_021FE784(q[0],2,2,1); ++*state; break;
    case 5: if(func_021FE7B0((int *)q[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) {
        ((struct Obj05476 *)p)->f4C=((struct Obj05476 *)p)->f50; ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 8: func_021FE784(q[0],2,2,0); ++*state; break;
    case 9: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 10: func_021FE784(q[0],2,3,1); ++*state; break;
    case 11: if(func_021FE7B0((int *)q[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(p+i*4)) func_021FC830(*(void **)(p+i*4));
    for(i=0;i<6;i++) if(*(void **)(p+0x20+i*4)) func_021FC830(*(void **)(p+0x20+i*4));
    if(((struct Obj05476 *)p)->f38) func_021FD1BC(((struct Obj05476 *)p)->f38);
    func_0201C4E4(((struct Obj05476 *)p)->f48);
    for(i=0;i<2;i++) func_021FD854(*(char **)(p+0x3c+i*4));
    return 0;
}

int func_021DFB90(char *p,char *q)
{
    int first,second,i;
    struct Request req;
    struct Triple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=func_021FC20C(*(char * *)&((struct Obj05478 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj05478 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj05478 *)q)->f8),26,((struct Obj05477 *)p)->f54);
    func_02082BCC(&req,0,8);
    func_021FC124(*(int *)&((struct Obj05478 *)q)->f8,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.x=r->x; req.y=r->y; req.id=r->id; req.flag=1;
        *(void **)(p+0xc+i*4)=func_021FB378(&req,r->file,0x60,1,((struct Obj05478 *)q)->f4,((struct Obj05477 *)p)->f44,first,second,&triple,((struct Obj05477 *)p)->f54);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        *(void **)(p+i*4)=func_021FC6A4(4,s->a,s->b,s->c,s->d,14,((struct Obj05477 *)p)->f48,((struct Obj05477 *)p)->f54);
        func_021FC754(*(char **)(p+i*4),(void *)second,s->value,(void *)first,0x3da0);
    }
    func_021FD170(((struct Obj05477 *)p)->f38,(char *)(*(int *)&((struct Obj05478 *)q)->f8),(void *)107);
    return 1;
}

int func_021DFC88(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(p + i * 4) != 0) {
            func_021FC734(*(void **)(p + i * 4));
            *(void **)(p + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(p + i * 4 + 12) != 0) {
            func_021FB494(*(void **)(p + i * 4 + 12));
            *(void **)(p + i * 4 + 12) = 0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(((struct Obj24620 *)q)->f8, 26);
    return 1;
}
