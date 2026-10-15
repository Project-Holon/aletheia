/*
 * function: BOX2_SEQ_StateTaskMenu
 * address: 0x021E20D4
 * packet: pkt_ov170_021E20D4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   d_021EFA4C 0x021EFA4C data a4
 */
extern void APP_TASKMENU_UpdateMenu(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern int KEY_SetRepeatSpeed(int a0, int a1);
typedef struct { int (*a)(char *); int (*b)(char *); } Pair;
extern const Pair d_021EFA4C[];
#define W(p) (*(char **)((p) + 0x2C))
int BOX2_SEQ_StateTaskMenu(char *p)
{
    APP_TASKMENU_UpdateMenu(*(void **)(W(p) + 0x1A0));
    if (APP_TASKMENU_IsFinish(*(void **)(W(p) + 0x1A0)) == 1) {
        int r = APP_TASKMENU_GetCursorPos(*(void **)(W(p) + 0x1A0));
        APP_TASKMENU_CloseMenu(*(void **)(W(p) + 0x1A0));
        KEY_SetRepeatSpeed(6, 6);
        if (r == 0)
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].a(p);
        else
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].b(p);
    }
    return 7;
}
