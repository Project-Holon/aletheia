/*
 * function: BEACON_VIEW_UpdateTaskMenuButtons
 * address:  0x021F0C70
 * packet:   pkt_ov032_021F0C70
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_UpdateTaskMenuButtons  0x021F0C70  thumb
 *   APP_TASKMENU_WIN_IsUpdateTrans  0x0202846C  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   BEACON_VIEW_PlaySe  0x021F0DD8  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 APP_TASKMENU_WIN_IsUpdateTrans(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 APP_TASKMENU_WIN_IsTouch(void **p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void BEACON_VIEW_PlaySe(unsigned int a);

int BEACON_VIEW_UpdateTaskMenuButtons(char *p, int flag)
{
    int s;
    char *q;
    int n;
    int i;

    s = -1;
    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
    } else {
        q = p + 0xf0;
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (APP_TASKMENU_WIN_IsUpdateTrans(*(u8 **)(q + i * 16)) == 1) {
            APP_TASKMENU_WIN_Update((u8 *)(*(u32 *)(q + i * 16)));
            return -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (APP_TASKMENU_WIN_IsTouch((void **)(*(u32 **)(q + i * 16))) != 0) {
            if (i < n - 1) {
                BEACON_VIEW_PlaySe(0x54c);
                s = i;
            } else {
                APP_TASKMENU_WIN_SetDecide(*(char **)(q + i * 16), 1);
                BEACON_VIEW_PlaySe(0x54c);
                s = i;
            }
        }
        APP_TASKMENU_WIN_Update((u8 *)(*(u32 *)(q + i * 16)));
    }
    return s;
}
