/*
 * volatile: 021FF12E reads hardware register 04000304.
 * function: func_021FF118
 * address: 0x021FF118
 * packet: pkt_ov135_021FF118
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj05418.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
typedef unsigned char  u8;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
int func_021FF118(char *p)
{
    ++((struct Obj05418 *)p)->fD3C;
    if (WIPE_SYS_EndCheck()) {
        *(volatile u16 *)0x04000304 |= 0x8000;
        ((struct Obj05418 *)p)->fD3C = -16;
        if (((struct Obj05418 *)p)->fE1A) {
            ((struct Obj05418 *)p)->f28 = 2;
            func_021F4EC0((u8 *)p, 3, 16);
            ((struct Obj05418 *)p)->fD4 = 0;
        }
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj05418 *)p)->fD38, 0);
    }
    return 2;
}
