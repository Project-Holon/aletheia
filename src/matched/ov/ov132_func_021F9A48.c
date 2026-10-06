/*
 * function: func_021F9A48
 * address: 0x021F9A48
 * packet: pkt_ov132_021F9A48
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_021F9754 0x021F9754 thumb ov132
 *   func_021FD974 0x021FD974 thumb ov132
 */
#include "../include/Obj08154.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int func_0203D378(void);
extern void func_021F9754(char *p, unsigned int i, int v);
typedef unsigned int   u32;
extern void func_021FD974(char *p, u32 key, u8 value);
void func_021F9A48(char *p)
{
    u8 i;
    if (**(void ** *)&((struct Obj08154 *)p)->f30 != 0 && func_0203D378() != 1) return;
    for (i = 0; i < 4; i++) {
        if (*(u16 *)(p + i * 2 + 0x124) != 0) {
            *(u16 *)(p + i * 2 + 0x124) -= 1;
            if (*(u16 *)(p + i * 2 + 0x124) == 0) {
                if (**(void ** *)&((struct Obj08154 *)p)->f30 == 0) func_021F9754(p, i, *(int *)(p + i * 4 + 0x12c));
                else func_021FD974(**(void ** *)&((struct Obj08154 *)p)->f30, i, *(int *)(p + i * 4 + 0x12c));
            }
        }
    }
}
