/*
 * function: func_021B9F24
 * address: 0x021B9F24
 * packet: pkt_ov069_021B9F24
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   func_021B9FC8 0x021B9FC8 thumb ov069
 *   d_021BA71C 0x021BA71C data a4
 *   d_021BA5EC 0x021BA5EC data a4
 */
#include "../include/Obj09876.h"
extern const char d_021BA71C[], d_021BA5EC[];
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_021B9FC8(char *p, int i);
void func_021B9F24(char *p)
{
    ((struct Obj09876 *)p)->f14C = func_02025CD0((u32)d_021BA71C, (u32)d_021BA5EC, (u32)p, 1, 0, 0x80);
    func_021B9FC8(p, 0);
}
