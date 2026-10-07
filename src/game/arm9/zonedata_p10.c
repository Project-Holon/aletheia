/*
 * file:     zonedata_p10.c
 * unit:     yes
 * function: func_020141E0, func_020141F0, func_02014204, func_02014264, func_02014274, func_020142A4, func_020142E8, func_02014314
 * address:  0x020141E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02013B90   0x02013B90  thumb
 *   sub_02013B74   0x02013B74  thumb
 *   func_02014204  0x02014204  thumb
 *   sub_02082BCC  0x02082BCC  arm
 *   func_02014388  0x02014388  thumb
 */
struct t;
typedef struct Vec020141E0 {
    int x;
    int y;
    int z;
} Vec020141E0;

typedef struct Rec020141E0 {
    int f0;
    int f4;
    int f8;
    int fC;
    Vec020141E0 v;
} Rec020141E0;

typedef struct Vec020141F0 {
    int x;
    int y;
    int z;
} Vec020141F0;

typedef struct Rec020141F0 {
    int f0;
    int f4;
    int f8;
    int fC;
    Vec020141F0 v;
} Rec020141F0;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

struct t {
    u32 a;      /* 0x00 */
    u16 b;      /* 0x04 */
    s16 c;      /* 0x06 */
    u16 d;      /* 0x08 */
    u16 e;      /* 0x0a */
    u32 f;      /* 0x0c */
    u16 g;      /* 0x10 */
    u8  pad[2];
    u16 h;      /* 0x14 */
    u16 i;      /* 0x16 */
};

struct v3 { u32 x, y, z; };

typedef signed int    s32;

extern void func_020140F8(int p0);
extern int func_02013C70(u32 a);
extern void sub_02013B90(u32 id, u32 *out);
extern void sub_02013B74(u32 id, u32 *out);
extern void func_02014204(struct t *p, int id);
extern u32 sub_02082BCC(u32 a, u32 b, u32 c);
extern u8 *func_02014388(void *bitmap, s32 id);
void func_020141E0(const Rec020141E0 *p, Vec020141E0 *out);
void func_020141F0(Rec020141F0 *p, const Vec020141F0 *v);
void sub_02014264(void *p);
u32 sub_02014274(u32 idx);
u32 sub_020142A4(u32 idx);
u32 sub_020142D0(void);
u32 sub_020142D8(u32 a);
u32 func_020142E8(void *bitmap, s32 id);
void func_02014314(char *a0, int a1);


/*
 * note:     wave 18 lane ties_b: unlabelled follower of func_020141DC; copies the three words at +0x10 out, read into locals last-to-first.
 */
void func_020141E0(const Rec020141E0 *p, Vec020141E0 *out)
{
    int z = p->v.z;
    int y = p->v.y;
    int x = p->v.x;

    out->x = x;
    out->y = y;
    out->z = z;
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower; clears the +0xC word and struct-assigns the three words at +0x10.
 */
void func_020141F0(Rec020141F0 *p, const Vec020141F0 *v)
{
    p->fC = 0;
    p->v = *v;
}


/*
 *           inside this function, and src/pending/func_02013C70.c is itself
 *           only MATCH (its pool word for tbl_0209E010 has no outside
 *           witness), so no `matched` entry can attest the site.  Every
 *           concrete byte here is correct; --suggest-split reports no
 *           viable cut.
 */
void func_02014204(struct t *p, int id)
{
    struct v3 v;

    func_020140F8((int)p);
    p->a = 1;
    p->b = id;
    p->c = -1;
    p->d = 2;
    p->e = 0;
    if (func_02013C70(id) != 0) {
        sub_02013B90(id, (u32 *)(&v));
        p->f = 1;
        *((u8 *)p + 0x12) = 1;
        p->g = v.x;
        p->i = v.y;
        p->h = v.z;
    } else {
        sub_02013B74(id, (u32 *)(&v));
        p->f = 0;
        *(struct v3 *)((u8 *)p + 0x10) = v;
    }
}


/*
 * A one-line forwarder: func_02014204 with its second argument pinned to
 * 0x187.  This IS compiled C, not a linker veneer: an ARM long-branch
 * veneer never materialises an argument, and the four-byte-ARM-veneer shape
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md)
 * does not apply -- this is six bytes of Thumb plus two pool words, the
 * ordinary tail-call form
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The constant lands in
 * a pool rather than a `movs` because 0x187 is out of the Thumb immediate
 * range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014264.c \
 *       --func sub_02014264 --addr 0x02014264 --cc 1.1p1 --thumb
 */
void sub_02014264(void *p)
{
    func_02014204(p, 0x187);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: sub_02014274 and sub_020142A4 are two dense switches over a small
 * id (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md): the
 * range each `cmp`/`bhi` accepts has one slot with no case of its own,
 * which lands on the same body as the function's default arm
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md); the id that
 * hits it is not a real case, it is written as the default.
 *
 * sub_020142D0 is a bare constant getter, hiding the same way the tail
 * calls elsewhere in this packet do: no prologue, so disasm.py's sweep
 * never labels it. sub_020142D8 is a tail call to the ARM function
 * sub_02082BCC forwarding its own argument and two more constants; the
 * same target is reached by an ordinary `blx` from unit_02014368.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014274.c \
 *       --addr 0x02014274 --thumb
 */
u32 sub_02014274(u32 idx)
{
    switch (idx) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    default: return 1;
    }
}


u32 sub_020142A4(u32 idx)
{
    switch (idx) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    default: return 2;
    }
}


u32 sub_020142D0(void)
{
    return 0x3EA;
}


u32 sub_020142D8(u32 a)
{
    return sub_02082BCC(a, 0, 0x3EA);
}


/*
 * Test one flag in a bitmap: the lookup at 0x02014388 resolves the flag id
 * to the byte that holds it, and this function picks the bit out of that
 * byte.  A null byte pointer reads as "clear" rather than asserting.
 *
 * The bit number is `id % 8` on a *signed* id, not `id & 7`.  That is the
 * whole reason for the `lsrs #31 / lsls #29 / subs / rors #29 / adds`
 * quintet: an unsigned id folds to a single `movs r1, #7 / ands`, and a
 * plain mask loses four instructions.  The two forms differ only for
 * negative ids, where the shift count would be negative, so the source is
 * relying on the caller never passing one.
 *
 * The null check and the bit test share one `return 0`, so they are nested
 * ifs, not an early return followed by a second one: written as
 * `if (byte == 0) return 0;` the compiler gives the null arm its own
 * `movs r0, #0 / pop` and the function grows two bytes
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * EXACT*: the extent runs to 44 bytes because the next function has no
 * label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020142E8.c \
 *       --func func_020142E8 --addr 0x020142E8 --cc 1.1p1 --thumb
 */
u32 func_020142E8(void *bitmap, s32 id)
{
    u8 *byte = func_02014388(bitmap, id);

    if (byte != 0) {
        if ((*byte & (1 << (id % 8))) != 0) {
            return 1;
        }
    }
    return 0;
}


void func_02014314(char *a0, int a1)
{
    unsigned char *p = func_02014388(a0, a1);

    if (p != 0)
        *p |= 1 << (a1 % 8);
}
