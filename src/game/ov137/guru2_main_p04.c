/*
 * file:     guru2_main_p04.c
 * unit:     yes
 * function: func_021DDD0C, func_021DDD48, func_021DDD80, func_021DDE24, func_021DDE74, func_021DDE94, func_021DDEDC, func_021DDF38, func_021DDF64, func_021DDF84, func_021DDFC0, func_021DDFFC, func_021DE060, func_021DE08C, func_021DE17C, func_021DE220, func_021DE248, func_021DE350, func_021DE354, func_021DE37C, func_021DE388, func_021DE4B4, func_021DE55C, func_021DE5C0, func_021DE5D0, func_021DE6C0, func_021DE6DC, func_021DE6EC, func_021DE738
 * address:  0x021DDD0C
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_0202208C 0x0202208C thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021E1AE8 0x021E1AE8 data a2
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   func_020061E4 0x020061E4 thumb
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184134 0x02184134 thumb ov022
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_02039338 0x02039338 arm
 *   func_021DD93C 0x021DD93C thumb ov137
 *   func_020399A8 0x020399A8 arm
 *   func_0203A424 0x0203A424 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   sub_02039338 0x02039338 arm
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_0201CE0C 0x0201CE0C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02008534 0x02008534 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021841A0 0x021841A0 thumb ov022
 *   func_02008530 0x02008530 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049F34 0x02049F34 arm
 *   func_020307B0  0x020307B0  arm
 *   d_021E1AF8 0x021E1AF8 data a1
 *   func_0207E51C 0x0207E51C arm
 *   func_02049E34 0x02049E34 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_02184114 0x02184114 thumb ov022
 */
#include "../../matched/include/Obj23724.h"
#include "../../matched/include/Obj14214.h"
#include "../../matched/include/Obj04538.h"
#include "../../matched/include/Obj14215.h"
#include "../../matched/include/Obj14216.h"
#include "../../matched/include/Obj14217.h"
#include "../../matched/include/Obj08212.h"
#include "../../matched/include/Obj14218.h"
#include "../../matched/include/Obj23725.h"
#include "../../matched/include/Obj23726.h"
#include "../../matched/include/Obj06535.h"
#include "../../matched/include/Obj03840.h"
#include "../../matched/include/Obj23727.h"
#include "../../matched/include/Obj01261.h"
#include "../../matched/include/Obj23728.h"
#include "../../matched/include/Obj02868.h"
#include "../../matched/include/Obj23729.h"
#include "../../matched/include/Obj23730.h"
#include "../../matched/include/Obj23731.h"
#include "../../matched/include/Obj23732.h"
#include "../../matched/include/Obj23733.h"
#include "../../matched/include/Obj01414.h"
#include "../../matched/include/Obj05428.h"
#include "../../matched/include/Obj23734.h"
#include "../../matched/include/Obj23735.h"
#include "../../matched/include/Obj08210.h"
#include "../../matched/include/Obj23736.h"
#include "../../matched/include/Obj00170.h"
#include "../../matched/include/Obj23737.h"
#include "../../matched/include/Obj23738.h"

struct BmpMenu;
struct WordSet;
struct Entry;
struct Link;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct Rec3;
struct Rec;
struct Obj;
struct Sub0204A9D0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;

typedef signed short s16;

typedef struct { void *current; void *previous; } Entry;

typedef struct { char pad[0x38]; void *font; void *formatter; void *bank; void *names[5]; char pad58[0xe0]; Entry entries[5]; } Context;

typedef unsigned long long u64;

typedef union { struct { u32 a,b; } words; u64 wide; } Pair;

typedef struct { char pad[0x4824]; Pair current,previous; } Record;

typedef signed int     s32;

typedef struct { u8 pad[0x4804]; volatile int previous; } Obj;

