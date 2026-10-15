/*
 * function: BR_RES_ApplyBgSet
 * address: 0x021FBDA4
 * packet: pkt_ov186_021FBDA4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned int   u32;
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_PushTile(u32 index);
void BR_RES_ApplyBgSet(int a,unsigned mode)
{
    switch(mode){
    case 24:
        BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);
        BG_SYS_ClearSlot(5);BG_SYS_PushTile(5);break;
    case 0:BG_SYS_ClearSlot(3);BG_SYS_PushTile(3);break;
    case 1:BG_SYS_ClearSlot(6);BG_SYS_PushTile(6);break;
    case 2:BG_SYS_ClearSlot(0);BG_SYS_PushTile(0);break;
    case 5:case 9:case 15:case 20:case 21:case 22:case 23:case 26:case 27:case 28:case 29:case 30:
        BG_SYS_ClearSlot(5);BG_SYS_PushTile(5);break;
    case 3:case 4:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 16:case 17:case 18:case 19:case 25:
        BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);break;
    case 14:break;
    }
}
