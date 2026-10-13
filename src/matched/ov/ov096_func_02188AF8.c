/*
 * function: func_02188AF8
 * address: 0x02188AF8
 * packet: pkt_ov096_02188AF8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 */
#include "../include/Obj21944.h"
struct Cursor; extern unsigned int VM_GetU32(struct Cursor *); extern int func_0218A0F4(unsigned char *,int,int,int,int);
int func_02188AF8(struct Cursor *a, unsigned char *b, int c) { int x,y; x=VM_GetU32(a); y=VM_GetU32(a); return func_0218A0F4((unsigned char *)a,c,((struct Obj21944 *)b)->f2,x,y); }
