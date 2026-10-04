/*
 * function: func_021B83E0
 * address: 0x021B83E0
 * packet: pkt_ov102_021B83E0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B62FC 0x021B62FC thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_021B7F08 0x021B7F08 thumb ov102
 *   func_021B82DC 0x021B82DC thumb ov102
 *   func_021B81B0 0x021B81B0 thumb ov102
 */
#include "../include/Obj07977.h"
#include "../include/Obj22159.h"
#include "../include/Obj22160.h"
#include "../include/Obj22161.h"
#include "../include/Obj22162.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B6480(int *);
extern int func_021B62FC(int *);
extern void func_021B63CC(int *, int);
extern void func_021B7F08(unsigned p, unsigned x);
extern void func_021B82DC(u8 *, u16 *);
extern void func_021B81B0(u8 *, u16 *);
void func_021B83E0(u8 *p)
{
    func_021B6480(*(int * *)&((struct Obj22159 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4);
    if (func_021B62FC(*(int * *)&((struct Obj22160 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4)) {
        func_021B63CC(*(int * *)&((struct Obj22161 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4, 1);
        ((struct Obj22162 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->fC = 0;
        func_021B7F08((unsigned int)p, (unsigned int)func_021B82DC);
    } else {
        func_021B7F08((unsigned int)p, (unsigned int)func_021B81B0);
    }
}
