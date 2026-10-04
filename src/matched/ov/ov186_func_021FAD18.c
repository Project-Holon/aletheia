/*
 * function: func_021FAD18
 * address: 0x021FAD18
 * packet: pkt_ov186_021FAD18
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAFD0 0x021FAFD0 thumb ov186
 *   func_021FB058 0x021FB058 thumb ov186
 *   func_021FB0E8 0x021FB0E8 thumb ov186
 *   func_021FB1EC 0x021FB1EC thumb ov186
 *   func_021FB2F0 0x021FB2F0 thumb ov186
 */
#include "../include/Obj03891.h"
extern int func_021FAFD0(char *), func_021FB058(char *), func_021FB0E8(char *), func_021FB1EC(char *), func_021FB2F0(char *);
void func_021FAD18(char *ctx, int mode, const int *target)
{
    ((struct Obj03891 *)ctx)->f1C = 0;
    if (target) {
        ((struct Obj03891 *)ctx)->f14 = target[0];
        ((struct Obj03891 *)ctx)->f18 = target[1];
    }
    switch (mode) {
    case 0: *(int (**)(char *))(ctx + 0x10) = func_021FAFD0; break;
    case 1: *(int (**)(char *))(ctx + 0x10) = func_021FB058; break;
    case 2: *(int (**)(char *))(ctx + 0x10) = func_021FB0E8; break;
    case 3: *(int (**)(char *))(ctx + 0x10) = func_021FB1EC; break;
    case 4: *(int (**)(char *))(ctx + 0x10) = func_021FB2F0; break;
    }
}
