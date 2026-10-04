/*
 * function: func_021E078C
 * address: 0x021E078C
 * packet: pkt_ov137_021E078C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0B14 0x021E0B14 thumb ov137
 *   func_021E0BA4 0x021E0BA4 thumb ov137
 */
#include "../include/Obj23777.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E0B14(char *,char *);
extern void func_021E0BA4(char *,char *);
void func_021E078C(char *p,char *q) { ((struct Obj23777 *)q)->f4=1; func_021E0B14(p,q); func_021E0BA4(p,q); }
