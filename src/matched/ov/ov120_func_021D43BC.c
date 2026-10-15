/*
 * function: func_021D43BC
 * address: 0x021D43BC
 * packet: pkt_ov120_021D43BC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D439C 0x021D439C arm ov120
 *   func_021D435C 0x021D435C thumb ov120
 *   func_021D437C 0x021D437C thumb ov120
 *   func_021D7E88 0x021D7E88 thumb ov120
 *   func_021D7E9C 0x021D7E9C thumb ov120
 *   func_021D7EB0 0x021D7EB0 thumb ov120
 *   func_021D6B84 0x021D6B84 thumb ov120
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj01150.h"
typedef unsigned int   u32;
extern void func_021D439C(int n, char *p);
extern void func_021D435C(int n, char *p);
extern void func_021D437C(int n, char *p);
typedef unsigned char  u8;
extern void func_021D7E88(char *p, int i);
extern void func_021D7E9C(char *p, int i);
extern void func_021D7EB0(char *p, int i);
extern void func_021D6B84(u8 *p, u32 n);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021D43BC(int n, char *p) {
    int result=0;
    switch(n) {
    case 0:func_021D439C(-1,p);result=2;func_021D7E88((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f144);break;
    case 1:func_021D439C(1,p);result=2;func_021D7E88((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f144);break;
    case 2:func_021D435C(-1,p);result=3;func_021D7E9C((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f13C);break;
    case 3:func_021D435C(1,p);result=3;func_021D7E9C((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f13C);break;
    case 4:func_021D437C(-1,p);result=4;func_021D7EB0((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f140);break;
    case 5:func_021D437C(1,p);result=4;func_021D7EB0((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f140);break;
    }
    if(n>=0 && n<=5) {GFL_USE_PlaySeDefaultVolume(0x548);func_021D6B84((u8 *)(((struct Obj01150 *)p)->f3C),n);}
    return result;
}
