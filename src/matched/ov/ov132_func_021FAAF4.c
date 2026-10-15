/*
 * function: func_021FAAF4
 * address: 0x021FAAF4
 * packet: pkt_ov132_021FAAF4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   NNS_FndInitList 0x02060468 arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 */
#include "../include/Obj05398.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern char d_021FDCEC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_02030CB0(u32);
struct Ctx;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void NNS_FndInitList(int p0, int p1);
void *func_021FAAF4(u32 heap, void *owner)
{
    u8 i;
    char *p;
    i = 0;
    p = func_02030734(heap, 0x44, 0, d_021FDCEC, 0x3f);
    ((struct Obj05398 *)p)->f0 = heap;
    ((struct Obj05398 *)p)->f34 = owner;
    ((struct Obj05398 *)p)->f8 = func_02030734(((struct Obj05398 *)p)->f0, func_02030CB0(16), 0, d_021FDCEC, 0x43);
    ((struct Obj05398 *)p)->f4 = func_02030CBC(16, ((struct Obj05398 *)p)->f8);
    NNS_FndInitList((int)(p + 0x38), 0);
    for (; i < 10; i++) *(void **)(p + 0xc + i * 4) = 0;
    return p;
}
