/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D59C
 * packet:   pkt_0200D59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200D59C, func_0200D5C8
 *
 * 52 bytes, 0x0200D59C..0x0200D5D0, 2 functions, one of which carries no
 * label in the generated listing.
 *
 * alias: 0x020A71E8 spells "gds_profile.c", the sixth original source file
 * name this project has recovered, attested by the `string` class off the
 * terminator of "musical_dist_save.c" at 0x020A71E6.  The constructor at
 * 0x0200D59C passes it to the debug allocator at 0x02030734 with line 0x50,
 * and the rest of the file is src/matched/unit_0200D6D0.c,
 * src/matched/unit_0200D6EC.c and src/matched/unit_0200D74C.c, with
 * func_0200D5D0 the one function of it left out; see below.
 *
 * The record is 0x80 bytes, which is what the constructor allocates and
 * clears, and which src/matched/unit_0200D5D0.c fills field by field.
 *
 * The heap id is a full word cast to `u16` at the call, not a `u16`
 * parameter: this front end assumes an incoming `u16` parameter is already
 * zero extended and emits nothing, so the `lsls #0x10` / `lsrs #0x10` pair at
 * 0x0200D5A2 is a narrowing the source wrote.  The same reading applies to
 * the tag parameters of func_0200D6D0 and func_0200D774.
 *
 * func_0200D5C8 is the destructor and is eight bytes: a pool word and a `bx`,
 * with no argument set-up at all; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Left out of this range: func_0200D5D0, 256 bytes, which builds the whole
 * record.  Every concrete byte of it reproduces and it is capped at MATCH,
 * because 0x0200C164 is the target of exactly one branch in the image, its
 * own call at 0x0200D610, so the `label` class has no witness outside the
 * compared range and no cut helps.  The source is parked in
 * src/matched/unit_0200D5D0.c.
 *
 * symbols:
 *   MI_CpuFill8         0x02082BCC  arm
 *   func_020307B0       0x020307B0  arm
 *   func_0200D59C_File  0x020A71E8  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char func_0200D59C_File[];
extern u32 func_020307B0(void *p);

struct Bits1B {
    u8 f0 : 1;
    u8 f1 : 6;
    u8 f7 : 1;
};

struct GdsProfile {
    u8  unk00[0x10];
    u32 unk10;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    struct Bits1B unk1B;
    u16 unk1C;
    u8  unk1E;
    u8  unk1F;
    u16 unk20[0x28];
    u8  unk70[0x0C];
    u16 unk7C;
    u16 unk7E;
};

struct GdsProfile *func_0200D59C(u32 heap)
{
    struct GdsProfile *p = func_02030734((u16)heap, sizeof(struct GdsProfile),
                                         0, func_0200D59C_File, 0x50);

    MI_CpuFill8(p, 0, sizeof(struct GdsProfile));
    return p;
}

void func_0200D5C8(struct GdsProfile *p)
{
    func_020307B0(p);
}
