/*
 * unit: yes
 * function: IRC_COMPATIBLE_MENU_ResetButtonPalettes,IRC_COMPATIBLE_MENU_ButtonCallback
 * address: 0x021B8724
 * packet: pkt_ov102_021B8724
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the 8-byte setter follower at 021B8794.
 * symbols:
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj07978.h"
#include "../include/Obj22167.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_FillTileMap(u32, u8, u8, u8, u8, u8);
extern void BG_SYS_PushTile(u32);
void IRC_COMPATIBLE_MENU_ResetButtonPalettes(u8 *p)
{
    int i;
    u32 win;
    u8 palette;
    u8 a, b, c, d;
    u16 *row;
    ((struct Obj07978 *)p)->f34 = 0;
    ((struct Obj07978 *)p)->f32 = 0;
    for (i = 0; i < ((struct Obj07978 *)p)->f2C; i++) {
        win = BMP_WIN_GetBgLayer((struct Descriptor *)(*(int *)(p + i * 4 + 4)));
        row = (u16 *)(*(u8 * *)&((struct Obj07978 *)p)->f28 + i * 12);
        a = row[1];
        b = row[2];
        c = row[3];
        d = row[4];
        switch (i) {
        case 0: palette = 11; break;
        case 1: palette = 4; break;
        }
        BG_SYS_FillTileMap(win, a, b, c, d, palette);
        BG_SYS_PushTile(win);
    }
}
void IRC_COMPATIBLE_MENU_ButtonCallback(u16 value, int flag, u8 *p)
{
    if (flag == 0) ((struct Obj22167 *)p)->f30 = value;
}
