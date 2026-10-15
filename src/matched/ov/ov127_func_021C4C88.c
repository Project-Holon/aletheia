/*
 * function: WF2DMAP_OBJ_ApplyCommand
 * address: 0x021C4C88
 * packet: pkt_ov127_021C4C88
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sWf2dmapCommandTable 0x021C601C data a4
 */
#include "../include/Obj23041.h"
#include "../include/Obj23042.h"
typedef unsigned short u16;
struct pair {u16 a,b;};
extern void (*sWf2dmapCommandTable)(char *,struct pair,unsigned);
void WF2DMAP_OBJ_ApplyCommand(char *p,char *q)
{
 (*(void (**)(char *,struct pair,unsigned))((unsigned)&sWf2dmapCommandTable+*(u16 *)(q+4)*4))(p,*(struct pair *)q,((struct Obj23042 *)q)->f6);
 ((struct Obj23041 *)p)->f16=0;
}
