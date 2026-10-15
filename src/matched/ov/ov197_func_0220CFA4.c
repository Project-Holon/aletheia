/*
 * function: B_BAG_MAIN_StateChangeCount
 * address: 0x0220CFA4
 * packet: pkt_ov197_0220CFA4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: narrow value load then compound add before reading maximum fixes r0/r6 swap.
 * symbols:
 *   B_BAG_MAIN_DrawPocket 0x0220B520 thumb ov197
 *   B_BAG_MAIN_DrawHeader 0x0220B584 thumb ov197
 */
#include "../include/Obj00314.h"
typedef signed char s8;
typedef unsigned char u8;
extern void B_BAG_MAIN_DrawPocket(char *);
extern void B_BAG_MAIN_DrawHeader(char *p);
int B_BAG_MAIN_StateChangeCount(char *p)
{
    unsigned index = ((struct Obj00314 *)p)->f533;
    short *values = (short *)(*(char * *)&((struct Obj00314 *)p)->f0 + 0x38);
    s8 value = (s8)values[index];
    u8 maximum;
    value += ((struct Obj00314 *)p)->f534;
    maximum = *(u8 *)(p + index + 0x539);
    if (value > maximum) value = 0;
    else if (value < 0) {
        values[index] = maximum;
        goto done;
    }
    values[index] = value;
done:
    B_BAG_MAIN_DrawPocket(p);
    B_BAG_MAIN_DrawHeader(p);
    return 12;
}
