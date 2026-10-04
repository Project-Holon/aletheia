/*
 * function: func_0220E518
 * address: 0x0220E518
 * packet: pkt_ov198_0220E518
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
#include "../include/Obj25208.h"
#include "../include/Obj25209.h"
#include "../include/Obj25210.h"
#include "../include/Obj25211.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204A6C8(void *, unsigned, unsigned, unsigned, u16);
extern int func_0204ABF0(void *, unsigned, unsigned, unsigned, u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_0220E518(char *p)
{
    void *owner;
    owner = func_020490F4(83,(((struct Obj25208 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000);
    ((struct Obj00172 *)p)->f24C0 = func_0204A6C8(owner, 65, 0, 1, ((struct Obj25209 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2514 = func_0204ABF0(owner, 66, 1, 128, ((struct Obj25210 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f252C = func_0204AF28(owner, 67, 70, ((struct Obj25211 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}
