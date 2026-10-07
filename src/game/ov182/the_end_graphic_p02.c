/*
 * file:     the_end_graphic_p02.c
 * unit:     yes
 * function: func_021B9810, func_021B9814, func_021B9840, func_021B98E4, func_021B998C
 * address:  0x021B9810
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020111E8  0x020111E8  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B9C28 0x021B9C28 data a4
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021B9A10 0x021B9A10 thumb ov182
 *   func_021B9AB4 0x021B9AB4 thumb ov182
 *   func_021B9B20 0x021B9B20 thumb ov182
 *   func_020056A0 0x020056A0 thumb
 *   func_021B99FC 0x021B99FC thumb ov182
 *   d_021B9CE0 0x021B9CE0 data a1
 *   d_021B9C48 0x021B9C48 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021B9B8C 0x021B9B8C thumb ov182
 *   func_021B9AF4 0x021B9AF4 thumb ov182
 *   func_021B9A70 0x021B9A70 thumb ov182
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj24514.h"
#include "../../matched/include/Obj24515.h"

struct DispVram;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern u32 func_020111E8(void);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021B9A10(void *, int);
extern void func_021B9AB4(int *, int, int);
extern void func_021B9B20(int *p, u16 heap);
extern void func_021B99FC(int, char *);
extern void *func_020056A0(void (*)(int, char *), void *, int);
extern void func_02030EAC(struct Node *n);
extern void func_021B9B8C(unsigned *);
extern void func_021B9AF4(void *);
extern void func_021B9A70(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
void func_021B9810(void *p);
void func_021B9814(void *a, void *b, void *c);
void func_021B9840(void);
char *func_021B98E4(int a, u16 heap);
void func_021B998C(char *p);
extern const u32 d_021B9C28[][2];
extern const char d_021B9CE0[];
extern const u32 d_021B9C48[];

void func_021B9810(void *p){}


void func_021B9814(void *a, void *b, void *c)
{
    if (func_020111E8() == 0x15)
        func_0204E720(3, (s32)a, (s32)b, (s32)c);
    else
        func_0204E720(0xc, (s32)a, (s32)b, (s32)c);
}

/*
 * volatile: hardware 04000008/04000060 read/write 021B984E-021B988C, 04000580 write 021B98AA.
 */
void func_021B9840(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3002) | 2;
    *(volatile u16 *)0x04000060 &= (u16)~0x3010;
    *(volatile u16 *)0x04000060 &= (u16)~0x3004;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    *(volatile u16 *)0x04000060 &= (u16)~0x3020;
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7fff, 0x3f, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        func_02046A94((u8)i, (const u16 *)d_021B9C28[i]);
    func_02046BE0(0, 0);
}

char *func_021B98E4(int a, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x10, 0, d_021B9CE0, 0x1cc);
    func_02082BCC(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021B9C48);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021B9A10(p, heap);
    func_021B9AB4((int *)(p + 4), (int)d_021B9C48, heap);
    func_021B9B20((int *)(p + 8), heap);
    ((struct Obj24514 *)p)->fC = func_020056A0(func_021B99FC, p, 0);
    return p;
}

/*
 * volatile: Hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 read/write at 0x021B99B2..0x021B99C8.
 */
void func_021B998C(char *p)
{
    func_02030EAC(((struct Obj24515 *)p)->fC);
    func_021B9B8C((unsigned *)(p + 8));
    func_021B9AF4(p + 4);
    func_021B9A70(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}
