/*
 * function: func_021BB61C
 * address: 0x021BB61C
 * packet: pkt_ov110_021BB61C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj03240.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int a,b,c; } Triple;
extern void func_021BAC64(void *,Triple *,int,int);
struct Obj;
extern struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021BB61C(u8 *p) { Triple t; func_021BAC64(((struct Obj03240 *)p)->f0,&t,0,0); ((struct Obj03240 *)p)->f54=func_021BAC78(((struct Obj03240 *)p)->f0,(u32 *)(&t),48,64,3,1); func_0204B878(((struct Obj03240 *)p)->f54,4); func_0204B3DC(((struct Obj03240 *)p)->f54,0); }
