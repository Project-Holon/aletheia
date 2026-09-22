/*
 * function: func_02071858
 * address:  0x02071858
 * packet:   pkt_02071360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 0x4c-byte display-descriptor builder of the 0x020713C8 family: fills a
 * 15-word descriptor on the stack, selects the translation source out of the
 * flag word's bits 3 / 2 / 0, applies the object's two 1.12 scale factors at
 * +0x30 / +0x34 when they are not unity, and hands the whole thing to
 * func_0206DDA4 with a count of 0xe.
 *
 * PINNED ../2.0/sp2 on the "kept branches" tell, the same pin its family-mate
 * src/matched/func_02071510.c carries (see docs/FRONTEND-PINS.md).  The image
 * emits REAL branches for the three-way translation select: `beq 0x20718f0`
 * at +0x5C, `beq 0x20718dc` at +0x70, `b 0x2071990` at +0x80 and again at
 * +0x94.  dsi/1.1p1 -O4,p if-converts the two inner arms into predicated
 * `movne`/`strne` + `ldreq`/`streq` runs and drops both `b`s, giving 440
 * bytes against the original's 452 with everything after +0x60 shifted.  No
 * source shape recovers them under 1.1p1: measured with the arms written as
 * `goto`-terminated blocks (440), with the second test reading a cached local
 * (436), and with each arm carrying its own tail (440).  Under the pin the
 * same C is 460 bytes including the two trailing pool words, 0 mismatches.
 *
 * TWO FIELD TELLS, both `volatile`, both needed:
 *   +0x00 flags   the INNER test at +0x68 re-reads the flag word
 *                 (`ldr r1, [r0]`) although +0x54 has it in r1 already.
 *   +0x30, +0x34  each scale factor is loaded TWICE, once for the `cmp`
 *                 against 0x1000 and again for the second `smull`
 *                 (`ldr r2, [r0, #0x30]` at +0x15C).  Non-volatile, 1.1p1
 *                 and 2.0 both cache the field and batch the two multiplies,
 *                 which is 8 bytes short.  This is the same re-read the
 *                 family-mate func_020713C8 documents for its own +0x30/+0x34
 *                 pair.
 *
 * AND ONE NON-VOLATILE READ.  The OUTER else-branch at +0x98 reuses the flag
 * value already in r1 rather than re-reading it, so `o->flags & 1` cannot be
 * written against the volatile field there: it is cached in the local `fl`
 * taken before the `& 4` test.  Spelling that test volatile too costs exactly
 * one `ldr r1, [r0]` and shifts the whole tail by four bytes -- this was the
 * last four bytes of the function, and the only difference between 448 and
 * EXACT.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071858.c \
 *       --func func_02071858 --addr 0x02071858 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   func_0206DDA4    0x0206DDA4  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

struct Obj {
    volatile u32 flags;   /* +0x00 */
    u8  pad_04[0x14];
    s32 f18;
    s32 f1c;
    u8  pad_20[4];
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
    s32 f30;
    s32 f34;
};

extern void func_0206DDA4(u32 hdr, int *body, int n);

void func_02071858(struct Obj *o)
{
    int buf[0x0f];
    s32 sc;
    u32 fl;

    if (o->flags & 8) buf[0] = 0x00101710;
    else              buf[0] = 0x00101910;

    buf[1] = 3;
    buf[0x0d] = 0;
    buf[0x0a] = 0;
    buf[9] = 0;
    buf[8] = 0;
    buf[7] = 0;
    buf[5] = 0;
    buf[4] = 0;
    buf[3] = 0;
    buf[0x0e] = 2;

    fl = o->flags;
    if (fl & 4) {
        buf[0x0b] = 0;
        buf[0x0c] = 0;
        if (o->flags & 1) {
            buf[2] = 0x1000;
            buf[6] = 0x1000;
        } else {
            buf[2] = o->f18;
            buf[6] = o->f1c;
        }
    } else if (fl & 1) {
        buf[0x0b] = (0 - (o->f24 << 4)) * (s32)o->f2c;
        buf[0x0c] = (0 - (o->f28 << 4)) * (s32)o->f2e;
        buf[2] = 0x1000;
        buf[6] = 0x1000;
    } else {
        buf[0x0b] = (s32)o->f2c * (0 - (s32)(((s64)o->f18 * o->f24) >> 8));
        buf[0x0c] = (s32)o->f2e * (0 - (s32)(((s64)o->f1c * o->f28) >> 8));
        buf[2] = o->f18;
        buf[6] = o->f1c;
    }

    sc = o->f30;
    if (sc != 0x1000) {
        buf[2]    = (s32)(((s64)sc * buf[2]) >> 12);
        buf[0x0b] = (s32)(((s64)o->f30 * buf[0x0b]) >> 12);
    }
    sc = o->f34;
    if (sc != 0x1000) {
        buf[6]    = (s32)(((s64)sc * buf[6]) >> 12);
        buf[0x0c] = (s32)(((s64)o->f34 * buf[0x0c]) >> 12);
    }

    {
        char *q = (char *)buf;
        func_0206DDA4((u32)buf[0], (int *)(q + 4), 0x0e);
    }
}
