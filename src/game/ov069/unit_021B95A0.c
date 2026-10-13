/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B9658, func_021B9680, func_021B96C8, func_021B96D4, func_021B9784, func_021B97D4, func_021B97F4, func_021B9888, func_021B98AC, func_021B9A44, func_021B9A50
 * address:  0x021B95A0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_0202223C  0x0202223C  thumb
 *   func_021B9B44  0x021B9B44  thumb  ov069
 *   func_021B9C44  0x021B9C44  thumb  ov069
 *   func_021B9D08  0x021B9D08  thumb  ov069
 *   func_021B9F24  0x021B9F24  thumb  ov069
 *   func_021BA384  0x021BA384  thumb  ov069
 *   func_021BA438  0x021BA438  thumb  ov069
 *   func_0202208C  0x0202208C  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_021B9E44 0x021B9E44 thumb ov069
 *   func_021B9DFC 0x021B9DFC thumb ov069
 *   func_0202CD94 0x0202CD94 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_021B9F58  0x021B9F58  thumb  ov069
 *   func_021B9DE8  0x021B9DE8  thumb  ov069
 *   func_021B9CD8  0x021B9CD8  thumb  ov069
 *   func_021B9BF0  0x021B9BF0  thumb  ov069
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A90  0x02045A90  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02012EFC  0x02012EFC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_021BA350  0x021BA350  thumb  ov069
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02049238  0x02049238  arm
 *   func_020433E0 0x020433E0 arm
 *   d_021BA620 0x021BA620 data a4
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA65C  0x021BA65C  data  a4
 *   d_021BA7A0  0x021BA7A0  data  a4
 *   d_021BA60C  0x021BA60C  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_0202CB18  0x0202CB18  thumb
 *   func_0202CB4C  0x0202CB4C  thumb
 *   d_021BA66C     0x021BA66C  data  a4
 *   func_0202CA0C  0x0202CA0C  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204B100  0x0204B100  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 */
#include "../../matched/include/Obj00432.h"
#include "../../matched/include/Obj06172.h"
#include "../../matched/include/Obj01132.h"
#include "../../matched/include/Obj06170.h"
#include "../../matched/include/Obj02418.h"

struct Obj0203159C;
struct Obj;
struct WorkObj;
struct WinMgr;
struct S020315D4;
struct Buf3FC;
struct MsgBank;
struct RecSlot;
struct U16Vec;
struct WordSet;
struct Node;
struct Rec;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B160 {
    u32 w[40];
} B160;

typedef signed char s8;

typedef struct {
    int x;
    int y;
} Pos;

