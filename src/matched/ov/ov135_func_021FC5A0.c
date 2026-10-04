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
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021FC810 0x021FC810 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj00018.h"

typedef unsigned int u32;
extern void *func_0200ADB4(void *);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021FC810(void *, unsigned, unsigned, unsigned, unsigned, void *);
extern void func_021F4E98(void *, unsigned, unsigned);
extern void func_021F4EC0(void *, unsigned, unsigned);
extern void func_020061E4(unsigned);
int func_021FC5A0(char *p)
{
    void *q;
    q = func_0200ADB4(**(void ** *)&((struct Obj00018 *)p)->f0);
    if ((func_020362DC() & 1) || func_02035C60()) {
        func_021FC810(p, 5, 1, 0, 0xf0f, q);
        func_021F4E98(p, 3, 7);
        func_020061E4(0x54c);
    } else if (func_020362DC() & 2) {
        *(int *)&((struct Obj00018 *)p)->f28 = 2;
        func_021F4EC0(p, 1, 0);
        func_020061E4(0x551);
    }
    return 2;
}
