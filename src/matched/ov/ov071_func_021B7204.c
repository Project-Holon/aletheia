/*
 * function: func_021B7204
 * address: 0x021B7204
 * packet: pkt_ov071_021B7204
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 */
typedef unsigned char u8;
extern void APP_TASKMENU_UpdateMenu(void *);
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
int func_021B7204(int a, int b, void *p, int *q) { APP_TASKMENU_UpdateMenu(p); if(APP_TASKMENU_IsFinish(p)==1) { *q=APP_TASKMENU_GetCursorPos(p)==0 ? 1 : 0;return 1;} return 0; }
