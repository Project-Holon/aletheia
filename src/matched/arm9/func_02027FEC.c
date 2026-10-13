/*
 * function: APP_TASKMENU_WIN_Create
 * address:  0x02027FEC
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_WIN_CreateEx  0x0202800C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);

u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5)
{
    return (u32)APP_TASKMENU_WIN_CreateEx(a0, a1, a2, a3, a4, 3, 0, 0, a5);
}
