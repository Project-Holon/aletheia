/*
 * function: func_021E20F8
 * address: 0x021E20F8
 * packet: pkt_ov183_021E20F8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 */
#include "../include/Obj06612.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(int);
extern int func_021FC830(u8 *p);
int func_021E20F8(int a,int b,int c,char *p)
{
    int i;
    func_021FD71C((u8 *)(((struct Obj06612 *)p)->f8));
    if (func_021FD72C((int *)(((struct Obj06612 *)p)->f8))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x14)));
    func_0201C4E4((struct PrintSys *)(((struct Obj06612 *)p)->f0));
    if (((struct Obj06612 *)p)->f4) func_021FD1BC(((struct Obj06612 *)p)->f4);
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0xc)) func_021FC830((u8 *)(*(int *)(p+i*4+0xc)));
    return 0;
}
