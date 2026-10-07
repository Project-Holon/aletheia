/*
 * file:     pokemontrade_proc_p21.c
 * unit:     yes
 * function: func_021DCD38, func_021DCF24, func_021DD018, func_021DD080, func_021DD09C, func_021DD0CC, func_021DD140, func_021DD174, func_021DD1B8, func_021DD21C, func_021DD24C, func_021DD294, func_021DD2A8, func_021DD2F4, func_021DD34C, func_021DD380, func_021DD3D4, func_021DD428, func_021DD4F4, func_021DD528, func_021DD588, func_021DD5B4, func_021DD68C, func_021DD90C, func_021DD9DC, func_021DDA50, func_021DDAD4, func_021DDB10, func_021DDB64
 * address:  0x021DCD38
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020275DC 0x020275DC thumb
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021D8A50 0x021D8A50 thumb ov119
 *   func_021DF868 0x021DF868 thumb ov119
 *   func_0204A600 0x0204A600 arm
 *   func_02027974 0x02027974 thumb
 *   func_02028178 0x02028178 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021DF978 0x021DF978 thumb ov119
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02014C08 0x02014C08 thumb
 *   func_02014D2C 0x02014D2C thumb
 *   func_021E31B4 0x021E31B4 thumb ov119
 *   func_02047970 0x02047970 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_02156ED0 0x02156ED0 thumb ov009
 *   func_0203D29C 0x0203D29C arm
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200FB38 0x0200FB38 thumb
 *   func_021DC818 0x021DC818 thumb ov119
 *   func_0202223C 0x0202223C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 *   func_021E5D84 0x021E5D84 thumb ov119
 *   func_021DC720 0x021DC720 thumb ov119
 *   func_020275E0 0x020275E0 thumb
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_021E31BC 0x021E31BC thumb ov119
 *   func_02030EAC 0x02030EAC arm
 *   func_021DC5D0 0x021DC5D0 thumb ov119
 *   func_021DC428 0x021DC428 thumb ov119
 *   func_021DC484 0x021DC484 thumb ov119
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   d_00000072 0x00000072 data a1
 *   d_00000043 0x00000043 data a1
 *   d_00000075 0x00000075 data a1
 *   d_00000076 0x00000076 data a1
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   d_021E7FE0 0x021E7FE0 data ov119 a4
 *   func_02039C68 0x02039C68 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02019D84 0x02019D84 thumb
 *   d_021E7718 0x021E7718 data ov119 a4
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021E2984 0x021E2984 thumb ov119
 *   func_021E2A80 0x021E2A80 thumb ov119
 *   func_021D89CC 0x021D89CC thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021E2A1C 0x021E2A1C thumb ov119
 *   func_0201293C 0x0201293C thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02007984 0x02007984 thumb
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021E80E0 0x021E80E0 data a4
 *   func_021DF918 0x021DF918 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_02049238 0x02049238 arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021DF9E8 0x021DF9E8 thumb ov119
 *   func_021E6334 0x021E6334 thumb ov119
 *   d_021E7704     0x021E7704  data  a4
 *   func_020275E4  0x020275E4  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021E76FC 0x021E76FC data a4
 *   func_020456F8 0x020456F8 arm
 *   func_021D8980  0x021D8980  thumb  ov119
 *   func_021DEBD4  0x021DEBD4  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E12F8  0x021E12F8  thumb  ov119
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0202208C  0x0202208C  thumb
 *   d_021E76F4 0x021E76F4 data a4
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DEA24 0x021DEA24 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj03257.h"
#include "../../matched/include/Obj22736.h"
#include "../../matched/include/Obj22737.h"
#include "../../matched/include/Obj10358.h"
#include "../../matched/include/Obj08061.h"
#include "../../matched/include/Obj22738.h"
#include "../../matched/include/Obj13896.h"
#include "../../matched/include/Obj22739.h"
#include "../../matched/include/Obj06425.h"
#include "../../matched/include/Obj00384.h"
#include "../../matched/include/Obj22740.h"

#define I(o) (*(int *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
#define B(o) (*(u8 *)(p+(o)))
struct Light;
struct McssSys;
struct Tcbl;
struct Entry;
struct PrintSys;
struct S020315D4;
struct Node;
struct Link;
struct Sav;
struct BigObj;
struct S119DD4F4;
struct State;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct WordSet;
struct TaskMenu;
typedef unsigned char u8;

typedef unsigned u32_021DCD38;

typedef struct Bits {u8 low:4,high:4;} Bits;

typedef unsigned short u16;

typedef unsigned int   u32_021DCF24;

typedef unsigned int   u32_021DD0CC;

typedef unsigned int   u32_021DD174;

typedef unsigned int   u32_021DD1B8;

typedef unsigned int   u32_021DD2A8;

typedef unsigned int   u32_021DD380;

typedef unsigned int u32_021DD428;

typedef struct State {
    char pad[0xfa4];
    int a[2][3];
    int b[2][3];
    char gap[4];
    void *value[2][3];
} State;

typedef unsigned int   u32_021DD4F4;

struct S { char pad[0xFA4]; int a[3][3]; int b[3][3]; int c[3][3]; };

struct S119DD4F4 { char pad[0xFA4]; int a[2][3]; int b[2][3]; int gap; int c[2][3]; };

typedef signed int     s32;

typedef unsigned int   u32_021DD528;

typedef unsigned int   u32_021DD588;

typedef unsigned int   u32_021DD5B4;

typedef unsigned int u32_021DD68C;

typedef signed short s16;

typedef struct {
    int a;
    int b;
} Pair_021DD68C;

typedef unsigned int u32_021DD90C;

typedef struct { int a,b; } Pair_021DD90C;

typedef unsigned int   u32_021DD9DC;

typedef unsigned int   u32_021DDA50;

typedef struct { int a,b; } Pair_021DDAD4;

extern int func_020275DC(void);
extern int func_021D8A24(void *);
extern u32_021DCD38 func_0200FB24(void);
extern u32_021DCD38 func_0203D29C(void);
extern void func_021D9468(void *,int,void *);
extern void func_021D8A50(void *);
extern void func_021DF868(void *);
extern void func_0204A600(void),func_02027974(void *),func_02028178(u8 *);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32_021DCD38 b, u32_021DCD38 c, u32_021DCD38 d);
extern void func_0201DE00(u8 *,u8 *,u8 *);
extern void func_0201DD78(u32_021DCD38,u32_021DCD38,u32_021DCD38);
extern void func_020310C4(struct Tcbl *p);
extern u32_021DCD38 func_0201C4E4(struct PrintSys *ps);
extern void func_021DF978(void *);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_02014C08(char *);
extern void func_02014D2C(struct McssSys *sys);
extern void func_021E31B4(void *);
extern void func_02047970(void);
extern void func_0200F7C0(unsigned);
extern void func_021B9774(u8 *);
extern void func_021B9838(u8 *);
extern void func_02156DC4(int,int);
extern void func_02156ED0(void);
extern int func_02157170(int a0, int a1);
extern void func_0200FB38(void);
extern void func_021DC818(char *);
extern void func_0202223C(unsigned,unsigned);
extern unsigned func_020221A4(void);
extern unsigned int func_020307B0(void *p);
extern void func_021E5EF8(void *);
extern void func_021E5D84(char *);
extern void func_021DC720(char *);
extern void func_020275E0(void);
extern void func_0203A5E4(u32_021DCF24 key);
extern void func_021E31BC(char *);
extern void func_02030EAC(struct Node *n);
extern void func_021DC5D0(char *p, int a1);
extern void func_021DC428(char *p);
extern void func_021DC484(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_02034A5C(int);
extern int func_021E4DBC(char *);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern u8 func_020355C4(void);
extern void func_021E68F4(int p, int i);
extern u32_021DD0CC func_02017E88(void *p, u32_021DD0CC id, u32_021DD0CC v);
extern u32_021DD0CC func_02017DBC(struct Sav *p);
extern u32_021DD0CC func_02017DE4(struct Sav *p, u32_021DD0CC f);
extern int func_02019D84(unsigned short);
extern int func_021D8ADC(char *p);
extern u32_021DD1B8 func_020173EC(void);
extern void func_02082BCC(void *, int, int);
extern void *func_021E2984(char *p, int a);
extern int func_021E2A80(void *);
extern void func_021D89CC(char *p);
extern void func_021D8E84(void *, int);
extern void func_021D9434(void *);
extern void func_021E2A1C(char *p, int a, int b);
extern unsigned int func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern u32_021DD2A8 func_0201AA18(void *p);
extern int func_02007984(void *save);
extern int func_021D8AA8(void *);
extern void *func_02030734(u32_021DD380 heapId, u32_021DD380 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *,const void *,int);
extern void func_021DF918(void *,int,void *);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204ACEC(void *a0, u32_021DD528 a1, u32_021DD528 a2, u32_021DD528 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32_021DD528 first, u32_021DD528 second, u32_021DD528 mode);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void func_02049238(void *);
extern void func_0204ADA4(u32_021DD588 i);
extern void func_0204AFD8(u32_021DD588 i);
extern void *func_021D8D4C(void **a, int b, int c, char *p);
extern int func_021DF9E8(char *,void *,int);
extern void func_021E6334(char *p, int i, int j, void *mon, int selected, u32_021DD5B4 visible);
extern u32_021DD68C func_020275E4(void);
extern void func_02049B40(u32_021DD68C, u32_021DD68C, u32_021DD68C, u32_021DD68C, u32_021DD68C, u16);
extern u32_021DD68C func_020452E8(struct Descriptor *d);
extern u32_021DD68C func_020450F0(u32_021DD68C layer, u32_021DD68C a, u32_021DD68C b, u32_021DD68C tiles, u8 c, u8 d, u8 slot);
extern void func_02045CAC(struct MsgBank *bank, u32_021DD68C index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_0201F02C(struct WordSet *p, u32_021DD68C i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32_021DD68C bit);
extern void func_020456F8(struct Descriptor *d);
extern int func_021D8980(char *p);
extern void func_021DEBD4(void *p);
extern void func_021E1098(char *p);
extern void func_021E12F8(char *p);
extern u32_021DDA50 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_0202208C(void *p1, u32_021DDA50 p2, u32_021DDA50 p3, u32_021DDA50 p4, u32_021DDA50 p5, u32_021DDA50 p6, u32_021DDA50 p7);
extern void func_021E1410(void *p, int *ids, int count);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_021DEA24(char *p);
extern int func_021E12AC(char *p);
int func_021DCD38(int a,int b,int c,char *p);
int func_021DCF24(void *owner,int unused,int keep,char *p);
void func_021DD018(char *p, int flag);
void func_021DD080(void *a, void *b, void *c);
void func_021DD09C(char *p);
int func_021DD0CC(char *p, int a);
int func_021DD140(char *p);
void func_021DD174(char *p);
void func_021DD1B8(char *p);
int func_021DD21C(char *p);
int func_021DD24C(char *p);
void func_021DD294(char *p, int a, int b);
int func_021DD2A8(char *p);
int func_021DD2F4(char *p);
int func_021DD34C(char *p, int a, int b);
void func_021DD380(char *p,int i,void *src);
int func_021DD3D4(const char *p, int n, int a, int b);
int func_021DD428(State *p,int side,int a,int b,void *value);
void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
void func_021DD528(char *p,int n);
void func_021DD588(char *p);
int func_021DD5B4(char *p,int a,int b);
void func_021DD68C(char *p);
void func_021DD90C(u8 *p,int i,int msg,int force);
void func_021DD9DC(unsigned char *p);
void func_021DDA50(void *p);
void func_021DDAD4(char *p);
void func_021DDB10(unsigned char *p);
void func_021DDB64(unsigned char *p);
extern char d_00000072[],d_00000043[],d_00000075[],d_00000076[];
extern const int d_021E7FE0[];
extern const int d_021E7718[];
extern const char d_021E80E0[];
extern const Pair_021DD68C d_021E7704;
extern const Pair_021DD90C d_021E76FC;
extern const Pair_021DDAD4 d_021E76F4;

int func_021DCD38(int a,int b,int c,char *p)
{
    int result=1;
    void (*callback)(char *)=*(void (**)(char *))(p+0x5ec);
    int i;
    u8 rgb[3];
    if(func_020275DC()) return 0;
    if(callback) {
        callback(p);
        I(0xf2c)++;
        result=0;
        for(i=0;i<2;i++) func_021DD90C((u8 *)p,i,*(u8 *)(p+i+0x11e8),0);
    }
    if(I(0xf9c) && B(0x11f3)==0) {
        func_021D9468(p,1,*(void **)(p+(I(0xf9c)-1)*4+0x5dc));I(0xf9c)=0;
    }
    func_021D8A50(p);func_021DF868(p);func_0204A600();
    if(P(0x64c)) func_02027974(P(0x64c));
    if(P(0x648)) func_02028178(P(0x648));
    if(((Bits *)(p+0x11fb))->high) {
        if(func_0203D3A8((struct Entry *)((unsigned)func_020399A8()),0xc17,0,0)) ((Bits *)(p+0x11fb))->high=0;
    }
    if(P(0x744)) {
        func_0201DE00(&rgb[2],&rgb[1],&rgb[0]);
        func_0201DD78(1,2,15);
        func_020310C4(P(0x744));
        func_0201DD78(rgb[2],rgb[1],rgb[0]);
        func_0201C4E4(P(0x740));
    }
    func_021DF978(p);func_02047964();func_02048AD0(P(0x810));func_020479D8();
    func_02014C08(P(0x840));func_02014D2C(P(0x840));func_021E31B4(p);func_02047970();
    if(func_021D8A24(p) && I(0xef8)==0 && func_0200FB24()) {
        if(B(0x11f7)) func_0200F7C0(41);
        if(P(0)) {
            func_021B9774(P(0));func_021B9838(P(0));P(0)=0;
            func_02156DC4(0,0);func_02156ED0();
        }
        if(func_0203D29C()) func_02157170(1,1);
        else if(I(0x118c)!=1) func_0200FB38();
        *(int *)((char *)P(8)+8)=2;
        func_021DC818(p);
        result=1;
        func_0202223C(0,0);func_0202223C(1,0);
    }
    return result;
}

int func_021DCF24(void *owner,int unused,int keep,char *p)
{
    int state=((struct Obj00001 *)p)->f118C;
    if(func_020221A4()==0)return 0;
    func_020307B0(((struct Obj00001 *)p)->f10A4);
    func_020307B0(((struct Obj00001 *)p)->f10A8);
    func_021E5EF8(p+0x950);func_021E5EF8(p+0x964);func_021E5EF8(p+0x978);
    func_021E5D84(p);func_021DC720(p);func_020275E0();
    if(func_021D8A24(p))func_0203A5E4(0xc00);
    func_021E31BC(p);
    func_020307B0(((struct Obj00001 *)p)->f5DC);func_020307B0(((struct Obj00001 *)p)->f5E0);
    func_02030EAC(((struct Obj00001 *)p)->f9C8);
    func_021DC5D0(p,keep!=0);
    func_021DC428(p);func_021DC484(p);func_020315D4(owner);
    func_020306F0(31);func_020306F0(145);
    if(state<5) {func_02034A5C((int)d_00000072);func_02034A5C((int)d_00000043);}
    func_02034A5C(state==0 || state==4 ?(int)d_00000075:(int)d_00000076);
    return 1;
}

void func_021DD018(char *p, int flag)
{
    int n;
    if (flag) {
        n = func_021E4DBC(p) + 2;
        if (n >= ((struct Obj03257 *)p)->f634) n -= ((struct Obj03257 *)p)->f634;
        if (((struct Obj03257 *)p)->f107C == d_021E7FE0[0]) n = 2;
        else if (((struct Obj03257 *)p)->f107C == d_021E7FE0[((struct Obj03257 *)p)->f630]) {
            n = 0;
            if (((struct Obj03257 *)p)->fF78 >= 3) ((struct Obj03257 *)p)->fF78 = 2;
        }
        ((struct Obj03257 *)p)->fF74 = n;
        ((struct Obj03257 *)p)->f1080 = -1;
    }
}

void func_021DD080(void *a, void *b, void *c)
{
    if (func_021D8A24(c))
        func_02039C68(a, (unsigned int)b, 8);
}

void func_021DD09C(char *p)
{
    if (func_020355C4()) {
        func_021E68F4((int)p, -1);
        return;
    }
    {
        int v = ((struct Obj22736 *)p)->f10A0;
        if (v != -1)
            func_021E68F4((int)p, v);
    }
}

int func_021DD0CC(char *p, int a)
{
    int v, lock, r;
    unsigned i;
    v = func_02017E88((void *)a,5,0);
    i = 0;
    if (((struct Obj22737 *)p)->f118C == 3) {
        lock = func_02017DBC((struct Sav *)a);
        for (; i < 15; i++) {
            r = func_02017E88((void *)a,d_021E7718[i],0);
            if (r == 1) break;
        }
        func_02017DE4((struct Sav *)a,lock);
        if (r) return 1;
        if (func_02019D84(v)) return 1;
    }
    return 0;
}

int func_021DD140(char *p)
{
    if (((struct Obj00001 *)p)->f11F1) {
        if (func_021D8ADC(p))
            ((struct Obj00001 *)p)->f11F1 = ((struct Obj00001 *)p)->f11F1 - 1;
        else
            ((struct Obj00001 *)p)->f11F1 = 0;
    }
    return ((struct Obj00001 *)p)->f11F1 == 0;
}

void func_021DD174(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            if (((struct Obj10358 *)q)->fFD8) {
                func_020307B0(((struct Obj10358 *)q)->fFD8);
                ((struct Obj10358 *)q)->fFD8 = 0;
            }
        }
    }
}

void func_021DD1B8(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            ((struct Obj08061 *)q)->fFA4 = -1;
            ((struct Obj08061 *)q)->fFBC = -1;
            if (((struct Obj08061 *)q)->fFD8) func_02082BCC(((struct Obj08061 *)q)->fFD8, 0, func_020173EC());
        }
    }
}

int func_021DD21C(char *p)
{
    int i, n = 0;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0xFA4) != -1 && *(int *)(p + i * 4 + 0xFBC) != -1)
            n++;
    }
    return n;
}

int func_021DD24C(char *p)
{
    if (((struct Obj00001 *)p)->f118C == 3) {
        if (*(int *)&((struct Obj00001 *)p)->f648 == 0) func_021E2984(p, 0x9a);
        if (func_021E2A80(p)) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return 1;
        }
    }
    return 0;
}

void func_021DD294(char *p, int a, int b)
{
    if (((struct Obj22738 *)p)->f118C == 3)
        func_021E2A1C(p, a, b);
}

int func_021DD2A8(char *p)
{
    int a, b, n;
    a = func_0201293C((const struct BigObj *)(*(int *)&((struct Obj13896 *)p)->f82C));
    b = func_021DD21C(p);
    n = func_0201AA18(func_02012934(((struct Obj13896 *)p)->f82C));
    n += func_02007984((void *)a);
    if (n == 2 && b >= 1) return 1;
    if (n > 2 && b >= 2) return 1;
    return 0;
}

int func_021DD2F4(char *p)
{
    int i;
    if (func_021D8AA8(p)) {
        for (i = 0; i < 3; i++) {
            if (*(int *)(p + i * 4 + 0xfa4) != -1 && *(int *)(p + i * 4 + 0xfbc) != -1) return 1;
        }
    } else {
        if (((struct Obj00001 *)p)->fF84 != -1 && ((struct Obj00001 *)p)->fF88 != -1) return 1;
    }
    return 0;
}

int func_021DD34C(char *p, int a, int b)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (b == *(int *)(p + i * 4 + 0xFA4) && a == *(int *)(p + i * 4 + 0xFBC))
            return i;
    }
    return -1;
}

void func_021DD380(char *p,int i,void *src)
{
    *(int *)(p+0xfb0+i*4)=i; *(int *)(p+0xfc8+i*4)=i; if(*(void **)(p+0xfe4+i*4)==0) *(void **)(p+0xfe4+i*4)=func_02030734(((struct Obj22739 *)p)->f5F4,func_020173EC(),1,(void *)d_021E80E0,0x122);func_02082D44(src,*(void **)(p+0xfe4+i*4),func_020173EC());
}

/*
 * lever: Spell the indexed object base at each field read; a cached q local
 * swaps the first-loop counter and pooled-offset registers (10 bytes).
 */
