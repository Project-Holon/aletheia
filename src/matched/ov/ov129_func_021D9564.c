/*
 * function: func_021D9564
 * address: 0x021D9564
 * packet: pkt_ov129_021D9564
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: The two-byte table record has byte fields a and b; both pool words reference that record.
 * symbols:
 *   d_021DA72C 0x021DA72C data a4 ov129
 */
#include "../include/Obj14056.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u8 a,b; } Entry;
extern Entry d_021DA72C[];
void func_021D9564(u8 *p,int n) { if(n>=12 && n<24) { ((struct Obj14056 *)p)->f1B8=d_021DA72C[n-12].a; ((struct Obj14056 *)p)->f1BA=d_021DA72C[n-12].b; } }
