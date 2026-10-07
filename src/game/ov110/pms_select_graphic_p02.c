/*
 * file:     pms_select_graphic_p02.c
 * unit:     yes
 * function: func_021C0F14, func_021C1154, func_021C1174, func_021C11B8, func_021C124C, func_021C12F8, func_021C132C, func_021C133C, func_021C1440, func_021C1450, func_021C1484, func_021C14E0, func_021C154C
 * address:  0x021C0F14
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021C0C50 0x021C0C50 thumb ov110
 *   func_021C0D34 0x021C0D34 thumb ov110
 *   func_021C0EB0 0x021C0EB0 thumb ov110
 *   func_021C0DE4 0x021C0DE4 thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021C080C 0x021C080C thumb ov110
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02024910 0x02024910 thumb
 *   func_0202452C 0x0202452C thumb
 *   func_0202DE64 0x0202DE64 thumb
 *   func_0202DE5C 0x0202DE5C thumb
 *   func_02024464 0x02024464 thumb
 *   func_0202DC48 0x0202DC48 thumb
 *   func_02035D20 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021C098C 0x021C098C thumb ov110
 *   func_020355D8 0x020355D8 arm
 *   func_021C0AC0 0x021C0AC0 thumb ov110
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_021C0AC8 0x021C0AC8 thumb ov110
 *   func_02023F60 0x02023F60 thumb
 *   func_021C0B4C 0x021C0B4C thumb ov110
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021C0B44 0x021C0B44 thumb ov110
 *   func_021C09E0 0x021C09E0 thumb ov110
 *   func_02024044 0x02024044 thumb
 *   func_02024108 0x02024108 thumb
 *   func_02031348 0x02031348 arm
 *   d_021C39B8 0x021C39B8 data a4
 */
#include "../../matched/include/Obj00217.h"
#include "../../matched/include/Obj10286.h"
#include "../../matched/include/Obj22412.h"
#include "../../matched/include/Obj22413.h"
#include "../../matched/include/Obj06396.h"
#include "../../matched/include/Obj03244.h"

struct Descriptor;
struct PrintSys;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct PmsDraw;
struct T;
struct TaskMenu;
struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 lo:1; u8 hi:7; } Flags;

typedef unsigned short u16;

typedef signed short s16;

typedef struct { u8 bit:1; u8 rest:7; } Flag;

extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32);
extern void func_021C0C50(u8 *);
extern void func_021C0D34(char *,int);
extern int func_021C0EB0(char *);
extern int func_021C0DE4(char *);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021C080C(u8 *,int,int,int);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02024910(char *p, int idx);
extern int func_0202452C(const u16 *p);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern int func_02024464(struct T *p, u32 a1);
extern void func_0202DC48(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021B64D0(u8 *,u32);
extern void func_021C098C(char *);
extern void func_020355D8(u8);
extern void func_021C0AC0(void *);
extern int func_021B6470(u8 *);
extern int func_021B6448(u8 *);
extern u8 func_020355C4(void);
extern int func_021C0AC8(void *parent, void *bank, u16 size);
extern void func_02023F60(u32,u32,u32);
extern void func_021C0B4C(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021C0B44(struct TaskMenu *);
extern void func_021C09E0(u8 *);
extern struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void func_02024108(u16 *dst, const u16 *src);
extern void func_02031348(void *, int, void *, void *);
int func_021C0F14(u8 *p);
void func_021C1154(char *p);
int func_021C1174(unsigned owner, void *p, int *state);
void func_021C11B8(u8 *p,int index,int unused,int flag);
void func_021C124C(u8 *p,int index,u8 which,int flag);
int func_021C12F8(void);
int func_021C132C(void *unused,u8 *p);
int func_021C133C(void *unused,u8 *p);
int func_021C1440(void *a, u8 *p);
int func_021C1450(void *a, u8 *p);
int func_021C1484(void *arg, u8 *p);
int func_021C14E0(void *arg, u8 *p);
int func_021C154C(int *state, u8 *p);
extern const unsigned d_021C39B8[];

/*
 * lever: Byte +99 is a one-bit field; selection bytes retain 255 and the signed touch result retains -1.
 */
int func_021C0F14(u8 *p)
{
    int result=0;
    int proceed=1;
    int active;
    int hit;
    if(!((Flags *)(p+0x99))->lo) {
        active=0;
        if(func_020362DC()&~2) active=1;
        if(active && p[0x95]==255) {
            if(p[0x94]==255) p[0x95]=p[0x96];
            else if(p[0x96]<=p[0x94] && p[0x94]<p[0x96]+3) p[0x95]=p[0x94];
            else p[0x95]=p[0x96];
            p[0x94]=255;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
            func_020061E4(1352);
            func_021C0C50(p);
        }
    }
    if(proceed && p[0x95]!=255 && !((Flags *)(p+0x99))->lo) {
        if(func_020362DC()&1) {
            result=1;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(func_0203633C()&64) {
            if(p[0x95]!=0) {
                p[0x94]=p[0x95];
                p[0x95]--;
                if(p[0x95]+1==p[0x96]) p[0x96]--;
                func_021C0D34((char *)p,0);
                func_021C0C50(p);
                func_020061E4(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(func_0203633C()&128) {
            if(p[0x95]<p[0x98]-1) {
                p[0x94]=p[0x95];
                p[0x95]++;
                if(p[0x95]==p[0x96]+3) p[0x96]++;
                func_021C0D34((char *)p,0);
                func_021C0C50(p);
                func_020061E4(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        }
    }
    if(proceed) {
        if(((Flags *)(p+0x99))->lo) {
            if(func_021C0EB0((char *)p)) {
                func_021C0C50(p);
                func_020061E4(1352);
            }
            ((struct Obj00217 *)p)->fA8=1;
        } else {
            hit=func_021C12F8();
            if(hit!=-1 && hit>p[0x98]-1) hit=-1;
            if(hit!=-1) {
                p[0x94]=p[0x95];
                p[0x95]=p[0x96]+hit;
                func_021C0C50(p);
                result=1;
                ((struct Obj00217 *)p)->fA8=1;
            } else {
                if(!((Flags *)(p+0x99))->lo) func_021C0DE4((char *)p);
                if(((Flags *)(p+0x99))->lo==1) {
                    if(func_021C0EB0((char *)p) || p[0x95]!=255) {
                        p[0x94]=p[0x95];
                        p[0x95]=255;
                        func_021C0C50(p);
                    }
                    func_020061E4(1352);
                    ((struct Obj00217 *)p)->fA8=1;
                }
            }
        }
    }
    return result;
}

void func_021C1154(char *p)
{
    int i;
    for (i=0; i<4; i++)
        func_021C1174(*(unsigned *)(p+0x5c), *(void **)(p+i*4+0x6c), (int *)(p+0x7c+i*4));
}

/*
 * Extent ends with two bytes of zero padding at 0x021C11B6.
 */
int func_021C1174(unsigned owner, void *p, int *state) {
    unsigned q = (unsigned)func_02045770(p);
    if (*state == 1 && func_0201C6C4((struct PrintSys *)owner, (void *)q) == 0) {
        func_02045334(p);
        func_02045374(p);
        func_02041B6C(func_02045730(p));
        *state = 0;
        return 1;
    }
    return 0;
}

void func_021C11B8(u8 *p,int index,int unused,int flag) {
    void *str;
    u16 color;
    str=func_02045EC0(((struct Obj10286 *)p)->f60,17);
    func_021C080C(p+0x24,index,6,flag);
    if (flag) {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),14);
        color=0x44e;
    } else {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),13);
        color=0x44d;
    }
    func_0201C724(((struct Obj10286 *)p)->f5C,(u32)func_02045770(*(void **)(p+0x6c+index*4)),0,0,(u32)str,((struct Obj10286 *)p)->f58,color);
    func_02045808(str);
    func_02045374(*(void **)(p+0x6c+index*4));
    func_02041B6C(func_02045730(*(void **)(p+0x6c+index*4)));
    *(int *)(p+0x7c+index*4)=1;
}

void func_021C124C(u8 *p,int index,u8 which,int flag) {
    void *item;
    item=func_02024910(*(void **)(p+0x20),which);
    func_021C080C(p+0x24,index,func_0202452C(item),flag);
    if (flag) {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),14);
        func_0202DE64(*(void **)(p+0x8c),0x44e);
        func_0202DE5C(*(void **)(p+0x8c),14);
    } else {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),13);
        func_0202DE64(*(void **)(p+0x8c),0x44d);
        func_0202DE5C(*(void **)(p+0x8c),13);
    }
    if (func_02024464(item,*(u16 *)(p+4))==1) {
        func_0202DC48((u32)(*(void **)(p+0x8c)),(u32)(*(void **)(p+0x6c+index*4)),(u32)item,index);
        *(int *)(p+0x7c+index*4)=1;
    }
}

int func_021C12F8(void) { u32 x,y; u32 result; if(func_02035D20(&x,&y) && x<232 && y>=8) { result=(y/8-1)/6; if(result<3) return result; } return -1; }

int func_021C132C(void *unused,u8 *p) { func_021B64D0(*(u8 * *)&((struct Obj22412 *)p)->f54,1); return 1; }

