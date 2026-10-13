/*
 * function: func_021FB1C0
 * address: 0x021FB1C0
 * packet: pkt_ov132_021FB1C0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj23250.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
int func_021FB1C0(void *unused,char *p) { VM_GetU32(*(struct Cursor * *)&((struct Obj23250 *)p)->f4); return 0; }
