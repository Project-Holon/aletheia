/*
 * function: ITEMMENU_TaskWaitMessageDismiss
 * address:  0x021B7C88
 * packet:   pkt_ov070_021B7C88
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskReturnToListFromQuantity  0x021B7CD0  thumb  ov070
 */

typedef unsigned int u32;

typedef struct Obj Obj;

extern int ITEMMENU_IsMessageFinished(int p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskReturnToListFromQuantity(struct Obj *o);

void ITEMMENU_TaskWaitMessageDismiss(Obj *o)
{
    if (ITEMMENU_IsMessageFinished((int)o) == 0)
        return;
    if (KEY_GetTrg() & 3) {
        ITEMMENU_SetCursorActive(o, 1);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskReturnToListFromQuantity));
        return;
    }
    if (TOUCHPANEL_GetTrg() != 0) {
        ITEMMENU_SetCursorActive(o, 0);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskReturnToListFromQuantity));
    }
}
