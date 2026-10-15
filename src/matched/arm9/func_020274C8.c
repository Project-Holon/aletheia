/*
 * function: GAME_BEACON_RegisterClearCallback
 * address:  0x020274C8
 * packet:   pkt_020274C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT*. The pooled overlay-id site
 *           ov231_id (231) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * The ABS32 pool word 0x000000E7 is an absolute overlay-id symbol (ov231,
 * matching the bl into CARD_SPI_CheckCardId in asm/overlays/ov231.s), per
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * EXACT* because the listing extent (84 bytes) runs over the follower
 * GAME_BEACON_ClearFlags.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   CARD_SPI_CheckCardId  0x021809D8  thumb ov231
 *   func_02034A5C  0x02034A5C  arm
 *   GAME_BEACON_ClearFlags   0x020274F8  thumb
 *   func_02005624  0x02005624  thumb
 *   ov231_id       0x000000E7  data
 */

typedef unsigned int u32;

extern char  ov231_id[];
extern int   func_02034AC4(signed int id);
extern int   CARD_SPI_CheckCardId(void);
extern void  func_02034A5C(int id);
extern void  GAME_BEACON_ClearFlags(void);
extern void *func_02005624(u32 a, u32 b, u32 c);

void GAME_BEACON_RegisterClearCallback(void)
{
    int r;

    func_02034AC4((int)ov231_id);
    r = CARD_SPI_CheckCardId();
    func_02034A5C((int)ov231_id);
    if (r == 0) {
        func_02005624((u32)GAME_BEACON_ClearFlags, 0, 3);
    }
}
