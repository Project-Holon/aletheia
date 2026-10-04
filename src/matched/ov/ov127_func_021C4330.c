/*
 * function: func_021C4330
 * address: 0x021C4330
 * packet: pkt_ov127_021C4330
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj14018.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204AFD8(u32);
void func_021C4330(char *p) { int i; char *q; for(i=16;i<18;i++) { q=(char *)((u32)p+(u32)i*20); func_0204AFD8(((struct Obj14018 *)q)->f188); ((struct Obj14018 *)q)->f188=0; } }
