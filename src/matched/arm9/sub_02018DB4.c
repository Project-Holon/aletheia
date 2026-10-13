/*
 * function: POKE_TOOL_GetPartyValueRaw
 * address:  0x02018DB4
 * packet:   pkt_02018DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The party-data half of the record's read accessor, and the outer half of the
 * get/set dispatcher quartet of poke_tool.c.  The record is the 0xDC byte
 * structure src/matched/unit_02017D30.c and src/matched/unit_02018D10.c
 * describe: a seed word at +0x00, three flag bits and a checksum at +0x04, an
 * 0x80 byte XOR masked block area at +0x08 and an 0x54 byte XOR masked party
 * area at +0x88.  This function owns the twelve ids that live in the party
 * area, 0x9D to 0xA8, and tail calls POKE_TOOL_GetBoxValueRaw for everything else, which
 * is the 176 case accessor over the block area (src/pending/POKE_TOOL_GetBoxValueRaw.c).
 *
 * The twelve ids are a dense switch from 0x9D, so the `cmp r3, #0xb` / `bhi` /
 * `add pc, r3` preamble and the twelve halfword table come out of a plain C
 * switch; see docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 * Only 0xA7 and 0xA8 have bodies that are not a field load: 0xA7 copies the
 * 0x38 byte object at +0x9C out through the third argument with
 * MAIL_Copy (the same whole-object copy src/matched/unit_02008F80.c
 * describes), and 0xA8 returns 1 with no field at all.  Both return 1 out of
 * their own `movs r0, #1` / `pop`, not a shared one.
 *
 * The setter half is POKE_TOOL_SetPartyValueRaw, src/matched/POKE_TOOL_SetPartyValueRaw.c, which has the
 * same twelve ids in the same order over the same offsets.
 *
 * Nothing here is version specific: the ids are structure offsets, not species
 * or version tables.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_GetPartyValueRaw.c \
 *       --func POKE_TOOL_GetPartyValueRaw --addr 0x02018DB4 --cc 1.1p1
 *
 * symbols:
 *   MAIL_Copy   0x02008F3C  thumb
 *   POKE_TOOL_GetBoxValueRaw  0x02018E34  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mail {
    u8 unk00[0x38];
};

struct Mon {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
    u32 unk88;
    u8  unk8C;
    u8  unk8D;
    u16 unk8E;
    u16 unk90;
    u16 unk92;
    u16 unk94;
    u16 unk96;
    u16 unk98;
    u16 unk9A;
    struct Mail unk9C;
};

struct Sub02008F80Obj;
extern void MAIL_Copy(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest);
extern u32  POKE_TOOL_GetBoxValueRaw(struct Mon *p, u32 id, u32 v);

u32 POKE_TOOL_GetPartyValueRaw(struct Mon *p, u32 id, u32 v)
{
    switch (id) {
    case 0x9D: return p->unk88;
    case 0x9E: return p->unk8C;
    case 0x9F: return p->unk8D;
    case 0xA0: return p->unk8E;
    case 0xA1: return p->unk90;
    case 0xA2: return p->unk92;
    case 0xA3: return p->unk94;
    case 0xA4: return p->unk96;
    case 0xA5: return p->unk98;
    case 0xA6: return p->unk9A;
    case 0xA7:
        MAIL_Copy((const struct Sub02008F80Obj *)(&p->unk9C), (struct Sub02008F80Obj *)v);
        return 1;
    case 0xA8:
        return 1;
    }
    return POKE_TOOL_GetBoxValueRaw(p, id, v);
}
