/*
 * function: C_GEAR_FadeAccentColors
 * address:  0x021F0F28
 * packet:   pkt_ov029_021F0F28
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
#include "../include/Obj09786.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;

extern u16 d_021F31B6[];
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

void C_GEAR_FadeAccentColors(char *p, int flag)
{
    int c = 8;
    if (flag == 0)
        c = 0;
    PALANM_RequestFade(((struct Obj09786 *)p)->f210, 8, 0x3C0, -120, 0, c,
                  d_021F31B6[((struct Obj09786 *)p)->f459], ((struct Obj09786 *)p)->f204);
}
