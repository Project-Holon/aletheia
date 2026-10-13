/*
 * unit:     yes
 * address:  0x02012914
 * packet:   pkt_020122B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_DATA_GetSituationWarpId
 *
 * symbols:
 *   func_02008850  0x02008850  thumb
 *
 * Sixteen bytes.  The other half of the cut described in the header of
 * src/matched/unit_0201283C.c: this call site and the one at 0x0201290A are
 * the only two references to func_02008850 in the image, so they have to sit
 * in different ranges for either of them to be attested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012914.c \
 *       --addr 0x02012914 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02008850(void *p);

struct BigObj {
    u8  unk000[0x15C];
    u32 unk15C;
};

u16 GAME_DATA_GetSituationWarpId(const struct BigObj *p)
{
    return *func_02008850((void *)p->unk15C);
}
