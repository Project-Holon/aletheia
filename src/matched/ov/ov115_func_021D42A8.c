/*
 * function: func_021D42A8
 * address: 0x021D42A8
 * packet: pkt_ov115_021D42A8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 */
#include "../include/Obj22582.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern u32 func_0201283C(const struct BigObj *p);
struct Sub020097BCObj;
extern void func_02009860(struct Sub020097BCObj *obj);
void func_021D42A8(u8 *p) { func_02009860((struct Sub020097BCObj *)func_0201283C(((struct Obj22582 *)p)->f44)); }
