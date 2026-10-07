/*
 * file:     musical_mcss_p01.c
 * unit:     yes
 * function: func_021F40D0, func_021F40F4, func_021F4280, func_021F4284, func_021F4300, func_021F4350, func_021F44E8
 * address:  0x021F40D0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F8264 0x021F8264 data a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02049B40 0x02049B40 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045924 0x02045924 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02030734 0x02030734 arm
 *   func_021F44F8 0x021F44F8 thumb ov112
 *   func_021F46A8 0x021F46A8 thumb ov112
 *   func_02027F60 0x02027F60 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_02043598 0x02043598 arm
 *   d_021F8394 0x021F8394 data a1
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_021F4748 0x021F4748 thumb ov112
 *   func_020403F4 0x020403F4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021F4794 0x021F4794 thumb ov112
 *   func_021F485C 0x021F485C thumb ov112
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_0200A640 0x0200A640 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F4804 0x021F4804 thumb ov112
 *   func_0200FB24 0x0200FB24 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_020310C4 0x020310C4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 */
#include "../../matched/include/Obj00669.h"
#include "../../matched/include/Obj04456.h"
#include "../../matched/include/Obj00226.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct R;
struct Bank;
struct Obj;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct Rec3;
struct TaskMenu;
struct Tcbl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 words[4]; } Quad;

typedef signed short s16_021F40F4;

typedef struct { u32 pad:9; u32 a:7; u32 b:5; u32 c:6; u32 tail:5; } Input;

typedef short s16_021F4280;

typedef signed char s8;

typedef int s32;

typedef struct { u16 v; u16 pad; } H16;

typedef struct { u8 b[8]; } Box;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *,s16_021F40F4,s16_021F40F4,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021F44F8(u8 *p);
extern void func_021F46A8(u8 *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_021F4748(u8 *);
extern void func_020403F4(u32 i);
extern u32 func_020307B0(void *p);
extern void func_020061E4(u32);
extern u32 func_020221A4(void);
extern void func_021F4794(u8 *,u32);
extern void func_021F485C(u8 *);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern void *func_0200A640(void *);
extern void func_02082D44(const void *,void *,u32);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern void func_021F4804(u8 *,u32);
extern u32 func_0200FB24(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_0201CE30(void *);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_020310C4(struct Tcbl *p);
extern void func_02041EE4(u32,u32,u32);
u32 func_021F40D0(void *p,u32 i,u16 c);
void func_021F40F4(u8 *p);
void func_021F4280(u8 *a0);
void *func_021F4284(u32 a, u32 b, u32 c, u32 d, H16 heap);
void func_021F4300(u8 *p);
void func_021F4350(u8 *p);
int func_021F44E8(u32 *p);
extern const Quad d_021F8264;
extern char d_021F8394[];
extern const Box d_021F8290;

u32 func_021F40D0(void *p,u32 i,u16 c) { Quad q=d_021F8264; return q.words[i]; }

void func_021F40F4(u8 *p)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((struct Obj00669 *)p)->f54=(void *)func_020450F0(1,24,22,8,2,10,1);
    ((struct Obj00669 *)p)->f58=(void *)func_020450F0(1,1,1,30,2,10,1);
    func_02043B5C(func_02045770(((struct Obj00669 *)p)->f54),0);
    func_02043B5C(func_02045770(((struct Obj00669 *)p)->f58),0);
    ((struct Obj00669 *)p)->f5C=func_0201D7EC(23,3,0,0,((struct Obj00669 *)p)->f0);
    ((struct Obj00669 *)p)->f60=func_0201D7EC(23,0,0,0,((struct Obj00669 *)p)->f0);
    func_02049B40(23,5,0,320,32,((struct Obj00669 *)p)->f0);
    buf=func_020457B0(128,((struct Obj00669 *)p)->f0);
    t=func_0201EC64(((struct Obj00669 *)p)->f0);
    f=func_02045B38(0,2,78,((struct Obj00669 *)p)->f0);
    b=func_02045EC0(f,0);
    func_0201EFA4(t,0,(*(Input * *)&((struct Obj00669 *)p)->f4)->a,2,2,1);
    func_0201EFA4(t,1,(*(Input * *)&((struct Obj00669 *)p)->f4)->b,2,2,1);
    func_0201EFA4(t,2,(*(Input * *)&((struct Obj00669 *)p)->f4)->c,2,2,1);
    func_0201F250(t,buf,b);
    func_0201C7D0(func_02045770(((struct Obj00669 *)p)->f54),0,0,buf,((struct Obj00669 *)p)->f5C,3424);
    func_02045808(buf);
    func_02045808(b);
    func_0201ED04(t);
    func_02045C04(f);
    buf=func_020457B0(37,((struct Obj00669 *)p)->f0);
    func_02045924(buf,(const u16 *)(*(u8 * *)&((struct Obj00669 *)p)->f4+356));
    func_0201C7D0(func_02045770(((struct Obj00669 *)p)->f58),0,0,buf,((struct Obj00669 *)p)->f60,15424);
    func_02045808(buf);
    func_02045334(((struct Obj00669 *)p)->f54);
    func_02045374(((struct Obj00669 *)p)->f54);
    func_02045334(((struct Obj00669 *)p)->f58);
    func_02045374(((struct Obj00669 *)p)->f58);
    func_020409B4(1);
}


void func_021F4280(u8 *a0) { }

void *func_021F4284(u32 a, u32 b, u32 c, u32 d, H16 heap)
{
    u8 *p = func_02030734(*(u16 *)&heap, 0x5c, 1, d_021F8394, 0x8d);
    *(u16 *)p = *(u16 *)&heap;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x44) = d;
    *(u32 *)(p + 0x2c) = 0;
    *(u8 *)(p + 8) = 0;
    if (c == 1) *(u32 *)(p + 4) = 0; else *(u32 *)(p + 4) = 1;
    func_021F44F8(p);
    func_021F46A8(p);
    *(u32 *)(p + 0x40) = (u32)func_02027F60(4, 12, *(u32 *)(p + 0x20), *(u32 *)(p + 0x38), *(u16 *)p);
    func_0203D34C(0, *(u16 *)&heap);
    func_02043598(16, 1);
    return p;
}

