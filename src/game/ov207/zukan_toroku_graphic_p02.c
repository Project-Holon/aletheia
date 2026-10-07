/*
 * file:     zukan_toroku_graphic_p02.c
 * unit:     yes
 * function: func_0220B2F8, func_0220B318, func_0220B3B8, func_0220B40C, func_0220B420
 * address:  0x0220B2F8
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
 *   func_02040588 0x02040588 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_0220B448 0x0220B448 thumb ov207
 *   func_0220B4EC 0x0220B4EC thumb ov207
 *   func_0220B434 0x0220B434 thumb ov207
 *   d_0220BC20 0x0220BC20 data a1
 *   d_0220BAE8 0x0220BAE8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0220B52C 0x0220B52C thumb ov207
 *   func_0220B4A8 0x0220B4A8 thumb ov207
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0220B548 0x0220B548 thumb ov207
 *   func_0220B4E0 0x0220B4E0 thumb ov207
 */
#include "../../matched/include/Obj14641.h"

struct DispVram;
struct Node;
struct Bank;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_0220B448(void *,int);
extern void func_0220B4EC(unsigned char *p, int a, int b);
extern void func_0220B434(void *unused, u8 *p);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_0220B52C(struct Bank **p);
extern void func_0220B4A8(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0220B548(void*),func_0220B4E0(void*);
void func_0220B2F8(int unused, char *p);
void *func_0220B318(int a,int heap);
void func_0220B3B8(unsigned *p);
void func_0220B40C(u8*p);
void func_0220B420(void *a0);
extern char d_0220BC20[];
extern unsigned d_0220BAE8[];


void func_0220B2F8(int unused, char *p)
{
    if (((struct Obj14641 *)p)->f2C != 0)
    {
        func_02040588(0, 0);
        func_02040588(2, 0);
        ((struct Obj14641 *)p)->f2C = 0;
    }
}

/*
 * volatile: hardware accesses 0x0220B33E-0x0220B352.
 */
void *func_0220B318(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_0220BC20,455);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_0220BAE8);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_0220B448(p,heap);
    func_0220B4EC((unsigned char *)(p+1),(int)d_0220BAE8,heap);
    p[3]=(unsigned)func_020056A0((void (*)(void *, void *))func_0220B434,p,0);
    return p;
}

/*
 * volatile: hardware accesses at 0x0220B3D6-0x0220B3EC.
 */
void func_0220B3B8(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_0220B52C((struct Bank **)(p+1));
    func_0220B4A8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}

void func_0220B40C(u8*p){func_0220B548(p+4);func_0220B4E0(p);}

void func_0220B420(void *a0){}
