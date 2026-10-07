/*
 * file:     unit_021F8480_p05.c
 * unit:     yes
 * function: func_021F8D98, func_021F8E60, func_021F8E90
 * address:  0x021F8D98
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
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   d_021F90A0 0x021F90A0 data a1
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 */
#include "../../matched/include/Obj03338.h"
#include "../../matched/include/Obj05490.h"
#include "../../matched/include/Obj04583.h"
#include "../../matched/include/Obj06623.h"

struct Pair;
struct PrintSys;
typedef unsigned short u16;

typedef struct Config {u16 x,y,z; unsigned char a,b;} Config;

typedef struct Triple {int a,b,c;} Triple;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern u32 func_021FC4DC(u8 *p);
extern int func_021FC124(void *,unsigned,void *);
extern void func_02082BCC(void *,int,unsigned);
extern void func_02034714(const char *,unsigned,const char *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,unsigned char,unsigned char,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBDA4(int,unsigned);
extern void func_021FB494(char *p);
extern void func_021FC734(u8 *p);
extern char *func_021FD1C4(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
void func_021F8D98(char *p,char *q);
void func_021F8E60(char *p,char *q);
void func_021F8E90(char *p,int *source);
extern const char d_021F90A0[];

void func_021F8D98(char *p,char *q)
{
    int a,b;
    void *v;
    Config cfg;
    Triple triple;
    if (!*(int *)&((struct Obj03338 *)p)->f1C) {
        a=func_021FC20C(*(char * *)&((struct Obj05490 *)q)->fC);
        b=func_021FC214(*(char * *)&((struct Obj05490 *)q)->fC);
        func_021FC4DC(((struct Obj05490 *)q)->f8);
        func_02082BCC(&cfg,0,8);
        cfg.x=0x50;cfg.y=0xa8;cfg.z=0;cfg.a=1;
        v=(void *)func_021FC4DC(((struct Obj05490 *)q)->f8);
        if (!func_021FC124(((struct Obj05490 *)q)->fC,6,&triple)) func_02034714(d_021F90A0,0,d_021F90A0);
        ((struct Obj03338 *)p)->f18=func_021FB378(&cfg,4,0x60,1,(int)v,((struct Obj03338 *)p)->f28,a,b,&triple,((struct Obj03338 *)p)->f30);
        ((struct Obj03338 *)p)->f1C=func_021FC6A4(4,8,3,0x10,2,0xe,((struct Obj03338 *)p)->f2C,((struct Obj03338 *)p)->f30);
        func_021FC754(*(char * *)&((struct Obj03338 *)p)->f1C,(void *)b,(void *)0x71,(void *)a,0x3da0);
        func_021FB964((void *)(*(int *)&((struct Obj05490 *)q)->fC),0x16,((struct Obj03338 *)p)->f30);
    }
}

void func_021F8E60(char *p,char *q) { if(((struct Obj06623 *)p)->f1C){func_021FBDA4(*(int *)&((struct Obj04583 *)q)->fC,22);func_021FB494(((struct Obj06623 *)p)->f18);((struct Obj06623 *)p)->f18=0;func_021FC734(((struct Obj06623 *)p)->f1C);((struct Obj06623 *)p)->f1C=0;func_021FBDA4(*(int *)&((struct Obj04583 *)q)->fC,22);} }

/*
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee func_021FD1C4 (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * note 2026-10-05 (D4-14): re-run, still MATCH, only func_021FD1C4 (ov186, pengy split) unresolved. No change.
 * note 2026-10-05 (D8-02): re-run, still MATCH. show --region ov186 at 0x021FD1C4 starts with push {r3-r7,lr},
 *   a real 1148-byte function in pengy's ov186 split; outside this lane's write set. No change.
 */
void func_021F8E90(char *p,int *source)
{
    if(*(int *)(p+0x10)==0) {
        int a=func_021FC20C((char *)source[3]);
        int b=func_021FC214((char *)source[3]);
        int c=func_021FC4DC((u8 *)source[2]);
        *(void **)(p+0x10)=func_021FD1C4(((void **)(p+0x40))[*(unsigned short *)(p+0xc)],(char *)source[3],(void *)c,(void *)(*(int *)(p+0x2c)),1,*(unsigned short *)(p+0x30));
        func_021FC754(*(char **)(p+0x1c),(void *)b,(void *)0x72,(void *)a,0x3da0);
    }
}
