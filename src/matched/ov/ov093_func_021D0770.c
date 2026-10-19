/*
 * function: BTL_CLIENT_StepAutoChooseActions
 * address: 0x021D0770
 * packet: pkt_ov093_021D0770
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: nested one-word aggregate return removes its extra frame word;
 *   named count/bytes reproduce original final read/store order. Three
 *   iteration runs, two scheduling variants; no prior compiles.
 * semantic: state/cursor arithmetic is unsigned; byte counters promote
 *   safely and narrow on store. CF81C writes all four availability bytes
 *   before return; CFBF0 writes the single output byte on every nonzero
 *   return path. Full-width pointer payloads retain their original bits.
 * symbols:
 *   BTL_CLIENT_ClearSlotOrder 0x021CFBA4 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_ACTION_SetNone 0x021D8434 thumb ov093
 *   BTL_CLIENT_IsActionForced 0x021CF470 thumb ov093
 *   BTL_CLIENT_TakeTrainerItemToUse 0x021D3DC4 thumb ov093
 *   BTL_ACTION_SetItem 0x021D8358 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_CLIENT_ChooseAiSwitchTarget 0x021CFBF0 thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_CLIENT_PickRotationPosition 0x021D06C8 thumb ov093
 *   BTL_SLOT_GetRotateSrcIndex 0x021B9AB0 thumb ov093
 *   BTL_ACTION_SetRotate 0x021D83FC thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTL_SICKCONT_GetValue 0x021E8B80 thumb ov093
 *   BTL_CALC_PeekMoveTarget 0x021D81F8 thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 *   BTL_CLIENT_SetStruggleIfNoMoves 0x021CF524 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_CLIENT_BuildUsableMoveMask 0x021CF81C thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   TR_AI_Start 0x021880BC thumb ov096
 *   BTL_CLIENT_SetStruggleAction 0x021CF58C thumb ov093
 *   TR_AI_Think 0x02187FB0 thumb ov096
 *   TR_AI_GetChosenMove 0x02188134 thumb ov096
 *   TR_AI_GetChosenTarget 0x02188140 thumb ov096
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_ACTION_SetEscape 0x021D8414 thumb ov093
 */
