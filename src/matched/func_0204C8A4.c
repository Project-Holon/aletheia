/*
 * function: func_0204C8A4
 * address:  0x0204C8A4
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Fill one 0x10-byte pool entry.  A leaf with five arguments, so the last one
 * is read straight back off the caller's stack with no frame at all.
 *
 * The store order in the source is +0x0c, +0x00, +0x04, +0x08: only the last
 * two are adjacent in both address and source order, which is what lets the
 * compiler fuse them into `stmib r0, {r2, ip}`.  Writing the four fields in
 * address order would fuse three of them instead and change the encoding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C8A4.c \
 *       --func func_0204C8A4 --addr 0x0204C8A4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Entry {
    u32 unk_00;   /* 0x00 */
    u32 unk_04;   /* 0x04 */
    u32 unk_08;   /* 0x08 */
    u32 unk_0c;   /* 0x0c */
};

void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c)
{
    e->unk_0c = sel;
    e->unk_00 = b;
    e->unk_04 = a;
    e->unk_08 = c;
}
