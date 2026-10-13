/*
 * function: POKE_TOOL_SetRotomFormMove
 * address:  0x02017A20
 * packet:   pkt_02017A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_DeleteMoveSlot  0x02017BC8  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   sRotomFormMoves       0x0209E298  data  a2
 *
 * Species check (id 5 == 0x1DF), then teach the move tbl[idx] from a
 * six-entry u16 table {0, 0x13B, 0x38, 0x3B, 0x193, 0x1B5} at 0x0209E298:
 * any slot already holding one of tbl[1..5] is overwritten (first hit) or
 * deleted (POKE_TOOL_DeleteMoveSlot, then the slot is re-examined), else the first
 * empty slot, else slot `val`; slot 0 empty gets move 0x54; finally
 * POKE_TOOL_ChangeForm(p, idx).  Wave 11, 2026-09-23.
 *
 * The straight-line six ldrh/strh copy with TWO `add rN, sp, #8` is a
 * 12-byte, 2-aligned aggregate copy scoped AFTER the guard: in the original
 * very likely a local initializer `u16 tbl[6] = {...}` inside a block (that
 * spelling is byte-identical but its anonymous rodata symbol cannot be named
 * in `symbols:`), written here as the equivalent struct copy from a named
 * extern so the relocation resolves (sole-ref).  Also load-bearing: `v` and
 * `val` are u32, so the (u16)/(u8) truncations land at the POKE_TOOL_SetMoveSlot
 * calls; `k` is unsigned (`blo`), `i` signed (`blt`); `r != 0 && r ==
 * tbl.v[k]` is the inner test.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);
extern void POKE_TOOL_DeleteMoveSlot(u8 *p, u32 i);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

struct MoveTbl { u16 v[6]; };
extern const struct MoveTbl sRotomFormMoves;

u32 POKE_TOOL_SetRotomFormMove(void *p, u32 idx, u32 val)
{
    u32 v;
    int i;
    u32 k;

    if (POKE_TOOL_GetPartyValue(p, 5, 0) != 0x1df)
        return 0;
    {
    struct MoveTbl tbl = sRotomFormMoves;
    v = tbl.v[idx];
    for (i = 0; i < 4; i++) {
        u32 r = POKE_TOOL_GetPartyValue(p, i + 0x36, 0);

        for (k = 1; k < 6; k++) {
            if (r != 0 && r == tbl.v[k]) {
                if (v != 0) {
                    POKE_TOOL_SetMoveSlot(p, v, (u8)i);
                    v = 0;
                } else {
                    POKE_TOOL_DeleteMoveSlot(p, i);
                    i--;
                }
                break;
            }
        }
    }
    }
    if (v != 0) {
        for (i = 0; i < 4; i++) {
            if (POKE_TOOL_GetPartyValue(p, i + 0x36, 0) == 0) {
                POKE_TOOL_SetMoveSlot(p, v, (u8)i);
                break;
            }
        }
        if (i == 4)
            POKE_TOOL_SetMoveSlot(p, v, (u8)val);
    }
    if (POKE_TOOL_GetPartyValue(p, 0x36, 0) == 0)
        POKE_TOOL_SetMoveSlot(p, 0x54, (u8)0);
    POKE_TOOL_ChangeForm(p, (u16)idx);
    return 1;
}
