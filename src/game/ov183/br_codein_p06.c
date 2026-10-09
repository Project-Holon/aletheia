/*
 * file:     br_codein_p06.c
 * unit:     yes
 * function: func_021E24C4, func_021E24F8, func_021E2538, func_021E2578, func_021E25E4, func_021E2640, func_021E26B8, func_021E2910, func_021E2AE0, func_021E2C2C, func_021E2E30, func_021E2E48, func_021E2E60, func_021E2E70, func_021E2F54
 * address:  0x021E24C4
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
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021E2F98 0x021E2F98 thumb ov183
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF698 0x021FF698 thumb ov186
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B938 0x0200B938 thumb
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021E300C 0x021E300C thumb ov183
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021E31E8 0x021E31E8 thumb ov183
 *   func_021E3228 0x021E3228 thumb ov183
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021D7540 0x021D7540 thumb ov125
 *   d_021E3910 0x021E3910 data a4
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3928 0x021E3928 data a4
 */
#include "../../matched/include/Obj24668.h"
#include "../../matched/include/Obj24669.h"
#include "../../matched/include/Obj24670.h"
#include "../../matched/include/Obj03332.h"
#include "../../matched/include/Obj06614.h"
#include "../../matched/include/Obj03333.h"
#include "../../matched/include/Obj24671.h"
#include "../../matched/include/Obj24672.h"
#include "../../matched/include/Obj03883.h"
#include "../../matched/include/Obj24673.h"
#include "../../matched/include/Obj24674.h"
#include "../../matched/include/Obj24675.h"
#include "../../matched/include/Obj01074.h"
#include "../../matched/include/Obj24678.h"
#include "../../matched/include/Obj03334.h"
#include "../../matched/include/Obj14443.h"
#include "../../matched/include/Obj14444.h"
#include "../../matched/include/Obj10762.h"
#include "../../matched/include/Obj14445.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
struct Big;
struct SOCLResource;
struct Pair;
struct U16Vec;
struct WordSet;
struct MsgBank;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef signed long long s64;

typedef enum { STATE_ZERO=0, STATE_TWELVE=12 } State;

typedef struct {u32 a,b;} Pair;

typedef struct {u32 words[2];} Request;

typedef struct {u32 fields[7];Pair request;} Arg;

typedef struct { u32 a,b; } Pair_021E2910;

typedef struct Pair_021E2AE0 {int a,b;} Pair_021E2AE0;

typedef struct Pair_021E2C2C {int x,y;} Pair_021E2C2C;

typedef union Config {u64 wide;Pair_021E2C2C pair;} Config;

typedef struct Pair_021E2E60 {int a,b;} Pair_021E2E60;

typedef struct Table {int head[4];Pair_021E2E60 pair;} Table;

extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int,unsigned);
extern void func_020409B4(u32 index);
extern void func_021FD860(int obj, int one, int *args);
extern void func_020061E4(u32 a);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void * func_02082BCC(void *,int,unsigned);
extern void *func_02025538(unsigned int a0, void *a1);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern u32 func_0201C440(void *);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void func_02025588(void *p);
extern void func_021F9BA0(unsigned *ctx);
extern void func_020315D4(struct S020315D4 *);
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(int);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern int func_021FC830(u8 *p);
extern void func_021E2F98(struct SOCLResource *resource);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern int func_021FF698(char *p, int a1, int *out);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_0200B928(void);
extern void func_0200B938(const void *,const void *,const void *,void *);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021FD170(char *p, char *q, void *text);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *,u32 *);
extern int *func_021FD73C(int *p, int v);
extern int func_021FD744(int *a);
extern void func_021E300C(Pair_021E2910 *);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern int func_021E31E8(char *,int,int),func_021E3228(char *,int,int);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c);
extern int func_021FC21C(char *);
extern int func_021FC214(char *);
extern unsigned func_021FC20C(char *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021FD19C(char *p, void *q, void *text);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(u16, unsigned, u16, u16, unsigned char, unsigned char, void *, u16);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
void func_021E24C4(char *p,char *q);
int func_021E24F8(char *p, int a, int b);
int func_021E2538(char *p, int a, int b);
int func_021E2578(void *obj,int b,char *q);
int func_021E25E4(int obj,int b,int c,char *p);
int func_021E2640(int a,int b,int c,char *p);
void func_021E26B8(int *task,State *state,char *p);
void func_021E2910(int *task,int *state,char *p);
void func_021E2AE0(int *task,unsigned *state,char *p);
void func_021E2C2C(int *task,unsigned *state,char *p);
void func_021E2E30(char *p, int a1, int a2);
void func_021E2E48(char *p,int a,int b);
void func_021E2E60(Pair_021E2E60 *p);
void func_021E2E70(char *p, const char *q);
void func_021E2F54(char *p,char *q);
extern const Table d_021E3910;
extern const unsigned char d_021E3928[];





/*
 * extent: final two bytes are alignment padding.
 */
void func_021E24C4(char *p,char *q){int i;for(i=0;i<2;i++){if(*(void **)(p+i*4+12)){func_021FC734(*(void **)(p+i*4+12));*(void **)(p+i*4+12)=0;}}func_020409B4(4);func_021FBDA4(((struct Obj24668 *)q)->fC,30);}






int func_021E24F8(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24669 *)p)->f18, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}






