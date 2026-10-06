/*
 * unit: yes
 * function: func_021BA934
 * address: 0x021BA934
 * packet: pkt_ov206_021BA934
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00173.h"
struct Descriptor;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern unsigned int func_020452E8(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BA934(char *p)
{
    int i;
    func_0201C6EC(((struct Obj00173 *)p)->f2C);
    for(i=0;i<4;i++){
        *(int *)(p+i*4+124)=1;
        func_020452E8(*(void **)(p+i*4+108));
    }
    func_020307B0(((struct Obj00173 *)p)->f2B0);
}
