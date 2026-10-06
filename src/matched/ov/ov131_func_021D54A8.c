/*
 * function: func_021D54A8
 * address: 0x021D54A8
 * packet: pkt_ov131_021D54A8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arithmetic: signed p+58 guard accepts negatives; scaled address uses
 *   unsigned 32-bit multiply/add for the original wrapping lsl/add sequence.
 * symbols:
 *   func_021D5C98 0x021D5C98 thumb ov131
 *   func_021D5B58 0x021D5B58 thumb ov131
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj00039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D5C98(u8 *p);
extern int func_021D5B58(u8 *,int);
extern int func_021D62E4(char *);
struct Obj;
extern void func_020061E4(u32 a);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021D54A8(char *p)
{
    switch (((struct Obj00039 *)p)->f24) {
    case 0:
        if (((struct Obj00039 *)p)->f58!=0) {
            ((struct Obj00039 *)p)->f58=0;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 1:
        if (((struct Obj00039 *)p)->f58!=1 && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=1;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 2:
        if (((struct Obj00039 *)p)->f58!=2 && ((struct Obj00039 *)p)->f38==0 && ((struct Obj00039 *)p)->f40==1) {
            ((struct Obj00039 *)p)->f58=2;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 3:
        if (((struct Obj00039 *)p)->f58<3 && func_021D62E4(p)==1) {
            if (*(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)==1) {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=0;
                func_0204B878(((struct Obj00039 *)p)->f184,6);
            } else {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=1;
                func_0204B878(((struct Obj00039 *)p)->f184,7);
            }
            func_020061E4(1606);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 4:
        if (func_021D5B58((u8 *)p,0)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,11);
            func_0204B878(((struct Obj00039 *)p)->f18C,2);
            ((struct Obj00039 *)p)->f48=1;
            ((struct Obj00039 *)p)->f4C=0;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 5:
        if (func_021D5B58((u8 *)p,1)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,3);
            func_0204B878(((struct Obj00039 *)p)->f18C,10);
            ((struct Obj00039 *)p)->f48=0;
            ((struct Obj00039 *)p)->f4C=1;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 6:
        if (func_021D62E4(p)==1) {
            ((struct Obj00039 *)p)->f54=2;
            (*(u8 **)(p+8))[0x12]=2;
            ((struct Obj00039 *)p)->f50=2;
            func_0204B878(((struct Obj00039 *)p)->f190,8);
            ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f190;
            func_020061E4(1366);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 7:
        ((struct Obj00039 *)p)->f54=1;
        (*(u8 **)(p+8))[0x12]=1;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f194,9);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f194;
        func_020061E4(1361);
        ((struct Obj00039 *)p)->f1C=1;
        break;
    }
}