int func_021E2538(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24670 *)p)->f18, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}





int func_021E2578(void *obj,int b,char *q)
{
    char *p;
    int i;
    p=func_0203159C(obj,0x54,func_021F9B9C(((struct Obj06614 *)q)->f10));
    func_02082BCC(p,0,0x54);
    *(char * *)&((struct Obj03332 *)p)->f3C=q;
    ((struct Obj03332 *)p)->f38=func_021F9B9C(((struct Obj06614 *)q)->f10);
    ((struct Obj03332 *)p)->f0=func_02025538(((struct Obj03332 *)p)->f38,((struct Obj06614 *)q)->f4);
    ((struct Obj03332 *)p)->fC=func_021FD6D8((int)p,(int)func_021E26B8,((struct Obj03332 *)p)->f38);
    ((struct Obj03332 *)p)->f4=func_0201C440((void *)(unsigned int)((struct Obj03332 *)p)->f38);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x30)=func_021FD760((unsigned int)(((struct Obj06614 *)q)->f4),(char *)(((struct Obj06614 *)q)->f8),i,((struct Obj03332 *)p)->f38);
    return 1;
}





/*
 * Extent remainder: zero alignment halfword at 021E263E.
 */
int func_021E25E4(int obj,int b,int c,char *p)
{
    int i;
    func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03333 *)p)->f3C));
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x30));
    if (((struct Obj03333 *)p)->f8) {
        func_021FD15C(((struct Obj03333 *)p)->f8,((struct Obj24671 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f8);
        *(int *)&((struct Obj03333 *)p)->f8=0;
    }
    func_0201C4C0((struct PrintSys *)(((struct Obj03333 *)p)->f4));
    func_021FD714((void *)(((struct Obj03333 *)p)->fC));
    func_02025588((void *)(((struct Obj03333 *)p)->f0));
    func_021F9BA0((unsigned int *)(((struct Obj24672 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f10));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}





int func_021E2640(int a,int b,int c,char *p)
{
    int i;
    if (!func_02012E40((const u8 *)(((struct Obj24673 *)(*(char * *)&((struct Obj03883 *)p)->f3C))->f14)) && func_021FF88C((char *)(((struct Obj24674 *)(*(char * *)&((struct Obj03883 *)p)->f3C))->fC))==2) {
        func_021F9C6C(((struct Obj24675 *)(*(char * *)&((struct Obj03883 *)p)->f3C))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(((struct Obj03883 *)p)->fC));
    if (func_021FD72C((int *)(((struct Obj03883 *)p)->fC))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x30)));
    func_0201C4E4((struct PrintSys *)(((struct Obj03883 *)p)->f4));
    if (((struct Obj03883 *)p)->f8) func_021FD1BC((void *)(((struct Obj03883 *)p)->f8));
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0x28)) func_021FC830((u8 *)(*(int *)(p+i*4+0x28)));
    return 0;
}



