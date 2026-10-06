/*
 * function: func_021B6828
 * address: 0x021B6828
 * packet: pkt_ov173_021B6828
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 2 zero alignment bytes at 0x021B684E follow the 38-byte function; no follower.
 * symbols:
 *   func_02028604 0x02028604 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 */
#include "../include/Obj24151.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02028604(int);
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
void func_021B6828(char *p) { u32 i; func_02028604(((struct Obj24151 *)p)->f21C); for(i=0;i<16;i++) func_020452E8(*(void **)((u32)p+i*4+4)); func_020450C8(); }
