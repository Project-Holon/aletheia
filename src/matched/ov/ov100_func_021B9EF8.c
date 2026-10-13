/*
 * function: func_021B9EF8
 * address:  0x021B9EF8
 * packet:   pkt_ov100_021B9EF8
 * region:   ov100
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   func_021B95B8  0x021B95B8  thumb  ov100
 *   func_021BA290  0x021BA290  thumb  ov100
 *   func_021B9EA4  0x021B9EA4  thumb  ov100
 *   func_021B9DB8  0x021B9DB8  thumb  ov100
 */
#include "../include/Obj00060.h"

typedef unsigned short u16;

struct TaskMenu;
extern unsigned int APP_TASKMENU_IsFinish(struct TaskMenu *m);
typedef unsigned char  u8;
struct TaskMenu;
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
typedef unsigned int   u32;
struct Entry;
struct Link;
extern void func_02041B6C(u32 bit);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021BA290(int, int);
extern void func_021B9EA4(int a);
extern void func_021B9DB8(int a);

void func_021B9EF8(u8 *a)
{
    if (((struct Obj00060 *)a)->fCC0 != 0) {
        if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((struct Obj00060 *)a)->fCC0)) != 0) {
            APP_TASKMENU_GetCursorPos((const u8 *)(((struct Obj00060 *)a)->fCC0));
            APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj00060 *)a)->fCC0));
            ((struct Obj00060 *)a)->fCC0 = 0;
            func_02041B6C(6);
            func_021B95B8(a, (u32)((void (*)(void))func_021B9EA4));
            return;
        }
    } else {
        func_021BA290((int)a, 0);
        return;
    }
    {
        int k = 0xc;

        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x78, k) != 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), k << 8, 4, (u32)(a + 0x24c)) != 0) {
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x7c, k);
                func_021B95B8(a, (u32)((void (*)(void))func_021B9DB8));
            }
        }
    }
}