void func_021E26B8(int *task,State *state,char *p) {
    u32 req[2];
    u32 msg;
    int extra;char *rec;
    u32 x,y;Pair click,cb;
    int result,found,i;
    u64 value;char *arg;
    switch(*state) {
    case 0:
        func_021E2F98((struct SOCLResource *)(&cb));arg=*(char **)(p+0x3c);*(Pair *)(p+0x4c)=cb;
        func_021E2E30((char *)p+0x4c,(int)p,(int)arg);*state=1;break;
    case 1:func_021FE784(**(int **)(p+0x3c),2,3,0);*state=2;break;
    case 2:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=3;break;
    case 3:
        func_02082BCC(req,0,8);*(u64 *)req=*(u64 *)(*(char **)(p+0x3c)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0x3c)+12),3,(const int *)req);
        *(u32 *)(p+0x44)=0;*state=4;break;
    case 4:
        ++*(u32 *)(p+0x44);
        if(func_021FF648(*(void **)(*(char **)(p+0x3c)+12)) && *(u32 *)(p+0x44)>96) {
            func_021FD860(*(int *)(p+0x30), 0, (int *)0);*state=5;
        }break;
    case 5:
        result=func_021FF72C(*(void **)(*(char **)(p+0x3c)+12),(int *)(&msg));
        if(result==0) {
            if(func_021FF698(*(void **)(*(char **)(p+0x3c)+12),(int)(&rec),&extra)) {
                func_0200B938(rec,rec+0x80,rec+0xc4,func_02012EBC(*(void **)(*(char **)(p+0x3c)+0x14)));
                found=0;value=func_0200B98C(func_0200B928(),4,0);
                i=1;arg=*(char **)(p+0x3c);
                for(;i<=3;i++) {
                    if(*(u64 *)(*(char **)(arg+0x18)+i*8+0x30)==value) {found=1;break;}
                }
                if(found==1) {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(arg+8)),(void *)316);*state=9;}
                else *state=6;
            } else {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)339);*state=9;}
        } else {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)msg);*state=9;}
        break;
    case 9:
        if(func_02035C60()) {
            func_02035D20(&x,&y);click.a=x;click.b=y;func_021FD860(*(int *)(p+0x34), 1, (int *)&click);
            func_020061E4(0x703);*state=10;
        }break;
    case 6:func_021FE784(**(int **)(p+0x3c),2,3,1);*state=7;break;
    case 7:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=8;break;
    case 8:func_021E2E48((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));func_021FD73C((int *)task,(int)func_021E2910);break;
    case 10:func_021FE784(**(int **)(p+0x3c),2,3,1);*state=11;break;
    case 11:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=12;break;
    case 12:func_021E2E48((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));func_021FD744(task);break;
    }
}



/*
 * lever: function-scope pair locals preserve stack-slot order across switch cases.
 */
void func_021E2910(int *task,int *state,char *p) {
    u32 x,y;
    Pair_021E2910 first,second,cb;
    int i;
    switch(*state) {
    case 0: {
        func_021E300C(&cb);
        *(Pair_021E2910 *)(p+0x4c)=cb;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct Obj01074 *)p)->f3C);
        *state=1; break;
    }
    case 1: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,0); *state=2; break;
    case 2: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=3; break;
    case 3: {
        if(func_02035D20(&x,&y)) {
            for(i=0;i<=2;i++) {
                if(func_021FB4B4((unsigned int *)(*(int *)(p+i*4+0x14)),x,y)) {
                    first.a=x; first.b=y;
                    func_021FD860(((struct Obj01074 *)p)->f34, 1, (int *)&first);
                    ((struct Obj01074 *)p)->f10=i;
                    if(*(int *)((u32)*(char * *)&((struct Obj24678 *)(*(char * *)&((struct Obj01074 *)p)->f3C))->f18+(u32)i*4+4)) *state=7;
                    else *state=4;
                }
            }
            if(func_021FB4B4((unsigned int *)(((struct Obj01074 *)p)->f20),x,y)) {
                second.a=x; second.b=y;
                func_021FD860(((struct Obj01074 *)p)->f34, 1, (int *)&second); *state=10;
            }
        }
        break;
    }
    case 4: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,1); *state=5; break;
    case 5: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=6; break;
    case 6: func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj01074 *)p)->f3C)); func_021FD73C(*(int * *)&((struct Obj01074 *)p)->fC,(int)func_021E2C2C); break;
    case 7: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,1); ++*state; break;
    case 8: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) ++*state; break;
    case 9: func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj01074 *)p)->f3C)); func_021FD73C(*(int * *)&((struct Obj01074 *)p)->fC,(int)func_021E2AE0); break;
    case 10: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,1); *state=11; break;
    case 11: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=12; break;
    case 12: func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj01074 *)p)->f3C)); func_021FD744(task); break;
    }
}



