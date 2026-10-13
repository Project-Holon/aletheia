/*
 * function: func_021DCFF4
 * address: 0x021DCFF4
 * packet: pkt_ov171_021DCFF4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_021DE8A8 0x021DE8A8 thumb ov171
 *   func_021DD51C 0x021DD51C thumb ov171
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021DD500 0x021DD500 thumb ov171
 */
#include "../include/Obj00347.h"
#include "../include/Obj24051.h"
#include "../include/Obj24052.h"
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int func_021DE8A8(char *);
extern int func_021DD51C(char *,s8);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int func_021DD500(char *,int,int,int);
int func_021DCFF4(char *p) {
    int choice;
    if (!PRINTSYS_QUE_IsFinished(((struct Obj00347 *)p)->fB6C)) return 4;
    choice=func_021DE8A8(p);
    switch(choice) {
    case 0:
        if (func_021DD51C(p,-1)==1) {
            GFL_USE_PlaySeDefaultVolume(0x54b);
            return func_021DD500(p,12,12,5);
        }
        break;
    case 1:
        if (func_021DD51C(p,1)==1) {
            GFL_USE_PlaySeDefaultVolume(0x54b);
            return func_021DD500(p,13,13,5);
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x556);
        ((struct Obj24051 *)(*(char * *)&((struct Obj00347 *)p)->f0))->f6=1;
        return func_021DD500(p,14,8,10);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ((struct Obj24052 *)(*(char * *)&((struct Obj00347 *)p)->f0))->f6=0;
        return func_021DD500(p,15,9,10);
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ((struct Obj00347 *)p)->fC5D=((struct Obj00347 *)p)->fC5C;
        return 6;
    case 5: case 6: case 7: case 8: case 9: case 10:
        ((struct Obj00347 *)p)->fC5D=choice-5;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 6;
    }
    return 4;
}
