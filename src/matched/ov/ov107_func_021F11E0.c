/*
 * unit: yes
 * function: MB_COMM_SYS_GetMaxSeen, MB_COMM_SYS_HasKind0
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
int MB_COMM_SYS_GetMaxSeen(unsigned char *a) { return ((struct Obj22299 *)(*(unsigned char * *)&((struct Obj22298 *)a)->f10))->f2; }
int MB_COMM_SYS_HasKind0(struct Bits *a) { return a->flag; }
