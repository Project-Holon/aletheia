/*
 * file:     wifibattlematch_view_p01.c
 * unit:     yes
 * function: func_021E5440, func_021E54E0, func_021E5534, func_021E5548, func_021E5554
 * address:  0x021E5440
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021E5568 0x021E5568 thumb ov177
 *   func_021E560C 0x021E560C thumb ov177
 *   func_020056A0 0x020056A0 thumb
 *   d_021E8DA0 0x021E8DA0 data a1
 *   d_021E8B2C 0x021E8B2C data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021E564C 0x021E564C thumb ov177
 *   func_021E55C8 0x021E55C8 thumb ov177
 *   func_020307B0 0x020307B0 arm
 *   func_021E5668  0x021E5668  thumb  ov177
 *   func_021E5600  0x021E5600  thumb  ov177
 *   func_021E5678   0x021E5678  thumb ov177
 *   func_021E5604  0x021E5604  thumb  ov177
 *   func_021E5670  0x021E5670  thumb  ov177
 */
#include "../../matched/include/Obj24443.h"

struct DispVram;
struct Node;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021E5568(void *, int);
extern void func_021E560C(int *, int, int);
extern int func_020056A0(void (*)(int, int *), int *, int);
extern void func_02030EAC(struct Node *n);
extern void func_021E564C(int *);
extern void func_021E55C8(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021E5668(void *p);
extern void func_021E5600(void *p);
extern int func_021E5678(int *);
extern void func_021E5604(int *);
extern void func_021E5670(int *);
int *func_021E5440(unsigned swap, int heap);
void func_021E54E0(char *p);
void func_021E5534(u8 *p);
int func_021E5548(int *p);
void func_021E5554(int a, int *p);
extern const char d_021E8DA0[];
extern const unsigned d_021E8B2C[];

int *func_021E5440(unsigned swap, int heap)
{
    int *p = func_02030734(heap, 16, 0, d_021E8DA0, 0x1BB);
    func_02082BCC(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021E8B2C);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021E5568(p, heap);
    func_021E560C(p + 1, (int)d_021E8B2C, heap);
    p[3] = func_020056A0(func_021E5554, p, 0);
    return p;
}

/*
 * volatile: display registers 04000050/04001050 cleared; DISPCNT 04000000/04001000 read-modify-write at 021E5506-021E5514.
 */
void func_021E54E0(char *p)
{
    func_02030EAC(((struct Obj24443 *)p)->fC);
    func_021E564C((int *)(p + 4));
    func_021E55C8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}


void func_021E5534(u8 *p)
{
    func_021E5668(p + 4);
    func_021E5600(p);
}


/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E5678 with
 * its pointer argument advanced by one word.  Matched to supply the `matched`
 * witness for the pending ov176 caller func_0217AF2C.
 */
int func_021E5548(int *p)
{
    return func_021E5678(p + 1);
}


void func_021E5554(int a, int *p)
{
    func_021E5604(p);
    func_021E5670((int *)((char *)p + 4));
}
