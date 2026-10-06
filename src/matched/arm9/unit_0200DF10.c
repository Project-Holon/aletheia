/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200DF10
 * packet:   pkt_0200DDD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200DF10, func_0200DF40, func_0200DF4C, func_0200DF58,
 *           func_0200DF94, func_0200DFB4, func_0200DFCC
 *
 * 200 bytes, 0x0200DF10..0x0200DFD8, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71F8 spells "bsubway_savedata.c", the fifth original source
 * file name this project has recovered, attested by the `string` class off
 * the terminator of "gds_profile.c" at 0x020A71F5.  func_0200DF58 passes it
 * to the debug allocator at 0x02030734 with line 0x508.
 *
 * The second slot of the record whose first slot is
 * src/matched/unit_0200DE5C.c: a 0x3FC-byte payload at +0x794 behind a
 * present flag at +0xFF and two byte tags at +0x102 and +0x103.  0x3FC is
 * thirty entries of 0x22 bytes, which is what func_0200DF94 walks, so the
 * payload's element type is pinned by the stride rather than assumed.
 *
 * Three details are worth having.
 *
 *  - func_0200DF58 allocates a copy of the payload and returns it; the size
 *    0x3FC is live in r6 across the allocation and is used again as the copy
 *    length, which is what writing it as `sizeof` at both sites gives.
 *  - in func_0200DF94 the loop index is declared **before** the counter even
 *    though the counter is the one assigned first in the output.  Declared
 *    the other way round the two swap registers and nothing else moves; see
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *  - func_0200DFB4 assembles a little-endian word out of four bytes and the
 *    compiler schedules the loads 0x16, 0x17, 0x14, 0x15, which is not the
 *    source order.  Every spelling tried, field by field or through an array,
 *    with or without casts on the operands, produces exactly these bytes, so
 *    the schedule says nothing about how it was written.
 *
 * symbols:
 *   MI_CpuCopy8         0x02082D44  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   func_0200DF58_File  0x020A71F8  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char func_0200DF58_File[];

struct SubEnt {
    u16 unk00;
    u8  unk02[0x12];
    u8  unk14[4];
    u8  unk18[0x0A];
};

struct Buf3FC {
    struct SubEnt ent[30];
};

struct RecSlot {
    u8 unk000[0xFE];
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    u8 unk101;
    u8 unk102;
    u8 unk103;
    u8 unk104[0x794 - 0x104];
    struct Buf3FC unk794;
};

void func_0200DF10(struct RecSlot *p, const void *src, u8 a, u8 b)
{
    MI_CpuCopy8(src, &p->unk794, sizeof(p->unk794));
    p->unk103 = a;
    p->unk102 = b;
    p->unkFF = 1;
}

int func_0200DF40(struct RecSlot *p)
{
    return p->unk103;
}

u8 func_0200DF4C(struct RecSlot *p)
{
    return p->unk102;
}

struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap)
{
    struct Buf3FC *copy = func_02030734(heap, sizeof(p->unk794), 1,
                                        func_0200DF58_File, 0x508);

    MI_CpuCopy8(&p->unk794, copy, sizeof(p->unk794));
    return copy;
}

u32 func_0200DF94(struct Buf3FC *b)
{
    s32 i;
    u32 n = 0;

    for (i = 0; i < 30; i++) {
        if (b->ent[i].unk00 != 0) {
            n++;
        }
    }
    return n;
}

u32 func_0200DFB4(struct SubEnt *e)
{
    return e->unk14[0] | (e->unk14[1] << 8) | (e->unk14[2] << 16)
           | (e->unk14[3] << 24);
}

void func_0200DFCC(void *p)
{
    MI_CpuFill8(p, 0, 0x42);
}
