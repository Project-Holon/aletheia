/*
 * function: func_021D61A4
 * address: 0x021D61A4
 * packet: pkt_ov175_021D61A4
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
#include "../../../matched/include/Obj08274.h"
#include "../../../matched/include/Obj24225.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D9EA0(u8 *p);
extern void func_021E8AA8(int a);
extern u32 func_0200FBB0(void);
void func_021D61A4(void *obj,int unused,u8 *p) { ((struct Obj24225 *)(*(u8 * *)&((struct Obj08274 *)p)->f40))->f4=3; if(((struct Obj08274 *)p)->f30) { func_021D9EA0(((struct Obj08274 *)p)->f30); *(u32 *)&((struct Obj08274 *)p)->f30=0; } func_0200FBB0(); func_021E8AA8((int)obj); }
