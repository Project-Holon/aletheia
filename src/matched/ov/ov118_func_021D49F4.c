/*
 * function: func_021D49F4
 * address: 0x021D49F4
 * packet: pkt_ov118_021D49F4
 * region: ov118
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02051A34 0x02051A34 arm
 *   func_02011610 0x02011610 thumb
 *   func_02051838 0x02051838 arm
 */
#include "../include/Obj13873.h"
#include "../include/Obj22658.h"
#include "../include/Obj22659.h"
typedef struct { int x,y,z; } Vec;
extern int func_02051A34(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int func_02011610(struct IcaAnime *p, struct Rec12 *dst);
extern void func_02051838(void *, Vec *);
void func_021D49F4(void *obj, int on) {
 int buf[3]; Vec *v; void *w;
 if (on != 0 && obj != 0) {
 w=(void *)func_02051A34(obj);
 if (((struct Obj22658 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98!=0) {
 v=(Vec *)buf; v->x=0; v->y=0; v->z=0;
 func_02011610(((struct Obj22659 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98,(struct Rec12 *)v);
 func_02051838(obj,v);
 }
 }
}