int func_021DD3D4(const char *p, int n, int a, int b)
{
    int j;
    long i;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + n * 12 + 0xfa4 + i * 4) == a &&
            *(int *)(p + n * 12 + 0xfbc + i * 4) == b)
            return -1;
    }
    for (j = 0; j < 3; j++) {
        if (*(int *)(p + n * 12 + 0xfa4 + j * 4) == -1)
            return j;
    }
    return 2;
}

/*
 * lever: Separate two-by-three struct fields recompute the side offset;
 * raw combined offsets cached it in ip and produced 208 rather than 204 bytes.
 */
int func_021DD428(State *p,int side,int a,int b,void *value)
{
    int i;
    for(i=0;i<3;i++) {
        if(a==p->a[side][i] && b==p->b[side][i])
            return -1;
    }
    for(i=0;i<3;i++) {
        if(p->a[side][i]==-1 || i==2) {
            p->a[side][i]=a;
            p->b[side][i]=b;
            if(p->value[side][i]==0)
                p->value[side][i]=func_02030734(((struct Obj00001 *)p)->f5F4,func_020173EC(),1,d_021E80E0,0x14c);
            func_02082D44(value,p->value[side][i],func_020173EC());
            func_021DF918(p,side,value);
            return i;
        }
    }
    return -1;
}