typedef signed int     s32;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082AC0(u32 val, void *dst, u32 size);
extern void  func_0202223C(u32 a, u32 color);
extern void func_021B9B44(struct WorkObj *o);
extern void func_021B9C44(struct Obj *o);
extern void func_021B9D08(u8 *p);
extern void func_021B9F24(char *p);
extern void  func_021BA384(char *o, int i, int n);
extern void func_021BA438(char *p, int i);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void  func_0203D34C(u32 a, u32 b);
extern int func_021B9E44(u8 *p);
extern void func_021B9DFC(u8 *p);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_0204A600(void);
extern int func_021B9F58(char *p);
extern void func_021B9DE8(u8 *p);
extern void func_021B9CD8(u8 *p);
extern void func_021B9BF0(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(unsigned int heap);
extern void *func_020490F4(u32 id, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 *func_02045A90(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void *fn, void *arg, u32 c);
extern void *func_02012EFC(void **p);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern u32 func_0200DF94(struct Buf3FC *b);
extern void func_021BA350(char *p);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *p);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u8);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 layer);
extern void func_0203F9B4(void);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CB18(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
int func_021B95A0(void *a, u32 b, u32 c);
int func_021B9658(u32 a,u32 b,u32 c,u8 *p);
int func_021B9680(u32 a, u32 b, u32 c, void *p);
void func_021B96C8(void);
void func_021B96D4(u8 *p, u32 a);
void func_021B9784(u8 *p);
void func_021B97D4(void);
void func_021B97F4(u8 *unused);
void func_021B9888(void *p);
void func_021B98AC(u8 *p);
void func_021B9A44(void *p);
void func_021B9A50(u8 *p);
extern const u32 d_021BA620[];
extern A16 d_021BA65C;
extern B160 d_021BA7A0;
extern u32 d_021BA60C[];
extern const Pos d_021BA66C[];
extern u8 d_020A1448[];



int func_021B95A0(void *a, u32 b, u32 c)
{
    u8 *p;

    func_0203064C(1, 0x80, 0x20000);
    p = func_0203159C(a, 0x168, 0x80);
    func_02082AC0(0, p, 0x168);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_021B96D4(p, c);
    func_021B97D4();
    func_021B97F4(p);
    func_021B98AC(p);
    func_021B9A50(p);
    func_021B9B44((struct WorkObj *)p);
    func_021B9C44((struct Obj *)p);
    func_021B9D08(p);
    func_021B9F24((char *)p);
    func_021BA384((char *)p, ((struct Obj00432 *)p)->f160, ((struct Obj00432 *)p)->f162);
    func_021BA438((char *)p, ((struct Obj00432 *)p)->f160);
    func_0202208C(0, 1, 1, 0, 0x10, 1, 0x80);
    func_0203D34C(1, 0x80);
    return 1;
}


/*
 * extent: final two bytes are alignment padding before next labelled function.
 */
int func_021B9658(u32 a,u32 b,u32 c,u8 *p) { if(func_021B9E44(p)==0) return 1; func_021B9DFC(p); func_0202CD94(*(struct WinMgr * *)&((struct Obj06172 *)p)->f4); func_0204A600(); return 0; }



int func_021B9680(u32 a, u32 b, u32 c, void *p)
{
    func_021B9F58(p);
    func_021B9DE8(p);
    func_021B9CD8(p);
    func_021B9BF0(p);
    func_021B9A44(p);
    func_021B9888(p);
    func_021B9784(p);
    func_020315D4((struct S020315D4 *)a);
    func_0203084C(0x80);
    func_020306F0(0x80);
    return 1;
}


void func_021B96C8(void)
{
    void func_0204A648(void);
    void func_020419E4(void);
    func_0204A648();
    func_020419E4();
}



/*
 * Byte-correct; blocked by one unwitnessed arm9 leaf (the integrator's), no outside
 * caller: func_02012EFC at 0x02012EFC (unlabelled tail-call stub), verified EXACT as
 *   extern void *func_020071CC(void *a, int b);   // symbols: func_020071CC 0x020071CC thumb
 *   void *func_02012EFC(void **p) { return func_020071CC(*p, 0x3b); }
 */
void func_021B96D4(u8 *p, u32 a)
{
    int i;
    int off = 0x154;

    *(u32 *)(p + off) = a;
    *(u32 *)(p + off + 8) = 0;
    *(void **)p = func_020490F4(0xc7, 0x80);
    *(void **)(p + 0xf4) = func_02045B38(0, 2, 0x39, 0x80);
    off -= 0x54;
    for (i = 0; i < 7; i++) {
        *(void **)(p + i * 4 + off) = func_02045EC0(*(void **)(p + 0xf4), i);
        func_02045A90(*(void **)(p + i * 4 + off));
    }
    *(void **)(p + 0xfc) = func_020457B0(0x40, 0x80);
    *(void **)(p + 0xf8) = func_0201EC74(8, 0x40, 0x80);
    *(void **)(p + 0x150) = func_020056A0((void *)func_021B96C8, p, 0);
    *(void **)(p + 8) = func_0200DF58(func_02012EFC(**(void ***)(p + 0x154)), 0x80);
    *(u32 *)(p + 0x164) = func_0200DF94(*(void **)(p + 8));
    func_021BA350((char *)p);
}



void func_021B9784(u8 *p)
{
    int i;

    func_020307B0(((struct Obj01132 *)p)->f8);
    for (i = 0; i < 7; i++) {
        func_02045808(*(void **)(p + i * 4 + 0x100));
    }
    func_02045808(((struct Obj01132 *)p)->fFC);
    func_0201ED04(((struct Obj01132 *)p)->fF8);
    func_02045C04(((struct Obj01132 *)p)->fF4);
    func_02030EAC(((struct Obj01132 *)p)->f150);
    func_02049238(((struct Obj01132 *)p)->f0);
}


void func_021B97D4(void) { func_020433E0((const struct DispVram *)d_021BA620); *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000); }



