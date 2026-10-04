/*
 * function: func_021C8FA8
 * address: 0x021C8FA8
 * packet: pkt_ov212_021C8FA8
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02031348 legacy void(void) forwards untouched r0-r3 to
 * 020314F4; its matched body reads all four and caller sets all four.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02031348 0x02031348 arm
 *   func_021C8F90 0x021C8F90 thumb ov212
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BC8BC 0x021BC8BC data ov211 a4
 *   ov211_id 0x000000D3 data a1
 */
#include "../include/Obj06701.h"
#include "../include/Obj25653.h"
typedef unsigned short u16;
struct Obj020314F4;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02031348(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern int func_021C8F90(char *,int);
extern const char d_021C99A0[];
extern const unsigned d_021BC8BC[];
extern unsigned char ov211_id[];
void func_021C8FA8(char *p)
{
    unsigned *q;
    q=func_02030734(105,12,0,d_021C99A0,297);
    ((struct Obj06701 *)p)->f28=q;
    q[0]=**(unsigned * *)&((struct Obj06701 *)p)->f0;
    q[1]=((struct Obj25653 *)(*(char * *)&((struct Obj06701 *)p)->f0))->f8;
    func_02031348(*(struct Obj020314F4 * *)&((struct Obj06701 *)p)->f4,(unsigned)ov211_id,(unsigned)d_021BC8BC,*(unsigned *)&((struct Obj06701 *)p)->f28);
    func_021C8F90(p,2);
}
