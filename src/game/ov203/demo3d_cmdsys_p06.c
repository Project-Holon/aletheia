/*
 * file:     demo3d_cmdsys_p06.c
 * unit:     yes
 * function: func_021BF8E8, func_021BF924, func_021BF964, func_021BF9B8
 * address:  0x021BF8E8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203101C 0x0203101C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_021BE9E8 0x021BE9E8 thumb ov203
 *   func_0203115C 0x0203115C arm
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_021BE990 0x021BE990 thumb ov203
 *   d_021C3D00 0x021C3D00 data a4
 */
#include "../../matched/include/Obj01776.h"
#include "../../matched/include/Obj02250.h"
#include "../../matched/include/Obj10867.h"

struct Tcbl;
struct GfFont;
struct S02031140;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int kind;unsigned limit;int values[8]; } Record;

extern struct Tcbl *func_0203101C(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
extern struct GfFont *func_0201D7EC(int,int,int,int,unsigned);
extern void *func_020490F4(u32 id, u32 heap);
extern signed char func_02012FFC(void);
extern void func_021BE9E8(int);
extern void func_0203115C(struct Tcbl *p);
extern void func_02005DE4(void *);
extern void func_02005DF8(u32 a);
extern void func_02049238(void *);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern int func_02005E9C(void);
extern u32 func_021BE990(u32 id);
void func_021BF8E8(char *p);
void func_021BF924(char *p);
int func_021BF964(char *p,char *owner,int *index);
void func_021BF9B8(unsigned a,unsigned b,char *p);
extern unsigned d_021C3D00[];

void func_021BF8E8(char *p){*(struct Tcbl * *)&((struct Obj01776 *)p)->f20=func_0203101C(((struct Obj01776 *)p)->f0,((struct Obj01776 *)p)->f0,16,128);*(struct GfFont * *)&((struct Obj01776 *)p)->f24=func_0201D7EC(23,0,0,0,((struct Obj01776 *)p)->f0);((struct Obj01776 *)p)->f28=func_020490F4(161,((struct Obj01776 *)p)->f0);p[0x18]=func_02012FFC();}

void func_021BF924(char *p)
{
    if(((struct Obj02250 *)p)->f2C) func_021BE9E8(((struct Obj02250 *)p)->f2C);
    func_0203115C(((struct Obj02250 *)p)->f20);
    if(((struct Obj02250 *)p)->f19) {
        func_02005E9C();func_02005DE4(0);func_02005DF8(60);
    }
    func_02049238(((struct Obj02250 *)p)->f28);func_0201D83C(((struct Obj02250 *)p)->f24);func_02031140(((struct Obj02250 *)p)->f20);
}

int func_021BF964(char *p,char *owner,int *index)
{
    Record *r;
    int i;
    r=(Record *)func_021BE990(((struct Obj10867 *)owner)->f78);
    for(i=0;i<9999;i++) {
        if(r[i].kind==18) return 1;
        if(r[i].limit==-1) func_021BF9B8((unsigned int)p,(unsigned int)owner,(char *)(&r[i]));
        else if(r[i].limit>=((struct Obj10867 *)owner)->f7C) {*index=i;return 0;}
    }
    return 0;
}

void func_021BF9B8(unsigned a,unsigned b,char *p){(*(void (**)(unsigned,unsigned,char *))((unsigned)d_021C3D00+*(unsigned *)p*4))(a,b,p+8);}
