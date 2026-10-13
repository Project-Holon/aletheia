/*
 * function: CLACT_DrawUnit
 * address:  0x0204C944
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 72 concrete bytes are correct and CLACT_UpdateActorAutoAnim
 * resolves `matched`, but the call to CLACT_DrawActor (+0x0028) has no
 * witness: 0204CB44 has exactly one branch reference image wide, this
 * call, so no cut frees it. CLACT_DrawUnit itself was the blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for CLACT_DrawAllUnits; closing it
 * only traded one fan-in-1 blocker for another one level down
 * (CLACT_DrawActor, 108 bytes, not otherwise investigated here).
 *
 * Guarded by the top nibble of the byte at +0xe (the low nibble is never
 * tested here, hence the `lsl #0x18; lsrs #0x1c` rather than a plain
 * `ldrb`/`ands`) and by the ring head at +0x04 being non-null. Then walk
 * that ring (the node's own +0x00 is its `next`, same shape as
 * CLACT_DrawAllUnits's bank ring) running CLACT_DrawActor and CLACT_UpdateActorAutoAnim (the
 * latter already matched, src/matched/CLACT_UpdateActorAutoAnim.c) over every member.
 *
 * symbols:
 *   CLACT_DrawActor  0x0204CB44  arm
 *   CLACT_UpdateActorAutoAnim  0x0204CEB4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_DrawUnit.c \
 *       --func CLACT_DrawUnit --addr 0x0204C944 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Elem {
    struct Elem *next;  /* 0x00 */
};

struct Ring {
    u8            pad_00[4];
    struct Elem  *head;   /* 0x04 */
    u32           arg;    /* 0x08 */
    u8            pad_0c[2];
    u8            flags_lo : 4;  /* 0x0e */
    u8            flags_hi : 4;
};

extern void CLACT_DrawActor(struct Elem *e, u32 arg);
struct Obj;
extern void CLACT_UpdateActorAutoAnim(struct Obj *o);

void CLACT_DrawUnit(struct Ring *b)
{
    struct Elem *cur;

    if (b->flags_hi == 0) {
        return;
    }

    cur = b->head;
    if (cur == 0) {
        return;
    }

    do {
        CLACT_DrawActor(cur, b->arg);
        CLACT_UpdateActorAutoAnim((struct Obj *)cur);
        cur = cur->next;
    } while (cur != b->head);
}
