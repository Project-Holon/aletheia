/*
 * unit: yes
 * function: func_021BCF6C, func_021BCF8C, func_021BCF98
 * address: 0x021BCF6C
 * packet: pkt_ov099_021BCF6C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BC06C 0x021BC06C thumb ov099
 */
#include "../include/Obj04412.h"
#include "../include/Obj22035.h"
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern void func_021BC06C(char *);
int func_021BCF6C(char *p, int ret)
{
    if (KEY_GetTrg() != 0) {
        func_021BC06C(p);
        ((struct Obj04412 *)p)->f1CC = 0x7C;
    }
    return ret;
}
int func_021BCF8C(char *p, int ret)
{
    ((struct Obj22035 *)p)->f1CC = 0x60;
    return ret;
}
int func_021BCF98(char *p, int ret)
{
    return ret;
}
