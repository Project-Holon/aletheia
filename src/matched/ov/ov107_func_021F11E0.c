/*
 * unit: yes
 * function: func_021F11E0, func_021F11E8
 * address: 0x021F11E0
 * packet: pkt_ov107_021F11E0
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj22298.h"
#include "../include/Obj22299.h"
typedef unsigned short u16;
struct Bits { unsigned char pad[24]; u16 unused:2; u16 flag:1; u16 rest:13; };
int func_021F11E0(unsigned char *a) { return ((struct Obj22299 *)(*(unsigned char * *)&((struct Obj22298 *)a)->f10))->f2; }
int func_021F11E8(struct Bits *a) { return a->flag; }
