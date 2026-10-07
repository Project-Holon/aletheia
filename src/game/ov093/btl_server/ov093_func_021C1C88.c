/*
 * function: func_021C1C88
 * address:  0x021C1C88
 * packet:   pkt_ov093_021C1C88
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
#include "../../../matched/include/Obj21079.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);

void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v)
{
    func_021D74F8(7009);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, v);
    func_021D75EC(0x12, ((struct Obj21079 *)q)->f0);
    func_021D70F0(p, 0x88);
    func_021D7540(7014);
}
