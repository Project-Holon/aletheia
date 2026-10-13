/*
 * function: BTL_CLIENT_StepSelectMove
 * address: 0x021CEA94
 * packet: pkt_ov093_021CEA94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witnesses: four ov093 blocker leaves 021E98AC, 021E98B4,
 * 021D7EF0, 021E9920 filed and individually shard-verified first.
 * lever: packed unsigned bitfields plus narrow caller extern CF5B0 move;
 * record declared before sub settles r6/r7 allocation (one variant).
 * interface: CF5B0 own source takes u32 move, but original narrows id at
 * 021CEBC6/021CEBCC; u16 extern preserves observed caller truncation.
 * CE3B4 ignores r1 but caller explicitly supplies p+0x58, retained here.
 * semantics: word bitfields use unsigned shifts; all dynamic address adds
 * and scaling are u32 modulo 2^32, without assuming selector/index bounds.
 * Byte increment is promoted in 0..255 then narrowed; all locals initialized
 * on each path to a use. The branch to state 4 has no uninitialized outputs.
 * symbols:
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_CLIENT_SetStruggleIfNoMoves 0x021CF524 thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   BTL_CLIENT_StepAdvanceSlot 0x021CF220 thumb ov093
 *   BTL_CLIENT_StepAutoSelectActions 0x021CE3C8 thumb ov093
 *   BTL_CLIENT_StepSelectAction 0x021CE4D0 thumb ov093
 *   BTL_CLIENT_StepMoveHighlight 0x021CED4C thumb ov093
 *   BTL_CLIENT_BuildMoveUsableTable 0x021CECB4 thumb ov093
 *   BTLV_CORE_StartMoveMenu 0x021E97BC thumb ov093
 *   BTLV_CORE_StartMoveMenuForEntry 0x021E9808 thumb ov093
 *   BTL_CLIENT_PollTimeLimitAndSetSub 0x021CE0BC thumb ov093
 *   BTLV_CORE_AbortMoveMenu 0x021E98AC thumb ov093
 *   BTLV_CORE_PollMoveMenu 0x021E98B4 thumb ov093
 *   BTL_CALC_ActionGetKind 0x021D8454 thumb ov093
 *   BTL_SLOT_GetRotateSrcIndex 0x021B9AB0 thumb ov093
 *   BTL_ACTION_GetFightSlotFlag 0x021D832C thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_CLIENT_IsMoveSelectionBlocked 0x021CF5B0 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   BTL_CLIENT_ShowMessage 0x021CE3B4 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_ACTION_GetFightMove 0x021D8340 thumb ov093
 *   BTL_ACTION_SetRotate 0x021D83FC thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 *   BTL_CALC_IsMultiFighterRule 0x021D7EF0 thumb ov093
 *   BTLV_CORE_StartTargetMenu 0x021E98BC thumb ov093
 *   BTLV_CORE_AbortTargetMenu 0x021E9920 thumb ov093
 *   BTLV_CORE_PollTargetMenu 0x021E98E8 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   BTLV_CORE_ReopenMoveMenu 0x021E9858 thumb ov093
 */
#include "../include/Obj00434.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record;
struct Unk021D82D0;
struct UtilWork;
extern u32 BTL_MAIN_GetRule(void **p);
extern u32 BTL_CLIENT_SetStruggleIfNoMoves(u32, void *, u32);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern u32 BTL_CLIENT_StepAdvanceSlot(u8 *, int *);
extern int BTL_CLIENT_StepAutoSelectActions(u8 *, int *);
extern int BTL_CLIENT_StepSelectAction(u8 *, u32 *);
extern u32 BTL_CLIENT_StepMoveHighlight(u8 *, int *);
extern void BTL_CLIENT_BuildMoveUsableTable(u8 *, void *);
extern void BTLV_CORE_StartMoveMenu(char *p, u8 *a, int b);
extern void BTLV_CORE_StartMoveMenuForEntry(char *p, u32 *q, int c);
extern int BTL_CLIENT_PollTimeLimitAndSetSub(u8 *p, void *q);
extern void BTLV_CORE_AbortMoveMenu(void *);
extern u32 BTLV_CORE_PollMoveMenu(void *);
extern u32 BTL_CALC_ActionGetKind(u32 *);
extern int BTL_SLOT_GetRotateSrcIndex(int);
struct Unk021D82FC;
extern u32 BTL_ACTION_GetFightSlotFlag(struct Unk021D82FC *p);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern int BTL_CLIENT_IsMoveSelectionBlocked(u8 *g, void *m, u32 move, void *out);
extern void func_021EAF78(u8 *, u8);
extern void BTL_CLIENT_ShowMessage(u8 *p, void *q);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u32 BTL_ACTION_GetFightMove(u32 *);
extern void BTL_ACTION_SetRotate(u32 *p, u32 sub);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u32 BTL_CALC_IsMultiFighterRule(u32);
extern void BTLV_CORE_StartTargetMenu(char *p, u8 *a, int b);
extern void BTLV_CORE_AbortTargetMenu(void *);
extern int BTLV_CORE_PollTargetMenu(char *p);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern void BTLV_CORE_ReopenMoveMenu(char *p);

