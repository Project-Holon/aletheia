/*
 * function: STA_ACT_LIGHT_UpdateSprite
 * address: 0x021F718C
 * packet: pkt_ov112_021F718C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before 021F7204.
 * symbols:
 *   STA_ACT_LIGHT_SetSpritePos 0x021F732C thumb ov112
 *   STA_ACTING_GetElapsedTicks 0x021F9E44 thumb ov132
 *   MUSICAL_MCSS_UpdateObject 0x021F4990 thumb ov112
 */
#include "../include/Obj10318.h"
extern void STA_ACT_LIGHT_SetSpritePos(unsigned char *self, unsigned char *q);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 STA_ACTING_GetElapsedTicks(u8 *p);
extern void MUSICAL_MCSS_UpdateObject(int);
typedef struct { int pad[5]; int flag; } Record;
void STA_ACT_LIGHT_UpdateSprite(char *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1) {
            STA_ACT_LIGHT_SetSpritePos((unsigned char *)p, (unsigned char *)(p + 0x14 + i * 0x108));
            if (((struct Obj10318 *)p)->f4 != 0) {
                for (j = 0; j < STA_ACTING_GetElapsedTicks((u8 *)(((struct Obj10318 *)p)->f4)); j++) {
                    if (*(void (**)(char *, char *))(p + i * 0x108 + 0x118) != 0)
                        (*(void (**)(char *, char *))(p + i * 0x108 + 0x118))(p, p + 0x14 + i * 0x108);
                }
            }
        }
    }
    MUSICAL_MCSS_UpdateObject(((struct Obj10318 *)p)->f10);
}
