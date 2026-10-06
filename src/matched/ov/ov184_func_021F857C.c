/*
 * function: func_021F857C
 * address: 0x021F857C
 * packet: pkt_ov184_021F857C
 * region: ov184
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
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 */
#include "../include/Obj03336.h"
#include "../include/Obj24698.h"
#include "../include/Obj24699.h"
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
typedef unsigned char  u8;
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern void func_021F3C50(u8 *p);
int func_021F857C(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char * *)&((struct Obj24698 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f14)==2) {
        func_021F9C6C(*(char * *)&((struct Obj24699 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(*(char * *)&((struct Obj03336 *)p)->fC));
    if (func_021FD72C(*(int * *)&((struct Obj03336 *)p)->fC)) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+20));
    func_0201C4E4((struct PrintSys *)(((struct Obj03336 *)p)->f20));
    if (*(char * *)&((struct Obj03336 *)p)->f10) func_021FD1BC(*(char * *)&((struct Obj03336 *)p)->f10);
    if (*(char * *)&((struct Obj03336 *)p)->f0) func_021F3C50((u8 *)(*(char * *)&((struct Obj03336 *)p)->f0));
    return 0;
}
