/*
 * file:     shinka_demo_view_p01.c
 * unit:     yes
 * function: func_022058F8, func_022059A0, func_022059FC, func_02205A10, func_02205A1C, func_02205A28
 * address:  0x022058F8
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02208F50 0x02208F50 data a4
 *   d_02208CEC 0x02208CEC data a4
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_02205AC0 0x02205AC0 thumb ov195
 *   func_02205B6C 0x02205B6C thumb ov195
 *   func_02205BDC 0x02205BDC thumb ov195
 *   func_02205AAC 0x02205AAC thumb ov195
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02205C48 0x02205C48 thumb ov195
 *   func_02205BAC 0x02205BAC thumb ov195
 *   func_02205B24 0x02205B24 thumb ov195
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02205BC8 0x02205BC8 thumb
 *   func_02205B60 0x02205B60 thumb
 *   func_02205C58 0x02205C58 thumb ov195
 *   func_02205C6C 0x02205C6C thumb ov195
 *   func_02205BD8 0x02205BD8 thumb ov195
 */
#include "../../matched/include/Obj24951.h"
#include "../../matched/include/Obj24952.h"

struct DispVram;
struct Node;
typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, int, int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_02205AC0(void *a, void *b);
extern void func_02205B6C(unsigned char *p, int a, u32 b);
extern void func_02205BDC(u32 *a, void *b);
extern void func_02205AAC(int a, char *b);
extern u32 func_020056A0(void *, void *, int);
extern void func_02030EAC(struct Node *n);
extern void func_02205C48(int *);
extern void func_02205BAC(char *);
extern void func_02205B24(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_02205BC8(void *);
extern void func_02205B60(void *);
extern void func_02205C58(char *a);
extern void func_02205C6C(void *);
extern int func_02205BD8(int *p);
char *func_022058F8(u32 a, u32 b);
void func_022059A0(char *p);
void func_022059FC(char *a);
void func_02205A10(char *a);
void func_02205A1C(char *a);
int func_02205A28(char *a);
extern u32 d_02208F50[];
extern u32 d_02208CEC[];


char *func_022058F8(u32 a, u32 b)
{
    char *p = func_02030734(b, 0x10, 0, (const char *)d_02208F50, 0x1df);

    func_02082BCC(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_02208CEC);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_02205AC0(p, (void *)b);
    func_02205B6C((unsigned char *)(p + 4), (int)d_02208CEC, b);
    func_02205BDC((u32 *)(p + 8), (void *)b);
    ((struct Obj24951 *)p)->fC = func_020056A0(func_02205AAC, p, 0);
    return p;
}

/*
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write at 022059C2-022059DC.
 */
void func_022059A0(char *p)
{
    func_02030EAC(((struct Obj24952 *)p)->fC);
    func_02205C48((int *)(p + 8));
    func_02205BAC(p + 4);
    func_02205B24(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}


void func_022059FC(char *a)
{
    func_02205BC8(a + 4);
    func_02205B60(a);
}


void func_02205A10(char *a)
{
    func_02205C58(a + 8);
}


void func_02205A1C(char *a)
{
    func_02205C6C(a + 8);
}


int func_02205A28(char *a)
{
    return func_02205BD8((int *)(a + 4));
}
