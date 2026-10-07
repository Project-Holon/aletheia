/*
 * file:     namein_graphic_p19.c
 * unit:     yes
 * function: func_021F4524, func_021F45A8, func_021F45EC, func_021F4608, func_021F4614, func_021F4628, func_021F462C, func_021F4634, func_021F463C, func_021F4674, func_021F46B4, func_021F46F4, func_021F47B4, func_021F4A5C, func_021F4AA8, func_021F4AE4, func_021F4B84, func_021F4BD8
 * address:  0x021F4524
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045874 0x02045874 arm
 *   func_021F2328 0x021F2328 thumb ov194
 *   func_0204589C 0x0204589C arm
 *   func_021F253C 0x021F253C thumb ov194
 *   func_02045838 0x02045838 arm
 *   func_02045808 0x02045808 arm
 *   func_020458F8 0x020458F8 arm
 *   func_021F23F4 0x021F23F4 thumb
 *   func_021F23F8 0x021F23F8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021F3304 0x021F3304 thumb ov194
 *   func_021F22E8 0x021F22E8 thumb ov194
 *   func_021F3E78 0x021F3E78 thumb ov194
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   sub_020310C4 0x020310C4 arm
 *   sub_0201CE30 0x0201CE30 thumb
 *   sub_0203630C 0x0203630C arm
 *   sub_02035C38 0x02035C38 arm
 *   sub_0201CE5C 0x0201CE5C thumb
 *   sub_020355D8 0x020355D8 arm
 *   sub_020362DC 0x020362DC arm
 *   sub_02035C60 0x02035C60 arm
 *   sub_0201CE38 0x0201CE38 thumb
 *   func_021F32D8 0x021F32D8 thumb ov194
 *   func_021F32FC 0x021F32FC thumb ov194
 *   func_021F4390 0x021F4390 thumb ov194
 *   func_021F3DE0 0x021F3DE0 thumb ov194
 *   func_021F3E18 0x021F3E18 thumb ov194
 *   func_021F3D70 0x021F3D70 thumb ov194
 *   func_021F2190 0x021F2190 thumb ov194
 *   func_021F21BC 0x021F21BC thumb ov194
 *   func_021F21FC 0x021F21FC thumb ov194
 *   func_021F22AC 0x021F22AC thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F233C 0x021F233C thumb ov194
 *   func_021F235C 0x021F235C thumb ov194
 *   func_021F5370 0x021F5370 thumb ov194
 *   func_021F54CC 0x021F54CC thumb ov194
 *   func_021F3EF0 0x021F3EF0 thumb ov194
 *   func_021F4480 0x021F4480 thumb ov194
 *   func_021F2394 0x021F2394 thumb ov194
 *   func_021F23B8 0x021F23B8 thumb ov194
 *   func_021F31F4 0x021F31F4 thumb ov194
 *   func_021F1FB4 0x021F1FB4 thumb ov194
 *   func_021F42E8 0x021F42E8 thumb ov194
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02045A90 0x02045A90 arm
 *   func_021F3350 0x021F3350 thumb ov194
 *   func_0200C0FC 0x0200C0FC thumb
 *   func_021BD368 0x021BD368 thumb ov088
 *   func_021BD380 0x021BD380 thumb ov088
 *   func_02030734 0x02030734 arm
 *   sub_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   sub_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021F4C0C 0x021F4C0C thumb ov194
 *   func_021F4CB0 0x021F4CB0 thumb ov194
 *   sub_020056A0 0x020056A0 thumb
 *   d_021F5784 0x021F5784 data a1
 *   d_021F55D0 0x021F55D0 data a4
 *   func_021F4BF8 0x021F4BF8 thumb ov194
 *   func_02030EAC 0x02030EAC arm
 *   func_021F4CF0 0x021F4CF0 thumb ov194
 *   func_021F4C6C 0x021F4C6C thumb ov194
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021F4D0C  0x021F4D0C  thumb  ov194
 *   func_021F4CA4  0x021F4CA4  thumb  ov194
 */
