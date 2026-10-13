/*
 * function: ITEMMENU_TaskReturnToListAfterMessage
 * address:  0x021B7688
 * packet:   pkt_ov070_021B7688
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_020414EC  0x020414EC  arm
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj;

extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_020414EC(u32 i);
extern void ITEMMENU_RedrawList(char *p);
extern void ITEMMENU_MoveCursorToRow(char *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void ITEMMENU_ReturnToBagMain(void *p);

void ITEMMENU_TaskReturnToListAfterMessage(Obj *o)
{
    if ((func_020362DC() & 3) || TOUCHPANEL_GetTrg() != 0) {
        func_020414EC(3);
        o->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)o);
        o->f83E = 1;
        ITEMMENU_MoveCursorToRow((char *)o);
        func_0204B92C(o->f6A8, 1);
        ITEMMENU_UpdateSideButtons((int)o, 1);
        ITEMMENU_ReturnToBagMain(o);
    }
}
