/*
 * function: func_021BA0F0
 * address: 0x021BA0F0
 * packet: pkt_ov225_021BA0F0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA152..021BA154 zero alignment padding, inspected in full show.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BA28C 0x021BA28C thumb ov225
 *   func_021BA368 0x021BA368 thumb ov225
 */
#include "../include/Obj01788.h"
typedef unsigned char u8;
struct Obj;
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_021BA28C(char *);
extern void func_021BA368(char *);
void func_021BA0F0(char *p,unsigned b,unsigned c)
{
    p[0xc]=b;p[0xd]=c;
    if(((struct Obj01788 *)p)->f8==3) {
        if(((struct Obj01788 *)p)->fC<=1) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);func_021BA28C(p);return;
        }
        if(((struct Obj01788 *)p)->fD==0) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        } else if(((struct Obj01788 *)p)->fD==b-1) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);
        } else {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        }
        func_021BA368(p);
    }
}
