/*
 * file:     unit_021B95A0_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B9658, func_021B9680, func_021B96C8, func_021B96D4, func_021B9784
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
 *   func_021B97D4  0x021B97D4  thumb  ov069
 *   func_021B97F4  0x021B97F4  thumb  ov069
 *   func_021B98AC  0x021B98AC  thumb  ov069
 *   func_021B9A50  0x021B9A50  thumb  ov069
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
 *   func_021B9A44  0x021B9A44  thumb  ov069
 *   func_021B9888  0x021B9888  thumb  ov069
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
 */
#include "../../matched/include/Obj00432.h"
#include "../../matched/include/Obj06172.h"
#include "../../matched/include/Obj01132.h"

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
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082AC0(u32 val, void *dst, u32 size);
extern void  func_0202223C(u32 a, u32 color);
extern void  func_021B97D4(void);
extern void  func_021B97F4();
extern void func_021B98AC(u8 *p);
extern void func_021B9A50(u8 *p);
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
extern void func_021B9A44(void *p);
extern void func_021B9888(void *p);
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
int func_021B95A0(void *a, u32 b, u32 c);
int func_021B9658(u32 a,u32 b,u32 c,u8 *p);
int func_021B9680(u32 a, u32 b, u32 c, void *p);
void func_021B96C8(void);
void func_021B96D4(u8 *p, u32 a);
void func_021B9784(u8 *p);


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
 * Byte-correct; blocked by one unwitnessed arm9 leaf (Ilias's), no outside
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
