/*
 * function: func_021B8810
 * address: 0x021B8810
 * packet: pkt_ov104_021B8810
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj22233.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
void func_021B8810(int a,int b,int c,u8 *p,int e) { if(e==(int)func_020399A8() && a!=func_02039338()) ((struct Obj22233 *)p)->f194=1; }
