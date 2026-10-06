/*
 * function: func_021BAA88
 * address: 0x021BAA88
 * packet: pkt_ov225_021BAA88
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   sub_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14806.h"
#include "../include/Obj26200.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct PrintSys;
struct TaskMenuState;
extern void func_0201C6EC(struct PrintSys *);
extern void func_02028148(u8 *);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void sub_02041B6C(u32);
void func_021BAA88(char *p) { u8 i; func_0201C6EC(*(struct PrintSys * *)&((struct Obj26200 *)(*(char * *)&((struct Obj14806 *)p)->f4))->f14); for(i=0;i<8;i++) if(*(u8 **)(p+i*4+12)) func_02028148(*(u8 **)(p+i*4+12)); func_02027FD8(*(struct TaskMenuState * *)&((struct Obj14806 *)p)->f8); sub_02041B6C(5); }
