/*
 * function: func_021DA3C0
 * address: 0x021DA3C0
 * packet: pkt_ov121_021DA3C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_Delete 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22883.h"
#include "../include/Obj22884.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
void func_021DA3C0(u8 *p) { u32 i; for(i=0;i<((struct Obj22884 *)(*(u8 * *)&((struct Obj22883 *)p)->f4))->f4;i++) BMP_Delete(*(void **)(p+8+i*4)); func_020307B0(p); }