void func_021DD4F4(struct S119DD4F4 *p, int i, int j)
{
    p->a[i][j] = -1;
    p->b[i][j] = -1;
    if (p->c[i][j])
        func_020307B0((void *)p->c[i][j]);
    p->c[i][j] = 0;
}

void func_021DD528(char *p,int n)
{
    void *v;int off;int a;v=func_020490F4(7,((struct Obj06425 *)p)->f5F4);off=96;if(n!=1)off=0;((struct Obj06425 *)p)->f890=func_0204ACEC(v,func_0201BC3C(),n,(u16)off,((struct Obj06425 *)p)->f5F4);a=func_0201BC78();((struct Obj06425 *)p)->f8C0=func_0204AF28(v,a,func_0201BCB4(),((struct Obj06425 *)p)->f5F4);func_02049238(v);
}


void func_021DD588(char *p)
{
    if (((struct Obj00001 *)p)->f890 != 0) {
        func_0204ADA4((u32_021DD588)(((struct Obj00001 *)p)->f890));
        ((struct Obj00001 *)p)->f890 = 0;
    }
    if (((struct Obj00001 *)p)->f8C0 != 0) {
        func_0204AFD8((u32_021DD588)(((struct Obj00001 *)p)->f8C0));
        ((struct Obj00001 *)p)->f8C0 = 0;
    }
}

