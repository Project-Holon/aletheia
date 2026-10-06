/*
 * function: func_0220E460
 * address: 0x0220E460
 * packet: pkt_ov198_0220E460
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
 *   func_020275F8 0x020275F8 thumb
 *   func_02027610 0x02027610 thumb
 */
#include "../include/Obj00172.h"
#include "../include/Obj25202.h"
#include "../include/Obj25203.h"
#include "../include/Obj25204.h"
#include "../include/Obj25205.h"
#include "../include/Obj25206.h"
#include "../include/Obj25207.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *, unsigned, unsigned, unsigned, u16);
extern int func_0204ABF0(void *, unsigned, unsigned, unsigned, u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_020275F8(unsigned);
extern unsigned func_02027610(unsigned);
void func_0220E460(char *p)
{
    void *owner;
    unsigned i;
    owner = func_020490F4(83,(u16)((((struct Obj25202 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f2518 = func_0204ABF0(owner, 33, 1, 160, ((struct Obj25203 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2530 = func_0204AF28(owner, 59, 62, ((struct Obj25204 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    for (i = 8; i <= 21; i++)
        ((int *)(p + 0x24a4))[i] = func_0204A6C8(owner, func_020275F8(0), 0, 1, ((struct Obj25205 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f24FC = func_0204A6C8(owner, func_02027610(0), 0, 1, ((struct Obj25206 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2500 = func_0204A6C8(owner, func_02027610(0), 0, 1, ((struct Obj25207 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}
