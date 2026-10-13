/*
 * function: POKE_TOOL_DeleteMoveSlot
 * address:  0x02017BC8
 * packet:   pkt_020179B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three "rows" of a dialog/UI record: for each row index below 3, read the
 * three fields at +0x37/+0x3B/+0x3F and write the copies back at
 * +0x36/+0x3A/+0x3E (the field before each), then clear the three
 * single-byte fields at 0x39/0x3D/0x41.
 *
 * The loop counter is the function's own second parameter -- there is no
 * initialiser, the entry test is `cmp r4, #3 / bhs` straight off the
 * argument, and the back edge is `cmp r4, #3 / blo`, so the source is
 * `for (; i < 3; i++)` over an unsigned i, not a local counter.
 *
 * The u16/u8 shift pairs are the destination widths of the three temporaries
 * (`lsls #16 / lsrs #16` versus `lsls #24 / lsrs #24` for a u8), which is
 * what fixes the return type of POKE_TOOL_GetPartyValue as wider than both.  The first
 * temporary is live across the other two reads and spills to the `push`
 * home area (`str r0, [sp]` / `ldr r2, [sp]`), which is why r3 is in the
 * push list without being read anywhere.
 *
 * EXACT*: the listing extent runs to 136 bytes because the follower at
 * 0x02017C50 saves no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_DeleteMoveSlot.c \
 *       --func POKE_TOOL_DeleteMoveSlot --addr 0x02017BC8 --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);

void POKE_TOOL_DeleteMoveSlot(u8 *p, u32 i)
{
    for (; i < 3; i++) {
        u16 a = POKE_TOOL_GetPartyValue(p, i + 0x37, 0);
        u8  b = POKE_TOOL_GetPartyValue(p, i + 0x3b, 0);
        u8  c = POKE_TOOL_GetPartyValue(p, i + 0x3f, 0);

        POKE_TOOL_SetPartyValue(p, i + 0x36, a);
        POKE_TOOL_SetPartyValue(p, i + 0x3a, b);
        POKE_TOOL_SetPartyValue(p, i + 0x3e, c);
    }
    POKE_TOOL_SetPartyValue(p, 0x39, 0);
    POKE_TOOL_SetPartyValue(p, 0x3d, 0);
    POKE_TOOL_SetPartyValue(p, 0x41, 0);
}
