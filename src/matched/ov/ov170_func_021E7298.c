/*
 * function: BOX2_SEQ_StateMoveItemC
 * address: 0x021E7298
 * packet: pkt_ov170_021E7298
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020260E4 has no outside code-start witness. Scratch one EXACT.
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 * symbols:
 *   BOX2_SEQ_DeleteB 0x021EA750 thumb ov170
 *   BOX2_SEQ_PrintPromptB 0x021EBCB4 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   func_0202136C 0x0202136C thumb
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
#define W(p) (*(u8 **)((p) + 44))
struct Sound;
extern void BOX2_SEQ_DeleteB(char *p);
extern void BOX2_SEQ_PrintPromptB(u8 *, int, int);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern unsigned func_0202136C(u16);
extern void BOX2_SEQ_SetSlotActorMode(char *p, int i, int f);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_SetActorAffineMode(char *p, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);
int BOX2_SEQ_StateMoveItemC(u8 *p)
{
    u16 *pair = *(u16 **)(W(p) + 96);
    u16 item = *(u16 *)(W(p) + 0xa16c);
    u16 second;
    if (item == 0) {
        BOX2_SEQ_DeleteB((char *)p);
        BOX2_SEQ_PrintPromptB(p, 0, 24);
        func_020260E4(*(void **)(W(p) + 112), 10);
        BOX2_UI_SetCursorPos((char **)p, 10);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        return 70;
    }
    if (pair[0] == p[22]) {
        second = pair[1];
        BOX2_SEQ_DeleteB((char *)p);
        func_020260E4(*(void **)(W(p) + 112), 9);
        BOX2_UI_SetCursorPos((char **)p, 9);
        if (func_0202136C(*(u16 *)(W(p) + 0xa16c)) == 1 && second != p[22]) {
            BOX2_SEQ_SetSlotActorMode((char *)W(p), p[22], 0);
            BOX2_SEQ_PrintPromptB(p, 7, 24);
            GFL_USE_PlaySeDefaultVolume(0x557);
            *(int *)(p + 40) = 14;
            return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
        }
        BOX2_SEQ_PrintPromptB(p, 1, 24);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        return 70;
    }
    if (func_0202136C(item) == 1) {
        BOX2_SEQ_DeleteB((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetSlotActorMode((char *)W(p), p[22], 0);
        BOX2_SEQ_PrintPromptB(p, 7, 24);
        GFL_USE_PlaySeDefaultVolume(0x557);
        func_020260E4(*(void **)(W(p) + 112), 9);
        BOX2_UI_SetCursorPos((char **)p, 9);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        *(int *)(p + 40) = 14;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
    }
    BOX2_SEQ_SetSlotActorMode((char *)W(p), pair[0], 0);
    BOX2_SEQ_SetSlotActorMode((char *)W(p), p[22], 1);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_SetActorAffineMode((char *)W(p), 1);
    BOX2_SEQ_SetActorAnimSeq((char *)W(p), 10, 2);
    return 73;
}
