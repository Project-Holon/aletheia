/*
 * function: BOX2_SEQ_PutNameFrame
 * address: 0x021EB95C
 * packet: pkt_ov170_021EB95C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BOX2_SEQ_ChangeFramePalette 0x021EB90C thumb ov170
 */
#include "../include/Obj01558.h"
#include "../include/Obj23986.h"
#include "../include/Obj23987.h"
#include "../include/Obj23988.h"
#include "../include/Obj23989.h"
typedef unsigned int   u32;
struct WinMgr;
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a); extern void BOX2_SEQ_ChangeFramePalette(char *);
void BOX2_SEQ_PutNameFrame(char *p){BGWINFRM_PutBmpWin((struct WinMgr *)(((struct Obj23986 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74),7,(void *)(((struct Obj23987 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f134));BGWINFRM_PutBmpWin((struct WinMgr *)(((struct Obj23988 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74),7,(void *)(((struct Obj23989 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f13C));BOX2_SEQ_ChangeFramePalette(p);}
