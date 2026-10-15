/*
 * function: WF2DMAP_OBJ_FindById
 * address: 0x021C4954
 * packet: pkt_ov127_021C4954
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj14029.h"
char *WF2DMAP_OBJ_FindById(unsigned *p, unsigned id)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0]; char *e;
 do { e=base+i*24; if (((struct Obj14029 *)e)->f0==1 && id==((struct Obj14029 *)e)->fC) return e; i++; } while(i<p[1]); }
 return 0;
}
