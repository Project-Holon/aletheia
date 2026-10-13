/*
 * function: IRCBATTLEMENU_SetSubPaletteActive
 * address:  0x02196228
 * packet:   pkt_ov021_02196228
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 *   IRCBATTLEMENU_FadePaletteBank  0x021961A4  thumb  ov021
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void MI_CpuCopy8(void *dst, u32 src, u32 size);
extern void func_0207E5D0(u32 p, u32 a, u32 size);
extern void func_0207E468(u32 p, u32 a, u32 size);
extern void IRCBATTLEMENU_FadePaletteBank(u8 *p, u32 a, u32 b);

void IRCBATTLEMENU_SetSubPaletteActive(u8 *p, int flag)
{
    if (flag) {
        MI_CpuCopy8((void *)0x05000600, ((struct Obj00094 *)p)->f2EC, 0x200);
        MI_CpuCopy8((void *)0x05000400, ((struct Obj00094 *)p)->f2F0, 0x200);
        IRCBATTLEMENU_FadePaletteBank(p, 3, 0xE);
        IRCBATTLEMENU_FadePaletteBank(p, 1, 9);
    } else {
        func_0207E5D0(((struct Obj00094 *)p)->f2EC, 0, 0x1C0);
        func_0207E468(((struct Obj00094 *)p)->f2F0, 0, 0x120);
    }
}
