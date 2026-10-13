/*
 * function: P_STATUS_CheckKey
 * address: 0x021D52D4
 * packet: pkt_ov131_021D52D4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Default max=2 followed by conditional max=1 preserves the register select.
 * interfaces: 0203633C/020362DC owner units spell their full-word payload as
 *   void *. This caller consumes r0 as an input bitmask; u32 return retains
 *   all 32 bits without dereferencing or narrowing. Guards stay signed while
 *   updates use unsigned wrapping through the same int lvalue.
 * arithmetic: signed p+58 guard accepts negatives; scaled address uses
 *   unsigned 32-bit multiply/add for the original wrapping lsl/add sequence.
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   P_STATUS_RequestRefresh 0x021D5C98 thumb ov131
 *   P_STATUS_ChangePokemon 0x021D5B58 thumb ov131
 *   P_STATUS_CanUseButtons 0x021D62E4 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj00039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void P_STATUS_RequestRefresh(u8 *p);
extern int P_STATUS_ChangePokemon(u8 *,int);
extern int P_STATUS_CanUseButtons(char *);
extern void func_020061E4(u32);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
int P_STATUS_CheckKey(char *p)
{
    int max;
    if (func_0203633C() & 0x80) {
        if (P_STATUS_ChangePokemon((u8 *)p,1)==1) {
            P_STATUS_RequestRefresh((u8 *)p);
            CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f188,3);
            CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f18C,10);
            ((struct Obj00039 *)p)->f48=0;
            ((struct Obj00039 *)p)->f4C=1;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x40) {
        if (P_STATUS_ChangePokemon((u8 *)p,0)==1) {
            P_STATUS_RequestRefresh((u8 *)p);
            CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f188,11);
            CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f18C,2);
            ((struct Obj00039 *)p)->f48=1;
            ((struct Obj00039 *)p)->f4C=0;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x10) {
        max=2;
        if (((struct Obj00039 *)p)->f40==0) max=1;
        if (((struct Obj00039 *)p)->f58<max && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=(int)((u32)((struct Obj00039 *)p)->f58+1);
            P_STATUS_RequestRefresh((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x20) {
        if (((struct Obj00039 *)p)->f58>0 && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=(int)((u32)((struct Obj00039 *)p)->f58-1);
            P_STATUS_RequestRefresh((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_020362DC() & 2) {
        ((struct Obj00039 *)p)->f54=1;
        (*(u8 **)(p+8))[0x12]=1;
        ((struct Obj00039 *)p)->f50=2;
        CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f194,9);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f194;
        func_020061E4(1361);
        ((struct Obj00039 *)p)->f1C=0;
        return 1;
    } else if ((func_020362DC() & 0x400) && P_STATUS_CanUseButtons(p)==1) {
        ((struct Obj00039 *)p)->f54=2;
        (*(u8 **)(p+8))[0x12]=2;
        ((struct Obj00039 *)p)->f50=2;
        CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f190,8);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f190;
        func_020061E4(1366);
        ((struct Obj00039 *)p)->f1C=0;
        return 1;
    } else if ((func_020362DC() & 0x800) && P_STATUS_CanUseButtons(p)==1) {
        if (((struct Obj00039 *)p)->f58<3) {
            if (*(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)==1) {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=0;
                CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f184,6);
            } else {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=1;
                CLACT_SetActorAnimSeq(((struct Obj00039 *)p)->f184,7);
            }
            func_020061E4(1606);
            ((struct Obj00039 *)p)->f1C=0;
        }
        return 1;
    }
    return 0;
}
