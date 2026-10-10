/*
 * file:     zukan_detail_graphic_p01.c
 * unit:     yes
 * function: func_021BCE10, func_021BCEC0, func_021BCF18, func_021BCF2C, func_021BCF3C, func_021BCF4C, func_021BCF58, func_021BCF6C, func_021BCF84, func_021BCF98, func_021BCFF8, func_021BD030, func_021BD034, func_021BD03C, func_021BD07C, func_021BD098, func_021BD0A0, func_021BD0A8, func_021BD0AC, func_021BD11C, func_021BD12C, func_021BD140, func_021BD148, func_021BD208, func_021BD23C, func_021BD2E0, func_021BD308, func_021BD330, func_021BD358, func_021BD35C, func_021BD360, func_021BD368, func_021BD378, func_021BD388, func_021BD394, func_021BD3A4, func_021BD3B4, func_021BD3C0, func_021BD3CC, func_021BD3F8, func_021BD404, func_021BD43C, func_021BD444, func_021BD538, func_021BD56C
 * address:  0x021BCE10
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
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021C8DC0 0x021C8DC0 data a1
 *   d_021C8184 0x021C8184 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021C8138 0x021C8138 data a4
 *   d_021C81B4 0x021C81B4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4  arm
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
 *   func_021BD634        0x021BD634  thumb
 *   data_021C8DD8        0x021C8DD8  data
 *   func_021BD74C 0x021BD74C thumb
 *   func_021BD764 0x021BD764 thumb ov208
 *   func_021BD7E4 0x021BD7E4 thumb ov208
 *   func_021BD878 0x021BD878 thumb ov208
 *   func_021BD7F8 0x021BD7F8  thumb  ov208
 *   func_021BD7FC  0x021BD7FC  thumb
 *   func_021BD814 0x021BD814  thumb  ov208
 *   func_021BD808 0x021BD808  thumb  ov208
 *   func_021BD844 0x021BD844  thumb  ov208
 *   func_021BD848 0x021BD848  thumb  ov208
 *   func_021BD868 0x021BD868  thumb  ov208
 *   func_0204B404        0x0204B404  arm
 *   func_020275E4        0x020275E4  thumb
 *   func_020490F4        0x020490F4  arm
 *   func_02027624        0x02027624  thumb
 *   func_02049B68        0x02049B68  arm
 *   func_02027628        0x02027628  thumb
 *   func_02049740        0x02049740  arm
 *   func_0202762C        0x0202762C  thumb
 *   ov208_func_021BD574  0x021BD574  thumb
 *   func_02027614        0x02027614  thumb
 *   func_0204AC18        0x0204AC18  arm
 *   func_02027618        0x02027618  thumb
 *   func_0204A6C8        0x0204A6C8  arm
 *   func_0202761C        0x0202761C  thumb
 *   func_02027620        0x02027620  thumb
 *   func_0204AF28        0x0204AF28  arm
 *   func_02049238        0x02049238  arm
 */
#include "../../matched/include/Obj04613.h"
#include "../../matched/include/Obj18203.h"
#include "../../matched/include/Obj18204.h"
#include "../../matched/include/Obj14644.h"
#include "../../matched/include/Obj18205.h"
#include "../../matched/include/Obj01977.h"
#include "../../matched/include/Obj12116.h"
#include "../../matched/include/Obj18229.h"
#include "../../matched/include/Obj18230.h"
#include "../../matched/include/Obj05865.h"
#include "zukan_detail_types.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Light;
struct Obj;
struct Vec2;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {u32 bg,tmpl[8],type,on;} BgEntry;

typedef unsigned short u16;

typedef struct {int x,y,z;} Vec3;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
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
extern void func_021BD634(struct Ov208Rec *p, u32 owner, struct Ov208Bg *res,
                          struct Ov208ActDesc *desc, u32 prio, u32 mode);