/*
 * extent: trailing two-byte padding at 0x021F434E.
 */
void func_021F4300(u8 *p)
{
    func_02027FD8((struct TaskMenuState *)(((struct Obj04456 *)p)->f40));
    if (((struct Obj04456 *)p)->fC==0) {
        func_0204ADA4(((struct Obj04456 *)p)->f4C);
        func_0204A8D4(((struct Obj04456 *)p)->f50);
        func_0204AFD8(((struct Obj04456 *)p)->f54);
        func_0204B3B4((struct Obj *)(((struct Obj04456 *)p)->f58));
    }
    func_0204B1CC((struct Bank *)(((struct Obj04456 *)p)->f48));
    func_021F4748(p);
    func_020403F4(4);
    func_020403F4(6);
    func_020403F4(7);
    func_020307B0(p);
}

/*
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 */
void func_021F4350(u8 *p)
{
    u8 v;
    switch (((struct Obj00226 *)p)->f4) {
    case 0:
        ((struct Obj00226 *)p)->f4=1;
        func_020061E4(1583);
    case 1:
        if(func_020221A4()==1) {
            if(((struct Obj00226 *)p)->fC==1) {
                func_021F4794(p,3);
                ((struct Obj00226 *)p)->f4=2;
            } else ((struct Obj00226 *)p)->f4=5;
        }
        break;
    case 2:
        if(!((struct Obj00226 *)p)->f24) {
            func_021F485C(p);
            ((struct Obj00226 *)p)->f4=3;
        }
        break;
    case 3:
        func_02027974(((struct Obj00226 *)p)->f3C);
        if(func_020279E8(((struct Obj00226 *)p)->f3C)==1) {
            v=func_02027A04(*(u8 * *)&((struct Obj00226 *)p)->f3C);
            func_02027858(((struct Obj00226 *)p)->f3C);
            if(v==0) func_02082D44(((struct Obj00226 *)p)->f10,func_0200A640(((struct Obj00226 *)p)->f14),432);
            if(*(int *)&((struct Obj00226 *)p)->f44) {
                ((struct Obj00226 *)p)->f4=4;
                func_021FCDEC(*(int *)&((struct Obj00226 *)p)->f44,71);
                func_021F4804(p,6);
            } else ((struct Obj00226 *)p)->f4=7;
        } else if(func_0200FB24()!=0) {
            func_02027858(((struct Obj00226 *)p)->f3C);
            ((struct Obj00226 *)p)->f4=7;
        }
        break;
    case 4:
        if(func_021FCE00(((struct Obj00226 *)p)->f44,71)==1) ((struct Obj00226 *)p)->f4=7;
        else if(func_0200FB24()!=0) ((struct Obj00226 *)p)->f4=7;
        break;
    case 5:
        if((func_020362DC()&2)||!func_02035C08(&d_021F8290)) {
            func_020061E4(1361);
            ((struct Obj00226 *)p)->f4=6;
            func_0204B878(((struct Obj00226 *)p)->f58,9);
            func_0204B92C(((struct Obj00226 *)p)->f58,1);
        }
        break;
    case 6:
        if(!func_0204B98C(((struct Obj00226 *)p)->f58)) ((struct Obj00226 *)p)->f4=7;
        break;
    case 7: break;
    }
    if(((struct Obj00226 *)p)->f24&&func_0201CE30(((struct Obj00226 *)p)->f24)==2) {
        func_0201CE48(((struct Obj00226 *)p)->f24);
        ((struct Obj00226 *)p)->f24=0;
    }
    func_0201C4E4(((struct Obj00226 *)p)->f38);
    if(((struct Obj00226 *)p)->f30==1&&func_0201C6B4(((struct Obj00226 *)p)->f38)==1) {
        ((struct Obj00226 *)p)->f30=0;
        *(u8 * *)&((struct Obj00226 *)p)->f34=func_0202EE8C(*(u32 *)&((struct Obj00226 *)p)->f18,((struct Obj00226 *)p)->f1C,15,16,((struct Obj00226 *)p)->f0);
        func_02045334(((struct Obj00226 *)p)->f1C);
    }
    func_020310C4(((struct Obj00226 *)p)->f18);
    (*(volatile u8 *)&((struct Obj00226 *)p)->f8)++;
    if(*(volatile u8 *)&((struct Obj00226 *)p)->f8>1) {
        *(volatile u8 *)&((struct Obj00226 *)p)->f8=0;
        func_02041EE4(7,1,1);
        func_02041EE4(7,5,1);
    }
}


int func_021F44E8(u32 *p) { if(p[1]==7) return 1; return 0; }
