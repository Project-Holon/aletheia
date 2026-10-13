/*
 * function: func_021DC914
 * address: 0x021DC914
 * packet: pkt_ov134_021DC914
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov90_id 0x0000005A data a1
 *   PLIST_COMM_End 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj23343.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PLIST_COMM_End(void *);
extern void func_02034A5C(int);
struct S020314B8;
struct S020315D4;
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern const char ov90_id[];
int func_021DC914(void *p,u32 a,u32 b,char *ctx) { PLIST_COMM_End(ctx+4); func_02034A5C((int)ov90_id); func_0203133C(((struct Obj23343 *)ctx)->fCC); func_020315D4(p); return 1; }
