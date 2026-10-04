/*
 * function: func_021C7CE8
 * address: 0x021C7CE8
 * packet: pkt_ov208_021C7CE8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: func_02014CEC witness filed as src/matched/arm9/func_02014CEC.c (2026-10-02), shard pending from the integrator; EXACT after that
 *   typedef unsigned int u32;
 *   void func_02014CEC(char *p, u32 value) { *(u32 *)(p + 8) = value; }
 * symbols:
 *   func_021C51A0 0x021C51A0 thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_02014CEC 0x02014CEC thumb
 */
#include "../include/Obj00147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C51A0(u8 *, u32);
extern void func_021C51C8(u32, int, u8 *);
extern void ov208_func_021C569C(u16 *, u8 *, int, int, int, int, u16);
extern void func_02014CEC(u8 *p, u32 value);
void func_021C7CE8(u16 *a0, u8 *p, int key)
{
    int a;
    int b;
    if (((struct Obj00147 *)p)->f6B8 != 0) return;
    func_021C51A0(p + 0x94, ((struct Obj00147 *)p)->f8);
    func_021C51A0(p + 0xD8, ((struct Obj00147 *)p)->f8);
    func_02014CEC((u8 *)(((struct Obj00147 *)p)->f8), 0);
    a = ((struct Obj00147 *)p)->f124 != 0 ? 2 : 4;
    b = ((struct Obj00147 *)p)->f124 != 0 ? 4 : 3;
    ov208_func_021C569C(a0, p, key, a, b, 2, ((struct Obj00147 *)p)->f550);
    if (a != 4) func_021C51C8(((struct Obj00147 *)p)->f98, 2, p);
    if (b != 4) func_021C51C8(((struct Obj00147 *)p)->fDC, 3, p);
    func_02014CEC((u8 *)(((struct Obj00147 *)p)->f8), ((struct Obj00147 *)p)->f120);
}
