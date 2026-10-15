/*
 * function: BOX2_SEQ_StateUseItemWait
 * address: 0x021E90D4
 * packet: pkt_ov170_021E90D4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_MAIN_ResetMovers 0x021DE728 thumb ov170
 *   BOX2_SEQ_ResetActorAffine 0x021EC94C thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 */
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_MAIN_ResetMovers(unsigned char *p);
extern void BOX2_SEQ_ResetActorAffine(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u8 func_020355C4(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_SEQ_StateUseItemWait(unsigned char *p)
{
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    BOX2_MAIN_ResetMovers(p);
    BOX2_SEQ_ResetActorAffine(*(char **)(WORK(p) + 0xA190));
    if (func_020355C4() == 1) {
        CURSOR_MOVE_SetState(*(void **)(WORK(p) + 0x70), 0);
    } else {
        CURSOR_MOVE_SetState(*(void **)(WORK(p) + 0x70), 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
    }
    return 0x5A;
}
