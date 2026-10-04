/*
 * function: func_021C8354
 * address: 0x021C8354
 * packet: pkt_ov128_021C8354
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 */
#include "../include/Obj23081.h"
#include "../include/Obj23082.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_02041EE4(u32,u32,u32);
extern void func_021CA4B4(char *);
int func_021C8354(u8 *p,u8 *q) {if(func_0201C6B4(*(const struct PrintSys * *)&((struct Obj23082 *)q)->f34)==1) {func_02041EE4(2,0,0);func_02041EE4(3,0,0);func_021CA4B4(**(char ** *)&((struct Obj23081 *)p)->f14);return 1;}return 0;}
