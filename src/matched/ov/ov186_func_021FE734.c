/*
 * function: func_021FE734
 * address: 0x021FE734
 * packet: pkt_ov186_021FE734
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021FE766 follow; no follower.
 * ABI: 02021540's legacy source declares void(void), but this caller loads r0 from p+0x20 at 021FE758; its tail-forward target 020307B0 saves and reads r0. Preserve that pointer argument.
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06634.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot; extern void func_020215A0(struct PalAnmSlot *,u32); extern void func_02021540(void *); extern void func_020307B0(void *);
void func_021FE734(char *p) { func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,2); func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,0); func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,3); func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,1); func_02021540(((struct Obj06634 *)p)->f20); func_020307B0(p); }
