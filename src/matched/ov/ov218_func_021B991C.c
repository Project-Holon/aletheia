/*
 * function: UN_SELECT_UpdateTaskMenu
 * address: 0x021B991C
 * packet: pkt_ov218_021B991C
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Obj Obj;
extern void APP_TASKMENU_UpdateMenu(Obj *);
void UN_SELECT_UpdateTaskMenu(Obj *p)
{
    APP_TASKMENU_UpdateMenu(p);
}
