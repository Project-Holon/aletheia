/*
 * function: func_02070A24
 * address:  0x02070A24
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * symbols:
 *   func_0206E62C  0x0206E62C  arm
 *   func_0207C768  0x0207C768  arm
 *
 * Applies a keyframe sample to a render record: reads a descriptor through
 * func_0206E62C, rewrites the record's f10 flags word, unpacks two 11-bit
 * subfields into the record's f2c/f2e halfwords, and for each builds a scale
 * via func_0207C768 (or the identity 0x1000 when the value is unchanged).
 *
 * VERDICT: DIFF 60 at the original's exact 216 bytes, with all three PC24
 * relocations resolving `label`, so the row stays evidence-complete. Every
 * instruction is the right instruction in the right place; the whole
 * difference is one allocator decision applied uniformly, the image holding
 * the 0x7ff field mask in r2 and the working value in r1 and this compile
 * holding them the other way round. Full evidence, the three levers that got
 * here, and what does NOT move the swap are in docs/notes/func_02070A24.c.txt.
 *
 * THE SOURCE FIELDS ARE 16-BIT BITFIELDS, and that is what makes the
 * `bic r5, r1, #0xe0000000` at 0x02070A64 survive at all. A `u32 x : 16` read
 * is a word `ldr` plus an unfoldable `lsl #16` / `lsr #16` pair, so the mask
 * on the plain u32 local that receives it is not provably dead. Spelled as a
 * u16 field or a u16 local the compiler folds the mask away and then folds
 * the surviving `lsr #16` into `add r2, r3, r2, lsr #16` for 212 bytes: that
 * four-byte wall is what this file's previous note recorded as unbroken.
 *
 * An EXACT here is one of the five `matched` witnesses that would unblock the
 * byte-correct 116-byte src/pending/func_02070B64.c.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;

struct S {
    u8  pad_00[8];
    u32 f8  : 16;
    u32 f8h : 16;
    u8  pad_0c[0x0c];
    u32 f18  : 16;
    u32 f18h : 16;
    u8  pad_1c[0x20];
};

struct T {
    u8  pad_00[0x10];
    u32 f10;
    u8  pad_14[0x18];
    u16 f2c;
    u16 f2e;
    s32 f30;
    s32 f34;
};

extern u32 *func_0206E62C(void *p);
extern s32  func_0207C768(s32 a, s32 b);

void func_02070A24(struct S *s, u32 *src, struct T *t)
{
    u32 *p;
    u32 m;
    u32 q;
    u32 k;
    s32 r;

    if (s == 0)
        p = 0;
    else
        p = func_0206E62C((void *)((char *)s + 0x3c));

    m = t->f10;
    k = 0x7ff;
    if ((p[0] & 0x1c000000) != 0x14000000)
        q = s->f8;
    else
        q = s->f18;
    q = q & ~0xe0000000u;

    m = m & 0xc00f0000u;
    t->f10 = m;
    t->f10 = m | (p[0] + q);

    t->f2c = (u16)(p[1] & k);
    t->f2e = (u16)((p[1] & (k << 11)) >> 11);
    {
        u32 v = p[1];
        u32 a = v & k, b = (v & (k << 11)) >> 11, c;
        c = t->f2c;
        if (a == c) r = 0x1000; else r = func_0207C768(a << 12, c << 12);
        t->f30 = r;
        c = t->f2e;
        if (b == c) r = 0x1000; else r = func_0207C768(b << 12, c << 12);
        t->f34 = r;
    }

}
