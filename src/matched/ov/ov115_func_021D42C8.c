/*
 * function: func_021D42C8
 * address: 0x021D42C8
 * packet: pkt_ov115_021D42C8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009C24 0x02009C24 thumb
 */
#include "../include/Obj22584.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
struct Sub020097BCObj;
extern u32 func_0201283C(const struct BigObj *p);
extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);
void func_021D42C8(int a,int b,u8 *p) { func_02009C24((void *)func_0201283C(((struct Obj22584 *)p)->f44),a,b); }
