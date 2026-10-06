/*
 * file:     unit_02067AA0.c
 * unit:     yes
 * function: func_02067AA0, func_02067AAC, func_02067AB8, func_02067AC0, func_02067B28, func_02067B40, func_02067B48, func_02067B50, func_02067B64, func_02067B78
 * address:  0x02067AA0
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
 *   g_02148B48   0x02148B48  data
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct G2dOamState {
    u8  pad_00[4];
    u32 mode;   /* 0x04 */
};

struct Src02067AC0 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

struct Work02067AC0 {
    u8  pad_00[0x28];
    u32 unk_28;
    u32 unk_2c;
    u8  pad_30[4];
    u32 unk_34;
    u8  pad_38[8];
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5c;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6c;
};

typedef unsigned short u16;

struct G2dOamState_02067B40 {
    u32 pad00[9];
    u32 flip;      /* +0x24 */
    u32 pad28[3];
    u32 f34;       /* +0x34 */
};

struct G2dOamState_02067B78 {
    u8  pad_00[0x24];
    u32 flip;   /* 0x24: bit0 flip-H, bit1 flip-V */
};

void func_02067AA0(int *p, int a, int b);
void func_02067AAC(int *p, int a, int b);
void func_02067B28(u32 a, u32 b);
extern struct Work02067AC0 *g_02148B48;



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AA0.c \
 *       --func func_02067AA0 --addr 0x02067AA0 --arm --cc 1.1p1
 */
