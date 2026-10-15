/*
 * function: POKETRADE_PROC_StepBrowseGrid
 * address:  0x021DBE70
 * packet:   pkt_ov119_021DBE70
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The bound block after POKETRADE_2D_GetScrollColumn closes only with its six locals
 * declared without initialisers and assigned afterwards; about a fifth of
 * the declaration orders then match (docs/notes/pkt_ov119_021DBE70.c.txt).
 *
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetCont 0x0203630C arm
 *   func_020355C4 0x020355C4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   POKETRADE_2D_GetVisibleColumnRange 0x021E4E0C thumb
 *   POKETRADE_PROC_IsSlotVisible 0x021DB4EC thumb
 *   POKETRADE_2D_GetScrollColumn 0x021E4DBC thumb
 *   POKETRADE_PROC_GetSlotPosition 0x021DB4B4 thumb
 *   POKETRADE_PROC_RedrawAndSyncGrid 0x021DB7AC thumb
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb
 *   POKETRADE_PROC_UpdateDragState 0x021D8B54 thumb
 *   POKETRADE_PROC_UpdateDragIcon 0x021D8C0C thumb
 *   POKETRADE_PROC_PollGridKeys 0x021DB52C thumb
 *   POKETRADE_NEGO_PollMarkerTouch 0x021DF7F0 thumb
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb
 *   func_02017E88 0x02017E88 thumb
 *   POKETRADE_PROC_CanTradeMon 0x021DD0CC thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb
 *   POKETRADE_PROC_StepWaitKeyAfterMessage 0x021DA064 thumb
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb
 *   POKETRADE_NEGO_FindOfferIndex 0x021DD34C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_NEGO_StepSendOfferRemoval 0x021DF708 thumb
 *   POKETRADE_2D_PlaceBoxIconActors 0x021E4A1C thumb
 *   POKETRADE_PROC_StepPeerSelectAction 0x021DBDB4 thumb
 *   POKETRADE_PROC_PollGridTouchDrag 0x021D9F24 thumb
 *   POKETRADE_PROC_IsSelectedOfferSlot 0x021D9548 thumb
 *   POKETRADE_PROC_ClearDragIcon 0x021D8C6C thumb
 *   POKETRADE_PROC_ShowCancelMessage 0x021DA0CC thumb
 *   POKETRADE_2D_StartIconFlight 0x021E6544 thumb
 *   POKETRADE_PROC_StepWaitIconFlight 0x021DBD3C thumb
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   POKETRADE_PROC_DragScrollGrid 0x021DB89C thumb
 *   POKETRADE_PROC_StepTouchbarAction 0x021DC2B0 thumb
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 */

typedef unsigned int u32;

