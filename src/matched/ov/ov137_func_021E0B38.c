/*
 * function: GURU2_MAIN_InitPlayerUnit
 * address: 0x021E0B38
 * packet: pkt_ov137_021E0B38
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj01555.h"
#include "../include/Obj23780.h"
#include "../include/Obj23781.h"
#include "../include/Obj23782.h"
#include "../include/Obj23783.h"
typedef struct { int x,y,z; } Vec;
void GURU2_MAIN_InitPlayerUnit(char *p,char *q,int amount)
{
    int n;
    ((struct Obj01555 *)q)->f4=0;
    ((struct Obj01555 *)q)->f6=0;
    ((struct Obj01555 *)q)->f8=0;
    *(Vec *)(q+0x18)=*(Vec *)(*(char * *)&((struct Obj01555 *)q)->f78+0x44);
    ((struct Obj01555 *)q)->f18-=((struct Obj23780 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f50;
    ((struct Obj01555 *)q)->f1C-=((struct Obj23781 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f54+amount;
    ((struct Obj01555 *)q)->f20-=((struct Obj23782 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f58;
    ((struct Obj01555 *)q)->f1C+=0x2000;
    n=((struct Obj23783 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f54+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    ((struct Obj01555 *)q)->fC=0x1000-n;
    ((struct Obj01555 *)q)->f10=0x1000-n;
    ((struct Obj01555 *)q)->f14=0x1000-n;
}
