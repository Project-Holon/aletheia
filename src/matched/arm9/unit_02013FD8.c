/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013FD8
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02013FD8, sub_02013FEC, sub_02013FFC, sub_0201400C,
 *           sub_02014018, sub_02014024, sub_02014034, sub_02014044,
 *           sub_0201405C, sub_02014068
 *
 * symbols:
 *   sub_02013AD0       0x02013AD0  thumb
 *   sub_02013B10       0x02013B10  thumb
 *   sub_02013E40       0x02013E40  thumb
 *
 * alias: sub_02013FD8 is the low 5 bit accessor of the cache record's
 * offset 0x1e halfword (unit_02013ED8.c has the high one).
 *
 * sub_02013FEC, sub_02013FFC and sub_02014024 are plain tail calls to
 * sub_02013B10 (unit_02013AD0.c) against three small { key; value } tables
 * of their own (0x0209DFDC/8, 0x0209DFB8/4, 0x0209DFD2/5); mwccarm emits a
 * tail call as a pool word and `bx` even to a function outside the unit
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so each is a function
 * with no prologue, invisible to disasm.py's prologue sweep and printed
 * inside the extent of the labelled accessor at 0x02013FD8.  The pool
 * words that hold sub_02013B10's own address are wildcarded (`literal`
 * class, attested by the same address in unit_02013AD0.c's callers); the
 * table addresses themselves need no attestation, since they are ordinary
 * immediate constants passed by value, not relocated pointers into this
 * range.
 *
 * sub_02014034 and sub_02014044 are plain range/equality tests on the raw
 * id (no call to sub_02013AD0).  sub_0201405C is another cache-record
 * accessor, the byte at offset 0x01.  sub_02014068 forwards to the
 * existing sub_02013E40 (unit_02013DF0.c region), an accessor on the same
 * cache record's offset 0x18.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013FD8.c \
 *       --addr 0x02013FD8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

extern void *sub_02013AD0(u32 id);
extern u32   sub_02013B10(u32 id, const u16 *table, s32 count);
extern u32   sub_02013E40(u32 id);

u8 sub_02013FD8(u32 id)
{
    struct { u8 pad[0x1e]; u16 lo5 : 5; u16 mid5 : 5; u16 hi6 : 6; } *r =
        sub_02013AD0(id);
    return r->lo5;
}

u32 sub_02013FEC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFDC, 8);
}

u32 sub_02013FFC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFB8, 4);
}

u32 sub_0201400C(u32 id)
{
    return id == 0xF6;
}

u32 sub_02014018(u32 id)
{
    return id == 0xF7;
}

u32 sub_02014024(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFD2, 5);
}

u32 sub_02014034(u32 id)
{
    return id >= 0x4C && id <= 0x69;
}

u32 sub_02014044(u32 id)
{
    return id == 0x17A || id == 0x176;
}

u8 sub_0201405C(u32 id)
{
    struct { u8 unk00; u8 unk01; } *r = sub_02013AD0(id);
    return r->unk01;
}

u32 sub_02014068(u32 id)
{
    return sub_02013E40(id) == 0xD6;
}
