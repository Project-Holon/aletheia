/*
 * file:     weather_task_p01.c
 * unit:     yes
 * function: func_021A1AAC, func_021A1AF4, func_021A1B38
 * address:  0x021A1AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021A1DF8  0x021A1DF8  thumb  ov021
 *   func_021A1C04  0x021A1C04  thumb  ov021
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_021A15D4  0x021A15D4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DDE6C     0x021DDE6C  data  ov021  a4
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   func_021A1E08  0x021A1E08  thumb  ov021
 *   func_021A15F4  0x021A15F4  thumb  ov021
 */
#include "../../matched/include/Obj07491.h"
#include "../../matched/include/Obj09548.h"

struct Bank;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02030EAC(struct Node *n);
extern void func_021A1DF8(u8 *p);
extern void func_021A1C04(u8 *p);
extern void func_0204B084(u32 v);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_021A15D4(u32 a);
extern u32 func_020307B0(void *p);
extern void func_021A1BDC(void *p, u32 v);
extern void func_021A1E08(u32 v, int x);
void func_021A15F4(u32 x);
void func_021A1AAC(u8 *p);
void func_021A1AF4(u8 *p, int x);
void func_021A1B38(u32 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021A1AAC(u8 *p)
{
    int i;

    func_02030EAC((struct Node *)(((struct Obj07491 *)p)->f2C));
    for (i = 0; i < 2; i++) {
        func_021A1DF8((u8 *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    func_021A1C04(p);
    func_0204B084(((struct Obj07491 *)p)->f1C);
    func_0204B1CC((struct Bank *)(((struct Obj07491 *)p)->f18));
    for (i = 0; i < 2; i++) {
        func_021A15D4(((u32 *)p)[i]);
    }
    func_020307B0(p);
}


extern void (*const d_021DDE6C[])(void *p, int x);


void func_021A1AF4(u8 *p, int x)
{
    int i;
    u16 t;

    d_021DDE6C[*(u16 *)(p + 8)](p, x);
    if (((struct Obj09548 *)p)->fA == 0) {
        t = ((struct Obj09548 *)p)->f14;
        if (t != 0xFFFF) {
            func_021A1BDC(p, t);
            ((struct Obj09548 *)p)->f14 = 0xFFFF;
        }
    }
    for (i = 0; i < 2; i++) {
        func_021A1E08(*(u32 *)(p + 0x20 + i * 4), x);
    }
}


void func_021A1B38(u32 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++)
            func_021A15F4(p[i]);
    }
}
