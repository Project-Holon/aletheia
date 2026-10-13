/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020242D8
 * packet:   pkt_02023A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PMSI_PARAM_SetDefaultSentence, PMSI_PARAM_SetDefaultGreeting
 *
 * symbols:
 *   PMSI_PARAM_InitSentence  0x020242A4  thumb
 *
 * PMSI_PARAM_SetDefaultSentence dispatches on a 0..3 index through a dense jump table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md); an index
 * over 3 lands on the shared epilogue with neither a call nor a store,
 * which only a `default: break;` with nothing else in it produces. Each
 * arm calls the shared initialiser PMSI_PARAM_InitSentence (its own file,
 * src/matched/sub_020242A4.c, EXACT) with a small id, then overwrites the
 * flag halfword and one trailing field with plain 16-bit constants; the
 * four constants are narrowed by the `strh`, not addresses. Case 3 passes
 * the same id as case 1 (2) but a different flag (0xd instead of 0), so
 * the four arms cannot be collapsed by id alone.
 *
 * PMSI_PARAM_SetDefaultGreeting is the same shape as one switch arm inlined outside a
 * switch: call PMSI_PARAM_InitSentence with id 0, then overwrite the flag and
 * trailing field it just set.
 *
 * The two functions are contiguous with no gap: PMSI_PARAM_SetDefaultSentence's own
 * literal pool (the four constants) runs right up to PMSI_PARAM_SetDefaultGreeting's
 * entry point.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020242D8.c \
 *       --addr 0x020242D8 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void PMSI_PARAM_InitSentence(void *obj, u32 id);

void PMSI_PARAM_SetDefaultSentence(void *slot, u32 idx)
{
    u16 *p = (u16 *)slot;

    switch (idx) {
    case 0:
        PMSI_PARAM_InitSentence(slot, 1);
        p[1] = 0;
        p[2] = 0x5D2;
        break;
    case 1:
        PMSI_PARAM_InitSentence(slot, 2);
        p[1] = 0;
        p[2] = 0x5CD;
        break;
    case 2:
        PMSI_PARAM_InitSentence(slot, 3);
        p[1] = 0;
        p[2] = 0x667;
        break;
    case 3:
        PMSI_PARAM_InitSentence(slot, 2);
        p[1] = 0xd;
        p[2] = 0x573;
        break;
    default:
        break;
    }
}

void PMSI_PARAM_SetDefaultGreeting(void *obj)
{
    u16 *p = (u16 *)obj;

    PMSI_PARAM_InitSentence(obj, 0);
    p[1] = 1;
    p[2] = 0x58F;
}
