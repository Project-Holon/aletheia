/*
 * function: func_021BE6A8
 * address: 0x021BE6A8
 * packet: pkt_ov208_021BE6A8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BE70E..021BE710 is two-byte zero alignment padding.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_021BD3F8 0x021BD3F8 thumb ov208
 */
#include "../include/Obj03931.h"

typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern void func_021BD3F8(void *,int);
void func_021BE6A8(char *p)
{
    unsigned held=KEY_GetTrg();
    unsigned keys=KEY_GetRepeat();
    if(!(held&0x3f0)) {
        if(keys&0x40) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f94);
        else if(keys&0x80) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f8C);
        else if(keys&0x220) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f7C);
        else if(keys&0x110) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f74);
    }
}
