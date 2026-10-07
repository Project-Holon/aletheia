/*
 * file:     gtsnego_disp_p02.c
 * unit:     yes
 * function: func_021D43BC, func_021D444C
 * address:  0x021D43BC
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D439C 0x021D439C thumb ov120
 *   func_021D435C 0x021D435C thumb ov120
 *   func_021D437C 0x021D437C thumb ov120
 *   func_021D7E88 0x021D7E88 thumb ov120
 *   func_021D7E9C 0x021D7E9C thumb ov120
 *   func_021D7EB0 0x021D7EB0 thumb ov120
 *   func_021D6B84 0x021D6B84 thumb ov120
 *   func_020061E4 0x020061E4 thumb
 *   func_02028218 0x02028218 thumb
 */
#include "../../matched/include/Obj01150.h"
#include "../../matched/include/Obj10385.h"

struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_021D439C(int n, char *p);
extern void func_021D435C(int n, char *p);
extern void func_021D437C(int n, char *p);
extern void func_021D7E88(char *p, int i);
extern void func_021D7E9C(char *p, int i);
extern void func_021D7EB0(char *p, int i);
extern void func_021D6B84(u8 *p, u32 n);
extern void func_020061E4(u32 a);
extern void func_02028218(struct Obj *,u32);
int func_021D43BC(int n, char *p);
int func_021D444C(int n,char *p);

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
    if(n>=0 && n<=5) {func_020061E4(0x548);func_021D6B84((u8 *)(((struct Obj01150 *)p)->f3C),n);}
    return result;
}

int func_021D444C(int n,char *p) { int result; if(*(struct Obj * *)&((struct Obj10385 *)p)->f34) func_02028218(*(struct Obj * *)&((struct Obj10385 *)p)->f34,0); result=func_021D43BC(n,p); if(result) ((struct Obj10385 *)p)->f160=result; return 1; }
