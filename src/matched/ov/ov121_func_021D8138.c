/*
 * function: MYSTERY_CreateSaveMenu
 * address: 0x021D8138
 * packet: pkt_ov121_021D8138
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D8196.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_UTIL_CreateMenu 0x021DA038 thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int f0, f4, f8, fc, f10, f14, f18; u16 f1c, f1e, f20, f22; } Config;
extern void MI_CpuFill8(void *, int, int);
extern void *MYSTERY_UTIL_CreateMenu(Config *, int);
void MYSTERY_CreateSaveMenu(u8 *p, int unused, int heap)
{
    Config c;
    if (*(int *)&((struct Obj00326 *)p)->f260 == 0) {
        MI_CpuFill8(&c, 0, 0x24);
        c.f0 = ((struct Obj00326 *)p)->f3A4;
        c.f4 = *(int *)&((struct Obj00326 *)p)->f398;
        c.f8 = *(int *)&((struct Obj00326 *)p)->f39C;
        c.fc = 0x54;
        c.f10 = 0x55;
        c.f18 = 2;
        c.f1c = 0;
        c.f1e = 15;
        c.f20 = 14;
        c.f22 = 1;
        ((struct Obj00326 *)p)->f260 = MYSTERY_UTIL_CreateMenu(&c, heap);
    }
}
