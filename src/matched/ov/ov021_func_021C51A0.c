/*
 * function: func_021C51A0
 * address:  0x021C51A0
 * packet:   pkt_ov021_021C51A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_021C5424  0x021C5424  thumb  ov021
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00020.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern int func_021C5424(u32 a, u32 b);
struct Bank;
struct Obj;
struct PrintSys;
struct Rec;
extern void func_0204B3B4(struct Obj *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern u32 func_020307B0(void *p);

void func_021C51A0(int *a)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    func_021C5424((int)a, a[0x7c / 4]);
    for (i = 0; i < 3; i++) {
        func_0204B3B4((struct Obj *)a[0x58 / 4 + i]);
    }
    func_0201C6EC((struct PrintSys *)a[0x6c / 4]);
    func_0201C4C0((struct PrintSys *)a[0x6c / 4]);
    func_0201D83C((void *)a[0x68 / 4]);
    func_02045C04((struct Rec *)a[0x64 / 4]);
    func_0204ADA4(((struct Obj00020 *)a)->f50);
    func_0204A8D4(((struct Obj00020 *)a)->f52);
    func_0204AFD8(((struct Obj00020 *)a)->f54);
    func_0204B1CC((struct Bank *)a[0x4c / 4]);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0((void *)((int)a));
}
