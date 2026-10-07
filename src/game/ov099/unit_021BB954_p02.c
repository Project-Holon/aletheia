/*
 * file:     unit_021BB954_p02.c
 * unit:     yes
 * function: func_021BBA20, func_021BBA4C, func_021BBC0C, func_021BBC34
 * address:  0x021BBA20
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021C3B30  0x021C3B30  data
 *   func_021BAC24  0x021BAC24  thumb  ov099
 *   data_021C3B34  0x021C3B34  data
 *   data_021C3A18  0x021C3A18  data
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   sub_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   sub_020452E8  0x020452E8  arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
#include "../../matched/include/Obj01245.h"
#include "../../matched/include/Obj03731.h"
#include "../../matched/include/Obj07943.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BBA20;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BBA20;

typedef int BOOL;

typedef unsigned int u32_021BBA4C;

typedef unsigned long  u32_021BBC0C;

typedef signed long    s32_021BBC0C;

typedef struct {
    char pad[0x1A0];
    void *f1A0;
} S;

typedef unsigned int u32_021BBC34;

typedef struct { u16 a,b,c; u8 d,e; } Rec;

typedef signed int     s32_021BBC34;

extern void func_021BAC24(int a, void *b, void *c, int d, int e, int f);
extern u32_021BBA4C func_020450F0(u32_021BBA4C layer, u32_021BBA4C a, u32_021BBA4C b, u32_021BBA4C tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct U16Vec *func_020457B0(u32_021BBA4C capacity, u32_021BBA4C heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern u32_021BBA4C func_0201AA18(void *);
extern void *func_0201AB28(void *,u32_021BBA4C);
extern u32_021BBA4C func_02017E1C(void *,u32_021BBA4C,u32_021BBA4C);
extern void func_02045CAC(struct MsgBank *bank, u32_021BBA4C index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32_021BBA4C i, u32_021BBA4C a, u32_021BBA4C b, u32_021BBA4C c, u32_021BBA4C d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32_021BBA4C);
extern void sub_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32_021BBC0C kind);
extern u32_021BBC0C sub_020452E8(struct Descriptor *d);
extern void *func_020185F4(void *);
extern u32_021BBC34 func_0201BA68(void *);
extern s32_021BBC34 func_0204A6C8(void *a, u32_021BBC34 b, u32_021BBC34 c, u32_021BBC34 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *o, u32_021BBC34 v, u32_021BBC34 flag);
void func_021BBA20(int a);
void func_021BBA4C(char *p,void *party);
void func_021BBC0C(S *s);
void func_021BBC34(char *p, void *a, int k, u32_021BBC34 o);
extern u8 data_021C3B30[];


/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 3 / 3 / 0x14.
 */
void func_021BBA20(int a)
{
    u16 *r = (u16 *)data_021C3B30;

    r[0xA] = 3;
    r[0xB] = 3;
    func_021BAC24(a, (void *)0x021C3B34, (void *)0x021C3A18, 3, 3, 0x14);
}

/*
 * Lever: binding the window address before the gender-zero call preserves its separate hoist and call site; form/gender declaration order fixes their spills.
 */
void func_021BBA4C(char *p,void *party)
{
    void *s,*t,*mon;
    int n,i,off;
    u32_021BBA4C species,gender,name,form;
    void **w;
    void *win;
    if (((struct Obj01245 *)p)->f1A0==0)
        ((struct Obj01245 *)p)->f1A0=(void *)func_020450F0(2,1,5,30,6,15,1);
    func_0201F73C(((struct Obj01245 *)p)->f1A0,2,(u16)(((struct Obj01245 *)p)->f1334),14);
    s=func_020457B0(0x40,0x21);
    t=func_020457B0(0x40,0x21);
    func_02043B5C(func_02045770(((struct Obj01245 *)p)->f1A0),255);
    func_020456F8(((struct Obj01245 *)p)->f1A0);
    n=func_0201AA18(party);
    for (i=0;i<n;i++) {
        mon=func_0201AB28(party,i);
        if (func_02017E1C(mon,0x4c,0)==0) {
            species=func_02017E1C(mon,0,0);
            form=func_02017E1C(mon,0xad,0);
            name=func_02017E1C(mon,0x9e,0);
            gender=func_02017E1C(mon,0x6e,0);
            func_02045CAC(((struct Obj01245 *)p)->fE0,0x74,t);
            func_0201EFA4(((struct Obj01245 *)p)->fDC,0,name,3,0,1);
            func_0201F250(((struct Obj01245 *)p)->fDC,s,t);
            off=i*40;
            func_0201C7A4(func_02045770(((struct Obj01245 *)p)->f1A0),off+1,32,s,((struct Obj01245 *)p)->fEC);
            if (gender!=2 && ((species!=0x1d && species!=0x20) || form!=0)) {
                if (gender==0) {
                    w=(void **)(p+0x1a0);
                    func_02045CAC(((struct Obj01245 *)p)->fE0,0x75,t);
                    win=*w;
                } else {
                    func_02045CAC(((struct Obj01245 *)p)->fE0,0x76,t);
                    win=((struct Obj01245 *)p)->f1A0;
                }
                func_0201C7A4(func_02045770(win),off+30,16,t,((struct Obj01245 *)p)->fE8);
            }
        }
    }
    func_02045808(s);
    func_02045808(t);
    func_02045374(((struct Obj01245 *)p)->f1A0);
    func_02045334(((struct Obj01245 *)p)->f1A0);
    func_02041B6C(2);
}


/*
 * Three-step release of the pointer at +0x1A0; the field is re-read for each
 * step, which is why the listing reloads it between the calls.
 */
void func_021BBC0C(S *s)
{
    if (s->f1A0 != 0) {
        sub_020456F8(s->f1A0);
        func_0201F7A8(s->f1A0, 1);
        sub_020452E8(s->f1A0);
        s->f1A0 = 0;
    }
}

void func_021BBC34(char *p, void *a, int k, u32_021BBC34 o)
{
    int i,n;
    char *base,*dst;
    void *mon;
    Rec rec;
    n = func_0201AA18(a);
    for (i=0;i<n;i++) {
        base = p + k*4;
        mon = func_020185F4(func_0201AB28(a,i));
        rec.a = i*40+22;
        rec.b = 54;
        rec.c = 0;
        rec.d = 0;
        rec.e = 0;
        dst = base+i*4;
        *(int *)&((struct Obj07943 *)dst)->f118 = func_0204A6C8((void *)o,func_0201BA68(mon),0,0,0x21);
        *(u32_021BBC34 *)&((struct Obj07943 *)dst)->f150 = (u32_021BBC34)func_0204B294((void *)((struct Obj03731 *)p)->f110,((struct Obj07943 *)dst)->f118,*(u32_021BBC34 *)&((struct Obj03731 *)p)->f148,*(u32_021BBC34 *)&((struct Obj03731 *)p)->f14C,&rec,0,0x21);
        func_0204B6F4(((struct Obj07943 *)dst)->f150,func_0201BBE8(mon),1);
    }
}
