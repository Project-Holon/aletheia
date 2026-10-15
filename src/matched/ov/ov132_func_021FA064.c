/*
 * function: STA_ACT_AUDIENCE_Update
 * address: 0x021FA064
 * packet: pkt_ov132_021FA064
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: compiled ends 021FA0CE; two zero padding bytes before labelled 021FA0D0.
 * symbols:
 *   STA_ACTING_GetCameraPos 0x021F9DFC thumb ov132
 *   func_02005728 0x02005728 thumb
 *   STA_ACT_AUDIENCE_DrawRecord 0x021FA3A8 thumb ov132
 *   STA_ACT_AUDIENCE_ApplyChoices 0x021FA4AC thumb ov132
 *   STA_ACT_AUDIENCE_UpdateRecords 0x021FA27C thumb ov132
 */
#include "../include/Obj10539.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 STA_ACTING_GetCameraPos(void *p);
extern unsigned func_02005728(unsigned);
extern void STA_ACT_AUDIENCE_DrawRecord(char *p, u8 *rec, unsigned type);
extern void STA_ACT_AUDIENCE_ApplyChoices(char *);
extern void STA_ACT_AUDIENCE_UpdateRecords(char *);
void STA_ACT_AUDIENCE_Update(char *p)
{
    u8 i;
    if (STA_ACTING_GetCameraPos(((struct Obj10539 *)p)->f1E8) == 0) {
        if (func_02005728(10) == 0) {
            for (i = 0; i < 3; i++) {
                u8 a = func_02005728(4);
                u8 b = func_02005728(60);
                STA_ACT_AUDIENCE_DrawRecord(p, (u8 *)(p + 0x204 + b * 8), a);
            }
        }
    } else {
        if (((struct Obj10539 *)p)->f200 == 1) {
            STA_ACT_AUDIENCE_ApplyChoices(p);
            ((struct Obj10539 *)p)->f200 = 0;
        }
        STA_ACT_AUDIENCE_UpdateRecords(p);
    }
}
