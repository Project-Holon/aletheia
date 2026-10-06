/*
 * function: func_021BADB8
 * address: 0x021BADB8
 * packet: pkt_ov070_021BADB8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021B61F4 0x021B61F4 thumb ov070
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj06177.h"
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
typedef unsigned char  u8;
extern void func_021B61F4(u8 *p, int a, unsigned int b);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021BADB8(char *p, unsigned v) { func_02045CAC((struct MsgBank *)(((struct Obj06177 *)p)->f51C), 0x2B, (void *)(*(int *)&((struct Obj06177 *)p)->f524)); func_021B61F4((u8 *)p, 0, v); func_0201F250(((struct Obj06177 *)p)->f520, ((struct Obj06177 *)p)->f528, ((struct Obj06177 *)p)->f524); }
