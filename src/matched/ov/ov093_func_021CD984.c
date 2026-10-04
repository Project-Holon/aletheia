/*
 * function: func_021CD984
 * address: 0x021CD984
 * packet: pkt_ov093_021CD984
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 * symbols:
 *   func_021EE674 0x021EE674 thumb ov093
 *   func_021EEBDC 0x021EEBDC thumb ov093
 *   func_021D3F64 0x021D3F64 thumb ov093
 *   func_021CDA0C 0x021CDA0C thumb ov093
 *   func_021CDC0C 0x021CDC0C thumb ov093
 */
#include "../include/Obj07767.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EE674(void *);
extern void func_021EEBDC(void *);
extern void func_021D3F64(u8 *,u16);
struct QE;
extern void func_021CDA0C(struct QE *p, u32 v);
extern int func_021CDC0C(u8 *);
void func_021CD984(u8 *p,u16 n) { func_021EE674(((struct Obj07767 *)p)->f14); func_021EEBDC(((struct Obj07767 *)p)->f50); func_021D3F64(p+0x18,n); func_021CDA0C((struct QE *)p,(u32)func_021CDC0C); }
