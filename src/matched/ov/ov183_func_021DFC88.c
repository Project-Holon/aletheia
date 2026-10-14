/*
 * function: func_021DFC88
 * address: 0x021DFC88
 * packet: pkt_ov183_021DFC88
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 */
#include "../include/Obj24620.h"
typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void func_021FB494(char *p);
extern void func_020409B4(unsigned int);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
int func_021DFC88(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(p + i * 4) != 0) {
            BR_UTIL_Delete(*(void **)(p + i * 4));
            *(void **)(p + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(p + i * 4 + 12) != 0) {
            func_021FB494(*(void **)(p + i * 4 + 12));
            *(void **)(p + i * 4 + 12) = 0;
        }
    }
    func_020409B4(4);
    BR_RES_ApplyBgSet(((struct Obj24620 *)q)->f8, 26);
    return 1;
}
