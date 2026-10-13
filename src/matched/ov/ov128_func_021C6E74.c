/*
 * function: func_021C6E74
 * address: 0x021C6E74
 * packet: pkt_ov128_021C6E74
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void APP_TASKMENU_UpdateMenu(void *);
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
int func_021C6E74(u8 *p) {int n;APP_TASKMENU_UpdateMenu(p);if(APP_TASKMENU_IsFinish((struct TaskMenu *)p)==1) {n=APP_TASKMENU_GetCursorPos(p);APP_TASKMENU_CloseMenu((struct TaskMenu *)p);return n;}return -1;}
