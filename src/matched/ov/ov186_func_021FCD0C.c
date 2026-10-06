/*
 * function: func_021FCD0C
 * address: 0x021FCD0C
 * packet: pkt_ov186_021FCD0C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCDA0 0x021FCDA0 thumb ov186
 *   func_021FCEDC 0x021FCEDC thumb ov186
 *   func_021FCE60 0x021FCE60 thumb ov186
 *   func_02006254 0x02006254 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00048.h"
typedef unsigned int   u32;
extern int func_021FCDA0(char *);
extern int func_021FCEDC(char *);
extern int func_02006254(u32 a);
struct Obj;
extern void func_021FCE60(char *,int);
extern void func_020061E4(u32 a);
extern void func_0204B3DC(struct Obj *,unsigned int);
void func_021FCD0C(char *p)
{
    if(func_021FCDA0(p)) {
        ((struct Obj00048 *)p)->f4C=func_021FCEDC(p);
        if(((struct Obj00048 *)p)->f4C) {
            if(((int (*)(char *,int))*(int *)(p+0x50))(p,((struct Obj00048 *)p)->f4C)) {
                if(func_02006254(0x6FE)==0) func_020061E4(0x6FE);
                func_021FCE60(p,((struct Obj00048 *)p)->f42);
            }
            if(((struct Obj00048 *)p)->f4D) {
                if(((struct Obj00048 *)p)->f42==0) func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,0);
                else func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,1);
                if(((struct Obj00048 *)p)->f4==((struct Obj00048 *)p)->f42+((struct Obj00048 *)p)->f44) func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,0);
                else func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,1);
            }
        }
    }
    ((void (*)(char *))*(int *)(p+0x58))(p);
}
