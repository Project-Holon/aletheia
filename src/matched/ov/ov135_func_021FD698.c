/*
 * function: WORLDTRADE_LIST_StateScrollIn
 * address: 0x021FD698
 * packet: pkt_ov135_021FD698
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021FD6B0 reads hardware register 04000304.
 * symbols:
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj10587.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern u32 WIPE_SYS_EndCheck(void);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
int WORLDTRADE_LIST_StateScrollIn(unsigned char *p)
{
    --((struct Obj10587 *)p)->fD3C;
    if (WIPE_SYS_EndCheck()) {
        *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
        ((struct Obj10587 *)p)->f28 = 2;
        WORLDTRADE_SetStateAndReturn(p, 4, 15);
        ((struct Obj10587 *)p)->fD3C = 16;
    }
    return 2;
}
