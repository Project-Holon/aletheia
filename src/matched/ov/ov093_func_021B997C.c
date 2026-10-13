/*
 * function: BTL_MAIN_GetClientVoiceFlag
 * address: 0x021B997C
 * packet: pkt_ov093_021B997C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetOwnsSlots 0x021B9114 thumb ov093
 *   func_02007B50 0x02007B50 thumb
 *   func_02007C70 0x02007C70 thumb
 */
#include "../include/Obj13279.h"
typedef unsigned char u8;
extern u8 BTL_MAIN_GetOwnsSlots(u8 **);
typedef unsigned int   u32;
struct PerapVoice;
extern void *func_02007B50(void **p);
extern u32 func_02007C70(struct PerapVoice *p);
int BTL_MAIN_GetClientVoiceFlag(u8 *p, unsigned int i)
{
    if (BTL_MAIN_GetOwnsSlots((u8 **)p) == 0) {
        unsigned int q = (unsigned int)p + 0x3e0;
        if (*(void **)(q + i * 4) != 0 && func_02007B50(*(void **)(q + i * 4)) != 0)
            return func_02007C70(*(void **)(q + i * 4));
        return 0;
    }
    return *(u8 *)((unsigned int)*(u8 * *)&((struct Obj13279 *)p)->f0 + i + 0x44);
}
