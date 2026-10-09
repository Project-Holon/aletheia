/*
 * file:     zukan_detail_graphic_p02.c
 * unit:     yes
 * function: func_021BD03C, func_021BD07C, func_021BD098, func_021BD0A0, func_021BD0A8, func_021BD0AC, func_021BD11C, func_021BD12C, func_021BD140, func_021BD148, func_021BD208, func_021BD23C, func_021BD2E0, func_021BD308, func_021BD330, func_021BD358, func_021BD35C, func_021BD360, func_021BD368, func_021BD378, func_021BD388, func_021BD394, func_021BD3A4, func_021BD3B4, func_021BD3C0, func_021BD3CC, func_021BD3F8
 * address:  0x021BD03C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204A600 0x0204A600  arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021BCD68 0x021BCD68 thumb ov208
 *   d_021C8114 0x021C8114 data a4
 *   g_020A1EB8 0x020A1EB8 data a4
 *   func_02047970 0x02047970  arm
 *   func_02030734        0x02030734  arm
 *   ov208_func_021BD444  0x021BD444  thumb
 *   func_021BD634        0x021BD634  thumb
 *   data_021C8DD8        0x021C8DD8  data
 *   func_021BD74C 0x021BD74C thumb
 *   func_021BD538 0x021BD538 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BD764 0x021BD764 thumb ov208
 *   func_021BD7E4 0x021BD7E4 thumb ov208
 *   func_021BD878 0x021BD878 thumb ov208
 *   func_021BD7F8 0x021BD7F8  thumb  ov208
 *   func_021BD7FC  0x021BD7FC  thumb
 *   func_021BD404 0x021BD404  thumb  ov208
 *   func_021BD814 0x021BD814  thumb  ov208
 *   func_021BD43C 0x021BD43C  thumb  ov208
 *   func_021BD808 0x021BD808  thumb  ov208
 *   func_021BD844 0x021BD844  thumb  ov208
 *   func_021BD848 0x021BD848  thumb  ov208
 *   func_021BD868 0x021BD868  thumb  ov208
 *   ov208_func_021BD404  0x021BD404  thumb
 *   func_0204B404        0x0204B404  arm
 */
#include "../../matched/include/Obj14644.h"
#include "../../matched/include/Obj18205.h"
#include "../../matched/include/Obj01977.h"
#include "../../matched/include/Obj12116.h"
#include "../../matched/include/Obj18229.h"
#include "../../matched/include/Obj18230.h"

struct Cfg;
struct Bank;
struct Light;
struct Obj;
struct Vec2;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {int x,y,z;} Vec3;

typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 owner;
    u32 channel;
    u32 pal;
    u32 objPal;
    u32 kind;
    u32 skip;
};

