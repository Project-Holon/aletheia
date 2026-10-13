/*
 * unit:     yes
 * address:  0x02012C0C
 * packet:   pkt_02012924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_DATA_GetRtcWork
 *
 * Twelve bytes: the address of the BigObj sub-object at +0x5E8, reached
 * through a literal pool word holding the plain constant 0x5E8 rather than a
 * relocation.  It is a file of its own because the function in front of it,
 * 0x02012BF8, is a documented near miss; see the header of
 * src/matched/unit_02012BE0.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012C0C.c \
 *       --addr 0x02012C0C --thumb
 */

typedef unsigned char u8;

struct BigObj {
    u8 unk000[0x5E8];
    u8 unk5E8[4];
};

u8 *GAME_DATA_GetRtcWork(struct BigObj *p)
{
    return p->unk5E8;
}
