/*
 * function: FIELD_SOUND_SYSTEM_StepBgmLoading
 * address:  0x02029434
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_StepBgmLoading.c \\
 *       --func FIELD_SOUND_SYSTEM_StepBgmLoading --addr 0x02029434 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 */
#include "../include/Obj00164.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern void func_0203D12C(int a);

u32 FIELD_SOUND_SYSTEM_StepBgmLoading(u8 *p)
{
    u32 r = GFL_USE_StepBgmLoad((u8 *)(((struct Obj00164 *)p)->f10), (u32 *)((u32)(p + 0x14)), 0);

    func_0203D12C(2);
    if (r != 0) {
        ((struct Obj00164 *)p)->f8 = ((struct Obj00164 *)p)->f10;
        ((struct Obj00164 *)p)->f10 = 0;
    }
    return r;
}