int func_021DD5B4(char *p,int a,int b)
{
    int value,slot;
    unsigned i;
    func_020399A8();
    value=(int)func_021D8D4C(*(void ** *)&((struct Obj00001 *)p)->f828,((struct Obj00001 *)p)->fF88,((struct Obj00001 *)p)->fF84,p);
    if(func_021D8A24(p)) {
        i=0;
        slot=func_021DD428((struct State *)p,0,a,b,(void *)value);
        if(slot!=-1) {
            if(func_021DF9E8(p,*(void **)(p+slot*4+0xfd8),slot+0xc07)==0) {
                func_021DD4F4((struct S119DD4F4 *)p,0,slot);
                func_020307B0((void *)value);
                return 0;
            }
            for(i=0;i<(unsigned)func_020173EC();i++) {}
        }
    } else {
        slot=func_021DD428((struct State *)p,0,a,b,(void *)value);
    }
    if(slot==-1) {func_020307B0((void *)value);return 1;}
    func_021E6334(p,0,slot,(void *)value,1,0);
    func_020307B0((void *)value);
    return 1;
}


void func_021DD68C(char *p)
{
    Pair_021DD68C t;
    Pair_021DD68C u;
    void *h;
    int q;
    void *h2;
    int i;
    int k;
    int m;
    int x;

    t = d_021E7704;
    u.a = ((struct Obj00384 *)p)->f830;
    u.b = ((struct Obj00384 *)p)->f834;
    func_02049B40(func_020275E4(), 0x1F, 0, 0x1A0, 0x20, ((struct Obj00384 *)p)->f5F4);
    if (((struct Obj00384 *)p)->f5D4 != 0) {
        func_020452E8(((struct Obj00384 *)p)->f5D4);
        func_020452E8(((struct Obj00384 *)p)->f5D8);
    }
    h = (void *)func_020450F0(3, 0, 0, 0x20, 2, 13, 0);
    ((struct Obj00384 *)p)->f5D4 = h;
    func_0201DD78(14, 15, 0);
    if (((struct Obj00384 *)p)->f118C == 3 && ((struct Obj00384 *)p)->f1050 != -1) {
        func_02045CAC(((struct Obj00384 *)p)->f720, 0x85, ((struct Obj00384 *)p)->f730);
        func_0201C7A4(func_02045770(h), 8, 2, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
        func_02045CAC(((struct Obj00384 *)p)->f720, ((struct Obj00384 *)p)->f1050 + 0x7B, ((struct Obj00384 *)p)->f730);
        func_0201C7A4(func_02045770(h), 0x88, 2, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
    }
    func_02045334(h);
    func_02045374(h);
    i = 0;
    h2 = (void *)func_020450F0(3, 0, 3, 0x20, 8, 5, 0);
    ((struct Obj00384 *)p)->f5D8 = h2;
    for (i = 0; i < 2; i++) {
        k = i * 4;
        q = *(int *)((char *)&u + k);
        if (q != 0) {
            if (((struct Obj00384 *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                m = 0x75;
            } else {
                m = 0x80;
            }
            func_0201DD78(1, 2, 0);
            func_02045CAC(((struct Obj00384 *)p)->f720, m, ((struct Obj00384 *)p)->f734);
            func_0201F02C(((struct Obj00384 *)p)->f724, 0, (void *)q);
            func_0201F250(((struct Obj00384 *)p)->f724, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f734);
            x = *(int *)((char *)&t + k) * 8;
            func_0201C7A4(func_02045770(h2), x, 2, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
            if (((struct Obj00384 *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                func_0201DD78(3, 4, 0);
                func_02045CAC(((struct Obj00384 *)p)->f720, *(int *)(p + k + 0x1048) + 0x76, ((struct Obj00384 *)p)->f730);
                func_0201C7A4(func_02045770(h2), x + 4, 0x22, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
            }
        }
    }
    func_02045334(h2);
    func_02045374(h2);
    func_02041B6C(3);
}

/*
 * 2026-10-02 lane R1: closed by storing the call result straight into items[i] and reading it back
 * (w=items[i]): the pointer local stays live across the call and the forwarded value is spilled.
 */
void func_021DD90C(u8 *p,int i,int msg,int force)
{
    Pair_021DD90C t=d_021E76FC;
    int w;
    int *items;
    if(force==0) {
        if((p+i)[0x11e8]==3) return;
        if(p[0x11ea]==0) return;
        if(func_021D8AA8(p)==0) return;
    }
    if(*(int *)(p+i*4+0x5bc)) func_020452E8((struct Descriptor *)(*(int *)(p+i*4+0x5bc)));
    items=(int *)(p+0x5bc); items[i]=(int)func_020450F0(3,(u8)(((int *)&t)[i]),16,12,2,5,0); w=items[i];
    func_0201DD78(5,6,0);
    msg+=0x72;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),msg,(void *)(*(int *)&((struct Obj00001 *)p)->f730));
    func_0201C7A4(func_02045770((struct Descriptor *)w),0,0,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(3);
    (p+i)[0x11e8]=3;
}


void func_021DD9DC(unsigned char *p)
{
    if(((struct Obj00001 *)p)->f5BC){func_020456F8((struct Descriptor *)(((struct Obj00001 *)p)->f5BC));func_020452E8((struct Descriptor *)(((struct Obj00001 *)p)->f5BC));((struct Obj00001 *)p)->f5BC=0;}if(((struct Obj00001 *)p)->f5C0){func_020456F8((struct Descriptor *)(((struct Obj00001 *)p)->f5C0));func_020452E8((struct Descriptor *)(((struct Obj00001 *)p)->f5C0));((struct Obj00001 *)p)->f5C0=0;}if(((struct Obj00001 *)p)->f5D4){func_020456F8((struct Descriptor *)(((struct Obj00001 *)p)->f5D4));func_020452E8((struct Descriptor *)(((struct Obj00001 *)p)->f5D4));((struct Obj00001 *)p)->f5D4=0;}if(((struct Obj00001 *)p)->f5D8){func_020456F8((struct Descriptor *)(((struct Obj00001 *)p)->f5D8));func_020452E8((struct Descriptor *)(((struct Obj00001 *)p)->f5D8));((struct Obj00001 *)p)->f5D8=0;}func_02041B6C(3);
}


void func_021DDA50(void *p)
{
    int v;

    if (func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C)) == 0)
        return;
    v = func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)&((struct Obj00001 *)p)->f64C = 0;
    switch (v) {
    case 0:
        func_0202208C((void *)3, 0, 0, 0, 6, 1, ((struct Obj00001 *)p)->f5F4);
        func_021D8E84(p, 0x021DE519);
        return;
    case 1:
        func_021D8980(p);
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p, 0x021DEA25);
        return;
    }
}

void func_021DDAD4(char *p)
{
    Pair_021DDAD4 t=d_021E76F4;
    func_021E1410(p,(int *)(&t),2);
    func_021B6558((unsigned char *)(((struct Obj22740 *)p)->f9C0),1,0);
    func_021D8E84(p,(int)func_021DDA50);
}


void func_021DDB10(unsigned char *p)
{
    func_020399A8(); if(func_021D8A24(p)) { if(func_02039CB4((struct Link *)func_020399A8(),25,8)==0) {func_021DD24C((char *)p);return;} } func_021E1098((char *)p);func_021DD294((char *)p,0,0);func_021D8980((char *)p);func_021DD09C((char *)p);func_021D8E84(p,(int)func_021DEA24);
}


void func_021DDB64(unsigned char *p)
{
    func_020399A8();
    if(func_021E12AC((char *)p)) {
        func_021DD080((void *)((unsigned)func_020399A8()),(void *)25,p);
        func_021D8E84(p,(int)func_021DDB10);
    }
}
