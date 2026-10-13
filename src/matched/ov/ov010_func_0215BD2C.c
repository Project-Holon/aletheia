/*
 * function: SCRCMD_PROC_SetMonMove
 * address:  0x0215BD2C
 * packet:   pkt_ov010_0215BD2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: reads a party slot, a move slot and a move. A move slot
 * past 4 goes to POKE_TOOL_PushMove (teach into a free slot); a zero move deletes
 * the slot, shifting the later moves (ids 0x36 move, 0x3A pp, 0x3E pp-ups)
 * down one; otherwise POKE_TOOL_SetMoveSlot sets the move into the slot.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
struct Sav;
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern void POKE_TOOL_PushMove(void *p, int move);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

int SCRCMD_PROC_SetMonMove(void *c, void *vm)
{
    u16 slot;
    u16 moveSlot;
    u16 move;
    void *mon;
    u32 saved;
    u8 i;
    u32 m;
    u32 ppUp;
    u32 pp;

    slot = SCRIPT_WORK_ReadWorkValue(c, vm);
    moveSlot = SCRIPT_WORK_ReadWorkValue(c, vm);
    move = SCRIPT_WORK_ReadWorkValue(c, vm);
    if (SCRCMD_PROC_GetPartyMember(vm, slot, &mon) == 0) {
        return 0;
    }
    saved = POKE_TOOL_DecodePartyParam(mon);
    if (moveSlot > 4) {
        POKE_TOOL_PushMove(mon, move);
    } else if (move == 0) {
        i = moveSlot;
        if (moveSlot < 3) {
            for (; i < 3; i++) {
                m = POKE_TOOL_GetPartyValue(mon, i + 0x37, 0);
                if (m == 0) {
                    break;
                }
                ppUp = POKE_TOOL_GetPartyValue(mon, i + 0x3F, 0);
                pp = POKE_TOOL_GetPartyValue(mon, i + 0x3B, 0);
                POKE_TOOL_SetPartyValue(mon, i + 0x36, m);
                POKE_TOOL_SetPartyValue(mon, i + 0x3E, ppUp);
                POKE_TOOL_SetPartyValue(mon, i + 0x3A, pp);
            }
        }
        POKE_TOOL_SetPartyValue(mon, i + 0x36, 0);
        POKE_TOOL_SetPartyValue(mon, i + 0x3E, 0);
        POKE_TOOL_SetPartyValue(mon, i + 0x3A, 0);
    } else {
        POKE_TOOL_SetMoveSlot(mon, move, (u8)moveSlot);
    }
    POKE_TOOL_EncodePartyParam(mon, saved);
    return 0;
}