extern int TOUCHPANEL_GetCont(void);
typedef unsigned char  u8;
struct MsgBank;
struct S;
extern void func_020355D8(u8 v);
extern unsigned int KEY_GetCont(void);
extern u8 func_020355C4(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern int POKETRADE_2D_GetVisibleColumnRange(char *p, int *out);
extern int POKETRADE_PROC_IsSlotVisible(char *p, int v);
extern int POKETRADE_2D_GetScrollColumn(char *p);
extern int POKETRADE_PROC_GetSlotPosition(int v);
extern void POKETRADE_PROC_RedrawAndSyncGrid(char *p, int v, int w);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern void POKETRADE_PROC_ShowDragIcon(void *p);
extern void POKETRADE_PROC_UpdateDragState(void *p);
extern void POKETRADE_PROC_UpdateDragIcon(void *p);
extern void POKETRADE_PROC_PollGridKeys(char *p);
extern void POKETRADE_NEGO_PollMarkerTouch(void *p);
extern int POKETRADE_PROC_GetBoxIndexForSlot(int v, char *p);
extern int POKETRADE_PROC_GetSlotIndexInBox(int a, int b);
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int POKETRADE_PROC_CanTradeMon(char *p, int e);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_PROC_StepWaitKeyAfterMessage(char *p);
extern int POKETRADE_PROC_IsHostSide(void *p);
extern int POKETRADE_NEGO_FindOfferIndex(char *p, int a, int b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void POKETRADE_NEGO_StepSendOfferRemoval(void *p);
extern void POKETRADE_2D_PlaceBoxIconActors(char *p);
extern int POKETRADE_PROC_StepPeerSelectAction(char *p);
extern int POKETRADE_PROC_PollGridTouchDrag(char *p, int v);
extern int POKETRADE_PROC_IsSelectedOfferSlot(char *p, int a, int b);
extern void POKETRADE_PROC_ClearDragIcon(void *p);
extern void POKETRADE_PROC_ShowCancelMessage(char *p);
extern void POKETRADE_2D_StartIconFlight(char *p);
extern void POKETRADE_PROC_StepWaitIconFlight(char *p);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void POKETRADE_PROC_DragScrollGrid(char *p);
extern void POKETRADE_PROC_StepTouchbarAction(char *p);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *p);

#define I(p, o) (*(int *)((p) + (o)))
#define H(p, o) (*(short *)((p) + (o)))

static inline int poll_a(void)
{
    int r = KEY_GetTrg();
    if (r)
        func_020355D8(0);
    return r;
}

static inline int poll_b(void)
{
    int r = TOUCHPANEL_GetTrg();
    if (r)
        func_020355D8(1);
    return r;
}

void POKETRADE_PROC_StepBrowseGrid(char *p)
{
    int n;
    int e;
    p[0x11EA] = 1;
    if (TOUCHPANEL_GetCont()) {
        func_020355D8(1);
        if (KEY_GetCont())
            return;
    }
    if (func_020355C4() && poll_a()) {
        func_020355D8(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &n) == 0) {
            int v = n;
            I(p, 0xF74) = v;
            if (v < 2 && I(p, 0xF78) >= 3)
                I(p, 0xF78) = 2;
        } else if (POKETRADE_PROC_IsSlotVisible(p, I(p, 0xF74)) == 0) {
            int end;
            int a;
            int t;
            int cur;
            int b;
            int lim;
            t = POKETRADE_2D_GetScrollColumn(p);
            cur = I(p, 0xF74);
            a = t + 5;
            b = t + 10;
            lim = I(p, 0x634);
            end = cur;
            if (b >= lim && cur < 0x14)
                end = cur + (lim + 1);
            if (a < end)
                H(p, 0x107C) = POKETRADE_PROC_GetSlotPosition(cur + 1) - 0x100;
            else
                H(p, 0x107C) = POKETRADE_PROC_GetSlotPosition(cur);
            H(p, 0x1080) = -1;
            I(p, 0x1084) = 1;
            POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 1);
            H(p, 0x107A) = 0;
            return;
        }
        POKETRADE_PROC_RequestBoxRedraw(p);
        H(p, 0x107A) = 0;
        return;
    }
    if (poll_a() || poll_b())
        H(p, 0x107A) = 0;
    if (poll_b()) {
        POKETRADE_PROC_ShowDragIcon(p);
        I(p, 0xF98) = -1;
        I(p, 0xF94) = -1;
    }
    POKETRADE_PROC_UpdateDragState(p);
    POKETRADE_PROC_UpdateDragIcon(p);
    POKETRADE_PROC_PollGridKeys(p);
    POKETRADE_NEGO_PollMarkerTouch(p);
    if (poll_a() == 1) {
        func_020355D8(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &n) == 0) {
            int v = n;
            I(p, 0xF74) = v;
            if (v < 2) {
                if (I(p, 0xF78) >= 3)
                    I(p, 0xF78) = 0;
            } else if (I(p, 0xF78) >= 5)
                I(p, 0xF78) = 0;
        }
        e = (int)POKETRADE_PROC_LoadSlotMonAlt((void *)I(p, 0x828), POKETRADE_PROC_GetBoxIndexForSlot(I(p, 0xF74), p), POKETRADE_PROC_GetSlotIndexInBox(I(p, 0xF74), I(p, 0xF78)), p);
        if (e && func_02017E88((void *)e, 0xA9, 0)) {
            if (POKETRADE_PROC_CanTradeMon(p, e)) {
                MSGDATA_ReadString((struct MsgBank *)I(p, 0x720), 0x8E, (void *)I(p, 0x738));
                POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
                POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitKeyAfterMessage);
                return;
            }
            I(p, 0xF98) = POKETRADE_PROC_GetBoxIndexForSlot(I(p, 0xF74), p);
            I(p, 0xF94) = POKETRADE_PROC_GetSlotIndexInBox(I(p, 0xF74), I(p, 0xF78));
            func_020355D8(0);
            if (POKETRADE_PROC_IsHostSide(p) && POKETRADE_NEGO_FindOfferIndex(p, I(p, 0xF98), I(p, 0xF94)) != -1) {
                GFL_USE_PlaySeDefaultVolume(0x626);
                POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendOfferRemoval);
                return;
            }
            POKETRADE_PROC_LoadSlotMonAlt((void *)I(p, 0x828), I(p, 0xF98), I(p, 0xF94), p);
            POKETRADE_PROC_ShowDragIcon(p);
            POKETRADE_2D_PlaceBoxIconActors(p);
            POKETRADE_PROC_StepPeerSelectAction(p);
            return;
        }
    }
    switch (POKETRADE_PROC_PollGridTouchDrag(p, 0)) {
    case 3:
        return;
    case 2:
        break;
    case 1:
        func_020355D8(1);
        I(p, 0xF70) = 1;
    default:
        if (!TOUCHPANEL_GetCont()) {
            if (I(p, 0x1088) && I(p, 0xF5C) && I(p, 0xF60)) {
                I(p, 0x1088) = 0;
                I(p, 0xF5C) = 0;
                if (POKETRADE_PROC_IsSelectedOfferSlot(p, I(p, 0xF80), I(p, 0xF7C))) {
                    I(p, 0xF80) = -1;
                    I(p, 0xF7C) = -1;
                    POKETRADE_PROC_ClearDragIcon(p);
                    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_ShowCancelMessage);
                    return;
                }
                I(p, 0xF98) = I(p, 0xF80);
                I(p, 0xF94) = I(p, 0xF7C);
                I(p, 0xF84) = I(p, 0xF7C);
                I(p, 0xF88) = I(p, 0xF80);
                I(p, 0xF60) = 0;
                TOUCHBAR_SetButtonVisible((unsigned char *)I(p, 0x9C0), 8, 1);
                TOUCHBAR_SetButtonEnabled((unsigned char *)I(p, 0x9C0), 8, 1);
                POKETRADE_2D_StartIconFlight(p);
                GFL_USE_PlaySeDefaultVolume(0x72A);
                POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitIconFlight);
                return;
            }
            if (I(p, 0x1088) && I(p, 0xF60) && I(p, 0xF70)) {
                I(p, 0xF98) = I(p, 0xF80);
                I(p, 0xF94) = I(p, 0xF7C);
                POKETRADE_PROC_StepPeerSelectAction(p);
                return;
            }
            if (I(p, 0xF7C) != -1 && I(p, 0xF80) != -1) {
                POKETRADE_PROC_ShowDragIcon(p);
                POKETRADE_PROC_RequestBoxRedraw(p);
            } else {
                POKETRADE_PROC_ShowDragIcon(p);
            }
            I(p, 0x1088) = 0;
            I(p, 0xF5C) = 0;
            CLACT_SetActorAutoAnim((struct Obj *)I(p, 0xF04), 0);
        }
        POKETRADE_PROC_DragScrollGrid(p);
        if (TOUCHPANEL_GetCont())
            I(p, 0x1088) = 1;
        TOUCHBAR_Update((struct S *)I(p, 0x9C0));
        switch (TOUCHBAR_GetPressedButtonIdIfPressing((u8 *)I(p, 0x9C0))) {
        case 1:
        case 7:
        case 8:
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepTouchbarAction);
            break;
        }
        break;
    }
}