void func_02067AA0(int *p, int a, int b)
{
    p[2] = a;
    p[3] = b;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AAC.c \
 *       --func func_02067AAC --addr 0x02067AAC --arm --cc 1.1p1
 */
void func_02067AAC(int *p, int a, int b)
{
    p[7] = a;
    p[8] = b;
}




/*
 * Unlabelled two-instruction leaf of the NNS G2D cell-to-OAM composer
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): the setter
 * for the mode word at +0x04 of the composer state whose flip lane is
 * src/matched/unit_02067B40.c.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CBB0+0x1c (src/matched/func_0204CBB0.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AB8.c \
 *       --func func_02067AB8 --addr 0x02067AB8 --cc 1.1p1 --arm
 */
void func_02067AB8(struct G2dOamState *p, u32 mode)
{
    p->mode = mode;
}


/*
 * Seeds the multi-cell renderer's working block from the caller's parameter
 * record: the record pointer at +0x2C, six of its words copied to +0x40..+0x50
 * and +0x64/+0x68, the four state words at +0x48..+0x5C zeroed, the blend
 * word at +0x60 set to 0x1000, and the shadow of the +0x34 field refreshed at
 * +0x6C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AC0.c \
 *       --func func_02067AC0 --addr 0x02067AC0 --arm --cc 1.1p1
 */
void func_02067AC0(struct Src02067AC0 *src)
{
    struct Work02067AC0 *w = g_02148B48;

    w->unk_2c = (u32)src;
    w->unk_40 = src->unk_00;
    w->unk_44 = src->unk_04;
    w->unk_48 = 0;
    w->unk_4c = src->unk_08;
    w->unk_50 = src->unk_0c;
    w->unk_54 = 0;
    w->unk_58 = 0;
    w->unk_5c = 0;
    w->unk_60 = 0x1000;
    w->unk_64 = src->unk_10;
    w->unk_68 = src->unk_14;
    w->unk_6c = w->unk_34;
}



void func_02067B28(u32 a, u32 b)
{
    struct Work02067AC0 *p = g_02148B48;

    p->unk_2c = a;
    p->unk_28 = b;
}





/*
 * The H/V flip lane of the NNS G2D cell-to-OAM composer: two setters, a
 * pair of predicates, and the one word the predicates read.
 *
 * The composer state's +0x24 word carries the two flip bits:
 *   bit0  flip horizontally
 *   bit1  flip vertically
 * func_02067B78 (0x02067B78, not in this file, see
 * docs/notes/g2d_flip_setter.c.txt) sets both from two BOOLs;
 * func_02067B50 and func_02067B64 answer them one at a time.  The functions that consume them are
 * func_0206775C and func_02067998, and the arithmetic there is the whole
 * reason this lane matters to a rig composer: with the flip bit set, the
 * OAM entry's own position field is replaced by
 *
 *     x' = -(x + objWidth [shape][size])       (attr1 bits 0-8,  9-bit)
 *     y' = -(y + objHeight[shape][size])       (attr0 bits 0-7,  8-bit)
 *
 * with shape from attr0 bits 14-15, size from attr1 bits 14-15, and the
 * two tables at 0x020A17F0 (width) and 0x020A17D8 (height), three rows of
 * four u16 on an 8-byte row stride.  An OAM composer that flips the pixels
 * but leaves the entry's x/y alone lands every flipped part at the wrong
 * place by its own width or height.
 *
 * func_02067B40 and func_02067B48 are plain word stores and none of these
 * saves lr, so they all print as a `.word` run in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02067B40.c \
 *       --addr 0x02067B40 --arm
 */
void func_02067B40(struct G2dOamState_02067B40 *p, u32 v)
{
    p->f34 = v;
}

/*
 * The H/V flip lane of the NNS G2D cell-to-OAM composer: two setters, a
 * pair of predicates, and the one word the predicates read.
 *
 * The composer state's +0x24 word carries the two flip bits:
 *   bit0  flip horizontally
 *   bit1  flip vertically
 * func_02067B78 (0x02067B78, not in this file, see
 * docs/notes/g2d_flip_setter.c.txt) sets both from two BOOLs;
 * func_02067B50 and func_02067B64 answer them one at a time.  The functions that consume them are
 * func_0206775C and func_02067998, and the arithmetic there is the whole
 * reason this lane matters to a rig composer: with the flip bit set, the
 * OAM entry's own position field is replaced by
 *
 *     x' = -(x + objWidth [shape][size])       (attr1 bits 0-8,  9-bit)
 *     y' = -(y + objHeight[shape][size])       (attr0 bits 0-7,  8-bit)
 *
 * with shape from attr0 bits 14-15, size from attr1 bits 14-15, and the
 * two tables at 0x020A17F0 (width) and 0x020A17D8 (height), three rows of
 * four u16 on an 8-byte row stride.  An OAM composer that flips the pixels
 * but leaves the entry's x/y alone lands every flipped part at the wrong
 * place by its own width or height.
 *
 * func_02067B40 and func_02067B48 are plain word stores and none of these
 * saves lr, so they all print as a `.word` run in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02067B40.c \
 *       --addr 0x02067B40 --arm
 */
void func_02067B48(u32 *p, u32 v)
{
    *p = v;
}

/*
 * The H/V flip lane of the NNS G2D cell-to-OAM composer: two setters, a
 * pair of predicates, and the one word the predicates read.
 *
 * The composer state's +0x24 word carries the two flip bits:
 *   bit0  flip horizontally
 *   bit1  flip vertically
 * func_02067B78 (0x02067B78, not in this file, see
 * docs/notes/g2d_flip_setter.c.txt) sets both from two BOOLs;
 * func_02067B50 and func_02067B64 answer them one at a time.  The functions that consume them are
 * func_0206775C and func_02067998, and the arithmetic there is the whole
 * reason this lane matters to a rig composer: with the flip bit set, the
 * OAM entry's own position field is replaced by
 *
 *     x' = -(x + objWidth [shape][size])       (attr1 bits 0-8,  9-bit)
 *     y' = -(y + objHeight[shape][size])       (attr0 bits 0-7,  8-bit)
 *
 * with shape from attr0 bits 14-15, size from attr1 bits 14-15, and the
 * two tables at 0x020A17F0 (width) and 0x020A17D8 (height), three rows of
 * four u16 on an 8-byte row stride.  An OAM composer that flips the pixels
 * but leaves the entry's x/y alone lands every flipped part at the wrong
 * place by its own width or height.
 *
 * func_02067B40 and func_02067B48 are plain word stores and none of these
 * saves lr, so they all print as a `.word` run in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02067B40.c \
 *       --addr 0x02067B40 --arm
 */
u32 func_02067B50(const struct G2dOamState_02067B40 *p)
{
    return (p->flip & 1) != 0;
}

/*
 * The H/V flip lane of the NNS G2D cell-to-OAM composer: two setters, a
 * pair of predicates, and the one word the predicates read.
 *
 * The composer state's +0x24 word carries the two flip bits:
 *   bit0  flip horizontally
 *   bit1  flip vertically
 * func_02067B78 (0x02067B78, not in this file, see
 * docs/notes/g2d_flip_setter.c.txt) sets both from two BOOLs;
 * func_02067B50 and func_02067B64 answer them one at a time.  The functions that consume them are
 * func_0206775C and func_02067998, and the arithmetic there is the whole
 * reason this lane matters to a rig composer: with the flip bit set, the
 * OAM entry's own position field is replaced by
 *
 *     x' = -(x + objWidth [shape][size])       (attr1 bits 0-8,  9-bit)
 *     y' = -(y + objHeight[shape][size])       (attr0 bits 0-7,  8-bit)
 *
 * with shape from attr0 bits 14-15, size from attr1 bits 14-15, and the
 * two tables at 0x020A17F0 (width) and 0x020A17D8 (height), three rows of
 * four u16 on an 8-byte row stride.  An OAM composer that flips the pixels
 * but leaves the entry's x/y alone lands every flipped part at the wrong
 * place by its own width or height.
 *
 * func_02067B40 and func_02067B48 are plain word stores and none of these
 * saves lr, so they all print as a `.word` run in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02067B40.c \
 *       --addr 0x02067B40 --arm
 */
u32 func_02067B64(const struct G2dOamState_02067B40 *p)
{
    return (p->flip & 2) != 0;
}


/*
 * The NNS G2D cell-to-OAM flip setter: bit 0 of the composer state's +0x24
 * word is flip-H and bit 1 is flip-V, both set or cleared from a BOOL.  Its
 * four neighbours in the same `.word` run are src/matched/unit_02067B40.c.
 *
 * docs/notes/g2d_flip_setter.c.txt wrote this off as a four-byte near miss:
 * the second `ldr r1, [r0, #0x24]` is a re-read of the word the preceding
 * store just wrote, which the compiler proves redundant and degrades to
 * `mov r1, r1`, and making the field or the parameter `volatile` restores
 * the load but splits the predicated `orrne`/`biceq` pair into a full
 * predicated load-modify-store per arm (60 bytes instead of 44).  The
 * spelling that does reproduce it is a volatile read of that one word and
 * nothing else: the first half stays a plain read-modify-write on the
 * field, so its predication survives, and only the re-read is forced.  See
 * docs/idioms/a-re-read-of-a-field-just-stored-is-one-volatile-read-not-a-volatile-field.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067B78.c \
 *       --func func_02067B78 --addr 0x02067B78 --cc 1.1p1 --arm
 */
void func_02067B78(struct G2dOamState_02067B78 *p, u32 h, u32 v)
{
    u32 w;

    if (h) p->flip |= 1;
    else   p->flip &= ~1u;

    w = *(volatile u32 *)&p->flip;

    if (v) w |= 2;
    else   w &= ~2u;

    p->flip = w;
}
