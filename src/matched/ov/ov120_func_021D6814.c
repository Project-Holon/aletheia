/*
 * function: func_021D6814
 * address: 0x021D6814
 * packet: pkt_ov120_021D6814
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D68C2.
 * symbols:
 *   func_021D6810 0x021D6810 thumb ov120
 *   func_021D6AF0 0x021D6AF0 thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj06436.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D6810(u8 *, int);
extern void func_021D6AF0(u8 *, u16, u16, int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
void func_021D6814(u8 *p)
{
    void *t;
    func_021D6810(p, 0);
    t = func_020490F4(144, ((struct Obj06436 *)p)->fF4);
    func_02049990(t, 19, 4, 0, (u16)(((struct Obj06436 *)p)->f0), 0, 0, ((struct Obj06436 *)p)->fF4);
    func_02049990(t, 20, 4, 0, (u16)(((struct Obj06436 *)p)->f0), 192, 0, ((struct Obj06436 *)p)->fF4);
    func_02049238(t);
    func_021D6AF0(p, 96, 56, 0);
    func_021D6AF0(p, 240, 56, 1);
    func_021D6AF0(p, 120, 96, 0);
    func_021D6AF0(p, 240, 96, 1);
    func_021D6AF0(p, 120, 136, 0);
    func_021D6AF0(p, 240, 136, 1);
}
