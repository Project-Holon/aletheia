/*
 * function: WIPE_SUB_CircleMain
 * address:  0x0202363C
 * packet:   pkt_0202363C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  none, needs a witness for WIPE_SUB_CircleStep; every concrete byte
 *           reproduces (verified with match.py one), the sole unresolved
 *           relocation is the THM_CALL to WIPE_SUB_CircleStep (0202363C..0202368C
 *           has no outside witness for it). WIPE_SUB_CircleStep itself is a real
 *           DIFF near miss (see docs/notes/WIPE_SUB_CircleStep.c.txt), not an
 *           EXACT/MATCH file, so it cannot supply a "matched" witness and
 *           the two cannot be folded into one tu unit yet.
 *
 * Dispatch on the +0xc mode word of a record: mode 1 closes the record's
 * +0x14 entry (via WIPE_SUB_CircleStep) and, once it reports the entry now empty,
 * frees the pair at entry+0x2c/entry+0x30 through WIPE_SUB_RequestWindowEnd (with the
 * record's own +0x10 as the third argument) and bumps +0xc, returning 0;
 * mode 2 tears the +0x14 entry down through WIPE_SUB_DeleteLineBuffers/func_020307B0,
 * clears +0x14, bumps +0xc and falls into the same "return 1" tail as mode
 * 3 (mode 3 alone has no other side effect); anything else, and mode 1
 * without the entry becoming empty, returns 0.
 *
 * symbols:
 *   WIPE_SUB_DeleteLineBuffers   0x02022D70  thumb
 *   WIPE_SUB_RequestWindowEnd   0x02022DCC  thumb
 *   func_020307B0   0x020307B0  arm
 *   WIPE_SUB_CircleStep  0x02023768  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec {
    u8  pad0[0xc];
    u32 mode;      /* +0xc */
    u32 f10;       /* +0x10 */
    void *entry;   /* +0x14 */
};

struct Entry {
    u8  pad0[0x2c];
    u32 f2c;       /* +0x2c */
    u32 f30;       /* +0x30 */
};

struct Wipe;
extern u32 WIPE_SUB_CircleStep(struct Wipe *w);
extern void WIPE_SUB_RequestWindowEnd(u32 a0, void *a1, u32 a2);
extern void WIPE_SUB_DeleteLineBuffers(void *a0);
extern u32 func_020307B0(void *p);

u32 WIPE_SUB_CircleMain(struct Rec *r)
{
    void *entry = r->entry;
    u32 result = 0;

    switch (r->mode) {
    case 1:
        if (WIPE_SUB_CircleStep(entry) == 1) {
            struct Entry *e = (struct Entry *)entry;
            WIPE_SUB_RequestWindowEnd(e->f2c, (void *)e->f30, r->f10);
            r->mode = r->mode + 1;
        }
        break;
    case 2:
        WIPE_SUB_DeleteLineBuffers(entry);
        func_020307B0(r->entry);
        r->mode = r->mode + 1;
        r->entry = 0;
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    default:
        break;
    }

    return result;
}
