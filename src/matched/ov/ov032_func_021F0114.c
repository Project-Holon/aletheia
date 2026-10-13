/*
 * function: func_021F0114
 * address: 0x021F0114
 * packet: pkt_ov032_021F0114
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F07D4 0x021F07D4 thumb ov032
 *   GPOWER_GetActiveIdOfSameType 0x02010EA0 thumb
 *   func_021F1A18 0x021F1A18 thumb ov032
 */
#include "../include/Obj05120.h"
typedef unsigned char u8;
extern unsigned func_021F07D4(u8 *);
extern u8 GPOWER_GetActiveIdOfSameType(int,u8 *);
extern void func_021F1A18(char *p, int b);
int func_021F0114(u8 *p) { unsigned n; n=func_021F07D4(p); if(n==0x30) return 0; if(n==GPOWER_GetActiveIdOfSameType(n,*(u8 * *)&((struct Obj05120 *)p)->f24)) return 0; func_021F1A18((char *)p,n); return 1; }
