/*
 * function: func_021BA068
 * address: 0x021BA068
 * packet: pkt_ov225_021BA068
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BA644 0x021BA644 thumb ov225
 *   func_021BA28C 0x021BA28C thumb ov225
 *   func_021BA2B0 0x021BA2B0 thumb ov225
 *   func_021BA30C 0x021BA30C thumb ov225
 */
#include "../include/Obj03964.h"
struct Obj;
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_021BA644(char *);
extern void func_021BA28C(char *);
extern void func_021BA2B0(char *);
extern void func_021BA30C(char *);
void func_021BA068(char *p,unsigned state)
{
    if(((struct Obj03964 *)p)->f8==state)return;
    switch(((struct Obj03964 *)p)->f8) {
    case 0:func_021B6558(((struct Obj03964 *)p)->f4,0,0);break;
    case 3:func_0204B3DC(*(struct Obj * *)&((struct Obj03964 *)p)->f38,0);func_0204B3DC(*(struct Obj * *)&((struct Obj03964 *)p)->f3C,0);break;
    case 1:case 2:case 4:break;
    }
    ((struct Obj03964 *)p)->f8=state;func_021BA644(p);
    switch(((struct Obj03964 *)p)->f8) {
    case 0:func_021B6558(((struct Obj03964 *)p)->f4,0,1);func_021BA28C(p);break;
    case 1:func_021BA2B0(p);break;
    case 2:func_021BA30C(p);break;
    case 3:case 4:break;
    }
}
