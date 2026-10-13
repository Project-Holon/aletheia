/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: CLACT_ApplyActorTransform
 * address:  0x0204CC6C
 * packet:   pkt_0204CC6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 * that src/pending/CLACT_DrawActor.c's last open site needs.
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
 *
 * symbols:
 *   func_020663D0  0x020663D0  arm
 *   func_020664CC  0x020664CC  arm
 *   func_02066620  0x02066620  arm
 *   func_02065CE4  0x02065CE4  arm
 *   func_02065D4C  0x02065D4C  arm
 *   func_02066080  0x02066080  arm
 *   FX_SinCosTable_     0x020A1B38  data
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef float          f32;

struct Obj {
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

extern s16 FX_SinCosTable_[];

extern void func_020663D0(s32 x, s32 y, s32 z);
extern void func_020664CC(s32 x, s32 y, s32 z);
extern void func_02066620(s32 a, s32 b);
extern void func_02065CE4(void *a0);
extern void func_02065D4C(void *p);
struct Obj02066080;
extern void func_02066080(struct Obj02066080 *c);

#define CONV(d, v) do { s32 _t = (v); if (_t > 0) { (d) = (f32)(_t << 12) + 0.5f; } else { (d) = (f32)(_t << 12) - 0.5f; } } while (0)

void CLACT_ApplyActorTransform(struct Obj *o)
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
        func_02066620(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);

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
 *   python tools/match.py one --src src/pending/CLACT_ApplyActorTransform.c \
 *       --func CLACT_ApplyActorTransform --addr 0x0204CC6C --cc 1.1p1 --arm
 */
