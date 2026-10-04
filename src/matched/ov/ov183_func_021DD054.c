/*
 * function: func_021DD054
 * address: 0x021DD054
 * packet: pkt_ov183_021DD054
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00050.h"
#include "../include/Obj06598.h"
#include "../include/Obj10730.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
void func_021DD054(char *p, char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD8) {
        if(((struct Obj00050 *)p)->f28) { func_021FC734(((struct Obj00050 *)p)->f28); *(int *)&((struct Obj00050 *)p)->f28=0; }
        for(i=0;i<2;i++) {
            slot=p+i*4;
            if(((struct Obj10730 *)slot)->f1C) { func_021FB494(((struct Obj10730 *)slot)->f1C); *(int *)&((struct Obj10730 *)slot)->f1C=0; }
        }
        func_020409B4(4);
        func_021FC0C8((char *)(((struct Obj06598 *)q)->f10),6);
        func_021FBDA4(((struct Obj06598 *)q)->f10,5);
        ((struct Obj00050 *)p)->fD8=0;
    }
}