#include "../include/Obj00464.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v; } Word;
extern void BTL_CLIENT_ClearSlotOrder(s8 *);
struct QG;
struct S2;
struct Unk021D62A8;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
struct G;
struct Unk021D82D0;
extern void BTL_ACTION_SetNone(u32 *p);
extern u32 BTL_CLIENT_IsActionForced(u8 *, void *, u8 *);
extern u32 BTL_CLIENT_TakeTrainerItemToUse(u8 *, void *, void *);
struct Unk021D82D0;
extern void BTL_ACTION_SetItem(u32 *p, u32 id, u32 sub, u32 val);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern int BTL_CLIENT_ChooseAiSwitchTarget(u8 *, void *, u32, u8 *);
extern void BTL_ACTION_SetChange(void *, u8, u32);
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_CLIENT_PickRotationPosition(struct G *g);
extern int BTL_SLOT_GetRotateSrcIndex(int);
extern void BTL_ACTION_SetRotate(u32 *p, u32 sub);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern Word BTL_POKEPARAM_GetSickContRaw(void *, int);
extern u16 BTL_SICKCONT_GetValue(Word);
extern u32 BTL_CALC_PeekMoveTarget(void *, void *, void *, u32, void *);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u32 BTL_CLIENT_SetStruggleIfNoMoves(u32, void *, u32);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u32 BTL_CLIENT_BuildUsableMoveMask(u8 *, void *, u8 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
extern void TR_AI_Start(int, u8 *, int);
extern void BTL_CLIENT_SetStruggleAction(struct Unk021D82D0 *out, u8 *p, void *q);
extern int TR_AI_Think(u8 *);
extern u8 TR_AI_GetChosenMove(u8 *);
extern u8 TR_AI_GetChosenTarget(u8 *);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern void BTL_ACTION_SetEscape(u32 *);
#define M (*(void **)(p+8))
#define R (*(u8 **)(p+12))
int BTL_CLIENT_StepAutoChooseActions(u8 *p, u32 *state)
{
    u8 available[4];
    u8 choice;
    u32 move;
    u32 slot;
    u32 sub;
    u32 result;
    u32 count;
    u32 bytes;
    switch (*state) {
    case 0:
        BTL_CLIENT_ClearSlotOrder((s8 *)p);
        p[0x11d] = 0;
        p[0x1af] = 0;
        *state = 1;
    case 1:
        if (p[0x11d] >= p[0x11c]) break;
        M = BTL_SLOT_GetPokeParam(((struct Obj00464 *)p)->f118, p[0x11d]);
        R = p+0x124+p[0x11d]*4;
        if (BTL_POKEPARAM_IsFainted(M)) {
            BTL_ACTION_SetNone((u32 *)R);
            goto complete;
        }
        if (BTL_CLIENT_IsActionForced(p,M,R)) goto complete;
        move = BTL_CLIENT_TakeTrainerItemToUse(p,M,((struct Obj00464 *)p)->f118);
        if (move) {
            BTL_ACTION_SetItem((u32 *)R,move,p[0x11d],0);
            goto complete;
        }
        if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00464 *)p)->f0) && BTL_CLIENT_ChooseAiSwitchTarget(p,M,p[0x11d],&choice)) {
            BTL_ACTION_SetChange(R,p[0x11d],choice);
            goto complete;
        }
        if (BTL_MAIN_GetRule(((struct Obj00464 *)p)->f0) == 3) {
            slot = BTL_CLIENT_PickRotationPosition((struct G *)p);
            if (slot != 1) {
                sub = BTL_SLOT_GetRotateSrcIndex(slot);
                BTL_ACTION_SetRotate((u32 *)R,slot);
                M = BTL_SLOT_GetPokeParam(((struct Obj00464 *)p)->f118,sub);
                p[0x1af] = 1;
                R = (u8 *)((u32)R+4U);
            }
        }
        if (BTL_POKEPARAM_HasSick(M,0x19)) {
            move = BTL_SICKCONT_GetValue(BTL_POKEPARAM_GetSickContRaw(M,0x19));
            result = BTL_CALC_PeekMoveTarget(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,M,move,p+0xf4);
            BTL_ACTION_SetFight((struct Unk021D82D0 *)R,move,result);
            goto complete;
        }
        if (BTL_CLIENT_SetStruggleIfNoMoves((u32)p,M,(u32)R)) *state = 3;
        BTL_POKEPARAM_GetMoveCount(M);
        slot = BTL_CLIENT_BuildUsableMoveMask(p,M,available);
        if (slot != 4) {
            result = BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,BTL_POKEPARAM_GetPokeId(M));
            TR_AI_Start(*(int *)&((struct Obj00464 *)p)->fF0,available,result);
            *state = 2;
        } else {
            BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)((u32)R),(u8 *)((u32)p),M);
            goto complete;
        }
        break;
    case 2:
        if (TR_AI_Think(*(u8 * *)&((struct Obj00464 *)p)->fF0)) break;
        slot = TR_AI_GetChosenMove(*(u8 * *)&((struct Obj00464 *)p)->fF0);
        if (slot != 4) {
            sub = TR_AI_GetChosenTarget(*(u8 * *)&((struct Obj00464 *)p)->fF0);
            move = BTL_POKEPARAM_GetMoveId(M,slot);
            BTL_ACTION_SetFight((struct Unk021D82D0 *)R,move,sub);
        } else BTL_ACTION_SetEscape((u32 *)R);
complete:
        *state = 3;
        break;
    case 3:
        p[0x11d]++;
        count = p[0x11c];
        if (p[0x11d] >= count) {
            bytes = (count+p[0x1af])*4;
            *(u8 * *)&((struct Obj00464 *)p)->fD8 = p+0x124;
            ((struct Obj00464 *)p)->fDC = bytes;
            p[0x1af] = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}
