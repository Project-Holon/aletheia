/*
 * function: func_021EB95C
 * address: 0x021EB95C
 * packet: pkt_ov170_021EB95C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_021EB90C 0x021EB90C thumb ov170
 */
#include "../include/Obj01558.h"
#include "../include/Obj23986.h"
#include "../include/Obj23987.h"
#include "../include/Obj23988.h"
#include "../include/Obj23989.h"
typedef unsigned int   u32;
struct WinMgr;
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a); extern void func_021EB90C(char *);
void func_021EB95C(char *p){func_0202CEBC((struct WinMgr *)(((struct Obj23986 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74),7,(void *)(((struct Obj23987 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f134));func_0202CEBC((struct WinMgr *)(((struct Obj23988 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74),7,(void *)(((struct Obj23989 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f13C));func_021EB90C(p);}
