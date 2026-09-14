/*
 * function: func_0204E074
 * address:  0x0204E074
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_02062820  0x02062820  arm
 *   func_02062670  0x02062670  arm
 *
 * Publish the two handles of one 0x14-byte pool entry.  The entry is
 * addressed as `pool->entries[idx]` (the `mla` by 0x14 is the subscript,
 * not a byte offset), each handle is registered through its own registrar,
 * and only when both succeed is the entry's +0x10 slot cleared and 1
 * returned.  Either failure leaves the entry alone and returns 0.
 *
 * The two guards must be written nested (`if (ok1) { if (ok2) { ...; return
 * 1; } } return 0;`), not as two early-`return 0` guards and not as one
 * `||`.  Only the nested form leaves the success path as the fall-through
 * of the second `cmp`, which is what lets the store, the constant and the
 * return if-convert into `movne`/`strne`/`movne`/`popne` above a single
 * shared `mov r0, #0` tail.  Two early returns give an if-converted first
 * guard and no shared tail (76 bytes); `||` emits the failure block first
 * and duplicates the return (84 bytes).  Both arguments must be read
 * into locals before the first call: the `mov r5, r3` ahead of the `bl` is
 * the fourth argument being parked in a callee-saved register, which only
 * happens when it is live across the call as a plain value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E074.c \
 *       --func func_0204E074 --addr 0x0204E074 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct Entry {
    u8    pad_00[8];
    void *unk_08;
    void *unk_0c;
    u32   unk_10;
};

struct Pool {
    u8            pad_00[0x10];
    struct Entry *entries;
};

extern s32 func_02062820(void *handle, void **slot);
extern s32 func_02062670(void *handle, void **slot);

s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b)
{
    struct Entry *entry = &pool->entries[idx];

    if (func_02062820(a, &entry->unk_08) != 0) {
        if (func_02062670(b, &entry->unk_0c) != 0) {
            entry->unk_10 = 0;
            return 1;
        }
    }
    return 0;
}
