/*
 * unit: yes
 * function: func_021FD938, func_021FD948, func_021FD954, func_021FD95C
 * The larger indexed follower at 021FD964 is parked separately at DIFF.
 * address: 0x021FD938
 * packet: pkt_ov132_021FD938
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCDEC 0x021FCDEC thumb ov132
 */
#include "../include/Obj14143.h"
#include "../include/Obj23302.h"
#include "../include/Obj23303.h"
#include "../include/Obj23304.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FCDEC(int,int);
void func_021FD938(char *p) {func_021FCDEC((int)p,0x42);((struct Obj23302 *)p)->f4C=12;}
void func_021FD948(char *p,u32 value){((struct Obj14143 *)p)->f4C=18;((struct Obj14143 *)p)->f120=value;}
u32 func_021FD954(char *p){return ((struct Obj23303 *)p)->f144;}
u32 func_021FD95C(char *p){return ((struct Obj23304 *)p)->f148;}
