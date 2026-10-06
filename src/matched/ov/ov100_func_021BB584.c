/*
 * function: func_021BB584
 * address: 0x021BB584
 * packet: pkt_ov100_021BB584
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: original lead code ends021BB64E, alignment nop at64E, pool650..65C;
 *   021BB65C..021BB8C0 are trailing rodata tables, descriptors and filename.
 * lever: bounded u16 off=0x28C avoids cached widened print/node offsets;
 *   off never changes and all additions promote to int, preserving offsets.
 *   C3-u16 EXACT216 after five iterations, manual order/extraction cap2.
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02027858 0x02027858 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02051C6C 0x02051C6C arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021BAC08 0x021BAC08 thumb ov100
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj02805.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct TaskMenu;struct WordSet;struct PrintSys;struct Node;struct Bank;struct S020315D4;
extern u32 func_020221A4(void);
extern int func_0203CD98(void);
extern void func_0203A5E4(u32);
extern void func_02027858(struct TaskMenu *);
extern void func_02028148(u8 *);
extern void func_02051C6C(void *);
extern u32 func_020307B0(void *p);
extern void func_0201ED04(struct WordSet *);
extern void func_021BAC08(int);
extern void func_02030EAC(struct Node *);
extern void func_0204B1CC(struct Bank *);
extern void func_0204A5AC(void);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
enum Offset { Words=0x28c };
enum Zero { Clear=0 };
enum PrintOffset { PrintBase=0xcb4 };
static inline struct PrintSys *printSys(u8 *p) { enum PrintOffset t=PrintBase; t+=4; return *(struct PrintSys **)(p+t); }
static inline struct Node *node(u8 *p,enum Offset off) { return *(struct Node **)(p+(off+0x80)); }
static inline void clearNode(u8 *p,enum Offset off,enum Zero zero) { *(int *)(p+(off+0x80))=zero; *(int *)(p+(off+0x84))=zero; }
int func_021BB584(struct S020315D4 *a,int b,int c,u8 *p)
{
    u16 off;
    long zero;
    if(!func_020221A4()) return 0;
    if(func_0203CD98()) func_0203A5E4(0xc00);
    if(*(struct TaskMenu * *)&((struct Obj02805 *)p)->fCC0) func_02027858(*(struct TaskMenu * *)&((struct Obj02805 *)p)->fCC0);
    if(*(u8 * *)&((struct Obj02805 *)p)->fCE0) func_02028148(*(u8 * *)&((struct Obj02805 *)p)->fCE0);
    if(*(u8 * *)&((struct Obj02805 *)p)->fCE4) func_02028148(*(u8 * *)&((struct Obj02805 *)p)->fCE4);
    if(((struct Obj02805 *)p)->fCA4) func_02051C6C(((struct Obj02805 *)p)->fCA4);
    func_020307B0(((struct Obj02805 *)p)->fCB4);
    off=Words;
    zero=Clear;
    *(int *)&((struct Obj02805 *)p)->fCA4=zero;
    func_0201ED04(*(struct WordSet **)(p+off));
    func_021BAC08((int)p);
    func_02030EAC(*(struct Node **)(p+(off+0x24)));
    func_0204B1CC(*(struct Bank **)(p+(off+0x28)));
    func_0204A5AC();
    func_0201C6EC(printSys(p));
    func_0201C4C0(printSys(p));
    if(node(p,off)) {
        func_02030EAC(node(p,off));
        clearNode(p,off,zero);
    }
    func_020315D4(a);
    func_020306F0(31);
    return 1;
}
