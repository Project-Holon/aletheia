/*
 * function: func_021D6CC4
 * address:  0x021D6CC4
 * packet:   pkt_ov118_021D6CC4
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: own callee 021DFBB4 takes the table as argument four and u16 heap
 * as argument five. Correct order and a word-aligned three-word output
 * buffer settle the saved registers; nonzero 11F0 arms come first. Bare
 * aligned data hints resolve the contested table through sole-ref/data.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006984  0x02006984  thumb
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   d_021D7CDC     0x021D7CDC  data a4
 *   d_021D8470     0x021D8470  data a4
 *   d_021D8880     0x021D8880  data a4
 *   d_021D8398     0x021D8398  data a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01149.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 v[4];
} Quad;

extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void MCSS_GetPosition(void *, u32 *);
extern void func_021DFD24(u32 *);
extern void *func_021DFBB4(void *, void *, void *, void *, u16);
extern const Quad d_021D7CDC;
extern const u32 d_021D8470[];
extern const u32 d_021D8880[];
extern const u32 d_021D8398[];

void func_021D6CC4(void *a0, int a1)
{
    void *x;
    u32 buf[3];

    x = func_021D8FA4(a0, 1 - func_021D8AA8(a0));
    func_02017E1C(x, 7, 0);
    if (func_02017E1C(x, 0x4c, 0) == 0) {
        func_02006984(func_02017E1C(x, 0xab, 0), func_02017E1C(x, 0x6f, 0),
                      0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj01149 *)a0)->f11EE == 0) {
        MCSS_GetPosition((void *)((u32 *)((char *)a0 + 0x844))[a1], buf);
        func_021DFD24(*(u32 * *)&((struct Obj01149 *)a0)->f868);
        if (((struct Obj01149 *)a0)->f11F0 != 0)
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)((u32 *)((char *)a0 + 0x844))[a1], (void *)0x14, buf, (void *)d_021D8880, ((struct Obj01149 *)a0)->f5F4);
        else
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)((u32 *)((char *)a0 + 0x844))[a1], (void *)0x28, buf, (void *)d_021D8470, ((struct Obj01149 *)a0)->f5F4);
        return;
    } else {
        Quad t;
        u32 r6;

        t = d_021D7CDC;
        r6 = ((u32 *)((char *)a0 + 0x844))[t.v[a1]];
        MCSS_GetPosition((void *)((u32 *)((char *)a0 + 0x844))[a1], buf);
        func_021DFD24(*(u32 * *)&((struct Obj01149 *)a0)->f868);
        if (((struct Obj01149 *)a0)->f11F0 != 0)
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)r6, (void *)0x14, buf, (void *)d_021D8880, ((struct Obj01149 *)a0)->f5F4);
        else
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)r6, (void *)0x12, buf, (void *)d_021D8398, ((struct Obj01149 *)a0)->f5F4);
    }
}
