/*
 * function: func_021D7180
 * address:  0x021D7180
 * packet:   pkt_ov123_021D7180
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D580C  0x021D580C  thumb  ov123
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_021D6EE0  0x021D6EE0  thumb  ov123
 *   func_021D5A60  0x021D5A60  thumb  ov123
 *   func_021D57D0  0x021D57D0  thumb  ov123
 *   func_021D56FC  0x021D56FC  thumb  ov123
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_021D70BC  0x021D70BC  thumb  ov123
 *   func_021D7130  0x021D7130  thumb  ov123
 */
#include "../include/Obj03792.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern int func_021D580C(char *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D5A60(char *p);
extern void func_021D57D0(void *p, int msg, int n, void *mon);
extern void func_021D56FC(char *p, int mode);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void func_021D70BC(char *p);
extern void func_021D7130(char *p);

void func_021D7180(int a)
{
    if (func_021D580C((char *)(((struct Obj03792 *)a)->f18)) == 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((struct Obj03792 *)a)->f6C == 0) {
        func_021D6EE0((u8 *)a, (int)func_021D70BC, 0x217);
        return;
    }
    func_021D5A60((char *)(((struct Obj03792 *)a)->f18));
    func_021D57D0((void *)(((struct Obj03792 *)a)->f18), 0x16, ((struct Obj03792 *)a)->f6C,
                 (void *)(((struct Obj03792 *)a)->fC));
    func_021D56FC((char *)(((struct Obj03792 *)a)->f18), 0);
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
    ((struct Obj03792 *)a)->f78 = 0xb4;
    func_021D6EE0((u8 *)a, (int)func_021D7130, 0x222);
}
