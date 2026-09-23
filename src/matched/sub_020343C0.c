/*
 * function: sub_020343C0
 * address:  0x020343C0
 * packet:   pkt_020343C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Areaman_RunMask   0x020A048C  data
 *   Areaman_TailMask  0x020A0495  data
 *
 * areaman.c.  Mark `len` bits starting at bit `start` of the bitmap as used:
 * fails (0) past the managed range or when any target bit is already set
 * (dumping the mask and the byte through the release-empty hook
 * func_020344C4 when p->unk08 is set), otherwise sets the head bits, fills
 * whole bytes with 0xFF and ORs the tail mask into the last byte.
 *
 * What closed it (wave 17, from 44 out): the byte index is the PARAMETER
 * reused, `start = start / 8;`, not a fresh local.  That is the image's
 * `asr r1, r1, #3` into start's own register, which is what rotates the
 * index/count/tail registers to r1/r3/r2; with it the then-arm zeros go in
 * the natural order `nfull = 0; tail = 0;` (the image's `mov r3, #0` /
 * `mov r2, r3`).  docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020343C0.c \
 *       --func sub_020343C0 --addr 0x020343C0 --cc 1.1p1 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

extern const u8 Areaman_RunMask[];
extern const u8 Areaman_TailMask[];

extern void func_020344C4(u8 x);

s32 sub_020343C0(struct AreaMan *p, s32 start, u32 len)
{
    u32 bit;
    u32 avail;
    u32 nfull;
    u32 tail;
    u32 mask;
    u8 *q;
    u8 v;

    if (start + len > p->unk00) {
        return 0;
    }

    bit = start % 8;
    avail = 8 - bit;
    start = start / 8;
    if (avail >= len) {
        mask = Areaman_RunMask[len] >> bit;
        nfull = 0;
        tail = 0;
    } else {
        len = len - avail;
        mask = Areaman_TailMask[avail];
        nfull = len >> 3;
        tail = len & 7;
    }
    q = &p->bits[start];
    v = p->bits[start];
    if ((mask & v) != 0) {
        if (p->unk08 != 0) {
            func_020344C4((u8)mask);
            func_020344C4(p->bits[start]);
        }
        return 0;
    }
    start++;
    *q = v | (u8)mask;
    while (nfull-- != 0) {
        p->bits[start] = 0xFF;
        start++;
    }
    if (tail != 0) {
        p->bits[start] |= Areaman_RunMask[tail];
    }
    return 1;
}
