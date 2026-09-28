/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013BA8
 * packet:   pkt_02013BA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02013BA8, sub_02013BBC, sub_02013BD0
 *
 * symbols:
 *   sub_02013AD0  0x02013AD0  thumb
 *
 * alias: three bitfield accessors on the record sub_02013AD0() returns for a
 * given id.  The halfword at +0x1c of that record is split into three
 * bitfields with no gap: bits[0:5] (6 bits, read by the neighbouring
 * sub_02013C10, not in this file), bits[6:8] (3 bits, sub_02013BA8) and
 * bits[9:15] (7 bits, sub_02013BBC).  sub_02013BD0 reads the separate plain
 * halfword at +0x20.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013BA8.c \
 *       --addr 0x02013BA8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_02013AD0(u32 id);

struct Sub02013AD0Rec {
    u8 pad00[0x1c];
    struct {
        u16 lo6 : 6;
        u16 mid3 : 3;
        u16 hi7 : 7;
    } unk1c;
    u16 unk1e;
    u16 unk20;
};

u8 sub_02013BA8(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->unk1c.mid3;
}

u8 sub_02013BBC(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->unk1c.hi7;
}

u32 sub_02013BD0(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->unk20;
}
