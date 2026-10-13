/*
 * function: GIMMICK_OBJ_ELBOARD_FillMessages
 * address:  0x021F3D78
 * packet:   pkt_021F3D78
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_GIMMICK_GATE_HasMessagesToShow  0x021F3A70  thumb
 *   GIMMICK_OBJ_ELBOARD_FillSavedListMessages  0x021F3DF0  thumb
 *   func_021F3D24  0x021F3D24  thumb
 *   GIMMICK_OBJ_ELBOARD_FillNoticeMessages  0x021F3E2C  thumb
 *   GIMMICK_OBJ_ELBOARD_FillDefaultMessages  0x021F3DA8  thumb
 */

typedef unsigned char  u8;
extern int FIELD_GIMMICK_GATE_HasMessagesToShow(u8 *p);
extern void GIMMICK_OBJ_ELBOARD_FillSavedListMessages(u8 *p);
extern int  func_021F3D24(void *p);
extern void GIMMICK_OBJ_ELBOARD_FillNoticeMessages(u8 *p);
extern void GIMMICK_OBJ_ELBOARD_FillDefaultMessages(u8 *p);

void GIMMICK_OBJ_ELBOARD_FillMessages(void *p)
{
    if (FIELD_GIMMICK_GATE_HasMessagesToShow(p) == 1) {
        GIMMICK_OBJ_ELBOARD_FillSavedListMessages(p);
        return;
    }
    if (func_021F3D24(p) != 0) {
        GIMMICK_OBJ_ELBOARD_FillNoticeMessages(p);
        return;
    }
    GIMMICK_OBJ_ELBOARD_FillDefaultMessages(p);
}
