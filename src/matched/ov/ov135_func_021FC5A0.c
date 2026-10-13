/*
 * function: func_021FC5A0
 * address: 0x021FC5A0
 * packet: pkt_ov135_021FC5A0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200ADB4 0x0200ADB4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021FC810 0x021FC810 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00018.h"

typedef unsigned int u32;
extern void *func_0200ADB4(void *);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
typedef unsigned char  u8;
extern void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
int func_021FC5A0(char *p)
{
    void *q;
    q = func_0200ADB4(**(void ** *)&((struct Obj00018 *)p)->f0);
    if ((KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg()) {
        func_021FC810((u8 *)p, 5, 1, 0, 0xf0f, q);
        func_021F4E98((u8 *)p, 3, 7);
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } else if (KEY_GetTrg() & 2) {
        *(int *)&((struct Obj00018 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
    return 2;
}
