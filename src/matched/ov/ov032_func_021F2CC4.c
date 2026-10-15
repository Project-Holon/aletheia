/*
 * function: BEACON_VIEW_DeleteTaskMenuRes
 * address:  0x021F2CC4
 * packet:   pkt_ov032_021F2CC4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_DeleteTaskMenuRes 0x021F2CC4 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 */
#include "../include/Obj00812.h"

typedef unsigned char  u8;
struct TaskMenuState;
struct U16Vec;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern int APP_KEYCURSOR_Delete(int a0);

void BEACON_VIEW_DeleteTaskMenuRes(char *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(p + i * 16 + 0xf0) != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(*(int *)(p + i * 16 + 0xf0)));
        }
        STRBUF_Delete((struct U16Vec *)(*(int *)(p + i * 16 + 0xf4)));
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 16 + 0xc0) != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(*(int *)(p + i * 16 + 0xc0)));
        }
        STRBUF_Delete((struct U16Vec *)(*(int *)(p + i * 16 + 0xc4)));
    }
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj00812 *)p)->fB8));
    APP_KEYCURSOR_Delete(((struct Obj00812 *)p)->fBC);
}