/*
 * lever: Declare scalar locals before Pair; assign the returned Pair as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 */
void func_021E2AE0(int *task,unsigned *state,char *p)
{
    unsigned x,y;
    Pair_021E2AE0 a;
    switch(*state) {
    case 0:
        func_021E2E60((Pair_021E2E60 *)&a);
        *(Pair_021E2AE0 *)(p+0x4c)=a;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct Obj03334 *)p)->f3C);
        ++*state; break;
    case 1:
        func_021FE784(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,0);
        ++*state; break;
    case 2:
        if(func_021FE7B0(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 3:
        if(func_02035D20(&x,&y)) {
            if(func_021E31E8(p,x,y)) *state=4;
            if(func_021E3228(p,x,y)) *state=7;
        }
        break;
    case 4:
        func_021FE784(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,1);
        ++*state; break;
    case 5:
        if(func_021FE7B0(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 6:
        func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03334 *)p)->f3C));
        func_021FD73C(task,(int)func_021E2C2C); break;
    case 7:
        func_021FE784(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,1);
        ++*state; break;
    case 8:
        if(func_021FE7B0(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 9:
        func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03334 *)p)->f3C));
        func_021FD73C(task,(int)func_021E2910); break;
    }
}


/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * lever: Write the zero halfwords in source order p+0x40 then p+0x42; the reversed spelling exchanged those two store addresses.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *     int i;
 *     u16 v;
 *     switch(selector) {
 *     case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *     case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *     case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *     case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *     case 4: return *(u64 *)(p+0x38);
 *     case 5: return *(u8 *)(p+0x2a);
 *     case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *     case 7: return *(u8 *)(p+0x2b);
 *     default:return 0;
 *     }
 * }
 */
void func_021E2C2C(int *task,unsigned *state,char *p)
{
    Pair_021E2C2C initial;
    Config cfg;
    int x,y;
    Pair_021E2C2C pair;
    int r;
    switch(*state) {
    case 0:
        if(!*(void **)(p+8)) *(void **)(p+8)=func_021FD12C(*(int *)(*(char **)(p+0x3c)+8),(void *)(*(int *)(p+4)),*(u16 *)(p+0x38));
        func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x13d);
        initial.x=0x80;initial.y=0x60;
        func_021FD860(*(int *)(p+0x30), 4, (int *)&initial);
        func_021FE784(**(int **)(p+0x3c),2,3,0);++*state;break;
    case 1:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 2:
        *(int *)(p+0x44)=0;
        *(u16 *)(p+0x40)=0;*(u16 *)(p+0x42)=0;
        ++*state;break;
    case 3:
        r=func_021D7540((void *)(*(int *)(*(char **)(p+0x3c)+0x14)),*(int *)(p+0x10)+1,(unsigned char)(*(int *)(*(char **)(p+0x3c)+0x24)),(u16 *)(p+0x40),(u16 *)(p+0x42),*(u16 *)(p+0x38));
        if((unsigned)(r-2)<=1) {
            *(int *)(*(char **)(p+0x3c)+0x28)=1;
            *(int *)(*(char **)(p+0x3c)+0x2c)=*(int *)(p+0x10)+1;
            ++*state;
        }
        ++*(int *)(p+0x44);break;
    case 4:
        func_02082BCC(&cfg,0,8);
        cfg.wide=func_0200B98C(func_0200B928(),4,0);
        func_021FF54C(*(char **)(*(char **)(p+0x3c)+12),8,(const int *)(&cfg));
        func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x13f);
        *(int *)(p+0x48)=0;++*(int *)(p+0x44);++*state;break;
    case 5:
        ++*(unsigned *)(p+0x44);++*(unsigned *)(p+0x48);
        if(func_021FF648(*(char **)(*(char **)(p+0x3c)+12)) && *(unsigned *)(p+0x44)>0x60 && *(unsigned *)(p+0x48)>0x3c) {
            func_021FD860(*(int *)(p+0x30), 0, (int *)0);
            func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x140);
            ++*state;
        }break;
    case 6:
        if(func_02035C60()) {
            func_02035D20((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            func_021FD860(*(int *)(p+0x34), 1, (int *)&pair);
            func_020061E4((int)0x703);++*state;
        }break;
    case 7:func_021FE784(**(int **)(p+0x3c),2,3,1);++*state;break;
    case 8:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 9:
        if(*(void **)(p+8)) {func_021FD15C(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8));*(int *)(p+8)=0;}
        func_021FD744(task);break;
    }
}



