/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02033BF0
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: SAVEDATA_GetTableMax, SAVEDATA_GetTotalSize
 *
 * Two plain field accessors on the same object, no relocations. Called
 * repeatedly through the rest of this packet.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02033BF0.c \
 *       --addr 0x02033BF0 --arm
 */

typedef unsigned int u32;

struct Obj02033BF0 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

u32 SAVEDATA_GetTableMax(struct Obj02033BF0 *p)
{
    return p->unk04;
}

u32 SAVEDATA_GetTotalSize(struct Obj02033BF0 *p)
{
    return p->unk0c;
}
