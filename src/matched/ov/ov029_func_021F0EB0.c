/*
 * function: func_021F0EB0
 * address:  0x021F0EB0
 * packet:   pkt_ov029_021F0EB0
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
#include "../include/Obj05115.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;

extern u16 d_021F31B6[];
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

void func_021F0EB0(char *p, int flag)
{
    int c = 8;
    if (flag == 0)
        c = 0;
    PALANM_RequestFade(((struct Obj05115 *)p)->f210, 8, 0xFFFF, -120, 0, c,
                  d_021F31B6[((struct Obj05115 *)p)->f459], ((struct Obj05115 *)p)->f204);
    PALANM_RequestFade(((struct Obj05115 *)p)->f210, 2, 0x3E, -120, 0, c,
                  d_021F31B6[((struct Obj05115 *)p)->f459], ((struct Obj05115 *)p)->f204);
}