extern void func_021BD74C(char *p);
extern int func_021BD764(char *);
extern int func_021BD7E4(int *p);
extern void func_021BD878(char *p);
extern int func_021BD7F8(char *);
extern void func_021BD7FC(struct Obj **p, unsigned int v);
extern void func_021BD814(char *p, int v);
extern unsigned func_021BD808(int *p);
extern void func_021BD844(char *p, int v);
extern void func_021BD848(char *p, int which);
extern int func_021BD868(const void *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32  func_020275E4(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32  func_02027624(void);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32  func_02027628(void);
extern u32  func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 flags);
extern u32  func_0202762C(void);
extern void ov208_func_021BD574(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6, u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u32 heap);
extern u32  func_02027614(void);
extern u32  func_0204AC18(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32  func_02027618(void);
extern u32  func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u32 flags);
extern u32  func_0202761C(u32 a);
extern u32  func_02027620(u32 a);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
char *func_021BCE10(unsigned display,unsigned short heap,int threeD);
void func_021BCEC0(char *p);
void func_021BCF18(char *p);
void func_021BCF2C(char *p);
void func_021BCF3C(char *p);
int func_021BCF4C(char *p);
void func_021BCF58(char *p, unsigned short x);
void func_021BCF6C(char *p);
void func_021BCF84(int unused, char *p);
void func_021BCF98(void *p,u32 heap);
void func_021BCFF8(void *p);
void func_021BD030(char *a0);
void func_021BD034(char *a0);
void func_021BD03C(unsigned char *p, int a, int b);
void func_021BD07C(char *p);
void func_021BD098(char *p);
void func_021BD0A0(char *a0);
int func_021BD0A8(int *p);
void func_021BD0AC(u32 **p,u16 heap);
void func_021BD11C(int *p);
void func_021BD12C(int *p);
void func_021BD140(char *p);
struct Ov208Mgr *ov208_func_021BD148(struct Ov208ActList *list, u32 heap);
void func_021BD208(struct Ov208Mgr *m);
void func_021BD23C(struct Ov208Mgr *p);
int func_021BD2E0(struct Ov208Mgr *p);
int func_021BD308(struct Ov208Mgr *m);
void ov208_func_021BD330(struct Ov208Mgr *p, int v);
void func_021BD358(struct Ov208Mgr *p, int v);
int func_021BD35C(struct Ov208Mgr *p);
void ov208_func_021BD360(struct Ov208Mgr *p);
void func_021BD368(struct Ov208Mgr *a, int b, int c);
void func_021BD378(struct Ov208Mgr *a, int b, int c);
int func_021BD388(struct Ov208Mgr *mgr, int key);
void func_021BD394(struct Ov208Mgr *a, int b, int c);
void func_021BD3A4(struct Ov208Mgr *a, int b, int c);
int func_021BD3B4(struct Ov208Mgr *mgr, int key);
int func_021BD3C0(struct Ov208Mgr *mgr, int key);
void ov208_func_021BD3CC(struct Ov208Mgr *p, int key, u16 *pos);
void func_021BD3F8(struct Ov208Mgr *mgr, int key);
struct Ov208Rec *func_021BD404(struct Ov208Mgr *p, int key);
void *func_021BD43C(void *mgr, int key);
void ov208_func_021BD444(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs, u32 kind, u8 pal, u8 objPal, u32 skip, u32 heap);
void func_021BD538(char *p);
int func_021BD56C(int *p, int i);
extern const char d_021C8DC0[];
extern const unsigned d_021C8184[];
extern const u32 d_021C8138[];
extern const BgEntry d_021C81B4[];
extern const Vec3 d_021C8114[];
extern const char g_020A1EB8[];
extern const char data_021C8DD8[];



/*
 * volatile: hardware 04000050/04001050 writes at 021BCE36/021BCE3C and 04000000/04001000 read-write at 021BCE40-021BCE4E.
 */
char *func_021BCE10(unsigned display,unsigned short heap,int threeD)
{
    char *p=func_02030734(heap,20,0,d_021C8DC0,0x1db);
    func_02082BCC(p,0,20);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021C8184);
    func_0204363C(display);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    ((struct Obj04613 *)p)->f10=0;
    func_021BCF98(p,heap);
    func_021BD03C((unsigned char *)p+4,(int)d_021C8184,heap);
    if(threeD)func_021BCF58(p,heap);
    ((struct Obj04613 *)p)->fC=func_020056A0((unsigned)func_021BCF84,(unsigned)p,0);
    return p;
}



/*
 * volatile: hardware writes 021BCEE4/021BCEEA and read-modify-write 021BCEEC/021BCEF4, 021BCEF6/021BCEFA.
 */
void func_021BCEC0(char *p)
{
    func_02030EAC(((struct Obj04613 *)p)->fC);
    func_021BCF6C(p);
    func_021BD07C(p+4);
    func_021BCFF8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,0x14);
    func_020307B0((void *)((unsigned)p));
}




