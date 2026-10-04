/*
 * function: func_021DE060
 * address: 0x021DE060
 * packet: pkt_ov137_021DE060
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021DD924 0x021DD924 thumb ov137
 */
#include "../include/Obj23727.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021DD924(char *);
int func_021DE060(char *p) {func_0202208C(0,0,0,0,16,1,114);((struct Obj23727 *)p)->f8=1;func_021DD924(p);return 3;}
