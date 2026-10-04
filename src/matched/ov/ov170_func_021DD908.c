/*
 * function: func_021DD908
 * address: 0x021DD908
 * packet: pkt_ov170_021DD908
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_020092AC 0x020092AC thumb
 */
#include "../include/Obj06551.h"
#include "../include/Obj23835.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern u32 func_021DD25C(void ***,u16,int,u32,u32);
extern u32 func_020092AC(const u8 *bits, int n);
u32 func_021DD908(char *p,u32 a) { u16 n;n=func_021DD25C((void ***)p,a,((struct Obj06551 *)p)->f14,5,0);return func_020092AC(*(u8 * *)&((struct Obj23835 *)(*(char * *)&((struct Obj06551 *)p)->f0))->f20,n); }
