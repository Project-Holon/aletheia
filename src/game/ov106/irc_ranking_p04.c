/*
 * file:     irc_ranking_p04.c
 * unit:     yes
 * function: func_021B7F88, func_021B7FC8, func_021B7FE4, func_021B7FEC, func_021B7FF4, func_021B7FF8, func_021B807C, func_021B80A0
 * address:  0x021B7F88
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B94B8 0x021B94B8 data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021B7D14 0x021B7D14 thumb ov106
 *   func_021B80BC 0x021B80BC thumb ov106
 *   func_020056A0 0x020056A0 thumb
 *   d_021B94F4 0x021B94F4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7F00 0x021B7F00 thumb ov106
 */
#include "../../matched/include/Obj22261.h"

struct Cfg;
struct Bank;
struct DispVram;
struct Node;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);
extern void func_021B7D14(u32 *, void *, u32);
extern void func_021B80BC(void *, u8 *);
extern void *func_020056A0(void (*)(void *, u8 *), void *, int);
extern void func_02030EAC(struct Node *n);
extern void func_021B7F00(u32 *);
void func_021B7F88(void **p, int a, int b);
void func_021B7FC8(void **p);
void func_021B7FE4(void *a0);
void func_021B7FEC(u8 *a0);
void *func_021B7FF4(void **p);
void func_021B7FF8(u8 *p, void *a, u32 b);
void func_021B807C(u8 *p);
void func_021B80A0(u8 *p);
extern char d_021B94B8[];
extern const u8 d_021B94F4[];

void func_021B7F88(void **p, int a, int b) {
    func_02082BCC(p,0,0x14);
    func_0204A48C((const struct Cfg *)d_021B94B8,a,b);
    *p=func_0204B100(128,0,b);
    func_0204B270(*p);
    func_020434DC(16,1);
    func_02043598(16,1);
}

void func_021B7FC8(void **p) { func_0204B1CC(*p); func_0204A5AC(); func_02082BCC(p,0,20); }


/*
 * Tail-call thunk to the ARM function at 0x0204A600.
 */
void func_021B7FE4(void *a0)
{
    func_0204A600();
}

void func_021B7FEC(u8 *a0) { func_0204A648(); }


/*
 * First-word accessor.
 */
void *func_021B7FF4(void **p)
{
    return *p;
}

void func_021B7FF8(u8 *p, void *a, u32 b) {
 func_02082BCC(p,0,0x28);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 func_0204335C(0);
 func_020433E0((const struct DispVram *)d_021B94F4);
 func_0204363C(1);
 func_0204361C();
 func_020434CC();
 func_0201DD60();
 func_021B7D14((u32 *)p,a,b);
 func_021B7F88((void **)(p+0x10),(int)d_021B94F4,b);
 *(void **)(p+0x24)=func_020056A0(func_021B80BC,p,0);
}

void func_021B807C(u8 *p) { func_02030EAC(((struct Obj22261 *)p)->f24); func_021B7FC8((void **)(p+16)); func_021B7F00((u32 *)p); func_02082BCC(p,0,40); }

/*
 * Unblocked by matching func_021B7FE4 in ov106 (pkt_ov106_021B7FE4).
 */
void func_021B80A0(u8 *p) { func_021B7FE4(p + 0x10); }
