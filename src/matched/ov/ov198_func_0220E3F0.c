/*
 * function: func_0220E3F0
 * address: 0x0220E3F0
 * packet: pkt_ov198_0220E3F0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00172.h"
#include "../include/Obj25198.h"
#include "../include/Obj25199.h"
#include "../include/Obj25200.h"
#include "../include/Obj25201.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *, unsigned, unsigned, unsigned, u16);
extern int func_0204ABF0(void *, unsigned, unsigned, unsigned, u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_0220E3F0(char *p)
{
    void *owner;
    owner = func_020490F4(83,(u16)((((struct Obj25198 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f24BC = func_0204A6C8(owner, 12, 0, 1, ((struct Obj25199 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2510 = func_0204ABF0(owner, 11, 1, 96, ((struct Obj25200 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2528 = func_0204AF28(owner, 13, 16, ((struct Obj25201 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}
