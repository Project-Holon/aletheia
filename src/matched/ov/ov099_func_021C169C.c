/*
 * function: func_021C169C
 * address: 0x021C169C
 * packet: pkt_ov099_021C169C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C16EA.
 * lever: GFL_NET_Exit receives the live zero in r0.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 */
#include "../include/Obj00008.h"
extern int func_021BA928(char *, int);
extern void func_021BAAB8(char *, int, int);
struct Sub020097BCObj;
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_GetRunState(void);
extern void func_02009B3C(struct Sub020097BCObj *obj);
int func_021C169C(char *p, int ret)
{
    if (func_021BA928(p, ret) == 0) return ret;
    if (((struct Obj00008 *)p)->f1E0 == 1) {
        ((struct Obj00008 *)p)->f1E0 = 0;
        GFL_NET_Exit(0);
    }
    if (GFL_NET_GetRunState() == 0) {
        func_02009B3C(((struct Obj00008 *)p)->f4);
        func_021BAAB8(p, 27, 1);
        ((struct Obj00008 *)p)->f1CC = 52;
        ((struct Obj00008 *)p)->f1E0 = 30;
    }
    return ret;
}
