/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007B54
 * packet:   pkt_02007B54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007B54, sub_02007B5C, sub_02007B64, sub_02007B68,
 *           sub_02007BD0, sub_02007C20, sub_02007C34, sub_02007C70
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   sub_02007B50   0x02007B50  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *
 * The rest of "perapvoice.c", which src/matched/unit_02007AC8.c opens.  That
 * file names the object: its constructor allocates 0x3EC bytes and its clear
 * routine zeroes 0x3EC, and the same 0x3EC is what sub_02007C20 copies here.
 * The object is one `u32` flag followed by 1000 bytes, and sub_02007B50 in
 * the neighbouring file reads the flag that sub_02007B54 and sub_02007B5C
 * write.
 *
 * Four of the eight carry no label, because none of them saves lr.
 * sub_02007B5C is the `= 1` twin of sub_02007B54, sub_02007B64 returns the
 * address of the payload, sub_02007B68 and sub_02007BD0 are the codec pair,
 * and sub_02007C20 is a tail call into MI_CpuCopy8.
 *
 * What the range teaches:
 *
 *  - the payload is 1000 bytes holding two signed four bit samples each.
 *    sub_02007B68 expands them to 8000 bytes, four copies of each sample in
 *    the high nibble of a byte, and zero fills to 0x1FF4; sub_02007BD0 is the
 *    exact inverse, 0x1F40 bytes in and 1000 out.  The bias of eight in both
 *    directions is what makes the four bit field signed.
 *  - the `lsls #28` / `asrs #24` pair at the end of each expansion is
 *    `(s8)(v << 4)` and not `v << 4`: the truncation is materialised because
 *    the value is assigned to an `s8` local before the inner store loop, and
 *    writing the shift straight into the store gives `lsls #4` alone.
 *  - sub_02007BD0 packs the two nibbles into one byte with a plain store
 *    followed by an `|=`, which is why the byte is stored, reloaded with
 *    `ldrb` and stored again.  Neither half is masked on the way in, so the
 *    source is two `u8` statements and not a bitfield.
 *  - sub_02007B68 reloads `src[i]` for the second nibble rather than keeping
 *    it: source and destination are both `s8 *`, so the stores in between may
 *    alias and the compiler has to re-read.
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

struct PerapVoice {
    u32 unk00;
    u8  data[1000];
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern u32 sub_02007B50(const struct PerapVoice *p);
extern int func_0201AA18(void *a);
extern void *func_0201AB28(void *a, int i);
extern u32 func_02017E1C(void *a, u32 b, u32 c);

void sub_02007B54(struct PerapVoice *p);

void sub_02007B54(struct PerapVoice *p)
{
    p->unk00 = 0;
}

void sub_02007B5C(struct PerapVoice *p)
{
    p->unk00 = 1;
}

u8 *sub_02007B64(struct PerapVoice *p)
{
    return p->data;
}

void sub_02007B68(s8 *dest, const s8 *src)
{
    int i;
    int j;
    int o;

    o = 0;
    for (i = 0; i < 1000; i++) {
        s8 a = (s8)((s8)((u8)(src[i] & 0xF) - 8) << 4);

        for (j = 0; j < 4; j++) {
            dest[o + j] = a;
        }
        {
            s8 b = (s8)((s8)((u8)(src[i] >> 4) - 8) << 4);

            for (j = 4; j < 8; j++) {
                dest[o + j] = b;
            }
        }
        o += 8;
    }
    for (i = 1000 * 8; i < 0x1FF4; i++) {
        dest[i] = 0;
    }
}

void sub_02007BD0(struct PerapVoice *p, const s8 *src)
{
    int i;
    int j;

    p->unk00 = 1;
    j = 0;
    for (i = 0; i < 0x1F40; i += 8) {
        u8 lo = (u8)((s8)(src[i] / 16) + 8);

        p->data[j] = lo;
        {
            u8 hi = (u8)((s8)(src[i + 4] / 16) + 8);

            p->data[j] |= (u8)(hi << 4);
        }
        j++;
    }
}

void sub_02007C20(struct PerapVoice *dest, const struct PerapVoice *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PerapVoice));
}

void sub_02007C34(struct PerapVoice *p, void *a)
{
    int i;
    int n = func_0201AA18(a);

    for (i = 0; i < n; i++) {
        if (func_02017E1C(func_0201AB28(a, i), 5, 0) == 0x1B9) {
            return;
        }
    }
    sub_02007B54(p);
}

u32 sub_02007C70(struct PerapVoice *p)
{
    if (sub_02007B50(p) == 1) {
        u8 v = (u8)(p->data[0x64] ^ p->data[0x1F4] ^ p->data[0x2BC]);

        if (v < 100) {
            return 1;
        }
        if (v >= 150 && v < 256) {
            return 2;
        }
    }
    return 0;
}
