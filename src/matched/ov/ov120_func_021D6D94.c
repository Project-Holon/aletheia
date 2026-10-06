/*
 * function: func_021D6D94
 * address: 0x021D6D94
 * packet: pkt_ov120_021D6D94
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049990 0x02049990 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 *   func_021D6C64 0x021D6C64 thumb ov120
 *   func_021D6FB4 0x021D6FB4 thumb ov120
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02041B6C(u32);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02049238(void *);
extern void func_021D6C64(u8 *);
extern void func_021D6FB4(u8 *);
void func_021D6D94(u8 *p)
{
    void *t = func_020490F4(144, ((struct Obj00199 *)p)->fF4);
    func_021D6C64(p);
    func_021D6FB4(p);
    func_02041300(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    func_02049BDC(t, 2, 5, 0, 256, 256, ((struct Obj00199 *)p)->fF4);
    func_02049990(t, 18, 4, 0, (u16)(((struct Obj00199 *)p)->f0), 0, 0, ((struct Obj00199 *)p)->fF4);
    func_02041B6C(4);
    func_02049238(t);
}
