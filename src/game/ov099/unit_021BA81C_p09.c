/*
 * file:     unit_021BA81C_p09.c
 * unit:     yes
 * function: func_021BB4D0, func_021BB4EC, func_021BB528, func_021BB918
 * address:  0x021BB4D0
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
 *   func_021B639C  0x021B639C  thumb  ov067
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049990  0x02049990  arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02009864 0x02009864 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021C2370 0x021C2370 thumb ov099
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_021C285C 0x021C285C thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_021BB374 0x021BB374 thumb ov099
 *   func_021BB460 0x021BB460 thumb ov099
 *   func_02043598 0x02043598 arm
 *   d_021C398C     0x021C398C  data   ov099
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj07942.h"

#define PTR(off) (*(void **)(p+(off)))
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Sub020097BCObj;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BB4D0;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x9a8];
    int f9a8;               /* 0x9a8 */
} Work;

typedef unsigned int   u32_021BB4EC;

typedef unsigned int   u32_021BB528;

typedef struct {
    int v[16];
} Tbl;

typedef unsigned int   u32_021BB918;

extern void func_021B639C(u8 *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32_021BB4EC func_02049990(void *a0, u32_021BB4EC a1, u32_021BB4EC a2, u32_021BB4EC a3, u32_021BB4EC a4, u32_021BB4EC a5, u32_021BB4EC a6, u16 a7);
extern void func_02049238(void *o);
extern void func_0201DD68(void);
extern u32_021BB528 func_02009864(const struct Sub020097BCObj *obj, u32_021BB528 i, u32_021BB528 field);
extern void func_0201DD78(u32_021BB528 r, u32_021BB528 g, u32_021BB528 b);
extern void func_021C2370(char *,int);
extern void func_02045CAC(struct MsgBank *bank, u32_021BB528 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern int func_021C23B8(int i);
extern unsigned func_021BDD48(char *,void *);
extern unsigned func_021BDD54(char *,void *);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(struct WordSet *p, u32_021BB528 i, u32_021BB528 a, u32_021BB528 b, u32_021BB528 c, u32_021BB528 d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void func_021BE4BC(char *p, int a, int b, int c, int d, unsigned int e, int f);
extern int func_021C285C(void *);
extern void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BB528 d, int e);
extern void func_021BB374(char *,int,int);
extern void func_021BB460(char *,int);
extern void func_02043598(u32_021BB528 mask, u32_021BB528 enable);
void func_021BB4D0(char *p);
void func_021BB4EC(Work *w);
void func_021BB528(char *p,int v);
int func_021BB918(void *w, unsigned int idx, int *unused);
extern const Tbl d_021C398C;


void func_021BB4D0(char *p)
{
    void *q = ((struct Obj00008 *)p)->f9AC;

    if (q != 0) {
        func_021B639C(q);
        ((struct Obj00008 *)p)->f9AC = 0;
    }
}


void func_021BB4EC(Work *w)
{
    void *o = func_020490F4(0x21, 0x21);

    func_02049990(o, 0x16, 4, 0, (unsigned short)w->f9a8, 0, 0, 0x21);
    func_02049238(o);
}

void func_021BB528(char *p,int v)
{
    int index;
    void *mon;
    unsigned kind,form;
    int unused;
    int message;
    func_0201DD68();
    index=((struct Obj07942 *)p)->f8ED-1;
    func_02009864(PTR(4),index,9);
    func_0201DD78(15,2,0);
    func_021C2370(p,index);
    func_02045CAC(PTR(0xe0),33,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7A4(func_02045770(PTR(0x958)),25,0,PTR(0xf8),PTR(0xe8));
    mon=(void *)func_021C23B8(index);
    kind=func_021BDD48(p,mon);
    form=func_021BDD54(p,mon);
    message=func_021BB918((void *)kind,form,&unused);
    if(message>=141 && message<=144)message-=81;
    func_02045CAC(PTR(0xe0),message,PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x958)),96,0,PTR(0xf0),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),35,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),104,0,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,2),4,1,1);
    func_02045CAC(PTR(0xe0),36,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),176,24,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,3),4,1,1);
    func_02045CAC(PTR(0xe0),37,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),176,40,PTR(0xf8),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),38,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),104,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,4),4,1,1);
    func_02045CAC(PTR(0xe0),39,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),188,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),42,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),8,96,PTR(0xf8),PTR(0xe8),0x3c40);
    message=func_02009864(PTR(4),index,7);
    if(message){
        func_0201EFA4(PTR(0x8b0),2,message,2,0,1);
        func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,5),4,1,1);
        func_0201EFA4(PTR(0x8b0),1,func_02009864(PTR(4),index,6),2,0,1);
        func_02045CAC(PTR(0xe0),44,PTR(0xf0));
        func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
        func_0201C7D0(func_02045770(PTR(0x95c)),152,96,PTR(0xf8),PTR(0xe8),0x3c40);
    }
    func_02045374(PTR(0x95c));
    func_02045334(PTR(0x95c));
    func_02045374(PTR(0x958));
    func_02045334(PTR(0x958));
    func_02041B6C(7);
    func_021BE4BC(p+0x898,6,2,1,kind,form,32);
    func_021BE3CC(p+0x898,6,28,1,func_021C285C(mon)?47:43,0);
    func_021BB374(p,index,v);
    func_021BB460(p,(u16)v);
    func_02043598(16,1);
}


int func_021BB918(void *w, unsigned int idx, int *unused)
{
    Tbl t;

    func_0201DD78(1, 2, 0);
    func_0201DD78(1, 2, 0);
    t = d_021C398C;
    if (idx > 15)
        idx = 15;
    return t.v[idx];
}