void func_021BCF18(char *p)
{
    func_021BD098(p + 4);
    func_021BD030(p);
}




/*
 * Calls func_021BD12C on +8 when the word at +0x10 is set.
 */
void func_021BCF2C(char *p)
{
    if (((struct Obj18203 *)p)->f10 != 0)
        func_021BD12C((int *)(p + 8));
}




/*
 * Calls func_021BD140 on +8 when the word at +0x10 is set.
 */
void func_021BCF3C(char *p)
{
    if (((struct Obj18204 *)p)->f10 != 0)
        func_021BD140(p + 8);
}



int func_021BCF4C(char *p)
{
    return func_021BD0A8((int *)(p + 4));
}




/*
 * Lazy setup: sets the flag at +0x10 and initialises the sub-object at +8.
 * The second argument is only forwarded to func_021BD0AC, which is why the
 * compiler parks the flag temp in r2 rather than r1.
 */
void func_021BCF58(char *p, unsigned short x)
{
    if (((struct Obj04613 *)p)->f10 == 0) {
        ((struct Obj04613 *)p)->f10 = 1;
        func_021BD0AC((u32 **)(p + 8), x);
    }
}




void func_021BCF6C(char *p)
{
    if (((struct Obj04613 *)p)->f10 != 0) {
        func_021BD11C((int *)(p + 8));
        ((struct Obj04613 *)p)->f10 = 0;
    }
}




void func_021BCF84(int unused, char *p)
{
    func_021BD034(p);
    func_021BD0A0(p + 4);
}



void func_021BCF98(void *p,u32 heap)
{
    u32 i=0;
    const BgEntry *row;
    u32 bg;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021C8138);
    for(;i<8;i++) {
        row=&d_021C81B4[i];
        bg=row->bg;
        func_0203FCA0((u8)bg,(const struct BgTemplate *)row->tmpl,(u8)row->type);
        func_020414AC(bg);
        func_02040588(bg,row->on);
    }
}



void func_021BCFF8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4((u8)d_021C81B4[i].bg);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}



/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021BD030(char *a0)
{
}




/*
 * Tail call to the ARM9 function at 0x020419E4: loads the pointer from the pool and branches through it.
 */
void func_021BD034(char *a0)
{
    func_020419E4();
}








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








struct Ov208Mgr *ov208_func_021BD148(struct Ov208ActList *list, u32 heap)
{
    struct Ov208Mgr *set;
    u32 size;
    u32 objChannel;
    u32 palOfs;
    u32 i;

    palOfs = 0;
    size = list->count * sizeof(struct Ov208Rec) + 0x28;
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
        func_021BD634(&set->recs[i], list->owner, &set->bg, &list->descs[i], objChannel, heap);
    return set;
}







void func_021BD208(struct Ov208Mgr *m)
{
    u32 i;
    for (i = 0; i < m->count; i++)
        func_021BD74C((char *)(&m->recs[i]));
    func_021BD538((char *)&m->bg);
    func_020307B0(m);
}







void func_021BD23C(struct Ov208Mgr *p)
{
    unsigned i;
    switch(p->f8) {
    case 0:
        p->f0=-1;
        if(p->fc && !p->f10) {
            for(i=0;i<p->count;i++) {
                if(func_021BD764((char *)&p->recs[i])) {
                    p->f0=i;
                    p->f8=1;
                    p->f10=1;
                    break;
                }
            }
        }
        break;
    case 1:
        p->f8=2;
    case 2:
        if(func_021BD7E4((int *)&p->recs[p->f0]))p->f8=3;
        break;
    case 3:
        p->f8=0;
        break;
    }
    for(i=0;i<p->count;i++)func_021BD878((char *)&p->recs[i]);
}


/*
 * Returns +0x14 of the 0x38-byte record selected by the index at +0, or -1.
 */
int func_021BD2E0(struct Ov208Mgr *p)
{
    int i;

    if (p->f8 == 3) {
        i = p->f0;
        if (i != -1)
            return func_021BD7F8((char *)&p->recs[i]);
    }
    return -1;
}







int func_021BD308(struct Ov208Mgr *m)
{
    if (m->f8 == 1 && m->f0 != -1)
        return func_021BD7F8((char *)(&m->recs[m->f0]));
    return -1;
}








