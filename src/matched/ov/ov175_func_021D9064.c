/*
 * function: func_021D9064
 * address: 0x021D9064
 * packet: pkt_ov175_021D9064
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
#include "../include/Obj08276.h"
#include "../include/Obj24283.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D9EA0(u8 *p);
extern void func_021E8AA8(int a);
extern u32 func_0200FBB0(void);
void func_021D9064(void *obj,int unused,u8 *p) { ((struct Obj24283 *)(*(u8 * *)&((struct Obj08276 *)p)->f104))->f4=3; if(((struct Obj08276 *)p)->f34) { func_021D9EA0(((struct Obj08276 *)p)->f34); *(u32 *)&((struct Obj08276 *)p)->f34=0; } func_0200FBB0(); func_021E8AA8((int)obj); }
