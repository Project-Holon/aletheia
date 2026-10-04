/*
 * function: func_021F19C8
 * address: 0x021F19C8
 * packet: pkt_ov107_021F19C8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 */
#include "../include/Obj13766.h"
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
int func_021F19C8(unsigned char *a) { if(func_020279E8(((struct Obj13766 *)a)->f3C)==1) return func_02027A04(((struct Obj13766 *)a)->f3C)+1; return 0; }
