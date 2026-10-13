/*
 * function: func_021E7710, func_021E7774
 * address: 0x021E7710
 * packet: pkt_ov177_021E7710
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * volatile: 0x021E7718 writes hardware 0x04000050
 * symbols:
 *   func_021E7CD0 0x021E7CD0 thumb ov177
 *   func_021E7C14 0x021E7C14 thumb ov177
 *   func_021E7B44 0x021E7B44 thumb ov177
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   func_02040618 0x02040618 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021E7AE0 0x021E7AE0 thumb ov177
 */
#include "../include/Obj14374.h"
extern void func_021E7CD0(void *);
typedef unsigned int   u32;
struct Obj;
extern void func_021E7C14(char *p);
extern void func_021E7B44(void *);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern int func_021E7AE0(unsigned char *p, void *mgr);
void func_021E7710(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    switch (((struct Obj14374 *)p)->f98) {
    case 0: case 1: break;
    case 2: case 3: func_021E7CD0(p); break;
    }
    func_021E7C14(p);
    func_021E7B44(p);
    PMS_DRAW_Delete(((struct Obj14374 *)p)->f7C);
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_020307B0(p);
}
int func_021E7774(void *p, void *mgr)
{
    return func_021E7AE0(p, mgr);
}
