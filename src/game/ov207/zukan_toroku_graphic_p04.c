/*
 * file:     zukan_toroku_graphic_p04.c
 * unit:     yes
 * function: func_0220B4E0, func_0220B4E4, func_0220B4EC, func_0220B52C, func_0220B548, func_0220B550
 * address:  0x0220B4E0
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../../matched/include/Obj14642.h"

struct Cfg;
struct Bank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_020419E4(void);
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
void func_0220B4E0(void*p);
void func_0220B4E4(void*p);
void func_0220B4EC(unsigned char *p, int a, int b);
void func_0220B52C(struct Bank**p);
void func_0220B548(void*p);
void func_0220B550(void*p);
u32 func_0220B558(u32*p);

void func_0220B4E0(void*p){}

void func_0220B4E4(void*p){func_020419E4();}


void func_0220B4EC(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x0220BACC, a, b);
    ((struct Obj14642 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14642 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

void func_0220B52C(struct Bank**p){func_0204B1CC(*p);func_0204A5AC();func_02082BCC(p,0,4);}

void func_0220B548(void*p){func_0204A600();}

void func_0220B550(void*p){func_0204A648();}

u32 func_0220B558(u32*p){return *p;}
