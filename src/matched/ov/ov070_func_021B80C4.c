/*
 * function: ITEMMENU_SetCursorActive
 * address:  0x021B80C4
 * packet:   pkt_ov070_021B80C4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355D8  0x020355D8  arm
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   ITEMMENU_UpdateSlotActorPosition  0x021BB398  thumb  ov070
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   ITEMMENU_SetMoveTypeIconsVisible  0x021B97E8  thumb  ov070
 */

typedef unsigned char u8;

typedef struct Obj {
    unsigned char pad000[0x81C];
    int f81C;
    unsigned char pad820[0x850 - 0x820];
    void *f850;
} Obj;

struct CodeIn;
extern void func_020355D8(u8 v);
extern int ITEMMENU_GetItemCount(u8 *p);
typedef unsigned int   u32;
extern void ITEMMENU_UpdateSlotActorPosition(int p, u32 val);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern void ITEMMENU_SetMoveTypeIconsVisible(char *p, int mode);

void ITEMMENU_SetCursorActive(Obj *o, int flag)
{
    if (o->f81C == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (ITEMMENU_GetItemCount((u8 *)o) == 0)
        flag = 0;
    if (flag == 0) {
        ITEMMENU_UpdateSlotActorPosition((int)o, 0);
    } else {
        ITEMMENU_UpdateSlotActorPosition((int)o, 1);
        BLINK_PALANM_ResetPhase(o->f850);
    }
    ITEMMENU_SetMoveTypeIconsVisible((char *)o, flag);
}
