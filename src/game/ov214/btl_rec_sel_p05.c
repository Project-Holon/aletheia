/*
 * file:     btl_rec_sel_p05.c
 * unit:     yes
 * function: func_021BA5C8, func_021BA650, func_021BA6A0
 * address:  0x021BA5C8
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_021BA4E8 0x021BA4E8 thumb ov214
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02035630 0x02035630 arm
 *   func_021BA794 0x021BA794 thumb ov214
 */
#include "../../matched/include/Obj02552.h"
#include "../../matched/include/Obj25726.h"
#include "../../matched/include/Obj00202.h"

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct S;
struct PrintSys;
struct Cfg;
struct CharBuf;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void*,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_021BA4E8(void *unused, struct S *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern u8 func_02035630(void);
extern void func_021BA794(void *, void *, unsigned int);
void func_021BA5C8(void*obj,char*p);
void func_021BA650(int unused,char*p);
void func_021BA6A0(void *obj, char *p, u32 v);

void func_021BA5C8(void*obj,char*p)
{
    void*h;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,19);
    func_0201C724(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)func_02045770(*(void* *)&((struct Obj02552 *)p)->f8C),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    func_02045808(h);
    ((struct Obj02552 *)p)->f9C=0;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,((struct Obj02552 *)p)->f2A4);
    func_0201C724(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)func_02045770(*(void* *)&((struct Obj02552 *)p)->f90),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    func_02045808(h);
    ((struct Obj02552 *)p)->fA0=0;
    func_021BA4E8(obj,(struct S *)p);
}

void func_021BA650(int unused,char*p)
{
    u8 i;
    void*h;
    for(i=0;i<=1;i++){
        func_0201C6EC((struct PrintSys *)(((struct Obj25726 *)p)->f10));
        func_02043B5C(func_02045770(*(void**)(p+i*4+0x8c)),0);
        h=*(void**)(p+i*4+0x8c);
        func_02045334(h);
        func_02045374(h);
        func_02041B6C(func_02045730(h));
        *(int*)(p+i*4+0x9c)=1;
    }
}

void func_021BA6A0(void *obj, char *p, u32 v)
{
    u32 threshold;
    if (func_02035630() == 30) threshold = 30;
    else threshold = 60;
    ((struct Obj00202 *)p)->fAC = threshold * (v + 1) - 1;
    ((struct Obj00202 *)p)->fB0 = threshold >> 1;
    ((struct Obj00202 *)p)->fB4 = 0;
    ((struct Obj00202 *)p)->fB8 = 0;
    ((struct Obj00202 *)p)->fBC = 0;
    ((struct Obj00202 *)p)->fC0 = 0;
    func_021BA794(obj, p, v);
}
