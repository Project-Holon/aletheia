/*
 * function: ITEMMENU_HandleScrollbarTouch
 * address:  0x021B63F8
 * packet:   pkt_ov070_021B63F8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   COMM_HISTORY_ScaleValue  0x0202EDE4  thumb
 *   ITEMMENU_UpdateCursorFromTouch  0x021BA654  thumb  ov070
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int ITEMMENU_GetItemCount(u8 *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int TOUCHPANEL_GetTrg(void);
struct Obj;
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern u32 COMM_HISTORY_ScaleValue(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void ITEMMENU_UpdateCursorFromTouch(char *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

u32 ITEMMENU_HandleScrollbarTouch(u8 *p)
{
    u32 x, y, old;
    int k;

    k = ITEMMENU_GetItemCount(p);
    if (k >= 7 && TOUCHPANEL_GetPointCont(&x, &y) == 1) {
        if (x >= 0x100 || x < 0xE0)
            return 0;
        if (((struct Obj00002 *)p)->f85C == 0) {
            if (TOUCHPANEL_GetTrg() == 1) {
                if (y < 0x10 || y >= 0x98)
                    return 0;
                ((struct Obj00002 *)p)->f85C = 1;
            } else
                return 0;
        }
        ITEMMENU_SetCursorActive((struct Obj *)p, 0);
        old = *(u32 *)&((struct Obj00002 *)p)->f814;
        *(u32 *)&((struct Obj00002 *)p)->f814 = COMM_HISTORY_ScaleValue(k - 6, y, 0x1A, 0x8E, 0) - 1;
        ITEMMENU_UpdateCursorFromTouch((char *)p);
        if (*(u32 *)&((struct Obj00002 *)p)->f814 != old) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 1;
        }
    }
    return 0;
}