void func_021E2E30(char *p, int a1, int a2)
{
    if (((struct Obj14443 *)p)->f0 != 0) {
        ((void (*)(int, int)) * (void **)p)(a1, a2);
        *(int *)&((struct Obj14443 *)p)->f0 = 0;
    }
}



void func_021E2E48(char *p,int a,int b) { void (*f)(int,int);f=*(void (**)(int,int))(p+4);if(f){f(a,b);*(int *)&((struct Obj14444 *)p)->f4=0;} }


void func_021E2E60(Pair_021E2E60 *p)
{
    *p=d_021E3910.pair;
}


/*
 * lever: Bounded permuter split the scaled index and delayed the base load, then introduced store-address temporaries after the constructor. Fixed one validated its behavior-preserving winning C.
 */
void func_021E2E70(char *p, const char *q)
{
  void *a;
  void *s;
  void *b;
  int h;
  int c;
  int i;
  const unsigned char *r;
  unsigned base;
  unsigned index;
  void **tmp;
  void **tmp1;
  char *tmp2;
  if (!(*((void **) (p + 8))))
    *((void **) (p + 8)) = func_021FD12C(*((int *) (q + 8)), (void *)(*((int *) (p + 4))), *((u16 *) (p + 0x38)));
  a = (void *) func_021FC21C(*((char **) (q + 8)));
  s = func_02045EC0((struct MsgBank *)func_021FC214(*((char **) (q + 8))), 0x141);
  b = func_020457B0(0x80, *((u16 *) (p + 0x38)));
  index = *((unsigned *) (p + 0x10));
  index = index * 4;
  base = *((unsigned *) (q + 0x18));
  func_0201EE0C(a, 0, (const void *)(*((unsigned *) ((base + index) + 0x14))), *((unsigned *) ((((unsigned) base) + index) + 0x24)), 1, 2);
  func_0201F250(a, b, s);
  func_021FD19C(*((void **) (p + 8)), (void *)(*((int *) (q + 8))), b);
  func_02045808(b);
  func_02045808(s);
  func_021FB964((void *)(*((int *) (q + 8))), 0x1e, *((u16 *) (p + 0x38)));
  h = func_021FC20C(*((char **) (q + 8)));
  c = func_021FC214(*((char **) (q + 8)));
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    tmp2 = p + 4;
    *((void **) ((p + (i * 4)) + 0x28)) = func_021FC6A4(4, r[0], r[1], r[2], r[3], 14, *((void **) tmp2), *((u16 *) (p + 0x38)));
    tmp1 = (void **) (0x28 + (p + (i * 4)));
    tmp = tmp1;
    func_021FC754(*tmp, (void *)c, (void *)(*((int *) (r + 4))), (void *)h, 0x3da0);
  }

}


void func_021E2F54(char *p,char *q)
{
    int i;
    for (i=0;i<2;i++) {
        if (*(void **)(p+i*4+0x28)) {
            func_021FC734(*(void **)(p+i*4+0x28));
            *(int *)(p+i*4+0x28)=0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(((struct Obj14445 *)q)->f8,0x1e);
    if (((struct Obj10762 *)p)->f8) {
        func_021FD15C(((struct Obj10762 *)p)->f8,((struct Obj14445 *)q)->f8);
        *(int *)&((struct Obj10762 *)p)->f8=0;
    }
}