extern void func_021DD924(char *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern struct BmpMenu *func_0201FDA0(const WinDat *,u16,u8,u8,u16);
extern unsigned func_021DE7F4(void);
extern void func_020061E4(u32 a);
extern u32 func_0201FEBC(u8 *p);
extern void *func_021DCF50(u8 *p);
extern void func_02184134(u8 *p);
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02039338(void);
extern void func_021DD93C(char *, int);
extern struct Entry *func_020399A8(void);
extern void func_0203A424(char *p, int a, int b, int c);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern void func_0203D7B0(u8 a0);
extern u16 sub_02039338(void);
extern int func_021841A4(u8 *);
extern void func_0201FEF4(u8 *o);
extern void func_0201CE0C(void *);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u8 func_021841A0(u8 *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_0201CCE4(void *, int, int, void *, void *, int, void *, int, u16, u16);
extern u32 func_0201CE30(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_0201F7A8(void *desc, u32 kind);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern void func_0207E51C(void *, int, int);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern int func_02184114(unsigned char *p);
int func_021DDD0C(char *p,int state);
int func_021DDD48(char *p,int state);
int func_021DDD80(char *p, int state);
int func_021DDE24(char *p, int state);
int func_021DDE74(char *p,int state);
int func_021DDE94(char *p, int state);
int func_021DDEDC(char *p, int state);
int func_021DDF38(char *p,int state);
int func_021DDF64(char *p,int state);
int func_021DDF84(char *p, int state);
int func_021DDFC0(char *p,int state);
int func_021DDFFC(char *p, int state);
int func_021DE060(char *p);
void func_021DE08C(char *p,int state,int player);
void func_021DE17C(char *p, int command, int player);
int func_021DE220(void *p);
int func_021DE248(void *window,int unused,u16 color,Context *p);
void func_021DE350(char *a0);
int func_021DE354(void *p);
unsigned func_021DE37C(void *p);
int func_021DE388(char *p);
void func_021DE4B4(char *p, int message, int unused);
int func_021DE55C(char *p);
void func_021DE5C0(u8 *p);
void func_021DE5D0(u8 *p);
void func_021DE6C0(char *p, void *a1);
void func_021DE6DC(u8 *p);
void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused);
int func_021DE738(Obj *obj);
extern const WinDat d_021E1AE8;
extern const u8 d_021E1AF8[];

/*
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DDD0C(char *p,int state) {if(++((struct Obj23724 *)p)->f124>60) {func_0202208C(0,0,0,0,16,1,114);state=3;}func_021DD924(p);return state;}

int func_021DDD48(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14214 *)p)->fE8=func_0201FDA0(&d_021E1AE8,31,11,0,114);((struct Obj14214 *)p)->f118=12;func_021DD924(p);return state;}

int func_021DDD80(char *p, int state) {
    char *q = *(char * *)&((struct Obj04538 *)p)->f10;
    unsigned result;
    if (((struct Obj14215 *)q)->f2C != func_021DE354(p) || ((struct Obj14215 *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x54c);
        func_021DD924(p);
        return state;
    }
    result = func_0201FEBC(((struct Obj04538 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            ((struct Obj04538 *)p)->f118 = 0;
            func_02184134(func_021DCF50((u8 *)p));
        } else {
            ((struct Obj04538 *)p)->f118 = 0xd;
            func_021DCBC4(((struct Obj04538 *)p)->f10, 0x2802, 0, 0);
            func_0201F02C(((struct Obj04538 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), 0));
        }
        ((struct Obj04538 *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}

int func_021DDE24(char *p, int state) {
    if (func_02039338() == 0) {
        func_021DE4B4(p, 5, 0);
    } else {
        func_0201F02C(((struct Obj14216 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), 0));
        func_021DE4B4(p, 0x10, 0);
    }
    func_021DD93C(p, 0xe);
    ((struct Obj14216 *)p)->f124 = 0;
    func_021DD924(p);
    return state;
}

int func_021DDE74(char *p,int state) {if(++((struct Obj14217 *)p)->f124>45) ((struct Obj14217 *)p)->f118=15;func_021DD924(p);return state;}

int func_021DDE94(char *p, int state) {
    func_020399A8();
    ((struct Obj08212 *)p)->f4814 = ((struct Obj08212 *)p)->f480C ^ func_021DE37C(p);
    func_0203A424((char *)func_020399A8(), 0xcf, 0x28, (u16)(((struct Obj08212 *)p)->f4814));
    ((struct Obj08212 *)p)->f118 = 0x10;
    func_021DD924(p);
    return state;
}

int func_021DDEDC(char *p, int state) {
    if (func_02039CB4((struct Link *)func_020399A8(), 0xcf, 0x28) != 0 ||
        ((struct Obj14218 *)p)->f4814 != (func_021DE37C(p) ^ ((struct Obj14218 *)p)->f480C)) {
        func_0203D7B0(0);
        func_0202208C(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    func_021DD924(p);
    return state;
}

int func_021DDF38(char *p,int state) {if(func_021DE55C(p)) {func_021DE4B4(p,7,0);((struct Obj23725 *)p)->f118=18;}func_021DD924(p);return state;}

int func_021DDF64(char *p,int state) {if(func_021DE55C(p)) ((struct Obj23726 *)p)->f118=10;func_021DD924(p);return state;}

int func_021DDF84(char *p, int state) {
    func_021DE4B4(p, 15, 1);
    *(int *)(p + 0x118) = 20;
    sub_02039338();
    *(int *)(p + 0x481C) = func_021841A4(func_021DCF50((u8 *)p));
    *(int *)(p + 0x4818) = 300;
    func_021DD924(p);
    return state;
}

int func_021DDFC0(char *p,int state) {if(((struct Obj06535 *)p)->f481C){if(((struct Obj06535 *)p)->f481C!=(u32)func_021841A4(func_021DCF50((u8 *)p))) ((struct Obj06535 *)p)->f481C=0;}((struct Obj06535 *)p)->f118=21;((struct Obj06535 *)p)->f124=0;func_021DD924(p);return state;}

int func_021DDFFC(char *p, int state) {
    if (((struct Obj03840 *)p)->f481C != 0) {
        if (((struct Obj03840 *)p)->f481C != func_021841A4(func_021DCF50((u8 *)p)))
            ((struct Obj03840 *)p)->f481C = 0;
    }
    if (--((struct Obj03840 *)p)->f4818 < 0)
        ((struct Obj03840 *)p)->f481C = 0;
    if (++((struct Obj03840 *)p)->f124 > 60 && ((struct Obj03840 *)p)->f481C == 0) {
        ((struct Obj03840 *)p)->f118 = 0;
        func_02039338();
    }
    func_021DD924(p);
    return state;
}

int func_021DE060(char *p) {func_0202208C(0,0,0,0,16,1,114);((struct Obj23727 *)p)->f8=1;func_021DD924(p);return 3;}

void func_021DE08C(char *p,int state,int player) {
    switch(state) {
    case 2:
        func_021DE5C0((u8 *)p);
        break;
    case 13:
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 25:
        func_021DE4B4(p,12,0);
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 19:
        if (((struct Obj01261 *)p)->f4810==1) return;
        func_0201F02C(((struct Obj01261 *)p)->f3C,0,func_02184180(func_021DCF50((u8 *)p),player));
        if (player==func_02039338()) return;
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        if (func_02039338()==0)
            ((struct Obj23728 *)(*(char * *)&((struct Obj01261 *)p)->f10))->f30&=player^0xffff;
        break;
    case 27:
        if (!func_021DE55C(p)) func_0201CE0C(((struct Obj01261 *)p)->fF0);
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    ((struct Obj01261 *)p)->f118=state;
}

void func_021DE17C(char *p, int command, int player) {
    void *target;
    if (((struct Obj02868 *)p)->f118 == 3) {
        switch (command) {
        case 1:
            target = func_02184180(func_021DCF50((u8 *)p), player);
            if (target != 0)
                func_0201F02C(((struct Obj02868 *)p)->f3C, 0, target);
            ((struct Obj02868 *)p)->f118 = command;
            ((struct Obj23729 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = func_021841A4(func_021DCF50((u8 *)p));
            ((struct Obj23730 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            return;
        case 19:
            func_0201F02C(((struct Obj02868 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), player));
            if (player != func_02039338()) {
                if (func_02039338() == 0)
                    ((struct Obj23731 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 &= player ^ 0xffff;
                ((struct Obj02868 *)p)->f118 = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Obj23732 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            ((struct Obj23733 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = func_021841A4(func_021DCF50((u8 *)p));
        }
    }
}

int func_021DE220(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(func_02184180(func_021DCF50(p),(u8)i)) n++;return n;}

/*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 */
int func_021DE248(void *window,int unused,u16 color,Context *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=func_02039338();
    if (!func_021DE388((char *)p)) return 0;
    func_02043B5C(func_02045770(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->entries[i].current) {
            int y;
            value=func_02008534(p->entries[i].current);
            text=func_020457B0(16,0x72);
            func_02008500(p->entries[i].current,p->names[i]);
            func_0201EFA4(p->formatter,0,value,5,2,1);
            format=func_02045EC0(p->bank,1);
            func_0201F250(p->formatter,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            func_0201C7D0(func_02045770(window),5,18*i+1,p->names[i],p->font,ink);
            func_0201C7D0(func_02045770(window),70,y,text,p->font,ink);
            func_02045808(text);
            do { func_02045808(format); } while (0);
        }
      } while (0);
    }
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
    return 1;
}

void func_021DE350(char *a0) {}

int func_021DE354(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(func_02184180(func_021DCF50(p),(u8)i)) n++;return n;}

unsigned func_021DE37C(void *p) {return func_021841A0(func_021DCF50(p));}

int func_021DE388(char *p) {
    int changed;
    int i;
    u32 *slot;
    Record *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        slot[0x13c/4]=slot[0x138/4];
        slot[0x138/4]=(u32)func_02184180(func_021DCF50((u8 *)p),(u8)i);
        record=(Record *)(p+i*16);
        record->previous=record->current;
        if (slot[0x138/4]) {
            record->current.words.a=func_02008530((void *)slot[0x138/4]);
            record->current.words.b=1;
        } else {
            record->current.wide=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        if (slot[0x13c/4]!=slot[0x138/4]) {
            changed=1;
            if (slot[0x138/4]==0) *(u32 *)(p+i*4+0x160)=3;
            else *(u32 *)(p+i*4+0x160)=1;
        } else {
            record=(Record *)(p+i*16);
            if (record->current.wide!=record->previous.wide) {
                changed=1;
                if (record->current.words.b==0) *(u32 *)(p+i*4+0x160)=3;
                else *(u32 *)(p+i*4+0x160)=1;
            }
        }
    }
    return changed;
}

void func_021DE4B4(char *p, int message, int unused) {
    void *text;
    void *window;
    text = func_020457B0(0xb4, 0x72);
    func_02045CAC(((struct Obj01414 *)p)->f40, message, text);
    func_0201F250(((struct Obj01414 *)p)->f3C, ((struct Obj01414 *)p)->f5C, text);
    func_02045808(text);
    func_02043B5C(func_02045770(((struct Obj01414 *)p)->fD4), 0xf);
    func_0201F73C(((struct Obj01414 *)p)->fD4, 0, 1, 0xa);
    if (((struct Obj01414 *)p)->fF0 != 0)
        func_0201CE48(((struct Obj01414 *)p)->fF0);
    ((struct Obj01414 *)p)->fF0 = func_0201CCE4(((struct Obj01414 *)p)->fD4, 0, 0, ((struct Obj01414 *)p)->f5C, ((struct Obj01414 *)p)->f38, 0, ((struct Obj01414 *)p)->fF4, 0, 0x72, 0xf);
    window = ((struct Obj01414 *)p)->fD4;
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
}

int func_021DE55C(char *p) {
    int state;
    if (((struct Obj05428 *)p)->fF0 == 0) return 1;
    state = func_0201CE30(((struct Obj05428 *)p)->fF0);
    if (state == 0) {
        if (func_0203630C() & 1)
            func_0201CE5C(((struct Obj05428 *)p)->fF0, 0);
    } else if (state == 1) {
        if (func_020362DC() & 1)
            func_0201CE38(((struct Obj05428 *)p)->fF0);
    } else if (state == 2) {
        func_0201CE48(((struct Obj05428 *)p)->fF0);
        ((struct Obj05428 *)p)->fF0 = 0;
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021DE5C0(u8 *p)
{
    func_0201F7A8(((struct Obj23734 *)p)->fD4, 0);
}

void func_021DE5D0(u8 *p)
{
    int i;
    int flag = 0;
    u8 a, b;
    for (i = 0; i < 5; i++) {
        switch(*(u32 *)(p+i*4+0x160)) {
        case 0: break;
        case 1:
            a=func_02008550(*(void **)(p+i*8+0x138));
            b=func_02008554(*(void **)(p+i*8+0x138));
            if (i==func_02039338()) {
                func_0204B878(*(void **)(p+i*4+0x9c),4);
            } else {
                func_021DE6EC((u8 *)p,*(u8 **)(p+0x114),i,b,a);
                func_0204B878(*(void **)(p+i*4+0x9c),4);
            }
            func_0204B3DC(*(void **)(p+i*4+0x9c),1);
            *(u32 *)(p+i*4+0x160)=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==func_02039338()) {
                func_02008550(*(void **)(p+i*8+0x138));
                func_0204B878(*(void **)(p+i*4+0x9c),5);
            } else {
                func_0204B878(*(void **)(p+i*4+0x9c),5);
            }
            *(u32 *)(p+i*4+0x160)=0;
            break;
        }
    }
    if(flag) func_020061E4(0x676);
}

void func_021DE6C0(char *p, void *a1) { ((struct Obj23735 *)p)->f110=func_02049F34(32,0,(u32)(p+276),114); }


void func_021DE6DC(u8 *p)
{
    func_020307B0(((struct Obj08210 *)p)->f110);
}

void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused)
{
    void *r;
    int n;
    func_0207E51C(*(u8 * *)&((struct Obj23736 *)q)->fC + d_021E1AF8[j] * 32, i * 32, 32);
    r = func_02049E34(32, j + 1, 0, (u32)(&n), 114);
    func_0204A9D0((int)(*(void **)(p + (i + 5) * 4 + 0x6c)), (struct Sub0204A9D0 *)n);
    func_020307B0(r);
}

/*
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 */
int func_021DE738(Obj *obj)
{
    u8 *p = (u8 *)obj;
    int state;
    state = func_021DE354(p);
    if (state > ((struct Obj23737 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f2C) {
        if (func_02184114(func_021DCF50(p))) ((struct Obj00170 *)p)->f4808 = 1;
    } else ((struct Obj00170 *)p)->f4808 = 0;
    if (state == obj->previous) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if ((unsigned)func_021841A4(func_021DCF50(p)) > 1 || func_021841A0(func_021DCF50(p)) > 1) return 1;
        *(int *)&((struct Obj00170 *)p)->f118 = 17;
        if (((struct Obj00170 *)p)->fE8) {
            func_0201FEF4(((struct Obj00170 *)p)->fE8);
            ((struct Obj00170 *)p)->fE8 = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previous)
            ((struct Obj23738 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f2C = (unsigned)func_021841A4(func_021DCF50(p));
        break;
    case 5: break;
    }
    obj->previous = func_021DE354(p);
    return 1;
}