int BTL_CLIENT_StepSelectMove(u8 *p, u32 *state)
{
    void *m;
    u32 slot, k;
    u32 *record;
    u8 sub;
    switch (*state) {
    case 0:
        if (BTL_MAIN_GetRule(((struct Obj00434 *)p)->f0) != 3) {
            if (BTL_CLIENT_SetStruggleIfNoMoves((u32)p, ((struct Obj00434 *)p)->f8, *(u32 *)&((struct Obj00434 *)p)->fC))
                BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            else *state = 1;
        } else {
            BTL_CLIENT_BuildMoveUsableTable(p, p + 0xa4);
            *state = 2;
        }
        break;
    case 1:
        BTLV_CORE_StartMoveMenu(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 2:
        BTLV_CORE_StartMoveMenuForEntry(((struct Obj00434 *)p)->f54, (u32 *)(p + 0xa4), *(int *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 3:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(p, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            BTLV_CORE_AbortMoveMenu(((struct Obj00434 *)p)->f54);
            return 0;
        }
        if (BTLV_CORE_PollMoveMenu(((struct Obj00434 *)p)->f54)) {
            k = BTL_CALC_ActionGetKind(*(u32 * *)&((struct Obj00434 *)p)->fC);
            if (k == 0) BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectAction));
            else if (k == 5) BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            else {
                m = ((struct Obj00434 *)p)->f8;
                record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                sub = 0;
                slot = p[0x11d];
                if (BTL_MAIN_GetRule(((struct Obj00434 *)p)->f0) == 3) {
                    sub = (u8)((Record *)(p + 0xbc))->sub;
                    slot = BTL_SLOT_GetRotateSrcIndex(sub);
                    m = *(void **)((u32)p + slot * 8U + 0xa4U);
                }
                if (BTL_ACTION_GetFightSlotFlag((struct Unk021D82FC *)record)) {
                    p[0x1b0] = slot;
                    p[0x1b1] = BTL_POKEPARAM_FindMoveSlot(m, (u16)((Record *)record)->id);
                    if (p[0x1b1] != 4) {
                        BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepMoveHighlight));
                        return 0;
                    }
                }
                if (BTL_CLIENT_IsMoveSelectionBlocked(p, m, (u16)((Record *)record)->id, p + 0x58)) {
                    func_021EAF78(p + 0x58, 0xff);
                    BTL_CLIENT_ShowMessage(p, p + 0x58);
                    *state = 7;
                } else {
                    if (BTL_MAIN_GetRule(((struct Obj00434 *)p)->f0) == 3 && sub != 0 && sub != 1 && !BTL_POKEPARAM_IsFainted(m)) {
                        k = BTL_ACTION_GetFightMove((u32 *)(p + 0xc0));
                        record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                        *(u32 *)&((struct Obj00434 *)p)->fC = (u32)record + 4U;
                        BTL_ACTION_SetRotate(record, sub);
                        BTL_ACTION_SetFight(((struct Obj00434 *)p)->fC, k, 6);
                        ++p[0x1af];
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (BTL_CALC_IsMultiFighterRule(BTL_MAIN_GetRule(((struct Obj00434 *)p)->f0))) *state = 5;
        else BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        break;
    case 5:
        BTLV_CORE_StartTargetMenu(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 6;
        break;
    case 6:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(p, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            BTLV_CORE_AbortTargetMenu(((struct Obj00434 *)p)->f54);
            return 0;
        }
        k = BTLV_CORE_PollTargetMenu(((struct Obj00434 *)p)->f54);
        if (k == 1) BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        else if (k == 2) *state = 1;
        break;
    case 7:
        if (BTLV_CORE_WaitMessage(((struct Obj00434 *)p)->f54)) {
            BTLV_CORE_ReopenMoveMenu(((struct Obj00434 *)p)->f54);
            *state = 3;
        }
        break;
    }
    return 0;
}
