/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008EAC
 * packet:   pkt_02008CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MAIL_Init
 *
 * symbols:
 *   unk_0209DF0C   0x0209DF0C  data
 *   unk_0209DF08   0x0209DF08  data
 *   func_02045A98  0x02045A98  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   MIi_CpuClear16 0x02082A48  arm
 *
 * alias: the constructor of a 0x38-byte record.  It is the last function of
 * the file that begins at 0x02008C20 with the 0x26 save block, or the first of
 * the next one; nothing in the bytes separates them, so it is kept as its own
 * range.
 *
 * The two byte globals it seeds the record from are 0x0209DF0C and 0x0209DF08,
 * and each is also loaded from a pool word in 005_02013528.s, at 0x020178C8
 * and 0x020178D4, which is what attests them.
 *
 * `MI_CpuFill16` is the SDK header's inline wrapper: it compiles to a direct
 * `blx MIi_CpuClear16` with the data and destination swapped, which is exactly
 * what the original does.  Calling MIi_CpuClear16 by hand would produce the
 * same bytes, but the wrapper is what the source said.
 *
 * The 0xFFFF at +0x1E is a pool word rather than a `movs`, because the Thumb
 * immediate stops at 255; the 0xFF at +7 is a `movs`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008EAC.c \
 *       --addr 0x02008EAC --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 unk_0209DF0C;
extern const u8 unk_0209DF08;

extern u16  func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);

static inline void MI_CpuFill16(void *dest, u16 data, u32 size)
{
    MIi_CpuClear16(data, dest, size);
}

struct Sub0202428CObj {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
};

extern void PMSI_PARAM_ClearSentence(void *obj);

struct Sub02008EACObj {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u16 unk08[8];
    u16 unk18[3];
    u16 unk1E;
    struct Sub0202428CObj unk20[3];
};

void MAIL_Init(struct Sub02008EACObj *obj)
{
    int i;

    obj->unk00 = 0;
    obj->unk04 = 0;
    obj->unk05 = unk_0209DF0C;
    obj->unk06 = unk_0209DF08;
    obj->unk07 = 0xFF;
    MI_CpuFill16(obj->unk08, func_02045A98(), sizeof(obj->unk08));
    obj->unk1E = 0xFFFF;
    for (i = 0; i < 3; i++) {
        PMSI_PARAM_ClearSentence(&obj->unk20[i]);
    }
}
