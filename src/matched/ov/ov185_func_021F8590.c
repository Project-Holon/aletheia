/*
 * function: func_021F8590
 * address: 0x021F8590
 * packet: pkt_ov185_021F8590
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD6B0 0x021FD6B0 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 */
#include "../include/Obj01966.h"
#include "../include/Obj24716.h"
#include "../include/Obj24717.h"
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
extern void func_021FD71C(char *);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021FC830(char *);
extern int func_021FD6B0(char *);
extern void func_021FD1BC(char *);
extern void func_021F3C50(char *);
int func_021F8590(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char * *)&((struct Obj24716 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f14)==2) {
        func_021F9C6C(*(char * *)&((struct Obj24717 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f10);
        return 1;
    }
    func_021FD71C(*(char * *)&((struct Obj01966 *)p)->f24);
    if (func_021FD72C(*(int * *)&((struct Obj01966 *)p)->f24)) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+56));
    func_0201C4E4((struct PrintSys *)(((struct Obj01966 *)p)->f2C));
    if (*(char * *)&((struct Obj01966 *)p)->f1C) func_021FC830(*(char * *)&((struct Obj01966 *)p)->f1C);
    if (*(char * *)&((struct Obj01966 *)p)->f10) func_021FD6B0(*(char * *)&((struct Obj01966 *)p)->f10);
    if (*(char * *)&((struct Obj01966 *)p)->f4) func_021FD1BC(*(char * *)&((struct Obj01966 *)p)->f4);
    if (*(char * *)&((struct Obj01966 *)p)->f14) func_021F3C50(*(char * *)&((struct Obj01966 *)p)->f14);
    return 0;
}