void func_021B97F4(u8 *unused)
{
    A16 a;
    B160 b;
    u32 i;
    u32 id;

    func_0203F8F4(0x80);
    a = d_021BA65C;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BA7A0;
    for (i = 0; i < 5; i++) {
        id = d_021BA60C[i];
        func_0203FCA0((u8)id, (const struct BgTemplate *)(&b.w[i * 8]), (int)0);
        func_020414EC(id);
        func_02040B94(id, 0x20, 0, 0x80);
        func_02040588(id, 1);
    }
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_02040588(3, 0);
}


void func_021B9888(void *p) { u32 i; for(i=0;i<5;i++) func_020403F4((u8)d_021BA60C[i]); func_0203F9B4(); }



void func_021B98AC(u8 *p)
{
    void *arc = ((struct Obj06170 *)p)->f0;
    void *arc2;
    int i;

    func_02049658(arc, 5, 5, 0, 0, 1, 0x80);
    func_020498F4(arc, 4, 5, 0, 0, 1, 0x80);
    func_02049B68(arc, 6, 4, 0, 0, 0x80);
    func_02049658(arc, 1, 2, 0, 0, 1, 0x80);
    func_020498F4(arc, 0, 2, 0, 0, 1, 0x80);
    func_02049B68(arc, 2, 0, 0, 0, 0x80);
    func_02049658(arc, 1, 1, 0, 0, 1, 0x80);
    func_020498F4(arc, 0, 1, 0, 0, 1, 0x80);
    arc2 = func_020490F4(func_020275E4(), 0x80);
    func_02049658(arc2, func_02027628(), 1, 0, 0, 0, 0x80);
    func_020498F4(arc2, func_0202762C(), 1, 0, 0, 0, 0x80);
    func_02049BDC(arc2, func_02027624(), 0, 0, 0x1C0, 0x20, 0x80);
    func_020413B0(1, 0, 0x15, 0x20, 3, 0xE);
    func_020409B4(1);
    func_02049238(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x80);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x80);
    ((struct Obj06170 *)p)->f4 = func_0202C9B4(2, 10, 0x80);
    for (i = 0; i < 10; i++) {
        func_0202CA3C(((struct Obj06170 *)p)->f4, i, 1, 0xE, 4);
        func_0202CB18(((struct Obj06170 *)p)->f4, i, arc, 3, 1);
        func_0202CB4C(((struct Obj06170 *)p)->f4, i, d_021BA66C[i].x, d_021BA66C[i].y);
    }
}


void func_021B9A44(void *p)
{
    void func_0202CA0C(struct WinMgr *mgr);
    func_0202CA0C(((struct Obj01132 *)p)->f4);
}



void func_021B9A50(u8 *p)
{
    void *h;
    u32 t;

    h = func_020490F4(func_020275E4(), 0x80);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_021BA620, 0x80);
    ((struct Obj02418 *)p)->f11C = (u32)func_0204B100(4, 1, 0x80);
    ((struct Obj02418 *)p)->f120 = (u32)func_0204B100(2, 1, 0x80);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    ((struct Obj02418 *)p)->f138 = func_0204A6C8(((struct Obj02418 *)p)->f0, 7, 1, 2, 0x80);
    ((struct Obj02418 *)p)->f134 = func_0204ABF0(((struct Obj02418 *)p)->f0, 10, 2, 0, 0x80);
    ((struct Obj02418 *)p)->f13C = func_0204AF28(((struct Obj02418 *)p)->f0, 8, 9, 0x80);
    ((struct Obj02418 *)p)->f144 = func_0204A6C8(h, func_02027618(), 0, 0, 0x80);
    ((struct Obj02418 *)p)->f140 = func_0204AC18(h, func_02027614(), 0, 0x160, 0, 3, 0x80);
    t = func_0202761C(0);
    ((struct Obj02418 *)p)->f148 = func_0204AF28(h, t, func_02027620(0), 0x80);
    func_02049238(h);
}
