/*
 * function: func_021D9E60
 * address: 0x021D9E60
 * packet: pkt_ov129_021D9E60
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Load actor into a local before the current-index store.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj14058.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { s16 x,y; } Pair;
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021D9E60(u8 *p,int n) { Pair s; void *actor; actor=*(void **)(p+n*28+12); ((struct Obj14058 *)p)->f188=n; func_0204B454(actor,(struct PtS *)&s,0); s.y+=16; func_0204B404(((struct Obj14058 *)p)->f194,(const struct Vec2 *)(&s),0); }
