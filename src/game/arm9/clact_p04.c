/*
 * file:     clact_p04.c
 * unit:     yes
 * function: func_0204CBB0, func_0204CC6C, func_0204CEB4, func_0204CED8, func_0204CF40
 * address:  0x0204CBB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02067AB8  0x02067AB8  arm
 *   func_0204B658  0x0204B658  arm
 *   func_02067B78  0x02067B78  arm
 *   func_02065CE4  0x02065CE4  104 bytes  -- OPEN (pkt_02065CE4), 4 bytes
 *   func_02065D4C  0x02065D4C  104 bytes  -- OPEN (pkt_02065D4C), twin of
 *   func_02066080  0x02066080  220 bytes  -- OPEN (pkt_02065D4C), unattempted
 *   func_020663D0  0x020663D0  arm
 *   func_020664CC  0x020664CC  arm
 *   func_02066620  0x02066620  arm
 *   g_020A1B38     0x020A1B38  data
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   sub_0204B8D4  0x0204B8D4  arm
 *   sub_0204B49C  0x0204B49C  arm
 *   sub_0204B84C  0x0204B84C  arm
 *   sub_0204B878  0x0204B878  arm
 *   sub_0204B95C  0x0204B95C  arm
 *   sub_0204B784  0x0204B784  arm
 *   sub_0204B728  0x0204B728  arm
 */
struct Actor;
struct G2dOamState;
struct Obj02066080;
struct Struct36;
struct Xform;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Elem {
    u8  pad_00[0x60];
    u32 pad_60_0  : 8;
    u32 f_08      : 4;   /* 0x60, bits 8-11  */
    u32 pad_60_1  : 4;
    u32 f_10      : 2;   /* 0x60, bits 16-17 */
    u32 f_12      : 2;   /* 0x60, bits 18-19 */
    u32 pad_60_2  : 2;
    u32 f_16      : 2;   /* 0x60, bits 22-23 */
    u32 f_18      : 1;   /* 0x60, bit 24     */
    u32 pad_60_3  : 7;
};

struct Rec {
    u8  pad_00[0x84];
    u32 unk_84;   /* 0x84 */
    u16 unk_88;   /* 0x88 */
    u16 pad_8a;
    u32 unk_8c;   /* 0x8c */
    u32 unk_90;   /* 0x90 */
};

typedef signed short   s16;

typedef signed int     s32;

typedef float          f32;

struct Obj_0204CC6C {
    u8  pad_00[0xc];
    s16 unk_0c;       /* 0x0c */
    s16 unk_0e;       /* 0x0e */
    s16 unk_10;       /* 0x10 */
    s16 unk_12;       /* 0x12 */
    u32 unk_14;       /* 0x14 */
    u32 unk_18;       /* 0x18 */
    u8  pad_1c[0x3c];
    u16 unk_58;       /* 0x58 */
    u8  pad_5a[6];
    u32 pad_60_0 : 18;
    u32 unk_60_12 : 2; /* 0x60, bits 18-19 */
    u32 pad_60_1 : 12;
    u32 unk_64_0 : 1;  /* 0x64, bit 0 */
    u32 pad_64_1 : 31;
    u32 unk_68;        /* 0x68 */
    u8  pad_6c[8];
    u8  unk_74[0x30];  /* 0x74 */
    u32 unk_a4;        /* 0xa4 */
};

struct Obj_0204CEB4 {
    u8   pad_00[0x54];
    u32  unk_54;
    u8   pad_58[8];
    u32  pad_60_lo : 25;
    u32  enabled   : 1;
    u32  pad_60_hi : 6;
};

struct Req_0204CED8 {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u8  unk_06;
    u8  unk_07;
};

struct Obj_0204CED8 {
    u8  pad_00[0x60];
    u32 low     : 8;
    u32 flag_hi : 24;
};

struct Req_0204CF40 {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u32 unk_08;
};

struct Obj_0204CF40 {
    u8  pad_00[0x5c];
    u16 unk_5c;
    u16 unk_5e;
};

extern void func_02067AB8(struct G2dOamState *p, u32 mode);
extern u32 func_0204B658(const struct Actor *actor, u32 which);
extern void func_02067B78(struct G2dOamState *p, u32 h, u32 v);
extern void func_020663D0(s32 x, s32 y, s32 z);
extern void func_020664CC(s32 x, s32 y, s32 z);
extern void func_02066620(s32 a, s32 b);
extern void func_02065CE4(void *a0);
extern void func_02065D4C(void *p);
extern void func_02066080(struct Obj02066080 *c);
extern void sub_0204B8D4(struct Obj_0204CEB4 *o, u32 arg);
extern void sub_0204B49C(struct Actor *o, s16 value, u32 space, u32 axis);
extern void sub_0204B84C(struct Obj_0204CED8 *o, u8 value);
extern void sub_0204B878(struct Obj_0204CED8 *o, u16 value);
extern void sub_0204B95C(struct Actor *a);
extern void sub_0204B784(char *dst, const struct Struct36 *src);
extern void sub_0204B728(struct Obj_0204CF40 *o, const struct Xform *m);
extern s16 g_020A1B38[];


