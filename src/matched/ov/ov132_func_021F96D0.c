/*
 * function: func_021F96D0
 * address: 0x021F96D0
 * packet: pkt_ov132_021F96D0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj23190.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021F96D0(char *p)
{
    u8 i;
    u8 min = 255;
    char *a = *(char * *)&((struct Obj23190 *)p)->f30;
    for (i = 0; i < 4; i++) {
        u16 v = *(u16 *)(*(char **)(a + i * 4 + 4) + 0x4a) + *(u8 *)(p + i + 0xf7);
        if (min > v) min = v;
    }
    if (min >= 70) GFL_USE_PlaySeDefaultVolume(1578);
    else if (min >= 30) GFL_USE_PlaySeDefaultVolume(1579);
    else if (min >= 1) GFL_USE_PlaySeDefaultVolume(1580);
}
