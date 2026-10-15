/*
 * function: ITEMMENU_TaskReturnToListFromQuantity
 * address:  0x021B7CD0
 * packet:   pkt_ov070_021B7CD0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   ITEMMENU_LeaveQuantityMode  0x021BB0BC  thumb  ov070
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj;

typedef unsigned int   u32;
extern void BG_SYS_ClearSlot(u32 i);
extern void ITEMMENU_RedrawList(char *p);
extern void ITEMMENU_MoveCursorToRow(char *p);
extern void ITEMMENU_LeaveQuantityMode(char *p);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void ITEMMENU_ReturnToBagMain(void *p);

void ITEMMENU_TaskReturnToListFromQuantity(Obj *o)
{
    BG_SYS_ClearSlot(3);
    o->f818 = 0xFFFF;
    ITEMMENU_RedrawList((char *)o);
    o->f83E = 1;
    ITEMMENU_MoveCursorToRow((char *)o);
    ITEMMENU_LeaveQuantityMode((char *)o);
    CLACT_SetActorAutoAnim(o->f6A8, 1);
    ITEMMENU_UpdateSideButtons((int)o, 1);
    ITEMMENU_ReturnToBagMain(o);
}
