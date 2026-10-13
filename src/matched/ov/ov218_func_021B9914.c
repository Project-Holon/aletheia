/*
 * function: func_021B9914
 * address: 0x021B9914
 * packet: pkt_ov218_021B9914
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
void func_021B9914(struct TaskMenu *p)
{
    APP_TASKMENU_CloseMenu(p);
}
