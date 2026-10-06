/*
 * file:     unit_02070D18_p03.c
 * unit:     yes
 * function: func_02071510, func_0207163C, func_02071858
 * address:  0x02071510
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0206DDA4    0x0206DDA4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   g_02148DB0     0x02148DB0  data
 *   g_02149BB4     0x02149BB4  data
 */
typedef unsigned int u32;

struct Obj {
    u32 flags;            /* +0x00 */
    int a[3];             /* +0x04 */
    int b[3];             /* +0x10 */
    int c[3];             /* +0x1c */
    int pad28[9];         /* +0x28 */
    volatile int s[3];    /* +0x4c */
};

typedef unsigned char  u8;

typedef int            s32;

typedef long long      s64;

struct Owner {
    u8  pad_00[0xc4];
    u32 bits[1];
};

struct Obj_0207163C {
    u32 flags;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 mtx[6];
};

struct Idx {
    u8 f0;
    u8 a;
    u8 b;
};

typedef unsigned short u16;

struct Obj_02071858 {
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

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern struct Owner *g_02148DB0;
extern s32 g_02149BB4[][6];


/*
 * Flushes the object's dirty transform components to func_0206DDA4, one
 * call per component group, each gated by a bit of the flag word at +0x00.
 * Bits 3/4 (mask 0x18) select whether the rotation block is sent raw or the
 * translation is pre-scaled by the 1.12 factors at +0x4c; bit 2 suppresses
 * the scaled translation, bit 1 selects the long (0xc) over the short (9)
 * matrix push, and bit 0 suppresses the final component push.
 *
 * Pinned to ../2.0/sp2: see docs/FRONTEND-PINS.md, the "kept branches" tell.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071510.c \
 *       --func func_02071510 --addr 0x02071510 --cc ../2.0/sp2 --arm
 */
void func_02071510(struct Obj *o)
{
    int tmp[3];
    int flag = 0;
    int m;

    m = o->flags & 0x18;
    if (m == 0)
        func_0206DDA4(0x1b, &o->c[0], 3);

    if (!(o->flags & 4)) {
        if (m != 0) {
            flag = 1;
        } else {
            tmp[0] = (int)(((long long)o->s[0] * o->b[0]) >> 12);
            tmp[1] = (int)(((long long)o->s[1] * o->b[1]) >> 12);
            tmp[2] = (int)(((long long)o->s[2] * o->b[2]) >> 12);
            func_0206DDA4(0x1c, tmp, 3);
        }
    }

    if (!(o->flags & 2)) {
        if (flag) func_0206DDA4(0x19, &o->pad28[0], 0xc);
        else      func_0206DDA4(0x1a, &o->pad28[0], 9);
    } else if (flag) {
        func_0206DDA4(0x1c, (void *)&o->s[0], 3);
    }

    if (m == 0)
        func_0206DDA4(0x1b, &o->b[0], 3);

    if (!(o->flags & 1))
        func_0206DDA4(0x1b, &o->a[0], 3);
}



/*
 * The matrix-slot propagation step of the cluster_02071360 transform
 * stage.  `idx` names two slots of the 0x18-byte record table at
 * 0x02149BB4 (a = idx[1], b = idx[2]); the owner at *0x02148DB0 carries
 * a per-slot bitmask at +0xC4.
 *   flags & 4:  set o->flags bit 0; if b's bit is set, set a's bit and
 *               o->flags |= 0x18; otherwise copy record b over record a
 *               and into o->mtx.
 *   otherwise:  copy m[0..2] into o->f04..f0c; if b's bit is set, copy m
 *               into record a, clear a's bit, o->flags |= 0x18; otherwise
 *               clear a's bit, record a = m * record b component-wise in
 *               1.12 ((s64)x*y >> 12, six terms) and copy record b into
 *               o->mtx.
 *
 * THE SIX POOL WORDS.  The image's pool holds 0x02149BB4, ...BB8, ...BBC,
 * ...BC0, ...BC4, ...BC8: not six objects but ONE `s32 [][6]` table,
 * whose column k is addressed as symbol+4k because a register-offset
 * `ldr r, [base, ip]` has no room for a further immediate.  The single
 * 2-D extern reproduces all six words (sole-ref/self per site).
 *
 * The callee is MIi_CpuCopy32 (src, dst, size), SOURCE FIRST: the first
 * argument of every call here is the record being read.
 *
 * Pin evidence (2.0): "kept constants".  The image rematerialises the
 * copy size `mov r2, #0x18` before each call; dsi/1.1p1 keeps 0x18 in a
 * callee-saved register and copies it (`mov r2, r6`), 536 bytes against
 * 540 with 362 concrete bytes out.  Under ../2.0/sp2 the same C is 540
 * bytes, 0 out, first compile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0207163C.c \
 *       --func func_0207163C --addr 0x0207163C --arm --cc ../2.0/sp2
 */
void func_0207163C(struct Obj_0207163C *o, s32 *m, struct Idx *idx, u32 flags)
{
    u32 a = idx->a;
    u32 b = idx->b;

    if (flags & 4) {
        o->flags |= 1;
        if (g_02148DB0->bits[b >> 5] & (1 << (b & 0x1f))) {
            g_02148DB0->bits[a >> 5] |= 1 << (a & 0x1f);
            o->flags |= 0x18;
            return;
        }
        MIi_CpuCopy32(g_02149BB4[b], g_02149BB4[a], 0x18);
        MIi_CpuCopy32(g_02149BB4[b], o->mtx, 0x18);
        return;
    }

    o->f04 = m[0];
    o->f08 = m[1];
    o->f0c = m[2];
    if (g_02148DB0->bits[b >> 5] & (1 << (b & 0x1f))) {
        MIi_CpuCopy32(m, g_02149BB4[a], 0x18);
        g_02148DB0->bits[a >> 5] &= ~(1 << (a & 0x1f));
        o->flags |= 0x18;
        return;
    }
    g_02148DB0->bits[a >> 5] &= ~(1 << (a & 0x1f));
    g_02149BB4[a][0] = (s32)(((s64)m[0] * g_02149BB4[b][0]) >> 12);
    g_02149BB4[a][1] = (s32)(((s64)m[1] * g_02149BB4[b][1]) >> 12);
    g_02149BB4[a][2] = (s32)(((s64)m[2] * g_02149BB4[b][2]) >> 12);
    g_02149BB4[a][3] = (s32)(((s64)m[3] * g_02149BB4[b][3]) >> 12);
    g_02149BB4[a][4] = (s32)(((s64)m[4] * g_02149BB4[b][4]) >> 12);
    g_02149BB4[a][5] = (s32)(((s64)m[5] * g_02149BB4[b][5]) >> 12);
    MIi_CpuCopy32(g_02149BB4[b], o->mtx, 0x18);
}


/*
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
 */
void func_02071858(struct Obj_02071858 *o)
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