#include "../../matched/include/Obj03343.h"
#include "../../matched/include/Obj10811.h"
#include "../../matched/include/Obj24911.h"
#include "../../matched/include/Obj24912.h"
#include "../../matched/include/Obj24913.h"
#include "../../matched/include/Obj24914.h"
#include "../../matched/include/Obj24915.h"
#include "../../matched/include/Obj24916.h"
#include "../../matched/include/Obj24917.h"
#include "../../matched/include/Obj24918.h"
#include "../../matched/include/Obj24919.h"
#include "../../matched/include/Obj24920.h"
#include "../../matched/include/Obj14507.h"
#include "../../matched/include/Obj24921.h"
#include "../../matched/include/Obj14508.h"
#include "../../matched/include/Obj24922.h"
#include "../../matched/include/Obj03901.h"
#include "../../matched/include/Obj01287.h"
#include "../../matched/include/Obj01577.h"
#include "../../matched/include/Obj14510.h"
#include "../../matched/include/Obj24924.h"
#include "../../matched/include/Obj24925.h"
#include "../../matched/include/Obj24926.h"
#include "../../matched/include/Obj24927.h"

#define OBJ(p) (*(char **)((p) + 0x2C4))
struct Buf;
struct U16Vec;
struct Strbuf;
struct Tcbl;
struct Rec;
struct Blk34;
struct DispVram;
struct Node;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef void (*fn_021F4614_t)(u8 *, u8 *, u32);

typedef signed int     s32;

extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_021F2328(char *,struct Strbuf *);
extern int func_0204589C(struct Buf *a, struct Buf *b);
extern int func_021F253C(u8 *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u32 func_021F23F4(const u8 *p);
extern u32 func_021F23F8(const u8 *p);
extern void func_02082BCC(u8 *, u32, u32);
extern int func_021F3304(char *),func_021F22E8(unsigned char *),func_021F3E78(unsigned char *);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void sub_020310C4(struct Tcbl *);
extern unsigned sub_0201CE30(void *);
extern unsigned int sub_0203630C(void);
extern int sub_02035C38(void);
extern void sub_0201CE5C(struct Rec *, int);
extern void sub_020355D8(unsigned char);
extern u32 sub_020362DC(void);
extern int sub_02035C60(void);
extern void sub_0201CE38(void *);
extern int func_021F32D8(char *,u16 *);
extern unsigned func_021F4390(unsigned char *p);
extern u16 func_021F32FC(char *);
extern u32 func_020362DC(void);
extern void func_021F3DE0(char *,int,u32,u32,u16);
extern void func_021F3E18(char *,int,void *),func_021F3D70(char *,int);
extern int func_021F2190(char *,u16);
extern int func_021F21BC(unsigned char *p, unsigned short a, unsigned short b);
extern int func_021F21FC(unsigned char *a, int b);
extern int func_021F22AC(char *);
extern int func_021F2150(unsigned char *p);
extern void func_021F233C(char *);
extern void func_021F235C(char *);
extern void func_021F2394(unsigned char *p);
extern void func_021F23B8(char *p, const u16 *q);
extern int func_021F5370(const u32 *cache, const void *input, u16 heap);
extern int func_021F54CC(void *,int,int);
extern int func_021F4480(u8 *p, int a, int b);
extern void func_020061E4(u32 a);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_021F31F4(char *,char *);
extern int func_021F1FB4(u8 *p);
extern void func_021F42E8(char *);
extern void *func_021F3350(const unsigned char *p);
extern void func_0200C0FC(struct Blk34 *p, u32 i, u8 v);
extern void func_021BD368(unsigned char *);
extern int func_021BD380(unsigned char *);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void sub_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void sub_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021F4C0C(void *, unsigned short);
extern void func_021F4CB0(unsigned char *, int, int);
extern void *sub_020056A0(unsigned, unsigned, unsigned);
extern void func_021F4BF8(u32 a, u8 *b);
extern void func_02030EAC(struct Node *);
extern void func_021F4CF0(unsigned char *);
extern void func_021F4C6C(void *p);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021F4D0C(u8 *);
extern void func_021F4CA4(u8 *);
void func_021F4524(char *p);
int func_021F45A8(int p);
void func_021F45EC(u8 *a, u32 b, u32 c);
void func_021F4608(void *p);
void func_021F4614(u8 *p);
unsigned func_021F4628(unsigned char *p);
void func_021F462C(unsigned char *p,unsigned value);
void func_021F4634(unsigned char *p);
void func_021F463C(unsigned char *p,int *unused,unsigned char *q);
void func_021F4674(unsigned char *p,int *state);
void func_021F46B4(unsigned char *p,int *state);
void func_021F46F4(unsigned char *a, int *state, char *p);
void func_021F47B4(unsigned char *owner,void *unused,char *p);
void func_021F4A5C(unsigned char *a, int unused, char *p);
void func_021F4AA8(unsigned char *p,int *state,unsigned char *q);
unsigned char *func_021F4AE4(unsigned swap, unsigned short heap);
void func_021F4B84(unsigned char *p);
void func_021F4BD8(u8 *p);
extern const char d_021F5784[];
extern const struct DispVram d_021F55D0;

void func_021F4524(char *p) {
    int text;
    char *obj;
    ((struct Obj24911 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=0;
    text=(int)func_02045874((struct U16Vec *)(((struct Obj24912 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),30);
    func_021F2328(p+0x68,(struct Strbuf *)((struct Obj24913 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20);
    if (func_0204589C((struct Buf *)text,(struct Buf *)(((struct Obj24914 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20)))
        ((struct Obj24915 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    if (!func_021F253C((u8 *)((int)(p+0x68)))) {
        func_02045838((struct U16Vec *)(((struct Obj24916 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),(struct U16Vec *)text);
        ((struct Obj24917 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    }
    func_02045808((struct U16Vec *)text);
    if (!func_020458F8((struct U16Vec *)(((struct Obj24918 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20))) {
        obj=*(char * *)&((struct Obj03343 *)p)->f2C4;
        if (((struct Obj10811 *)obj)->f0!=0 && ((struct Obj10811 *)obj)->f0!=3) ((struct Obj10811 *)obj)->f1C=1;
    }
}


int func_021F45A8(int p)
{
    int *q = *(int * *)&((struct Obj24919 *)p)->f2C4;

    if (*q == 0 || *q == 3) {
        if (func_021F23F4((const u8 *)(p + 0x68)) == 0 && func_021F23F8((const u8 *)(p + 0x68)) == 0) {
            return 0;
        }
        if (func_021F253C((u8 *)(p + 0x68)) == 0) {
            return 0;
        }
    }
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F45EC(u8 *a, u32 b, u32 c)
{
    func_02082BCC(a, 0, 0x10);
    ((struct Obj24920 *)a)->fC = b;
    func_021F462C(a, c);
}

void func_021F4608(void *p){func_02082BCC(p,0,16);}


void func_021F4614(u8 *p)
{
    if (((struct Obj14507 *)p)->f4 == 0) {
        ((fn_021F4614_t)*(void **)p)(p, p + 8, ((struct Obj14507 *)p)->fC);
    }
}

unsigned func_021F4628(unsigned char *p){return ((struct Obj24921 *)p)->f4;}

void func_021F462C(unsigned char *p,unsigned value){((struct Obj14508 *)p)->f0=value;((struct Obj14508 *)p)->f8=0;}

void func_021F4634(unsigned char *p){((struct Obj24922 *)p)->f4=1;}

void func_021F463C(unsigned char *p,int *unused,unsigned char *q){int v;v=func_021F3304((char *)(q+252));v|=func_021F22E8(q+104);if(func_021F3E78(q+560)|v)func_021F462C(p,(unsigned)func_021F4674);}

void func_021F4674(unsigned char *p,int *state) {
    switch (*state) {
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if (!func_0204E804()) *state=2; break;
    case 2: func_021F462C(p,(unsigned)func_021F47B4); break;
    }
}

void func_021F46B4(unsigned char *p,int *state) {
    switch (*state) {
    case 0: func_0204E720(3,0,16,0); *state=1; break;
    case 1: if (!func_0204E804()) *state=2; break;
    case 2: func_021F462C(p,(unsigned)func_021F4A5C); break;
    }
}

/*
 * Padding: two zero bytes at 0x021F47B2, then a function prologue.
 */
void func_021F46F4(unsigned char *a, int *state, char *p)
{
    char *q = p + 0x254;
    switch (*state) {
    case 0:
        sub_020310C4(*(struct Tcbl * *)&((struct Obj03901 *)q)->f4);
        switch (sub_0201CE30(((struct Obj03901 *)q)->f0)) {
        case 0:
            if (((unsigned)sub_0203630C() & 3) != 0 || sub_02035C38() != 0) {
                sub_0201CE5C(*(struct Rec * *)&((struct Obj03901 *)q)->f0, 0);
                if (((unsigned)sub_0203630C() & 3) != 0) sub_020355D8(0);
                else sub_020355D8(1);
            }
            break;
        case 2:
            *state = 1;
            break;
        case 1:
            if (((unsigned)sub_020362DC() & 3) != 0 || sub_02035C60() != 0) {
                sub_0201CE38(((struct Obj03901 *)q)->f0);
                if (((unsigned)sub_020362DC() & 3) != 0) sub_020355D8(0);
                else sub_020355D8(1);
            }
            break;
        }
        break;
    case 1:
        if (((struct Obj03901 *)q)->fE >= ((struct Obj03901 *)q)->fC) *state = 2;
        else (((struct Obj03901 *)q)->fE)++;
        break;
    case 2:
        func_021F462C(a, ((struct Obj03901 *)q)->f8);
        break;
    }
}

static inline int invert(char *p,int v) { int r=1; if(func_021F21FC((unsigned char *)p,v)==0) r=0; return r; }

void func_021F47B4(unsigned char *owner,void *unused,char *p)
{
    u16 selected;
    u32 action=func_021F32D8(p+0xfc,&selected);
    u16 value=func_021F32FC(p+0xfc);
    if(((struct Obj01287 *)p)->f2C8==1) {
        if(action!=0 || func_021F4390((unsigned char *)(p+0x264))!=0 || (func_020362DC()&~1u)!=0) {
            int *q=*(int * *)&((struct Obj01287 *)p)->f2C4;
            if(q[0]==1) {
                if(q[2]==0) func_021F3DE0(p+0x230,q[0],((struct Obj01577 *)q)->f4,((struct Obj01577 *)q)->f6,30);
                else func_021F3E18(p+0x230,q[0],(void *)q[2]);
            } else func_021F3D70(p+0x230,q[0]);
            ((struct Obj01287 *)p)->f2C8=0;
        }
    }
    switch(action) {
    case 1: if(func_021F2190(p+0x68,selected)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 2: if(func_021F21BC((unsigned char *)(p+0x68),selected,value)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 3: if(invert(p+0x68,0)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 4: if(invert(p+0x68,1)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 10: if(func_021F22AC(p+0x68)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 5: if(func_021F2150((unsigned char *)(p+0x68))) func_020061E4(0x553); else func_020061E4(0x557); break;
    case 6: func_021F233C(p+0x68); break;
    case 11: func_021F235C(p+0x68); break;
    case 7: if(func_021F23F8((const u8 *)((int)(p+0x68)))==0) {
        if(func_021F45A8((int)p)==0) {func_020061E4(0x557);func_021F3D70(p+0x230,8);((struct Obj01287 *)p)->f2C8=1;}
        else {
            if(func_021F5370(*(u32 * *)&((struct Obj01287 *)p)->f2CC,p+0x68,30)) func_020061E4(0x557);
            else if(func_021F54CC(p+0x68,((struct Obj01287 *)p)->f86,30)) {func_020061E4(0x557);func_021F3D70(p+0x230,9);((struct Obj01287 *)p)->f2C8=1;}
            else {
                int *q;
                func_020061E4(0x54d);func_021F4524(p);q=*(int * *)&((struct Obj01287 *)p)->f2C4;
                if(q[0]==1 && q[3]!=0) {func_021F3EF0(p+0x254,p+0x230,q,30);func_021F462C(owner,(u32)func_021F46F4);}
                else func_021F462C(owner,(u32)func_021F46B4);
            }
        }
    } else {func_021F235C(p+0x68);func_020061E4(0x54d);} break;
    case 0: if(func_021F4390((unsigned char *)(p+0x264))) {
        int text=func_021F4480((u8 *)p,**(int * *)&((struct Obj01287 *)p)->f2C4,30);
        func_021F2394((unsigned char *)(p+0x68));
        if(text) {func_021F23B8(p+0x68,func_02045A90((struct U16Vec *)text));func_02045808((struct U16Vec *)text);}
        func_020061E4(0x54c);
    } break;
    case 9: func_021F235C(p+0x68);if(func_021F2190(p+0x68,selected)) func_020061E4(0x54c); else func_020061E4(0x557);break;
    default: break;
    }
    func_021F31F4(p+0xfc,p+0x68);
    func_021F1FB4((u8 *)(p+0x68));
    func_021F42E8(p+0x264);
    func_021F3E78((u8 *)(p+0x230));
}

void func_021F4A5C(unsigned char *a, int unused, char *p)
{
    unsigned n;
    if (*(void **)(OBJ(p) + 0x28) != 0) {
        n = (unsigned int)func_021F3350((const unsigned char *)(p + 0xFC));
        func_0200C0FC(*(void **)(OBJ(p) + 0x28), (u32)(*(void **)OBJ(p)), n);
    }
    if (*(void **)(OBJ(p) + 0x24) != 0) func_021F462C(a, (unsigned)func_021F4AA8);
    else func_021F4634(a);
}

void func_021F4AA8(unsigned char *p,int *state,unsigned char *q){switch(*state){case 0:func_021BD368(*(unsigned char * *)&((struct Obj24924 *)(*(unsigned char * *)&((struct Obj14510 *)q)->f2C4))->f24);*state=1;break;case 1:if(func_021BD380(*(unsigned char * *)&((struct Obj24925 *)(*(unsigned char * *)&((struct Obj14510 *)q)->f2C4))->f24)==1)func_021F4634(p);break;}}

static inline void G2_BlendNone(void) { *(volatile unsigned short *)0x04000050 = 0; }

static inline void G2S_BlendNone(void) { *(volatile unsigned short *)0x04001050 = 0; }

static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0xE000) | (window << 13); }

static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xE000) | (window << 13); }

/*
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 */
unsigned char *func_021F4AE4(unsigned swap, unsigned short heap)
{
    unsigned char *p;
    p = func_02030734(heap, 0x10, 0, d_021F5784, 0x1BB);
    func_02082BCC(p, 0, 0x10);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    sub_0204335C(0);
    func_020433E0(&d_021F55D0);
    func_0204363C(swap);
    func_0204361C();
    sub_020434CC();
    func_02043588();
    func_0201DD60();
    func_021F4C0C(p, heap);
    func_021F4CB0(p + 4, (int)&d_021F55D0, heap);
    ((struct Obj24926 *)p)->fC = sub_020056A0((unsigned)func_021F4BF8, (unsigned)p, 0);
    return p;
}

void func_021F4B84(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj24927 *)p)->fC);
    func_021F4CF0(p + 4);
    func_021F4C6C(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}


void func_021F4BD8(u8 *p)
{
    func_021F4D0C(p + 4);
    func_021F4CA4(p);
}
