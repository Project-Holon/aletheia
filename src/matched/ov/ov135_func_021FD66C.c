/*
 * function: WORLDTRADE_LIST_StateWaitPageWipe
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
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj08188.h"
struct Obj;
extern unsigned WIPE_SYS_EndCheck(void);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
int WORLDTRADE_LIST_StateWaitPageWipe(char *p) { (((struct Obj08188 *)p)->fD3C)++; if(WIPE_SYS_EndCheck()) {((struct Obj08188 *)p)->fD3C=0; ((struct Obj08188 *)p)->f28=1; CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj08188 *)p)->fD34,1);} return 2; }
