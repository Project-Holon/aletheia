/*
 * unit:     yes
 * function: func_02012088
 * address:  0x02012088
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * symbols:
 *   func_0203133C     0x0203133C  arm
 *   func_02011F90     0x02011F90  thumb
 *
 * The range 0x02012088..0x020120A4: the object's +0x08 resource is released
 * and the teardown func_02011F90 runs, followed by the six-byte leaf that
 * carries no label (it has no prologue - two stores and `bx lr`), which is a
 * plain two-field setter for +0x10 and +0x14.
 *
 * blocker:  label.  The call to 0x02011F90 at +0x0C is the only branch to
 *           that address in the whole image, so it has no witness outside this
 *           range.  src/matched/unit_02011F90.c reproduces it byte for byte
 *           but is itself capped (on 0x0202B4F0, a call into the
 *           0x0201E000..0x0202E000 lane), so the pair graduates together or
 *           not at all.  Merging the two ranges into one unit over
 *           0x02011F90..0x020120A4 also needs 0x02011FCC (144 bytes) written.
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02012088.c \
 *       --addr 0x02012088 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f8;         /* +0x08 */
    u32 pad0c;      /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 f14;        /* +0x14 */
    u32 pad18;      /* +0x18 */
    u32 f1c;        /* +0x1C */
    u32 f20;        /* +0x20 */
    u32 f24;        /* +0x24 */
    u32 pad28;      /* +0x28 */
    u32 f2c;        /* +0x2C */
};

extern void func_0203133C(u32 v);
extern void func_02011F90(struct IcaAnime *p);

void func_02012088(struct IcaAnime *p)
{
    func_0203133C(p->f8);
    func_02011F90(p);
}

void func_0201209C(struct IcaAnime *p, u32 a, u32 b)
{
    p->f10 = a;
    p->f14 = b;
}