struct Ov208Bg {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct Ov208ActObj {
    u8 raw[0x38];
};

struct Ov208ActSet {
    u32 f0;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    struct Ov208Bg bg;
    struct Ov208ActObj objs[1];
};

struct Ov208Item { char b[0x38]; };

struct Ov208Mgr_021BD208 { int f0; u32 count; int f8; int fc; int f10; char f14[0x14]; struct Ov208Item items[1]; };

struct Ov208Mgr_021BD308 { int idx; unsigned count; int state; int fc; int f10; char f14[0x14]; struct Ov208Item items[1]; };

struct Ov208Mgr_021BD330 {
    u32 f0;
    u32 count;
};

struct Ov208Mgr_021BD360 {
    u32 pad0[4];
    u32 f10;
};

struct Ov208Rec {
    u32 f0;
    u32 pad4[5];
    u16 x;
    u16 y;
};

struct Ov208Mgr {
    u32 pad0[8];
    u32 f20;
};

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(char *);
extern void func_0204A648(void);
extern void func_021BCD68(void);
extern void func_02046440(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,const Vec3 *,const Vec3 *,const Vec3 *,u16);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_02047964(void *);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_02047970(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void ov208_func_021BD444(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs,
                                u32 kind, u8 pal, u8 objPal, u32 skip, u32 heap);
extern void func_021BD634(struct Ov208ActObj *p, u32 owner, struct Ov208Bg *res,
                          struct Ov208ActDesc *desc, u32 prio, u32 mode);
extern void func_021BD74C(char *p);
extern void func_021BD538(char *p);
extern u32 func_020307B0(void *p);
extern int func_021BD764(char *);
extern int func_021BD7E4(int *p);
extern void func_021BD878(char *p);
extern int func_021BD7F8(char *);
extern void func_021BD7FC(struct Obj **p, unsigned int v);
extern int func_021BD404(int, int);
extern void func_021BD814(char *p, int v);
extern void *func_021BD43C(void *mgr, int key);
extern void func_021BD808(int *p);
extern void func_021BD844(char *p, int v);
extern void func_021BD848(char *p, int which);
extern int func_021BD868(const void *p);
extern struct Ov208Rec *ov208_func_021BD404(struct Ov208Mgr *p, int key);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BD03C(unsigned char *p, int a, int b);
void func_021BD07C(char *p);
void func_021BD098(char *p);
void func_021BD0A0(char *a0);
int func_021BD0A8(int *p);
void func_021BD0AC(u32 **p,u16 heap);
void func_021BD11C(int *p);
void func_021BD12C(int *p);
void func_021BD140(char *p);
struct Ov208ActSet *ov208_func_021BD148(struct Ov208ActList *list, u32 heap);
void func_021BD208(struct Ov208Mgr_021BD208 *m);
void func_021BD23C(char *p);
int func_021BD2E0(char *p);
int func_021BD308(struct Ov208Mgr_021BD308 *m);
void ov208_func_021BD330(struct Ov208Mgr_021BD330 *p, int v);
void func_021BD358(char *p, int v);
int func_021BD35C(char *p);
void ov208_func_021BD360(struct Ov208Mgr_021BD360 *p);
void func_021BD368(int a, int b, int c);
void func_021BD378(int a, int b, int c);
void func_021BD388(void *mgr, int key);
void func_021BD394(int a, int b, int c);
void func_021BD3A4(int a, int b, int c);
int func_021BD3B4(void *mgr, int key);
int func_021BD3C0(void *mgr, int key);
void ov208_func_021BD3CC(struct Ov208Mgr *p, int key, u16 *pos);
void func_021BD3F8(void *mgr, int key);
extern const Vec3 d_021C8114[];
extern const char g_020A1EB8[];
extern const char data_021C8DD8[];






void func_021BD03C(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021C8148, a, b);
    ((struct Obj14644 *)p)->f0 = func_0204B100(0x50, 0, b);
    func_0204B270(((struct Obj14644 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}






void func_021BD07C(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj18205 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}






void func_021BD098(char *p)
{
    func_0204A600(p);
}






void func_021BD0A0(char *a0)
{
    func_0204A648();
}





int func_021BD0A8(int *p)
{
    return *p;
}





void func_021BD0AC(u32 **p,u16 heap)
{
    func_02046440(0,1,0,2,0,heap,func_021BCD68);
    *p=func_02048A24(0,*(const short *)(g_020A1EB8+12),*(const short *)(g_020A1EB8+14),0x1555,0,0x107c20,0x400000,0,&d_021C8114[1],&d_021C8114[0],&d_021C8114[2],heap);
}






/*
 * Loads the word at [p], then calls the ARM9 functions at 0x02048AC4 and 0x02046788.
 */
void func_021BD11C(int *p)
{
    func_02048AC4((void *)(*p));
    func_02046788();
}






/*
 * Calls 0x02047964 on p, then 0x02048AD0 on the word at [p], then 0x020479D8.
 */
void func_021BD12C(int *p)
{
    func_02047964(p);
    func_02048AD0((struct Light *)(*p));
    func_020479D8();
}






void func_021BD140(char *p)
{
    func_02047970();
}






struct Ov208ActSet *ov208_func_021BD148(struct Ov208ActList *list, u32 heap)
{
    struct Ov208ActSet *set;
    u32 size;
    u32 objChannel;
    u32 palOfs;
    u32 i;

    palOfs = 0;
    size = list->count * sizeof(struct Ov208ActObj) + 0x28;
    set = func_02030734(heap, size, 0, data_021C8DD8, 0x107);
    func_02082BCC(set, 0, size);
    set->count = list->count;
    set->f8 = 0;
    set->fc = 1;
    set->f10 = 0;
    objChannel = 1;
    if (list->channel >= 4)
        palOfs = 4;
    else
        objChannel = 0;
    ov208_func_021BD444(&set->bg, (u8)list->channel, objChannel, palOfs, list->kind,
                        (u8)list->pal, (u8)list->objPal, list->skip, heap);
    for (i = 0; i < set->count; i++)
        func_021BD634(&set->objs[i], list->owner, &set->bg, &list->descs[i], objChannel, heap);
    return set;
}





void func_021BD208(struct Ov208Mgr_021BD208 *m)
{
    u32 i;
    for (i = 0; i < m->count; i++)
        func_021BD74C((char *)(&m->items[i]));
    func_021BD538(m->f14);
    func_020307B0(m);
}





void func_021BD23C(char *p)
{
    unsigned i;
    switch(*(unsigned *)&((struct Obj01977 *)p)->f8) {
    case 0:
        *(int *)&((struct Obj01977 *)p)->f0=-1;
        if(((struct Obj01977 *)p)->fC && !((struct Obj01977 *)p)->f10) {
            for(i=0;i<((struct Obj01977 *)p)->f4;i++) {
                if(func_021BD764(p+0x28+i*0x38)) {
                    ((struct Obj01977 *)p)->f0=i;
                    ((struct Obj01977 *)p)->f8=1;
                    ((struct Obj01977 *)p)->f10=1;
                    break;
                }
            }
        }
        break;
    case 1:
        ((struct Obj01977 *)p)->f8=2;
    case 2:
        if(func_021BD7E4((int *)(p+0x28+((struct Obj01977 *)p)->f0*0x38)))((struct Obj01977 *)p)->f8=3;
        break;
    case 3:
        ((struct Obj01977 *)p)->f8=0;
        break;
    }
    for(i=0;i<((struct Obj01977 *)p)->f4;i++)func_021BD878(p+0x28+i*0x38);
}






/*
 * Returns +0x14 of the 0x38-byte record selected by the index at +0, or -1.
 */
int func_021BD2E0(char *p)
{
    int i;

    if (((struct Obj12116 *)p)->f8 == 3) {
        i = ((struct Obj12116 *)p)->f0;
        if (i != -1)
            return func_021BD7F8(p + 0x28 + i * 0x38);
    }
    return -1;
}





int func_021BD308(struct Ov208Mgr_021BD308 *m)
{
    if (m->state == 1 && m->idx != -1)
        return func_021BD7F8((char *)(&m->items[m->idx]));
    return -1;
}






void ov208_func_021BD330(struct Ov208Mgr_021BD330 *p, int v)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        func_021BD7FC((void *)((u32)p + 0x28 + i * 0x38), v);
}







/*
 * Stores the second argument at +0xC.
 */
void func_021BD358(char *p, int v)
{
    ((struct Obj18229 *)p)->fC = v;
}







/*
 * Returns the word at +0xC (the two words after it are untraced continuations).
 */
int func_021BD35C(char *p)
{
    return ((struct Obj18230 *)p)->fC;
}






void ov208_func_021BD360(struct Ov208Mgr_021BD360 *p)
{
    p->f10 = 0;
}






void func_021BD368(int a, int b, int c)
{
    func_021BD814((char *)func_021BD404(a, b), c);
}






void func_021BD378(int a, int b, int c)
{
    func_021BD7FC((struct Obj **)func_021BD404(a, b), c);
}





void func_021BD388(void *mgr, int key)
{
    func_021BD808(func_021BD43C(mgr, key));
}





void func_021BD394(int a, int b, int c)
{
    func_021BD844((char *)func_021BD404(a, b), c);
}





void func_021BD3A4(int a, int b, int c)
{
    func_021BD848((char *)func_021BD404(a, b), c);
}




int func_021BD3B4(void *mgr, int key)
{
    return func_021BD868(func_021BD43C(mgr, key));
}




int func_021BD3C0(void *mgr, int key)
{
    return *(int *)(void *)func_021BD404((int)mgr, key);
}



void ov208_func_021BD3CC(struct Ov208Mgr *p, int key, u16 *pos)
{
    struct Ov208Rec *r = ov208_func_021BD404(p, key);

    r->x = pos[0];
    r->y = pos[1];
    func_0204B404((struct Obj *)r->f0, (const struct Vec2 *)pos, (u16)(p->f20 >= 4 ? 1 : 0));
}



void func_021BD3F8(void *mgr, int key)
{
    *(int *)((char *)func_021BD404((int)mgr, key) + 0x34) = 1;
}