/*
 * Publishes five bitfields of the element's flag word at +0x60 into the
 * render record: the two-bit mode at bits 18-19 through func_02067AB8, the
 * two corner values through func_02067B78 when that mode is zero, then the
 * four-bit value at bits 8-11 into +0x84, bit 24 into +0x90, bits 22-23 into
 * +0x8c and bits 16-17 into +0x88.
 *
 * The +0x84 store is three instructions of arithmetic that computes nothing:
 * `(v | m) & ~(~m)` is `m`, and mwccarm folds every direct spelling of it
 * away.  The cast between the two complements, and the statement boundaries
 * that put the first `mvn` ahead of the `orr`, are what keep all five
 * instructions:
 * docs/idioms/a-cast-between-two-complements-is-what-keeps-both-mvns.md.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x3c (src/pending/func_0204CB44.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204CBB0.c \
 *       --func func_0204CBB0 --addr 0x0204CBB0 --cc 1.1p1 --arm
 */
void func_0204CBB0(struct Elem *e, struct Rec *r)
{
    u32 a, b, v;
    int n;
    u8  m;

    func_02067AB8((struct G2dOamState *)r, e->f_12);

    if (e->f_12 == 0) {
        a = func_0204B658((const struct Actor *)e, 0);
        b = func_0204B658((const struct Actor *)e, 1);
        func_02067B78((struct G2dOamState *)r, b, a);
    }

    m = e->f_08;
    n = ~m;
    v = r->unk_84 | m;
    r->unk_84 = v & ~(u32)n;
    r->unk_90 = e->f_18;
    r->unk_8c = e->f_16;
    r->unk_88 = (u8)e->f_10;
}


#define CONV(d, v) do { s32 _t = (v); if (_t > 0) { (d) = (f32)(_t << 12) + 0.5f; } else { (d) = (f32)(_t << 12) - 0.5f; } } while (0)


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 584 concrete bytes are right; 36 of 40 relocation sites resolve.  The
 * four that do not are the three fan-in-1 callees of the trailing switch:
 *
 *   func_02065CE4  0x02065CE4  104 bytes  -- OPEN (pkt_02065CE4), 4 bytes
 *                                            from EXACT, see
 *                                            docs/notes/func_02065CE4.c.txt
 *   func_02065D4C  0x02065D4C  104 bytes  -- OPEN (pkt_02065D4C), twin of
 *                                            the above, same near miss
 *   func_02066080  0x02066080  220 bytes  -- OPEN (pkt_02065D4C), unattempted
 *
 * Each has exactly one branch reference image-wide and it is the call in this
 * function, so `label` cannot see them and a single function cannot be split.
 * Closing all three turns this file EXACT and makes it the `matched` witness
 * that src/pending/func_0204CB44.c's last open site needs.
 *
 * What it does.  Publishes the cell actor's two coordinate pairs into the
 * render state.  Each s16 field is converted with the same inlined helper:
 * the fixed-point value `v << 12` is turned into a float and rounded half
 * away from zero, `(f32)(v << 12) + 0.5f` for a positive v and
 * `(f32)(v << 12) - 0.5f` otherwise, then truncated back to s32 by the
 * soft-float runtime.  The
 * second pair is published only when the 2-bit field at 0x60 bits 18-19 is
 * set, is followed by a scale (func_020664CC, 0x1000 == FX32_ONE) and a
 * rotation read as a pair of s16 from the table at 0x020A1B38 indexed by
 * `unk_58 >> 4`, and is then undone by publishing the negated pair.  The
 * trailing switch on +0x68 picks the draw path; case 0 splits again on bit 0
 * of +0x64.
 *
 * The add in the first arm is the expression form: mwccarm canonicalises the
 * commutative add so the constant becomes the first operand and the call is
 * `_fadd(0.5f, t)`, which is what the image has.  See
 * docs/idioms/a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-assignment.md
 * (this file was matched earlier as `0.5f - t' / `t += 0.5f' against swapped
 * _fsub/_fadd addresses; 0x0209C95C is the add, 0x0209CB8C the subtract).
 */
