/*
 * function: GAME_DATA_GetSaveBlock21
 * address:  0x02012F5C
 * packet:   pkt_02012F5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020089C0  0x020089C0  thumb
 *
 * Save-block getter through the handle's first word: tail call to
 * TRCARD_SIGN_GetFromSave (block 0x21, src/matched/unit_020089A8.c).  Seeded from ov111
 * 0x021C40FC, 0x021C4126, 0x021C6208 and ov010 0x0215AC8E.
 *
 * Addresses are Black-image addresses.
 */

struct Sub020089A8Obj;
extern struct Sub020089A8Obj *func_020089C0(void *sys);

void *GAME_DATA_GetSaveBlock21(void **h)
{
    return func_020089C0(*h);
}
