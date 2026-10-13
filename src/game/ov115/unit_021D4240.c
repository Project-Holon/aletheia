/*
 * file:     unit_021D4240.c
 * unit:     yes
 * function: func_021D4240, func_021D426C, func_021D4270, func_021D4290, func_021D4298, func_021D429C
 * address:  0x021D4240
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   d_021D6640 0x021D6640 data a4
 */
#include "../../matched/include/Obj22580.h"
#include "../../matched/include/Obj22581.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int func_021D4240(u8 *p);
void func_021D426C(u8 *p, u32 v);
void func_021D4270(u32 a, u32 b, u32 c, u8 *p, u32 id);

int func_021D4240(u8 *p) { if(KEY_GetTrg()&3) return 1; if(*(int *)(((struct Obj22580 *)p)->f40+4) && TOUCHPANEL_GetTrg()) return 1; return 0; }


void func_021D426C(u8 *p, u32 v) { ((struct Obj22581 *)p)->f0 = v; }


void func_021D4270(u32 a, u32 b, u32 c, u8 *p, u32 id)
{
    if (id == GFL_NET_HANDLE_GetCurrentHandle() && a != GFL_NET_SYSTEM_GetCurrentAid()) {
        *(u32 *)(p + 0x1c) = 1;
    }
}


extern u8 d_021D6640[];
u8 *func_021D4290(void)
{
    return d_021D6640;
}


int func_021D4298(void)
{
    return 4;
}


int func_021D429C(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}
