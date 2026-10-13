/*
 * function: ITEMMENU_HandleListTouch
 * address:  0x021B65E8
 * packet:   pkt_ov070_021B65E8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_MoveCursorDown  0x021B6300  thumb  ov070
 *   ITEMMENU_MoveCursorUp  0x021B6374  thumb  ov070
 *   ITEMMENU_MoveSlot  0x021B624C  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int ITEMMENU_GetItemCount(u8 *p);
extern int ITEMMENU_GetCursorIndex(u8 *p);
struct Obj;
extern int ITEMMENU_MoveCursorDown(struct Obj *o, int n, int k);
extern int ITEMMENU_MoveCursorUp(struct Obj *o, int n, int k);
extern void ITEMMENU_MoveSlot(void *o, int a, int b);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);

int ITEMMENU_HandleListTouch(u8 *p)
{
    u32 x, y;
    int k, a;
    u32 target;
    int n;
    u32 i;

    if (TOUCHPANEL_GetPointCont(&x, &y) == 1) {
        if (x < 0x90 || x > 0xE7 || y < 0xC || y > 0x9B)
            return 0;
        target = (y - 0xC) / 0x18;
        if (*(u32 *)&((struct Obj00002 *)p)->f810 == target)
            return 0;
        k = ITEMMENU_GetItemCount(p);
        a = ITEMMENU_GetCursorIndex(p);
        n = *(u32 *)&((struct Obj00002 *)p)->f810 - target;
        if (n < 0)
            n = -n;
        if (*(u32 *)&((struct Obj00002 *)p)->f810 < target) {
            for (i = 0; i < n; i++) {
                if (ITEMMENU_MoveCursorDown((struct Obj *)p, k, 0) == 0)
                    break;
            }
        } else if (*(u32 *)&((struct Obj00002 *)p)->f810 > target) {
            for (i = 0; i < n; i++) {
                if (ITEMMENU_MoveCursorUp((struct Obj *)p, k, 0) == 0)
                    break;
            }
        }
        if (i == 0)
            return 0;
        ITEMMENU_MoveSlot(p, a, ITEMMENU_GetCursorIndex(p));
        ITEMMENU_SetCursorActive((struct Obj *)p, 0);
        return 1;
    }
    return 0;
}
