/*
 * function: WIFI_BSUBWAY_GRAPHIC_EndBt
 * address: 0x021D7AC8
 * packet: pkt_ov116_021D7AC8
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D70EC 0x021D70EC thumb ov116
 *   DPW_BT_End 0x021C93BC arm ov114
 */
#include "../include/Obj13868.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021D70EC(u8 *, int *);
extern void DPW_BT_End(void);
int WIFI_BSUBWAY_GRAPHIC_EndBt(u8 *p)
{
    int result;
    if (((struct Obj13868 *)p)->fB68 == 0) return 1;
    if (func_021D70EC(p + 0x182c, &result)) {
        DPW_BT_End();
        ((struct Obj13868 *)p)->fB68 = 0;
        return 1;
    }
    return 0;
}
