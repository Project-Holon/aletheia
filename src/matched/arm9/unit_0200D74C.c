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
 * function: func_0200D74C, func_0200D760, func_0200D774, func_0200D810,
 *           func_0200D820, func_0200D82C
 *
 * 268 bytes, 0x0200D74C..0x0200D858, 6 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: the tail of "gds_profile.c"; the constructor at 0x0200D59C names
 * 0x020A71E8, see src/matched/unit_0200D59C.c.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern int func_020248D8(u32 v, u32 *a1, u32 *a2);
extern void  func_020242A4(void *rec, u32 n);
extern u16 func_02024888(u32 idx, u16 add);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);

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

u32 func_0200D82C(struct GdsProfile *p);

u32 func_0200D74C(struct GdsProfile *p)
{
    return func_02025C1C(p->unk17, p->unk18, func_0200D82C(p));
}

void func_0200D760(struct GdsProfile *p)
{
    func_02025C30(p->unk17, p->unk18, func_0200D82C(p));
}

void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag)
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
        if ((out->unk04 != 0xFFFF && func_020248D8(out->unk04, &a, &b) == 0)
            || (out->unk06 != 0xFFFF
                && func_020248D8(out->unk06, &a, &b) == 0)) {
            n++;
        }
    chk:
        if (n > 0) {
            func_020242A4(out, 4);
            out->unk02 = 0;
            out->unk04 = func_02024888(0x95, 0x1D);
            out->unk06 = 0xFFFF;
        }
        return 0;
    } else {
        void *h = func_020457B0(0x28, (u16)tag);

        func_02045994(h, (const u16 *)&p->unk20, sizeof(p->unk20));
        return h;
    }
}

u32 func_0200D810(struct GdsProfile *p)
{
    u32 v = p->unk15;

    if (v < 1 || v > 0xC) {
        v = 1;
    }
    return v;
}

u32 func_0200D820(struct GdsProfile *p)
{
    u32 v = p->unk16;

    if (v > 0xF) {
        v = 0;
    }
    return v;
}

u32 func_0200D82C(struct GdsProfile *p)
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
