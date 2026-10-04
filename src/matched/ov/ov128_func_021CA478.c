/*
 * function: func_021CA478
 * address: 0x021CA478
 * packet: pkt_ov128_021CA478
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj06477.h"
#include "../include/Obj08135.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
void func_021CA478(char *p) {u32 i;char *q;void *v;for(i=0;i<64;i++){q=*(char **)(p+i*4+56);if(!q)break;v=((struct Obj06477 *)p)->f34;if(((struct Obj08135 *)q)->f4) {if(!func_0201C6C4(v,func_02045770(((struct Obj08135 *)q)->f0))) {func_02045334(((struct Obj08135 *)q)->f0);((struct Obj08135 *)q)->f4=0;}}}}
