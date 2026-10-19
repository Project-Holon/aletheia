/*
 * function: BOX2_SEQ_StateMoveItemD
 * address: 0x021E754C
 * packet: pkt_ov170_021E754C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_SEQ_DeleteB 0x021EA750 thumb ov170
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 */
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_SetSlotActorMode(char *w, int i, int f);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_SEQ_DeleteB(char *p);
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_UI_ShowWindowB(char *w);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int BOX2_SEQ_StateMoveItemD(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x667);
        BOX2_SEQ_SetSlotActorMode(WORK(p), **(unsigned short **)(WORK(p) + 0x60), 0);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        CURSOR_MOVE_SetCurrent(*(void **)(WORK(p) + 0x70), p[0x16] - 0x1E);
        BOX2_SEQ_DeleteB((char *)p);
        STEP(p)++;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 1)
            break;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, p[0x16]);
        CURSOR_MOVE_SetState(*(void **)(WORK(p) + 0x70), 1);
        BOX2_UI_ShowWindowB(WORK(p));
        return 0x46;
    }
    return 0x4A;
}
