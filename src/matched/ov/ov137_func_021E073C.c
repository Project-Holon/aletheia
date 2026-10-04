/*
 * function: func_021E073C
 * address: 0x021E073C
 * packet: pkt_ov137_021E073C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020480E4 0x020480E4 arm
 */
#include "../include/Obj10629.h"
#include "../include/Obj14237.h"
typedef unsigned short u16;
extern void func_020480E4(void *,u16);
void func_021E073C(char *p)
{
    int i;
    char *q = p+0x1a0;
    for (i=0;i<5;i++) func_020480E4(((struct Obj10629 *)p)->fAF4,*(int *)(q+0x940+i*4));
    func_020480E4(((struct Obj10629 *)p)->fAF4,((struct Obj14237 *)q)->f938);
    func_020480E4(((struct Obj10629 *)p)->fAF4,((struct Obj14237 *)q)->f93C);
}
