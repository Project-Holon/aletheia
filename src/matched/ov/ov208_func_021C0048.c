/*
 * function: func_021C0048
 * address: 0x021C0048
 * packet: pkt_ov208_021C0048
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 *   d_021C8670 0x021C8670 data a2
 */
#include "../include/Obj25495.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 TOWNMAP_GRH_GetTownInfoValue(char *, int, int);
extern const u16 d_021C8670[];
void func_021C0048(u16 *unused, char *p, int a2)
{
    u8 i;
    for (i = 0; i < 61; i++) {
        u16 value = TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj25495 *)p)->f3C8, i, 0);
        u8 j;
        for (j = 0; j < 61; j++) {
            if (value == d_021C8670[j]) {
                *(u8 *)(p + i + 0x3cc) = j;
                break;
            }
        }
    }
}
