/*
 * function: C_GEAR_StartFadeOut
 * address:  0x021F0F70
 * packet:   pkt_ov029_021F0F70
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_RequestFade  0x0202173C  thumb
 *   d_021F31B6     0x021F31B6  data  a2
 */
#include "../include/Obj00106.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;

extern u16 d_021F31B6[];
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

void C_GEAR_StartFadeOut(char *p)
{
    PALANM_RequestFade(((struct Obj00106 *)p)->f210, 8, 0xFFFF, 1, 0, 0x10,
                  d_021F31B6[((struct Obj00106 *)p)->f459], ((struct Obj00106 *)p)->f204);
}
