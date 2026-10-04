/*
 * function: func_0216F3B0
 * address: 0x0216F3B0
 * packet: pkt_ov010_0216F3B0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent: two-byte zero alignment padding at 0216F3D2.
 * symbols:
 *   func_0216F088 0x0216F088 thumb ov010
 */
#include "../include/Obj01640.h"
#include "../include/Obj19156.h"
extern int func_0216F088(int a0);
int func_0216F3B0(char *p) { if (!func_0216F088((int)(p+8))) return 6; if (((struct Obj19156 *)(*(char * *)&((struct Obj01640 *)p)->f18))->fC==3) return 1; return 7; }
