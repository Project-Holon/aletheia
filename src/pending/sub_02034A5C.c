/*
 * function: sub_02034A5C
 * address:  0x02034A5C
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   MATCH
 *
 * symbols:
 *   func_02034D60  0x02034D60  arm
 *   func_02034CBC  0x02034CBC  arm
 *   func_02034D08  0x02034D08  arm
 *   sub_02034A3C   0x02034A3C  arm
 *
 * Release the registration a handle owns.  -1 is the "no handle" value and
 * returns at once; otherwise the handle is resolved to its owner
 * (func_02034D60), the eight-byte registration table is fetched
 * (func_02034CBC) and its live length taken (func_02034D08), and the first
 * entry whose state word at +4 is 1 and whose handle at +0 is the one asked
 * for is handed to sub_02034A3C.  At most one entry matches, so the scan
 * returns rather than breaking.
 *
 * The second field load is spelled off the table base with the scaled index
 * (`ldreq r1, [r5, r3, lsl #3]`) rather than off the entry pointer already
 * in r2: writing both halves of the condition against the same `&table[i]`
 * local costs a `ldr r1, [r2]` instead and is a byte difference.
 *
 * Byte-correct on the first attempt, capped at MATCH: the PC24 at +0x50
 * (sub_02034A3C) has no witness.  The `bl` at 0x02034AAC inside this
 * function is 0x02034A3C's only reference anywhere in the image, so `label`
 * is out, and the `matched` route is closed too because
 * src/pending/sub_02034A3C.c is itself stuck at MATCH on func_020792B8,
 * which has exactly one call site of its own.  A unit over
 * 0x02034A3C..0x02034AC4 would make this site `local` but would inherit
 * that function's unresolved func_020792B8, so the combined range stays
 * MATCH and nothing is gained.  The chain unsticks only when a second
 * caller of 0x020792B8 turns up, most likely in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034A5C.c \
 *       --func sub_02034A5C --addr 0x02034A5C --cc 1.1p1 --arm
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Registration {
    s32 handle;
    s32 state;
};

extern struct Registration *func_02034CBC(void);
extern void *func_02034D60(s32 handle);
extern s32 func_02034D08(void *owner);
extern void sub_02034A3C(struct Registration *entry);

void sub_02034A5C(s32 handle)
{
    void *owner;
    struct Registration *table;
    s32 count;
    s32 i;

    if (handle == -1) {
        return;
    }

    owner = func_02034D60(handle);
    table = func_02034CBC();
    count = func_02034D08(owner);

    for (i = 0; i < count; i++) {
        if (table[i].state == 1 && handle == table[i].handle) {
            sub_02034A3C(&table[i]);
            return;
        }
    }
}
