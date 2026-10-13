/*
 * function: func_021FD66C
 * address: 0x021FD66C
 * packet: pkt_ov135_021FD66C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj08188.h"
struct Obj;
extern unsigned WIPE_SYS_EndCheck(void);
extern void func_0204B3DC(struct Obj *,unsigned);
int func_021FD66C(char *p) { (((struct Obj08188 *)p)->fD3C)++; if(WIPE_SYS_EndCheck()) {((struct Obj08188 *)p)->fD3C=0; ((struct Obj08188 *)p)->f28=1; func_0204B3DC(*(struct Obj * *)&((struct Obj08188 *)p)->fD34,1);} return 2; }
