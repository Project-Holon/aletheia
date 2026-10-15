/*
 * function: STA_ACTING_TickActionTimers
 * address: 0x021F9A48
 * packet: pkt_ov132_021F9A48
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   STA_ACTING_ApplyAction 0x021F9754 thumb ov132
 *   STA_SLOT_SetValueByKey 0x021FD974 thumb ov132
 */
#include "../include/Obj08154.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int GFL_NET_IsParentAid(void);
extern void STA_ACTING_ApplyAction(char *p, unsigned int i, int v);
typedef unsigned int   u32;
extern void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value);
void STA_ACTING_TickActionTimers(char *p)
{
    u8 i;
    if (**(void ** *)&((struct Obj08154 *)p)->f30 != 0 && GFL_NET_IsParentAid() != 1) return;
    for (i = 0; i < 4; i++) {
        if (*(u16 *)(p + i * 2 + 0x124) != 0) {
            *(u16 *)(p + i * 2 + 0x124) -= 1;
            if (*(u16 *)(p + i * 2 + 0x124) == 0) {
                if (**(void ** *)&((struct Obj08154 *)p)->f30 == 0) STA_ACTING_ApplyAction(p, i, *(int *)(p + i * 4 + 0x12c));
                else STA_SLOT_SetValueByKey(**(void ** *)&((struct Obj08154 *)p)->f30, i, *(int *)(p + i * 4 + 0x12c));
            }
        }
    }
}
