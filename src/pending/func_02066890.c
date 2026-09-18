/*
 * function: func_02066890
 * address:  0x02066890
 * packet:   pkt_02066890
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_020640B0   0x020640B0  arm
 *   func_020640CC   0x020640CC  arm
 *   g_02148B20      0x02148B20  data
 *
 * Initialises one 0x30-byte record of the recs array published in
 * g_02148B20.recs, clears it with func_020640B0, then sets three of its fields
 * through func_020640CC(index 0/1/2) for each of the three values that is not
 * the -1 sentinel, and finally stores the four remaining words from the
 * caller's stack arguments at +0xC..+0x18.
 *
 * The residue is the sentinel test: the original materialises -1 with
 * `mvn r0, #0` and compares register-to-register three times, while the front
 * end folds `v != 0xffffffff` into `cmn v, #1`, four bytes per guard.  See
 * docs/notes/pkt_020637BC.c.txt for the ten spellings already tried.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02066890.c \
 *       --func func_02066890 --addr 0x02066890 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec02066890 {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8  pad_1c[0x14];
};

struct Bank02066890 {
    u32            unk_00;
    u32            unk_04;
    struct Rec02066890 *recs;
};

extern struct Bank02066890 g_02148B20;
extern void func_020640B0(struct Rec02066890 *rec);
extern void func_020640CC(struct Rec02066890 *rec, u32 idx, u32 val);

void func_02066890(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    struct Rec02066890 *rec = &g_02148B20.recs[idx];

    func_020640B0(rec);

    if (a != 0xffffffffu) {
        func_020640CC(rec, 0, a);
    }
    if (b != 0xffffffffu) {
        func_020640CC(rec, 1, b);
    }
    if (c != 0xffffffffu) {
        func_020640CC(rec, 2, c);
    }

    rec->unk_0c = d;
    rec->unk_10 = e;
    rec->unk_14 = f;
    rec->unk_18 = g;
}
