/*
 * function: func_02189EF8
 * address: 0x02189EF8
 * packet: pkt_ov096_02189EF8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113B0 0x020113B0 thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D6D7C 0x021D6D7C thumb ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj21978.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u32 func_021D6D7C(u8 *p);
int func_02189EF8(struct Cursor *a, u8 *b)
{
    int t; u32 n; u8 s; t = func_0201134C(a); n = func_0201134C(a); s = func_0218A160(b,t); if (func_021D6D7C(func_0218A2FC(b,s))) func_020113B0((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + n); return ((struct Obj21978 *)b)->fC4;
}
