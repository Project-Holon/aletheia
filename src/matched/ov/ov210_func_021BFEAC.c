/*
 * function: func_021BFEAC
 * address: 0x021BFEAC
 * packet: pkt_ov210_021BFEAC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_02025CD0 0x02025CD0 thumb
 *   func_021BFF30 0x021BFF30 thumb ov210
 *   func_02025D1C 0x02025D1C thumb
 *   d_021C0B60 0x021C0B60 data a4
 *   d_021C0B14 0x021C0B14 data a4
 */
#include "../include/Obj10923.h"
extern const unsigned d_021C0B60[], d_021C0B14[];
extern unsigned char func_020355C4(void);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
struct Struct_02025D1C;
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_021BFF30(int, unsigned, unsigned);
extern void func_02025D1C(struct Struct_02025D1C *obj);
void func_021BFEAC(char *ctx, int index)
{
    if (func_020355C4() == 1) {
        ((struct Obj10923 *)ctx)->f2B0 = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 0, index, 123);
    } else {
        ((struct Obj10923 *)ctx)->f2B0 = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 1, index, 123);
        func_021BFF30((int)ctx, index, 3);
    }
    func_02025D1C(((struct Obj10923 *)ctx)->f2B0);
}
