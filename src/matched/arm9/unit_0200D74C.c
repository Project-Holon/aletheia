/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D74C
 * packet:   pkt_0200D74C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GDS_PROFILE_GetRecordWord1C, GDS_PROFILE_GetRecordWord30, GDS_PROFILE_ExportRecord, GDS_PROFILE_GetVariant,
 *           GDS_PROFILE_GetCountry, GDS_PROFILE_GetMode
 *
 * 268 bytes, 0x0200D74C..0x0200D858, 6 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: the tail of "gds_profile.c"; the constructor at 0x0200D59C names
 * 0x020A71E8, see src/matched/unit_0200D59C.c.
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   PMSI_PARAM_InitSentence  0x020242A4  thumb
 *   PMS_WORD_MakeWordId  0x02024888  thumb
 *   PMS_WORD_SplitWordId  0x020248D8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern int PMS_WORD_SplitWordId(u32 v, u32 *a1, u32 *a2);
extern void  PMSI_PARAM_InitSentence(void *rec, u32 n);
extern u16 PMS_WORD_MakeWordId(u32 idx, u16 add);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 size);

struct GdsRecord {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u8  unk08[0x20];
};

struct GdsProfile {
    u8  unk00[0x15];
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B[3];
    u8  unk1E;
    u8  unk1F;
    struct GdsRecord unk20;
};

u32 GDS_PROFILE_GetMode(struct GdsProfile *p);

u32 GDS_PROFILE_GetRecordWord1C(struct GdsProfile *p)
{
    return func_02025C1C(p->unk17, p->unk18, GDS_PROFILE_GetMode(p));
}

u32 GDS_PROFILE_GetRecordWord30(struct GdsProfile *p)
{
    return func_02025C30(p->unk17, p->unk18, GDS_PROFILE_GetMode(p));
}

void *GDS_PROFILE_ExportRecord(struct GdsProfile *p, struct GdsRecord *out, u32 tag)
{
    u32 a;
    u32 b;
    s32 n = 0;

    if (p->unk1E == 0) {
        out->unk00 = p->unk20.unk00;
        out->unk02 = p->unk20.unk02;
        out->unk04 = p->unk20.unk04;
        out->unk06 = p->unk20.unk06;
        if (out->unk00 >= 5) {
            n++;
            goto chk;
        }
        if (out->unk02 > 0x13) {
            n++;
            goto chk;
        }
        if ((out->unk04 != 0xFFFF && PMS_WORD_SplitWordId(out->unk04, &a, &b) == 0)
            || (out->unk06 != 0xFFFF
                && PMS_WORD_SplitWordId(out->unk06, &a, &b) == 0)) {
            n++;
        }
    chk:
        if (n > 0) {
            PMSI_PARAM_InitSentence(out, 4);
            out->unk02 = 0;
            out->unk04 = PMS_WORD_MakeWordId(0x95, 0x1D);
            out->unk06 = 0xFFFF;
        }
        return 0;
    } else {
        void *h = STRBUF_Create(0x28, (u16)tag);

        STRBUF_SetStringN(h, (const u16 *)&p->unk20, sizeof(p->unk20));
        return h;
    }
}

u32 GDS_PROFILE_GetVariant(struct GdsProfile *p)
{
    u32 v = p->unk15;

    if (v < 1 || v > 0xC) {
        v = 1;
    }
    return v;
}

u32 GDS_PROFILE_GetCountry(struct GdsProfile *p)
{
    u32 v = p->unk16;

    if (v > 0xF) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetMode(struct GdsProfile *p)
{
    u32 v = p->unk1A;

    switch (v) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
        return v;
    }
    return 2;
}
