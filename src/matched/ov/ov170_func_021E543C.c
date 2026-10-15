/*
 * function: BOX2_SEQ_StateOpenBoxC
 * address: 0x021E543C
 * packet: pkt_ov170_021E543C
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
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_HideSlotsC61C 0x021EC61C thumb ov170
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb ov170
 *   BOX2_UI_CloseBar 0x021EF36C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb ov170
 *   BOX2_SEQ_Create 0x021EA1C0 thumb ov170
 *   BOX2_MAIN_StateMachineClose 0x021E0068 thumb ov170
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb ov170
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb ov170
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BOX2_SEQ_HideSlotsC61C(u8 *);
struct Sound;
struct WinMgr;
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowBusy(u8 *);
extern void BOX2_SEQ_SwapSlotActors(char *, unsigned);
extern void BOX2_SEQ_Create(void *p);
extern int BOX2_MAIN_StateMachineClose(char *p);
extern void BOX2_MAIN_UpdateBoxSlots(u8 *);
extern void BOX2_SEQ_Delete(char *p);
extern void BOX2_MAIN_ResetBoxView(char *);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **, unsigned);
extern void BOX2_SEQ_SetCursorDraw(char **, int);
int BOX2_SEQ_StateOpenBoxC(u8 *p)
{
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_SEQ_HideSlotsC61C(p);
        BOX2_UI_PutBottomBarClosed((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        BOX2_UI_CloseBar((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        p[26] = 2;
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 47);
    case 1:
        p[23] = p[20];
        BOX2_SEQ_SwapSlotActors(*(char **)(p + 44), p[22]);
        BOX2_SEQ_Create(p);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_StateMachineClose, 47);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_MAIN_UpdateBoxSlots(p);
        BOX2_SEQ_Delete((char *)p);
        BOX2_MAIN_ResetBoxView((char *)p);
        BOX2_UI_OpenBar((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 47);
    case 3:
        func_020260E4(*(void **)(*(u8 **)(p + 44) + 112), p[22]);
        BOX2_UI_SetCursorPos((char **)p, p[22]);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        p[22] = 255;
        *(u32 *)(*(u8 **)(p + 44) + 0xa194) = 0;
        return 44;
    }
    return 47;
}