void ov208_func_021BD330(struct Ov208Mgr *p, int v)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        func_021BD7FC((void *)((u32)p + 0x28 + i * 0x38), v);
}









/*
 * Stores the second argument at +0xC.
 */
void func_021BD358(struct Ov208Mgr *p, int v)
{
    p->fc = v;
}









/*
 * Returns the word at +0xC (the two words after it are untraced continuations).
 */
int func_021BD35C(struct Ov208Mgr *p)
{
    return p->fc;
}








void ov208_func_021BD360(struct Ov208Mgr *p)
{
    p->f10 = 0;
}








void func_021BD368(struct Ov208Mgr *a, int b, int c)
{
    func_021BD814((char *)func_021BD404(a, b), c);
}








void func_021BD378(struct Ov208Mgr *a, int b, int c)
{
    func_021BD7FC((struct Obj **)func_021BD404(a, b), c);
}







int func_021BD388(struct Ov208Mgr *mgr, int key)
{
    return func_021BD808(func_021BD43C(mgr, key));
}







void func_021BD394(struct Ov208Mgr *a, int b, int c)
{
    func_021BD844((char *)func_021BD404(a, b), c);
}







void func_021BD3A4(struct Ov208Mgr *a, int b, int c)
{
    func_021BD848((char *)func_021BD404(a, b), c);
}






int func_021BD3B4(struct Ov208Mgr *mgr, int key)
{
    return func_021BD868(func_021BD43C(mgr, key));
}






int func_021BD3C0(struct Ov208Mgr *mgr, int key)
{
    return func_021BD404(mgr, key)->f0;
}





void ov208_func_021BD3CC(struct Ov208Mgr *p, int key, u16 *pos)
{
    struct Ov208Rec *r = func_021BD404(p, key);

    r->desc.x = pos[0];
    r->desc.y = pos[1];
    func_0204B404((struct Obj *)r->f0, (const struct Vec2 *)pos, (u16)(p->bg.fc >= 4 ? 1 : 0));
}





void func_021BD3F8(struct Ov208Mgr *mgr, int key)
{
    func_021BD404(mgr, key)->f34 = 1;
}




struct Ov208Rec *func_021BD404(struct Ov208Mgr *p, int key)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (key == func_021BD7F8((char *)((u32)p + 0x28 + i * 0x38)))
            return (struct Ov208Rec *)((u32)p + 0x28 + i * 0x38);
    }
    return 0;
}




void *func_021BD43C(void *mgr, int key)
{
    return func_021BD404(mgr, key);
}




void ov208_func_021BD444(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs,
                         u32 kind, u8 pal, u8 objPal, u32 skip, u32 heap)
{
    void *h;

    func_02082BCC(p, 0, sizeof(*p));
    p->fc = channel;
    h = func_020490F4(func_020275E4(), heap);
    if (skip == 0) {
        func_02049B68(h, func_02027624(), palOfs, pal << 5, 0x20, heap);
        p->f10 = func_02049740(h, func_02027628(), p->fc, 0x800, 0, heap);
        ov208_func_021BD574(h, func_0202762C(), p->fc, (u16)p->f10, 0, 0x15, 0x20, 0x18,
                            0, 0x15, 0x20, 3, pal, 0, heap);
    }
    p->f0 = func_0204AC18(h, func_02027614(), objChannel, (u16)(objPal << 5), 0, 3, heap);
    p->f4 = func_0204A6C8(h, func_02027618(), 0, objChannel, heap);
    p->f8 = func_0204AF28(h, func_0202761C(kind), func_02027620(kind), heap);
    func_02049238(h);
}




/*
 * Releases +8, +4 and +0, passes the pair at +0x10 on and clears the 0x14-byte object.
 */
void func_021BD538(char *p)
{
    unsigned int w;

    func_0204AFD8(((struct Obj05865 *)p)->f8);
    func_0204A8D4(((struct Obj05865 *)p)->f4);
    func_0204ADA4(((struct Obj05865 *)p)->f0);
    w = ((struct Obj05865 *)p)->f10;
    func_0203FB44(((struct Obj05865 *)p)->fC, (unsigned short)w, (unsigned short)(w >> 16));
    func_02082BCC((void *)((int)p), 0, 0x14);
}



int func_021BD56C(int *p, int i)
{
    return p[i];
}
