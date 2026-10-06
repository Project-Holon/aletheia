/*
 * file:     clact_p06.c
 * unit:     yes
 * function: func_0204C788, func_0204C7A4, func_0204C804
 * address:  0x0204C788
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_020307B0   0x020307B0  arm
 *   func_0204C8B8  0x0204C8B8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 */
struct Xfer;
typedef unsigned char u8;

struct Pool_0204C788 {
    u8    pad_00[4];
    void *ents;   /* 0x04 */
};

typedef unsigned int   u32;

struct Entry {
    u32 unk_00;
    u8  pad_04[0x0c];
};

struct Table {
    u8            pad_00[4];
    struct Entry *ents;
    u32           count;
};

struct Pool_0204C804 {
    u8            pad_00[4];
    struct Entry *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
};

extern u32 sub_020307B0(void *p);
extern void func_0204C8B8(struct Xfer *x);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);


/*
 * Release the 0x10-byte entry array func_0204C718 allocates at +0x04 and NULL
 * the pointer.  The pointer has to survive the free call, so the object is
 * kept in r4 and the store is written after it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C788.c \
 *       --func func_0204C788 --addr 0x0204C788 --cc 1.1p1 --arm
 */
void func_0204C788(struct Pool_0204C788 *p)
{
    sub_020307B0(p->ents);
    p->ents = 0;
}


/*
 * Blocked at MATCH: all 96 concrete bytes are correct, but the PC24 at
 * +0x0034 (the call to func_0204C8B8) has no witness of any class.
 * 0x0204C8B8 has exactly one branch reference image wide and it is that
 * call, so no cut frees it; the unblock is a `matched` entry at 0x0204C8B8,
 * which src/pending/func_0204C8B8.c cannot supply, being itself byte-correct
 * but capped at MATCH by the handler table at 0x020A138C having no second
 * pool word anywhere in the image.
 *
 * Tear down every live entry of a 16-byte-record table: the record count is
 * at +0x08 and the array base at +0x04, and a record is live when its first
 * word is non-null.  Each live record is handed to func_0204C8B8 and then
 * zeroed.
 *
 * The array base is re-read from +0x04 on both sides of the func_0204C8B8
 * call, which is what fixes it as a field load rather than a cached local:
 * the callee may move the table.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C7A4.c \
 *       --func func_0204C7A4 --addr 0x0204C7A4 --cc 1.1p1 --arm
 */
void func_0204C7A4(struct Table *t)
{
    u32 i;

    for (i = 0; i < t->count; i++) {
        if (t->ents[i].unk_00 != 0) {
            func_0204C8B8((struct Xfer *)(&t->ents[i]));
            MI_CpuFill8(&t->ents[i], 0, sizeof(struct Entry));
        }
    }
}


/*
 * Find the first free 0x10-byte entry of a pool, free meaning a zero word at
 * +0x00.  Returns NULL when the pool is full.  A leaf: nothing here calls
 * anything, so both the entry array and the count are hoisted out of the loop
 * and the element address is only materialised on the arm that returns it
 * (`addeq r0, r2, r1, lsl #4`).
 *
 * The scaled register offset `ldr r0, [r2, r1, lsl #4]` is the subscript form
 * `p->ents[i].unk_00`; a walking cursor would have produced a post-indexed
 * load and an extra add
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C804.c \
 *       --func func_0204C804 --addr 0x0204C804 --cc 1.1p1 --arm
 */
struct Entry *func_0204C804(struct Pool_0204C804 *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (p->ents[i].unk_00 == 0) {
            return &p->ents[i];
        }
    }

    return 0;
}
