/*
 * unit:     no
 * function: func_0204C7A4
 * address:  0x0204C7A4
 * packet:   pkt_0204C7A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204C8B8  0x0204C8B8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u32 unk_00;
    u8  pad_04[0x0c];
};

struct Table {
    u8            pad_00[4];
    struct Entry *ents;
    u32           count;
};

extern void func_0204C8B8(struct Entry *e);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);

void func_0204C7A4(struct Table *t)
{
    u32 i;

    for (i = 0; i < t->count; i++) {
        if (t->ents[i].unk_00 != 0) {
            func_0204C8B8(&t->ents[i]);
            MI_CpuFill8(&t->ents[i], 0, sizeof(struct Entry));
        }
    }
}
