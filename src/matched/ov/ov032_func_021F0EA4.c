/*
 * function: func_021F0EA4
 * address: 0x021F0EA4
 * packet: pkt_ov032_021F0EA4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F0ED0 0x021F0ED0 thumb ov032
 */
#include "../include/Obj00225.h"
extern void BMP_OAM_SetEnabled(unsigned char *,unsigned);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021F0ED0(char *,int);
void func_021F0EA4(char *p,unsigned a) { BMP_OAM_SetEnabled(*(unsigned char * *)&((struct Obj00225 *)p)->f18,a); func_0204B3DC(((struct Obj00225 *)p)->f10,a); func_0204B3DC(((struct Obj00225 *)p)->fC,a); if(a==0) func_021F0ED0(p,a); }
