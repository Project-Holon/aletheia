/*
 * file:     btl_rec_sel_p04.c
 * unit:     yes
 * function: func_021BA43C, func_021BA45C, func_021BA4E8
 * address:  0x021BA43C
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
 *   func_020452E8 0x020452E8 arm
 *   func_02035630 0x02035630 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BA794 0x021BA794 thumb ov214
 *   func_021BA6F0 0x021BA6F0 thumb ov214
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj00202.h"
#include "../../matched/include/Obj01588.h"

struct Descriptor;
struct PrintSys;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {int a,b,c;} Obj;

typedef unsigned char  u8;

struct S { u8 pad[0x8C]; struct Descriptor *descriptors[2]; struct Descriptor *other1,*other2; u32 flags[2]; };

extern u32 func_020452E8(struct Descriptor *d);
extern u8 func_02035630(void);
extern void func_021BA794(Obj*,char*,u16);
extern void func_021BA6F0(void *obj, char *p);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *,void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021BA43C(int unused, char *p);
void func_021BA45C(Obj*obj,char*p);
void func_021BA4E8(void *unused,struct S *p);


void func_021BA43C(int unused, char *p)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        func_020452E8(*(void **)(p + 0x8c + i * 4));
    }
}

/*
 * note: BA794's third argument is narrowed at 021BA49A..A0; caller
 * extern uses u16 despite its own source's unsigned parameter.
 */
void func_021BA45C(Obj*obj,char*p)
{
    unsigned threshold;
    if(func_02035630()==30)threshold=30;else threshold=60;
    if(obj->c && !((struct Obj00202 *)p)->fB4 && (((struct Obj00202 *)p)->fAC>=threshold || *(int *)&((struct Obj00202 *)p)->fB0)){
        func_021BA794(obj,p,((struct Obj00202 *)p)->fAC/threshold);
        if(((struct Obj00202 *)p)->fAC>=threshold){
            --((struct Obj00202 *)p)->fAC;
            if(((struct Obj00202 *)p)->fAC==threshold-1)((struct Obj00202 *)p)->fB8=1;
        }else{
            --((struct Obj00202 *)p)->fB0;
            if(!((struct Obj00202 *)p)->fB0)func_021BA6F0(obj,p);
        }
    }
}

/*
 * extent: two bytes zero alignment at 021BA5C6.
 * lever: indexed struct members keep the fixed field offset inside the loop;
 *   raw pointer form was DIFF236/217, integer form DIFF222/66.
 */
void func_021BA4E8(void *unused,struct S *p)
{
    u8 i;
    struct Descriptor *d;
    for (i=0;i<=1;i++) {
        if (p->flags[i]==0) {
            if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj01588 *)p)->f10,func_02045770(p->descriptors[i]))==0) {
                d=p->descriptors[i];
                func_02045334(d);
                func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                p->flags[i]=1;
            }
        }
    }
    if (((struct Obj01588 *)p)->fA4==0) {
        if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj01588 *)p)->f14,func_02045770(p->other1))==0) {
            d=p->other1;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            ((struct Obj01588 *)p)->fA4=1;
        }
    }
    if (((struct Obj01588 *)p)->fA8==0) {
        if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj01588 *)p)->f18,func_02045770(p->other2))==0) {
            d=p->other2;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            ((struct Obj01588 *)p)->fA8=1;
        }
    }
}
