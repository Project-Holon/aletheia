/*
 * unit: yes
 * function: func_021FCA38, func_021FCAA0
 * address: 0x021FCA38
 * packet: pkt_ov132_021FCA38
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03291.h"
#include "../include/Obj10565.h"
#include "../include/Obj23271.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021FCA38(char *p)
{
    u8 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*0x30;
        if(((struct Obj10565 *)q)->f7C) {
            func_020307B0(((struct Obj10565 *)q)->f8C);
            func_020307B0(((struct Obj10565 *)q)->f7C);
        }
    }
    if(((struct Obj03291 *)p)->f124) func_020307B0(((struct Obj03291 *)p)->f124);
    if(((struct Obj03291 *)p)->f138) func_020307B0(((struct Obj03291 *)p)->f138);
    if(((struct Obj03291 *)p)->f128) func_020307B0(((struct Obj03291 *)p)->f128);
    if(((struct Obj03291 *)p)->f13C) func_020307B0(((struct Obj03291 *)p)->f13C);
}
void func_021FCAA0(char *p)
{
    ((struct Obj23271 *)p)->f10=1;
}
