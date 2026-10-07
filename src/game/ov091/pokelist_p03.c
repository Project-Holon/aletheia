/*
 * file:     pokelist_p03.c
 * unit:     yes
 * function: func_021B6F28, func_021B6FEC
 * address:  0x021B6F28
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_02046440  0x02046440  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021BEAB8     0x021BEAB8  data  a4
 *   d_021BEAD0     0x021BEAD0  data  a4
 *   d_021BEAC4     0x021BEAC4  data  a4
 *   func_02061C30  0x02061C30  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021B7034  0x021B7034  thumb
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
#include "../../matched/include/Obj07728.h"

struct Light;
typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0207D4B0(int, int, int);
extern void func_02046440(int, int, int, int, int, int, int);
extern int func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_02050B80(u32 heap);
extern void func_02061C30(void);
extern void func_0204A5AC(void);
extern void func_021B7034(int);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021B6F28(char *p);
void func_021B6FEC(int a);
extern char d_021BEAB8[];
extern char d_021BEAD0[];
extern char d_021BEAC4[];


void func_021B6F28(char *p)
{
    int r;

    func_0207D4B0(1, 0, 1);
    func_02046440(0, 1, 0, 1, 0, ((struct Obj07728 *)p)->f0, 0);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    r = func_02048A24(2, 0, 0x50D7, 0, 0x6BCA, 0x1000, 0x80000, 0, d_021BEAB8, d_021BEAD0, d_021BEAC4, ((struct Obj07728 *)p)->f0);
    ((struct Obj07728 *)p)->f258 = r;
    func_02048AD0((struct Light *)r);
    func_0207D63C(0x04000050, 4, 0x1e, 0x10, 10);
    func_02050B80(((struct Obj07728 *)p)->f0);
}


/*
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void func_02061B5C(void *); extern char d_02146B80[];
 *   void func_02061C30(void) { func_02061B5C(d_02146B80); }
 *   (`return func_02061B5C((int)d_02146B80)` with int types: same DIFF)
 */
void func_021B6FEC(int a)
{
    func_02061C30();
    func_0204A5AC();
    func_021B7034(a);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020450C8();
    func_0203F9B4();
}
