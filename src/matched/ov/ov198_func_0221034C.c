/*
 * function: func_0221034C
 * address: 0x0221034C
 * packet: pkt_ov198_0221034C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * remainder: separate conditional follower ov198_func_0221039C.c (28 bytes).
 * symbols:
 *   func_02211958 0x02211958 thumb ov198
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 */
#include "../include/Obj08362.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02211958(u8 **);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_0201F7A8(void *,u32);
int func_0221034C(char *p)
{
    if (func_02211958((u8 **)p)==1) return 0x1f;
    if ((func_020362DC()&3)!=0 || TOUCHPANEL_GetTrg()==1) {
        if (((struct Obj08362 *)p)->f2193==1) {
            func_0201F7A8(((struct Obj08362 *)p)->f1F68,0);
            ((struct Obj08362 *)p)->f2193=0;
        }
        return ((struct Obj08362 *)p)->f217C;
    }
    return 0x18;
}
