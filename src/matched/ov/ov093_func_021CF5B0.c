/*
 * function: BTL_CLIENT_IsMoveSelectionBlocked
 * address: 0x021CF5B0
 * packet: pkt_ov093_021CF5B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_IsHeldItemEffective 0x021CF89C thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTL_SICKCONT_GetValue 0x021E8B80 thumb ov093
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTLV_SCU_AppendMessageArg 0x021EAF50 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_GetSickParam 0x021D62D8 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   BTL_FIELD_IsSlotInUse 0x021EFCE4 thumb ov093
 *   BTL_FIELD_IsMoveSealedBySlot 0x021EFC1C thumb ov093
 */
#include "../include/Obj01894.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v; } Word;
struct L;
struct QI;
struct Unk021D62A8;
struct UtilSlots;
extern int BTL_CLIENT_IsHeldItemEffective(u8 *p, void *q);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern Word BTL_POKEPARAM_GetSickContRaw(void *, int);
extern u16 BTL_SICKCONT_GetValue(Word);
extern int BTL_POKEPARAM_HasMove(void *, u32);
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *p);
extern u16 BTL_POKEPARAM_GetSickParam(struct UtilSlots *p, int i);
extern int WAZA_TOOL_GetFlag(u32, int);
extern void *BTL_FIELD_IsSlotInUse(char *arg0, int arg1);
extern int BTL_FIELD_IsMoveSealedBySlot(int, int, void *, u32);
int BTL_CLIENT_IsMoveSelectionBlocked(u8 *g, void *m, u32 move, void *out)
{
    u32 k;
    u32 k2;
    Word w;
    if (move == 0xa5) return 0;
    if (BTL_CLIENT_IsHeldItemEffective(g, m) && BTL_POKEPARAM_HasSick(m, 0x1b)) {
        w = BTL_POKEPARAM_GetSickContRaw(m, 0x1b);
        k = BTL_SICKCONT_GetValue(w);
        if (BTL_POKEPARAM_HasMove(m, k) && k != move) {
            if (out) {
                BTLV_SCU_InitMessage(out, 1, 0x63);
                BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetItem(m));
                BTLV_SCU_AppendMessageArg(out, k);
            }
            return 1;
        }
    }
    if (BTL_POKEPARAM_HasSick(m, 0x17)) {
        k2 = BTL_SICKCONT_GetValue(BTL_POKEPARAM_GetSickContRaw(m, 0x17));
        if (move != k2) {
            if (out) {
                BTLV_SCU_InitMessage(out, 1, 0x64);
                BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
                BTLV_SCU_AppendMessageArg(out, k2);
            }
            return 1;
        }
    }
    if (BTL_POKEPARAM_HasSick(m, 0xb) && WAZA_TOOL_IsDamaging((void *)move) == 0) {
        if (out) {
            BTLV_SCU_InitMessage(out, 2, 0x23b);
            BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
            BTLV_SCU_AppendMessageArg(out, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(m, 0xc) && move == BTL_POKEPARAM_GetLastSelectedMoveId(m)) {
        if (out) {
            BTLV_SCU_InitMessage(out, 2, 0x244);
            BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
            BTLV_SCU_AppendMessageArg(out, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(m, 0xd) && move == BTL_POKEPARAM_GetSickParam(m, 0xd) && move != 0xa5) {
        if (out) {
            BTLV_SCU_InitMessage(out, 2, 0x253);
            BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
            BTLV_SCU_AppendMessageArg(out, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(m, 0xf) && WAZA_TOOL_GetFlag(move, 0xc)) {
        if (out) {
            BTLV_SCU_InitMessage(out, 2, 0x37a);
            BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
            BTLV_SCU_AppendMessageArg(out, move);
        }
        return 1;
    }
    if (BTL_FIELD_IsSlotInUse((char *)(*(int *)&((struct Obj01894 *)g)->f34), 3) && BTL_FIELD_IsMoveSealedBySlot(*(int *)&((struct Obj01894 *)g)->f34, *(int *)&((struct Obj01894 *)g)->f4, m, move)) {
        if (out) {
            BTLV_SCU_InitMessage(out, 2, 0x24d);
            BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
            BTLV_SCU_AppendMessageArg(out, move);
        }
        return 1;
    }
    if (BTL_FIELD_IsSlotInUse((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) && WAZA_TOOL_GetFlag(move, 9)) {
        if (out) {
            BTLV_SCU_InitMessage(out, 2, 0x43e);
            BTLV_SCU_AppendMessageArg(out, BTL_POKEPARAM_GetPokeId(m));
            BTLV_SCU_AppendMessageArg(out, move);
        }
        return 1;
    }
    return 0;
}
