/*
 * function: BOX2_SEQ_GotoSlotHandlerA
 * address:  0x021E9E7C
 * packet:   pkt_ov170_021E9E7C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb
 */

struct WinMgr;
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_SceneWaitScroll(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_GotoSlotHandlerA(char *p, unsigned char i, int v)
{
    p[0x16] = i;
    *(unsigned char *)(WORK(p) + 0xA172) = 1;
    BOX2_SEQ_SetSlotDrawPriority(WORK(p), (unsigned char)p[0x16], 1);
    BOX2_SEQ_RefreshCursorSlot(p);
    BOX2_UI_CloseListPack(*(struct WinMgr **)(WORK(p) + 0x74));
    BOX2_SEQ_SetSeqThird(p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState(p, v));
}
