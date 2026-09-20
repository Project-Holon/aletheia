/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_0201D6D8
 * address:  0x0201D6D8
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * 144 bytes, 0x0201D6D8..0x0201D768, one function, every concrete byte
 * reproduced (0 differing bytes of 144) -- the diff is empty apart from the
 * three wildcarded call fields.
 *
 * Blocked on the `label` class, and it is a one-address wall: all three
 * unresolved sites at +0x24, +0x32 and +0x44 call func_0201D768, which is the
 * function *immediately after this one* and whose only callers in the whole
 * image are these three.  The compared range ends where 0x0201D768 begins, so
 * shrinking the range is not possible (the callee cannot go in), and the
 * `matched` class needs an EXACT entry covering 0x0201D768 that does not
 * exist yet.  It graduates the day 0x0201D768 is matched -- nothing in this C
 * changes.
 *
 * What it is: the cache-side of a record reader.  It asks
 * func_0201D768(p, func_02045A90(c), (u16)func_0201D69C(c), 2) for a slot
 * keyed by the record at `c`, stores a second slot for `b` (0x1c/0x1c) in a
 * stack local, zero-initialises a 4-byte stack local through a third call,
 * and then walks the list hanging off p->f10 through func_0201D7C4 until it
 * runs out, rebasing the node pointer on p+0x18 and clamping the resulting
 * offset against p->f4 (u16) before a 4-byte memcpy into the local.  When
 * p->f10 is null it installs the two slots instead.
 *
 * Two details that cost a compile each: func_02045A90 is ARM, not Thumb (the
 * symbols: block says `arm`, and the harness refuses the call otherwise), and
 * the offset is truncated to u16 twice -- once right after the subtraction and
 * once after the +0x1c -- which is the `(u16)(...) + 0x1c` spelling in a u16
 * local, not a single cast.
 *
 * Verified with
 *   python tools/match.py one --src src/pending/func_0201D6D8.c \
 *       --func func_0201D6D8 --addr 0x0201D6D8 --cc 1.1p1 --thumb
 *
 * symbols:
 *   func_0201D69C  0x0201D69C  thumb
 *   func_0201D768  0x0201D768  thumb
 *   func_0201D7C4  0x0201D7C4  thumb
 *   func_02045A90  0x02045A90  arm
 *   memcpy         0x02082D44  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u8  pad00[4];
    u16 f04;
    u8  pad06[0x10 - 6];
    void *f10;
    u32   f14;
} Blk;

extern u32  func_0201D69C(void *c);
extern void *func_0201D768(Blk *p, void *src, u32 a, u32 b);
extern void *func_0201D7C4(Blk *p, void *q);
extern u32  func_02045A90(void *c);
extern void *memcpy(void *dst, const void *src, u32 n);

void func_0201D6D8(Blk *p, void *b, void *c)
{
    void *e;
    void *q;
    void *t;
    u32 v;
    u32 x;

    x = (u32)func_0201D768(p, (void *)func_02045A90(c),
                           (u16)func_0201D69C(c), 2);
    e = func_0201D768(p, b, 0x1c, 0x1c);
    v = 0;
    func_0201D768(p, &v, 4, 4);
    q = p->f10;
    if (q != 0) {
        for (;;) {
            t = func_0201D7C4(p, q);
            if (t == 0) break;
            q = t;
        }
        {
            u16 off = (u16)((u32)q - ((u32)p + 0x18)) + 0x1c;

            if (off >= p->f04) off = 0;
            memcpy(&e, (char *)p + 0x18 + off, 4);
        }
        return;
    }
    p->f10 = e;
    p->f14 = x;
}
