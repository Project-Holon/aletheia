/*
 * function: func_021F1574
 * address:  0x021F1574
 * packet:   pkt_ov029_021F1574
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the two tables are `const`: non-const, the copy of p lands after the first
 *           stack-argument store (4 bytes out). The loop needs i = 0 hoisted first, the
 *           base hoisted and q = p + i*4 with q[0x6e].
 * symbols:
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049F78  0x02049F78  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_RestartWithTimeout  0x0203D88C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_021F31C8     0x021F31C8  data  a4
 *   d_021F33CC     0x021F33CC  data  a4
 */
#include "../include/Obj02749.h"
#include "../include/Obj20392.h"

typedef signed int     s32;
typedef unsigned short u16;
extern s32 func_0204ABF0(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void *func_02049F78(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
extern void GFL_NET_RestartWithTimeout(u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern const int d_021F31C8[];
extern const int d_021F33CC[];

void func_021F1574(char *p, int idx)
{
    int i;
    int r;
    char *loc;
    int *base;
    int *q;

    i = 0;
    ((struct Obj02749 *)p)->f28 = func_0204ABF0((void *)(((struct Obj02749 *)p)->f24), d_021F31C8[idx], 1, 0, 0x70);
    ((struct Obj02749 *)p)->f2C = func_0204A6C8((void *)(((struct Obj02749 *)p)->f24), 0x16, 0, 1, 0x70);
    ((struct Obj02749 *)p)->f30 = func_0204AF28((void *)(((struct Obj02749 *)p)->f24), 0x15, 0x14, ((struct Obj02749 *)p)->fC);
    r = (int)func_02049F78((void *)(((struct Obj02749 *)p)->f24), 0x18, (unsigned int)(&loc), ((struct Obj02749 *)p)->fC);
    base = *(int * *)&((struct Obj20392 *)loc)->fC;
    for (; i < 17; i++) {
        q = (int *)(p + i * 4);
        q[0x6e] = base[d_021F33CC[i]];
    }
    func_020307B0((void *)r);
    GFL_NET_RestartWithTimeout(0xda, 0xe);
    func_0203D34C(0, ((struct Obj02749 *)p)->fC);
}
