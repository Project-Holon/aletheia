/*
 * function: func_021E10D8, func_021E11A0
 * unit: yes
 * address: 0x021E10D8
 * packet: pkt_ov137_021E10D8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0E50 0x021E0E50 thumb ov137
 *   func_021E0E8C 0x021E0E8C thumb ov137
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj04541.h"
typedef unsigned char u8;
typedef struct {unsigned state;int active,other,timer,speed;} State;
extern void func_021E0E50(char *p);
extern int func_021E0E8C(char *p);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void func_021E10D8(u8 *p,State *s)
{
    u8 *b=p+0xe0;
    switch(s->state) {
    case 1:
        s->speed=0x4000;s->timer=0;s->state++;
    case 2:
        ((struct Obj04541 *)b)->f34-=4096;
        if(((struct Obj04541 *)b)->f34<=-32768)s->state++;
        break;
    case 3:
        ((struct Obj04541 *)b)->f34+=8192;
        if(((struct Obj04541 *)b)->f34>=0) {
            ((struct Obj04541 *)b)->f34=0;
            func_021E0E50((char *)p);
            s->active=1;s->state++;
            func_020061E4(0x55e);
        }
        break;
    case 4:
        ((struct Obj04541 *)b)->f28=s->speed;
        s->speed=-s->speed;
        s->timer++;
        if(!(s->timer&3)) {
            if(s->speed<=4096) {((struct Obj04541 *)b)->f28=0;s->state++;}
            else s->speed>>=1;
        }
        break;
    case 5:
        if(!func_021E0E8C((char *)p)) {
            s->other=0;s->active=0;s->state=0;
            func_020061E4(0x76d);
        }
        break;
    case 0:break;
    }
}
void func_021E11A0(void *unused,u8 *p)
{
    func_021E10D8(p,(State *)(p+0xc74));
}
