/*
 * unit: yes
 * function: ZUKAN_DETAIL_VOICE_SetActorsAlphaMode, ZUKAN_DETAIL_FORM_SetHeapId
 * address: 0x021C3B14
 * packet: pkt_ov208_021C3B14
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb ov208
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *p, u32 on);
extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);
void ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(void *unused, u8 *p, int a2)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (*(struct Actor **)(p + i * 4 + 0x54))
            CLACT_SetActorObjMode(*(struct Actor **)(p + i * 4 + 0x54), 1);
    }
    for (i = 0; i < 6; i++)
        CLACT_SetActorObjMode(*(struct Actor **)(p + i * 4 + 0x9c), 1);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(*(int * *)&((struct Obj00146 *)p)->fC0);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(*(int * *)&((struct Obj00146 *)p)->fC4);
}
void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value)
{
    *p = value;
}
