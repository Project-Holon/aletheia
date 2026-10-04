/*
 * function: func_020116E0
 * address:  0x020116E0
 * packet:   pkt_020116E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Open four channels: a halfword tag at +0, a handset object at +4, a peer
 * object at +8, and then sub_0204944C(p->f04, p->f08, id, len, dest) for
 * ids 0, 4, 5 and 6 -- the last three writing one byte each into buf[2],
 * buf[1] and buf[0], i.e. backwards from the end of the four-byte buffer.
 *
 * `v = 1;` is a SEPARATE statement after the four calls, not the
 * declaration initialiser.  As `u32 v = 1;` at the top of the body the
 * assignment is hoisted to the function entry (r6 = 1 before the first
 * call, the zero constant landing in r4), and the result is a diff of two
 * instructions at the end: the original keeps 1 in r4 (the register the
 * dead a2 parameter was homed to) and the 0 in r6, and the guard stores
 * `r4 = r6` on the equal arm instead of `r6 = r4`.  Sinking the assignment
 * to its own statement after the last call reproduces the original
 * allocation exactly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020116E0.c \
 *       --func func_020116E0 --addr 0x020116E0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_020490F4(unsigned int id, unsigned int heap);
struct ArcFile;
extern void sub_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);

void func_020116E0(u8 *p, u32 a1, u32 a2, u32 a3)
{
    u8 buf[4];
    u32 v;

    *(u16 *)p = (u16)a3;
    *(void **)(p + 4) = sub_020490F4(a1, a3);
    *(u32 *)(p + 8) = a2;
    sub_0204944C((struct ArcFile *)*(u32 *)(p + 4), a2, 0, 4, p + 0xc);
    sub_0204944C((struct ArcFile *)*(u32 *)(p + 4), *(u32 *)(p + 8), 4, 1, buf + 2);
    sub_0204944C((struct ArcFile *)*(u32 *)(p + 4), *(u32 *)(p + 8), 5, 1, buf + 1);
    sub_0204944C((struct ArcFile *)*(u32 *)(p + 4), *(u32 *)(p + 8), 6, 1, buf);
    v = 1;
    if (buf[2] == 0) {
        v = 0;
    }
    *(u32 *)(p + 0x30) = v;
    *(u32 *)(p + 0x2c) = (buf[1] != 0);
    *(u32 *)(p + 0x28) = (buf[0] != 0);
}
