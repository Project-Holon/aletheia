/*
 * function: func_021FE93C
 * address: 0x021FE93C
 * packet: pkt_ov135_021FE93C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj23416.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);extern void func_021F4E98(char *,unsigned,unsigned);extern void GFL_USE_PlaySeDefaultVolume(int);
int func_021FE93C(char *p) {func_021FF318((u8 *)p,171,4,0,0xf0f);func_021F4E98(p,24,31);((struct Obj23416 *)p)->fDFC=0;GFL_USE_PlaySeDefaultVolume(0x557);return 2;}
