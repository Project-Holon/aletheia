/*
 * function: POKETRADE_SAVE_ShowTimeIcon
 * address: 0x021E1030
 * packet: pkt_ov119_021E1030
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 */
#include "../include/Obj00001.h"
typedef unsigned char  u8;
extern void TIME_ICON_Delete(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);
void POKETRADE_SAVE_ShowTimeIcon(char *p)
{
    if (((struct Obj00001 *)p)->f5F0) {
        TIME_ICON_Delete(((struct Obj00001 *)p)->f5F0);
        ((struct Obj00001 *)p)->f5F0 = 0;
    }
    ((struct Obj00001 *)p)->f5F0 = TIME_ICON_CreateNode((u32)(((struct Obj00001 *)p)->f744), ((struct Obj00001 *)p)->f71C, 0xF, 0x10, ((struct Obj00001 *)p)->f5F4);
}
