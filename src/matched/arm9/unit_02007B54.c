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
 * function: PERAPVOICE_ClearRecorded, PERAPVOICE_SetRecorded, PERAPVOICE_GetSamples, PERAPVOICE_Unpack,
 *           PERAPVOICE_Pack, PERAPVOICE_Copy, PERAPVOICE_ClearIfNoChatot, PERAPVOICE_GetVoiceKind
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   PERAPVOICE_IsRecorded   0x02007B50  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *
 * The rest of "perapvoice.c", which src/matched/unit_02007AC8.c opens.  That
 * file names the object: its constructor allocates 0x3EC bytes and its clear
 * routine zeroes 0x3EC, and the same 0x3EC is what PERAPVOICE_Copy copies here.
 * The object is one `u32` flag followed by 1000 bytes, and PERAPVOICE_IsRecorded in
 * the neighbouring file reads the flag that PERAPVOICE_ClearRecorded and PERAPVOICE_SetRecorded
 * write.
 *
 * Four of the eight carry no label, because none of them saves lr.
 * PERAPVOICE_SetRecorded is the `= 1` twin of PERAPVOICE_ClearRecorded, PERAPVOICE_GetSamples returns the
 * address of the payload, PERAPVOICE_Unpack and PERAPVOICE_Pack are the codec pair,
 * and PERAPVOICE_Copy is a tail call into MI_CpuCopy8.
 *
 * What the range teaches:
 *
 *  - the payload is 1000 bytes holding two signed four bit samples each.
 *    PERAPVOICE_Unpack expands them to 8000 bytes, four copies of each sample in
 *    the high nibble of a byte, and zero fills to 0x1FF4; PERAPVOICE_Pack is the
 *    exact inverse, 0x1F40 bytes in and 1000 out.  The bias of eight in both
 *    directions is what makes the four bit field signed.
 *  - the `lsls #28` / `asrs #24` pair at the end of each expansion is
 *    `(s8)(v << 4)` and not `v << 4`: the truncation is materialised because
 *    the value is assigned to an `s8` local before the inner store loop, and
 *    writing the shift straight into the store gives `lsls #4` alone.
 *  - PERAPVOICE_Pack packs the two nibbles into one byte with a plain store
 *    followed by an `|=`, which is why the byte is stored, reloaded with
 *    `ldrb` and stored again.  Neither half is masked on the way in, so the
 *    source is two `u8` statements and not a bitfield.
 *  - PERAPVOICE_Unpack reloads `src[i]` for the second nibble rather than keeping
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

extern u32 PERAPVOICE_IsRecorded(const struct PerapVoice *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);

void PERAPVOICE_ClearRecorded(struct PerapVoice *p);

void PERAPVOICE_ClearRecorded(struct PerapVoice *p)
{
    p->unk00 = 0;
}

void PERAPVOICE_SetRecorded(struct PerapVoice *p)
{
    p->unk00 = 1;
}

u8 *PERAPVOICE_GetSamples(struct PerapVoice *p)
{
    return p->data;
}

void PERAPVOICE_Unpack(s8 *dest, const s8 *src)
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

void PERAPVOICE_Pack(struct PerapVoice *p, const s8 *src)
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

void PERAPVOICE_Copy(struct PerapVoice *dest, const struct PerapVoice *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PerapVoice));
}

void PERAPVOICE_ClearIfNoChatot(struct PerapVoice *p, void *a)
{
    int i;
    int n = POKEPARTY_GetCount(a);

    for (i = 0; i < n; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(a, i), 5, 0) == 0x1B9) {
            return;
        }
    }
    PERAPVOICE_ClearRecorded(p);
}

u32 PERAPVOICE_GetVoiceKind(struct PerapVoice *p)
{
    if (PERAPVOICE_IsRecorded(p) == 1) {
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
