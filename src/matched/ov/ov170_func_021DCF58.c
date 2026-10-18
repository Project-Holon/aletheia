/*
 * function: BOX2_MAIN_OpenTaskMenu
 * address:  0x021DCF58
 * packet:   pkt_ov170_021DCF58
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetCursorPos 0x02027CFC thumb
 *
 * Opens the two-item yes/no task menu (items at work+0x184) with cursor sel.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 heapId;
    u8 count;
    u8 pad05[3];
    const void *items;
    u32 unk0c;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} MenuTmpl;

struct Sound;
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void UI_SetInputMode(u8 v);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void APP_TASKMENU_SetCursorPos(u8 *p, int sel);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_MAIN_OpenTaskMenu(unsigned char *p, int sel)
{
    MenuTmpl t;
    t.heapId = 0x4C;
    t.count = 2;
    t.items = WORK(p) + 0x184;
    t.unk0c = 1;
    t.x = 0x20;
    t.y = 0x12;
    t.w = 8;
    t.h = 3;
    if (CURSOR_MOVE_GetState(*(void **)(WORK(p) + 0x70)) == 1)
        UI_SetInputMode(0);
    else
        UI_SetInputMode(1);
    *(void **)(WORK(p) + 0x1A0) = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), *(void **)(WORK(p) + 0x19C));
    APP_TASKMENU_SetCursorPos(*(void **)(WORK(p) + 0x1A0), sel);
}
