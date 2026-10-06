/*
 * function: func_021C940C
 * address: 0x021C940C
 * packet: pkt_ov212_021C940C
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj08418.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap) {
    return func_0204B294((void *)bank,*(const u32 *)&((struct Obj08418 *)t)->f8,*(const u32 *)&((struct Obj08418 *)t)->fC,*(const u32 *)&((struct Obj08418 *)t)->f10,t,*(const u16 *)&((struct Obj08418 *)t)->f16,heap);
}
