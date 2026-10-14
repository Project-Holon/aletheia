/*
 * function: ZUKAN_LIST_StartButtonAnim
 * address: 0x021BD2C4
 * packet: pkt_ov209_021BD2C4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 */
#include "../include/Obj25555.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bits {u16 low:1;u16 high:15;};
extern void ZUKAN_LIST_StartActorAnim(char *,int,int);
int ZUKAN_LIST_StartButtonAnim(char *p,int a,int b,int c) { ZUKAN_LIST_StartActorAnim(p,a,b);((struct Bits *)(p+0xc24))->high=(u16)a;((struct Obj25555 *)p)->f18=c;return 6; }