/*
 * outside 0x021C133C..0x021C1440; all concrete bytes match, 9/10
 * relocations resolved. Owner-only leaf; no blocker C filed or embedded.
 * Lever: one-bit field at +0x99 gives the original shift pair. Calls in
 * both Boolean arms preserve 355D8's u8 ABI without ternary truncation.
 * Empty switch cases -1 and 7 preserve the original unused comparisons.
 * The original explicitly supplies r0 to the otherwise argument-free
 * 021C0AC0 forwarder; its unused input is retained at this caller.
 */
int func_021C133C(void *unused,u8 *p)
{
    int result=-1;
    int done=0;
    int input;
    func_021C098C((char *)p+0x24);
    if(!*(int *)(p+0x40)) {
        input=0;
        if(!((Flag *)(p+0x99))->bit) {
            if(*(int *)(p+0xa8)) func_020355D8(1);
            else func_020355D8(0);
            func_021C0AC0(*(void **)(p+0x54));
            if(func_021B6470(*(u8 **)(p+0x54))!=-1) *(int *)(p+0xa4)=0;
            result=func_021B6448(*(u8 **)(p+0x54));
            if(result!=-1) *(int *)(p+0xa4)=1;
            *(int *)(p+0xa8)=func_020355C4()==1;
        }
        switch(result) {
        case -1: break;
        case 1:
            *(int *)(*(u8 **)p+4)=1;
            *(int *)(*(u8 **)p+8)=0;
            *(int *)(p+0xa0)=5;
            return 1;
        case 7: break;
        }
        if(*(int *)(p+0xa4)) input=func_021C0F14(p);
        if(input) {
            func_020061E4(1356);
            *(int *)(p+0x40)=1;
        }
    } else {
        if(p[0x44]==16) done=1;
    }
    if(done) {
        if(func_02024464(func_02024910(*(void **)(p+0x20),p[0x95]),*(u16 *)(p+4))) *(int *)(p+0xa0)=8;
        else *(int *)(p+0xa0)=11;
        return 1;
    }
    return 0;
}

int func_021C1440(void *a, u8 *p) { func_021B64D0(*(u8 * *)&((struct Obj22413 *)p)->f54,0); return 1; }

int func_021C1450(void *a, u8 *p) { if(((struct Obj06396 *)p)->fA8) func_020355D8(1); else func_020355D8(0); ((struct Obj06396 *)p)->f68=(void *)func_021C0AC8((void *)(((struct Obj06396 *)p)->f64),(void *)(((struct Obj06396 *)p)->f60),((struct Obj06396 *)p)->f4); func_02023F60(-8,30,1); return 1; }

/*
 * Blocked on ARM9 0x02024910 (no outside witness); two-byte zero padding follows.
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 */
int func_021C1484(void *arg, u8 *p) {
    func_021C0B4C(*(void **)(p+0x68));
    if (func_020279E8(*(void **)(p+0x68))) {
        switch (func_02027A04(*(void **)(p+0x68))) {
        case 0:
            *(int *)(p+0xa0)=5;
            *(unsigned *)(*(u8 **)p+8)=(unsigned int)func_02024910(*(void **)(p+0x20),p[0x95]);
            *(unsigned *)(*(u8 **)p+4)=0;
            break;
        case 1: *(int *)(p+0xa0)=11; break;
        case 2: *(int *)(p+0xa0)=4; break;
        }
        return 1;
    }
    return 0;
}

int func_021C14E0(void *arg, u8 *p) {
    func_021C0B44(((struct Obj03244 *)p)->f68);
    ((struct Obj03244 *)p)->fA8 = func_020355C4()==1;
    if (((struct Obj03244 *)p)->fA0==4) {
        func_02023F60(0,30,1);
        func_021C09E0(p+0x24);
        p[0x44]=0;
        ((struct Obj03244 *)p)->f40=0;
        if (((struct Obj03244 *)p)->fA8!=0) {
            p[0x94]=p[0x95];
            p[0x95]=255;
            func_021C0C50(p);
        }
    }
    return 1;
}

/*
 * Blocked on ARM9 leaves 0x02024910 and 0x02024108, no outside witnesses.
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 *   typedef unsigned char u8; typedef unsigned short u16;
 *   void func_02024108(u8 *p,const u16 *s) {
 *     *(u16 *)(p+16)=s[0]; *(u16 *)(p+18)=s[1];
 *     *(u16 *)(p+20)=s[2]; *(u16 *)(p+22)=s[3];
 *   }
 */
int func_021C154C(int *state, u8 *p) {
    void *q;
    switch (*state) {
    case 0: ++*state; break;
    case 1:
        q=func_02024044(2,0,0,1,*(void **)(p+0x1c),*(u16 *)(p+4));
        func_02024108(q,func_02024910(*(void **)(p+0x20),p[0x95]));
        func_02031348(*(void **)(p+0xac),-1,(void *)d_021C39B8,q);
        *(void **)(p+0x90)=q;
        return 1;
    }
    return 0;
}