void func_0204CC6C(struct Obj_0204CC6C *o)
{
    f32 a, b;
    s32 i;

    CONV(a, o->unk_0e);
    CONV(b, o->unk_0c);
    func_020663D0((s32)b, (s32)a, 0);

    if (o->unk_60_12 != 0) {
        CONV(a, o->unk_12);
        CONV(b, o->unk_10);
        func_020663D0((s32)b, (s32)a, 0);

        func_020664CC(o->unk_14, o->unk_18, 0x1000);

        i = o->unk_58 >> 4;
        func_02066620(g_020A1B38[i * 2], g_020A1B38[i * 2 + 1]);

        CONV(a, o->unk_12);
        CONV(b, o->unk_10);
        func_020663D0(-(s32)b, -(s32)a, 0);
    }

    switch (o->unk_68) {
    case 0:
        if (o->unk_64_0 == 1) {
            func_02065CE4((void *)o->unk_a4);
        } else {
            func_02065D4C(o->unk_74);
        }
        break;
    case 1:
        func_02065D4C(o->unk_74);
        break;
    case 2:
        func_02066080((struct Obj02066080 *)o->unk_74);
        break;
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204CC6C.c \
 *       --func func_0204CC6C --addr 0x0204CC6C --cc 1.1p1 --arm
 */


/*
 * Run the object through sub_0204B8D4, but only when the flag word at +0x60
 * has its seventh bit set.
 *
 * `lsl #6; lsr #31` with nothing that could be a type conversion is a
 * one-bit unsigned bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  The
 * pair names the bit from the top: `lsl #6` says six bits sit above it, so
 * it is bit 25 counting from the least significant end, and this front end
 * allocates bitfields from the least significant end upward, which means
 * twenty-five bits of padding must be declared before it.  Declaring the
 * six-bit pad first instead gives `lsl #25` and is the whole difference
 * between the two spellings.  The guard is `== 1`, not a plain truth test, which
 * is why the comparison survives as an explicit `cmp r1, #1` instead of
 * folding into the shift's flags.
 *
 * sub_0204B8D4 takes one argument; the `ldr r1, [r0, #0x54]` that precedes
 * the call is a second, forwarded value this function reads but that callee
 * ignores (src/pending/sub_0204B8D4.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CEB4.c \
 *       --func sub_0204CEB4 --addr 0x0204CEB4 --cc 1.1p1 --arm
 */
void sub_0204CEB4(struct Obj_0204CEB4 *o)
{
    if (o->enabled == 1) {
        sub_0204B8D4(o, o->unk_54);
    }
}


/*
 * Apply the seven-field request to the object: the two signed halfwords at
 * +0 and +2 are the two axes of the same setter, selected by a trailing
 * 0/1; the byte at +6 replaces the low eight bits of the flag word at
 * +0x60; the byte at +7 and the halfword at +4 go to their own setters, and
 * sub_0204B95C commits the result.
 *
 * `ldrsh` with no immediate offset form is the only evidence that the first
 * two fields are `s16` rather than `u16`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md); the third is
 * `ldrh`, so the request really does mix the two.
 *
 * The flag-word update is a plain `bic #0xff` / `orr`, with no shift on
 * either side, which places the field at bit 0 and fixes its width at
 * eight: the value comes from an `ldrb`, so nothing has to mask it first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CED8.c \
 *       --func sub_0204CED8 --addr 0x0204CED8 --cc 1.1p1 --arm
 */
void sub_0204CED8(struct Obj_0204CED8 *o, const struct Req_0204CED8 *r, u32 space)
{
    sub_0204B49C((struct Actor *)o, r->unk_00, space, 0);
    sub_0204B49C((struct Actor *)o, r->unk_02, space, 1);
    o->low = r->unk_06;
    sub_0204B84C(o, r->unk_07);
    sub_0204B878(o, r->unk_04);
    sub_0204B95C((struct Actor *)o);
}


/*
 * Apply a four-field request to the object: the two words at +4 and +8 go
 * through the setters at 0x0204B784 and 0x0204B728, the two halfwords at +0
 * and +2 are copied straight into the object's +0x5c/+0x5e pair.
 *
 * Both halfwords are loaded before either is stored, which is the ordinary
 * effect of the two loads having no dependence on the stores: reading them
 * one at a time would have interleaved `ldrh`/`strh`.
 *
 * Was capped at MATCH: the PC24 site at +0x1c names 0x0204B728 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing outside the compared range to point at, and the two functions are
 * not contiguous, so no unit can make the site `local` either.  0x0204B728
 * is now EXACT in src/matched/sub_0204B728.c (the blocker there was one
 * `const` on the source pointer of its closing struct assignment, see
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md), and
 * the site resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CF40.c \
 *       --func sub_0204CF40 --addr 0x0204CF40 --cc 1.1p1 --arm
 */
void sub_0204CF40(struct Obj_0204CF40 *o, const struct Req_0204CF40 *r)
{
    sub_0204B784((char *)o, (const struct Struct36 *)r->unk_04);
    sub_0204B728(o, (const struct Xform *)r->unk_08);
    o->unk_5c = r->unk_00;
    o->unk_5e = r->unk_02;
}
