/*
 * function: POKETRADE_SAVE_StepEventMessage2
 * address: 0x021DFF40
 * packet: pkt_ov119_021DFF40
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepWaitFade1 0x021DFFE0 thumb ov119
 */
#include "../include/Obj01252.h"
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *, int, int);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_StepWaitFade1(char *p);
void POKETRADE_SAVE_StepEventMessage2(char *p)
{
    void *a;
    if (((struct Obj01252 *)p)->fF2C < 0xC8) {
        return;
    }
    if (POKETRADE_PROC_IsHostSide(p)) {
        a = POKETRADE_PROC_GetSideMon(p, 0);
    } else {
        a = POKETRADE_PROC_GetSideMon(p, 1);
    }
    WORDSET_SetSlotMonNickname(((struct Obj01252 *)p)->f724, 1, a);
    WORDSET_SetSlotMyStatus(((struct Obj01252 *)p)->f724, 0, (void *)(((struct Obj01252 *)p)->f834));
    if (((struct Obj01252 *)p)->f118C != 7 && ((struct Obj01252 *)p)->f118C != 8) {
        if (((struct Obj01252 *)p)->f11EE) {
            MSGDATA_ReadString(((struct Obj01252 *)p)->f720, 0x84, ((struct Obj01252 *)p)->f73C);
            WORDSET_CopyTaggedText(((struct Obj01252 *)p)->f724, ((struct Obj01252 *)p)->f738, ((struct Obj01252 *)p)->f73C);
            POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
        } else {
            MSGDATA_ReadString(((struct Obj01252 *)p)->f720, 0x31, ((struct Obj01252 *)p)->f73C);
            WORDSET_CopyTaggedText(((struct Obj01252 *)p)->f724, ((struct Obj01252 *)p)->f738, ((struct Obj01252 *)p)->f73C);
            POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
        }
    }
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepWaitFade1);
}
